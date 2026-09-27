#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOL = ROOT / "tools" / "hico_dependency_resolver.py"

spec = importlib.util.spec_from_file_location("hico_dependency_resolver", TOOL)
assert spec and spec.loader
mod = importlib.util.module_from_spec(spec)
spec.loader.exec_module(mod)

repos = [
    {"provider": "github", "full_name": "LineageOS/android_device_xiaomi_garnet"},
    {"provider": "github", "full_name": "LineageOS/android_kernel_xiaomi_sm7435"},
    {"provider": "gitlab", "full_name": "Other/android_kernel_xiaomi_sm7435"},
    {"provider": "github", "full_name": "LineageOS/android_hardware_xiaomi"},
]

assert mod.normalize_reference("https://github.com/LineageOS/android_device_xiaomi_garnet.git") == (
    "lineageos/android_device_xiaomi_garnet"
)

exact = mod.resolve_dependency("LineageOS/android_device_xiaomi_garnet.git", repos)
assert exact["status"] == "resolved"
assert exact["strategy"] == "exact-full-name"

ambiguous = mod.resolve_dependency("android_kernel_xiaomi_sm7435", repos)
assert ambiguous["status"] == "ambiguous"
assert ambiguous["strategy"] == "ambiguous-basename"
assert len(ambiguous["candidates"]) == 2

unique = mod.resolve_dependency("android_hardware_xiaomi", repos)
assert unique["status"] == "resolved"
assert unique["strategy"] == "unique-basename"

missing = mod.resolve_dependency("android_vendor_xiaomi_unknown", repos)
assert missing["status"] == "unresolved"
assert missing["strategy"] == "no-match"

print("HiCo dependency resolver test: PASS")
