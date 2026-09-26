#!/usr/bin/env python3
from __future__ import annotations

import argparse
import json
import os
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
if str(ROOT / "tools") not in sys.path:
    sys.path.insert(0, str(ROOT / "tools"))

from hico_thermal.artifacts import analyze_file, detect_format
from hico_thermal.codecs import CodecError, CodecRegistry
from hico_thermal.mapping import write_mapping, write_mapping_set, write_deep_mapping, write_deep_mapping_set
from hico_thermal.pack import PackError, pack_directory, pack_sparse, pack_stream
from hico_thermal.unpack import UnpackError, unpack


def find_hicod(value: str | None) -> str | None:
    if value:
        return value
    env = os.environ.get("HICOD")
    if env:
        return env
    candidate = ROOT / "build" / "hicod"
    return str(candidate) if candidate.is_file() else shutil.which("hicod")


def main() -> int:
    parser = argparse.ArgumentParser(description="HiCo Thermal artifact codec, unpack/pack and mapping tools")
    parser.add_argument("--hicod", help="path to host hicod for the Xiaomi MiCrypt codec")
    sub = parser.add_subparsers(dest="command", required=True)

    p = sub.add_parser("detect")
    p.add_argument("file")

    sub.add_parser("codecs")

    p = sub.add_parser("decode")
    p.add_argument("file")
    p.add_argument("output")
    p.add_argument("--codec", default=None, help="explicit codec name; auto-detect when omitted")

    p = sub.add_parser("encode")
    p.add_argument("source")
    p.add_argument("target")
    p.add_argument("--codec", default="auto", help="codec to use; auto only works when source format identifies it")

    p = sub.add_parser("unpack")
    p.add_argument("file")
    p.add_argument("output")
    p.add_argument("--filesystem-extract", action="store_true")

    p = sub.add_parser("pack")
    p.add_argument("source")
    p.add_argument("target")
    p.add_argument("--format", choices=["zip", "tar", "gzip", "xz", "bzip2", "zstd", "android-sparse"], required=True)

    p = sub.add_parser("map")
    p.add_argument("root")
    p.add_argument("output")
    p.add_argument("--decode", action="store_true")

    p = sub.add_parser("map-set")
    p.add_argument("roots_file", help="newline-separated root directories")
    p.add_argument("output")
    p.add_argument("--decode", action="store_true")

    p = sub.add_parser("deep-map")
    p.add_argument("root")
    p.add_argument("output")
    p.add_argument("--decode", action="store_true")
    p.add_argument("--filesystem-extract", action="store_true")
    p.add_argument("--max-depth", type=int, default=2)

    p = sub.add_parser("deep-map-set")
    p.add_argument("roots_file", help="newline-separated root directories")
    p.add_argument("output")
    p.add_argument("--decode", action="store_true")
    p.add_argument("--filesystem-extract", action="store_true")
    p.add_argument("--max-depth", type=int, default=2)

    args = parser.parse_args()
    hicod = find_hicod(args.hicod)

    try:
        if args.command == "detect":
            path = Path(args.file)
            result = analyze_file(path)
            result["format"] = detect_format(path)
            print(json.dumps(result, indent=2, sort_keys=True))
            return 0
        if args.command == "codecs":
            print(json.dumps(CodecRegistry(hicod).list(), indent=2))
            return 0
        if args.command == "decode":
            path = Path(args.file)
            codec_name, data = CodecRegistry(hicod).decode(path, args.codec)
            output = Path(args.output)
            output.parent.mkdir(parents=True, exist_ok=True)
            output.write_bytes(data)
            print(json.dumps({"codec": codec_name, "input": str(path), "output": str(output), "size": len(data)}, indent=2))
            return 0
        if args.command == "encode":
            source = Path(args.source)
            target = Path(args.target)
            registry = CodecRegistry(hicod)
            codec_name, data = registry.encode(source, source.read_bytes(), None if args.codec == "auto" else args.codec)
            target.parent.mkdir(parents=True, exist_ok=True)
            target.write_bytes(data)
            print(json.dumps({"codec": codec_name, "input": str(source), "output": str(target), "size": len(data)}, indent=2))
            return 0
        if args.command == "unpack":
            result = unpack(args.file, args.output, allow_filesystem_extract=args.filesystem_extract)
            print(json.dumps(result, indent=2, sort_keys=True))
            return 0
        if args.command == "pack":
            source = Path(args.source)
            fmt = args.format
            if fmt in {"zip", "tar"}:
                result = pack_directory(source, args.target, fmt)
            elif fmt in {"gzip", "xz", "bzip2", "zstd"}:
                result = pack_stream(source, args.target, fmt)
            else:
                result = pack_sparse(source, args.target)
            print(json.dumps(result, indent=2, sort_keys=True))
            return 0
        if args.command == "map":
            result = write_mapping(args.root, args.output, hicod=hicod, decode=args.decode)
            print(json.dumps(result["summary"], indent=2, sort_keys=True))
            return 0 if not result["failures"] else 1
        if args.command == "map-set":
            roots = [line.strip() for line in Path(args.roots_file).read_text().splitlines() if line.strip() and not line.lstrip().startswith("#")]
            if not roots:
                raise ValueError("roots file contains no directories")
            result = write_mapping_set(roots, args.output, hicod=hicod, decode=args.decode)
            print(json.dumps(result["summary"], indent=2, sort_keys=True))
            return 0 if not result["failures"] else 1
        if args.command == "deep-map":
            result = write_deep_mapping(
                args.root,
                args.output,
                hicod=hicod,
                decode=args.decode,
                filesystem_extract=args.filesystem_extract,
                max_depth=args.max_depth,
            )
            print(json.dumps(result["summary"], indent=2, sort_keys=True))
            return 0 if not result["failures"] else 1
        if args.command == "deep-map-set":
            roots = [line.strip() for line in Path(args.roots_file).read_text().splitlines() if line.strip() and not line.lstrip().startswith("#")]
            if not roots:
                raise ValueError("roots file contains no directories")
            result = write_deep_mapping_set(
                roots,
                args.output,
                hicod=hicod,
                decode=args.decode,
                filesystem_extract=args.filesystem_extract,
                max_depth=args.max_depth,
            )
            print(json.dumps(result["summary"], indent=2, sort_keys=True))
            return 0 if not result["failures"] else 1
    except (CodecError, PackError, UnpackError, OSError, ValueError) as exc:
        print(f"hico-thermal: {exc}", file=sys.stderr)
        return 1
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
