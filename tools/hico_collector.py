#!/usr/bin/env python3
"""Local, token-free collector for public HiCo thermal sources.

The collector never uses the GitHub/GitLab APIs during normal sync. It works from
`sources/repositories.json`, clones/fetches the public Git remotes listed there,
extracts only thermal-relevant blobs, and stores them in the repository as a
canonical, provenance-preserving dataset under `thermal-data/`.
"""
from __future__ import annotations

import argparse
import concurrent.futures
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import threading
import time
from dataclasses import dataclass
from pathlib import Path
from urllib.parse import urlparse, unquote

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))

from hico_thermal.artifacts import analyze_file, relevant_path

MAX_RELEVANT_FILES = 4096
MAX_RAW_FILE = 90 * 1024 * 1024
DEFAULT_WORKERS = max(2, min(4, os.cpu_count() or 2))
LOG_LOCK = threading.Lock()
STATE_LOCK = threading.Lock()

ROLE_PATTERNS = (
    ("device", re.compile(r"(?:^|/)(?:android_)?device_[^/]+", re.I)),
    ("vendor", re.compile(r"(?:^|/)(?:android_)?vendor_[^/]+", re.I)),
    ("kernel", re.compile(r"(?:^|/)(?:android_)?kernel_[^/]+", re.I)),
    ("hardware", re.compile(r"(?:^|/)(?:android_)?hardware_[^/]+", re.I)),
)

ROM_KEYS = (
    ("ro.mi.os.version.name", "hyperos"),
    ("ro.miui.ui.version.name", "miui"),
    ("ro.lineage.version", "lineageos"),
    ("ro.evolution.version", "evolution-x"),
    ("ro.pixelos.version", "pixelos"),
    ("ro.crdroid.version", "crdroid"),
    ("ro.aospa.version", "aospa"),
)

OEM_ALIASES = {
    "xiaomi": "xiaomi",
    "redmi": "xiaomi",
    "poco": "xiaomi",
    "samsung": "samsung",
    "oneplus": "oneplus",
    "oppo": "oppo",
    "realme": "realme",
    "vivo": "vivo",
    "motorola": "motorola",
    "google": "google",
    "sony": "sony",
    "asus": "asus",
    "nothing": "nothing",
}


@dataclass(frozen=True)
class RepoSpec:
    provider: str
    source_id: str
    full_name: str
    branch: str
    web_url: str
    clone_url: str
    ecosystem: str
    family: str
    vendor: str = ""
    device: str = ""
    android: str = ""

    @property
    def key(self) -> str:
        return f"{self.provider}:{self.full_name}"


def log(message: str) -> None:
    with LOG_LOCK:
        print(message, flush=True)


def clean(value: str, fallback: str = "unknown", limit: int = 120) -> str:
    value = re.sub(r"[^A-Za-z0-9._-]+", "_", value.strip().lower())
    return (value[:limit] or fallback)


def run(cmd: list[str], *, cwd: Path | None = None, env: dict[str, str] | None = None,
        timeout: int = 900) -> subprocess.CompletedProcess:
    merged = os.environ.copy()
    merged.setdefault("GIT_TERMINAL_PROMPT", "0")
    merged.setdefault("GIT_CONFIG_NOSYSTEM", "1")
    if env:
        merged.update(env)
    return subprocess.run(cmd, cwd=cwd, env=merged, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                          text=False, check=False, timeout=timeout)


def git_text(cmd: list[str], *, cwd: Path | None = None, timeout: int = 900) -> str:
    proc = run(cmd, cwd=cwd, timeout=timeout)
    if proc.returncode:
        detail = proc.stderr.decode("utf-8", errors="replace").strip()
        raise RuntimeError(f"git failed ({proc.returncode}): {detail or 'unknown error'}")
    return proc.stdout.decode("utf-8", errors="replace")


def git_bytes(cmd: list[str], *, cwd: Path | None = None, timeout: int = 900) -> bytes:
    proc = run(cmd, cwd=cwd, timeout=timeout)
    if proc.returncode:
        detail = proc.stderr.decode("utf-8", errors="replace").strip()
        raise RuntimeError(f"git failed ({proc.returncode}): {detail or 'unknown error'}")
    return proc.stdout


