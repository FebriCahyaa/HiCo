#!/usr/bin/env python3
"""Multi-vendor, multi-ROM repository discovery and thermal-relevant ingestion."""
from __future__ import annotations

import argparse
import json
import os
import re
import subprocess
import sys
import tempfile
import time
import urllib.error
import urllib.parse
import urllib.request
from dataclasses import dataclass
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOLS = ROOT / "tools"
if str(TOOLS) not in sys.path:
    sys.path.insert(0, str(TOOLS))

from hico_thermal.artifacts import analyze_file, relevant_path, sha256_bytes
from hico_thermal.codecs import CodecError, CodecRegistry

MAX_FILE = 512 * 1024
MAX_FILES_PER_REPO = 2048
RETRY_CODES = {429, 500, 502, 503, 504}
REPO_NAME_RE = re.compile(r"(?:^|_)(?:android_)?(?:device|vendor|kernel|hardware)(?:_|$)", re.I)
ROM_FAMILY_BY_SOURCE = {
    "lineageos": "lineageos",
    "pixelos": "pixelos",
    "evolution-x": "evolution-x",
    "crdroid": "crdroid",
    "aospa": "aospa",
    "arrowos": "arrowos",
    "derpfest": "derpfest",
    "voltageos": "voltageos",
    "superioros": "superioros",
    "project-elixir": "project-elixir",
    "nusantara": "nusantara",
    "infinity-x": "infinity-x",
    "axion": "axion",
    "cherish": "cherish",
    "risingos": "risingos",
}


class IngestError(RuntimeError):
    pass


def request_json(url: str, token: str | None = None, *, token_header: str = "Authorization", timeout: int = 45):
    headers = {"User-Agent": "HiCo-Thermal-Ingest/2.0", "Accept": "application/json"}
    if token:
        headers[token_header] = f"Bearer {token}" if token_header == "Authorization" else token
    req = urllib.request.Request(url, headers=headers)
    for attempt in range(5):
        try:
            with urllib.request.urlopen(req, timeout=timeout) as response:
                return json.loads(response.read().decode("utf-8"))
        except urllib.error.HTTPError as exc:
            if exc.code not in RETRY_CODES or attempt == 4:
                raise
            time.sleep(2**attempt)
        except (urllib.error.URLError, TimeoutError):
            if attempt == 4:
                raise
            time.sleep(2**attempt)
    raise IngestError(f"unable to fetch {url}")


def github_token() -> str | None:
    return os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN")


def gitlab_token() -> str | None:
    return os.environ.get("HICO_GITLAB_TOKEN") or os.environ.get("GITLAB_TOKEN")


@dataclass(frozen=True)
class Repo:
    provider: str
    source_id: str
    full_name: str
    branch: str
    web_url: str
    api_url: str
    clone_url: str = ""

    def key(self) -> str:
        return f"{self.provider}:{self.full_name}"


def clean_name(value: str) -> str:
    cleaned = re.sub(r"[^A-Za-z0-9._-]+", "_", value.strip())
    return cleaned[:160] or "unknown"


def chunk(values: list[dict], size: int) -> list[list[dict]]:
    if size <= 0:
        raise ValueError("shard size must be > 0")
    return [values[i : i + size] for i in range(0, len(values), size)]


def _repo_name_relevant(name: str, query: str = "") -> bool:
    lowered = name.lower()
    if REPO_NAME_RE.search(name):
        return True
    if any(token in lowered for token in ("thermal", "thermald", "powerhal", "cpufreq", "devfreq", "cooling")):
        return True
    return any(token in query.lower() for token in ("thermal", "cooling", "powerhal", "cpufreq", "devfreq")) and bool(REPO_NAME_RE.search(name))


def github_org_repos(org: str, source_id: str) -> list[Repo]:
    token = github_token()
    repos: list[Repo] = []
    page = 1
    while True:
        url = f"https://api.github.com/orgs/{urllib.parse.quote(org)}/repos?per_page=100&page={page}&type=all&sort=full_name&direction=asc"
        items = request_json(url, token)
        if not items:
            break
        for item in items:
            name = item.get("name", "")
            if item.get("private") or item.get("archived") or item.get("disabled") or not _repo_name_relevant(name):
                continue
            branch = item.get("default_branch")
            if not branch:
                continue
            repos.append(
                Repo(
                    "github",
                    source_id,
                    item["full_name"],
                    branch,
                    item.get("html_url", ""),
                    item["url"],
                    item.get("clone_url", ""),
                )
            )
        if len(items) < 100:
            break
        page += 1
    return repos


