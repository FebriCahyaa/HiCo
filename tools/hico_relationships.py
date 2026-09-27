#!/usr/bin/env python3
"""Build a conservative HiCo source relationship graph.

Metadata-first; never clones repositories and never calls GitHub/GitLab APIs.
Exact device identity creates device links. Platform hints create platform links only;
platform equality by itself never creates a device link because multiple devices can share a platform.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
from hico_dependency_resolver import resolve_dependency
DEVICE_RE = re.compile(r"(?:^|/)android_device_([^/]+)$", re.I)
VENDOR_RE = re.compile(r"(?:^|/)android_vendor_([^/]+)$", re.I)
KERNEL_RE = re.compile(r"(?:^|/)android_kernel_([^/]+)$", re.I)
HARDWARE_RE = re.compile(r"(?:^|/)android_hardware_([^/]+)$", re.I)
PLATFORM_PATTERNS = (
    re.compile(r"\b(sm\d{3,5}(?:-[a-z0-9]+)?)\b", re.I),
    re.compile(r"\b(sdm\d{3,5})\b", re.I),
    re.compile(r"\b(msm\d{4,5})\b", re.I),
    re.compile(r"\b(mt\d{4,5}[a-z0-9_-]*)\b", re.I),
    re.compile(r"\b(parrot|ravelin|lahaina|taro|kona|kalama|pineapple|bengal|monaco|waipio|holi|crow)\b", re.I),
)
ROLES = {"device", "vendor", "kernel", "hardware", "hal", "init", "firmware", "rom", "source", "independent"}


def clean(value: object, fallback: str = "unknown") -> str:
    value = re.sub(r"[^A-Za-z0-9._/-]+", "_", str(value).strip().lower())
    return value or fallback


def load_json(path: Path) -> dict:
    return json.loads(path.read_text(encoding="utf-8"))


def load_repositories(path: Path) -> list[dict]:
    data = load_json(path)
    if data.get("schema") != "hico.repositories.v1":
        raise ValueError(f"unsupported repository index schema: {data.get('schema')!r}")
    repos = data.get("repositories", [])
    if not isinstance(repos, list):
        raise ValueError("repositories must be a list")
    return [dict(r) for r in repos if isinstance(r, dict)]


def load_universal_devices(path: Path | None) -> dict[str, dict]:
    if path is None or not path.is_file():
        return {}
    data = load_json(path)
    return {str(x["id"]): x for x in data.get("devices", []) if isinstance(x, dict) and x.get("id")}


def display_path(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path).replace("\\", "/")


def repository_role(repo: dict) -> str:
    role = str(repo.get("repository_role", "")).strip().lower()
    if role in ROLES:
        return role
    if str(repo.get("ecosystem", "")).lower() == "oem":
        return "firmware"
    name = str(repo.get("full_name", ""))
    for pattern, inferred in ((DEVICE_RE, "device"), (VENDOR_RE, "vendor"), (KERNEL_RE, "kernel"), (HARDWARE_RE, "hardware")):
        if pattern.search(name):
            return inferred
    return "source"


def infer_device(repo: dict) -> str:
    explicit = clean(repo.get("device", ""), "")
    if explicit:
        return explicit
    name = str(repo.get("full_name", "")).strip("/")
    m = DEVICE_RE.search(name)
    if m:
        return clean(m.group(1).split("_")[-1], "")
    if str(repo.get("ecosystem", "")).lower() == "oem":
        parts = name.split("/")
        if len(parts) >= 2:
            return clean(parts[-1], "")
    return ""


def device_id_for_repo(repo: dict) -> str | None:
    vendor = clean(repo.get("vendor", ""), "")
    device = infer_device(repo)
    return f"{vendor}/{device}" if vendor and device else None


def infer_platforms(repo: dict, universal: dict[str, dict]) -> set[str]:
    text = " ".join(str(repo.get(k, "")) for k in ("full_name", "device", "vendor", "source_id", "rom_family"))
    platforms = {clean(m.group(1)) for p in PLATFORM_PATTERNS for m in p.finditer(text)}
    did = device_id_for_repo(repo)
    if did and universal.get(did, {}).get("platform"):
        platforms.add(clean(universal[did]["platform"]))
    return platforms


def source_id(repo: dict) -> str:
    return f"{clean(repo.get('provider', 'unknown'))}/{str(repo.get('full_name', '')).strip('/')}"


def make_relationship(repo: dict, target: str, rel_type: str, confidence: str, evidence: list[str]) -> dict:
    return {
        "source": source_id(repo),
        "source_repository": repo.get("full_name", ""),
        "source_provider": repo.get("provider", ""),
        "source_role": repository_role(repo),
        "target": target,
        "type": rel_type,
        "confidence": confidence,
        "evidence": sorted(set(evidence)),
    }


def normalize_index(repos: list[dict]) -> tuple[list[dict], int]:
    out, changed = [], 0
    for repo in repos:
        item = dict(repo)
        if str(item.get("ecosystem", "")).lower() == "oem" and not item.get("repository_role"):
            item["repository_role"] = "firmware"
            changed += 1
        out.append(item)
    return out, changed


def repository_identity_relationship(repo: dict) -> tuple[str, str, str, list[str]] | None:
    did = device_id_for_repo(repo)
    if not did:
        return None
    role = repository_role(repo)
    mapping = {
        "device": "device-source",
        "firmware": "firmware-device",
        "vendor": "vendor-device",
        "hardware": "hardware-device-exact",
        "hal": "hal-device-exact",
        "init": "init-device-exact",
    }
    if role not in mapping:
        return None
    return did, mapping[role], "high", ["repository-device-identity"]


def repository_source_key(provider: str, full_name: str) -> str:
    return f"{clean(provider, 'unknown')}/{str(full_name).strip('/')}"


def index_repository_lookup(repos: list[dict]) -> dict[str, list[dict]]:
    by_basename: dict[str, list[dict]] = {}
    for repo in repos:
        name = str(repo.get("full_name", "")).strip("/")
        if not name:
            continue
        base = name.rsplit("/", 1)[-1]
        by_basename.setdefault(base, []).append(repo)
    return by_basename


def load_evidence_files(evidence_roots: list[Path]) -> dict[str, dict[str, str]]:
    """Load lightweight source evidence from collector manifests.

    Returns source repository -> {tree_path: absolute raw path}. Only manifests and
    text/json-like files needed for relationship evidence are considered.
    """
    evidence: dict[str, dict[str, str]] = {}
    for root in evidence_roots:
        if not root.is_dir():
            continue
        for manifest_path in sorted(root.rglob("manifest.json")):
            try:
                manifest = load_json(manifest_path)
            except Exception:
                continue
            source = manifest.get("source", {})
            repo_name = str(source.get("repository", "")).strip()
            provider = str(source.get("provider", "")).strip()
            if not repo_name or not provider:
                continue
            key = repository_source_key(provider, repo_name)
            bucket = evidence.setdefault(key, {})
            for item in manifest.get("files", []):
                tree_path = str(item.get("tree_path") or item.get("path") or "").strip("/")
                raw_path = str(item.get("raw_path") or "")
                if not tree_path or not raw_path:
                    continue
                raw = Path(raw_path)
                if not raw.is_absolute():
                    # Manifest paths are normally ROOT-relative.
                    raw = ROOT / raw
                if raw.is_file():
                    bucket[tree_path] = str(raw)
    return evidence


def parse_lineage_dependencies(path: Path) -> list[dict[str, str]]:
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return []
    if not isinstance(data, list):
        return []
    out: list[dict[str, str]] = []
    seen = set()
    for item in data:
        if not isinstance(item, dict):
            continue
        repository = str(item.get("repository", "")).strip()
        if not repository:
            continue
        record = {
            "repository": repository,
            "target_path": str(item.get("target_path", "")).strip("/"),
        }
        key = (record["repository"], record["target_path"])
        if key in seen:
            continue
        seen.add(key)
        out.append(record)
    return sorted(out, key=lambda item: (item["repository"], item["target_path"]))


def parse_boardconfig_references(path: Path) -> list[tuple[str, str]]:
    """Return (kind, target) build-tree references from BoardConfig.mk."""
    try:
        text = path.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return []
    refs: list[tuple[str, str]] = []
    patterns = (
        ("kernel-source", re.compile(r"^\s*TARGET_KERNEL_SOURCE\s*:?=\s*([^\s#]+)", re.M)),
        ("kernel-modules-root", re.compile(r"^\s*TARGET_KERNEL_EXT_MODULE_ROOT\s*:?=\s*([^\s#]+)", re.M)),
        ("vendor-include", re.compile(r"^\s*include\s+(vendor/[^\s#]+)", re.M)),
        ("hardware-include", re.compile(r"^\s*include\s+(hardware/[^\s#]+)", re.M)),
    )
    for kind, pattern in patterns:
        for match in pattern.finditer(text):
            refs.append((kind, match.group(1).strip()))
    return sorted(set(refs))


def build_relationships(
    repos: list[dict],
    universal: dict[str, dict],
    evidence_roots: list[Path] | None = None,
) -> tuple[list[dict], dict]:
    rels = []
    seen = set()
    counts = Counter()
    device_keys = set(universal)
    by_basename = index_repository_lookup(repos)
    evidence = load_evidence_files(evidence_roots or [])

    for repo in repos:
        did = device_id_for_repo(repo)
        if did:
            device_keys.add(did)
        role = repository_role(repo)

        identity = repository_identity_relationship(repo)
        if identity:
            target, typ, confidence, ev = identity
            rel = make_relationship(repo, target, typ, confidence, ev)
            key = (rel["source"], rel["type"], rel["target"])
            if key not in seen:
                seen.add(key)
                rels.append(rel)
                counts[typ] += 1

        for platform in sorted(infer_platforms(repo, universal)):
            rel = make_relationship(
                repo,
                f"platform/{platform}",
                "platform-source",
                "high" if role in {"device", "firmware"} else "medium",
                [f"platform-hint:{platform}"],
            )
            key = (rel["source"], rel["type"], rel["target"])
            if key not in seen:
                seen.add(key)
                rels.append(rel)
                counts["platform-source"] += 1

        source_key = repository_source_key(repo.get("provider", "unknown"), repo.get("full_name", ""))
        files = evidence.get(source_key, {})

        deps_path = next((Path(v) for k, v in files.items() if k == "lineage.dependencies"), None)
        if deps_path:
            for dependency in parse_lineage_dependencies(deps_path):
                dep_name = dependency["repository"]
                resolution = resolve_dependency(dep_name, repos)
                if resolution["status"] == "resolved":
                    target_repo = resolution["repository"]
                    target = repository_source_key(
                        target_repo.get("provider", "unknown"),
                        target_repo.get("full_name", ""),
                    )
                    rel = make_relationship(
                        repo,
                        target,
                        "dependency-source",
                        "high",
                        ["lineage.dependencies", f"dependency:{dep_name}"],
                    )
                else:
                    rel = make_relationship(
                        repo,
                        f"repository-name/{clean(dep_name)}",
                        "dependency-source-unresolved",
                        "medium",
                        ["lineage.dependencies", f"dependency:{dep_name}"],
                    )
                key = (rel["source"], rel["type"], rel["target"])
                if key not in seen:
                    seen.add(key)
                    rels.append(rel)
                    counts[rel["type"]] += 1

        boardconfig = next((Path(v) for k, v in files.items() if k == "BoardConfig.mk"), None)
        if boardconfig:
            for kind, target_path in parse_boardconfig_references(boardconfig):
                rel = make_relationship(
                    repo,
                    f"build-path/{target_path}",
                    "build-path-reference",
                    "high",
                    ["BoardConfig.mk", kind],
                )
                key = (rel["source"], rel["type"], rel["target"])
                if key not in seen:
                    seen.add(key)
                    rels.append(rel)
                    counts["build-path-reference"] += 1

    summary = {
        "repository_count": len(repos),
        "relationship_count": len(rels),
        "relationship_types": dict(sorted(counts.items())),
        "device_count": len(device_keys),
        "platform_count": len({r["target"] for r in rels if r["target"].startswith("platform/")}),
    }
    return sorted(rels, key=lambda r: (r["source"], r["type"], r["target"])), summary

def save_index(path: Path, repos: list[dict]) -> None:
    old = {}
    if path.is_file():
        try: old = load_json(path)
        except Exception: pass
    payload = {
        "schema": "hico.repositories.v1",
        "description": old.get("description", "Concrete repository index."),
        "repository_count": len(repos),
        "repositories": sorted(repos, key=lambda r: (str(r.get("provider", "")), str(r.get("full_name", "")))),
    }
    for key in ("generated_from", "discovery_snapshot"):
        if key in old: payload[key] = old[key]
    path.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repositories", default=str(ROOT / "sources/repositories.json"))
    ap.add_argument("--universal-index", default=str(ROOT / "database/universal/index.json"))
    ap.add_argument("--output", default=str(ROOT / "sources/relationships.json"))
    ap.add_argument("--evidence-root", action="append", default=None, help="Evidence root; may be repeated. Explicit values override the canonical sources/evidence root.")
    ap.add_argument("--normalize-index", action="store_true", help="Backfill missing OEM repository_role=firmware")
    args = ap.parse_args()
    repo_path = Path(args.repositories)
    repos = load_repositories(repo_path)
    universal = load_universal_devices(Path(args.universal_index))
    normalized, role_changes = normalize_index(repos)
    if args.normalize_index:
        save_index(repo_path, normalized)
        repos = normalized
    evidence_roots = [Path(p) for p in args.evidence_root] if args.evidence_root else [ROOT / "sources" / "evidence"]
    rels, summary = build_relationships(repos, universal, evidence_roots)
    output = Path(args.output)
    output.parent.mkdir(parents=True, exist_ok=True)
    payload = {
        "schema": "hico.source-relationships.v1",
        "version": 1,
        "generated_from": display_path(repo_path),
        "universal_index": display_path(Path(args.universal_index)),
        "normalization": {"oem_role_changes_available": role_changes, "applied": bool(args.normalize_index)},
        "summary": summary,
        "relationships": rels,
    }
    output.write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")
    print(json.dumps({**summary, "oem_role_changes_available": role_changes, "normalized": bool(args.normalize_index), "output": str(output)}, indent=2))
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
