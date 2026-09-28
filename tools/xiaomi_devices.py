#!/usr/bin/env python3
#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
#
"""Generate HiCo's Xiaomi device profiles from public firmware dumps.

Every profile is derived from the stock vendor partition of a real firmware
dump; nothing is typed in by hand. For each device it records:

  - identity: codename, brand, model / market name, SoC platform, Android release
  - thermal services declared in the vendor's thermal init scripts (exact names)
  - thermal configuration files shipped in vendor/etc (mi_thermald scenes, ...)
  - where it came from (dump URL and branch), so every line can be checked

Sources:
  --gitlab URL --group dumps/xiaomi   GitLab instance (default: dumps.tadiphone.dev);
                                      files are read one by one through the API
  --gitlab URL --sparse               list the dumps through the API (names only), then
                                      partial-clone each dump checking out only the paths
                                      in SPARSE_PATHS (build.prop + vendor thermal files)
  --local DIR                         directory of dump checkouts, one per device

Every dump name ends up in docs/DEVICES.md, including dumps without usable
vendor data; only the files needed per device are ever downloaded.

Output (--out, default: repository root):
  devices/xiaomi/<codename>.prop      read by hicod (DeviceProfile)
  docs/DEVICES.md                     supported device list
"""

from __future__ import annotations

import argparse
import hashlib
import concurrent.futures
import json
import os
import re
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
from dataclasses import dataclass, field
from pathlib import Path
import shutil
import signal
import subprocess
import tempfile
import threading

DEFAULT_GITLAB = "https://dumps.tadiphone.dev"
# Xiaomi, Redmi and POCO firmware; groups that do not exist on the instance are skipped.
DEFAULT_GROUP = "dumps/xiaomi,dumps/redmi,dumps/poco"

CODENAME_RE = re.compile(r"^[a-z0-9_]{1,64}$")
SERVICE_RE = re.compile(r"^[A-Za-z0-9_.@-]{1,96}$")
SERVICE_LINE_RE = re.compile(r"^\s*service\s+(\S+)\s+(\S+)")
THERMAL_CONFIG_RE = re.compile(r"^(thermal[\w.-]*\.(conf|xml|json)|thermal_info_config[\w.-]*\.json)$", re.I)
THERMAL_RC_RE = re.compile(r"thermal", re.I)
PRINTABLE_RE = re.compile(r"[^\x20-\x7e]")

# build.prop files, most specific first; the first file that defines a key wins.
# system/build.prop is where pre-Treble dumps (no vendor partition) keep everything.
BUILD_PROPS = [
    "vendor/build.prop",
    "odm/etc/build.prop",
    "product/etc/build.prop",
    "product/build.prop",
    "system_ext/etc/build.prop",
    "system/system/build.prop",
    "system/build.prop",
]
PROP_KEYS = {
    "codename": ["ro.product.vendor.device", "ro.product.device", "ro.product.product.device"],
    "brand": ["ro.product.vendor.brand", "ro.product.brand", "ro.product.product.brand"],
    "market": ["ro.product.marketname", "ro.product.product.marketname", "ro.product.odm.marketname",
               "ro.product.vendor.marketname", "ro.product.system.marketname", "ro.product.system_ext.marketname"],
    "model": ["ro.product.vendor.model", "ro.product.model", "ro.product.product.model"],
    "platform": ["ro.board.platform", "ro.vendor.qti.soc_name", "ro.hardware"],
    # The system release is what the user runs; with GRF the vendor partition keeps its launch release.
    "android": ["ro.system.build.version.release", "ro.build.version.release", "ro.vendor.build.version.release"],
}


# Everything the scanner reads from a dump. --sparse checks out exactly these
# (gitignore-style patterns for `git sparse-checkout --no-cone`); keep them in
# sync with BUILD_PROPS and the vendor/etc lookups in scan().
# Where thermal configuration files live: the vendor partition on Treble
# devices, system/vendor or system/etc on older (pre-Treble) firmware.
CONFIG_DIRS = ["vendor/etc", "odm/etc", "system/vendor/etc", "system/etc", "system/system/etc"]
# Init scripts: files named *thermal* are read whole; general scripts (init.qcom.rc, ...)
# in the hw directories contribute only their thermal services.
RC_DIRS = ["vendor/etc/init", "system/vendor/etc/init", "system/etc/init"]
RC_HW_DIRS = ["vendor/etc/init/hw", "system/vendor/etc/init/hw", "system/etc/init/hw"]