def github_search(query: str, source_id: str) -> list[Repo]:
    token = github_token()
    repos: list[Repo] = []
    seen: set[str] = set()
    for page in range(1, 11):
        q = urllib.parse.quote(f"{query} archived:false")
        body = request_json(
            f"https://api.github.com/search/repositories?q={q}&per_page=100&page={page}&sort=updated&order=desc",
            token,
        )
        items = body.get("items", [])
        for item in items:
            full_name = item.get("full_name", "")
            if not full_name or full_name in seen or item.get("private") or item.get("archived") or item.get("disabled"):
                continue
            if not _repo_name_relevant(item.get("name", ""), query):
                continue
            branch = item.get("default_branch")
            if not branch:
                continue
            seen.add(full_name)
            repos.append(
                Repo(
                    "github",
                    source_id,
                    full_name,
                    branch,
                    item.get("html_url", ""),
                    item["url"],
                    item.get("clone_url", ""),
                )
            )
        if len(items) < 100:
            break
    return repos


def gitlab_group_projects(base: str, group: str, source_id: str) -> list[Repo]:
    token = gitlab_token()
    repos: list[Repo] = []
    group_id = urllib.parse.quote(group, safe="")
    page = 1
    while True:
        url = f"{base.rstrip('/')}/api/v4/groups/{group_id}/projects?include_subgroups=true&archived=false&order_by=path&sort=asc&per_page=100&page={page}"
        items = request_json(url, token, token_header="PRIVATE-TOKEN")
        if not items:
            break
        for item in items:
            branch = item.get("default_branch")
            if item.get("empty_repo") or not branch:
                continue
            repos.append(
                Repo(
                    "gitlab",
                    source_id,
                    item.get("path_with_namespace", item.get("path", "")),
                    branch,
                    item.get("web_url", ""),
                    f"{base.rstrip('/')}/api/v4/projects/{item['id']}",
                    item.get("http_url_to_repo", ""),
                )
            )
        if len(items) < 100:
            break
        page += 1
    return repos


def matrix_from_discovery(discovery: dict, max_jobs: int = 250) -> list[dict]:
    jobs = list(discovery.get("jobs", []))
    if len(jobs) > max_jobs:
        raise IngestError(f"discovery contains {len(jobs)} shards; max allowed matrix jobs is {max_jobs}")
    return jobs


def _git_url(repo: Repo) -> str:
    clone = repo.clone_url
    if not clone:
        if repo.provider == "github":
            clone = f"https://github.com/{repo.full_name}.git"
        else:
            raise IngestError(f"no clone URL available for {repo.full_name}")
    if repo.provider == "github":
        token = github_token()
        if token and clone.startswith("https://github.com/"):
            suffix = clone[len("https://") :]
            return "https://x-access-token:" + urllib.parse.quote(token, safe="") + "@" + suffix
    else:
        token = gitlab_token()
        if token and clone.startswith("https://"):
            suffix = clone[len("https://") :]
            return "https://oauth2:" + urllib.parse.quote(token, safe="") + "@" + suffix
    return clone


def _run_git(cmd: list[str], *, cwd: Path | None = None, input_text: str | None = None) -> subprocess.CompletedProcess:
    return subprocess.run(
        cmd,
        cwd=cwd,
        input=input_text,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
        text=False,
    )


def _git_text(cmd: list[str], *, cwd: Path | None = None) -> str:
    proc = _run_git(cmd, cwd=cwd)
    if proc.returncode != 0:
        detail = proc.stderr.decode("utf-8", errors="replace").strip()
        raise IngestError(f"git command failed: {detail or proc.returncode}")
    return proc.stdout.decode("utf-8", errors="replace")


