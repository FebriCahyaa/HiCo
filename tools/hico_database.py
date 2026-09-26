#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import shutil
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOL_ROOT = ROOT / "tools"
if str(TOOL_ROOT) not in sys.path:
    sys.path.insert(0, str(TOOL_ROOT))

from hico_thermal.artifacts import analyze_file, walk_relevant
from hico_thermal.table import write_thermal_table

PROP_RE = re.compile(r"^([A-Za-z0-9_.-]+)=(.*)$")
SHA_RE = re.compile(r"[0-9a-f]{64}")


def read_prop(path: Path) -> dict[str, str]:
    data: dict[str, str] = {}
    for line in path.read_text(errors="replace").splitlines():
        if not line or line.startswith("#"):
            continue
        match = PROP_RE.match(line)
        if match:
            data.setdefault(match.group(1), match.group(2).strip())
    return data


def clean_component(value: str) -> str:
    value = value.strip().lower()
    value = re.sub(r"[^a-z0-9._-]+", "_", value)
    return value[:96] or "unknown"


def device_record(prop: Path, device_root: Path, root: Path) -> dict:
    values = read_prop(prop)
    codename = values.get("codename", prop.stem)
    thermal_dir = device_root / "thermal"
    artifacts = []
    if thermal_dir.is_dir():
        for path in sorted(thermal_dir.iterdir()):
            if not path.is_file() or path.name == "index.tsv":
                continue
            info = analyze_file(path)
            info["storage"] = "repository-artifact"
            artifacts.append(info)

    return {
        "schema": "hico.device.v1",
        "identity": {
            "codename": codename,
            "brand": values.get("brand", ""),
            "model": values.get("model", ""),
            "platform": values.get("platform", ""),
            "android": values.get("android", ""),
        },
        "source": {
            "url": values.get("source", ""),
            "kind": "oem-firmware-dump",
        },
        "thermal": {
            "mi_thermald": values.get("mi_thermald", "0") == "1",
            "services": [x for x in values.get("thermal_services", "").split(",") if x],
            "config_names": [x for x in values.get("thermal_configs", "").split(",") if x],
            "artifact_count": len(artifacts),
            "artifacts": artifacts,
        },
        "provenance": {
            "source_file": str(prop.resolve().relative_to(root.resolve())).replace("\\", "/"),
        },
    }


def build_database(root: Path, out: Path) -> dict:
    out.mkdir(parents=True, exist_ok=True)
    devices_out = out / "devices"
    if devices_out.exists():
        shutil.rmtree(devices_out)
    devices_out.mkdir(parents=True)
    records = []
    for prop in sorted(root.glob("devices/*/*.prop")):
        vendor = prop.parent.name
        device_root = prop.parent / prop.stem
        record = device_record(prop, device_root, root)
        device_dir = devices_out / clean_component(vendor) / clean_component(prop.stem)
        device_dir.mkdir(parents=True, exist_ok=True)
        (device_dir / "profile.json").write_text(json.dumps(record, indent=2, sort_keys=True) + "\n")
        records.append({
            "vendor": vendor,
            "codename": prop.stem,
            "platform": record["identity"]["platform"],
            "android": record["identity"]["android"],
            "thermal_artifacts": len(record["thermal"]["artifacts"]),
            "source": record["source"]["url"],
        })

    records.sort(key=lambda r: (r["vendor"], r["codename"]))
    index = {
        "schema": "hico.database.v1",
        "generated_from": "repository devices/*/*.prop",
        "device_count": len(records),
        "artifact_count": sum(r["thermal_artifacts"] for r in records),
        "devices": records,
    }
    (out / "index.json").write_text(json.dumps(index, indent=2, sort_keys=True) + "\n")
    return index


def map_external_tree(root: Path, out: Path) -> dict:
    out.mkdir(parents=True, exist_ok=True)
    records = []
    for path in walk_relevant(root):
        rel = path.relative_to(root)
        record = analyze_file(path)
        record["relative_path"] = str(rel).replace("\\", "/")
        records.append(record)
    result = {
        "schema": "hico.artifact-index.v1",
        "root": str(root),
        "artifact_count": len(records),
        "artifacts": records,
    }
    (out / "artifact-index.json").write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    return result