SPARSE_PATHS = [
    *[f"/{p}" for p in BUILD_PROPS],
    *[f"/{d}/{pat}" for d in CONFIG_DIRS for pat in ("thermal*", "Thermal*")],
    *[f"/{d}/{pat}" for d in RC_DIRS for pat in ("*thermal*", "*Thermal*")],
    *[f"/{d}/*.rc" for d in RC_HW_DIRS],
]

# Thermal files kept in the repository: bounded, so one odd dump cannot bloat it.
MAX_THERMAL_FILE = 512 * 1024


@dataclass
class Device:
    codename: str
    brand: str = ""
    model: str = ""
    platform: str = ""
    android: str = ""
    source: str = ""
    services: list[str] = field(default_factory=list)
    configs: list[str] = field(default_factory=list)
    mi_thermald: bool = False
    thermal_files: dict[str, bytes] = field(default_factory=dict)  # config name -> content
    variants: list[str] = field(default_factory=list)               # other dumps of this codename
    dump: str = ""                                                   # markdown link to this dump

    def to_prop(self) -> str:
        lines = [
            "# Generated by tools/xiaomi_devices.py from the stock firmware dump below.",
            "# Do not edit by hand: re-run the generator instead.",
            f"codename={self.codename}",
            f"brand={clean(self.brand)}",
            f"model={clean(self.model)}",
            f"platform={clean(self.platform)}",
            f"android={clean(self.android)}",
            f"source={clean(self.source, 512)}",  # dump URLs embed the full firmware branch name
            f"mi_thermald={1 if self.mi_thermald else 0}",
            f"thermal_services={','.join(self.services)}",
            f"thermal_configs={','.join(self.configs)}",
        ]
        stats = thermal_stats(self.thermal_files)
        lines += [f"{k}={v}" for k, v in stats.items()]
        return "\n".join(lines) + "\n"


def clean(value: str, limit: int = 128) -> str:
    return PRINTABLE_RE.sub("", value).replace("=", " ").strip()[:limit]


def parse_props(text: str) -> dict[str, str]:
    props: dict[str, str] = {}
    for line in text.splitlines():
        line = line.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, value = line.split("=", 1)
        props.setdefault(key.strip(), value.strip())
    return props


def parse_rc_services(text: str, thermal_only: bool = False) -> list[str]:
    """Service names declared in an init script.

    thermal_only: keep only services whose name or executable mentions thermal
    (for general scripts such as init.qcom.rc that declare many services).
    """
    names = []
    for line in text.splitlines():
        m = SERVICE_LINE_RE.match(line)
        if not m or not SERVICE_RE.match(m.group(1)):
            continue
        if thermal_only and not (THERMAL_RC_RE.search(m.group(1)) or THERMAL_RC_RE.search(m.group(2))):
            continue
        names.append(m.group(1))
    return names


# ── Thermal file analysis ─────────────────────────────────────────────────────

SECTION_RE = re.compile(r"^\s*\[([^\]]+)\]\s*$")


def to_celsius(raw: str) -> float | None:
    try:
        v = float(raw)
    except ValueError:
        return None
    c = v / 1000 if abs(v) >= 1000 else v  # thermal-engine uses millidegrees; old configs use degrees
    return c if -40 <= c <= 200 else None