def load_index(path: Path) -> list[RepoSpec]:
    data = json.loads(path.read_text(encoding="utf-8"))
    if data.get("schema") != "hico.repositories.v1":
        raise ValueError(f"unsupported repository index schema: {data.get('schema')!r}")
    repos: list[RepoSpec] = []
    for raw in data.get("repositories", []):
        repos.append(RepoSpec(
            provider=str(raw.get("provider", "")),
            source_id=str(raw.get("source_id", "")),
            full_name=str(raw.get("full_name", "")),
            branch=str(raw.get("branch", "")),
            web_url=str(raw.get("web_url", "")),
            clone_url=str(raw.get("clone_url", "")),
            ecosystem=str(raw.get("ecosystem", "")),
            family=str(raw.get("rom_family", raw.get("family", ""))),
            vendor=str(raw.get("vendor", "")),
            device=str(raw.get("device", "")),
            android=str(raw.get("android", "")),
        ))
    return [r for r in repos if r.provider and r.full_name and r.branch and r.clone_url]


def load_state(path: Path) -> dict:
    if not path.is_file():
        return {"schema": "hico.collector-state.v1", "repositories": {}}
    data = json.loads(path.read_text(encoding="utf-8"))
    if data.get("schema") != "hico.collector-state.v1":
        raise ValueError(f"unsupported collector state schema: {data.get('schema')!r}")
    return data


def save_json(path: Path, data: object) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(data, indent=2, sort_keys=True) + "\n", encoding="utf-8")


def source_hint(spec: RepoSpec) -> str:
    text = f"{spec.source_id} {spec.full_name} {spec.family} {spec.vendor}".lower()
    return text


def infer_vendor(spec: RepoSpec, props: dict[str, str]) -> str:
    # Registered OEM groups are the strongest source-level identity. This avoids
    # misclassifying Xiaomi dumps whose build.prop manufacturer is a subsidiary/OEM
    # string such as qti, alps or miphone.
    match = re.search(r"(?:^|tadiphone-)(xiaomi|redmi|poco|samsung|oneplus|oppo|realme|vivo|motorola|google|sony|asus|nothing)(?:$|[-/])", spec.source_id.lower())
    if match:
        return OEM_ALIASES[match.group(1)]
    for token, vendor in OEM_ALIASES.items():
        if re.search(rf"(?:^|[^a-z]){re.escape(token)}(?:$|[^a-z])", source_hint(spec)):
            return vendor
    for key in ("ro.product.manufacturer", "ro.product.brand", "ro.product.vendor.manufacturer", "ro.product.odm.manufacturer"):
        value = props.get(key, "").strip().lower()
        if value:
            return clean(OEM_ALIASES.get(value, value))
    return clean(spec.vendor, "unknown")


def infer_device(spec: RepoSpec, props: dict[str, str]) -> str:
    for key in (
        "ro.product.device",
        "ro.product.vendor.device",
        "ro.product.odm.device",
        "ro.product.system.device",
        "ro.boot.product.hardware.sku",
    ):
        value = props.get(key, "").strip()
        if value and not value.lower().startswith(("unknown", "generic")):
            return clean(value)
    name = spec.full_name.rstrip("/").split("/")[-1]
    name = re.sub(r"^android_(?:device|vendor|kernel|hardware)_", "", name, flags=re.I)
    name = re.sub(r"^(?:device|vendor|kernel)_", "", name, flags=re.I)
    return clean(spec.device or name)


def infer_android(spec: RepoSpec, props: dict[str, str]) -> str:
    value = props.get("ro.build.version.release", "").strip()
    return clean(value, "unknown") if value else clean(spec.android, "unknown")


def infer_rom(spec: RepoSpec, props: dict[str, str]) -> str:
    for key, family in ROM_KEYS:
        if props.get(key, "").strip():
            return family
    if spec.family and spec.family not in {"", "oem", "independent"}:
        return clean(spec.family)
    return "stock-oem"


