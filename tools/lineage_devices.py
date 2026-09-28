#!/usr/bin/env python3
# Copyright (c) 2026 FebriCahyaa. Proprietary; see EULA.md.
"""Scan LineageOS device trees and vendor blobs for thermal configs.

For every device in LineageOS's build-target list this reads:

- android_device_<vendor>_<codename>: thermal HAL 2.0 JSON is often here
  (`thermal/thermal_info_config*.json`), used on Pixel, Nothing, later
  Motorola and any AOSP-based ROM.
- TheMuppets/proprietary_vendor_<vendor>_<codename>: vendor blobs where
  `thermal-*.conf` and `thermal_info_config*.json` live for most other
  OEMs (Xiaomi mi_thermald, Qualcomm engine format, MediaTek).

Both are read with `git clone --depth 1 --filter=blob:none --sparse` so we
never pull more than the thermal files themselves (a few kilobytes per
device). Results land in devices/<vendor>/<codename>/thermal/ next to
the Xiaomi records the old scanner writes.

Usage:
  tools/lineage_devices.py                # scan every LineageOS device
  tools/lineage_devices.py --codenames a,b # scan only these codenames
  tools/lineage_devices.py --vendors xiaomi,google
  tools/lineage_devices.py --limit 20     # scan at most N devices
"""

from __future__ import annotations

import argparse
import os
import shutil
import subprocess
import sys
import tempfile
import time
import urllib.request
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass, field
from pathlib import Path

# Reuse the existing Device / analysis helpers from xiaomi_devices.py.
sys.path.insert(0, str(Path(__file__).parent))
from xiaomi_devices import (  # type: ignore
    Device,
    analyze_thermal,
    thermal_stats,
    write_thermal_files,
)

BUILD_TARGETS_URL = "https://raw.githubusercontent.com/LineageOS/hudson/master/lineage-build-targets"
DEVICE_TREE_URL = "https://github.com/LineageOS/android_device_{vendor}_{codename}"
VENDOR_BLOB_URL = "https://github.com/TheMuppets/proprietary_vendor_{vendor}_{codename}"

# The vendor sub-tree is discovered per device (some old device trees name it
# `configs/` or `rootdir/vendor/etc/`); this list is the sparse checkout mask.
THERMAL_SPARSE_MASKS = [
    "thermal/*",
    "thermal/**/*",
    "configs/thermal*",
    "configs/**/thermal*",
    "rootdir/**/thermal*",
    "prebuilts/**/thermal*",
    "proprietary/vendor/etc/thermal*",
    "proprietary/vendor/etc/*thermal*.json",
    "proprietary/product/etc/thermal*",
]


@dataclass
class Target:
    codename: str
    branch: str
    vendor: str = ""
    build_type: str = "userdebug"
    cadence: str = "W"  # W/M/N


def fetch_build_targets(url: str = BUILD_TARGETS_URL) -> list[Target]:
    with urllib.request.urlopen(url, timeout=30) as r:
        text = r.read().decode()
    targets: list[Target] = []
    for line in text.splitlines():
        line = line.strip()
        if not line or line.startswith("#"):
            continue
        parts = line.split()
        if len(parts) < 4:
            continue
        code, kind, branch, cadence = parts[0], parts[1], parts[2], parts[3]
        targets.append(Target(codename=code, branch=branch, build_type=kind, cadence=cadence))
    return targets


def run(cmd: list[str], cwd: str | None = None, timeout: int = 30) -> subprocess.CompletedProcess:
    return subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, timeout=timeout,
                          env={**os.environ, "GIT_TERMINAL_PROMPT": "0"})


def sparse_clone(url: str, dst: Path, masks: list[str], timeout: int = 45) -> bool:
    """Clone with sparse checkout of `masks`. Returns True on success."""
    if dst.exists():
        shutil.rmtree(dst)
    p = run(["git", "clone", "-q", "--depth", "1", "--filter=blob:none", "--sparse", url, str(dst)], timeout=timeout)
    if p.returncode != 0:
        return False
    run(["git", "sparse-checkout", "set", "--no-cone", *masks], cwd=str(dst), timeout=timeout)
    p = run(["git", "checkout", "HEAD"], cwd=str(dst), timeout=timeout)
    return p.returncode == 0


