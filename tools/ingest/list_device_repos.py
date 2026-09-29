#!/usr/bin/env python3
"""Enumerate device-tree / vendor-blob repositories for stock/sources.yaml.

Writes one JSON per source into stock/manifest/<source_id>.json listing each
repository: vendor, codename, kind (device | common), repo, clone_url,
default_branch, updated_at (upstream pushed_at when known). This is the
metadata layer: no repository content is downloaded.

Providers:
  github         GitHub REST API (orgs/<org>/repos, users/<org>/repos as a
                 fallback). Uses GH_TOKEN / GITHUB_TOKEN when set.
  repo-manifest  A repo-tool manifest file (e.g. TheMuppets/manifests
                 muppets.xml) read from raw.githubusercontent.com, one per
                 branch. No API needed.
  vendor-probe   Vendor blob repositories that ROM orgs keep next to their
                 device trees (device_<oem>_<codename> ->
                 vendor_<oem>_<codename> in the same org), for devices the
                 blob mirrors above do not cover. Reads the other sources'
                 manifests and asks each remote with `git ls-remote`, so it
                 must be listed after them. No API needed.

A source that cannot be listed keeps its committed manifest (reported, not
overwritten), so an API outage never empties the database.

    python3 tools/ingest/list_device_repos.py
    python3 tools/ingest/list_device_repos.py --only lineageos,themuppets
"""
from __future__ import annotations

import argparse
import concurrent.futures
import json
import os
import re
import sys
import time
import urllib.error
import urllib.parse
import urllib.request
import xml.etree.ElementTree as ET
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from common import MANIFEST_DIR, ROOT, SOURCES_YAML, load_sources, remote_default_branch, write_json  # noqa: E402

API = "https://api.github.com"
RAW = "https://raw.githubusercontent.com"

CODENAME_RE = re.compile(r"^[a-z0-9][a-z0-9_-]{0,63}$")

# Names that use the device prefix but are not device or SoC-common trees.
NON_DEVICE = frozenset({
    "sepolicy", "sepolicy_vndr", "sepolicy-legacy-um", "sepolicy-legacy",
    "generic", "opensource", "libs", "tools", "manifest", "hardware", "kernel",
})
# SoC / platform family names: shared trees even without a "-common" suffix
# (android_device_xiaomi_sm8250, android_device_google_gs101 ...).
PLATFORM_RE = re.compile(
    r"^(sm|sdm|msm|apq|mt|mtk|kirin|tegra|exynos|universal|gs|zuma|lahaina|kona|taro|"
    r"kalama|pineapple|sun|parrot|lito|atoll|trinket|bengal|holi|khaje|blair|crow|yupik)\d*[a-z]?$"
)


class ListingError(RuntimeError):
    pass


def _http_json(url: str, token: str | None) -> tuple[object, dict[str, str]]:
    req = urllib.request.Request(url, headers={
        "Accept": "application/vnd.github+json",
        "User-Agent": "hico-ingest",
        "X-GitHub-Api-Version": "2022-11-28",
    })
    if token:
        req.add_header("Authorization", f"Bearer {token}")
    for attempt in range(3):
        try:
            with urllib.request.urlopen(req, timeout=30) as resp:
                return json.loads(resp.read().decode()), dict(resp.headers)
        except urllib.error.HTTPError as exc:
            if exc.code in (502, 503, 504) and attempt < 2:
                time.sleep(2 * (attempt + 1))
                continue
            body = exc.read().decode(errors="replace")[:200]
            raise ListingError(f"HTTP {exc.code} {url}: {body}") from exc
        except (urllib.error.URLError, TimeoutError) as exc:
            if attempt < 2:
                time.sleep(2 * (attempt + 1))
                continue
            raise ListingError(f"{url}: {exc}") from exc
    raise ListingError(f"{url}: retries exhausted")


