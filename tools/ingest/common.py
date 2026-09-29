"""Shared helpers for tools/ingest/*.

Kept dependency-free (stdlib only) so the same code runs on a developer
machine, in a sandbox without the GitHub CLI, and on a GitHub runner where
PyYAML may be missing.
"""
from __future__ import annotations

import json
import os
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
STOCK = ROOT / "stock"
MANIFEST_DIR = STOCK / "manifest"
SOURCES_YAML = STOCK / "sources.yaml"

# Where each source family lands inside stock/. Vendor blob mirrors are kept
# apart from ROM device trees: they are extracted stock firmware, not ROM code.
FAMILY_DIRS = {"rom": "rom", "aosp": "rom", "blobs": "blobs", "oem": "oem", "kernel": "kernel"}


def load_sources(path: Path = SOURCES_YAML) -> dict:
    sys.path.insert(0, str(ROOT / "tools" / "verify"))
    from rom_sources import _load_sources  # type: ignore

    return _load_sources(path)


def source_map(data: dict) -> dict[str, dict]:
    return {s["id"]: s for s in (data.get("sources") or []) if s.get("id")}


def dest_root(source: dict, stock: Path = STOCK) -> Path:
    return stock / FAMILY_DIRS.get(source.get("family", "rom"), "rom") / source["id"]


def paths_for(source: dict, data: dict) -> list[str]:
    """Sparse-checkout paths: vendor blob mirrors have their own layout."""
    if source.get("family") == "blobs":
        return list(data.get("blob_paths") or [])
    return list(data.get("thermal_paths") or [])


def device_key(dev: dict) -> str:
    return f"{dev['vendor']}/{dev['codename']}"


def device_dir_name(dev: dict) -> str:
    return f"{dev['vendor']}__{dev['codename']}"


def git_env() -> dict[str, str]:
    # Never prompt for credentials: a missing public repo must fail fast, not hang.
    return {**os.environ, "GIT_TERMINAL_PROMPT": "0", "GIT_ASKPASS": "true"}


def run(cmd: list[str], cwd: Path | None = None, timeout: int = 120) -> tuple[int, str]:
    """Run a command; a timeout is a failure (exit 124), never an exception."""
    try:
        p = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True, timeout=timeout, env=git_env())
    except subprocess.TimeoutExpired:
        return 124, f"timeout after {timeout}s: {' '.join(cmd[:3])}"
    except OSError as exc:
        return 127, str(exc)
    return p.returncode, (p.stdout if p.returncode == 0 else (p.stderr or p.stdout)).strip()


def ls_remote_sha(url: str, branch: str | None, timeout: int = 30) -> str | None:
    """Commit SHA of `branch` (default HEAD) on `url`, without cloning anything."""
    ref = f"refs/heads/{branch}" if branch else "HEAD"
    rc, out = run(["git", "ls-remote", url, ref], timeout=timeout)
    if rc != 0 or not out:
        return None
    first = out.splitlines()[0].split()
    return first[0] if first and len(first[0]) == 40 else None


def remote_heads(url: str, timeout: int = 30) -> dict[str, str] | None:
    """Every branch head of `url` in one request: {branch: sha}. None if unreachable."""
    rc, out = run(["git", "ls-remote", "--heads", url], timeout=timeout)
    if rc != 0:
        return None
    heads: dict[str, str] = {}
    for line in out.splitlines():
        sha, _, ref = line.partition("\t")
        if ref.startswith("refs/heads/") and len(sha) == 40:
            heads[ref[len("refs/heads/"):]] = sha
    return heads


def remote_default_branch(url: str, timeout: int = 30) -> str | None:
    """Default branch of a remote repository ("" when HEAD is detached), None when unreachable / missing."""
    rc, out = run(["git", "ls-remote", "--symref", url, "HEAD"], timeout=timeout)
    if rc != 0 or not out:
        return None
    for line in out.splitlines():
        if line.startswith("ref: refs/heads/") and line.endswith("\tHEAD"):
            return line[len("ref: refs/heads/"):-len("\tHEAD")]
    return ""


def candidate_branches(dev: dict) -> list[str]:
    """Branches to try, preferred first. Repo-tool manifests list a repository on
    a new branch before the repository itself has that branch."""
    branches = [b for b in (dev.get("branches") or []) if b]
    if dev.get("default_branch") and dev["default_branch"] not in branches:
        branches.insert(0, dev["default_branch"])
    return branches


