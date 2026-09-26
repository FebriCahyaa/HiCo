#!/usr/bin/env python3
from __future__ import annotations

import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from hico_thermal.topology import analyze_tree


def main() -> int:
    with tempfile.TemporaryDirectory(prefix="hico-topology-test-") as td:
        root = Path(td)
        (root / "vendor/etc/init").mkdir(parents=True)
        (root / "vendor/etc/thermal").mkdir(parents=True)
        (root / "device/dts").mkdir(parents=True)
        (root / "vendor/etc/init/thermal.rc").write_text(
            "service vendor.thermal-engine /vendor/bin/thermal-engine\n"
            "    class main\n"
            "android.hardware.thermal-service\n"
        )
        (root / "vendor/etc/thermal/thermal.conf").write_text("[CPU]\nsensor soc\nthresholds 80000 90000\n")
        (root / "device/dts/thermal.dtsi").write_text(
            "thermal-zones {\n"
            "    soc_thermal { thermal-sensors = <&tsens>; };\n"
            "    cooling-maps { };\n"
            "};\n"
        )
        result = analyze_tree(root)
        assert result["artifact_count"] == 3
        assert "vendor.thermal-engine" in result["services"]
        assert result["thermal_daemons"]
        assert result["thermal_zone_references"]
        assert result["cooling_references"]
    print("HiCo topology test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
