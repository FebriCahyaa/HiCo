#!/usr/bin/env python3
"""Token-free discovery of public OEM/ROM Git repositories.

Reads sources/registry.json, discovers public repository links from HTML listings,
verifies candidates with git ls-remote, resolves default branches, and writes
sources/repositories.json plus a diagnostic sources/discovery.json snapshot.
No GitHub/GitLab REST API or access token is used.
"""
from __future__ import annotations

import argparse
import concurrent.futures
import html
import json
import os
import re
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from urllib.parse import parse_qsl, urlencode, urljoin, urlparse, urlunparse
from urllib.request import Request, urlopen

ROOT = Path(__file__).resolve().parent.parent
DEFAULT_REGISTRY = ROOT / "sources/registry.json"
DEFAULT_REPOSITORIES = ROOT / "sources/repositories.json"
DEFAULT_SNAPSHOT = ROOT / "sources/discovery.json"

OEM_ALIASES = {
    "xiaomi": "xiaomi", "redmi": "xiaomi", "poco": "xiaomi",
    "samsung": "samsung", "oneplus": "oneplus", "oppo": "oppo",
    "realme": "realme", "vivo": "vivo", "iqoo": "vivo",
    "motorola": "motorola", "google": "google", "sony": "sony",
    "asus": "asus", "nothing": "nothing", "huawei": "huawei",
    "honor": "honor", "lenovo": "lenovo", "zte": "zte",
    "nubia": "nubia", "meizu": "meizu",
}

ROLE_RULES = (
    ("device", re.compile(r"(^|/)android_device_[^/]+", re.I)),
    ("vendor", re.compile(r"(^|/)android_vendor_[^/]+", re.I)),
    ("kernel", re.compile(r"(^|/)android_kernel_[^/]+", re.I)),
    ("hardware", re.compile(r"(^|/)android_hardware_[^/]+", re.I)),
    ("hal", re.compile(r"(^|/)(?:android_)?(?:hardware_interfaces|thermal_hal)[^/]*", re.I)),
    ("init", re.compile(r"(^|/)(?:android_)?init[^/]*", re.I)),
    ("rom", re.compile(r"(^|/)(?:android_)?(?:frameworks|packages|system|platform|build|manifest|vendor_lineage)[^/]*", re.I)),
)


def clean(value: str, fallback: str = "unknown") -> str:
    value = re.sub(r"[^A-Za-z0-9._-]+", "_", value.strip().lower())
    return value or fallback


def family_from_registry(source: dict) -> str:
    return clean(str(source.get("family") or "independent"))


def ecosystem_from_registry(source: dict) -> str:
    family = family_from_registry(source)
    if family == "oem" or (
        source.get("type") == "gitlab_group"
        and str(source.get("id", "")).startswith("tadiphone-")
    ):
        return "oem"
    if family == "independent":
        return "independent"
    return "custom-rom"


def vendor_hint(source: dict, repo_name: str) -> str:
    sid = str(source.get("id", "")).lower()
    match = re.search(r"tadiphone-([a-z0-9_-]+)", sid)
    if match:
        token = match.group(1)
        return OEM_ALIASES.get(token, clean(token))
    for token in re.split(r"[^a-z0-9]+", repo_name.lower()):
        if token in OEM_ALIASES:
            return OEM_ALIASES[token]
    return ""


def role_hint(full_name: str, family: str, ecosystem: str) -> str:
    for role, pattern in ROLE_RULES:
        if pattern.search(full_name.strip("/")):
            return role
    return "firmware" if ecosystem == "oem" else (
        "rom" if family not in {"oem", "independent"} else "source"
    )


def device_hint(full_name: str) -> str:
    name = full_name.rsplit("/", 1)[-1]
    match = re.search(r"android_(?:device|vendor|kernel)_([a-z0-9_-]+)$", name, re.I)
    if not match:
        return ""
    parts = match.group(1).split("_")
    if len(parts) >= 2 and parts[-1]:
        return clean(parts[-1])
    return clean(parts[0]) if parts else ""


def set_page(url: str, page: int) -> str:
    parsed = urlparse(url)
    query = [(k, v) for k, v in parse_qsl(parsed.query, keep_blank_values=True) if k != "page"]
    if page > 1:
        query.append(("page", str(page)))
    return urlunparse(parsed._replace(query=urlencode(query)))


def fetch_text(url: str, timeout: int = 30) -> str:
    request = Request(
        url,
        headers={
            "User-Agent": "HiCo-Thermal-Discovery/1.0",
            "Accept": "text/html,application/xhtml+xml",
        },
    )
    with urlopen(request, timeout=timeout) as response:
        return response.read().decode("utf-8", errors="replace")


def extract_hrefs(page: str) -> list[str]:
    return [
        html.unescape(match.group(1).strip())
        for match in re.finditer(r"""href\s*=\s*["']([^"']+)["']""", page, re.I)
    ]