def analyze_thermal(name: str, data: bytes) -> dict:
    """Format and trip points of one thermal configuration file.

    Many recent Xiaomi thermal configs are encrypted blobs; only plain-text
    thermal-engine style files ([SECTION] / algo_type / sensor / thresholds /
    actions) are parsed. Nothing is guessed for other formats.
    """
    info = {"name": name, "size": len(data), "format": "empty" if not data else "text",
            "sections": 0, "max_trip_c": None, "shutdown_c": None}
    if not data:
        return info
    sample = data[:4096]
    binary = sum(1 for b in sample if b < 9 or 13 < b < 32 or b == 127)
    if b"\0" in sample or binary > len(sample) // 20:
        info["format"] = "encrypted"
        return info
    text = data.decode("utf-8", errors="replace")
    if name.endswith(".xml") or text.lstrip().startswith("<"):
        info["format"] = "xml"
        return info
    if name.endswith(".json") or text.lstrip().startswith("{"):
        info["format"] = "json"
        return info

    section: dict | None = None
    sections: list[dict] = []
    for line in text.splitlines():
        line = line.split("#", 1)[0].strip()
        if not line:
            continue
        m = SECTION_RE.match(line)
        if m:
            section = {"name": m.group(1), "thresholds": [], "actions": ""}
            sections.append(section)
            continue
        key, _, value = line.partition(" ")
        if key in ("thresholds", "set_point") and section is not None:
            section["thresholds"] += [c for c in (to_celsius(v) for v in value.split()) if c is not None]
        elif key == "actions" and section is not None:
            section["actions"] = value
    info["sections"] = len(sections)
    if not sections:
        info["format"] = "text-unknown"
        return info
    trips = [t for s in sections if "shutdown" not in s["actions"] for t in s["thresholds"]]
    shutdowns = [t for s in sections if "shutdown" in s["actions"] for t in s["thresholds"]]
    info["max_trip_c"] = max(trips) if trips else None
    info["shutdown_c"] = min(shutdowns) if shutdowns else None
    return info


def thermal_stats(files: dict[str, bytes]) -> dict[str, str]:
    infos = [analyze_thermal(n, d) for n, d in sorted(files.items())]
    count = lambda fmt: sum(1 for i in infos if i["format"] == fmt)
    trips = [i["max_trip_c"] for i in infos if i["max_trip_c"] is not None]
    shutdowns = [i["shutdown_c"] for i in infos if i["shutdown_c"] is not None]
    fmt = lambda v: f"{v:g}" if v is not None else ""
    return {
        "thermal_files": str(len(infos)),
        "thermal_encrypted": str(count("encrypted")),
        "thermal_parsed": str(count("text")),
        "vendor_max_trip_c": fmt(max(trips) if trips else None),
        "vendor_shutdown_c": fmt(min(shutdowns) if shutdowns else None),
    }


# ── Sources ───────────────────────────────────────────────────────────────────


class LocalSource:
    """A directory holding one checked-out dump per device."""

    def __init__(self, root: str):
        self.root = Path(root)

    def projects(self) -> list[dict]:
        return [
            {"id": p.name, "path": p.name, "branch": "local", "url": str(p)}
            for p in sorted(self.root.iterdir())
            if p.is_dir() and not p.name.startswith(".")
        ]

    def read(self, project: dict, path: str) -> str | None:
        f = self.root / project["path"] / path
        try:
            return f.read_text(errors="replace") if f.is_file() else None
        except OSError:
            return None

    def listdir(self, project: dict, path: str) -> list[str]:
        d = self.root / project["path"] / path
        return sorted(p.name for p in d.iterdir() if p.is_file()) if d.is_dir() else []

    def read_bytes(self, project: dict, path: str, limit: int) -> bytes | None:
        f = self.root / project["path"] / path
        try:
            return f.read_bytes()[:limit] if f.is_file() and f.stat().st_size <= limit else None
        except OSError:
            return None


