#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import subprocess
import sys
import time
from pathlib import Path
from typing import Any

TERMINAL = {"SUCCEEDED", "FAILED", "FAULT", "STOPPED", "TIMED_OUT"}


def run(cmd: list[str]) -> str:
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=False)
    if proc.returncode != 0:
        raise RuntimeError(f"command failed ({proc.returncode}): {' '.join(cmd)}\n{proc.stderr.strip()}")
    return proc.stdout


def load_json(path: Path) -> Any:
    return json.loads(path.read_text(encoding="utf-8"))


def s3_uri(bucket: str, key: str) -> str:
    return f"s3://{bucket.strip().rstrip('/')}/{key.strip().lstrip('/') }"


def build_inline_buildspec(shard_ids: list[str]) -> str:
    if not shard_ids:
        raise ValueError("shard_ids must not be empty")
    shard_values = "\n".join(f"            - {json.dumps(value)}" for value in shard_ids)
    empty_mapping = json.dumps({
        "schema": "hico.artifact-map-set.v2",
        "roots": [],
        "maps": [],
        "artifacts": [],
        "failures": [],
        "summary": {"roots": 0, "artifacts": 0, "plain": 0, "decoded": 0, "opaque": 0, "decode_failures": 0},
    }, separators=(",", ":"))
    template = """version: 0.2
env:
  shell: bash
batch:
  fast-fail: false
  build-matrix:
    static:
      ignore-failure: false
    dynamic:
      env:
        variables:
          HICO_SHARD_ID:
__SHARD_VALUES__
phases:
  install:
    commands:
      - set -euo pipefail
      - test -n \"$HICO_SOURCE_URI\"
      - test -n \"$HICO_DISCOVERY_URI\"
      - test -n \"$HICO_HICOD_URI\"
  pre_build:
    commands:
      - set -euo pipefail
      - mkdir -p build/source build/discovery build/bin
      - aws s3 cp \"$HICO_SOURCE_URI\" build/hico-source.zip
      - aws s3 cp \"$HICO_DISCOVERY_URI\" build/discovery/discovery.json
      - aws s3 cp \"$HICO_HICOD_URI\" build/bin/hicod
      - chmod +x build/bin/hicod
      - test -x build/bin/hicod
      - python3 -m zipfile -e build/hico-source.zip build/source
      - test -f build/source/tools/hico_ingest.py
      - test -f build/source/tools/hico_thermal.py
  build:
    commands:
      - set -euo pipefail
      - job_file=\"build/job.json\"
      - jq --arg id \"$HICO_SHARD_ID\" '.jobs[] | select(.id == $id)' build/discovery/discovery.json > \"$job_file\"
      - test -s \"$job_file\"
      - mkdir -p \"build/results/ingest/$HICO_SHARD_ID\" \"build/results/mapping/$HICO_SHARD_ID\"
      - python3 build/source/tools/hico_ingest.py ingest --job \"$job_file\" --output \"build/results/ingest/$HICO_SHARD_ID\" --hicod build/bin/hicod --decode-known
      - roots=\"build/roots.txt\"
      - find \"build/results/ingest/$HICO_SHARD_ID/raw\" -mindepth 2 -maxdepth 2 -type d -print | sort > \"$roots\" || true
      - if test -s \"$roots\"; then python3 build/source/tools/hico_thermal.py --hicod build/bin/hicod map-set \"$roots\" \"build/results/mapping/$HICO_SHARD_ID/mapping.json\" --decode; else printf '%s\\n' '__EMPTY_MAPPING__' > \"build/results/mapping/$HICO_SHARD_ID/mapping.json\"; fi
      - python3 -c 'import json,os,pathlib; pathlib.Path(\"build/results/shard.json\").write_text(json.dumps({\"shard_id\":os.environ[\"HICO_SHARD_ID\"],\"batch_identifier\":os.environ.get(\"CODEBUILD_BATCH_BUILD_IDENTIFIER\"),\"build_id\":os.environ.get(\"CODEBUILD_BUILD_ID\")},sort_keys=True)+\"\\n\")'
  post_build:
    commands:
      - set -euo pipefail
      - aws s3 sync \"build/results/ingest/$HICO_SHARD_ID/\" \"$HICO_RESULTS_URI/ingest/$HICO_SHARD_ID/\" --no-progress
      - aws s3 sync \"build/results/mapping/$HICO_SHARD_ID/\" \"$HICO_RESULTS_URI/mapping/$HICO_SHARD_ID/\" --no-progress
      - aws s3 cp build/results/shard.json \"$HICO_RESULTS_URI/status/$HICO_SHARD_ID.json\"
"""
    return template.replace('__SHARD_VALUES__', shard_values).replace('__EMPTY_MAPPING__', empty_mapping)


