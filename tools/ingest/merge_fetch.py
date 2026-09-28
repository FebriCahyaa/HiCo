#!/usr/bin/env python3
"""Merge per-source fetch artifacts back into stock/ (ingest.yml commit job).

Each fetch job uploads stock/{rom,blobs}/<source_id>/ and
stock/manifest/<source_id>.state.json. For every repository in the change
set this replaces its directory with the fetched copy, removes it when the
fetch found nothing thermal-related any more, and keeps it untouched when
the fetch failed (the state keeps the last good commit). Directories of
repositories that were not in the change set are never touched.

    python3 tools/ingest/merge_fetch.py --changed changed.json --artifacts DIR
"""
from __future__ import annotations

import argparse
import json
import shutil
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import (  # noqa: E402
    FAMILY_DIRS, MANIFEST_DIR, SOURCES_YAML, STOCK, dest_root, device_dir_name, device_key, load_sources,
    source_map,
)


def merge(changed: dict, artifacts: Path, sources: dict[str, dict], stock: Path = STOCK,
          manifest_dir: Path = MANIFEST_DIR) -> dict[str, int]:
    counts = {"replaced": 0, "removed": 0, "kept": 0, "missing_artifact": 0}
    by_source: dict[str, list[dict]] = {}
    for dev in changed.get("devices", []):
        by_source.setdefault(dev["source_id"], []).append(dev)
    for sid, devs in sorted(by_source.items()):
        source = sources[sid]
        art = artifacts / f"fetched-{sid}"
        art_state = art / "manifest" / f"{sid}.state.json"
        if not art_state.is_file():
            counts["missing_artifact"] += len(devs)
            print(f"[{sid}] no artifact (fetch job failed?): {len(devs)} repositories left as they were")
            continue
        state = json.loads(art_state.read_text()).get("devices", {})
        family_dir = FAMILY_DIRS.get(source.get("family", "rom"), "rom")
        for dev in devs:
            name = device_dir_name(dev)
            target = dest_root(source, stock) / name
            fetched = art / family_dir / sid / name
            status = (state.get(device_key(dev)) or {}).get("status")
            if status == "ok" and fetched.is_dir():
                if target.exists():
                    shutil.rmtree(target)
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copytree(fetched, target)
                counts["replaced"] += 1
            elif status == "empty":
                if target.exists():
                    shutil.rmtree(target)
                    counts["removed"] += 1
            else:
                counts["kept"] += 1
        manifest_dir.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(art_state, manifest_dir / f"{sid}.state.json")
    return counts


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--changed", required=True)
    ap.add_argument("--artifacts", required=True)
    ap.add_argument("--sources", default=str(SOURCES_YAML))
    args = ap.parse_args()
    counts = merge(json.loads(Path(args.changed).read_text()), Path(args.artifacts),
                   source_map(load_sources(Path(args.sources))))
    print(f"merged: {counts}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
