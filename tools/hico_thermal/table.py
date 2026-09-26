from __future__ import annotations

import csv
import json
import re
from pathlib import Path
from typing import Iterable


_FLOAT_RE = re.compile(r"(?<![A-Za-z0-9_.-])(-?(?:\d+(?:\.\d*)?|\.\d+))(?:\s*°?C)?")
_TEMPLATE_RE = re.compile(
    r"^\|\s*(?P<file>[^|]+)\|\s*(?P<section>[^|]+)\|\s*`?(?P<device>[^`|]+?)`?\s*\|\s*`?(?P<sensor>[^`|]+?)`?\s*\|\s*(?P<stock>[^|]+)\|\s*(?P<tuned>[^|]+)\|\s*$"
)

_ARTIFACT_FIELDS = [
    "vendor",
    "codename",
    "artifact",
    "path",
    "format",
    "codec",
    "parser",
    "decode_status",
    "original_max_trip_c",
    "highest_trip_type",
    "shutdown_c",
    "hico_candidate_max_trip_c",
    "delta_c",
    "source",
]

_TUNING_FIELDS = [
    "vendor",
    "codename",
    "platform",
    "policy",
    "margin_c",
    "file",
    "section",
    "device",
    "sensor",
    "original_max_trip_c",
    "hico_candidate_max_trip_c",
    "delta_c",
    "original_trips_c",
    "hico_candidate_trips_c",
    "source",
]


def _numbers(value: str) -> list[float]:
    return [float(match.group(1)) for match in _FLOAT_RE.finditer(value)]


def _max_or_none(values: Iterable[float]) -> float | None:
    values = list(values)
    return max(values) if values else None


def _relative_identity(path: str) -> tuple[str, str]:
    parts = Path(path).as_posix().split("/")
    if len(parts) >= 3 and parts[0] == "devices":
        return parts[1], parts[2]
    if len(parts) >= 3 and parts[0] == "sources":
        return parts[1], parts[2]
    return "unknown", "unknown"


def _load_mappings(database_root: Path) -> list[dict]:
    mapped = database_root / "mapped"
    rows: list[dict] = []
    if not mapped.is_dir():
        return rows
    for path in sorted(mapped.rglob("*.json")):
        try:
            data = json.loads(path.read_text())
        except (OSError, json.JSONDecodeError):
            continue
        if not isinstance(data, dict) or not str(data.get("schema", "")).startswith("hico.artifact-map"):
            continue
        for artifact in data.get("artifacts", []):
            if not isinstance(artifact, dict):
                continue
            source_path = str(artifact.get("path", ""))
            mapped_root = str(data.get("root", ""))
            combined = source_path
            if mapped_root and not source_path.startswith("devices/") and not source_path.startswith("sources/"):
                combined = f"{mapped_root.rstrip('/')}/{source_path}"
            vendor, codename = _relative_identity(combined)
            original = artifact.get("max_trip_c")
            if original is None:
                original = artifact.get("decoded_max_trip_c")
            rows.append({
                "vendor": vendor,
                "codename": codename,
                "artifact": str(artifact.get("name", Path(source_path).name)),
                "path": combined,
                "format": artifact.get("decoded_format") or artifact.get("format"),
                "codec": artifact.get("codec"),
                "parser": artifact.get("decoded_parser") or artifact.get("parser"),
                "decode_status": artifact.get("decode_status"),
                "original_max_trip_c": original,
                "highest_trip_type": None,
                "shutdown_c": artifact.get("shutdown_c"),
                "hico_candidate_max_trip_c": None,
                "delta_c": None,
                "source": "mapped-artifact",
            })
    return rows


def _load_tuning_templates(root: Path) -> list[dict]:
    rows: list[dict] = []
    for template in sorted(root.glob("devices/*/*/tuned/TEMPLATE.md")):
        parts = template.relative_to(root).parts
        if len(parts) < 5:
            continue
        vendor, codename = parts[1], parts[2]
        text = template.read_text(errors="replace")
        platform = ""
        policy = ""
        margin = None
        header = re.search(r"Platform `([^`]*)`, policy \*\*([^*]+)\*\*, margin ([0-9.]+) °C", text)
        if header:
            platform, policy, margin = header.group(1), header.group(2), float(header.group(3))

        in_table = False
        for line in text.splitlines():
            if line.strip().startswith("| File | Section |"):
                in_table = True
                continue
            if not in_table or line.strip().startswith("|---"):
                continue
            match = _TEMPLATE_RE.match(line)
            if not match:
                continue
            stock_text = match.group("stock").strip()
            tuned_text = match.group("tuned").strip()
            stock = _numbers(stock_text)
            tuned = _numbers(tuned_text)
            if not stock and not tuned:
                continue
            original = _max_or_none(stock)
            candidate = _max_or_none(tuned)
            rows.append({
                "vendor": vendor,
                "codename": codename,
                "platform": platform,
                "policy": policy,
                "margin_c": margin,
                "file": match.group("file").strip(),
                "section": match.group("section").strip(),
                "device": match.group("device").strip().strip("`"),
                "sensor": match.group("sensor").strip().strip("`"),
                "original_max_trip_c": original,
                "hico_candidate_max_trip_c": candidate,
                "delta_c": (candidate - original) if candidate is not None and original is not None else None,
                "original_trips_c": stock,
                "hico_candidate_trips_c": tuned,
                "source": "HiCo tuning template",
            })
    return rows


