#!/usr/bin/env python3
from __future__ import annotations

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from hico_discovery import merge_repository_records


def main() -> int:
    existing = [
        {"provider": "gitlab", "full_name": "xiaomi/legacy", "ecosystem": "oem"},
        {"provider": "gitlab", "full_name": "xiaomi/preserved", "ecosystem": "oem"},
    ]
    discovered = [
        {"provider": "github", "full_name": "LineageOS/android_device_test", "ecosystem": "custom-rom", "repository_role": "device"},
        {"provider": "gitlab", "full_name": "xiaomi/legacy", "ecosystem": "oem", "repository_role": "device"},
    ]
    result = merge_repository_records(existing, discovered)
    records = {(x["provider"], x["full_name"]): x for x in result}
    assert len(result) == 3
    assert records[("gitlab", "xiaomi/legacy")]["repository_role"] == "device"
    assert records[("gitlab", "xiaomi/preserved")]["repository_role"] == "firmware"
    assert ("github", "LineageOS/android_device_test") in records
    print("HiCo repository index merge test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
