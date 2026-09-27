#!/usr/bin/env python3
from __future__ import annotations
import importlib.util
import json
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
spec = importlib.util.spec_from_file_location("hico_relationships", ROOT / "tools/hico_relationships.py")
assert spec and spec.loader
h = importlib.util.module_from_spec(spec)
spec.loader.exec_module(h)

repos = [
    {"provider":"github","source_id":"lineageos","full_name":"LineageOS/android_device_xiaomi_garnet","vendor":"xiaomi","device":"garnet","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"device"},
    {"provider":"gitlab","source_id":"tadiphone-redmi","full_name":"dumps/redmi/garnet","vendor":"xiaomi","device":"garnet","ecosystem":"oem","rom_family":"stock-oem","repository_role":""},
    {"provider":"github","source_id":"lineageos","full_name":"LineageOS/android_kernel_xiaomi_sm7435","vendor":"xiaomi","device":"sm7435","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"kernel"},
    {"provider":"github","source_id":"lineageos","full_name":"LineageOS/android_kernel_motorola_sm7435","vendor":"motorola","device":"sm7435","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"kernel"},
]
rels, summary = h.build_relationships(repos, {})
def has(suffix, typ, target):
    return any(r["source"].endswith(suffix) and r["type"] == typ and r["target"] == target for r in rels)
assert summary["repository_count"] == 4
assert has("github/LineageOS/android_device_xiaomi_garnet", "device-source", "xiaomi/garnet")
assert has("gitlab/dumps/redmi/garnet", "firmware-device", "xiaomi/garnet")
assert has("github/LineageOS/android_kernel_xiaomi_sm7435", "platform-source", "platform/sm7435")
assert has("github/LineageOS/android_kernel_motorola_sm7435", "platform-source", "platform/sm7435")
assert not any(r["source"].endswith("github/LineageOS/android_kernel_motorola_sm7435") and r["target"] == "xiaomi/garnet" for r in rels)
assert not any(r["type"] == "kernel-device-exact" for r in rels)
with tempfile.TemporaryDirectory() as td:
    root = Path(td)
    dataset = root / "custom-rom/xiaomi/lineageos/garnet/unknown/device/test"
    raw = dataset / "raw"
    raw.mkdir(parents=True)
    (raw / "lineage.dependencies").write_text(json.dumps([
        {"repository": "android_kernel_xiaomi_sm7435", "target_path": "kernel/xiaomi/sm7435"},
        {"repository": "android_hardware_xiaomi", "target_path": "hardware/xiaomi"},
    ]), encoding="utf-8")
    (raw / "BoardConfig.mk").write_text(
        "TARGET_KERNEL_SOURCE := kernel/xiaomi/sm7435\n"
        "TARGET_KERNEL_EXT_MODULE_ROOT := kernel/xiaomi/sm7435-modules\n"
        "include vendor/xiaomi/garnet/BoardConfigVendor.mk\n",
        encoding="utf-8",
    )
    (dataset / "manifest.json").write_text(json.dumps({
        "source": {"provider": "github", "repository": "LineageOS/android_device_xiaomi_garnet"},
        "files": [
            {"tree_path": "lineage.dependencies", "raw_path": str(raw / "lineage.dependencies")},
            {"tree_path": "BoardConfig.mk", "raw_path": str(raw / "BoardConfig.mk")},
        ],
    }), encoding="utf-8")
    rels2, _ = h.build_relationships(
        repos + [{"provider":"github","full_name":"LineageOS/android_hardware_xiaomi","vendor":"xiaomi","device":"","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"hardware"}],
        {},
        [root],
    )
    dep_targets = {(r["type"], r["target"]) for r in rels2 if r["source_repository"] == "LineageOS/android_device_xiaomi_garnet"}
    assert ("dependency-source", "github/LineageOS/android_kernel_xiaomi_sm7435") in dep_targets
    assert ("dependency-source", "github/LineageOS/android_hardware_xiaomi") in dep_targets
    assert ("build-path-reference", "build-path/kernel/xiaomi/sm7435") in dep_targets
    assert ("build-path-reference", "build-path/vendor/xiaomi/garnet/BoardConfigVendor.mk") in dep_targets

normalized, changed = h.normalize_index(repos)
assert changed == 1 and normalized[1]["repository_role"] == "firmware"
with tempfile.TemporaryDirectory() as td:
    p = Path(td) / "repositories.json"
    p.write_text(json.dumps({"schema":"hico.repositories.v1","repositories":repos}), encoding="utf-8")
    assert len(h.load_repositories(p)) == 4
print("HiCo universal source relationship test: PASS")
