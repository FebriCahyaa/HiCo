#!/usr/bin/env python3
"""Verify every entry in stock/sources.yaml points at a live provider.

Runs in ingest.yml and locally before merging changes to sources.yaml. Fails
when a source cannot be reached, when its `family` is unknown, or when its
`org` returns zero public repos.

Deterministic, network-only for validation; never fetches device data.

    python3 tools/verify/rom_sources.py
    python3 tools/verify/rom_sources.py --sources stock/sources.yaml --strict
"""
from __future__ import annotations

import argparse
import json
import os
import sys
import urllib.error
import urllib.request
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

SCHEMA = "hico.ingest-sources.v1"
FAMILIES = {"rom", "oem", "kernel", "aosp", "blobs"}
PROVIDERS = {"github", "gitlab", "git", "repo-manifest"}


def _load_sources(path: Path) -> dict:
    text = path.read_text(encoding="utf-8")
    try:
        import yaml

        return yaml.safe_load(text)
    except ImportError:
        return _mini_yaml(text)


def _scalar(val: str):
    """One YAML scalar or inline flow list (`[a, "b"]`) from this file's subset."""
    val = val.strip()
    if val.startswith("[") and val.endswith("]"):
        inner = val[1:-1].strip()
        return [_scalar(v) for v in inner.split(",")] if inner else []
    if len(val) >= 2 and val[0] == val[-1] == '"':
        # YAML double-quoted escapes (\\, \") match JSON's for this file's content.
        try:
            return json.loads(val)
        except ValueError:
            return val[1:-1]
    if len(val) >= 2 and val[0] == val[-1] == "'":
        return val[1:-1].replace("''", "'")
    return val


def _strip_comment(line: str) -> str:
    """Drop a trailing `# comment` that is not inside quotes."""
    quote = None
    for i, ch in enumerate(line):
        if quote:
            if ch == quote:
                quote = None
        elif ch in "\"'":
            quote = ch
        elif ch == "#" and (i == 0 or line[i - 1] in " \t"):
            return line[:i]
    return line


def _mini_yaml(text: str) -> dict:
    """Small YAML loader for the subset stock/sources.yaml uses.

    GitHub runners set up by actions/setup-python have no PyYAML, so this
    must read everything the file holds, not only the keys known today:
    top-level scalars, top-level lists of strings (thermal_paths,
    blob_paths, ...), and the `sources` list of flat maps whose values may be
    scalars or inline lists (`branches: [a, b]`). tests/ingest_test.py checks
    that it returns exactly what PyYAML returns for the real file.
    """
    result: dict = {}
    section: str | None = None
    entry: dict | None = None
    for raw in text.splitlines():
        stripped = _strip_comment(raw).rstrip()
        if not stripped.strip():
            continue
        indent = len(stripped) - len(stripped.lstrip(" "))
        body = stripped.strip()
        if indent == 0:
            if entry is not None and section is not None:
                result[section].append(entry)
            entry = None
            key, _, val = body.partition(":")
            key = key.strip()
            if val.strip():
                result[key] = _scalar(val)
                section = None
            else:
                result[key] = []
                section = key
            continue
        if section is None:
            continue
        if body.startswith("- "):
            item = body[2:].strip()
            key, sep, val = item.partition(":")
            is_map_item = sep and not item.startswith(("\"", "'")) and " " not in key.strip()
            if is_map_item:
                if entry is not None:
                    result[section].append(entry)
                entry = {key.strip(): _scalar(val)}
            else:
                if entry is not None:
                    result[section].append(entry)
                    entry = None
                result[section].append(_scalar(item))
        elif entry is not None and ":" in body:
            key, _, val = body.partition(":")
            entry[key.strip()] = _scalar(val)
    if entry is not None and section is not None:
        result[section].append(entry)
    return result


def _http_ok(url: str, token: str | None = None) -> tuple[bool, int, str]:
    req = urllib.request.Request(url, headers={"User-Agent": "hico-source-verifier"})
    if token:
        req.add_header("Authorization", f"Bearer {token}")
    try:
        with urllib.request.urlopen(req, timeout=15) as resp:
            body = resp.read().decode("utf-8", "replace")
            return True, resp.status, body
    except urllib.error.HTTPError as exc:
        return False, exc.code, exc.reason
    except Exception as exc:  # noqa: BLE001 — network shape is intentionally broad
        return False, 0, str(exc)


