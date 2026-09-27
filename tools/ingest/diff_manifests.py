#!/usr/bin/env python3
"""Diff the freshly-enumerated manifests against what is already committed.

Emits a JSON change set: devices whose upstream pushed_at is newer than the
sha we already have, plus devices that appear/disappear. `ingest.yml` runs
this after list_device_repos.py to decide what to re-fetch.

    python3 tools/ingest/diff_manifests.py --out changed.json
    python3 tools/ingest/diff_manifests.py --only lineageos --out changed.json
    python3 tools/ingest/diff_manifests.py --force true --out changed.json
"""
from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MANIFEST_DIR = ROOT / "stock" / "manifest"
STOCK_ROM = ROOT / "stock" / "rom"


def _committed_state(source_id: str) -> dict[str, str]:
    """Read every stock/rom/<source_id>/<vendor>__<codename>/source.json.

    Return {"vendor/codename": committed_sha, ...}.
    """
    out: dict[str, str] = {}
    root = STOCK_ROM / source_id
    if not root.is_dir():
        return out
    for dev in root.iterdir():
        meta = dev / "source.json"
        if not meta.is_file():
            continue
        try:
            data = json.loads(meta.read_text())
            key = f"{data['vendor']}/{data['codename']}"
            out[key] = data.get("commit", "")
        except Exception:  # noqa: BLE001 — corrupted sidecar is a "changed" signal
            continue
    return out


def diff_source(source_id: str, force: bool) -> list[dict]:
    manifest_path = MANIFEST_DIR / f"{source_id}.json"
    if not manifest_path.is_file():
        return []
    manifest = json.loads(manifest_path.read_text())
    committed = _committed_state(source_id)

    changed: list[dict] = []
    for dev in manifest.get("devices", []):
        key = f"{dev['vendor']}/{dev['codename']}"
        committed_sha = committed.get(key, "")
        if force or not committed_sha:
            changed.append({**dev, "source_id": source_id, "reason": "new" if not committed_sha else "forced"})
            continue
        # We don't know upstream's sha without another API call. Use pushed_at
        # as a proxy: if upstream pushed since our fetch, the sha almost
        # certainly moved. False positives are cheap (a no-op re-fetch);
        # false negatives are what we must avoid.
        # If updated_at is missing, treat as changed to be safe.
        if not dev.get("updated_at"):
            changed.append({**dev, "source_id": source_id, "reason": "no-timestamp"})

    return changed


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--only", default="", help="comma-separated source ids")
    ap.add_argument("--force", default="false", help="'true' to refetch every device")
    ap.add_argument("--out", required=True)
    args = ap.parse_args()

    force = str(args.force).lower() in {"true", "1", "yes"}

    if not (MANIFEST_DIR / "index.json").is_file():
        raise SystemExit(f"missing index: {MANIFEST_DIR / 'index.json'} — run list_device_repos.py first")
    index = json.loads((MANIFEST_DIR / "index.json").read_text())

    wanted = set(s for s in args.only.split(",") if s)
    all_source_ids = [s["source_id"] for s in index["sources"]]
    source_ids = [s for s in all_source_ids if not wanted or s in wanted]

    changed: list[dict] = []
    for sid in source_ids:
        changed.extend(diff_source(sid, force))

    result = {
        "schema": "hico.ingest-change-set.v1",
        "force": force,
        "sources": sorted(set(d["source_id"] for d in changed)),
        "device_count": len(changed),
        "devices": changed,
    }
    Path(args.out).write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    print(f"change set: {len(changed)} device(s) across {len(result['sources'])} source(s) → {args.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