def infer_ecosystem(spec: RepoSpec) -> str:
    return "oem" if spec.ecosystem == "oem" or spec.family == "oem" else "custom-rom"


def infer_role(spec: RepoSpec) -> str:
    for role, pattern in ROLE_PATTERNS:
        if pattern.search(spec.full_name):
            return role
    return "firmware" if infer_ecosystem(spec) == "oem" else "source"


def parse_props(files: dict[str, bytes]) -> dict[str, str]:
    props: dict[str, str] = {}
    for path, data in files.items():
        if Path(path).name.lower() not in {"build.prop", "vendor.prop", "odm.prop", "product.prop", "system.prop"}:
            continue
        text = data.decode("utf-8", errors="replace")
        for line in text.splitlines():
            line = line.strip()
            if not line or line.startswith("#") or "=" not in line:
                continue
            key, value = line.split("=", 1)
            key = key.strip()
            if key and key not in props:
                props[key] = value.strip()
    return props


def infer_dataset_relative(spec: RepoSpec, props: dict[str, str]) -> Path:
    ecosystem = infer_ecosystem(spec)
    vendor = infer_vendor(spec, props)
    rom = infer_rom(spec, props)
    device = infer_device(spec, props)
    android = infer_android(spec, props)
    role = infer_role(spec)
    repo = clean(spec.full_name.replace("/", "__"))
    return Path(ecosystem) / vendor / rom / device / android / role / repo


def repo_cache_path(cache_root: Path, spec: RepoSpec) -> Path:
    return cache_root / spec.provider / clean(spec.full_name.replace("/", "__"))


def clone_or_fetch(spec: RepoSpec, cache_root: Path) -> tuple[Path, str, bool]:
    destination = repo_cache_path(cache_root, spec)
    if not destination.exists():
        destination.parent.mkdir(parents=True, exist_ok=True)
        log(f"[collector] CLONE {spec.full_name} ({spec.branch})")
        proc = run([
            "git", "-c", "protocol.version=2", "clone", "--filter=blob:none", "--no-checkout",
            "--depth=1", "--single-branch", "--branch", spec.branch, spec.clone_url, str(destination)
        ])
        if proc.returncode:
            detail = proc.stderr.decode("utf-8", errors="replace").strip()
            raise RuntimeError(f"clone failed: {detail or proc.returncode}")
        commit = git_text(["git", "rev-parse", "HEAD"], cwd=destination).strip()
        return destination, commit

    # Keep the local mirror shallow. Fetch only the tracked branch and inspect FETCH_HEAD.
    log(f"[collector] FETCH {spec.full_name} ({spec.branch})")
    proc = run(["git", "fetch", "--depth=1", "origin", spec.branch], cwd=destination)
    if proc.returncode:
        detail = proc.stderr.decode("utf-8", errors="replace").strip()
        raise RuntimeError(f"fetch failed: {detail or proc.returncode}")
    fetched = git_text(["git", "rev-parse", "FETCH_HEAD"], cwd=destination).strip()
    return destination, fetched


def tree(repo_dir: Path, commit: str) -> list[str]:
    return [
        line for line in git_text(["git", "ls-tree", "-r", "--name-only", commit], cwd=repo_dir).splitlines()
        if line
    ]


def blob_size(repo_dir: Path, commit: str, path: str) -> int:
    value = git_text(["git", "cat-file", "-s", f"{commit}:{path}"], cwd=repo_dir).strip()
    return int(value)


def read_blob(repo_dir: Path, commit: str, path: str) -> bytes:
    return git_bytes(["git", "show", f"{commit}:{path}"], cwd=repo_dir, timeout=120)


def path_ref(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(ROOT.resolve())).replace("\\", "/")
    except ValueError:
        return str(path.resolve())


def write_manifest(base: Path, manifest: dict) -> None:
    save_json(base / "manifest.json", manifest)