def start(args: argparse.Namespace) -> int:
    discovery = load_json(Path(args.discovery))
    matrix = load_json(Path(args.matrix))
    shard_ids = [str(item["id"]) for item in matrix]
    if not shard_ids:
        raise RuntimeError("matrix.json contains no shard IDs")
    if len(shard_ids) > 250:
        raise RuntimeError(f"CodeBuild batch would contain {len(shard_ids)} builds; HiCo allows at most 250")

    run_prefix = f"runs/{args.run_id}"
    discovery_uri = s3_uri(args.bucket, f"{run_prefix}/input/discovery.json")
    source_uri = s3_uri(args.bucket, f"{run_prefix}/input/source.zip")
    hicod_uri = s3_uri(args.bucket, f"{run_prefix}/input/hicod")
    results_uri = s3_uri(args.bucket, f"{run_prefix}/results")

    for source, destination in ((args.discovery, discovery_uri), (args.source, source_uri), (args.hicod, hicod_uri)):
        run(["aws", "s3", "cp", str(source), destination, "--no-progress"])

    request = {
        "projectName": args.project,
        "buildspecOverride": build_inline_buildspec(shard_ids),
        "idempotencyToken": args.run_id,
        "environmentVariablesOverride": [
            {"name": "HICO_SOURCE_URI", "type": "PLAINTEXT", "value": source_uri},
            {"name": "HICO_DISCOVERY_URI", "type": "PLAINTEXT", "value": discovery_uri},
            {"name": "HICO_HICOD_URI", "type": "PLAINTEXT", "value": hicod_uri},
            {"name": "HICO_RESULTS_URI", "type": "PLAINTEXT", "value": results_uri},
        ],
        "buildBatchConfigOverride": {
            "restrictions": {"maximumBuildsAllowed": len(shard_ids)},
            "timeoutInMins": int(args.timeout_minutes),
        },
    }
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    request_path = output.with_suffix(".request.json")
    request_path.write_text(json.dumps(request, indent=2) + "\n", encoding="utf-8")
    response = json.loads(run(["aws", "codebuild", "start-build-batch", "--cli-input-json", f"file://{request_path}"]))
    batch = response.get("buildBatch") or {}
    batch_id = batch.get("id")
    if not batch_id:
        raise RuntimeError("StartBuildBatch returned no build batch ID")
    result = {
        "batch_id": batch_id,
        "project": args.project,
        "run_id": args.run_id,
        "run_prefix": run_prefix,
        "results_uri": results_uri,
        "shards": len(shard_ids),
        "discovery_jobs": len(discovery.get("jobs", [])),
    }
    output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(result, indent=2))
    return 0


def wait(args: argparse.Namespace) -> int:
    deadline = time.time() + args.timeout_minutes * 60
    while True:
        response = json.loads(run(["aws", "codebuild", "batch-get-build-batches", "--ids", args.batch_id]))
        batches = response.get("buildBatches", [])
        if not batches:
            raise RuntimeError(f"batch not found: {args.batch_id}")
        status = batches[0].get("buildBatchStatus", "")
        print(f"CodeBuild batch status: {status}", flush=True)
        if status in TERMINAL:
            if status != "SUCCEEDED":
                print(json.dumps(batches[0], indent=2), file=sys.stderr)
                return 1
            return 0
        if time.time() >= deadline:
            raise RuntimeError("timed out waiting for CodeBuild batch")
        time.sleep(args.poll_seconds)


def fetch(args: argparse.Namespace) -> int:
    destination = Path(args.output)
    destination.mkdir(parents=True, exist_ok=True)
    run(["aws", "s3", "sync", args.results_uri, str(destination), "--no-progress"])
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description="HiCo Thermal AWS CodeBuild batch controller")
    sub = parser.add_subparsers(dest="command", required=True)

    p = sub.add_parser("start")
    p.add_argument("--project", required=True)
    p.add_argument("--bucket", required=True)
    p.add_argument("--run-id", required=True)
    p.add_argument("--discovery", required=True)
    p.add_argument("--matrix", required=True)
    p.add_argument("--source", required=True)
    p.add_argument("--hicod", required=True)
    p.add_argument("--timeout-minutes", type=int, default=360)
    p.add_argument("--output", required=True)
    p.set_defaults(func=start)

    p = sub.add_parser("wait")
    p.add_argument("--batch-id", required=True)
    p.add_argument("--timeout-minutes", type=int, default=420)
    p.add_argument("--poll-seconds", type=int, default=30)
    p.set_defaults(func=wait)

    p = sub.add_parser("fetch")
    p.add_argument("--results-uri", required=True)
    p.add_argument("--output", required=True)
    p.set_defaults(func=fetch)

    args = parser.parse_args()
    try:
        return args.func(args)
    except Exception as exc:
        print(f"hico-aws-batch: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