def _next_link(headers: dict[str, str]) -> str | None:
    link = headers.get("Link") or headers.get("link") or ""
    for part in link.split(","):
        m = re.match(r'\s*<([^>]+)>;\s*rel="next"', part)
        if m:
            return m.group(1)
    return None


def github_repos(org: str, token: str | None) -> list[dict]:
    """Every repository of an org (or user account), following Link pagination."""
    last_error: ListingError | None = None
    for kind in ("orgs", "users"):
        url: str | None = f"{API}/{kind}/{org}/repos?per_page=100&type=all"
        repos: list[dict] = []
        try:
            while url:
                page, headers = _http_json(url, token)
                if not isinstance(page, list):
                    raise ListingError(f"unexpected response for {url}")
                repos.extend(page)
                url = _next_link(headers)
            return repos
        except ListingError as exc:
            last_error = exc
            if "HTTP 404" not in str(exc):
                break  # 403 / network: the users/ endpoint will not do better
    raise last_error or ListingError(f"cannot list {org}")


def identity(repo_name: str, prefix: str) -> tuple[str, str, str] | None:
    """android_device_xiaomi_alioth -> ("xiaomi", "alioth", "device").

    Common trees keep their full name: android_device_xiaomi_sm8250-common ->
    ("xiaomi", "sm8250-common", "common"). They often hold the thermal HAL
    config or the thermal-engine file for a whole SoC family, so they are
    kept (not dropped) and marked kind=common.
    """
    if prefix and not repo_name.startswith(prefix):
        return None
    rest = repo_name[len(prefix):]
    vendor, sep, codename = rest.partition("_")
    if not sep or not vendor or not codename:
        return None
    vendor, codename = vendor.lower(), codename.lower()
    if vendor in NON_DEVICE or codename in NON_DEVICE:
        return None
    kind = "common" if ("common" in codename or PLATFORM_RE.match(codename)) else "device"
    return vendor, codename, kind


def list_github(src: dict, token: str | None) -> dict[str, dict]:
    prefix = src.get("repo_prefix", "")
    devices: dict[str, dict] = {}
    for repo in github_repos(src["org"], token):
        ident = identity(repo.get("name") or "", prefix)
        if ident is None:
            continue
        vendor, codename, kind = ident
        devices.setdefault(f"{vendor}/{codename}", {
            "vendor": vendor,
            "codename": codename,
            "kind": kind,
            "repo": repo["name"],
            "clone_url": repo.get("clone_url") or f"https://github.com/{src['org']}/{repo['name']}.git",
            "default_branch": repo.get("default_branch"),
            "updated_at": repo.get("pushed_at"),
            "archived": bool(repo.get("archived")),
            "fork": bool(repo.get("fork")),
        })
    return devices


def fetch_text(url: str) -> str | None:
    req = urllib.request.Request(url, headers={"User-Agent": "hico-ingest"})
    try:
        with urllib.request.urlopen(req, timeout=30) as resp:
            return resp.read().decode()
    except (urllib.error.URLError, TimeoutError):
        return None


def parse_repo_manifest(xml_text: str, org: str, prefix: str) -> dict[str, dict]:
    """Projects of one repo-tool manifest: {key: entry with `serves` codenames}."""
    out: dict[str, dict] = {}
    root = ET.fromstring(xml_text)
    for proj in root.iter("project"):
        name = proj.get("name") or ""
        repo = name.split("/", 1)[1] if name.startswith(f"{org}/") else name
        ident = identity(repo, prefix)
        if ident is None:
            continue
        vendor, codename, kind = ident
        groups = [g for g in (proj.get("groups") or "").split(",") if g.startswith("muppets_")]
        serves = sorted({g[len("muppets_"):].lower() for g in groups})
        out[f"{vendor}/{codename}"] = {
            "vendor": vendor,
            "codename": codename,
            "kind": kind,
            "repo": repo,
            "clone_url": f"https://github.com/{org}/{repo}.git",
            "serves": serves,
        }
    return out