def _git_bytes(cmd: list[str], *, cwd: Path | None = None) -> bytes:
    proc = _run_git(cmd, cwd=cwd)
    if proc.returncode != 0:
        detail = proc.stderr.decode("utf-8", errors="replace").strip()
        raise IngestError(f"git command failed: {detail or proc.returncode}")
    return proc.stdout


def clone_partial(repo: Repo, destination: Path) -> Path:
    cmd = [
        "git",
        "-c",
        "protocol.version=2",
        "clone",
        "--filter=blob:none",
        "--no-checkout",
        "--depth=1",
        "--single-branch",
        "--branch",
        repo.branch,
        _git_url(repo),
        str(destination),
    ]
    proc = _run_git(cmd)
    if proc.returncode != 0:
        detail = proc.stderr.decode("utf-8", errors="replace").strip()
        raise IngestError(f"partial clone failed for {repo.full_name}: {detail or proc.returncode}")
    return destination


def repo_tree(repo_dir: Path) -> list[str]:
    output = _git_text(["git", "ls-tree", "-r", "--name-only", "HEAD"], cwd=repo_dir)
    return [line for line in output.splitlines() if line]


def archive_paths(repo_dir: Path, paths: list[str]) -> dict[str, tuple[bytes, int]]:
    if not paths:
        return {}
    data = _git_bytes(["git", "archive", "--format=tar", "HEAD", "--", *paths], cwd=repo_dir)
    import io
    import tarfile

    result: dict[str, tuple[bytes, int]] = {}
    with tarfile.open(fileobj=io.BytesIO(data), mode="r:") as archive:
        for member in archive.getmembers():
            if not member.isfile():
                continue
            stream = archive.extractfile(member)
            if stream is None:
                continue
            result[member.name] = (stream.read(MAX_FILE + 1), member.size)
    return result


def repo_commit(repo_dir: Path) -> str:
    return _git_text(["git", "rev-parse", "HEAD"], cwd=repo_dir).strip()


def parse_dependency_refs(path: str, data: bytes) -> list[str]:
    if not path.lower().endswith(".dependencies") and Path(path).name.lower() != ".gitmodules":
        return []
    text = data[:MAX_FILE].decode("utf-8", errors="replace")
    patterns = [
        re.compile(r"https?://github\.com/([A-Za-z0-9_.-]+/[A-Za-z0-9_.-]+)"),
        re.compile(r"https?://gitlab\.com/([A-Za-z0-9_.-]+/[A-Za-z0-9_.-]+)"),
        re.compile(r"[\"'](?:repository|repo)[\"']\s*[:=]\s*[\"']([^\"']+/[^\"']+)[\"']"),
    ]
    refs: set[str] = set()
    for pattern in patterns:
        refs.update(match.group(1).removesuffix(".git") for match in pattern.finditer(text))
    return sorted(refs)


def discover(registry_path: Path, shard_size: int) -> dict:
    registry = json.loads(registry_path.read_text())
    jobs: list[dict] = []
    sources: list[dict] = []
    errors: list[dict] = []
    for spec in registry.get("sources", []):
        sid = spec.get("id", "")
        kind = spec.get("type", "")
        try:
            repos: list[Repo] = []
            if kind == "github_org":
                repos = github_org_repos(spec["organization"], sid)
            elif kind == "github_search":
                for query in spec.get("queries", []):
                    repos.extend(github_search(query, sid))
                unique = {repo.key(): repo for repo in repos}
                repos = sorted(unique.values(), key=lambda item: item.full_name)
            elif kind == "gitlab_group":
                repos = gitlab_group_projects(spec["base"], spec["group"], sid)
            else:
                raise ValueError(f"unsupported source type: {kind}")
            raw = [repo.__dict__ for repo in repos]
            shards = chunk(raw, shard_size)
            for index, items in enumerate(shards):
                jobs.append(
                    {
                        "id": f"{sid}-{index:04d}",
                        "source_id": sid,
                        "source_type": kind,
                        "rom_family": spec.get("family", ROM_FAMILY_BY_SOURCE.get(sid, "oem")),
                        "repos": items,
                    }
                )
            sources.append(
                {
                    "id": sid,
                    "type": kind,
                    "family": spec.get("family", ROM_FAMILY_BY_SOURCE.get(sid, "oem")),
                    "repos": len(repos),
                    "shards": len(shards),
                    "status": "ok",
                }
            )
        except urllib.error.HTTPError as exc:
            if (kind == "gitlab_group" and exc.code == 404) or (kind == "github_org" and exc.code == 404 and spec.get("optional", False)):
                sources.append({"id": sid, "type": kind, "repos": 0, "shards": 0, "status": "missing"})
            else:
                errors.append({"source": sid, "status": exc.code, "error": str(exc)})
                sources.append({"id": sid, "type": kind, "repos": 0, "shards": 0, "status": "error", "error": str(exc)})
        except Exception as exc:
            errors.append({"source": sid, "error": str(exc)})
            sources.append({"id": sid, "type": kind, "repos": 0, "shards": 0, "status": "error", "error": str(exc)})
    return {"schema": "hico.discovery.v2", "sources": sources, "jobs": jobs, "errors": errors}


