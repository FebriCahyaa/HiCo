#!/usr/bin/env python3
from __future__ import annotations

from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BUILD = ROOT / ".github/workflows/build.yml"
TOOLS = ROOT / ".github/workflows/tools.yml"
DATABASE = ROOT / ".github/workflows/database.yml"


def require(text: str, needle: str, label: str) -> None:
    if needle not in text:
        raise AssertionError(f"missing {label}: {needle}")


def main() -> int:
    build = BUILD.read_text()
    tools = TOOLS.read_text()
    database = DATABASE.read_text()

    require(build, "python3 tests/hico_evidence_test.py", "build canonical evidence regression test")
    require(build, "python3 tests/hico_relationships_test.py", "build relationship regression test")
    require(build, "python3 tools/hico_evidence.py verify --root sources/evidence", "build canonical evidence verifier")
    require(build, "python3 tools/hico_relationships.py", "build relationship resolver")
    require(build, "git diff --exit-code -- sources/relationships.json", "build deterministic relationship graph gate")

    require(database, "python3 tests/hico_evidence_test.py", "database canonical evidence regression test")
    require(database, "python3 tests/hico_relationships_test.py", "database relationship regression test")
    require(database, "python3 tools/hico_evidence.py verify --root sources/evidence", "database canonical evidence verifier")
    require(database, "python3 tools/hico_relationships.py", "database relationship resolver")
    require(database, "git diff --exit-code -- sources/relationships.json", "database deterministic relationship graph gate")

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
    require(tools, "thermal-data", "canonical thermal dataset")
    require(tools, "generated-thermal", "generated thermal candidates")

    require(database, "name: Verify collected thermal dataset", "database verification workflow")
    require(database, "python3 tools/hico_collector.py verify", "collector dataset verification")
    require(database, "python3 tools/hico_generator.py verify", "generated thermal verification")
    require(database, "python3 tools/hico_database.py build --root . --output build/database", "deterministic database rebuild")
    require(database, "name: Rebuild deterministic database in a clean directory", "clean database rebuild")
    if any(token in database.lower() for token in ("aws", "codebuild", "cloudformation", "hico_aws")):
        raise AssertionError("database workflow must not contain AWS infrastructure/offload logic")

    for path in (
        ROOT / ".github/workflows/aws-infra.yml",
        ROOT / "tools/hico_aws_batch.py",
        ROOT / "infra/aws",
    ):
        if path.exists():
            raise AssertionError(f"AWS component still exists: {path}")

    print("Workflow regression checks: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
