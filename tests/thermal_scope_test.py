#!/usr/bin/env python3
"""Guardrail: thermal monitor/tooling must not pull Flux/Tweaks concerns into the thermal layer."""
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
FILES = [
    ROOT / "jni/include/Monitor.hpp",
    ROOT / "jni/src/Monitor.cpp",
    ROOT / "webui/src/views/Monitor.vue",
    ROOT / ".github/workflows/tools.yml",
    *sorted((ROOT / "tools/hico_thermal").rglob("*.py")),
]
# CPU/GPU temperature names are legitimate thermal telemetry. Only concrete Flux/Tweaks/game/performance
# component identifiers are forbidden from this thermal-only surface.
FORBIDDEN = re.compile(r"\bFlux(?:Boost|Sched)?\b|GameTweaks|Games\.vue|CpuGovernor|GpuGovernor|Profiler|RenderBooster|gamelist", re.I)

for path in FILES:
    text = path.read_text(errors="replace")
    match = FORBIDDEN.search(text)
    assert not match, f"thermal scope violation in {path}: {match.group(0)!r}"

workflow = (ROOT / ".github/workflows/tools.yml").read_text(errors="replace")
assert "gh release" not in workflow.lower(), "tools workflow must not publish releases"
assert "release_token" not in workflow.lower(), "tools workflow must not use release credentials"
assert "build-module" not in workflow.lower(), "tools workflow must not package flashable releases"
assert (ROOT / ".github/workflows/release.yml").is_file(), "release workflow must remain separate"

print(f"thermal scope: {len(FILES)} files clean")