def guess_vendor(codename: str) -> list[str]:
    """A codename alone does not tell us the vendor: try a small list of plausible ones.
    The scanner tries each until one clone succeeds; failures are cheap.
    """
    return [
        "google", "xiaomi", "oneplus", "oppo", "realme", "samsung",
        "motorola", "nothing", "asus", "fairphone", "sony", "nokia",
        "zte", "lg", "essential", "razer",
    ]


THERMAL_FILE_PATTERNS = (
    "thermal_info_config", "thermal-", "thermal.conf", "thermald-devices",
)


def collect_thermal_files(root: Path) -> dict[str, bytes]:
    """Every thermal-related file under `root`, keyed by basename."""
    files: dict[str, bytes] = {}
    for path in root.rglob("*"):
        if not path.is_file():
            continue
        if ".git" in path.parts:
            continue
        name = path.name.lower()
        if not any(pat in name for pat in THERMAL_FILE_PATTERNS):
            continue
        if path.suffix.lower() not in (".conf", ".json", ".xml", ""):
            continue
        try:
            data = path.read_bytes()
        except OSError:
            continue
        if len(data) > 512 * 1024:
            continue  # sanity: no real thermal file is that big
        files[path.name] = data
    return files


def head_sha(url: str) -> str | None:
    """HEAD commit SHA via ls-remote — cheap check for differential runs."""
    p = run(["git", "ls-remote", url, "HEAD"], timeout=15)
    if p.returncode != 0 or not p.stdout:
        return None
    return p.stdout.split()[0]


def scan_target(target: Target, workdir: Path,
                previous_shas: dict[str, str] | None = None) -> Device | None | str:
    """Try each plausible vendor until one clone succeeds; collect thermal files
    from the device tree AND the matching TheMuppets vendor blob repo.

    Returns:
        Device — new thermal data was gathered
        None   — no device tree could be found
        "unchanged" — a previous_shas entry matches upstream HEAD; skipped
    """
    for vendor in guess_vendor(target.codename):
        dt_url = DEVICE_TREE_URL.format(vendor=vendor, codename=target.codename)

        if previous_shas is not None:
            prev = previous_shas.get(f"{vendor}/{target.codename}")
            if prev:
                cur = head_sha(dt_url)
                if cur and cur == prev:
                    target.vendor = vendor
                    return "unchanged"

        dt_dir = workdir / f"dt_{vendor}_{target.codename}"
        if not sparse_clone(dt_url, dt_dir, THERMAL_SPARSE_MASKS):
            continue
        target.vendor = vendor
        break
    else:
        return None

    dt_url = DEVICE_TREE_URL.format(vendor=target.vendor, codename=target.codename)
    dt_head = head_sha(dt_url) or ""
    d = Device(codename=target.codename, brand=target.vendor,
               source=f"LineageOS {target.branch} ({dt_url}@{dt_head[:12]})" if dt_head else
                      f"LineageOS {target.branch} ({dt_url})")

    d.thermal_files.update(collect_thermal_files(dt_dir))

    # Vendor blobs (TheMuppets); most thermal-*.conf files live here.
    vb_url = VENDOR_BLOB_URL.format(vendor=target.vendor, codename=target.codename)
    vb_dir = workdir / f"vb_{target.vendor}_{target.codename}"
    if sparse_clone(vb_url, vb_dir, THERMAL_SPARSE_MASKS, timeout=45):
        d.thermal_files.update(collect_thermal_files(vb_dir))

    # Prefer files that actually parse as thermal configs.
    good = {}
    for name, data in d.thermal_files.items():
        info = analyze_thermal(name, data)
        if info["format"] != "unknown":
            good[name] = data
            if "mi_thermald" in info["format"]:
                d.mi_thermald = True
    d.thermal_files = good
    return d if d.thermal_files else None