def build_thermal_table(root: str | Path) -> dict:
    root = Path(root)
    artifacts = _load_mappings(root / "database")
    tuning = _load_tuning_templates(root)

    # Overlay a file-level candidate maximum onto the artifact table. The source of
    # that candidate is explicit: it is a HiCo candidate generated from the device's
    # own tuning template, never a claim about a measured safe maximum.
    candidates: dict[tuple[str, str, str], float] = {}
    for row in tuning:
        key = (row["vendor"], row["codename"], row["file"])
        value = row["hico_candidate_max_trip_c"]
        if value is not None:
            candidates[key] = max(candidates.get(key, value), value)

    for row in artifacts:
        path = row["path"]
        file_name = Path(path).name
        key = (row["vendor"], row["codename"], file_name)
        candidate = candidates.get(key)
        row["hico_candidate_max_trip_c"] = candidate
        if candidate is not None and row["original_max_trip_c"] is not None:
            row["delta_c"] = candidate - row["original_max_trip_c"]

    tuning.sort(key=lambda r: (r["vendor"], r["codename"], r["file"], r["section"], r["device"], r["sensor"]))
    artifacts.sort(key=lambda r: (r["vendor"], r["codename"], r["path"]))

    return {
        "schema": "hico.thermal-table.v1",
        "description": "Original thermal trip values and HiCo candidate values derived from the device's own tuning rules.",
        "value_semantics": {
            "original_max_trip_c": "Highest trip threshold present in the original mapped artifact/section.",
            "hico_candidate_max_trip_c": "Highest trip threshold produced by HiCo's validated tuning policy for the same artifact/section; candidate only, not a measured safety limit.",
            "delta_c": "HiCo candidate minus original, in degrees Celsius.",
        },
        "summary": {
            "artifact_rows": len(artifacts),
            "tuning_rows": len(tuning),
            "rows_with_hico_candidate": sum(1 for r in tuning if r["hico_candidate_max_trip_c"] is not None),
            "rows_with_delta": sum(1 for r in tuning if r["delta_c"] is not None),
        },
        "artifacts": artifacts,
        "tuning": tuning,
    }


def _write_csv(path: Path, rows: list[dict], fields: list[str]) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=fields, extrasaction="ignore")
        writer.writeheader()
        for row in rows:
            writer.writerow(row)


def _fmt(value: object) -> str:
    if value is None:
        return "–"
    if isinstance(value, float):
        return f"{value:g}"
    return str(value)


def write_thermal_table(root: str | Path, output_dir: str | Path | None = None) -> dict:
    root = Path(root)
    output = Path(output_dir) if output_dir else root / "database" / "tables"
    table = build_thermal_table(root)
    output.mkdir(parents=True, exist_ok=True)
    (output / "thermal.json").write_text(json.dumps(table, indent=2, sort_keys=True) + "\n")
    _write_csv(output / "thermal-artifacts.csv", table["artifacts"], _ARTIFACT_FIELDS)
    _write_csv(output / "thermal-tuning.csv", table["tuning"], _TUNING_FIELDS)

    lines = [
        "# HiCo Thermal Table",
        "",
        table["description"],
        "",
        "`original_max_trip_c` is the highest value found in the source artifact/section.",
        "`hico_candidate_max_trip_c` is the highest value produced by HiCo's tuning policy for the same source scope. It is a candidate, not a measured or certified safe temperature.",
        "",
        f"Artifacts: **{table['summary']['artifact_rows']}** · tuning rows: **{table['summary']['tuning_rows']}** · tuning rows with candidate: **{table['summary']['rows_with_hico_candidate']}**",
        "",
        "## Tuning table",
        "",
        "| Vendor | Device | File | Section | Sensor | Original max °C | HiCo candidate max °C | Delta °C | Stock trips °C | HiCo trips °C |",
        "|---|---|---|---|---|---:|---:|---:|---|---|",
    ]
    for row in table["tuning"]:
        def trips(values: list[float]) -> str:
            return " ".join(_fmt(v) for v in values) if values else "–"
        lines.append(
            f"| {row['vendor']} | `{row['codename']}` | `{row['file']}` | `{row['section']}` | `{row['sensor']}` | "
            f"{_fmt(row['original_max_trip_c'])} | {_fmt(row['hico_candidate_max_trip_c'])} | {_fmt(row['delta_c'])} | "
            f"{trips(row['original_trips_c'])} | {trips(row['hico_candidate_trips_c'])} |"
        )
    (output / "THERMAL_TABLE.md").write_text("\n".join(lines) + "\n")
    return table
