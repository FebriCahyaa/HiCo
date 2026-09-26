#!/usr/bin/env python3
from __future__ import annotations

import argparse
import hashlib
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def manifest_for(root: Path) -> dict[str, str]:
    result = {}
    for path in sorted(root.rglob("*")):
        if not path.is_file():
            continue
        rel = path.relative_to(root).as_posix()
        digest = hashlib.sha256(path.read_bytes()).hexdigest()
        result[rel] = digest
    return result


def read_manifest(path: Path) -> dict[str, str]:
    entries: dict[str, str] = {}
    for line in path.read_text().splitlines():
        if not line.strip():
            continue
        parts = line.split(None, 1)
        if len(parts) != 2 or len(parts[0]) != 64:
            raise ValueError(f"invalid manifest line: {line!r}")
        digest, rel = parts
        entries[rel] = digest
    return entries


def write_manifest(webui: Path, output: Path) -> None:
    data = manifest_for(webui)
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text("".join(f"{digest}  {path}\n" for path, digest in sorted(data.items())))


def verify(webui: Path, manifest: Path) -> list[str]:
    expected = read_manifest(manifest)
    actual = manifest_for(webui)
    errors = []
    for rel in sorted(expected.keys() | actual.keys()):
        if rel not in expected:
            errors.append(f"unexpected WebUI file: {rel}")
        elif rel not in actual:
            errors.append(f"missing WebUI file: {rel}")
        elif expected[rel] != actual[rel]:
            errors.append(f"modified WebUI file: {rel}")
    return errors


def main() -> int:
    ap = argparse.ArgumentParser(description="Verify the HiCo WebUI against a checked-in SHA-256 manifest")
    ap.add_argument("--webui", default=str(ROOT / "webui"))
    ap.add_argument("--manifest", default=str(ROOT / "docs" / "integrity" / "webui.sha256"))
    ap.add_argument("--write", action="store_true", help="write a new manifest instead of verifying")
    args = ap.parse_args()

    webui = Path(args.webui)
    manifest = Path(args.manifest)
    if not webui.is_dir():
        print(f"webui directory not found: {webui}", file=sys.stderr)
        return 1
    if args.write:
        write_manifest(webui, manifest)
        print(f"WebUI manifest written: {manifest}")
        return 0
    if not manifest.is_file():
        print(f"WebUI manifest not found: {manifest}", file=sys.stderr)
        return 1
    errors = verify(webui, manifest)
    if errors:
        for error in errors:
            print(error, file=sys.stderr)
        return 1
    print(f"WebUI integrity verified: {len(manifest_for(webui))} files")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
