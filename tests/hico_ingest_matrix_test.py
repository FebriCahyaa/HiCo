#!/usr/bin/env python3
from __future__ import annotations

import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
INGEST = ROOT / "tools" / "hico_ingest.py"


def main() -> int:
    jobs = [
        {
            "id": f"source-{index:04d}",
            "source_id": "source",
            "source_type": "github_org",
            "rom_family": "custom-rom",
            "repos": [],
        }
        for index in range(250)
    ]
    with tempfile.TemporaryDirectory(prefix="hico-matrix-test-") as temp_dir:
        temp = Path(temp_dir)
        discovery = temp / "discovery.json"
        matrix = temp / "matrix.json"
        discovery.write_text(json.dumps({"schema": "hico.discovery.v2", "jobs": jobs, "errors": []}))
        subprocess.run(
            [
                sys.executable,
                str(INGEST),
                "matrix",
                "--discovery",
                str(discovery),
                "--output",
                str(matrix),
                "--max-jobs",
                "250",
                "--ids-only",
            ],
            check=True,
            cwd=ROOT,
        )
        values = json.loads(matrix.read_text())
        assert len(values) == 250
        assert values[0] == "source-0000"
        assert values[-1] == "source-0249"
        assert all(isinstance(value, str) for value in values)
        assert matrix.stat().st_size < 16 * 1024
    print("hico ingest dynamic matrix output: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