def github_repo_links(page: str, organization: str) -> set[str]:
    out: set[str] = set()
    org = organization.strip("/")
    pattern = re.compile(rf"^https://github\.com/{re.escape(org)}/([^/?#]+)/?$", re.I)
    for raw in extract_hrefs(page):
        href = urljoin(f"https://github.com/{org}/", raw)
        match = pattern.match(href)
        if match:
            out.add(f"https://github.com/{org}/{match.group(1)}")
    return out


def gitlab_repo_links(page: str, base: str, group: str) -> set[str]:
    out: set[str] = set()
    parsed_base = urlparse(base)
    group = group.strip("/")
    prefix = "/" + group + "/"
    for raw in extract_hrefs(page):
        href = urljoin(base.rstrip("/") + "/", raw)
        parsed = urlparse(href)
        if parsed.netloc != parsed_base.netloc or not parsed.path.startswith(prefix):
            continue
        suffix = parsed.path[len(prefix):].strip("/")
        if not suffix or suffix.startswith(("-", "users", "groups", "explore")):
            continue
        out.add(f"{parsed.scheme}://{parsed.netloc}/{group}/{suffix}")
    return out


def load_existing_index(path: Path) -> list[dict]:
    # Load the existing collector-ready repository index when available.
    if not path.exists():
        return []
    try:
        import json
        payload = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, ValueError):
        return []
    repositories = payload.get("repositories", [])
    if not isinstance(repositories, list):
        return []
    return [dict(item) for item in repositories if isinstance(item, dict)]


def merge_repository_records(
    existing: list[dict],
    discovered: list[dict],
) -> list[dict]:
    # Merge by provider/full_name without dropping the existing index.
    merged: dict[tuple[str, str], dict] = {}

    for record in existing:
        item = dict(record)
        if item.get("ecosystem") == "oem" and not item.get("repository_role"):
            item["repository_role"] = "firmware"
        key = (str(item.get("provider", "")), str(item.get("full_name", "")))
        if key != ("", ""):
            merged[key] = item

    for record in discovered:
        item = dict(record)
        key = (str(item.get("provider", "")), str(item.get("full_name", "")))
        if key != ("", ""):
            merged[key] = item

    return sorted(
        merged.values(),
        key=lambda item: (
            str(item.get("provider", "")),
            str(item.get("full_name", "")),
        ),
    )


def probe_default_branch(clone_url: str, timeout: int = 45) -> tuple[str, str | None]:
    proc = subprocess.run(
        ["git", "ls-remote", "--symref", clone_url, "HEAD"],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
        timeout=timeout,
        check=False,
    )
    if proc.returncode:
        return "error", None

    for line in proc.stdout.splitlines():
        if line.startswith("ref: refs/heads/") and "\tHEAD" in line:
            branch = line.split("ref: refs/heads/", 1)[1].split("\t", 1)[0]
            return "ok", branch

    if not proc.stdout.strip():
        return "empty", None

    return "error", None


@dataclass(frozen=True)
class Candidate:
    source: dict
    web_url: str


def discover_source(source: dict, max_pages: int, timeout: int) -> tuple[list[Candidate], dict]:
    source_type = str(source.get("type", ""))
    found: set[str] = set()
    pages = 0
    errors: list[str] = []

    if source_type == "github_org":
        org = str(source.get("organization", "")).strip()
        if not org:
            return [], {"pages": 0, "errors": ["missing organization"], "candidate_count": 0}
        base = f"https://github.com/orgs/{org}/repositories?type=all&sort=name"
        extractor = lambda body: github_repo_links(body, org)
    elif source_type == "gitlab_group":
        base_url = str(source.get("base", "")).rstrip("/")
        group = str(source.get("group", "")).strip("/")
        if not base_url or not group:
            return [], {"pages": 0, "errors": ["missing base/group"], "candidate_count": 0}
        base = f"{base_url}/{group}"
        extractor = lambda body: gitlab_repo_links(body, base_url, group)
    else:
        return [], {"pages": 0, "errors": [f"unsupported source type: {source_type}"], "candidate_count": 0}

    for page_no in range(1, max_pages + 1):
        pages += 1
        url = set_page(base, page_no)
        try:
            body = fetch_text(url, timeout)
        except Exception as exc:
            errors.append(f"{url}: {exc}")
            break
        links = extractor(body)
        before = len(found)
        found.update(links)
        if not links or len(found) == before:
            break

    return [
        Candidate(source=source, web_url=url.rstrip("/"))
        for url in sorted(found)
    ], {"pages": pages, "errors": errors, "candidate_count": len(found)}


def make_repository_record(candidate: Candidate, branch: str) -> dict:
    source = candidate.source
    parsed = urlparse(candidate.web_url)
    full_name = parsed.path.strip("/")
    family = family_from_registry(source)
    ecosystem = ecosystem_from_registry(source)
    repo_name = full_name.rsplit("/", 1)[-1]
    return {
        "provider": "github" if parsed.netloc.lower() == "github.com" else "gitlab",
        "source_id": str(source.get("id", "unknown")),
        "full_name": full_name,
        "branch": branch,
        "web_url": candidate.web_url,
        "clone_url": candidate.web_url + ".git",
        "ecosystem": ecosystem,
        "rom_family": family,
        "vendor": vendor_hint(source, repo_name),
        "device": device_hint(full_name),
        "android": "unknown",
        "repository_role": role_hint(full_name, family, ecosystem),
    }