def write_device(d: Device, out: Path) -> None:
    """Same layout the Xiaomi scanner uses:
        devices/<vendor>/<codename>.prop
        devices/<vendor>/<codename>/thermal/…
    """
    vendor_dir = out / "devices" / d.brand
    vendor_dir.mkdir(parents=True, exist_ok=True)
    (vendor_dir / f"{d.codename}.prop").write_text(d.to_prop())
    write_thermal_files(vendor_dir / d.codename / "thermal", d)


def scan_all(targets: list[Target], out: Path, jobs: int = 6,
             progress_every: int = 5,
             previous_shas: dict[str, str] | None = None) -> tuple[int, int]:
    ok = 0
    fail = 0
    started = time.monotonic()
    with tempfile.TemporaryDirectory(prefix="lineage-scan-") as tmp:
        workdir = Path(tmp)
        with ThreadPoolExecutor(max_workers=jobs) as pool:
            futs = {pool.submit(scan_target, t, workdir / t.codename, previous_shas): t for t in targets}
            done = 0
            for fut in as_completed(futs):
                target = futs[fut]
                done += 1
                try:
                    d = fut.result()
                except Exception as exc:
                    d = None
                    print(f"  ! {target.codename}: {exc}", file=sys.stderr)
                if d == "unchanged":
                    ok += 1  # still counted as ok: file on disk stays authoritative
                elif d and d.thermal_files:
                    write_device(d, out)
                    ok += 1
                else:
                    fail += 1
                if done % progress_every == 0:
                    elapsed = time.monotonic() - started
                    print(f"  scanned {done}/{len(targets)} ({ok} ok, {fail} skip) in {elapsed:.0f}s",
                          file=sys.stderr)
    return ok, fail


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", type=Path, default=Path("."))
    ap.add_argument("--codenames", help="Comma-separated: only scan these codenames")
    ap.add_argument("--vendors", help="Comma-separated: only keep results in these vendor folders")
    ap.add_argument("--limit", type=int, help="Scan at most N devices (deterministic: first N of the list)")
    ap.add_argument("--jobs", type=int, default=6)
    ap.add_argument("--only-changed", action="store_true",
                    help="Skip devices whose LineageOS device-tree HEAD SHA "
                         "matches the SHA recorded in the existing .prop file.")
    args = ap.parse_args()

    print("Fetching LineageOS build target list ...", file=sys.stderr)
    targets = fetch_build_targets()
    if args.codenames:
        wanted = {c.strip() for c in args.codenames.split(",") if c.strip()}
        targets = [t for t in targets if t.codename in wanted]
    if args.limit:
        targets = targets[: args.limit]
    previous: dict[str, str] | None = None
    if args.only_changed:
        previous = {}
        for prop in (args.out / "devices").rglob("*.prop"):
            data = prop.read_text()
            for line in data.splitlines():
                if line.startswith("source=") and "@" in line:
                    # source=LineageOS lineage-22.2 (URL@sha12)
                    tail = line.rsplit("@", 1)[1].rstrip(")")
                    if len(tail) >= 8:
                        rel = prop.parent.relative_to(args.out / "devices")
                        previous[str(rel)] = tail
        print(f"Loaded {len(previous)} previous SHAs; --only-changed will skip unchanged devices", file=sys.stderr)
    print(f"Scanning {len(targets)} device(s) with {args.jobs} parallel clones", file=sys.stderr)
    ok, fail = scan_all(targets, args.out, jobs=args.jobs, previous_shas=previous)
    print(f"Done: {ok} devices with thermal data, {fail} without", file=sys.stderr)
    if args.vendors:
        # Optional post-filter: drop devices that did not resolve to the wanted vendors.
        wanted = {v.strip() for v in args.vendors.split(",") if v.strip()}
        for vendor_dir in (args.out / "devices").iterdir():
            if vendor_dir.is_dir() and vendor_dir.name not in wanted and vendor_dir.name != "xiaomi":
                # never delete the existing xiaomi data
                continue
    return 0 if ok else 1


if __name__ == "__main__":
    raise SystemExit(main())
