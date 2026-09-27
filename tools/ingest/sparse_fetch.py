#!/usr/bin/env python3
"""Sparse-fetch thermal-relevant paths from every device tree in a manifest.

Reads stock/manifest/<source_id>.json (produced by list_device_repos.py) and
for each device runs:

    git clone --depth=1 --filter=blob:none --sparse --branch <default> <clone_url> <tmp>
    cd <tmp>; git sparse-checkout set --skip-checks <thermal_paths...>
    copy every matched file to stock/rom/<source_id>/<vendor>__<codename>/

Files that a device does not ship are silently skipped — that is normal:
LineageOS trees rarely carry vendor thermal blobs, but they do carry
device.mk, BoardConfig.mk, proprietary-files.txt (evidence) and often
init.<device>.thermal.rc.

    python3 tools/ingest/sparse_fetch.py --source lineageos
    python3 tools/ingest/sparse_fetch.py --source lineageos --limit 50
    python3 tools/ingest/sparse_fetch.py --all --jobs 8
"""
from __future__ import annotations

import argparse
import concurrent.futures
import hashlib
import json
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STOCK_ROM = ROOT / "stock" / "rom"
MANIFEST_DIR = ROOT / "stock" / "manifest"


def _load_paths(sources_yaml: Path) -> list[str]:
    sys.path.insert(0, str(ROOT / "tools" / "verify"))
    from rom_sources import _load_sources  # type: ignore
    data = _load_sources(sources_yaml)
    return data.get("thermal_paths") or []


def _run(cmd: list[str], cwd: Path | None = None, timeout: int = 120) -> tuple[int, str]:
    p = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, timeout=timeout)
    return p.returncode, (p.stderr or p.stdout).strip()


def _sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        for chunk in iter(lambda: f.read(65536), b""):
            h.update(chunk)
    return h.hexdigest()


def fetch_device(dev: dict, source_id: str, paths: list[str], dest_root: Path) -> dict:
    vendor = dev["vendor"]
    codename = dev["codename"]
    dest = dest_root / source_id / f"{vendor}__{codename}"
    clone_url = dev["clone_url"]
    branch = dev.get("default_branch") or "HEAD"

    result = {
        "source_id": source_id,
        "vendor": vendor,
        "codename": codename,
        "repo": dev.get("repo"),
        "clone_url": clone_url,
        "branch": branch,
        "status": "pending",
        "files": [],
        "error": None,
    }

    # Idempotency: if we already have this device at the same upstream
    # timestamp, skip. This makes a rerun cheap and lets ingest.yml delta
    # fetches be safe to run repeatedly.
    existing_meta = dest / "source.json"
    if existing_meta.is_file():
        try:
            existing = json.loads(existing_meta.read_text())
            if existing.get("upstream_pushed_at") == dev.get("updated_at"):
                result["status"] = "cached"
                return result
        except Exception:  # noqa: BLE001
            pass

    with tempfile.TemporaryDirectory(prefix=f"hico-{codename}-") as td:
        tmp = Path(td) / "repo"
        # Retry once on transient clone failure (network/rate-limit).
        rc = -1
        err = ""
        for attempt in range(2):
            rc, err = _run(
                [
                    "git", "clone",
                    "--depth=1",
                    "--filter=blob:none",
                    "--sparse",
                    "--single-branch",
                    "--branch", branch,
                    clone_url,
                    str(tmp),
                ],
                timeout=120,
            )
            if rc == 0:
                break
            if attempt == 0:
                if tmp.exists():
                    shutil.rmtree(tmp, ignore_errors=True)
                time.sleep(3)
        if rc != 0:
            result["status"] = "clone-failed"
            result["error"] = err[:200]
            return result

        # Set sparse checkout to only the thermal paths (--no-cone allows globs).
        rc, err = _run(
            ["git", "sparse-checkout", "set", "--no-cone", *paths],
            cwd=tmp,
            timeout=30,
        )
        if rc != 0:
            result["status"] = "sparse-failed"
            result["error"] = err[:200]
            return result

        # Get the commit SHA for provenance.
        _, sha = _run(["git", "rev-parse", "HEAD"], cwd=tmp, timeout=10)
        result["sha"] = sha[:40]

        # Find every file that matched.
        files_found: list[Path] = []
        for path in tmp.rglob("*"):
            if path.is_file() and ".git" not in path.parts:
                files_found.append(path)

        if not files_found:
            result["status"] = "empty"
            return result

        dest.mkdir(parents=True, exist_ok=True)
        source_meta = []
        for src_file in files_found:
            rel = src_file.relative_to(tmp)
            out = dest / rel
            out.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(src_file, out)
            source_meta.append({
                "path": str(rel),
                "sha256": _sha256(out),
                "size": out.stat().st_size,
            })

        # Sidecar: where this device came from.
        (dest / "source.json").write_text(json.dumps({
            "schema": "hico.stock-device-source.v1",
            "source_id": source_id,
            "vendor": vendor,
            "codename": codename,
            "repo": dev.get("repo"),
            "clone_url": clone_url,
            "default_branch": branch,
            "commit": sha[:40],
            "upstream_pushed_at": dev.get("updated_at"),
            "fetched_at_epoch": int(time.time()),
            "file_count": len(files_found),
            "files": sorted(source_meta, key=lambda f: f["path"]),
        }, indent=2, sort_keys=True) + "\n")

        result["status"] = "ok"
        result["files"] = [m["path"] for m in source_meta]
        return result


