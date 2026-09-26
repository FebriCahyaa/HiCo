from __future__ import annotations

import hashlib
import json
import tempfile
from pathlib import Path

from .artifacts import analyze_file, detect_format, walk_relevant
from .codecs import CodecError, CodecRegistry
from .topology import analyze_tree


def _map_one(path: Path, registry: CodecRegistry, decode: bool) -> tuple[dict, dict | None]:
    data = path.read_bytes()
    record = analyze_file(path, data)
    candidates = registry.candidates(path, data)
    record["codec_candidates"] = [codec.name for codec in candidates]
    record["codec"] = candidates[0].name if candidates else "unknown"
    record["decode_supported"] = bool(candidates and candidates[0].can_decode)
    record["encode_supported"] = bool(candidates and candidates[0].can_encode)
    record["decode_status"] = "not-requested"
    record["tunable_status"] = "unknown"
    if record["codec"] == "plain":
        record["tunable_status"] = "parser-dependent" if record.get("parser") else "not-parsed"
        record["decode_status"] = "plain"
        return record, None
    if not decode:
        return record, None
    for codec in candidates:
        if not codec.can_decode or codec.name == "plain":
            continue
        try:
            plain = codec.decode(data, path)
        except CodecError as exc:
            message = str(exc)
            if "not an encrypted mi_thermald config" in message or "no decoder" in message:
                record["decode_status"] = "opaque"
                record["decode_error"] = message
                record["codec"] = "unknown"
                return record, None
            record["decode_status"] = "failed"
            record["decode_error"] = message
            return record, {"path": str(path), "error": message}
        decoded_format = analyze_file(path, plain)
        record.update(
            {
                "codec": codec.name,
                "decode_supported": True,
                "encode_supported": codec.can_encode,
                "decode_status": "decoded",
                "decoded_size": len(plain),
                "decoded_sha256": hashlib.sha256(plain).hexdigest(),
                "decoded_format": decoded_format["format"],
                "decoded_parser": decoded_format["parser"],
                "decoded_sections": decoded_format["sections"],
                "decoded_max_trip_c": decoded_format["max_trip_c"],
                "tunable_status": "parser-supported" if decoded_format["parser"] else "decoded-unparsed",
            }
        )
        return record, None
    record["decode_status"] = "opaque"
    return record, None


def map_tree(root: Path, *, hicod: str | None = None, decode: bool = False) -> dict:
    registry = CodecRegistry(hicod)
    records = []
    failures = []
    for path in walk_relevant(root):
        record, failure = _map_one(path, registry, decode)
        records.append(record)
        if failure:
            failures.append(failure)
    return {
        "schema": "hico.artifact-map.v2",
        "root": str(root),
        "codecs": registry.list(),
        "topology": analyze_tree(root),
        "artifacts": records,
        "failures": failures,
        "summary": {
            "artifacts": len(records),
            "thermal": sum(r["category"] == "thermal" for r in records),
            "plain": sum(r["codec"] == "plain" for r in records),
            "decoded": sum(r["decode_status"] == "decoded" for r in records),
            "opaque": sum(r["decode_status"] == "opaque" for r in records),
            "decode_failures": len(failures),
        },
    }


def map_roots(roots: list[Path], *, hicod: str | None = None, decode: bool = False) -> dict:
    maps = []
    failures = []
    for root in roots:
        result = map_tree(root, hicod=hicod, decode=decode)
        maps.append(result)
        failures.extend(result["failures"])
    aggregate = [record for result in maps for record in result["artifacts"]]
    return {
        "schema": "hico.artifact-map-set.v2",
        "roots": [str(root) for root in roots],
        "maps": maps,
        "artifacts": aggregate,
        "failures": failures,
        "summary": {
            "roots": len(roots),
            "artifacts": len(aggregate),
            "plain": sum(r["codec"] == "plain" for r in aggregate),
            "decoded": sum(r["decode_status"] == "decoded" for r in aggregate),
            "opaque": sum(r["decode_status"] == "opaque" for r in aggregate),
            "decode_failures": len(failures),
        },
    }


