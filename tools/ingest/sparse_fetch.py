#!/usr/bin/env python3
"""Sparse-fetch thermal-relevant paths from every repository in a manifest.

Reads stock/manifest/<source_id>.json (list_device_repos.py) and, per
repository:

    git clone --depth=1 --filter=blob:none --sparse [--branch B] <url> <tmp>
    git sparse-checkout set --no-cone <paths from sources.yaml>
    replace stock/<family>/<source_id>/<vendor>__<codename>/ with the result

Only the matched files are downloaded (blob:none + sparse), a few kilobytes
per device. The destination is replaced as a whole, so files removed
upstream disappear here too. Every outcome (ok / empty / failed) is recorded
in stock/manifest/<source_id>.state.json with the fetched commit, which is
what diff_manifests.py compares against upstream.

    python3 tools/ingest/sparse_fetch.py --source lineageos --limit 50
    python3 tools/ingest/sparse_fetch.py --all --jobs 16
    python3 tools/ingest/sparse_fetch.py --all --only-changed changed.json
"""
from __future__ import annotations

import argparse
import concurrent.futures
import hashlib
import json
import shutil
import sys
import tempfile
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import (  # noqa: E402
    MANIFEST_DIR, SOURCES_YAML, STOCK, branch_dir_suffix, candidate_branches, dest_root,
    device_dir_name, device_key, load_sources, load_state, oldest_and_newest, paths_for,
    remote_heads, resolve_branch, run, save_state, source_map, write_json,
)

MAX_FILE_BYTES = 2 * 1024 * 1024  # no thermal or evidence file is bigger; guards the repo size


def _sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()


def fetch_device(dev: dict, source: dict, paths: list[str], stock: Path = STOCK) -> dict:
    """Fetch one repository. Never raises: failures come back as a status."""
    key = device_key(dev)
    result = {"key": key, "dir": device_dir_name(dev), "status": "pending", "commit": None, "branch": None,
              "file_count": 0, "error": None, "pushed_at": dev.get("updated_at")}
    dest = dest_root(source, stock) / device_dir_name(dev)

    branch = dev.get("default_branch") or None
    if len(candidate_branches(dev)) > 1:
        heads = remote_heads(dev["clone_url"])
        if heads is None:
            result.update(status="clone-failed", error="repository unreachable (ls-remote)")
            return result
        branch, _ = resolve_branch(dev, heads)
        if branch is None:
            result.update(status="clone-failed", error=f"none of {candidate_branches(dev)} exists upstream")
            return result
    result["branch"] = branch

    with tempfile.TemporaryDirectory(prefix="hico-fetch-") as td:
        tmp = Path(td) / "repo"
        clone = ["git", "clone", "-q", "--depth=1", "--filter=blob:none", "--sparse", "--single-branch"]
        if branch:
            clone += ["--branch", branch]
        rc, err = 1, ""
        for attempt in range(2):  # one retry for transient network / rate-limit failures
            rc, err = run([*clone, dev["clone_url"], str(tmp)], timeout=180)
            if rc == 0:
                break
            shutil.rmtree(tmp, ignore_errors=True)
            if attempt == 0:
                time.sleep(3)
        if rc != 0:
            result.update(status="clone-failed", error=err[:300])
            return result

        rc, err = run(["git", "sparse-checkout", "set", "--no-cone", *paths], cwd=tmp, timeout=180)
        if rc != 0:
            result.update(status="sparse-failed", error=err[:300])
            return result
        rc, sha = run(["git", "rev-parse", "HEAD"], cwd=tmp, timeout=30)
        result["commit"] = sha if rc == 0 and len(sha) == 40 else None

        staged = Path(td) / "out"
        files: list[dict] = []
        skipped_large: list[str] = []
        for path in sorted(tmp.rglob("*")):
            if ".git" in path.relative_to(tmp).parts or path.is_symlink() or not path.is_file():
                continue
            rel = path.relative_to(tmp)
            size = path.stat().st_size
            if size > MAX_FILE_BYTES:
                skipped_large.append(str(rel))
                continue
            out = staged / rel
            out.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(path, out)
            files.append({"path": rel.as_posix(), "sha256": _sha256(out), "size": size})

        if not files:
            # Nothing thermal-related upstream: drop an old copy, remember it in the state.
            shutil.rmtree(dest, ignore_errors=True)
            result["status"] = "empty"
            return result

        write_json(staged / "source.json", {
            "schema": "hico.stock-device-source.v2",
            "source_id": source["id"],
            "vendor": dev["vendor"],
            "codename": dev["codename"],
            "kind": dev.get("kind", "device"),
            "serves": dev.get("serves", []),
            "repo": dev.get("repo"),
            "clone_url": dev["clone_url"],
            "branch": branch,
            "commit": result["commit"],
            "upstream_pushed_at": dev.get("updated_at"),
            "file_count": len(files),
            "skipped_large": skipped_large,
            "files": files,
        })
        # Replace the whole directory: files deleted upstream must not linger.
        dest.parent.mkdir(parents=True, exist_ok=True)
        if dest.exists():
            shutil.rmtree(dest)
        shutil.move(str(staged), str(dest))
        result.update(status="ok", file_count=len(files))
        return result


