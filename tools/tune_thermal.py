#!/usr/bin/env python3
#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
#
"""Tune every collected Xiaomi thermal config for its chipset, and verify it.

Reads   devices/xiaomi/<codename>.prop              (platform -> chipset policy)
        devices/xiaomi/<codename>/thermal/*.conf    (stock vendor configs, thermal-engine syntax)
        devices/xiaomi/<codename>/thermal/thermal_info_config*.json (thermal HAL)
Writes  devices/xiaomi/<codename>/tuned/*.conf      (relaxed configs as plain text, for review;
                                                     encrypted mi_thermald files are decrypted)
        devices/xiaomi/<codename>/tuned/TEMPLATE.md (the device's template: stock -> tuned trips)
        docs/THERMAL_TUNING.md                      (per-device report)

Encrypted mi_thermald configs (recent Xiaomi firmware) are decrypted, tuned and
re-encrypted by hicod itself; each device is bounded by its own highest trips
(`--ceilings`: nolimits / game scenes), so templates follow Xiaomi's data.

The tuning is done by the host build of hicod (`hicod thermal tune` /
`hicod thermal check`), i.e. the exact code the device runs at the relaxed
level, so what is reviewed here is what users get. Every tuned file is
checked by the independent verifier; any violation fails the run.

    python3 tools/tune_thermal.py --hicod build/hicod
"""

from __future__ import annotations

import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
REPORT_RE = re.compile(r"(\w+)=(\S+)")


def read_prop(path: Path) -> dict[str, str]:
    out = {}
    for line in path.read_text(errors="replace").splitlines():
        if line and not line.startswith("#") and "=" in line:
            k, v = line.split("=", 1)
            out[k.strip()] = v.strip()
    return out


def run(hicod: str, *args: str) -> subprocess.CompletedProcess:
    return subprocess.run([hicod, *args], capture_output=True, timeout=60)


def tune_device(hicod: str, prop: Path, margin: int) -> dict:
    info = read_prop(prop)
    codename = prop.stem
    thermal_dir = prop.parent / codename / "thermal"
    tuned_dir = prop.parent / codename / "tuned"
    if tuned_dir.exists():
        shutil.rmtree(tuned_dir)

    platform = info.get("platform", "")
    result = {"codename": codename, "name": f"{info.get('brand', '')} {info.get('model', '')}".strip(),
              "platform": platform, "policy": "", "margin": "", "files": 0, "tunable": 0, "tuned": 0,
              "sections": 0, "tuned_sections": 0, "encrypted": 0, "violations": [], "changes": []}
    if not thermal_dir.is_dir():
        return result

    extra = ["--platform", platform or "unknown", "--ceilings", str(thermal_dir)] + (
        ["--margin", str(margin)] if margin else [])
    # thermal-engine / mi_thermald configs and thermal HAL JSON (AOSP-based ROMs, newer vendors).
    configs = sorted([*thermal_dir.glob("*.conf"), *thermal_dir.glob("thermal_info_config*.json")])
    for conf in configs:
        result["files"] += 1
        r = run(hicod, "thermal", "tune", str(conf), *extra)
        report = dict(REPORT_RE.findall(r.stderr.decode(errors="replace").splitlines()[0] if r.stderr else ""))
        result["policy"] = report.get("policy", result["policy"])
        result["margin"] = report.get("margin", result["margin"])
        if r.returncode == 2:
            continue  # encrypted or not thermal-engine syntax
        if r.returncode != 0:
            result["violations"].append(f"{conf.name}: hicod thermal tune failed ({r.returncode})")
            continue
        result["tunable"] += 1
        result["sections"] += int(report.get("sections", 0))
        tuned_sections = int(report.get("tuned", 0))
        if tuned_sections == 0:
            continue

        tuned_dir.mkdir(parents=True, exist_ok=True)
        out = tuned_dir / conf.name
        out.write_bytes(r.stdout)
        check = run(hicod, "thermal", "check", str(conf), str(out), *extra)
        if check.returncode != 0:
            result["violations"].append(f"{conf.name}: {check.stderr.decode(errors='replace').strip()}")
            out.unlink()
            continue
        # Review copies are text: decrypt what hicod re-encrypted (the device keeps it encrypted).
        stock_text = conf.read_bytes()
        dec = run(hicod, "thermal", "decrypt", str(out))
        if dec.returncode == 0:
            result["encrypted"] += 1
            out.write_bytes(dec.stdout)
            stock_text = run(hicod, "thermal", "decrypt", str(conf)).stdout
        result["changes"] += diff_trips(conf.name, stock_text.decode(errors="replace"), out.read_text(errors="replace"))
        result["tuned"] += 1
        result["tuned_sections"] += tuned_sections
    if result["changes"]:
        write_template(result, tuned_dir / "TEMPLATE.md")
    return result


def sections_of(text: str) -> dict[str, dict[str, str]]:
    out: dict[str, dict[str, str]] = {}
    cur = None
    for line in text.splitlines():
        t = line.strip()
        if t.startswith("[") and t.endswith("]"):
            cur = out.setdefault(t[1:-1], {})
        elif cur is not None and t and not t.startswith("#"):
            key, _, val = t.partition("\t") if "\t" in t else t.partition(" ")
            cur.setdefault(key, " ".join(val.split()))
    return out