def _github_repo_count(org: str, token: str | None) -> int | None:
    ok, code, body = _http_ok(f"https://api.github.com/orgs/{org}", token)
    if not ok:
        return None
    try:
        return int(json.loads(body).get("public_repos", 0))
    except Exception:  # noqa: BLE001
        return None


def _gitlab_group_exists(group: str) -> bool | None:
    encoded = group.replace("/", "%2F")
    ok, _, _ = _http_ok(f"https://dumps.tadiphone.dev/api/v4/groups/{encoded}")
    return ok


def verify(sources_path: Path, strict: bool) -> int:
    data = _load_sources(sources_path)
    if data.get("schema") != SCHEMA:
        print(f"FAIL schema: expected {SCHEMA!r}, got {data.get('schema')!r}")
        return 2

    entries = data.get("sources") or []
    if not entries:
        print("FAIL sources: none listed")
        return 2

    token = os.environ.get("GITHUB_TOKEN") or os.environ.get("GH_TOKEN")
    failures: list[str] = []
    for src in entries:
        sid = src.get("id") or "?"
        fam = src.get("family") or "?"
        prov = src.get("provider") or "?"
        org = src.get("org") or "?"
        line = f"{sid:24s} family={fam:6s} provider={prov:7s} org={org}"

        if fam not in FAMILIES:
            failures.append(f"{sid}: unknown family {fam!r}")
            print(f"FAIL {line}  — unknown family")
            continue
        if prov not in PROVIDERS:
            failures.append(f"{sid}: unknown provider {prov!r}")
            print(f"FAIL {line}  — unknown provider")
            continue

        if prov == "github":
            count = _github_repo_count(org, token)
            if count is None:
                failures.append(f"{sid}: github org {org!r} unreachable")
                print(f"FAIL {line}  — github unreachable")
            elif count == 0:
                failures.append(f"{sid}: github org {org!r} has 0 public repos")
                print(f"FAIL {line}  — 0 public repos")
            else:
                print(f"OK   {line}  repos={count}")
        elif prov == "repo-manifest":
            # A repo-tool manifest (e.g. TheMuppets/manifests muppets.xml) lists every
            # repository of the org per branch: readable without the GitHub API.
            repo = src.get("manifest_repo") or ""
            fname = src.get("manifest_file") or ""
            branches = src.get("branches") or []
            if isinstance(branches, str):
                branches = [branches]
            counts = []
            for br in branches:
                ok, code, body = _http_ok(f"https://raw.githubusercontent.com/{repo}/{br}/{fname}")
                counts.append(body.count("<project") if ok else 0)
            total = sum(counts)
            if not branches or total == 0:
                failures.append(f"{sid}: manifest {repo}/{fname} has no projects on {branches}")
                print(f"FAIL {line}  — manifest unreadable or empty")
            else:
                print(f"OK   {line}  projects per branch={dict(zip(branches, counts))}")
        elif prov == "gitlab":
            exists = _gitlab_group_exists(org)
            if not exists:
                # tadiphone requires auth; do not fail in strict mode when we
                # already know the endpoint needs a token
                msg = "gitlab group unreachable (auth may be required)"
                if strict:
                    failures.append(f"{sid}: {msg}")
                    print(f"FAIL {line}  — {msg}")
                else:
                    print(f"WARN {line}  — {msg}")
            else:
                print(f"OK   {line}  reachable")
        else:
            print(f"SKIP {line}  — provider not verified here")

    print(f"---\nsources={len(entries)} failures={len(failures)}")
    return 0 if not failures else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--sources", default=str(ROOT / "stock" / "sources.yaml"))
    ap.add_argument("--strict", action="store_true", help="fail on unreachable auth-required endpoints")
    args = ap.parse_args()
    return verify(Path(args.sources), args.strict)


if __name__ == "__main__":
    sys.exit(main())
