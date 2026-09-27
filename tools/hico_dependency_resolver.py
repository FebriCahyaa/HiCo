#!/usr/bin/env python3
# Deterministic resolver for Lineage-style repository dependency references.
from __future__ import annotations

import re
from typing import Iterable

GITHUB_PREFIXES = (
    "https://github.com/",
    "http://github.com/",
    "https://www.github.com/",
    "http://www.github.com/",
    "github.com/",
)


def normalize_reference(value: object) -> str:
    text = str(value or "").strip()
    text = text.replace("\\", "/")
    if text.startswith("git@github.com:"):
        text = "github.com/" + text.split(":", 1)[1]
    text = re.sub(r"^\s+", "", text)
    lowered = text.lower()
    for prefix in GITHUB_PREFIXES:
        if lowered.startswith(prefix):
            text = text[len(prefix):]
            break
        if lowered.startswith(prefix.rstrip("/")):
            text = text[len(prefix.rstrip("/")):]
            break
        lowered = text.lower()
    text = text.strip().strip("/")
    if text.lower().endswith(".git"):
        text = text[:-4]
    return text.lower()


def repository_full_name(repo: dict) -> str:
    return normalize_reference(repo.get("full_name", ""))


def repository_basename(repo: dict) -> str:
    name = repository_full_name(repo)
    return name.rsplit("/", 1)[-1] if name else ""


def resolve_dependency(reference: object, repositories: Iterable[dict]) -> dict:
    # Resolve exact full-name first, then unique basename; never guess.
    wanted = normalize_reference(reference)
    if not wanted:
        return {"status": "unresolved", "strategy": "empty-reference", "repository": None, "candidates": []}

    repos = sorted(
        (dict(repo) for repo in repositories if isinstance(repo, dict)),
        key=lambda repo: (
            normalize_reference(repo.get("provider", "")),
            repository_full_name(repo),
        ),
    )

    full_matches = [repo for repo in repos if repository_full_name(repo) == wanted]
    if len(full_matches) == 1:
        return {
            "status": "resolved",
            "strategy": "exact-full-name",
            "repository": full_matches[0],
            "candidates": [repository_full_name(full_matches[0])],
        }
    if len(full_matches) > 1:
        return {
            "status": "ambiguous",
            "strategy": "duplicate-full-name",
            "repository": None,
            "candidates": [repository_full_name(repo) for repo in full_matches],
        }

    basename = wanted.rsplit("/", 1)[-1]
    basename_matches = [repo for repo in repos if repository_basename(repo) == basename]
    if len(basename_matches) == 1:
        return {
            "status": "resolved",
            "strategy": "unique-basename",
            "repository": basename_matches[0],
            "candidates": [repository_full_name(basename_matches[0])],
        }
    if len(basename_matches) > 1:
        return {
            "status": "ambiguous",
            "strategy": "ambiguous-basename",
            "repository": None,
            "candidates": [repository_full_name(repo) for repo in basename_matches],
        }

    return {
        "status": "unresolved",
        "strategy": "no-match",
        "repository": None,
        "candidates": [],
    }


if __name__ == "__main__":
    import argparse
    import json

    ap = argparse.ArgumentParser()
    ap.add_argument("reference")
    ap.add_argument("--repository", action="append", default=[])
    args = ap.parse_args()
    repos = [{"provider": "github", "full_name": item} for item in args.repository]
    print(json.dumps(resolve_dependency(args.reference, repos), indent=2, sort_keys=True))
