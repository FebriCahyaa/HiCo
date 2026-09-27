from __future__ import annotations

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from tools.hico_aws_batch import build_inline_buildspec


def main() -> int:
    ids = [f"shard-{index:04d}" for index in range(250)]
    spec = build_inline_buildspec(ids)
    assert spec.count('- "shard-') == 250
    assert "env:\n  shell: bash\n" in spec
    assert "batch:\n" in spec
    assert "build-matrix:" in spec
    assert "aws s3 cp \"$HICO_SOURCE_URI\"" in spec
    assert "aws s3 sync \"build/results/ingest/$HICO_SHARD_ID/\"" in spec
    assert 'job_file="build/job.json"' in spec
    assert 'roots="build/roots.txt"' in spec
    print("AWS batch buildspec test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