def collect_one(spec: RepoSpec, cache_root: Path, data_root: Path, state: dict) -> dict:
    started = time.monotonic()
    repo_dir, commit = clone_or_fetch(spec, cache_root)
    previous = state.get("repositories", {}).get(spec.key, {})
    if previous.get("commit") == commit:
        return {
            "repository": spec.full_name,
            "status": "unchanged",
            "commit": commit,
            "elapsed_s": round(time.monotonic() - started, 2),
        }

    paths = [p for p in tree(repo_dir, commit) if relevant_path(p)]
    if len(paths) > MAX_RELEVANT_FILES:
        raise RuntimeError(f"{len(paths)} relevant files exceed MAX_RELEVANT_FILES={MAX_RELEVANT_FILES}")

    # Read only identity files first. The rest of the relevant blobs are fetched afterwards.
    identity_files: dict[str, bytes] = {}
    for path in paths:
        if Path(path).name.lower() in {"build.prop", "vendor.prop", "odm.prop", "product.prop", "system.prop"}:
            try:
                if blob_size(repo_dir, commit, path) <= MAX_RAW_FILE:
                    identity_files[path] = read_blob(repo_dir, commit, path)
            except Exception:
                continue
    props = parse_props(identity_files)
    dataset_root = data_root / infer_dataset_relative(spec, props)
    raw_root = dataset_root / "raw"
    previous_dataset = previous.get("dataset")
    if previous_dataset:
        old_root = Path(previous_dataset)
        if not old_root.is_absolute():
            old_root = ROOT / old_root
        if old_root.resolve() != dataset_root.resolve() and old_root.exists():
            shutil.rmtree(old_root)
    if dataset_root.exists():
        shutil.rmtree(dataset_root)
    raw_root.mkdir(parents=True, exist_ok=True)

    files = []
    stored = 0
    metadata_only = 0
    for path in paths:
        size = blob_size(repo_dir, commit, path)
        entry = {
            "path": path,
            "source_commit": commit,
            "size": size,
        }
        if size > MAX_RAW_FILE:
            entry.update({"storage": "metadata-only", "status": "file-too-large"})
            metadata_only += 1
            files.append(entry)
            continue
        data = read_blob(repo_dir, commit, path)
        destination = raw_root / Path(path)
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_bytes(data)
        info = analyze_file(destination, data)
        info["path"] = path
        info.update({
            "source_id": spec.source_id,
            "provider": spec.provider,
            "repository": spec.full_name,
            "branch": spec.branch,
            "source_url": spec.web_url,
            "source_commit": commit,
            "tree_path": path,
            "storage": "raw",
            "raw_path": path_ref(destination),
        })
        files.append(info)
        stored += 1

    manifest = {
        "schema": "hico.thermal-source.v1",
        "source": {
            "id": spec.source_id,
            "provider": spec.provider,
            "repository": spec.full_name,
            "branch": spec.branch,
            "commit": commit,
            "url": spec.web_url,
        },
        "identity": {
            "ecosystem": infer_ecosystem(spec),
            "vendor": infer_vendor(spec, props),
            "rom_family": infer_rom(spec, props),
            "device": infer_device(spec, props),
            "android": infer_android(spec, props),
            "repository_role": infer_role(spec),
            "properties": {k: props[k] for k in sorted(props) if k in {
                "ro.product.manufacturer", "ro.product.brand", "ro.product.device",
                "ro.product.vendor.device", "ro.product.odm.device", "ro.build.version.release",
                "ro.mi.os.version.name", "ro.miui.ui.version.name", "ro.lineage.version",
                "ro.evolution.version", "ro.pixelos.version", "ro.crdroid.version", "ro.aospa.version",
                "ro.board.platform", "ro.hardware",
            }},
            "platform": props.get("ro.board.platform", ""),
        },
        "repository": {
            "tree_complete": True,
            "relevant_file_count": len(paths),
            "stored_file_count": stored,
            "metadata_only_count": metadata_only,
        },
        "files": sorted(files, key=lambda item: item.get("tree_path", item.get("path", ""))),
    }
    write_manifest(dataset_root, manifest)

    with STATE_LOCK:
        state.setdefault("repositories", {})[spec.key] = {
            "commit": commit,
            "dataset": path_ref(dataset_root),
            "updated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        }
    return {
        "repository": spec.full_name,
        "status": "updated",
        "commit": commit,
        "files": stored,
        "metadata_only": metadata_only,
        "dataset": path_ref(dataset_root),
        "elapsed_s": round(time.monotonic() - started, 2),
    }


def verify_dataset(data_root: Path, state_path: Path | None = None) -> dict:
    errors: list[str] = []
    manifests = sorted(data_root.rglob("manifest.json")) if data_root.is_dir() else []
    for manifest_path in manifests:
        try:
            manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            errors.append(f"{manifest_path}: invalid JSON: {exc}")
            continue
        if manifest.get("schema") != "hico.thermal-source.v1":
            errors.append(f"{manifest_path}: unsupported manifest schema")
            continue
        for item in manifest.get("files", []):
            rel = item.get("raw_path")
            if item.get("storage") == "raw":
                if not rel:
                    errors.append(f"{manifest_path}: raw file without raw_path: {item.get('tree_path')}")
                    continue
                target = ROOT / rel
                if not target.is_file():
                    errors.append(f"{manifest_path}: missing raw file: {rel}")
                    continue
                info = analyze_file(target)
                if info.get("sha256") != item.get("sha256"):
                    errors.append(f"{manifest_path}: checksum mismatch: {rel}")
        source = manifest.get("source", {})
        for required in ("repository", "branch", "commit"):
            if not source.get(required):
                errors.append(f"{manifest_path}: source.{required} missing")
        identity = manifest.get("identity", {})
        for required in ("ecosystem", "vendor", "rom_family", "device", "android", "repository_role"):
            if not identity.get(required):
                errors.append(f"{manifest_path}: identity.{required} missing")
    result = {
        "schema": "hico.collector-verification.v1",
        "manifest_count": len(manifests),
        "errors": errors,
    }
    if state_path and state_path.is_file():
        try:
            state = load_state(state_path)
            result["state_count"] = len(state.get("repositories", {}))
        except Exception as exc:
            errors.append(f"{state_path}: {exc}")
    return result


def bootstrap_from_database(database_index: Path, output: Path) -> dict:
    data = json.loads(database_index.read_text(encoding="utf-8"))
    repositories: dict[str, dict] = {}
    for device in data.get("devices", []):
        source = str(device.get("source", ""))
        parsed = urlparse(source)
        path = unquote(parsed.path).strip("/")
        match = re.match(r"dumps/([^/]+)/([^/]+)/-/tree/(.+)$", path)
        if not match:
            continue
        group, repo_name, branch = match.groups()
        base_path = f"https://{parsed.netloc}/dumps/{group}/{repo_name}.git"
        source_id = f"tadiphone-{group}"
        key = f"gitlab:dumps/{group}/{repo_name}"
        repositories[key] = {
            "provider": "gitlab",
            "source_id": source_id,
            "full_name": f"dumps/{group}/{repo_name}",
            "branch": branch,
            "web_url": source,
            "clone_url": base_path,
            "ecosystem": "oem",
            "rom_family": "stock-oem",
            "vendor": "xiaomi" if group in {"xiaomi", "redmi", "poco"} else group,
            "device": str(device.get("codename", repo_name)),
            "android": str(device.get("android", "unknown")),
        }
    payload = {
        "schema": "hico.repositories.v1",
        "description": "Known public repositories that the local collector can fetch without GitHub/GitLab API access.",
        "generated_from": path_ref(database_index),
        "repository_count": len(repositories),
        "repositories": [repositories[key] for key in sorted(repositories)],
    }
    save_json(output, payload)
    return payload


def sync(args: argparse.Namespace) -> int:
    repos = load_index(Path(args.repo_index))
    if args.limit:
        repos = repos[: args.limit]
    state_path = Path(args.state)
    state = load_state(state_path)
    selected = []
    for repo in repos:
        if args.source and repo.source_id != args.source:
            continue
        if args.ecosystem and infer_ecosystem(repo) != args.ecosystem:
            continue
        if args.family and clean(repo.family) != clean(args.family):
            continue
        selected.append(repo)
    log(f"[collector] repositories={len(selected)} workers={args.workers} changed_only={args.changed_only}")
    cache_root = Path(args.cache).expanduser()
    cache_root.mkdir(parents=True, exist_ok=True)
    results: list[dict] = []
    data_root = Path(args.data)
    data_root.mkdir(parents=True, exist_ok=True)
    with concurrent.futures.ThreadPoolExecutor(max_workers=args.workers) as pool:
        futures = {pool.submit(collect_one, repo, cache_root, data_root, state): repo for repo in selected}
        for future in concurrent.futures.as_completed(futures):
            repo = futures[future]
            try:
                result = future.result()
                results.append(result)
                log(f"[collector] {result['status'].upper()} {repo.full_name} files={result.get('files', 0)} elapsed={result['elapsed_s']}s")
            except Exception as exc:
                results.append({"repository": repo.full_name, "status": "error", "error": str(exc)})
                log(f"[collector] ERROR {repo.full_name}: {exc}")
    if args.changed_only:
        # A changed-only run only affects repositories whose upstream commit moved; unchanged entries
        # are harmless and remain available as deterministic local state.
        results = results
    save_json(state_path, state)
    summary = {
        "schema": "hico.collector-run.v1",
        "repository_count": len(selected),
        "updated": sum(1 for x in results if x["status"] == "updated"),
        "unchanged": sum(1 for x in results if x["status"] == "unchanged"),
        "errors": [x for x in results if x["status"] == "error"],
        "results": sorted(results, key=lambda x: x.get("repository", "")),
    }
    save_json(Path(args.report), summary)
    return 1 if summary["errors"] else 0




def import_legacy_devices(devices_root: Path, data_root: Path, state_path: Path) -> dict:
    """Promote the existing Xiaomi repository thermal files into the canonical dataset."""
    from hico_thermal.artifacts import sha256_file

    state = load_state(state_path)
    imported = 0
    files = 0
    failures = []
    for prop in sorted(devices_root.glob("*.prop")):
        values: dict[str, str] = {}
        try:
            for line in prop.read_text(encoding="utf-8", errors="replace").splitlines():
                if line and not line.startswith("#") and "=" in line:
                    key, value = line.split("=", 1)
                    values[key.strip()] = value.strip()
        except OSError as exc:
            failures.append({"device": prop.stem, "error": str(exc)})
            continue
        source = values.get("source", "")
        branch = source.rsplit("/-/tree/", 1)[-1] if "/-/tree/" in source else "unknown"
        rom = "hyperos" if re.search(r"(?:^|-)OS\d", branch, re.I) else "stock-oem"
        device = clean(values.get("codename", prop.stem))
        android = clean(values.get("android", "unknown"))
        source_group = "xiaomi"
        if "/redmi/" in source:
            source_group = "redmi"
        elif "/poco/" in source:
            source_group = "poco"
        vendor = "xiaomi" if source_group in {"xiaomi", "redmi", "poco"} else clean(source_group)
        dataset_root = data_root / "oem" / vendor / rom / device / android / "firmware" / clean(f"tadiphone-{source_group}-{device}")
        thermal_dir = prop.parent / device / "thermal"
        if not thermal_dir.is_dir():
            continue
        raw_root = dataset_root / "raw"
        raw_root.mkdir(parents=True, exist_ok=True)
        manifest_files = []
        for source_file in sorted(thermal_dir.rglob("*")):
            if not source_file.is_file() or source_file.name == "index.tsv":
                continue
            rel = source_file.relative_to(thermal_dir)
            destination = raw_root / rel
            destination.parent.mkdir(parents=True, exist_ok=True)
            destination.write_bytes(source_file.read_bytes())
            info = analyze_file(destination)
            info["path"] = rel.as_posix()
            info.update({
                "provider": "gitlab",
                "source_id": f"tadiphone-{source_group}",
                "repository": f"dumps/{source_group}/{device}",
                "branch": branch,
                "source_url": source,
                "source_commit": "legacy-import",
                "tree_path": rel.as_posix(),
                "storage": "raw",
                "raw_path": path_ref(destination),
                "legacy_import": True,
            })
            manifest_files.append(info)
            files += 1
        if not manifest_files:
            continue
        manifest = {
            "schema": "hico.thermal-source.v1",
            "source": {
                "id": f"tadiphone-{source_group}",
                "provider": "gitlab",
                "repository": f"dumps/{source_group}/{device}",
                "branch": branch,
                "commit": "legacy-import",
                "url": source,
            },
            "identity": {
                "ecosystem": "oem",
                "vendor": vendor,
                "rom_family": rom,
                "device": device,
                "android": android,
                "repository_role": "firmware",
                "platform": values.get("platform", ""),
                "properties": {},
            },
            "repository": {
                "tree_complete": False,
                "relevant_file_count": len(manifest_files),
                "stored_file_count": len(manifest_files),
                "metadata_only_count": 0,
                "legacy_import": True,
            },
            "files": manifest_files,
        }
        write_manifest(dataset_root, manifest)
        state.setdefault("repositories", {})[f"gitlab:dumps/{source_group}/{device}"] = {
            "commit": "legacy-import",
            "dataset": path_ref(dataset_root),
            "updated_at": time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime()),
        }
        imported += 1
    save_json(state_path, state)
    return {"repositories": imported, "files": files, "failures": failures}