def list_repo_manifest(src: dict) -> dict[str, dict]:
    branches = src.get("branches") or []
    if isinstance(branches, str):
        branches = [branches]
    devices: dict[str, dict] = {}
    read_any = False
    for branch in branches:  # newest first: the newest branch listing a repo wins
        text = fetch_text(f"{RAW}/{src['manifest_repo']}/{branch}/{src['manifest_file']}")
        if text is None:
            print(f"     ! {branch}: manifest not readable, skipped", flush=True)
            continue
        read_any = True
        for key, entry in parse_repo_manifest(text, src["org"], src.get("repo_prefix", "")).items():
            if key in devices:
                devices[key]["branches"].append(branch)
                continue
            devices[key] = {**entry, "default_branch": branch, "branches": [branch], "updated_at": None,
                            "archived": False, "fork": False}
    if not read_any:
        raise ListingError(f"no manifest readable for {src['manifest_repo']}")
    return devices


def vendor_repo_name(device_repo: str) -> str | None:
    """android_device_realme_RMX2001 -> android_vendor_realme_RMX2001 (None without a device_ part)."""
    head, sep, tail = device_repo.partition("device_")
    return f"{head}vendor_{tail}" if sep and tail else None


def list_vendor_probe(src: dict, manifest_dir: Path, probe=remote_default_branch, jobs: int = 8) -> dict[str, dict]:
    covered: set[tuple[str, str]] = set()
    for sid in src.get("skip_covered_by") or []:
        path = manifest_dir / f"{sid}.json"
        if not path.is_file():
            raise ListingError(f"{sid} manifest missing: cannot tell which devices it covers")
        for d in json.loads(path.read_text()).get("devices", []):
            covered.add((d["vendor"], d["codename"]))
            covered.update((d["vendor"], s) for s in d.get("serves") or [])

    # Candidates in from_sources order: the first org that has the vendor repo wins.
    candidates: dict[tuple[str, str], list[tuple[str, dict, str]]] = {}
    read_any = False
    for sid in src.get("from_sources") or []:
        path = manifest_dir / f"{sid}.json"
        if not path.is_file():
            continue
        read_any = True
        for d in json.loads(path.read_text()).get("devices", []):
            key = (d["vendor"], d["codename"])
            if key in covered:
                continue
            base, _, repo = d["clone_url"].rstrip("/").rpartition("/")
            name = vendor_repo_name(repo.removesuffix(".git"))
            if name:
                candidates.setdefault(key, []).append((sid, d, f"{base}/{name}.git"))
    if not read_any:
        raise ListingError("none of from_sources has a manifest yet")

    urls = sorted({url for cands in candidates.values() for _, _, url in cands})
    with concurrent.futures.ThreadPoolExecutor(max_workers=jobs) as pool:
        branch_of = dict(zip(urls, pool.map(probe, urls)))
    if urls and all(b is None for b in branch_of.values()):
        raise ListingError(f"no remote answered for {len(urls)} candidates (network?)")

    devices: dict[str, dict] = {}
    for (vendor, codename), cands in sorted(candidates.items()):
        for sid, dev, url in cands:
            branch = branch_of.get(url)
            if branch is None:
                continue
            devices[f"{vendor}/{codename}"] = {
                "vendor": vendor,
                "codename": codename,
                "kind": dev.get("kind", "device"),
                "repo": url.rsplit("/", 1)[1].removesuffix(".git"),
                "clone_url": url,
                "default_branch": branch or dev.get("default_branch"),
                "updated_at": None,
                "archived": False,
                "fork": False,
                "device_source": sid,
            }
            break
    return devices


