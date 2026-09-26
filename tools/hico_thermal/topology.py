from __future__ import annotations

import re
from pathlib import Path

from .artifacts import classify_path, walk_relevant

_SERVICE_RE = re.compile(r"^\s*service\s+([A-Za-z0-9_.@:-]+)", re.M)
_HAL_RE = re.compile(r"android\.hardware\.thermal(?:[-./][A-Za-z0-9_.-]+)?", re.I)
_THERMAL_ZONE_RE = re.compile(r"\b(?:thermal[-_]?(?:zones?|zone)|thermal_zone\w*)\b", re.I)
_COOLING_RE = re.compile(r"\bcooling[-_]?(?:maps?|device)\b", re.I)
_DRIVER_RE = re.compile(r"\b(?:thermal-engine|mi_thermald|thermald|thermal_manager|eara_thermal|thermal-service|thermal_hal|thermalhal)\b", re.I)


def _text(path: Path) -> str:
    data = path.read_bytes()
    if b"\x00" in data[:8192]:
        return ""
    return data[:1024 * 1024].decode("utf-8", errors="replace")


def analyze_tree(root: str | Path) -> dict:
    root = Path(root)
    services: set[str] = set()
    hals: set[str] = set()
    daemons: set[str] = set()
    zone_refs: set[str] = set()
    cooling_refs: set[str] = set()
    category_counts: dict[str, int] = {}
    files = []
    for path in walk_relevant(root):
        rel = path.relative_to(root).as_posix()
        category = classify_path(path)
        category_counts[category] = category_counts.get(category, 0) + 1
        text = _text(path)
        if text:
            services.update(_SERVICE_RE.findall(text))
            hals.update(_HAL_RE.findall(text))
            daemons.update(_DRIVER_RE.findall(text))
            if _THERMAL_ZONE_RE.search(text):
                zone_refs.add(rel)
            if _COOLING_RE.search(text):
                cooling_refs.add(rel)
        files.append(rel)
    return {
        "schema": "hico.thermal-topology.v1",
        "root": str(root),
        "status": "static-scan",
        "artifact_count": len(files),
        "category_counts": dict(sorted(category_counts.items())),
        "services": sorted(services),
        "thermal_hal_references": sorted(hals),
        "thermal_daemons": sorted(daemons),
        "thermal_zone_references": sorted(zone_refs),
        "cooling_references": sorted(cooling_refs),
        "files": files,
    }