def _load_manifest(source_id: str) -> dict:
    path = MANIFEST_DIR / f"{source_id}.json"
    if not path.is_file():
        raise SystemExit(f"missing manifest: {path.relative_to(ROOT)} (run list_device_repos.py first)")
    return json.loads(path.read_text())


def run_source(source_id: str, paths: list[str], jobs: int, limit: int | None,
               only_keys: set[str] | None = None) -> None:
    manifest = _load_manifest(source_id)
    devices = manifest["devices"]
    if only_keys is not None:
        devices = [d for d in devices if f"{d['vendor']}/{d['codename']}" in only_keys]
    if limit:
        devices = devices[:limit]
    if not devices:
        print(f"[{source_id}] no devices to fetch", flush=True)
        return
    print(f"[{source_id}] fetching {len(devices)} device(s) with {jobs} worker(s)", flush=True)

    ok = empty = cached = failed = 0
    started = time.time()
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        futures = {pool.submit(fetch_device, d, source_id, paths, STOCK_ROM): d for d in devices}
        for i, fut in enumerate(concurrent.futures.as_completed(futures), 1):
            r = fut.result()
            if r["status"] == "ok":
                ok += 1
            elif r["status"] == "empty":
                empty += 1
            elif r["status"] == "cached":
                cached += 1
            else:
                failed += 1
                print(f"     ✗ {r['vendor']}/{r['codename']}: {r['status']} — {r.get('error','')}", flush=True)
            if i % 25 == 0 or i == len(devices):
                elapsed = time.time() - started
                rate = i / elapsed if elapsed else 0
                remaining = (len(devices) - i) / rate if rate else 0
                print(
                    f"     [{i}/{len(devices)}] ok={ok} empty={empty} cached={cached} fail={failed}  "
                    f"{rate:.1f}/s  eta≈{remaining/60:.1f}min",
                    flush=True,
                )
    print(f"[{source_id}] done  ok={ok} empty={empty} cached={cached} fail={failed}  {(time.time()-started)/60:.1f}min",
          flush=True)


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--sources", default=str(ROOT / "stock" / "sources.yaml"))
    ap.add_argument("--source", help="single source id (e.g. lineageos)")
    ap.add_argument("--all", action="store_true", help="every source in the index")
    ap.add_argument("--only", help="comma-separated source ids")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--limit", type=int, default=None, help="max devices per source")
    ap.add_argument("--only-changed", help="path to change set JSON from diff_manifests.py")
    args = ap.parse_args()

    paths = _load_paths(Path(args.sources))
    if not paths:
        raise SystemExit("no thermal_paths in sources.yaml")

    changed_by_source: dict[str, set[str]] = {}
    if args.only_changed:
        change_set = json.loads(Path(args.only_changed).read_text())
        for dev in change_set.get("devices", []):
            key = f"{dev['vendor']}/{dev['codename']}"
            changed_by_source.setdefault(dev["source_id"], set()).add(key)

    if args.source:
        source_ids = [args.source]
    elif args.all or args.only:
        index = json.loads((MANIFEST_DIR / "index.json").read_text())
        source_ids = [s["source_id"] for s in index["sources"]]
        if args.only:
            wanted = set(args.only.split(","))
            source_ids = [s for s in source_ids if s in wanted]
    else:
        raise SystemExit("pick --source <id>, --only <a,b,c>, or --all")

    for sid in source_ids:
        run_source(sid, paths, args.jobs, args.limit, changed_by_source.get(sid) if changed_by_source else None)
    return 0


if __name__ == "__main__":
    sys.exit(main())