def diff_trips(name: str, stock: str, tuned: str) -> list[dict]:
    """Sections whose trip points changed, with the device / sensor they act on."""
    a, b = sections_of(stock), sections_of(tuned)
    rows = []
    for sec, keys in a.items():
        new = b.get(sec, {})
        for key in ("trig", "thresholds"):
            if key in keys and keys[key] != new.get(key):
                rows.append({"file": name, "section": sec, "device": keys.get("device", keys.get("sensor", "")),
                             "sensor": keys.get("sensor", ""), "stock": keys[key], "tuned": new.get(key, "")})
    return rows


def c(v: str) -> str:
    """Trip list in °C for reading (millidegrees in the files)."""
    vals = [int(x) for x in v.split() if x.lstrip("-").isdigit()]
    return " ".join(f"{x / 1000:g}" if abs(x) >= 1000 else str(x) for x in vals)


def write_template(r: dict, out: Path) -> None:
    lines = [
        f"# Thermal template: {r['name']} (`{r['codename']}`)",
        "",
        f"Platform `{r['platform'] or '–'}`, policy **{r['policy']}**, margin {r['margin']} °C. Generated by",
        "`tools/tune_thermal.py`; the device builds the same template at runtime from its own files.",
        "",
        "Trips in °C. mi_thermald sections are bounded by the highest trip this device's own configs use",
        "for the same device and sensor (its nolimits / game scenes), so nothing goes beyond what Xiaomi",
        "allows on this phone. Targets (frequencies, levels) are never changed.",
        "",
        "| File | Section | Limits | Sensor | Stock trips | Tuned trips |",
        "|---|---|---|---|---|---|",
    ]
    for ch in r["changes"]:
        lines.append(f"| {ch['file']} | {ch['section']} | `{ch['device']}` | `{ch['sensor']}` | "
                     f"{c(ch['stock'])} | {c(ch['tuned'])} |")
    out.write_text("\n".join(lines) + "\n")


def write_report(results: list[dict], out: Path) -> None:
    lines = [
        "# Thermal tuning per device",
        "",
        "Generated by [`tools/tune_thermal.py`](../tools/tune_thermal.py) with the host build of `hicod`",
        "(`hicod thermal tune` / `check`), the same code the relaxed level runs on the device.",
        "",
        "Encrypted mi_thermald configs (recent Xiaomi firmware) are decrypted, tuned and encrypted again",
        "by hicod. Their performance sections (cpu, gpu, hotplug, boost_limit) move trig and clr up by the",
        "chipset margin, never above the highest trip the same device's own configs use for that limit",
        "(its nolimits / game scenes); battery, charging, brightness, modem, wifi and temp_state sections",
        "are never changed. Each device's template is in `devices/xiaomi/<codename>/tuned/TEMPLATE.md`.",
        "",
        "Rules: eligible trips (monitor / ss / pid sections) are raised by the chipset margin; shutdown",
        "sections, battery / charger / PMIC sensors, descending monitors and virtual sensors are never",
        "changed; no trip is lowered; skin and board sensors stop at 55 °C, CPU/GPU sensors at 105 °C and",
        "10 °C below their own shutdown threshold; hysteresis and trip order are kept. Every tuned file",
        "passed the independent verifier. Tuned copies are in `devices/xiaomi/<codename>/tuned/`.",
        "",
        "Margins are HiCo's conservative defaults per chipset class (not vendor data) and can be changed",
        "on the device with `relax_margin`.",
        "",
        f"**{sum(1 for r in results if r['tuned'])} devices with tuned configs**, "
        f"{sum(r['tuned'] for r in results)} files, {sum(r['tuned_sections'] for r in results)} sections",
        "",
        "| Device | Codename | Platform | Policy | Margin | Configs | Tunable | Encrypted tuned | Tuned files | Tuned sections |",
        "|---|---|---|---|---|---|---|---|---|---|",
    ]
    for r in sorted(results, key=lambda r: r["codename"]):
        if not r["files"]:
            continue
        lines.append(f"| {r['name']} | `{r['codename']}` | {r['platform'] or '–'} | {r['policy'] or '–'} | "
                     f"{r['margin'] + ' °C' if r['margin'] else '–'} | {r['files']} | {r['tunable']} | "
                     f"{r['encrypted']} | {r['tuned']} | {r['tuned_sections']} of {r['sections']} |")
    no_files = sorted(r["codename"] for r in results if not r["files"])
    if no_files:
        lines += ["", f"No thermal configs collected ({len(no_files)}): " + ", ".join(f"`{c}`" for c in no_files)]
    out.parent.mkdir(exist_ok=True)
    out.write_text("\n".join(lines) + "\n")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--hicod", required=True, help="host build of hicod (cmake --build build)")
    ap.add_argument("--data", default=str(ROOT / "devices" / "xiaomi"))
    ap.add_argument("--report", default=str(ROOT / "docs" / "THERMAL_TUNING.md"))
    ap.add_argument("--margin", type=int, default=0, help="override every chipset margin (1-10)")
    args = ap.parse_args()

    props = sorted(Path(args.data).glob("*.prop"))
    # Devices are independent and the work is hicod processes: run them side by side.
    with ThreadPoolExecutor(max_workers=os.cpu_count() or 4) as pool:
        results = list(pool.map(lambda p: tune_device(args.hicod, p, args.margin), props))
    write_report(results, Path(args.report))

    violations = [v for r in results for v in r["violations"]]
    for v in violations:
        print(f"violation: {v}", file=sys.stderr)
    print(f"{len(props)} devices, {sum(r['tuned'] for r in results)} tuned files, "
          f"{len(violations)} violations", file=sys.stderr)
    return 1 if violations else 0


if __name__ == "__main__":
    sys.exit(main())
