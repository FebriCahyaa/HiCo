#!/usr/bin/env python3
from __future__ import annotations

import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

PILOT = {
    "github/LineageOS/android_device_xiaomi_garnet": "xiaomi",
    "github/LineageOS/android_device_motorola_berlin": "motorola",
    "github/LineageOS/android_device_samsung_a52q": "samsung",
    "github/LineageOS/android_device_oneplus_avalon": "oneplus",
}


def load(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def main() -> int:
    evidence_root = ROOT / "sources/evidence"
    index = load(evidence_root / "index.json")
    sources = {
        item["source"]: item
        for item in index.get("sources", [])
        if isinstance(item, dict) and item.get("source")
    }

    relationships = load(ROOT / "sources/relationships.json")
    rels = relationships.get("relationships", [])

    for source, vendor in PILOT.items():
        assert source in sources, f"missing canonical pilot source: {source}"
        manifest = Path(sources[source]["manifest"])
        if not manifest.is_absolute():
            manifest = ROOT / manifest
        assert manifest.is_file(), f"missing canonical manifest: {manifest}"

        data = load(manifest)
        trees = {
            item.get("tree_path")
            for item in data.get("files", [])
            if isinstance(item, dict)
        }
        assert {"BoardConfig.mk", "lineage.dependencies"} <= trees, (
            f"{source}: expected canonical relationship evidence files, got {sorted(trees)}"
        )

        scoped = [r for r in rels if r.get("source") == source]
        assert any(
            r.get("type") in {
                "dependency-source",
                "dependency-source-unresolved",
                "build-path-reference",
            }
            and set(r.get("evidence", [])) & {"lineage.dependencies", "BoardConfig.mk"}
            for r in scoped
        ), f"{source}: no evidence-backed relationship"

        for rel in scoped:
            if rel.get("type") in {
                "device-source",
                "firmware-device",
                "vendor-device",
                "hardware-device-exact",
                "hal-device-exact",
                "init-device-exact",
            }:
                assert str(rel.get("target", "")).startswith(vendor + "/"), (
                    f"{source}: cross-OEM identity edge -> {rel.get('target')}"
                )

    print("HiCo multi-OEM evidence pilot test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
