#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SCHEMA = ROOT / "database" / "schema" / "universal.v1.schema.json"

OEM_ALIASES = {
    "xiaomi": "xiaomi", "redmi": "xiaomi", "poco": "xiaomi",
    "samsung": "samsung", "oneplus": "oneplus", "oppo": "oppo",
    "realme": "realme", "vivo": "vivo", "motorola": "motorola",
    "google": "google", "sony": "sony", "asus": "asus", "nothing": "nothing",
}
SOC_PREFIXES = (
    ("qualcomm", ("msm", "sdm", "sm", "apq", "qcs")),
    ("mediatek", ("mt", "mediatek")),
    ("unisoc", ("ums", "sp", "unisoc")),
    ("exynos", ("exynos", "universal", "s5e")),
    ("tensor", ("gs",)),
)


def clean(value: str, fallback: str = "unknown") -> str:
    value = re.sub(r"[^A-Za-z0-9._-]+", "_", value.strip().lower())
    return value or fallback


def infer_soc(platform: str) -> str:
    p = platform.strip().lower()
    if not p:
        return "unknown"
    if p in {"zuma", "zumapro", "laguna"}:
        return "tensor"
    for vendor, prefixes in SOC_PREFIXES:
        if any(p.startswith(x) for x in prefixes):
            return vendor
    if p in {"kalam", "kalama", "lahaina", "taro", "pineapple", "parrot", "crow", "volcano",
             "blair", "khaje", "monaco", "neo", "anorak", "niobe", "cliffs", "ravelin",
             "seraph", "tuna"}:
        return "qualcomm"
    return "unknown"


def infer_device_id(identity: dict) -> str:
    oem = clean(str(identity.get("vendor", "unknown")))
    codename = clean(str(identity.get("device", "unknown")))
    return f"{oem}/{codename}"


ROM_NAMES = {
    "hyperos": "HyperOS",
    "miui": "MIUI",
    "oneui": "One UI",
    "oxygenos": "OxygenOS",
    "coloros": "ColorOS",
    "realmeui": "realme UI",
    "lineageos": "LineageOS",
    "evolution-x": "Evolution X",
    "pixelos": "PixelOS",
    "crdroid": "crDroid",
    "aospa": "Paranoid Android",
    "arrowos": "ArrowOS",
    "derpfest": "DerpFest",
    "voltageos": "VoltageOS",
    "superioros": "SuperiorOS",
    "project-elixir": "Project Elixir",
    "aosp": "AOSP",
    "stock-oem": "OEM Stock",
}


def rom_name(family: str, oem: str) -> str:
    return ROM_NAMES.get(family, family.replace("-", " ").title())


def rom_id(identity: dict) -> str:
    family = clean(str(identity.get("rom_family", "unknown")))
    android = clean(str(identity.get("android", "unknown")))
    return f"{family}/{android}"


def source_layer(manifest: dict) -> str:
    paths = [str(x.get("tree_path", x.get("path", ""))).lower() for x in manifest.get("files", [])]
    for layer, needles in (
        ("kernel", ("/kernel/", "kernel_", "kernel/")),
        ("device-tree", ("dts/", ".dts", ".dtsi")),
        ("vendor", ("vendor/", "vendor_")),
        ("odm", ("odm/", "odm_")),
        ("system_ext", ("system_ext/",)),
        ("product", ("product/",)),
        ("system", ("system/",)),
        ("hal", ("android.hardware.", "hardware/interfaces/thermal", "thermalhal")),
        ("init", ("init.", "/etc/init/", "etc/init/")),
    ):
        if any(n in p for p in paths for n in needles):
            return layer
    role = str(manifest.get("identity", {}).get("repository_role", "unknown"))
    return role if role in {"firmware", "vendor", "device", "kernel", "hardware", "rom", "hal", "init", "mod", "independent", "source"} else "unknown"