class GitLabSource:
    """GitLab API (v4) of a firmware dump instance."""

    def __init__(self, base: str, group: str, limit: int | None):
        self.base = base.rstrip("/")
        self.group = group
        self.limit = limit

    def _get(self, url: str) -> tuple[bytes, dict] | None:
        for attempt in range(4):
            try:
                req = urllib.request.Request(url, headers={"User-Agent": "HiCo-Thermal-device-scanner"})
                with urllib.request.urlopen(req, timeout=30) as resp:
                    return resp.read(), dict(resp.headers)
            except urllib.error.HTTPError as e:
                if e.code == 404:
                    return None
                if e.code in (429, 500, 502, 503, 504):
                    time.sleep(2 ** attempt * 2)
                    continue
                raise
            except (urllib.error.URLError, TimeoutError):
                time.sleep(2 ** attempt * 2)
        raise RuntimeError(f"giving up on {url}")

    def _api(self, endpoint: str, **params) -> str:
        query = urllib.parse.urlencode(params)
        return f"{self.base}/api/v4/{endpoint}{'?' + query if query else ''}"

    def projects(self) -> list[dict]:
        out: list[dict] = []
        found = 0
        for group_name in [g.strip() for g in self.group.split(",") if g.strip()]:
            group = urllib.parse.quote(group_name, safe="")
            page = 1
            listed = 0
            exists = False
            # --limit applies per group, so a short test run still covers Xiaomi, Redmi and POCO.
            while page and not (self.limit and listed >= self.limit):
                got = self._get(self._api(f"groups/{group}/projects", per_page=100, page=page,
                                          include_subgroups="true", archived="false", order_by="path", sort="asc"))
                if got is None:
                    print(f"  ? group {group_name} not found on {self.base}, skipped", file=sys.stderr)
                    if os.environ.get("GITHUB_ACTIONS"):
                        print(f"::warning::GitLab group {group_name} not found on {self.base}, skipped")
                    break
                if page == 1:
                    found += 1
                    exists = True
                body, headers = got
                for p in json.loads(body):
                    if p.get("empty_repo") or not p.get("default_branch"):
                        continue
                    out.append({
                        "id": p["id"],
                        "path": p["path"],
                        "name": f"{group_name.rsplit('/', 1)[-1]}/{p['path']}",
                        "branch": p["default_branch"],
                        "url": f"{p['web_url']}/-/tree/{p['default_branch']}",
                        "git_url": p.get("http_url_to_repo") or f"{p['web_url']}.git",
                    })
                    listed += 1
                    if self.limit and listed >= self.limit:
                        break
                page = int(headers.get("X-Next-Page") or headers.get("x-next-page") or 0)
            if exists:
                print(f"  {group_name}: {listed} dumps", file=sys.stderr)
        if not found:
            raise RuntimeError(f"none of the groups {self.group} exist on {self.base}")
        return out

    def read(self, project: dict, path: str) -> str | None:
        file = urllib.parse.quote(path, safe="")
        got = self._get(self._api(f"projects/{project['id']}/repository/files/{file}/raw", ref=project["branch"]))
        return got[0].decode(errors="replace") if got else None

    def read_bytes(self, project: dict, path: str, limit: int) -> bytes | None:
        file = urllib.parse.quote(path, safe="")
        got = self._get(self._api(f"projects/{project['id']}/repository/files/{file}/raw", ref=project["branch"]))
        return got[0] if got and len(got[0]) <= limit else None

    def listdir(self, project: dict, path: str) -> list[str]:
        names, page = [], 1
        while page:
            got = self._get(self._api(f"projects/{project['id']}/repository/tree", path=path,
                                      ref=project["branch"], per_page=100, page=page))
            if got is None:
                return names
            body, headers = got
            names += [e["name"] for e in json.loads(body) if e.get("type") == "blob"]
            page = int(headers.get("X-Next-Page") or headers.get("x-next-page") or 0)
        return sorted(names)


