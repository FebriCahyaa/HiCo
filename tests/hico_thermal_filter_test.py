#!/usr/bin/env python3
from __future__ import annotations

import json
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import hico_thermal_filter as hf


def main() -> int:
    device = {
        "provider": "github",
        "full_name": "LineageOS/android_device_xiaomi_garnet",
        "repository_role": "device",
        "vendor": "xiaomi",
        "device": "garnet",
        "android": "15",
        "ecosystem": "custom-rom",
        "rom_family": "lineageos",
    }
    decision = hf.decide(device)
    assert decision.verdict == "candidate"
    assert decision.confidence == "high"
    assert decision.score >= 100

    thermal = dict(device, full_name="org/android_thermal_engine")
    thermal["repository_role"] = "source"
    assert hf.decide(thermal).verdict == "candidate"

    framework = {
        "provider": "github",
        "full_name": "LineageOS/android_frameworks_base",
        "repository_role": "rom",
        "vendor": "",
        "device": "",
        "android": "unknown",
        "ecosystem": "custom-rom",
        "rom_family": "lineageos",
    }
    assert hf.decide(framework).verdict == "reject"

    generic_rom_vendor = {
        "provider": "github",
        "full_name": "LineageOS/android_external_google-fonts_google-sans-flex",
        "repository_role": "rom",
        "vendor": "google",
        "device": "",
        "android": "unknown",
        "ecosystem": "custom-rom",
        "rom_family": "lineageos",
    }
    gated = hf.decide(generic_rom_vendor)
    assert gated.verdict == "reject"
    assert gated.confidence == "low"
    assert "custom-rom-rom-requires-thermal-signal" in gated.reasons

    rom_thermal = dict(generic_rom_vendor, full_name="LineageOS/android_thermal")
    rom_thermal_decision = hf.decide(rom_thermal)
    assert rom_thermal_decision.verdict == "candidate"

    generic = {
        "provider": "github",
        "full_name": "someorg/random-tools",
        "repository_role": "unknown",
        "vendor": "",
        "device": "",
        "android": "unknown",
        "ecosystem": "independent",
        "rom_family": "independent",
    }
    assert hf.decide(generic).verdict == "reject"

    with tempfile.TemporaryDirectory(prefix="hico-filter-test-") as td:
        tmp = Path(td)
        source = tmp / "repositories.json"
        out = tmp / "thermal-candidates.json"
        report = tmp / "thermal-filter.json"
        source.write_text(json.dumps({
            "schema": "hico.repositories.v1",
            "repositories": [device, framework, generic],
        }), encoding="utf-8")
        repos = hf.load_repositories(source)
        candidates, decisions = hf.filter_repositories(repos)
        assert len(candidates) == 1
        assert len(decisions) == 3

    print("HiCo thermal candidate filter test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