def ingest_job(job: dict, out: Path, *, hicod: str | None = None, decode_known: bool = False) -> dict:
    out.mkdir(parents=True, exist_ok=True)
    manifests = out / "manifests"
    raw_root = out / "raw"
    manifests.mkdir(exist_ok=True)
    raw_root.mkdir(exist_ok=True)
    output_repos: list[str] = []
    failures: list[dict] = []
    registry = CodecRegistry(hicod) if decode_known and hicod else None
    for raw_repo in job.get("repos", []):
        repo = Repo(**raw_repo)
        repo_key = clean_name(repo.full_name)
        try:
            with tempfile.TemporaryDirectory(prefix="hico-ingest-") as td:
                repo_dir = clone_partial(repo, Path(td) / "repo")
                commit = repo_commit(repo_dir)
                tree = repo_tree(repo_dir)
                candidates = [path for path in tree if relevant_path(path)]
                truncated = len(candidates) > MAX_FILES_PER_REPO
                if truncated:
                    raise IngestError(
                        f"{repo.full_name}: {len(candidates)} thermal-relevant files exceed MAX_FILES_PER_REPO={MAX_FILES_PER_REPO}"
                    )
                blobs = archive_paths(repo_dir, sorted(candidates))
                files = []
                dependencies: set[str] = set()
                for path in sorted(candidates):
                    blob = blobs.get(path, (b"", 0))
                    data, full_size = blob
                    if full_size > MAX_FILE:
                        files.append(
                            {
                                "path": path,
                                "tree_path": path,
                                "provider": repo.provider,
                                "repository": repo.full_name,
                                "branch": repo.branch,
                                "source_url": repo.web_url,
                                "source_commit": commit,
                                "sha256_prefix": sha256_bytes(data[:MAX_FILE]),
                                "size": full_size,
                                "storage": "metadata-only",
                                "status": "file-too-large",
                            }
                        )
                        continue
                    info = analyze_file(Path(path), data)
                    info.update(
                        {
                            "source_id": repo.source_id,
                            "provider": repo.provider,
                            "repository": repo.full_name,
                            "branch": repo.branch,
                            "source_url": repo.web_url,
                            "source_commit": commit,
                            "tree_path": path,
                        }
                    )
                    if Path(path).name.lower() in {
                        "lineage.dependencies",
                        "evolution.dependencies",
                        "aospa.dependencies",
                        ".gitmodules",
                    }:
                        dependencies.update(parse_dependency_refs(path, data))
                    if registry is not None:
                        candidates_for_decode = registry.candidates(Path(path), data)
                        info["codec_candidates"] = [codec.name for codec in candidates_for_decode]
                        info["decode_status"] = "plain" if info.get("format") in {"text", "thermal-engine-text", "json", "xml"} else "not-requested"
                        for codec in candidates_for_decode:
                            if codec.name == "plain" or not codec.can_decode:
                                continue
                            try:
                                decoded = codec.decode(data, Path(path))
                            except CodecError as exc:
                                message = str(exc)
                                if "not an encrypted mi_thermald config" in message or "no decoder" in message:
                                    info["decode_status"] = "opaque"
                                    info["decode_error"] = message
                                    info["codec"] = "unknown"
                                else:
                                    failures.append({"repository": repo.full_name, "path": path, "error": message})
                                    info["decode_status"] = "failed"
                                    info["decode_error"] = message
                                break
                            decoded_info = analyze_file(Path(path), decoded)
                            info.update({
                                "codec": codec.name,
                                "decode_status": "decoded",
                                "decoded_size": len(decoded),
                                "decoded_sha256": sha256_bytes(decoded),
                                "decoded_format": decoded_info["format"],
                                "decoded_parser": decoded_info["parser"],
                                "decoded_sections": decoded_info["sections"],
                                "decoded_max_trip_c": decoded_info["max_trip_c"],
                            })
                            break
                    if info["format"] in {"text", "thermal-engine-text", "json", "xml"} and len(data) <= MAX_FILE:
                        destination = raw_root / job["source_id"] / repo_key / path
                        destination.parent.mkdir(parents=True, exist_ok=True)
                        destination.write_bytes(data)
                        info["storage"] = "raw-text"
                        info["raw_path"] = str(destination.relative_to(out)).replace("\\", "/")
                    else:
                        info["storage"] = "metadata-only"
                    files.append(info)

                manifest = {
                    "schema": "hico.repository.v2",
                    "source": {
                        "id": repo.source_id,
                        "provider": repo.provider,
                        "repository": repo.full_name,
                        "branch": repo.branch,
                        "commit": commit,
                        "url": repo.web_url,
                        "family": job.get("rom_family", "oem"),
                    },
                    "repository": {"tree_complete": True, "candidate_count": len(candidates)},
                    "dependencies": sorted(dependencies),
                    "files": files,
                    "failure_count": 0,
                }
                manifest_path = manifests / job["source_id"] / f"{repo_key}.json"
                manifest_path.parent.mkdir(parents=True, exist_ok=True)
                manifest_path.write_text(json.dumps(manifest, indent=2, sort_keys=True) + "\n")
                output_repos.append(repo.full_name)
        except Exception as exc:
            failures.append({"repository": repo.full_name, "error": str(exc)})

    summary = {
        "schema": "hico.ingest-result.v2",
        "job": job["id"],
        "repositories": len(output_repos),
        "failures": failures,
    }
    (out / "summary.json").write_text(json.dumps(summary, indent=2, sort_keys=True) + "\n")
    return summary


