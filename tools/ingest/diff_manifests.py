#!/usr/bin/env python3
"""Decide which repositories changed upstream since they were fetched.

For every repository in stock/manifest/<source_id>.json this compares the
upstream state with stock/manifest/<source_id>.state.json:

  new       never fetched
  moved     upstream branch HEAD differs from the fetched commit
  retry     last fetch failed
  forced    --force

The check is two-step so a scheduled run stays cheap:
  1. `updated_at` (GitHub pushed_at from the listing) equal to the recorded
     value → unchanged, no network call.
  2. otherwise `git ls-remote <url> refs/heads/<branch>` (one tiny request,
     no clone, no API quota) → changed only when the commit differs. A push
     to another branch moves pushed_at but not the fetched branch: not a change.

Writes a change set JSON; `sources` lists the source ids with work, which
ingest.yml turns into its fetch matrix.

    python3 tools/ingest/diff_manifests.py --out changed.json
    python3 tools/ingest/diff_manifests.py --only lineageos --out changed.json
"""
from __future__ import annotations

import argparse
import concurrent.futures
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import (  # noqa: E402
    MANIFEST_DIR, candidate_branches, device_key, load_state, ls_remote_sha, remote_heads, resolve_branch,
)


def classify(dev: dict, prev: dict | None, force: bool, remote_sha=ls_remote_sha,
             heads_of=remote_heads) -> str | None:
    """Reason to fetch `dev`, or None when it is up to date."""
    if force:
        return "forced"
    if not prev:
        return "new"
    if prev.get("status") not in ("ok", "empty"):
        return "retry"
    if dev.get("updated_at") and prev.get("pushed_at") == dev.get("updated_at"):
        return None
    if len(candidate_branches(dev)) > 1:
        # Repo-tool manifest source: the preferred branch may have appeared since.
        heads = heads_of(dev["clone_url"])
        if heads is None:
            return "retry"
        branch, sha = resolve_branch(dev, heads)
        if branch is None:
            return "retry"
        if branch != prev.get("branch"):
            return "moved"  # a newer branch exists now
        return None if sha == prev.get("commit") else "moved"
    sha = remote_sha(dev["clone_url"], dev.get("default_branch") or None)
    if sha is None:
        return "retry"  # unreachable now: try the fetch, it records the outcome
    return None if sha == prev.get("commit") else "moved"


def diff_source(source_id: str, force: bool, jobs: int = 16, manifest_dir: Path = MANIFEST_DIR,
                remote_sha=ls_remote_sha) -> tuple[list[dict], list[str]]:
    path = manifest_dir / f"{source_id}.json"
    if not path.is_file():
        return [], []
    manifest = json.loads(path.read_text())
    state = load_state(source_id, manifest_dir)
    devices = manifest.get("devices", [])
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        reasons = list(pool.map(lambda d: classify(d, state.get(device_key(d)), force, remote_sha), devices))
    changed = [{**d, "source_id": source_id, "reason": r} for d, r in zip(devices, reasons) if r]
    listed = {device_key(d) for d in devices}
    removed = sorted(k for k in state if k not in listed)
    return changed, removed


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--only", default="", help="comma-separated source ids")
    ap.add_argument("--force", default="false", help="'true' to refetch every repository")
    ap.add_argument("--jobs", type=int, default=16)
    ap.add_argument("--out", required=True)
    args = ap.parse_args()

    force = str(args.force).lower() in {"true", "1", "yes"}
    index_path = MANIFEST_DIR / "index.json"
    if not index_path.is_file():
        raise SystemExit(f"missing {index_path} (run list_device_repos.py first)")
    index = json.loads(index_path.read_text())
    wanted = {s for s in args.only.split(",") if s}
    source_ids = [s["source_id"] for s in index["sources"] if not wanted or s["source_id"] in wanted]

    changed: list[dict] = []
    removed: dict[str, list[str]] = {}
    for sid in source_ids:
        c, r = diff_source(sid, force, args.jobs)
        changed.extend(c)
        if r:
            removed[sid] = r
        reasons: dict[str, int] = {}
        for d in c:
            reasons[d["reason"]] = reasons.get(d["reason"], 0) + 1
        print(f"[{sid}] {len(c)} to fetch {reasons or ''}{f', {len(r)} removed upstream' if r else ''}", flush=True)

    result = {
        "schema": "hico.ingest-change-set.v2",
        "force": force,
        "sources": sorted({d["source_id"] for d in changed}),
        "device_count": len(changed),
        "devices": changed,
        "removed": removed,
    }
    Path(args.out).write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    print(f"change set: {len(changed)} repositories across {len(result['sources'])} sources → {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