def root_relative(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path.resolve())


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    sub = ap.add_subparsers(dest="command", required=True)
    p = sub.add_parser("discover")
    p.add_argument("--registry", default=str(DEFAULT_REGISTRY))
    p.add_argument("--output", default=str(DEFAULT_REPOSITORIES))
    p.add_argument("--snapshot", default=str(DEFAULT_SNAPSHOT))
    p.add_argument("--workers", type=int, default=max(2, min(8, os.cpu_count() or 2)))
    p.add_argument("--max-pages", type=int, default=50)
    p.add_argument("--timeout", type=int, default=30)
    p.add_argument("--probe-timeout", type=int, default=45)
    p.add_argument("--source", default="")
    args = ap.parse_args()

    if args.workers < 1 or args.workers > 32:
        ap.error("--workers must be 1..32")

    registry_path = Path(args.registry)
    registry = json.loads(registry_path.read_text(encoding="utf-8"))
    if registry.get("schema") != "hico.sources.v2":
        raise SystemExit(f"unsupported registry schema: {registry.get('schema')!r}")

    selected = [s for s in registry.get("sources", []) if not args.source or s.get("id") == args.source]
    if not selected:
        raise SystemExit("no registry sources selected")

    snapshot = {
        "schema": "hico.discovery.v1",
        "generated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        "mode": "public-html-plus-git-ls-remote",
        "sources": [],
        "repositories": [],
        "errors": [],
        "empty_repositories": [],
    }

    candidates: list[Candidate] = []
    for source in selected:
        found, meta = discover_source(source, args.max_pages, args.timeout)
        snapshot["sources"].append({
            "id": source.get("id", ""),
            "type": source.get("type", ""),
            "pages": meta["pages"],
            "candidate_count": meta["candidate_count"],
            "errors": meta["errors"],
        })
        for err in meta["errors"]:
            snapshot["errors"].append({"source": source.get("id", ""), "error": err})
        candidates.extend(found)

    unique: dict[str, Candidate] = {}
    for candidate in candidates:
        unique[candidate.web_url + ".git"] = candidate
    candidates = [unique[key] for key in sorted(unique)]

    def probe(candidate: Candidate):
        status, branch = probe_default_branch(
            candidate.web_url + ".git",
            args.probe_timeout,
        )
        return candidate, status, branch

    records = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.workers) as pool:
        futures = [pool.submit(probe, c) for c in candidates]
        for future in concurrent.futures.as_completed(futures):
            candidate, status, branch = future.result()

            if status == "empty":
                snapshot["empty_repositories"].append({
                    "source": candidate.source.get("id", ""),
                    "repository": candidate.web_url,
                    "reason": "valid Git remote without HEAD/ref",
                })
                continue

            if status != "ok" or not branch:
                snapshot["errors"].append({
                    "source": candidate.source.get("id", ""),
                    "repository": candidate.web_url,
                    "error": "git ls-remote failed",
                })
                continue

            records.append(make_repository_record(candidate, branch))

    records.sort(key=lambda x: (x["provider"], x["full_name"]))
    discovered_records = list(records)

    # Safe incremental discovery: preserve existing repositories and replace
    # only records with the same provider/full_name key.
    existing_index = Path(args.output)
    records = merge_repository_records(
        load_existing_index(existing_index),
        records,
    )

    payload = {
        "schema": "hico.repositories.v1",
        "description": "Concrete repositories discovered from public HTML listings and verified with git ls-remote.",
        "generated_from": root_relative(registry_path),
        "discovery_snapshot": root_relative(Path(args.snapshot)),
        "repository_count": len(records),
        "repositories": records,
    }

    Path(args.output).parent.mkdir(parents=True, exist_ok=True)
    Path(args.output).write_text(json.dumps(payload, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    # Keep discovery.json source-scoped. The merged collector index is stored separately.
    snapshot["repositories"] = discovered_records
    snapshot["empty_repositories"].sort(
        key=lambda x: x["repository"]
    )
    snapshot["errors"].sort(
        key=lambda x: x["repository"]
    )

    snapshot["summary"] = {
        "source_count": len(selected),
        "candidate_count": len(candidates),
        "repository_count": len(discovered_records),
        "merged_repository_count": len(records),
        "empty_repository_count": len(snapshot["empty_repositories"]),
        "error_count": len(snapshot["errors"]),
    }
    Path(args.snapshot).parent.mkdir(parents=True, exist_ok=True)
    Path(args.snapshot).write_text(json.dumps(snapshot, indent=2, sort_keys=True) + "\n", encoding="utf-8")

    print(json.dumps({
        "discovered_repositories": len(discovered_records),
        "merged_repositories": len(records),
        "empty_repositories": len(snapshot["empty_repositories"]),
        "errors": len(snapshot["errors"]),
        "output": str(args.output),
        "snapshot": str(args.snapshot),
    }, indent=2))
    return 1 if snapshot["errors"] and not records else 0


if __name__ == "__main__":
    raise SystemExit(main())
