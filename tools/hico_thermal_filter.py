#!/usr/bin/env python3
"""Rank repository-index records for token-free thermal collection.

This stage is intentionally metadata-only. It never clones repositories and never
calls GitHub/GitLab APIs. It reduces the collector fan-out using repository role,
identity hints, repository naming signals, and ROM-family context.
"""
from __future__ import annotations

import argparse
import json
import re
from collections import Counter
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_INPUT = ROOT / "sources/repositories.json"
DEFAULT_OUTPUT = ROOT / "sources/thermal-candidates.json"
DEFAULT_REPORT = ROOT / "sources/thermal-filter.json"

# Strong signals identify source layers that commonly own thermal configuration,
# sensor definitions, governors, cooling policy, or power/performance controls.
ROLE_SCORES = {
    "device": 70,
    "vendor": 65,
    "kernel": 60,
    "hardware": 55,
    "hal": 50,
    "init": 45,
    "firmware": 45,
    "mod": 35,
    "source": 20,
    "independent": 20,
    "rom": 15,
    "unknown": 0,
}

THERMAL_NAME_RE = re.compile(
    r"(?:^|[_/.-])(thermal|thermald|thermal-engine|thermal_hal|thermal-info|"
    r"thermal_config|thermal-zone|trip[-_]?point|cooling|cpufreq|devfreq|"
    r"powerhal|power[-_]?policy|perf(?:ormance)?)(?:$|[_/.-])",
    re.I,
)

PERFORMANCE_NAME_RE = re.compile(
    r"(?:^|[_/.-])(sched|governor|energy[_-]?model|uclamp|qos|boost|"
    r"mpm|rpmh|powerhint|perf)(?:$|[_/.-])",
    re.I,
)

GENERIC_REPO_NAMES = {
    "android",
    "android_art",
    "android_frameworks_base",
    "android_frameworks_native",
    "android_system_core",
    "android_system_sepolicy",
    "android_build",
    "frameworks_base",
    "frameworks_native",
    "system_core",
    "build",
    "manifest",
}

@dataclass(frozen=True)
class Decision:
    score: int
    verdict: str
    confidence: str
    reasons: tuple[str, ...]


def load_repositories(path: Path) -> list[dict]:
    data = json.loads(path.read_text(encoding="utf-8"))
    if data.get("schema") != "hico.repositories.v1":
        raise ValueError(f"unsupported repository index schema: {data.get('schema')!r}")
    repos = data.get("repositories", [])
    if not isinstance(repos, list):
        raise ValueError("repositories must be a list")
    return [dict(item) for item in repos if isinstance(item, dict)]


def norm(value: object) -> str:
    return str(value or "").strip().lower()


def repo_name(record: dict) -> str:
    return norm(record.get("full_name")).rsplit("/", 1)[-1]


def decide(record: dict, min_score: int = 25) -> Decision:
    role = norm(record.get("repository_role") or record.get("role"))
    ecosystem = norm(record.get("ecosystem"))
    if role in {"", "unknown"} and ecosystem == "oem":
        role = "firmware"
    role = role or "unknown"
    family = norm(record.get("rom_family"))
    ecosystem = norm(record.get("ecosystem"))
    vendor = norm(record.get("vendor"))
    device = norm(record.get("device"))
    android = norm(record.get("android"))
    full_name = norm(record.get("full_name"))
    name = repo_name(record)

    score = ROLE_SCORES.get(role, 0)
    reasons: list[str] = []

    if role in ROLE_SCORES and ROLE_SCORES[role] > 0:
        reasons.append(f"role:{role}+{ROLE_SCORES[role]}")
    else:
        reasons.append("role:unknown+0")

    if vendor and vendor != "unknown":
        score += 15
        reasons.append("vendor-identity+15")
    if device and device != "unknown":
        score += 20
        reasons.append("device-identity+20")
    if android and android != "unknown":
        score += 5
        reasons.append("android-identity+5")

    has_thermal_name = bool(THERMAL_NAME_RE.search(full_name))
    has_performance_name = bool(PERFORMANCE_NAME_RE.search(full_name))

    if has_thermal_name:
        score += 45
        reasons.append("thermal-name-signal+45")
    elif has_performance_name:
        score += 20
        reasons.append("performance-name-signal+20")

    # Custom ROM framework repositories are lower-confidence sources. A generic
    # ROM/framework repository is not a collector candidate by identity alone;
    # it must carry an explicit thermal/performance name signal.
    custom_rom_rom_gate = ecosystem == "custom-rom" and role == "rom"
    if custom_rom_rom_gate:
        reasons.append("custom-rom-framework-low-weight")
    if name in GENERIC_REPO_NAMES and not THERMAL_NAME_RE.search(full_name):
        score -= 10
        reasons.append("generic-framework-penalty-10")

    if family in {"lineageos", "pixelos", "evolution-x", "crdroid", "aospa", "arrowos", "derpfest", "voltageos", "superioros", "project-elixir"}:
        score += 5
        reasons.append("known-rom-family+5")

    # Apply the custom-ROM ROM gate after all additive scoring so vendor/family
    # identity cannot accidentally push a generic framework repository back over
    # the candidate threshold.
    if custom_rom_rom_gate and not has_thermal_name and not has_performance_name:
        score = min(score, max(min_score - 1, 0))
        reasons.append("custom-rom-rom-requires-thermal-signal")

    score = max(score, 0)
    if score >= max(min_score + 30, 55):
        confidence = "high"
    elif score >= min_score:
        confidence = "medium"
    else:
        confidence = "low"

    # No metadata signal means the collector should not clone the repository.
    if score >= min_score:
        verdict = "candidate"
    else:
        verdict = "reject"

    return Decision(score, verdict, confidence, tuple(reasons))


