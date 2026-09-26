#!/usr/bin/env python3
from __future__ import annotations

import json
import shutil
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from hico_database import merge_mappings


def main() -> int:
    with tempfile.TemporaryDirectory(prefix="hico-database-test-") as td:
        root = Path(td)
        input_root = root / "input"
        output = root / "database"
        mapping = {
            "schema": "hico.artifact-map-set.v3",
            "roots": [
                "devices/test/device-a/thermal",
                "database/sources/ingested/raw/source/repo-a",
            ],
            "maps": [
                {
                    "schema": "hico.artifact-map.v3",
                    "root": "devices/test/device-a/thermal",
                    "artifacts": [{"path": "thermal.conf", "sha256": "a" * 64}],
                    "failures": [],
                    "summary": {"artifacts": 1},
                    "topology": {"status": "static-scan"},
                },
                {
                    "schema": "hico.artifact-map.v3",
                    "root": "database/sources/ingested/raw/source/repo-a",
                    "artifacts": [{"path": "thermal/config.json", "sha256": "b" * 64}],
                    "failures": [],
                    "summary": {"artifacts": 1},
                    "topology": {"status": "static-scan"},
                },
            ],
            "artifacts": [],
            "failures": [],
            "summary": {"roots": 2, "artifacts": 2, "decode_failures": 0},
        }
        input_root.mkdir(parents=True)
        (input_root / "mapping.json").write_text(json.dumps(mapping) + "\n")
        result = merge_mappings(input_root, output)
        assert result["mapping_count"] == 2
        assert result["artifact_count"] == 2
        assert not result["failures"]
        assert (output / "mapped/devices/test/device-a/thermal.json").is_file()
        assert (output / "mapped/sources/source/repo-a.json").is_file()
        shutil.rmtree(output / "mapped" / "devices" / "test", ignore_errors=False)
        shutil.rmtree(output / "mapped" / "sources", ignore_errors=False)
    print("HiCo database tests: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
