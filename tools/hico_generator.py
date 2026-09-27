#!/usr/bin/env python3
"""Generate and verify HiCo Thermal candidates from the canonical thermal dataset.

Input:  thermal-data/**/manifest.json + raw files
Output: generated-thermal/<same dataset path>/candidate + review + manifest

The original files in `thermal-data/` are never modified. Candidate files are
produced by the host `hicod thermal tune` implementation and then independently
checked with `hicod thermal check` before being marked valid.
"""
from __future__ import annotations

import argparse
import concurrent.futures
import json
import os
import re
import subprocess
import sys
import threading
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LOG_LOCK = threading.Lock()

TUNABLE_FORMATS = {"thermal-engine-text", "json", "xml", "text", "opaque-binary"}


def log(message: str) -> None:
    with LOG_LOCK:
        print(message, flush=True)


def save_json(path: Path, value: object) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(value, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def run_hicod(hicod: str, args: list[str], timeout: int = 120) -> subprocess.CompletedProcess:
    return subprocess.run([hicod, *args], stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                          text=False, check=False, timeout=timeout)


def parse_report(stderr: bytes) -> dict[str, str]:
    text = stderr.decode("utf-8", errors="replace")
    for line in text.splitlines():
        if "policy=" in line and "sections=" in line:
            return dict(re.findall(r"([A-Za-z_]+)=([^\s]+)", line))
    return {}


def generation_root(manifest_path: Path, data_root: Path, output_root: Path) -> Path:
    rel = manifest_path.parent.relative_to(data_root)
    return output_root / rel


def generate_manifest(manifest_path: Path, data_root: Path, output_root: Path, hicod: str, margin: int) -> dict:
    manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    dataset_root = manifest_path.parent
    destination_root = generation_root(manifest_path, data_root, output_root)
    candidate_root = destination_root / "candidate"
    review_root = destination_root / "review"
    candidate_root.mkdir(parents=True, exist_ok=True)
    review_root.mkdir(parents=True, exist_ok=True)
    identity = manifest.get("identity", {})
    platform = str(identity.get("platform", "")).strip()
    source = manifest.get("source", {})
    generated_files = []
    failures = []
    started = time.monotonic()

    raw_items = [item for item in manifest.get("files", []) if item.get("storage") == "raw" and item.get("raw_path")]
    for item in sorted(raw_items, key=lambda x: str(x.get("tree_path", ""))):
        path = str(item.get("tree_path", ""))
        category = str(item.get("category", ""))
        if category != "thermal":
            continue
        raw_path = ROOT / str(item["raw_path"])
        if not raw_path.is_file():
            failures.append({"path": path, "error": f"missing raw file: {item['raw_path']}"})
            continue
        args = ["thermal", "tune", str(raw_path)]
        if platform:
            args += ["--platform", platform]
        args += ["--ceilings", str(dataset_root)]
        if margin:
            args += ["--margin", str(margin)]
        proc = run_hicod(hicod, args)
        report = parse_report(proc.stderr)
        if proc.returncode == 2:
            generated_files.append({"path": path, "status": "not-tunable", "format": item.get("format")})
            continue
        if proc.returncode != 0:
            failures.append({"path": path, "error": proc.stderr.decode("utf-8", errors="replace").strip() or f"hicod exit {proc.returncode}"})
            continue
        tuned_sections = int(report.get("tuned", "0"))
        candidate_bytes = proc.stdout
        candidate_sha = __import__("hashlib").sha256(candidate_bytes).hexdigest()
        original_bytes = raw_path.read_bytes()
        if candidate_bytes == original_bytes or tuned_sections == 0:
            generated_files.append({
                "path": path,
                "status": "unchanged",
                "original_sha256": item.get("sha256"),
                "candidate_sha256": candidate_sha,
                "sections": int(report.get("sections", "0")),
                "tuned_sections": tuned_sections,
            })
            continue

        rel = Path(path)
        candidate_path = candidate_root / rel
        review_path = review_root / rel
        candidate_path.parent.mkdir(parents=True, exist_ok=True)
        review_path.parent.mkdir(parents=True, exist_ok=True)
        candidate_path.write_bytes(candidate_bytes)

        check_args = ["thermal", "check", str(raw_path), str(candidate_path)]
        if platform:
            check_args += ["--platform", platform]
        check_args += ["--ceilings", str(dataset_root)]
        if margin:
            check_args += ["--margin", str(margin)]
        check = run_hicod(hicod, check_args)
        if check.returncode != 0:
            failures.append({"path": path, "error": check.stderr.decode("utf-8", errors="replace").strip() or "independent verification failed"})
            candidate_path.unlink(missing_ok=True)
            continue

        # For review only, ask hicod for readable plaintext. The candidate/ output remains
        # in the same format as the source, including encrypted mi_thermald configs.
        review_proc = run_hicod(hicod, args + ["--plain"])
        review_bytes = review_proc.stdout if review_proc.returncode == 0 else candidate_bytes
        review_path.write_bytes(review_bytes)
        def output_ref(value: Path) -> str:
            try:
                return str(value.resolve().relative_to(ROOT.resolve())).replace("\\", "/")
            except ValueError:
                return str(value.resolve())

        generated_files.append({
            "path": path,
            "status": "generated",
            "original_sha256": item.get("sha256"),
            "candidate_sha256": candidate_sha,
            "candidate_path": output_ref(candidate_path),
            "review_path": output_ref(review_path),
            "sections": int(report.get("sections", "0")),
            "tuned_sections": tuned_sections,
            "policy": report.get("policy", ""),
            "margin": report.get("margin", ""),
        })

    result = {
        "schema": "hico.thermal-generation.v1",
        "source": source,
        "identity": identity,
        "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "files": generated_files,
        "failures": failures,
        "summary": {
            "thermal_files": len(generated_files),
            "generated": sum(1 for item in generated_files if item.get("status") == "generated"),
            "unchanged": sum(1 for item in generated_files if item.get("status") == "unchanged"),
            "not_tunable": sum(1 for item in generated_files if item.get("status") == "not-tunable"),
            "failures": len(failures),
        },
        "elapsed_s": round(time.monotonic() - started, 2),
    }
    save_json(destination_root / "generation.json", result)
    return result


def verify_generated(data_root: Path, output_root: Path) -> dict:
    errors = []
    generations = sorted(output_root.rglob("generation.json")) if output_root.is_dir() else []
    for path in generations:
        try:
            data = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            errors.append(f"{path}: {exc}")
            continue
        if data.get("schema") != "hico.thermal-generation.v1":
            errors.append(f"{path}: unsupported schema")
        if data.get("failures"):
            errors.append(f"{path}: contains generation failures")
        for item in data.get("files", []):
            if item.get("status") != "generated":
                continue
            for key in ("candidate_path", "review_path"):
                target = ROOT / str(item.get(key, ""))
                if not target.is_file():
                    errors.append(f"{path}: missing {key}: {target}")
    return {"schema": "hico.thermal-generation-verification.v1", "generation_count": len(generations), "errors": errors}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)

    p = sub.add_parser("generate")
    p.add_argument("--hicod", required=True)
    p.add_argument("--data", default=str(ROOT / "thermal-data"))
    p.add_argument("--output", default=str(ROOT / "generated-thermal"))
    p.add_argument("--workers", type=int, default=max(2, min(4, os.cpu_count() or 2)))
    p.add_argument("--margin", type=int, default=0)
    p.add_argument("--limit", type=int, default=0)

    p = sub.add_parser("verify")
    p.add_argument("--data", default=str(ROOT / "thermal-data"))
    p.add_argument("--output", default=str(ROOT / "generated-thermal"))

    args = parser.parse_args()
    if args.command == "verify":
        result = verify_generated(Path(args.data), Path(args.output))
        print(json.dumps(result, indent=2, sort_keys=True))
        return 1 if result["errors"] else 0

    if args.workers < 1 or args.workers > 16:
        parser.error("--workers must be between 1 and 16")
    data_root = Path(args.data)
    output_root = Path(args.output)
    manifests = sorted(data_root.rglob("manifest.json")) if data_root.is_dir() else []
    if args.limit:
        manifests = manifests[:args.limit]
    log(f"[generator] manifests={len(manifests)} workers={args.workers}")
    results: list[dict] = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.workers) as pool:
        futures = {pool.submit(generate_manifest, manifest, data_root, output_root, args.hicod, args.margin): manifest for manifest in manifests}
        for future in concurrent.futures.as_completed(futures):
            manifest = futures[future]
            try:
                result = future.result()
                results.append(result)
                summary = result["summary"]
                log(f"[generator] {manifest.parent}: generated={summary['generated']} unchanged={summary['unchanged']} failures={summary['failures']} elapsed={result['elapsed_s']}s")
            except Exception as exc:
                results.append({"schema": "hico.thermal-generation.v1", "files": [], "failures": [{"manifest": str(manifest), "error": str(exc)}], "summary": {"generated": 0, "unchanged": 0, "not_tunable": 0, "failures": 1}})
                log(f"[generator] ERROR {manifest.parent}: {exc}")
    index = {
        "schema": "hico.thermal-generation-index.v1",
        "manifest_count": len(results),
        "generated": sum(x.get("summary", {}).get("generated", 0) for x in results),
        "unchanged": sum(x.get("summary", {}).get("unchanged", 0) for x in results),
        "not_tunable": sum(x.get("summary", {}).get("not_tunable", 0) for x in results),
        "failures": sum(len(x.get("failures", [])) for x in results),
    }
    save_json(output_root / "index.json", index)
    return 1 if index["failures"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
