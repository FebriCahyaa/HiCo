#!/usr/bin/env python3
from __future__ import annotations

import json
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from hico_universal import build, validate


def main() -> int:
    with tempfile.TemporaryDirectory(prefix="hico-universal-test-") as td:
        root = Path(td)
        thermal = root / "thermal-data" / "custom-rom" / "xiaomi" / "garnet" / "17" / "vendor" / "smoke"
        raw = thermal / "raw" / "vendor" / "etc"
        raw.mkdir(parents=True)
        (raw / "thermal-engine.conf").write_text(
            "[CPU_MONITOR]\nthresholds 45000 50000\n", encoding="utf-8"
        )
        (thermal / "manifest.json").write_text(json.dumps({
            "schema": "hico.thermal-source.v1",
            "source": {
                "id": "smoke",
                "provider": "github",
                "repository": "Smoke/device_vendor_garnet",
                "branch": "main",
                "commit": "abcdef1234567890",
                "url": "https://github.com/Smoke/device_vendor_garnet",
            },
            "identity": {
                "ecosystem": "custom-rom",
                "vendor": "xiaomi",
                "rom_family": "lineageos",
                "device": "garnet",
                "android": "17",
                "repository_role": "vendor",
                "platform": "sm7435",
            },
            "files": [{
                "tree_path": "vendor/etc/thermal-engine.conf",
                "storage": "raw",
                "format": "thermal-engine",
                "sha256": "a" * 64
            }]
        }, indent=2) + "\n", encoding="utf-8")

        device_prop = root / "devices" / "xiaomi"
        device_prop.mkdir(parents=True)
        (device_prop / "garnet.prop").write_text(
            "codename=garnet\nbrand=Redmi\nmodel=Redmi Note 13 Pro 5G\nplatform=sm7435\n",
            encoding="utf-8",
        )

        data = build(root)
        errors = validate(data)
        assert not errors, errors
        assert "xiaomi/garnet" in {x["id"] for x in data["devices"]}
        assert "lineageos/17" in {x["id"] for x in data["roms"]}
        source = data["thermal_sources"][0]
        assert source["device_id"] == "xiaomi/garnet"
        assert source["rom_id"] == "lineageos/17"
        assert source["source_layer"] == "vendor"

    print("HiCo universal schema test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