def merge_ingest(input_root: Path, out: Path) -> dict:
    target = out / "sources" / "ingested"
    if target.exists():
        shutil.rmtree(target)
    manifests_out = target / "manifests"
    raw_out = target / "raw"
    manifests_out.mkdir(parents=True)
    raw_out.mkdir(parents=True)
    merged = []
    errors = []
    for summary_path in sorted(input_root.rglob("summary.json")):
        try:
            summary = json.loads(summary_path.read_text())
            if summary.get("failures"):
                errors.extend(summary["failures"])
        except (OSError, json.JSONDecodeError) as exc:
            errors.append({"file": str(summary_path), "error": str(exc)})
    for manifest_path in sorted(input_root.rglob("manifests/*.json")):
        try:
            manifest = json.loads(manifest_path.read_text())
            if manifest.get("schema") not in {"hico.repository.v1", "hico.repository.v2"}:
                errors.append({"file": str(manifest_path), "error": "unsupported manifest schema"})
                continue
            source = manifest.get("source", {})
            source_id = clean_component(str(source.get("id", "unknown")))
            repo_key = clean_component(str(source.get("repository", manifest_path.stem)))
            dest_manifest = manifests_out / source_id / f"{repo_key}.json"
            dest_manifest.parent.mkdir(parents=True, exist_ok=True)
            raw_root = manifest_path.parent.parent.parent / "raw" / source_id / repo_key
            copied = 0
            for item in manifest.get("files", []):
                rel = item.get("tree_path", item.get("path", ""))
                rel_path = Path(rel)
                if rel_path.is_absolute() or ".." in rel_path.parts:
                    errors.append({"file": str(manifest_path), "error": f"unsafe artifact path: {rel}"})
                    continue
                item["database_storage"] = "metadata-only"
                if item.get("storage", "").startswith("raw-") and (raw_root / rel_path).is_file():
                    dest = raw_out / source_id / repo_key / rel_path
                    dest.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(raw_root / rel_path, dest)
                    item["database_storage"] = str(dest.relative_to(out)).replace("\\", "/")
                    copied += 1
            manifest["merge"] = {"raw_files_copied": copied}
            dest_manifest.write_text(json.dumps(manifest, indent=2, sort_keys=True) + "\n")
            merged.append(manifest)
        except (OSError, json.JSONDecodeError) as exc:
            errors.append({"file": str(manifest_path), "error": str(exc)})

    source_counts = Counter(m.get("source", {}).get("id", "unknown") for m in merged)
    index = {
        "schema": "hico.ingested-database.v1",
        "repository_count": len(merged),
        "artifact_count": sum(len(m.get("files", [])) for m in merged),
        "raw_artifact_count": sum(
            1
            for m in merged
            for f in m.get("files", [])
            if str(f.get("database_storage", "")).startswith("sources/ingested/raw/")
        ),
        "sources": [{"id": key, "repositories": source_counts[key]} for key in sorted(source_counts)],
        "errors": errors,
    }
    (target / "index.json").write_text(json.dumps(index, indent=2, sort_keys=True) + "\n")
    return index


def _mapping_destination(root: Path, mapping_file: Path, database_root: Path) -> Path:
    normalized = str(root).replace("\\", "/").strip("/")
    if normalized.startswith("./"):
        normalized = normalized[2:]
    parts = [part for part in normalized.split("/") if part]
    if "raw" in parts:
        marker = parts.index("raw")
        parts = ["sources", *parts[marker + 1 :]]
    elif "devices" in parts:
        marker = parts.index("devices")
        parts = parts[marker:]
    parts = [clean_component(part) for part in parts]
    if not parts:
        parts = [clean_component(mapping_file.stem)]
    return database_root / "mapped" / Path(*parts[:-1]) / (parts[-1] + ".json")


def merge_mappings(input_root: Path, out: Path) -> dict:
    target = out / "mapped"
    if target.exists():
        shutil.rmtree(target)
    target.mkdir(parents=True)
    merged = []
    errors = []
    for path in sorted(input_root.rglob("*.json")):
        try:
            data = json.loads(path.read_text())
        except (OSError, json.JSONDecodeError) as exc:
            errors.append({"file": str(path), "error": str(exc)})
            continue
        schema = data.get("schema")
        if schema not in {"hico.artifact-map.v2", "hico.artifact-map-set.v2", "hico.artifact-map.v3", "hico.artifact-map-set.v3"}:
            continue
        maps = data.get("maps") if schema in {"hico.artifact-map-set.v2", "hico.artifact-map-set.v3"} else [data]
        if not isinstance(maps, list):
            errors.append({"file": str(path), "error": "mapping set has invalid maps field"})
            continue
        for index, item in enumerate(maps):
            if not isinstance(item, dict):
                errors.append({"file": str(path), "error": f"mapping entry {index} is not an object"})
                continue
            if item.get("failures"):
                errors.extend(item["failures"])
                continue
            root_value = item.get("root") or (item.get("roots") or [""])[0]
            destination = _mapping_destination(Path(str(root_value)), path, out)
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_text(json.dumps(item, indent=2, sort_keys=True) + "\n")
            merged.append(item)

    result = {
        "schema": "hico.mapping-database.v1",
        "mapping_count": len(merged),
        "artifact_count": sum(len(m.get("artifacts", [])) for m in merged),
        "decode_failure_count": sum(len(m.get("failures", [])) for m in merged),
        "failures": errors,
    }
    (target / "index.json").write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    return result