def fetch_device_multi_branch(dev: dict, source: dict, paths: list[str], stock: Path = STOCK) -> list[dict]:
    """Fetch oldest-qualifying AND newest branch for a device, storing each separately.

    Returns a list of per-branch result dicts (same shape as fetch_device).
    Each is stored at <dest_root>/<vendor>__<codename>__<branch>/ so branches
    with different thermal configs do not overwrite each other.
    Used when source has multi_branch: true (e.g. LineageOS).
    Falls back to single-branch fetch when ls-remote finds only one qualifying branch.
    """
    key = device_key(dev)
    heads = remote_heads(dev["clone_url"])
    if heads is None:
        return [{"key": key, "dir": device_dir_name(dev), "status": "clone-failed",
                 "commit": None, "branch": None, "file_count": 0,
                 "error": "unreachable (ls-remote)", "pushed_at": dev.get("updated_at")}]

    pairs = oldest_and_newest(heads)
    if not pairs:
        # No qualifying Android 10+ branch found — skip this device.
        return [{"key": key, "dir": device_dir_name(dev), "status": "empty",
                 "commit": None, "branch": None, "file_count": 0,
                 "error": "no Android 10+ branch", "pushed_at": dev.get("updated_at")}]

    results = []
    for branch, _sha in pairs:
        branch_dev = {**dev, "default_branch": branch, "branches": [branch]}
        result = fetch_device(branch_dev, source, paths, stock)
        if len(pairs) > 1:
            # Store under <vendor>__<codename>__<branch>/ so branches coexist.
            suffix = branch_dir_suffix(branch)
            base_name = device_dir_name(dev)
            result["dir"] = base_name + suffix
            # Rename on disk: fetch_device wrote to base_name; move it.
            base_path = dest_root(source, stock) / base_name
            branch_path = dest_root(source, stock) / result["dir"]
            if base_path.exists() and result["status"] == "ok":
                if branch_path.exists():
                    shutil.rmtree(branch_path)
                shutil.move(str(base_path), str(branch_path))
        results.append(result)
    return results


def _stage(source: dict, sid: str, dirs: list[str], stock: Path, manifest_dir: Path, stage: Path) -> None:
    """Copy this run's results into a fixed layout for a CI artifact:
    <stage>/<rom|blobs>/<sid>/<vendor>__<codename>/ and <stage>/manifest/<sid>.state.json."""
    root = dest_root(source, stock)
    for name in dirs:
        out = stage / root.relative_to(stock) / name
        if out.exists():
            shutil.rmtree(out)
        shutil.copytree(root / name, out)
    (stage / "manifest").mkdir(parents=True, exist_ok=True)
    shutil.copyfile(manifest_dir / f"{sid}.state.json", stage / "manifest" / f"{sid}.state.json")


def load_manifest(source_id: str, manifest_dir: Path = MANIFEST_DIR) -> dict:
    path = manifest_dir / f"{source_id}.json"
    if not path.is_file():
        raise SystemExit(f"missing manifest {path} (run list_device_repos.py first)")
    return json.loads(path.read_text())


def select(devices: list[dict], state: dict[str, dict], only_keys: set[str] | None,
           refetch: bool) -> list[dict]:
    """Which repositories to fetch this run.

    only_keys (from a change set) wins. Otherwise skip what the state already
    has at the same upstream push time, so an interrupted seed resumes where
    it stopped instead of starting over.
    """
    if only_keys is not None:
        return [d for d in devices if device_key(d) in only_keys]
    if refetch:
        return devices
    out = []
    for d in devices:
        prev = state.get(device_key(d))
        if prev and prev.get("status") in ("ok", "empty") and (
                d.get("updated_at") is None or prev.get("pushed_at") == d.get("updated_at")):
            continue
        out.append(d)
    return out