def build(root: Path) -> dict:
    thermal_root = root / "thermal-data"
    devices: dict[str, dict] = {}
    roms: dict[str, dict] = {}
    sources: dict[str, dict] = {}

    for manifest_path in sorted(thermal_root.rglob("manifest.json")) if thermal_root.is_dir() else []:
        try:
            manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError):
            continue
        if manifest.get("schema") != "hico.thermal-source.v1":
            continue

        identity = manifest.get("identity", {})
        source = manifest.get("source", {})
        device_id = infer_device_id(identity)
        family = clean(str(identity.get("rom_family", "unknown")))
        android = clean(str(identity.get("android", "unknown")))
        rid = f"{family}/{android}"
        oem = clean(str(identity.get("vendor", "unknown")))
        platform = str(identity.get("platform", ""))
        sid = f"{source.get('provider', 'unknown')}/{source.get('repository', 'unknown')}@{source.get('commit', 'unknown')}"

        devices.setdefault(device_id, {
            "id": device_id,
            "oem": oem,
            "codename": clean(str(identity.get("device", "unknown"))),
            "brand": "",
            "model": "",
            "platform": platform,
            "soc_vendor": infer_soc(platform),
            "aliases": [],
            "thermal_source_ids": [],
            "rom_ids": [],
        })
        roms.setdefault(rid, {
            "id": rid,
            "family": family,
            "name": rom_name(family, oem),
            "version": "",
            "android": android,
            "ecosystem": str(identity.get("ecosystem", "independent")),
            "oem": oem,
            "device_ids": [],
            "thermal_source_ids": [],
        })

        files = manifest.get("files", [])
        formats = sorted({
            str(x.get("format", "")).strip()
            for x in files
            if str(x.get("format", "")).strip()
        })
        src = {
            "id": sid,
            "device_id": device_id,
            "rom_id": rid,
            "ecosystem": str(identity.get("ecosystem", "independent")),
            "oem": oem,
            "repository_role": str(identity.get("repository_role", "unknown")),
            "source_layer": source_layer(manifest),
            "formats": formats,
            "repository": {
                "provider": str(source.get("provider", "unknown")),
                "repository": str(source.get("repository", "unknown")),
                "branch": str(source.get("branch", "unknown")),
                "commit": str(source.get("commit", "unknown")),
                "url": str(source.get("url", "")),
            },
            "artifact_count": len(files),
            "raw_artifact_count": sum(1 for x in files if x.get("storage") == "raw"),
            "manifest": str(manifest_path.relative_to(root)).replace("\\", "/"),
        }
        sources[sid] = src

        devices[device_id]["platform"] = devices[device_id]["platform"] or platform
        devices[device_id]["soc_vendor"] = infer_soc(devices[device_id]["platform"])
        if sid not in devices[device_id]["thermal_source_ids"]:
            devices[device_id]["thermal_source_ids"].append(sid)
        if rid not in devices[device_id]["rom_ids"]:
            devices[device_id]["rom_ids"].append(rid)
        if device_id not in roms[rid]["device_ids"]:
            roms[rid]["device_ids"].append(device_id)
        if sid not in roms[rid]["thermal_source_ids"]:
            roms[rid]["thermal_source_ids"].append(sid)

    # Preserve the existing runtime device universe even before all of its thermal
    # sources have been normalized into thermal-data.
    for prop in sorted((root / "devices").glob("*/*.prop")) if (root / "devices").is_dir() else []:
        props = {}
        for line in prop.read_text(errors="replace").splitlines():
            if "=" in line and not line.startswith("#"):
                k, v = line.split("=", 1)
                props[k.strip()] = v.strip()
        oem = clean(prop.parent.name)
        codename = clean(props.get("codename", prop.stem))
        device_id = f"{oem}/{codename}"
        devices.setdefault(device_id, {
            "id": device_id,
            "oem": oem,
            "codename": codename,
            "brand": props.get("brand", ""),
            "model": props.get("model", ""),
            "platform": props.get("platform", ""),
            "soc_vendor": infer_soc(props.get("platform", "")),
            "aliases": [],
            "thermal_source_ids": [],
            "rom_ids": [],
        })
        rec = devices[device_id]
        rec["brand"] = rec["brand"] or props.get("brand", "")
        rec["model"] = rec["model"] or props.get("model", "")
        rec["platform"] = rec["platform"] or props.get("platform", "")
        rec["soc_vendor"] = infer_soc(rec["platform"])

    result = {
        "schema": "hico.universal.v1",
        "version": 1,
        "devices": sorted(devices.values(), key=lambda x: x["id"]),
        "roms": sorted(roms.values(), key=lambda x: x["id"]),
        "thermal_sources": sorted(sources.values(), key=lambda x: x["id"]),
        "stats": {
            "device_count": len(devices),
            "rom_count": len(roms),
            "thermal_source_count": len(sources),
            "oem_count": len({x["oem"] for x in devices.values()}),
        },
    }
    return result