def main() -> int:
    ap = argparse.ArgumentParser(description="Discover and ingest device/thermal repositories without vendor-specific assumptions")
    sub = ap.add_subparsers(dest="cmd", required=True)
    p = sub.add_parser("discover")
    p.add_argument("--registry", default=str(ROOT / "sources" / "registry.json"))
    p.add_argument("--output", required=True)
    p.add_argument("--shard-size", type=int, default=25)
    p = sub.add_parser("matrix")
    p.add_argument("--discovery", required=True)
    p.add_argument("--output", required=True)
    p.add_argument("--max-jobs", type=int, default=250)
    p = sub.add_parser("ingest")
    p.add_argument("--job", required=True)
    p.add_argument("--output", required=True)
    p.add_argument("--hicod", default=None, help="host hicod used for supported known codecs such as Xiaomi MiCrypt")
    p.add_argument("--decode-known", action="store_true", help="decode supported known codecs and store only normalized metadata, never decoded raw bytes")
    args = ap.parse_args()

    if args.cmd == "discover":
        result = discover(Path(args.registry), args.shard_size)
        output = Path(args.output)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
        print(json.dumps({"sources": len(result["sources"]), "jobs": len(result["jobs"]), "errors": len(result["errors"])}, indent=2))
        return 1 if result["errors"] else 0
    if args.cmd == "matrix":
        discovery = json.loads(Path(args.discovery).read_text())
        jobs = matrix_from_discovery(discovery, args.max_jobs)
        output = Path(args.output)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(json.dumps(jobs, separators=(",", ":")) + "\n")
        print(json.dumps({"jobs": len(jobs)}, indent=2))
        return 0

    job = json.loads(Path(args.job).read_text())
    result = ingest_job(job, Path(args.output), hicod=args.hicod, decode_known=args.decode_known)
    print(json.dumps({"job": result["job"], "repositories": result["repositories"], "failures": len(result["failures"])}, indent=2))
    return 1 if result["failures"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