def filter_repositories(repositories: list[dict], min_score: int = 25) -> tuple[list[dict], list[dict]]:
    candidates: list[dict] = []
    decisions: list[dict] = []
    for record in repositories:
        decision = decide(record, min_score=min_score)
        enriched = dict(record)
        enriched["thermal_filter"] = {
            "score": decision.score,
            "verdict": decision.verdict,
            "confidence": decision.confidence,
            "reasons": list(decision.reasons),
        }
        decisions.append(enriched)
        if decision.verdict == "candidate":
            candidate = {k: v for k, v in record.items()}
            if not candidate.get("repository_role") and candidate.get("role"):
                candidate["repository_role"] = candidate["role"]
            if not candidate.get("repository_role") and norm(candidate.get("ecosystem")) == "oem":
                candidate["repository_role"] = "firmware"
            candidates.append(candidate)
    return candidates, decisions


def root_relative(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path.resolve()).replace("\\", "/")


def write_json(path: Path, payload: object) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--input", default=str(DEFAULT_INPUT))
    ap.add_argument("--output", default=str(DEFAULT_OUTPUT))
    ap.add_argument("--report", default=str(DEFAULT_REPORT))
    ap.add_argument("--min-score", type=int, default=25)
    args = ap.parse_args()
    if args.min_score < 0 or args.min_score > 200:
        ap.error("--min-score must be 0..200")

    repositories = load_repositories(Path(args.input))
    candidates, decisions = filter_repositories(repositories, args.min_score)
    candidates.sort(key=lambda item: (norm(item.get("provider")), norm(item.get("full_name"))))
    decisions.sort(key=lambda item: (norm(item.get("provider")), norm(item.get("full_name"))))

    candidate_payload = {
        "schema": "hico.repositories.v1",
        "description": "Thermal-focused repository subset produced by metadata-only filtering.",
        "generated_from": root_relative(Path(args.input)),
        "filter_report": root_relative(Path(args.report)),
        "repository_count": len(candidates),
        "repositories": candidates,
    }
    write_json(Path(args.output), candidate_payload)

    verdicts = Counter(item["thermal_filter"]["verdict"] for item in decisions)
    confidences = Counter(item["thermal_filter"]["confidence"] for item in decisions)
    roles = Counter(item.get("repository_role") or "unknown" for item in candidates)
    report = {
        "schema": "hico.thermal-filter.v1",
        "description": "Metadata-only thermal candidate classification; this does not prove thermal-source presence.",
        "generated_from": root_relative(Path(args.input)),
        "min_score": args.min_score,
        "repository_count": len(decisions),
        "candidate_count": len(candidates),
        "reject_count": len(decisions) - len(candidates),
        "verdicts": dict(sorted(verdicts.items())),
        "confidences": dict(sorted(confidences.items())),
        "candidate_roles": dict(sorted(roles.items())),
        "decisions": decisions,
    }
    write_json(Path(args.report), report)

    print(json.dumps({
        "repositories": len(repositories),
        "candidates": len(candidates),
        "rejected": len(repositories) - len(candidates),
        "high_confidence": confidences.get("high", 0),
        "medium_confidence": confidences.get("medium", 0),
        "output": str(args.output),
        "report": str(args.report),
    }, indent=2))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