def write_mapping(root: str | Path, output: str | Path, *, hicod: str | None = None, decode: bool = False) -> dict:
    result = map_tree(Path(root), hicod=hicod, decode=decode)
    out = Path(output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    return result


def write_mapping_set(roots: list[str | Path], output: str | Path, *, hicod: str | None = None, decode: bool = False) -> dict:
    result = map_roots([Path(root) for root in roots], hicod=hicod, decode=decode)
    out = Path(output)
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    return result


_EXPAND_FORMATS = {
    "zip", "tar", "gzip", "xz", "bzip2", "zstd", "android-sparse", "android-super", "erofs", "ext4",
}


def map_tree_deep(
    root: Path,
    *,
    hicod: str | None = None,
    decode: bool = False,
    filesystem_extract: bool = False,
    max_depth: int = 2,
) -> dict:
    from .unpack import UnpackError, unpack

    root = Path(root)
    if not root.is_dir():
        raise ValueError(f"root is not a directory: {root}")
    depth_limit = max(0, max_depth)
    registry = CodecRegistry(hicod)
    result = map_tree(root, hicod=hicod, decode=decode)
    result["schema"] = "hico.artifact-map.v3"
    result["expanded"] = []
    result["expansion_failures"] = []
    if depth_limit == 0:
        result["summary"]["expanded_containers"] = 0
        return result

    with tempfile.TemporaryDirectory(prefix="hico-deep-map-") as td:
        work = Path(td)
        queue: list[tuple[Path, int, str | None]] = []
        for path in sorted(root.rglob("*")):
            if path.is_file():
                queue.append((path, 0, None))
        seen: set[tuple[str, str]] = set()
        while queue:
            source, depth, parent = queue.pop(0)
            if source.is_symlink() or not source.is_file():
                continue
            fmt = detect_format(source)
            if fmt not in _EXPAND_FORMATS or depth >= depth_limit:
                continue
            stat = source.stat()
            signature = (str(source.resolve()), str(stat.st_size), str(stat.st_mtime_ns), fmt)
            if signature in seen:
                continue
            seen.add(signature)
            rel_key = hashlib.sha256(":".join(signature).encode()).hexdigest()[:16]
            target = work / rel_key
            try:
                expansion = unpack(source, target, allow_filesystem_extract=filesystem_extract)
            except UnpackError as exc:
                result["expansion_failures"].append({"source": str(source), "format": fmt, "error": str(exc)})
                continue
            expansion["source"] = str(source)
            expansion["depth"] = depth
            expansion["parent"] = parent
            result["expanded"].append(expansion)
            if expansion.get("action") == "detected-only":
                continue
            if not target.exists():
                continue
            extracted = map_tree(target, hicod=hicod, decode=decode)
            for record in extracted["artifacts"]:
                extracted_path = Path(record["path"])
                try:
                    member = extracted_path.resolve().relative_to(target.resolve())
                except ValueError:
                    member = extracted_path.name
                record["path"] = str(member).replace("\\", "/")
                record["origin_container"] = str(source)
                record["origin_format"] = fmt
                result["artifacts"].append(record)
            result["failures"].extend(extracted["failures"])
            if depth + 1 < depth_limit:
                for child in sorted(target.rglob("*")):
                    if child.is_file():
                        queue.append((child, depth + 1, str(source)))

    # De-duplicate exact artifact/source pairs introduced by nested expansion.
    dedup: dict[tuple[str, str], dict] = {}
    for record in result["artifacts"]:
        key = (record.get("origin_container", "root"), record.get("path", ""))
        dedup.setdefault(key, record)
    result["artifacts"] = list(dedup.values())
    result["summary"] = {
        "artifacts": len(result["artifacts"]),
        "thermal": sum(r.get("category") == "thermal" for r in result["artifacts"]),
        "plain": sum(r.get("codec") == "plain" for r in result["artifacts"]),
        "decoded": sum(r.get("decode_status") == "decoded" for r in result["artifacts"]),
        "opaque": sum(r.get("decode_status") == "opaque" for r in result["artifacts"]),
        "decode_failures": len(result["failures"]),
        "expanded_containers": len(result["expanded"]),
        "expansion_failures": len(result["expansion_failures"]),
    }
    return result


def write_deep_mapping(root: str | Path, output: str | Path, **kwargs) -> dict:
    result = map_tree_deep(Path(root), **kwargs)
    Path(output).parent.mkdir(parents=True, exist_ok=True)
    Path(output).write_text(json.dumps(result, indent=2, sort_keys=True) + "\n")
    return result


def write_deep_mapping_set(roots: list[str | Path], output: str | Path, **kwargs) -> dict:
    maps = []
    failures = []
    for root in roots:
        result = map_tree_deep(Path(root), **kwargs)
        maps.append(result)
        failures.extend(result["failures"])
        failures.extend(result.get("expansion_failures", []))
    artifacts = [record for result in maps for record in result["artifacts"]]
    aggregate = {
        "schema": "hico.artifact-map-set.v3",
        "roots": [str(root) for root in roots],
        "maps": maps,
        "artifacts": artifacts,
        "failures": failures,
        "summary": {
            "roots": len(maps),
            "artifacts": len(artifacts),
            "plain": sum(r.get("codec") == "plain" for r in artifacts),
            "decoded": sum(r.get("decode_status") == "decoded" for r in artifacts),
            "opaque": sum(r.get("decode_status") == "opaque" for r in artifacts),
            "decode_failures": sum(len(r.get("failures", [])) for r in maps),
            "expanded_containers": sum(len(r.get("expanded", [])) for r in maps),
            "expansion_failures": sum(len(r.get("expansion_failures", [])) for r in maps),
        },
    }
    Path(output).parent.mkdir(parents=True, exist_ok=True)
    Path(output).write_text(json.dumps(aggregate, indent=2, sort_keys=True) + "\n")
    return aggregate