def _gitlab_paginate(url: str, token: str | None) -> list[dict]:
    """Walk GitLab pagination (X-Next-Page header), return all items."""
    items: list[dict] = []
    while url:
        req = urllib.request.Request(url, headers={"User-Agent": "hico-ingest"})
        if token:
            req.add_header("PRIVATE-TOKEN", token)
        for attempt in range(3):
            try:
                with urllib.request.urlopen(req, timeout=30) as resp:
                    items.extend(json.loads(resp.read().decode()))
                    next_page = resp.headers.get("X-Next-Page") or ""
                    if next_page.isdigit():
                        base = url.split("?")[0]
                        url = f"{base}?per_page=100&page={next_page}"
                    else:
                        url = None
                break
            except urllib.error.HTTPError as exc:
                if exc.code in (502, 503, 504) and attempt < 2:
                    time.sleep(2 * (attempt + 1))
                    continue
                body = exc.read().decode(errors="replace")[:200]
                raise ListingError(f"HTTP {exc.code} {url}: {body}") from exc
            except (urllib.error.URLError, TimeoutError) as exc:
                if attempt < 2:
                    time.sleep(2 * (attempt + 1))
                    continue
                raise ListingError(f"{url}: {exc}") from exc
    return items


def list_gitlab(src: dict, token: str | None) -> dict[str, dict]:
    """List devices from a GitLab group dump repository (e.g. dumps.tadiphone.dev).

    Each project in the group IS a device dump; repo path == codename, group
    path == vendor. No android_device_ prefix needed.
    """
    base_url = (src.get("base_url") or "https://dumps.tadiphone.dev").rstrip("/")
    group = src["org"]  # e.g. "dumps/samsung"
    vendor = group.rsplit("/", 1)[-1].lower()
    encoded = urllib.parse.quote(group, safe="")
    url = f"{base_url}/api/v4/groups/{encoded}/projects?per_page=100&archived=false&include_subgroups=false"
    try:
        repos = _gitlab_paginate(url, token)
    except ListingError:
        raise
    devices: dict[str, dict] = {}
    for repo in repos:
        codename = (repo.get("path") or "").lower().strip()
        if not codename or not CODENAME_RE.match(codename):
            continue
        devices[f"{vendor}/{codename}"] = {
            "vendor": vendor,
            "codename": codename,
            "kind": "device",
            "repo": repo.get("path_with_namespace", repo.get("path")),
            "clone_url": repo.get("http_url_to_repo"),
            "default_branch": repo.get("default_branch"),
            "updated_at": repo.get("last_activity_at"),
            "archived": bool(repo.get("archived")),
            "fork": False,
        }
    return devices


def rom_device_set(manifest_dir: Path, sources: list[dict]) -> set[str]:
    """All '<vendor>/<codename>' keys that appear in ANY committed ROM-family manifest.

    Used to gate OEM dump ingestion: only devices that have custom ROM support
    are worth fetching from stock firmware mirrors.
    """
    keys: set[str] = set()
    for src in sources:
        if src.get("family") not in ("rom", "aosp"):
            continue
        path = manifest_dir / f"{src['id']}.json"
        if not path.is_file():
            continue
        for d in json.loads(path.read_text()).get("devices", []):
            keys.add(f"{d['vendor']}/{d['codename']}")
    return keys