def validate(data: dict) -> list[str]:
    errors: list[str] = []
    if data.get("schema") != "hico.universal.v1" or data.get("version") != 1:
        errors.append("unsupported universal schema")
        return errors
    devices = {x.get("id"): x for x in data.get("devices", [])}
    roms = {x.get("id"): x for x in data.get("roms", [])}
    sources = {x.get("id"): x for x in data.get("thermal_sources", [])}

    if len(devices) != len(data.get("devices", [])):
        errors.append("duplicate device ids")
    if len(roms) != len(data.get("roms", [])):
        errors.append("duplicate ROM ids")
    if len(sources) != len(data.get("thermal_sources", [])):
        errors.append("duplicate thermal source ids")

    for d in devices.values():
        for rid in d.get("rom_ids", []):
            if rid not in roms:
                errors.append(f"{d['id']}: unknown rom_id {rid}")
        for sid in d.get("thermal_source_ids", []):
            if sid not in sources:
                errors.append(f"{d['id']}: unknown thermal_source_id {sid}")

    for r in roms.values():
        for did in r.get("device_ids", []):
            if did not in devices:
                errors.append(f"{r['id']}: unknown device_id {did}")
        for sid in r.get("thermal_source_ids", []):
            if sid not in sources:
                errors.append(f"{r['id']}: unknown thermal_source_id {sid}")

    for s in sources.values():
        if s.get("device_id") not in devices:
            errors.append(f"{s['id']}: unknown device_id {s.get('device_id')}")
        if s.get("rom_id") not in roms:
            errors.append(f"{s['id']}: unknown rom_id {s.get('rom_id')}")
        if s.get("artifact_count", 0) < s.get("raw_artifact_count", 0):
            errors.append(f"{s['id']}: raw_artifact_count exceeds artifact_count")
        repo = s.get("repository", {})
        for key in ("provider", "repository", "branch", "commit"):
            if not repo.get(key):
                errors.append(f"{s['id']}: repository.{key} missing")
    return errors


def main() -> int:
    ap = argparse.ArgumentParser(description="Build/validate the universal HiCo device-ROM-thermal index.")
    sub = ap.add_subparsers(dest="command", required=True)

    p = sub.add_parser("build")
    p.add_argument("--root", default=str(ROOT))
    p.add_argument("--output", default=str(ROOT / "database" / "universal"))

    p = sub.add_parser("validate")
    p.add_argument("--input", default=str(ROOT / "database" / "universal" / "index.json"))

    args = ap.parse_args()
    if args.command == "build":
        root = Path(args.root)
        out = Path(args.output)
        out.mkdir(parents=True, exist_ok=True)
        data = build(root)
        path = out / "index.json"
        path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")
        errors = validate(data)
        print(json.dumps({"output": str(path), "errors": errors, "stats": data["stats"]}, indent=2))
        return 1 if errors else 0

    data = json.loads(Path(args.input).read_text(encoding="utf-8"))
    errors = validate(data)
    print(json.dumps({
        "schema": data.get("schema"),
        "version": data.get("version"),
        "errors": errors,
        "stats": data.get("stats", {}),
    }, indent=2))
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
