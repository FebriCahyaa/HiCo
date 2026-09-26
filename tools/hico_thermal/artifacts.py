from __future__ import annotations

import hashlib
import io
import json
import re
import struct
import tarfile
import zipfile
from pathlib import Path
from typing import Iterable

MAX_INSPECT_BYTES = 512 * 1024
MAX_TEXT_BYTES = 1024 * 1024

THERMAL_NAME_RE = re.compile(
    r"(?:^|/)(?:thermal|thermald|thermal-engine|thermal_manager|thermal_core|"
    r"thermal-hal|thermal_info_config|powerhint|powerhal|perf(?:ormance)?|"
    r"cpufreq|devfreq|cooling|trip[_-]?point|thermal[_-]?zone)(?:[._/-]|$)",
    re.I,
)

THERMAL_EXTENSIONS = {
    ".conf", ".json", ".xml", ".ini", ".prop", ".rc", ".dts", ".dtsi",
    ".mk", ".bp", ".te", ".txt", ".dependencies",
}

DEVICE_TREE_NAMES = {
    "androidproducts.mk",
    "boardconfig.mk",
    "device.mk",
    "lineage.dependencies",
    "evolution.dependencies",
    "aospa.dependencies",
    "proprietary-files.txt",
    "extract-files.sh",
    "extract-files.py",
    "setup-makefiles.sh",
    "setup-makefiles.py",
    ".gitmodules",
}