def resolve_branch(dev: dict, heads: dict[str, str]) -> tuple[str | None, str | None]:
    """(branch, sha) to fetch: the first candidate that exists, else the remote default."""
    for b in candidate_branches(dev):
        if b in heads:
            return b, heads[b]
    if not candidate_branches(dev) and len(heads) == 1:
        (b, sha), = heads.items()
        return b, sha
    return None, None


# ---------------------------------------------------------------------------
# Multi-branch helpers (multi_branch: oldest_and_newest in sources.yaml)
# ---------------------------------------------------------------------------

_LINEAGE_VER_RE = re.compile(r"lineage[_-](\d+)\.\d+")
_NUMERIC_VER_RE = re.compile(r"^(\d{2})\.\d")
_NAMED_ANDROID: dict[str, int] = {
    "udc": 14, "vic": 15, "bic": 16,
    "topaz": 14, "uvite": 15,
    "fifteen": 15, "fourteen": 14, "thirteen": 13,
    "arrow-13": 13, "arrow-14": 14, "arrow-15": 15,
}
_MIN_ANDROID = 10  # never fetch branches older than Android 10


def android_ver_from_branch(branch: str) -> int | None:
    """Return the Android version encoded in a ROM branch name, or None if unknown.

    lineage-17.1 → 10, lineage-21.0 → 14, 15.0 → 15, udc → 14, etc.
    """
    m = _LINEAGE_VER_RE.match(branch)
    if m:
        n = int(m.group(1))
        return (n - 7) if n >= 17 else None  # lineage-17 == Android 10
    m = _NUMERIC_VER_RE.match(branch)
    if m:
        return int(m.group(1))
    return _NAMED_ANDROID.get(branch.split("-")[0].lower())


def qualifying_branches(heads: dict[str, str]) -> list[tuple[str, str, int]]:
    """(branch, sha, android_ver) sorted oldest→newest, Android >= _MIN_ANDROID only."""
    result = []
    for branch, sha in heads.items():
        ver = android_ver_from_branch(branch)
        if ver is not None and ver >= _MIN_ANDROID:
            result.append((branch, sha, ver))
    return sorted(result, key=lambda t: t[2])


def oldest_and_newest(heads: dict[str, str]) -> list[tuple[str, str]]:
    """Return [(branch, sha)] for oldest AND newest qualifying branches (deduplicated)."""
    qs = qualifying_branches(heads)
    if not qs:
        return []
    oldest = qs[0]
    newest = qs[-1]
    if oldest[0] == newest[0]:
        return [(oldest[0], oldest[1])]
    return [(oldest[0], oldest[1]), (newest[0], newest[1])]


def branch_dir_suffix(branch: str) -> str:
    """Filesystem-safe suffix from a branch name: lineage-17.1 → __lineage-17.1."""
    return "__" + re.sub(r"[^A-Za-z0-9._-]", "_", branch)


# ---------------------------------------------------------------------------
# Per-source fetch state: stock/manifest/<source_id>.state.json
#
# One entry per device key, whatever the outcome (ok / empty / failed), so a
# device that ships no thermal files is not re-cloned on every run and the
# delta check never has to walk thousands of sidecar files.
# ---------------------------------------------------------------------------

def state_path(source_id: str, manifest_dir: Path = MANIFEST_DIR) -> Path:
    return manifest_dir / f"{source_id}.state.json"


def load_state(source_id: str, manifest_dir: Path = MANIFEST_DIR) -> dict[str, dict]:
    path = state_path(source_id, manifest_dir)
    if not path.is_file():
        return {}
    try:
        return json.loads(path.read_text()).get("devices", {})
    except (OSError, ValueError):
        return {}


def save_state(source_id: str, devices: dict[str, dict], manifest_dir: Path = MANIFEST_DIR) -> None:
    manifest_dir.mkdir(parents=True, exist_ok=True)
    state_path(source_id, manifest_dir).write_text(json.dumps({
        "schema": "hico.ingest-state.v1",
        "source_id": source_id,
        "devices": {k: devices[k] for k in sorted(devices)},
    }, indent=2, sort_keys=True) + "\n")


def write_json(path: Path, data: object) -> bool:
    """Write only when the content changes: unchanged runs leave git clean."""
    text = json.dumps(data, indent=2, sort_keys=True) + "\n"
    if path.is_file() and path.read_text() == text:
        return False
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text)
    return True