def run_source(source: dict, data: dict, jobs: int, limit: int | None, only_keys: set[str] | None,
               refetch: bool, stock: Path = STOCK, manifest_dir: Path = MANIFEST_DIR,
               stage: Path | None = None) -> dict[str, int]:
    sid = source["id"]
    manifest = load_manifest(sid, manifest_dir)
    state = load_state(sid, manifest_dir)
    todo = select(manifest["devices"], state, only_keys, refetch)
    if limit:
        todo = todo[:limit]
    counts = {"ok": 0, "empty": 0, "failed": 0}
    fetched_ok: list[str] = []
    if not todo:
        print(f"[{sid}] nothing to fetch", flush=True)
        if stage is not None:
            _stage(source, sid, [], stock, manifest_dir, stage)
        return counts
    paths = paths_for(source, data)
    multi = bool(source.get("multi_branch"))
    print(f"[{sid}] fetching {len(todo)} repositories with {jobs} workers"
          + (" (multi-branch: oldest+newest)" if multi else ""), flush=True)
    started = time.time()

    def _fetch(d: dict) -> list[dict]:
        if multi:
            return fetch_device_multi_branch(d, source, paths, stock)
        return [fetch_device(d, source, paths, stock)]

    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = [pool.submit(_fetch, d) for d in todo]
        for i, fut in enumerate(concurrent.futures.as_completed(futures), 1):
            results = fut.result()
            for r in results:
                bucket = r["status"] if r["status"] in ("ok", "empty") else "failed"
                counts[bucket] += 1
                if bucket == "ok":
                    fetched_ok.append(r["dir"])
                prev = state.get(r["key"], {})
                if bucket == "failed":
                    # Keep the last good commit: a transient failure must not look like a change.
                    state[r["key"]] = {**prev, "status": r["status"], "error": r["error"]}
                    print(f"     ✗ {r['key']}: {r['status']} {r['error'] or ''}", flush=True)
                else:
                    state[r["key"]] = {"status": r["status"], "commit": r["commit"],
                                       "branch": r["branch"], "pushed_at": r["pushed_at"],
                                       "file_count": r["file_count"]}
            if i % 50 == 0 or i == len(todo):
                rate = i / max(time.time() - started, 1e-6)
                print(f"     [{i}/{len(todo)}] ok={counts['ok']} empty={counts['empty']} "
                      f"failed={counts['failed']}  {rate:.1f} repos/s  "
                      f"eta {(len(todo) - i) / rate / 60:.1f} min", flush=True)
            if i % 200 == 0:
                save_state(sid, state, manifest_dir)  # resumable if the run is interrupted
    # Forget repositories that left the manifest.
    listed = {device_key(d) for d in manifest["devices"]}
    for gone in [k for k in state if k not in listed]:
        del state[gone]
    save_state(sid, state, manifest_dir)
    if stage is not None:
        _stage(source, sid, fetched_ok, stock, manifest_dir, stage)
    print(f"[{sid}] done ok={counts['ok']} empty={counts['empty']} failed={counts['failed']} "
          f"in {(time.time() - started) / 60:.1f} min", flush=True)
    return counts


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--sources", default=str(SOURCES_YAML))
    ap.add_argument("--source", help="single source id")
    ap.add_argument("--only", help="comma-separated source ids")
    ap.add_argument("--all", action="store_true", help="every source with a manifest")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=None, help="max repositories per source")
    ap.add_argument("--only-changed", help="change set JSON from diff_manifests.py")
    ap.add_argument("--refetch", action="store_true", help="ignore the state and fetch everything")
    ap.add_argument("--stage", help="also copy this run's results into DIR (CI artifact layout)")
    args = ap.parse_args()

    data = load_sources(Path(args.sources))
    sources = source_map(data)
    if args.source:
        ids = [args.source]
    elif args.only:
        ids = [s for s in args.only.split(",") if s]
    elif args.all:
        ids = [sid for sid in sources if (MANIFEST_DIR / f"{sid}.json").is_file()]
    else:
        raise SystemExit("pick --source <id>, --only <a,b>, or --all")

    changed: dict[str, set[str]] | None = None
    if args.only_changed:
        cs = json.loads(Path(args.only_changed).read_text())
        changed = {}
        for d in cs.get("devices", []):
            changed.setdefault(d["source_id"], set()).add(device_key(d))

    failed = 0
    for sid in ids:
        if sid not in sources:
            raise SystemExit(f"unknown source {sid!r} (not in {args.sources})")
        only_keys = changed.get(sid, set()) if changed is not None else None
        failed += run_source(sources[sid], data, args.jobs, args.limit, only_keys, args.refetch,
                             stage=Path(args.stage) if args.stage else None)["failed"]
    return 0 if failed == 0 else 2


if __name__ == "__main__":
    sys.exit(main())