class SparseGitSource(GitLabSource):
    """Lists dumps through the API, then reads each one from a sparse partial clone.

    `git clone --filter=blob:none --depth 1 --no-checkout` downloads only the
    latest commit's trees (file names), no file contents; `sparse-checkout`
    then fetches the blobs of SPARSE_PATHS alone. A dump of tens of GB costs a
    few MB. If the server ignores the filter, the clone is aborted instead of
    downloading the whole firmware.
    """

    FILTER_IGNORED = "filtering not recognized by server"

    def __init__(self, base: str, group: str, limit: int | None, workdir: str | None = None, timeout: int = 600):
        super().__init__(base, group, limit)
        self.workdir = workdir
        self.timeout = timeout

    def _git(self, *args: str, cwd: str | None = None) -> None:
        env = {**os.environ, "GIT_TERMINAL_PROMPT": "0", "GIT_LFS_SKIP_SMUDGE": "1"}
        err: list[str] = []
        # Own process group: git's helpers (git-remote-https, ...) are killed with it.
        with subprocess.Popen(["git", *args], cwd=cwd, env=env, stdout=subprocess.DEVNULL,
                              stderr=subprocess.PIPE, text=True, start_new_session=True) as proc:

            def kill() -> None:
                try:
                    os.killpg(proc.pid, signal.SIGKILL)
                except ProcessLookupError:
                    pass

            # The watchdog also fires when git hangs without printing anything.
            watchdog = threading.Timer(self.timeout, kill)
            watchdog.start()
            try:
                assert proc.stderr is not None
                for line in proc.stderr:
                    err.append(line)
                    if self.FILTER_IGNORED in line:
                        kill()
                        raise RuntimeError("server ignores --filter=blob:none, refusing a full firmware download")
                code = proc.wait()
            finally:
                watchdog.cancel()
        if code != 0:
            reason = "timed out" if code < 0 else f"failed: {''.join(err[-3:]).strip()}"
            raise RuntimeError(f"git {args[0]} {reason}")

    def scan_project(self, project: dict) -> Device | None:
        tmp = tempfile.mkdtemp(prefix="hico-dump-", dir=self.workdir)
        try:
            repo = os.path.join(tmp, "repo")
            self._git("clone", "--quiet", "--filter=blob:none", "--depth", "1", "--no-checkout",
                      "--single-branch", "--branch", project["branch"], project["git_url"], repo)
            self._git("sparse-checkout", "set", "--no-cone", *SPARSE_PATHS, cwd=repo)
            self._git("checkout", "--quiet", project["branch"], cwd=repo)
            local = LocalSource(tmp)
            return scan(local, {**project, "path": "repo"})
        finally:
            shutil.rmtree(tmp, ignore_errors=True)


# ── Scan ─────────────────────────────────────────────────────────────────────


def scan(source, project: dict) -> Device | None:
    props: dict[str, str] = {}
    for path in BUILD_PROPS:
        text = source.read(project, path)
        if text:
            for k, v in parse_props(text).items():
                props.setdefault(k, v)
    if not props:
        return None

    def pick(name: str) -> str:
        return next((props[k] for k in PROP_KEYS[name] if props.get(k)), "")

    codename = pick("codename").lower()
    if not CODENAME_RE.match(codename):
        return None

    brand = pick("brand")
    dev = Device(
        codename=codename,
        brand=brand[:1].upper() + brand[1:] if brand else "Xiaomi",
        model=pick("market") or pick("model"),
        platform=pick("platform"),
        android=pick("android"),
        source=project["url"],
    )

    # Thermal configs: first directory that has a given file name wins (vendor before system).
    for d in CONFIG_DIRS:
        for name in source.listdir(project, d):
            if not THERMAL_CONFIG_RE.match(name) or name in dev.thermal_files:
                continue
            data = source.read_bytes(project, f"{d}/{name}", MAX_THERMAL_FILE)
            if data is not None:
                dev.thermal_files[name] = data
    dev.configs = sorted(dev.thermal_files)

    services: set[str] = set()
    for d in RC_DIRS:
        for rc in source.listdir(project, d):
            if rc.endswith(".rc") and THERMAL_RC_RE.search(rc):
                services.update(parse_rc_services(source.read(project, f"{d}/{rc}") or ""))
    for d in RC_HW_DIRS:
        for rc in source.listdir(project, d):
            if rc.endswith(".rc"):
                services.update(parse_rc_services(source.read(project, f"{d}/{rc}") or "", thermal_only=True))
    dev.services = sorted(services)
    dev.mi_thermald = any("mi_thermald" in s for s in dev.services)
    return dev