def build_manifest(src: dict, devices: dict[str, dict]) -> dict:
    rows = sorted(devices.values(), key=lambda d: (d["vendor"], d["codename"]))
    return {
        "schema": "hico.ingest-manifest.v2",
        "source_id": src["id"],
        "source_name": src.get("name", src["id"]),
        "provider": src.get("provider"),
        "family": src.get("family"),
        "org": src.get("org"),
        "repo_prefix": src.get("repo_prefix", ""),
        "device_count": sum(1 for d in rows if d["kind"] == "device"),
        "common_count": sum(1 for d in rows if d["kind"] == "common"),
        "devices": rows,
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--sources", default=str(SOURCES_YAML))
    ap.add_argument("--only", default="", help="comma-separated source ids")
    ap.add_argument("--manifest-dir", default=str(MANIFEST_DIR))
    ap.add_argument("--jobs", type=int, default=8,
                     help="parallel git ls-remote probes for vendor-probe sources "
                          "(rom-vendor-blobs alone probes candidates from every ROM source "
                          "combined, easily 1000+ URLs; keep this low on constrained hosts)")
    args = ap.parse_args()

    manifest_dir = Path(args.manifest_dir)
    token = os.environ.get("GH_TOKEN") or os.environ.get("GITHUB_TOKEN")
    wanted = {s for s in args.only.split(",") if s}
    data = load_sources(Path(args.sources))
    sources = [s for s in data.get("sources") or []
               if s.get("provider") in ("github", "gitlab", "repo-manifest", "vendor-probe")
               and (not wanted or s["id"] in wanted)]

    # ROM device set is built once (lazily) for filter_requires_rom sources.
    _rom_keys: set[str] | None = None

    def get_rom_keys() -> set[str]:
        nonlocal _rom_keys
        if _rom_keys is None:
            _rom_keys = rom_device_set(manifest_dir, data.get("sources") or [])
            print(f"     rom-gate: {len(_rom_keys)} devices covered by ROM sources", flush=True)
        return _rom_keys

    failed: list[str] = []
    for src in sources:
        started = time.time()
        print(f"[{src['id']}] {src['provider']} {src.get('org')}", flush=True)
        try:
            if src["provider"] == "github":
                devices = list_github(src, token)
            elif src["provider"] == "gitlab":
                # dumps.tadiphone.dev is a public GitLab instance — no token needed.
                # TADIPHONE_TOKEN is optional; omit it to use anonymous access.
                gl_token = os.environ.get("TADIPHONE_TOKEN") or None
                devices = list_gitlab(src, gl_token)
            elif src["provider"] == "vendor-probe":
                devices = list_vendor_probe(src, manifest_dir, jobs=args.jobs)
            else:
                devices = list_repo_manifest(src)
        except ListingError as exc:
            failed.append(src["id"])
            print(f"     ✗ listing failed, committed manifest kept: {exc}", flush=True)
            continue

        if src.get("filter_requires_rom"):
            before = len(devices)
            rom_keys = get_rom_keys()
            devices = {k: v for k, v in devices.items() if k in rom_keys}
            dropped = before - len(devices)
            if dropped:
                print(f"     rom-gate: dropped {dropped} devices without custom ROM support", flush=True)

        manifest = build_manifest(src, devices)
        changed = write_json(manifest_dir / f"{src['id']}.json", manifest)
        print(f"     → {manifest['device_count']} devices + {manifest['common_count']} common trees"
              f" in {time.time() - started:.1f}s{'' if changed else ' (unchanged)'}", flush=True)

    # The index covers every committed manifest, listed or not in this run.
    summary = []
    for src in data.get("sources") or []:
        path = manifest_dir / f"{src['id']}.json"
        if not path.is_file():
            continue
        m = json.loads(path.read_text())
        summary.append({
            "source_id": src["id"],
            "source_name": src.get("name"),
            "family": src.get("family"),
            "device_count": m.get("device_count", 0),
            "common_count": m.get("common_count", 0),
            "manifest": str(path.relative_to(ROOT)) if path.is_relative_to(ROOT) else str(path),
        })
    write_json(manifest_dir / "index.json", {
        "schema": "hico.ingest-manifest-index.v2",
        "source_count": len(summary),
        "device_total": sum(s["device_count"] for s in summary),
        "common_total": sum(s["common_count"] for s in summary),
        "sources": summary,
    })
    print(f"---\n{sum(s['device_count'] for s in summary)} devices + "
          f"{sum(s['common_count'] for s in summary)} common trees across {len(summary)} sources"
          + (f"; listing failed for {', '.join(failed)}" if failed else ""))
    # Exit 0 when at least one source listed; the workflow reads failures from the log.
    return 1 if failed and len(failed) == len(sources) else 0


if __name__ == "__main__":
    sys.exit(main())