def validate_database(root: Path) -> list[str]:
    errors: list[str] = []
    for path in sorted(root.rglob("*.json")):
        try:
            data = json.loads(path.read_text())
        except (OSError, json.JSONDecodeError) as exc:
            errors.append(f"{path}: invalid JSON: {exc}")
            continue
        schema = data.get("schema") if isinstance(data, dict) else None
        if path.name == "profile.json" and schema != "hico.device.v1":
            errors.append(f"{path}: unexpected device schema")
        if path.parent.name == "manifests" and schema not in {"hico.repository.v1", "hico.repository.v2"}:
            errors.append(f"{path}: unexpected repository manifest schema")
        if schema in {"hico.artifact-map.v2", "hico.artifact-map-set.v2", "hico.artifact-map.v3", "hico.artifact-map-set.v3"}:
            if data.get("failures"):
                errors.append(f"{path}: mapping contains decode/analysis failures")
            if data.get("expansion_failures"):
                errors.append(f"{path}: deep mapping contains unpack failures")
        if schema == "hico.thermal-table.v1":
            semantics = data.get("value_semantics", {})
            for key in ("original_max_trip_c", "hico_candidate_max_trip_c", "delta_c"):
                if key not in semantics:
                    errors.append(f"{path}: thermal table is missing value semantics for {key}")
            if not isinstance(data.get("artifacts"), list) or not isinstance(data.get("tuning"), list):
                errors.append(f"{path}: thermal table artifacts/tuning must be arrays")
        for item in data.get("files", []) if isinstance(data, dict) else []:
            sha = item.get("sha256")
            if sha and not SHA_RE.fullmatch(str(sha)):
                errors.append(f"{path}: invalid SHA-256 for {item.get('path', '')}")
        for item in data.get("artifacts", []) if isinstance(data, dict) else []:
            sha = item.get("sha256")
            if sha and not SHA_RE.fullmatch(str(sha)):
                errors.append(f"{path}: invalid SHA-256 for {item.get('path', '')}")
    return errors


def main() -> int:
    ap = argparse.ArgumentParser(description="Build and validate HiCo's device/thermal knowledge database")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("build")
    p.add_argument("--root", default=str(ROOT))
    p.add_argument("--output", default=str(ROOT / "database"))
    p = sub.add_parser("map-tree")
    p.add_argument("root")
    p.add_argument("--output", required=True)
    p = sub.add_parser("merge-ingest")
    p.add_argument("root")
    p.add_argument("--output", required=True)
    p = sub.add_parser("merge-mappings")
    p.add_argument("root")
    p.add_argument("--output", required=True)
    p = sub.add_parser("thermal-table")
    p.add_argument("--root", default=str(ROOT))
    p.add_argument("--output", default="")
    p = sub.add_parser("validate")
    p.add_argument("root")
    args = ap.parse_args()

    if args.cmd == "build":
        result = build_database(Path(args.root), Path(args.output))
        print(json.dumps({k: result[k] for k in ("device_count", "artifact_count")}, indent=2))
        return 0
    if args.cmd == "map-tree":
        result = map_external_tree(Path(args.root), Path(args.output))
        print(json.dumps({"artifact_count": result["artifact_count"]}, indent=2))
        return 0
    if args.cmd == "merge-ingest":
        result = merge_ingest(Path(args.root), Path(args.output))
        print(json.dumps({k: result[k] for k in ("repository_count", "artifact_count", "raw_artifact_count", "errors")}, indent=2))
        return 1 if result["errors"] else 0
    if args.cmd == "merge-mappings":
        result = merge_mappings(Path(args.root), Path(args.output))
        print(json.dumps(result, indent=2))
        return 1 if result["failures"] else 0
    if args.cmd == "thermal-table":
        output = Path(args.output) if args.output else Path(args.root) / "database" / "tables"
        result = write_thermal_table(Path(args.root), output)
        print(json.dumps(result["summary"], indent=2))
        return 0

    errors = validate_database(Path(args.root))
    for error in errors:
        print(error, file=sys.stderr)
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
