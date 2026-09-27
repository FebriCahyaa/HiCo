#!/usr/bin/env python3
"""Enumerate device-tree repositories for every entry in stock/sources.yaml.

Uses the GitHub API (via `gh api`) for github providers. Writes one JSON
per source into stock/manifest/<source_id>.json listing each repo's
{name, default_branch, updated_at, size_kb, sha}. This is the metadata
layer — no repo content is downloaded.

    python3 tools/ingest/list_device_repos.py
    python3 tools/ingest/list_device_repos.py --only lineageos,pixelos
"""
from __future__ import annotations

import argparse
import json
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MANIFEST_DIR = ROOT / "stock" / "manifest"


def _load_sources(path: Path) -> list[dict]:
    sys.path.insert(0, str(ROOT / "tools" / "verify"))
    from rom_sources import _load_sources  # type: ignore
    data = _load_sources(path)
    return [s for s in (data.get("sources") or []) if s.get("provider") == "github"]


def _gh_paginated(endpoint: str, per_page: int = 100) -> list[dict]:
    """Fetch every page of a github API listing via `gh api --paginate`."""
    cmd = ["gh", "api", "--paginate", f"{endpoint}?per_page={per_page}"]
    proc = subprocess.run(cmd, capture_output=True, text=True, check=False)
    if proc.returncode != 0:
        raise RuntimeError(f"gh api failed: {proc.stderr.strip()}")
    # gh --paginate concatenates JSON arrays as one stream; split them.
    out = proc.stdout.strip()
    if not out:
        return []
    # Simple approach: replace "][" between arrays with "," to make one list
    combined = out.replace("]\n[", ",").replace("][", ",")
    return json.loads(combined)


# SoC/vendor "common" packages that use the device_ / android_device_
# prefix but are NOT per-device trees. Filtered out during enumeration.
COMMON_TOKENS = frozenset({
    "sepolicy", "sepolicy_vndr", "sepolicy-legacy-um", "sepolicy-legacy",
    "common", "qcom-common", "qcom_common", "mtk-common", "mtk_common",
    "exynos-common", "exynos_common", "kirin-common", "kirin_common",
    "tegra-common", "tegra_common", "unisoc-common", "unisoc_common",
    "generic", "opensource", "libs", "tools",
    "manifest", "hardware", "kernel",
})


def _matches(repo_name: str, prefix: str) -> bool:
    if not prefix:
        return True
    return repo_name.startswith(prefix)


def _is_real_device(vendor: str, codename: str) -> bool:
    if vendor in COMMON_TOKENS or codename in COMMON_TOKENS:
        return False
    if "common" in codename:
        return False
    if codename.startswith(("sm", "msm", "sdm", "mt", "mtk", "kirin", "tegra")) and codename.replace("-", "").isalnum() and any(c.isdigit() for c in codename) and len(codename) < 10:
        # e.g. sm8350, msm8996 — SoC-common, not device
        return False
    return True


def _extract_identity(repo_name: str, prefix: str) -> tuple[str, str] | None:
    """From e.g. android_device_xiaomi_alioth → ("xiaomi", "alioth")."""
    if not repo_name.startswith(prefix):
        return None
    rest = repo_name[len(prefix):]
    parts = rest.split("_", 1)
    if len(parts) != 2:
        # e.g. "aosp_redfin" or plain "redfin"
        if "_" in rest:
            return None
        return ("unknown", rest)
    vendor, codename = parts
    codename = codename.replace("-common", "")
    return (vendor.lower(), codename.lower())


def list_source(src: dict) -> dict:
    sid = src["id"]
    org = src["org"]
    prefix = src.get("repo_prefix", "")
    print(f"  ↳ listing {org} (prefix={prefix or '*'}) ...", flush=True)
    started = time.time()
    repos = _gh_paginated(f"orgs/{org}/repos")

    devices: dict[str, dict] = {}
    other: list[str] = []
    for repo in repos:
        name = repo.get("name") or ""
        if not _matches(name, prefix):
            other.append(name)
            continue
        ident = _extract_identity(name, prefix) if prefix else None
        if ident is None:
            other.append(name)
            continue
        vendor, codename = ident
        if not _is_real_device(vendor, codename):
            other.append(name)
            continue
        key = f"{vendor}/{codename}"
        # Prefer the -common repo's sibling when both exist; keep both by key.
        devices.setdefault(key, {
            "vendor": vendor,
            "codename": codename,
            "repo": name,
            "clone_url": repo.get("clone_url"),
            "default_branch": repo.get("default_branch"),
            "updated_at": repo.get("pushed_at"),
            "size_kb": repo.get("size", 0),
            "archived": repo.get("archived", False),
            "fork": repo.get("fork", False),
        })

    elapsed = time.time() - started
    print(f"     → {len(devices)} devices, {len(other)} non-device repos, {elapsed:.1f}s",
          flush=True)

    return {
        "schema": "hico.ingest-manifest.v1",
        "source_id": sid,
        "source_name": src.get("name", sid),
        "provider": src.get("provider"),
        "org": org,
        "repo_prefix": prefix,
        "device_count": len(devices),
        "devices": sorted(devices.values(), key=lambda d: (d["vendor"], d["codename"])),
    }


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--sources", default=str(ROOT / "stock" / "sources.yaml"))
    ap.add_argument("--only", default=None, help="comma-separated source ids")
    args = ap.parse_args()

    only = set(args.only.split(",")) if args.only else None
    sources = _load_sources(Path(args.sources))
    if only:
        sources = [s for s in sources if s.get("id") in only]

    MANIFEST_DIR.mkdir(parents=True, exist_ok=True)
    summary: list[dict] = []
    for src in sources:
        print(f"[{src['id']}]", flush=True)
        manifest = list_source(src)
        out = MANIFEST_DIR / f"{src['id']}.json"
        out.write_text(json.dumps(manifest, indent=2, sort_keys=True) + "\n")
        summary.append({
            "source_id": src["id"],
            "source_name": src.get("name"),
            "device_count": manifest["device_count"],
            "manifest": str(out.relative_to(ROOT)),
        })

    index = MANIFEST_DIR / "index.json"
    index.write_text(json.dumps({
        "schema": "hico.ingest-manifest-index.v1",
        "generated_at_epoch": int(time.time()),
        "source_count": len(summary),
        "device_total": sum(s["device_count"] for s in summary),
        "sources": summary,
    }, indent=2, sort_keys=True) + "\n")
    print(f"---\nindex → {index.relative_to(ROOT)}  ({sum(s['device_count'] for s in summary)} devices across {len(summary)} sources)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
