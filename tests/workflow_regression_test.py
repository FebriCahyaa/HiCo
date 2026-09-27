#!/usr/bin/env python3
from __future__ import annotations

from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / ".github/workflows/tools.yml"
DATABASE = ROOT / ".github/workflows/database.yml"


def require(text: str, needle: str, label: str) -> None:
    if needle not in text:
        raise AssertionError(f"missing {label}: {needle}")


def main() -> int:
    tools = TOOLS.read_text()
    database = DATABASE.read_text()

    require(tools, "chmod +x build/hicod", "tools matrix executable guard")
    require(tools, "chmod +x build/hicod\n          test -x build/hicod", "tools full-map executable guard")
    if "| head -n 1" in tools:
        raise AssertionError("tools workflow contains a pipe to head under pipefail")
    require(tools, "sed -n '1p'", "safe first-root selection")
    require(tools, "matrix_ids: ${{ steps.matrix.outputs.ids }}", "compact full-matrix output")
    require(tools, "name: full-mapping-matrix", "full mapping matrix artifact")
    require(tools, "download-artifact@v6", "artifact transfer")
    require(tools, "name: Download mapping matrix definition", "full-map matrix download")
    require(tools, "jq -r --arg id \"$JOB_ID\" '.[] | select(.id == $id) | .roots[]'", "local shard resolution")

    require(database, "matrix_ids: ${{ steps.matrix.outputs.ids }}", "compact database matrix output")
    require(database, "name: Download discovery metadata", "discovery artifact download")
    require(database, "matrix:\n        id: ${{ fromJSON(needs.discover.outputs.matrix_ids) }}", "database map matrix ids")
    require(database, "chmod +x build/bin/hicod", "database merge executable guard")
    require(database, "HICOD: build/bin/hicod", "database merge test binary path")

    print("Workflow regression checks: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