def sha256_bytes(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def sha256_file(path: Path, chunk: int = 1024 * 1024) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        while True:
            block = f.read(chunk)
            if not block:
                break
            h.update(block)
    return h.hexdigest()


def is_probably_text(data: bytes) -> bool:
    if not data:
        return True
    sample = data[:8192]
    if b"\x00" in sample:
        return False
    bad = sum(1 for b in sample if b < 9 or 13 < b < 32 or b == 127)
    return bad <= max(2, len(sample) // 100)


def _ext4(data: bytes) -> bool:
    return len(data) >= 0x43A and data[0x438:0x43A] == b"\x53\xEF"


def _erofs(data: bytes) -> bool:
    return len(data) >= 1028 and data[1024:1028] == struct.pack("<I", 0xE0F5E1E2)


def _tar_bytes(data: bytes) -> bool:
    if len(data) < 512 or data[257:262] != b"ustar":
        return False
    try:
        with tarfile.open(fileobj=io.BytesIO(data), mode="r:"):
            return True
    except (OSError, tarfile.TarError):
        return False


def detect_format(path: str | Path, data: bytes | None = None) -> str:
    p = Path(path)
    name = str(p).lower()
    data = data if data is not None else p.read_bytes()[:MAX_INSPECT_BYTES]
    if not data:
        return "empty"
    if data.startswith(b"PK\x03\x04"):
        return "zip"
    if p.is_file():
        try:
            if zipfile.is_zipfile(p):
                return "zip"
        except (OSError, zipfile.BadZipFile):
            pass
    if data.startswith(b"\x1f\x8b"):
        return "gzip"
    if data.startswith(b"\xfd7zXZ\x00"):
        return "xz"
    if data.startswith(b"BZh"):
        return "bzip2"
    if data.startswith(b"(\xb5/\xfd"):
        return "zstd"
    if len(data) >= 4 and data[:4] == b"\x3a\xff\x26\xed":
        return "android-sparse"
    if p.name.lower() == "super.img":
        return "android-super"
    if _erofs(data):
        return "erofs"
    if _ext4(data):
        return "ext4"
    if data.startswith(b"\x7fELF"):
        return "elf"
    if _tar_bytes(data):
        return "tar"
    if p.is_file():
        try:
            if tarfile.is_tarfile(p):
                return "tar"
        except (OSError, tarfile.TarError):
            pass
    text = data.lstrip()
    if text.startswith(b"{") or text.startswith(b"["):
        try:
            json.loads(data.decode("utf-8"))
            return "json"
        except (UnicodeDecodeError, json.JSONDecodeError):
            pass
    if text.startswith(b"<"):
        return "xml"
    if is_probably_text(data):
        text_data = data.decode("utf-8", errors="replace")
        if re.search(r"^\s*\[[^\]]+\]\s*$", text_data, re.M):
            return "thermal-engine-text"
        return "text"
    if ".conf" in name or "thermal" in name or "thermald" in name:
        return "opaque-binary"
    return "binary"


def classify_path(path: str | Path) -> str:
    p = str(path).replace("\\", "/")
    base = Path(p).name.lower()
    lower = p.lower()
    if (
        "thermal" in base
        or "thermald" in base
        or "/thermal/" in lower
        or "thermal_info_config" in lower
        or "thermal-zones" in lower
        or "trip_point" in lower
    ):
        return "thermal"
    if (
        base.startswith("powerhint")
        or "powerhal" in base
        or "power-policy" in lower
        or base.startswith("perf")
    ):
        return "power-performance"
    if any(token in lower for token in ("cpufreq", "devfreq", "cooling", "energy_model", "sched_policy")):
        return "kernel-performance"
    if base in DEVICE_TREE_NAMES or base.endswith((".dts", ".dtsi")):
        if base.endswith((".dts", ".dtsi")) and not any(k in lower for k in ("thermal", "cooling", "trip")):
            return "device-tree"
        return "device-tree-thermal"
    if base.endswith(".rc") and any(k in lower for k in ("thermal", "power", "perf")):
        return "init-service"
    return "other"


def relevant_path(path: str | Path) -> bool:
    category = classify_path(path)
    if category != "other":
        return True
    p = Path(path)
    name = p.name.lower()
    lower = str(p).replace("\\", "/").lower()
    if name in DEVICE_TREE_NAMES:
        return True
    if name in {"build.prop", "vendor.prop", "odm.prop", "product.prop", "system.prop"}:
        return True
    if p.suffix.lower() in THERMAL_EXTENSIONS and any(
        token in lower
        for token in (
            "thermal", "thermald", "power", "perf", "cooling", "cpufreq", "devfreq",
            "thermal-zone", "trip-point", "thermal_service",
        )
    ):
        return True
    return False


def parse_engine_text(text: str) -> dict:
    sections: list[dict] = []
    current: dict | None = None
    shutdown: list[float] = []
    for raw in text.splitlines():
        line = raw.split("#", 1)[0].strip()
        if not line:
            continue
        m = re.match(r"^\[([^\]]+)\]$", line)
        if m:
            current = {"name": m.group(1), "sensor": "", "device": "", "algorithm": "", "thresholds": []}
            sections.append(current)
            continue
        if current is None:
            continue
        parts = re.split(r"\s+", line, maxsplit=1)
        if len(parts) != 2:
            continue
        key, value = parts
        if key in {"sensor", "device", "algo_type"}:
            current[{"sensor": "sensor", "device": "device", "algo_type": "algorithm"}[key]] = value.strip()
        elif key in {"thresholds", "set_point", "trig", "temp", "shutdown"}:
            values = []
            for token in value.split():
                try:
                    number = float(token)
                except ValueError:
                    continue
                normalized = number / 1000.0 if abs(number) >= 1000 else number
                values.append(normalized)
                if key == "shutdown":
                    shutdown.append(normalized)
            current["thresholds"].extend(values)
    max_trip = None
    for section in sections:
        if section["thresholds"]:
            candidate = max(section["thresholds"])
            max_trip = candidate if max_trip is None else max(max_trip, candidate)
    return {
        "sections": len(sections),
        "max_trip_c": max_trip,
        "shutdown_c": min(shutdown) if shutdown else None,
    }


def analyze_file(path: str | Path, data: bytes | None = None) -> dict:
    p = Path(path)
    data = data if data is not None else p.read_bytes()
    fmt = detect_format(p, data[:MAX_INSPECT_BYTES])
    result = {
        "path": str(p).replace("\\", "/"),
        "name": p.name,
        "category": classify_path(p),
        "format": fmt,
        "size": len(data),
        "sha256": sha256_bytes(data),
        "parser": None,
        "sections": 0,
        "max_trip_c": None,
        "shutdown_c": None,
    }
    if fmt == "thermal-engine-text" and len(data) <= MAX_TEXT_BYTES:
        parsed = parse_engine_text(data.decode("utf-8", errors="replace"))
        result.update(parsed)
        result["parser"] = "thermal-engine-text-v2"
    elif fmt == "json" and len(data) <= MAX_TEXT_BYTES:
        try:
            obj = json.loads(data.decode("utf-8"))
            if isinstance(obj, dict) and isinstance(obj.get("Sensors"), list):
                result["parser"] = "thermal-hal-json-v2"
                result["sections"] = len(obj["Sensors"])
        except (UnicodeDecodeError, json.JSONDecodeError):
            pass
    return result


def walk_relevant(root: Path) -> Iterable[Path]:
    root = Path(root)
    for path in sorted(root.rglob("*")):
        if path.is_file() and relevant_path(path):
            yield path