def write_thermal_files(tdir: Path, d: Device) -> None:
    """Raw vendor thermal files plus an index (sha256, size, format, trips) for review."""
    if not d.thermal_files:
        return
    tdir.mkdir(parents=True, exist_ok=True)
    index = ["# name\tsha256\tsize\tformat\tsections\tmax_trip_c\tshutdown_c"]
    for name, data in sorted(d.thermal_files.items()):
        (tdir / name).write_bytes(data)
        i = analyze_thermal(name, data)
        index.append("\t".join([name, hashlib.sha256(data).hexdigest(), str(i["size"]), i["format"],
                                str(i["sections"]), f"{i['max_trip_c']:g}" if i["max_trip_c"] is not None else "",
                                f"{i['shutdown_c']:g}" if i["shutdown_c"] is not None else ""]))
    (tdir / "index.tsv").write_text("\n".join(index) + "\n")


def write_outputs(devices: list[Device], out: Path, source_desc: str,
                  unusable: list[dict] | None = None) -> None:
    ddir = out / "devices" / "xiaomi"
    ddir.mkdir(parents=True, exist_ok=True)
    for old in ddir.glob("*.prop"):
        old.unlink()
    for old in ddir.iterdir():
        if old.is_dir():
            shutil.rmtree(old)
    for d in devices:
        (ddir / f"{d.codename}.prop").write_text(d.to_prop())
        write_thermal_files(ddir / d.codename / "thermal", d)

    rows = sorted(devices, key=lambda d: (d.brand.lower(), d.model.lower(), d.codename))
    lines = [
        "# Supported Xiaomi devices",
        "",
        "Generated by [`tools/xiaomi_devices.py`](../tools/xiaomi_devices.py) from the stock vendor",
        f"partitions in {source_desc}. Every row links to the dump it was read from.",
        "",
        "These records are compiled into hicod (`tools/gen_device_db.py` → `jni/src/DeviceDatabase.gen.cpp`);",
        "they are never shipped as files. A record adds the exact thermal service names the vendor declares",
        "and selects the thermal backends for the device's SoC. Devices that are not listed use runtime",
        "detection only (thermal services from `init.svc.*`, zones and cooling devices from `/sys/class/thermal`).",
        "",
        f"**{len(rows)} devices with a profile**"
        + (f", {len(unusable)} more dumps listed below without one" if unusable else "")
        + (f", {sum(len(d.variants) for d in devices)} more dumps of listed devices" if any(d.variants for d in devices) else ""),
        "",
        "Thermal configs: files kept in `devices/xiaomi/<codename>/thermal/` (plain text / encrypted);",
        "trips are the highest non-shutdown and the lowest shutdown threshold found in the plain-text files.",
        "",
        "| Device | Codename | Platform | Android | mi_thermald | Thermal services | Thermal configs | Trips (max / shutdown) | Source |",
        "|---|---|---|---|---|---|---|---|---|",
    ]
    for d in rows:
        services = ", ".join(f"`{s}`" for s in d.services) or "–"
        st = thermal_stats(d.thermal_files)
        configs = f"{st['thermal_files']} ({st['thermal_parsed']} text, {st['thermal_encrypted']} encrypted)" \
            if d.thermal_files else "0"
        trips = f"{st['vendor_max_trip_c'] or '–'} / {st['vendor_shutdown_c'] or '–'} °C" \
            if st["vendor_max_trip_c"] or st["vendor_shutdown_c"] else "–"
        variants = f" (+{len(d.variants)} variants)" if d.variants else ""
        lines.append(
            f"| {clean(d.brand)} {clean(d.model)} | `{d.codename}` | {clean(d.platform) or '–'} | "
            f"{clean(d.android) or '–'} | {'yes' if d.mi_thermald else 'no'} | {services} | "
            f"{configs} | {trips} | [dump]({d.source}){variants} |"
        )
    if unusable:
        lines += [
            "",
            "## Dumps without a profile",
            "",
            "Found in the dump group, but no profile could be built (no vendor `build.prop`, or the",
            "dump could not be read). These devices use runtime detection only.",
            "",
            "| Dump | Reason |",
            "|---|---|",
        ]
        for p in sorted(unusable, key=lambda p: p.get("name", p["path"])):
            lines.append(f"| [{clean(p.get('name', p['path']))}]({p['url']}) | {clean(p['reason'])} |")

    merged = sorted((v, d.codename) for d in devices for v in d.variants)
    if merged:
        lines += [
            "",
            "## Other dumps of listed devices",
            "",
            "Regional variants and other firmware versions of a device already listed above; the record",
            "uses the dump with the most thermal information.",
            "",
            "| Dump | Device |",
            "|---|---|",
        ]
        lines += [f"| {clean(v, 512)} | `{c}` |" for v, c in merged]
    (out / "docs").mkdir(exist_ok=True)
    (out / "docs" / "DEVICES.md").write_text("\n".join(lines) + "\n")