def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    sub = parser.add_subparsers(dest="command", required=True)

    p = sub.add_parser("bootstrap", help="build a token-free repository index from the existing Xiaomi database")
    p.add_argument("--database-index", default=str(ROOT / "database" / "index.json"))
    p.add_argument("--output", default=str(ROOT / "sources" / "repositories.json"))

    p = sub.add_parser("import-legacy", help="migrate existing devices/*/thermal data into the canonical thermal-data tree")
    p.add_argument("--devices", default=str(ROOT / "devices" / "xiaomi"))
    p.add_argument("--data", default=str(ROOT / "thermal-data"))
    p.add_argument("--state", default=str(ROOT / "sources" / "collector-state.json"))

    p = sub.add_parser("sync", help="fetch known public repositories and collect thermal-relevant files")
    p.add_argument("--repo-index", default=str(ROOT / "sources" / "repositories.json"))
    p.add_argument("--cache", default=str(Path.home() / ".cache" / "hico" / "repos"))
    p.add_argument("--data", default=str(ROOT / "thermal-data"))
    p.add_argument("--state", default=str(ROOT / "sources" / "collector-state.json"))
    p.add_argument("--report", default=str(ROOT / "sources" / "collector-last-run.json"))
    p.add_argument("--workers", type=int, default=DEFAULT_WORKERS)
    p.add_argument("--limit", type=int, default=0)
    p.add_argument("--source", default="")
    p.add_argument("--ecosystem", default="")
    p.add_argument("--family", default="")
    p.add_argument("--changed-only", action="store_true")

    p = sub.add_parser("verify", help="verify manifests, raw files and checksums")
    p.add_argument("--data", default=str(ROOT / "thermal-data"))
    p.add_argument("--state", default=str(ROOT / "sources" / "collector-state.json"))

    args = parser.parse_args()
    if args.command == "bootstrap":
        result = bootstrap_from_database(Path(args.database_index), Path(args.output))
        print(json.dumps({"repositories": result["repository_count"], "output": args.output}, indent=2))
        return 0
    if args.command == "import-legacy":
        result = import_legacy_devices(Path(args.devices), Path(args.data), Path(args.state))
        print(json.dumps(result, indent=2, sort_keys=True))
        return 1 if result["failures"] else 0
    if args.command == "sync":
        if args.workers < 1 or args.workers > 16:
            parser.error("--workers must be between 1 and 16")
        return sync(args)
    if args.command == "verify":
        result = verify_dataset(Path(args.data), Path(args.state))
        print(json.dumps(result, indent=2, sort_keys=True))
        return 1 if result["errors"] else 0
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
