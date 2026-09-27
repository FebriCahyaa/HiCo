#!/usr/bin/env python3
"""Extract small, deterministic relationship evidence from collected HiCo datasets.

The canonical evidence layer stores only source files needed to establish source
relationships (currently lineage.dependencies and root BoardConfig.mk). It keeps
repository/branch/commit provenance and SHA-256 checksums, while deliberately
avoiding a copy of the whole collected source tree.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SCHEMA = "hico.source-evidence.v1"
EVIDENCE_FILES = {
    "lineage.dependencies": "lineage-dependencies",
    "BoardConfig.mk": "boardconfig",
}
MAX_EVIDENCE_FILE = 512 * 1024


def clean_segment(value: object) -> str:
    text = str(value or "").strip()
    text = re.sub(r"[^A-Za-z0-9._-]+", "_", text)
    return text or "unknown"


def clean_path_segment(value: object) -> str:
    return clean_segment(value).strip(".") or "unknown"


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def root_relative(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path.resolve()).replace("\\", "/")


def dataset_relative(path: Path, data_root: Path) -> str:
    try:
        return str(path.resolve().relative_to(data_root.resolve())).replace("\\", "/")
    except ValueError:
        return path.name


def resolve_raw_path(raw_path: str, manifest_path: Path) -> Path | None:
    raw = Path(raw_path)
    candidates = []
    if raw.is_absolute():
        candidates.append(raw)
    else:
        candidates.extend((ROOT / raw, manifest_path.parent / raw))
    for candidate in candidates:
        if candidate.is_file():
            return candidate.resolve()
    return None


def iter_manifests(data_root: Path) -> list[Path]:
    if not data_root.is_dir():
        raise FileNotFoundError(f"dataset root does not exist: {data_root}")
    return sorted(path for path in data_root.rglob("manifest.json") if path.is_file())


def source_key(source: dict) -> tuple[str, str, str]:
    return (
        str(source.get("provider", "")).strip(),
        str(source.get("repository", "")).strip(),
        str(source.get("commit", "")).strip(),
    )


def canonical_dir(output_root: Path, source: dict) -> Path:
    provider = clean_path_segment(source.get("provider"))
    repository = str(source.get("repository", "")).strip("/")
    repo_parts = [clean_path_segment(part) for part in repository.split("/") if part]
    if not repo_parts:
        repo_parts = ["unknown-repository"]
    commit = clean_path_segment(source.get("commit"))
    return output_root / provider / Path(*repo_parts) / commit


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def select_evidence(manifest_path: Path, manifest: dict) -> list[tuple[dict, Path, str]]:
    source = manifest.get("source", {})
    selected: list[tuple[dict, Path, str]] = []
    for item in manifest.get("files", []):
        tree_path = str(item.get("tree_path") or item.get("path") or "").strip("/")
        if tree_path not in EVIDENCE_FILES:
            continue
        raw_path = str(item.get("raw_path") or "")
        raw = resolve_raw_path(raw_path, manifest_path)
        if raw is None:
            continue
        kind = EVIDENCE_FILES[tree_path]
        selected.append((item, raw, kind))
    return selected


def extract(data_root: Path, output_root: Path, source_filters: list[str]) -> dict:
    output_root.mkdir(parents=True, exist_ok=True)
    manifests = iter_manifests(data_root)
    grouped: dict[tuple[str, str, str], tuple[Path, dict]] = {}
    missing_source = 0
    for manifest_path in manifests:
        try:
            manifest = load_json(manifest_path)
        except (OSError, json.JSONDecodeError):
            continue
        if manifest.get("schema") != "hico.thermal-source.v1":
            continue
        source = manifest.get("source", {})
        provider, repository, commit = source_key(source)
        if not provider or not repository or not commit:
            missing_source += 1
            continue
        if source_filters:
            key = f"{provider}/{repository}"
            if not any(key == wanted or repository == wanted for wanted in source_filters):
                continue
        grouped.setdefault((provider, repository, commit), (manifest_path, manifest))

    exported = []
    failures = []
    total_files = 0
    for key in sorted(grouped):
        manifest_path, manifest = grouped[key]
        source = dict(manifest["source"])
        selected = select_evidence(manifest_path, manifest)
        if not selected:
            continue
        destination = canonical_dir(output_root, source)
        destination.mkdir(parents=True, exist_ok=True)
        evidence_entries = []
        for item, raw, kind in sorted(selected, key=lambda row: row[0].get("tree_path", "")):
            size = raw.stat().st_size
            tree_path = str(item.get("tree_path") or item.get("path") or "").strip("/")
            if size > MAX_EVIDENCE_FILE:
                failures.append(f"{root_relative(manifest_path)}: {tree_path}: size {size} exceeds {MAX_EVIDENCE_FILE}")
                continue
            data = raw.read_bytes()
            target = destination / Path(tree_path).name
            target.write_bytes(data)
            digest = sha256_bytes(data)
            evidence_entries.append({
                "kind": kind,
                "tree_path": tree_path,
                "path": root_relative(target),
                "raw_path": root_relative(target),
                "source_commit": source["commit"],
                "sha256": digest,
                "size": len(data),
            })
            total_files += 1

        if not evidence_entries:
            continue
        canonical_manifest = {
            "schema": SCHEMA,
            "version": 1,
            "source": {
                "id": source.get("id", ""),
                "provider": source["provider"],
                "repository": source["repository"],
                "branch": source.get("branch", ""),
                "commit": source["commit"],
                "url": source.get("url", ""),
            },
            "source_manifest": dataset_relative(manifest_path, data_root),
            "evidence": {
                "purpose": "relationship-resolution",
                "supported_files": sorted(EVIDENCE_FILES),
                "items": evidence_entries,
            },
            "files": evidence_entries,
            "repository": {
                "file_count": len(evidence_entries),
                "max_file_size": MAX_EVIDENCE_FILE,
            },
        }
        (destination / "manifest.json").write_text(
            json.dumps(canonical_manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8"
        )
        exported.append({
            "source": f"{source['provider']}/{source['repository']}",
            "commit": source["commit"],
            "manifest": root_relative(destination / "manifest.json"),
            "file_count": len(evidence_entries),
        })

    # Rebuild the index from all canonical manifests currently present in the
    # evidence store, not only from the current extraction input. This preserves
    # previously canonicalized evidence when a bounded pilot/subset is extracted.
    indexed = []
    for canonical_manifest_path in sorted(
        path for path in output_root.rglob("manifest.json")
        if path.is_file()
    ):
        try:
            canonical = load_json(canonical_manifest_path)
        except (OSError, json.JSONDecodeError):
            continue
        if canonical.get("schema") != SCHEMA:
            continue

        source = canonical.get("source", {})
        provider = str(source.get("provider", "")).strip()
        repository = str(source.get("repository", "")).strip()
        commit = str(source.get("commit", "")).strip()
        if not provider or not repository or not commit:
            continue

        items = canonical.get("files") or canonical.get("evidence", {}).get("items") or []
        indexed.append({
            "source": f"{provider}/{repository}",
            "commit": commit,
            "manifest": root_relative(canonical_manifest_path),
            "file_count": len(items),
        })

    indexed_by_key = {}
    for item in indexed:
        indexed_by_key[(item["source"], item["commit"])] = item

    index_sources = sorted(
        indexed_by_key.values(),
        key=lambda item: (item["source"], item["commit"]),
    )
    index = {
        "schema": "hico.source-evidence-index.v1",
        "version": 1,
        "description": "Deterministic index of canonical relationship evidence stored in the evidence tree.",
        "generated_from": "canonical-evidence-tree",
        "input_root_kind": "repository" if data_root.resolve().is_relative_to(ROOT.resolve()) else "external",
        "repository_count": len(index_sources),
        "file_count": sum(item["file_count"] for item in index_sources),
        "sources": index_sources,
    }
    (output_root / "index.json").write_text(
        json.dumps(index, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )
    return {
        "manifests_scanned": len(manifests),
        "sources_exported": len(exported),
        "files_exported": total_files,
        "missing_source_manifests": missing_source,
        "failures": failures,
        "output": root_relative(output_root),
    }


def verify(root: Path) -> dict:
    errors: list[str] = []
    manifests = []
    canonical_manifests = []
    if root.is_dir():
        manifests = sorted(
            path for path in root.rglob("manifest.json")
            if path.is_file() and path.name == "manifest.json"
        )
    for manifest_path in manifests:
        try:
            manifest = load_json(manifest_path)
        except (OSError, json.JSONDecodeError) as exc:
            errors.append(f"{root_relative(manifest_path)}: invalid JSON: {exc}")
            continue
        if manifest.get("schema") != SCHEMA:
            continue
        canonical_manifests.append(manifest_path)
        source = manifest.get("source", {})
        for required in ("provider", "repository", "branch", "commit"):
            if not source.get(required):
                errors.append(f"{root_relative(manifest_path)}: source.{required} missing")
        for item in manifest.get("files", []):
            path = str(item.get("raw_path") or item.get("path") or "")
            target = Path(path)
            if not target.is_absolute():
                target = ROOT / target
            if not target.is_file():
                errors.append(f"{root_relative(manifest_path)}: missing evidence file: {path}")
                continue
            data = target.read_bytes()
            if len(data) != item.get("size"):
                errors.append(f"{root_relative(manifest_path)}: size mismatch: {path}")
            if sha256_bytes(data) != item.get("sha256"):
                errors.append(f"{root_relative(manifest_path)}: checksum mismatch: {path}")
    index_path = root / "index.json"
    index_ok = index_path.is_file()
    if root.is_dir() and not index_ok:
        errors.append(f"{root_relative(root)}: index.json missing")
    return {
        "schema": "hico.source-evidence-verification.v1",
        "manifest_count": len(canonical_manifests),
        "index_present": index_ok,
        "errors": errors,
    }


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)

    p = sub.add_parser("extract", help="copy relationship evidence from collector manifests into sources/evidence")
    p.add_argument("--data", default=str(ROOT / "thermal-data"))
    p.add_argument("--output", default=str(ROOT / "sources" / "evidence"))
    p.add_argument("--source", action="append", default=[], help="provider/repository or repository; may be repeated")

    p = sub.add_parser("verify", help="verify canonical evidence manifests and checksums")
    p.add_argument("--root", default=str(ROOT / "sources" / "evidence"))

    args = parser.parse_args()
    if args.command == "extract":
        result = extract(Path(args.data), Path(args.output), args.source)
        print(json.dumps(result, indent=2, sort_keys=True))
        return 1 if result["failures"] else 0
    if args.command == "verify":
        result = verify(Path(args.root))
        print(json.dumps(result, indent=2, sort_keys=True))
        return 1 if result["errors"] else 0
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