def group_links(base: str, groups: str) -> str:
    return ", ".join(f"[{g.strip()}]({base.rstrip('/')}/{g.strip()})" for g in groups.split(",") if g.strip())


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    src = ap.add_mutually_exclusive_group()
    src.add_argument("--gitlab", default=DEFAULT_GITLAB, help="GitLab instance URL")
    src.add_argument("--local", help="directory of dump checkouts (one per device)")
    ap.add_argument("--sparse", action="store_true",
                    help="with --gitlab: partial-clone each dump, checking out only the needed paths")
    ap.add_argument("--workdir", help="where --sparse clones are made (default: system temp)")
    ap.add_argument("--group", default=DEFAULT_GROUP,
                    help="comma-separated GitLab groups holding the dumps (missing groups are skipped)")
    ap.add_argument("--out", default=str(Path(__file__).resolve().parent.parent), help="repository root")
    ap.add_argument("--limit", type=int, help="scan at most N dumps per group (testing)")
    ap.add_argument("--jobs", type=int, default=8)
    args = ap.parse_args()

    if args.local:
        source, desc = LocalSource(args.local), "local dumps"
    elif args.sparse:
        source = SparseGitSource(args.gitlab, args.group, args.limit, args.workdir)
        desc = group_links(args.gitlab, args.group)
    else:
        source = GitLabSource(args.gitlab, args.group, args.limit)
        desc = group_links(args.gitlab, args.group)

    projects = source.projects()
    if args.limit:
        projects = projects[: args.limit]
    print(f"scanning {len(projects)} dumps", file=sys.stderr)

    devices: dict[str, Device] = {}
    unusable: list[dict] = []
    failures = 0
    scan_one = source.scan_project if isinstance(source, SparseGitSource) else (lambda p: scan(source, p))
    with concurrent.futures.ThreadPoolExecutor(max_workers=max(1, args.jobs)) as pool:
        futures = {pool.submit(scan_one, p): p for p in projects}
        for fut in concurrent.futures.as_completed(futures):
            p = futures[fut]
            try:
                dev = fut.result()
            except Exception as e:  # keep going: one broken dump must not stop the scan
                failures += 1
                print(f"  ! {p['path']}: {e}", file=sys.stderr)
                unusable.append({**p, "reason": f"not readable: {str(e)[:80]}"})
                continue
            if dev is None:
                print(f"  - {p['path']}: no usable build.prop with a device codename, skipped", file=sys.stderr)
                unusable.append({**p, "reason": "no build.prop with a device codename"})
                continue
            dev.dump = f"[{p.get('name', p['path'])}]({p['url']})"
            # Several dumps can share a codename (regional variants): keep the richest one,
            # and list the others under it.
            prev = devices.get(dev.codename)
            if prev is None:
                devices[dev.codename] = dev
            elif (len(dev.services), len(dev.thermal_files)) > (len(prev.services), len(prev.thermal_files)):
                dev.variants = prev.variants + [prev.dump]
                devices[dev.codename] = dev
            else:
                prev.variants.append(dev.dump)

    write_outputs(list(devices.values()), Path(args.out), desc, unusable)
    files = sum(len(d.thermal_files) for d in devices.values())
    print(f"{len(devices)} device profiles written ({files} thermal files), "
          f"{sum(len(d.variants) for d in devices.values())} variant dumps merged, "
          f"{len(unusable)} dumps without a profile, {failures} dumps failed", file=sys.stderr)
    return 1 if failures and not devices else 0


if __name__ == "__main__":
    sys.exit(main())
