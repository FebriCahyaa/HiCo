#!/usr/bin/env python3
"""Small deterministic parsers for canonical Android source evidence.

Phase 2.6a is parser-only: these functions turn already-collected evidence files
into structured facts. They do not resolve repository identities, create graph
relationships, call network APIs, or mutate the evidence tree.
"""
from __future__ import annotations

import re
import shlex
from typing import Iterable

SCHEMA = "hico.source-evidence-parsers.v1"


def _unique_sorted(values: Iterable[str]) -> list[str]:
    return sorted({str(value).strip() for value in values if str(value).strip()})


def _strip_comment(line: str) -> str:
    quote = None
    escaped = False
    for i, ch in enumerate(line):
        if escaped:
            escaped = False
            continue
        if ch == "\\":
            escaped = True
            continue
        if quote:
            if ch == quote:
                quote = None
            continue
        if ch in ("'", '"'):
            quote = ch
        elif ch == "#":
            return line[:i]
    return line


def _logical_make_lines(text: str) -> list[str]:
    """Join Make continuation lines without attempting to evaluate Make."""
    result: list[str] = []
    current = ""
    for raw in text.splitlines():
        line = _strip_comment(raw).rstrip()
        if not line and not current:
            continue
        if line.endswith("\\"):
            current += line[:-1].rstrip() + " "
            continue
        current += line
        if current.strip():
            result.append(current.strip())
        current = ""
    if current.strip():
        result.append(current.strip())
    return result


def _assignment_values(lines: Iterable[str], key: str) -> list[str]:
    pattern = re.compile(
        rf"^\s*{re.escape(key)}\s*(?:::=|\+=|:=|\?=|=)\s*(.*?)\s*$"
    )
    values: list[str] = []
    for line in lines:
        match = pattern.match(line)
        if match:
            values.append(match.group(1).strip())
    return values


def _make_tokens(value: str) -> list[str]:
    try:
        return [token for token in shlex.split(value, posix=True) if token]
    except ValueError:
        return [token for token in value.split() if token]


def _assigned_tokens(lines: Iterable[str], key: str) -> list[str]:
    values = _assignment_values(lines, key)
    tokens: list[str] = []
    for value in values:
        tokens.extend(_make_tokens(value))
    return _unique_sorted(tokens)


def parse_android_products_mk(text: str) -> dict:
    """Parse root AndroidProducts.mk product and lunch declarations."""
    lines = _logical_make_lines(text)
    return {
        "schema": SCHEMA,
        "file": "AndroidProducts.mk",
        "product_makefiles": _assigned_tokens(lines, "PRODUCT_MAKEFILES"),
        "common_lunch_choices": _assigned_tokens(lines, "COMMON_LUNCH_CHOICES"),
    }


def parse_device_mk(text: str) -> dict:
    """Parse common product/build declarations from device.mk without evaluation."""
    lines = _logical_make_lines(text)
    includes = []
    inherited_products = []
    include_re = re.compile(r"^\s*include\s+(.+?)\s*$")
    inherit_re = re.compile(
        r"\$\(call\s+inherit-product(?:-if-exists)?\s*,\s*([^\)]+)\)"
    )
    for line in lines:
        match = include_re.match(line)
        if match:
            includes.append(match.group(1).strip())
        for inherited in inherit_re.findall(line):
            inherited_products.append(inherited.strip())

    return {
        "schema": SCHEMA,
        "file": "device.mk",
        "includes": _unique_sorted(includes),
        "inherited_products": _unique_sorted(inherited_products),
        "product_packages": _assigned_tokens(lines, "PRODUCT_PACKAGES"),
        "product_copy_files": _assigned_tokens(lines, "PRODUCT_COPY_FILES"),
        "product_soong_namespaces": _assigned_tokens(lines, "PRODUCT_SOONG_NAMESPACES"),
        "device_package_overlays": _assigned_tokens(lines, "DEVICE_PACKAGE_OVERLAYS"),
    }


def _find_matching_brace(text: str, opening: int) -> int | None:
    depth = 0
    quote: str | None = None
    escaped = False
    line_comment = False
    block_comment = False
    i = opening
    while i < len(text):
        ch = text[i]
        nxt = text[i + 1] if i + 1 < len(text) else ""
        if line_comment:
            if ch == "\n":
                line_comment = False
            i += 1
            continue
        if block_comment:
            if ch == "*" and nxt == "/":
                block_comment = False
                i += 2
                continue
            i += 1
            continue
        if quote:
            if escaped:
                escaped = False
            elif ch == "\\":
                escaped = True
            elif ch == quote:
                quote = None
            i += 1
            continue
        if ch == "/" and nxt == "/":
            line_comment = True
            i += 2
            continue
        if ch == "/" and nxt == "*":
            block_comment = True
            i += 2
            continue
        if ch in ("'", '"'):
            quote = ch
        elif ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return None


def _bp_named_blocks(text: str) -> list[tuple[str, str]]:
    """Return (block_type, body) for top-level-looking Blueprint blocks."""
    header = re.compile(r"(?m)^\s*([A-Za-z_][A-Za-z0-9_.-]*)\s*\{")
    blocks: list[tuple[str, str]] = []
    search_from = 0
    while True:
        match = header.search(text, search_from)
        if not match:
            break
        opening = match.end() - 1
        closing = _find_matching_brace(text, opening)
        if closing is None:
            break
        blocks.append((match.group(1), text[opening + 1 : closing]))
        search_from = closing + 1
    return blocks


def _bp_scalar(body: str, key: str) -> str:
    match = re.search(rf"(?m)^\s*{re.escape(key)}\s*:\s*\"([^\"]*)\"", body)
    return match.group(1) if match else ""


def _bp_string_array(body: str, key: str) -> list[str]:
    match = re.search(rf"(?ms)^\s*{re.escape(key)}\s*:\s*\[(.*?)\]", body)
    if not match:
        return []
    return _unique_sorted(re.findall(r'\"([^\"]*)\"', match.group(1)))


def parse_android_bp(text: str) -> dict:
    """Parse named Blueprint blocks and selected dependency/source arrays."""
    modules = []
    for block_type, body in _bp_named_blocks(text):
        name = _bp_scalar(body, "name")
        if not name and block_type not in {"package", "soong_namespace"}:
            continue
        item = {"type": block_type}
        if name:
            item["name"] = name
        for key in (
            "srcs",
            "required",
            "shared_libs",
            "static_libs",
            "defaults",
            "local_include_dirs",
            "export_include_dirs",
            "include_dirs",
            "imports",
        ):
            values = _bp_string_array(body, key)
            if values:
                item[key] = values
        modules.append(item)

    modules.sort(key=lambda item: (item["type"], item.get("name", "")))
    return {
        "schema": SCHEMA,
        "file": "Android.bp",
        "modules": modules,
    }


def _local_assignment(line: str) -> tuple[str, str] | None:
    match = re.match(r"^\s*(LOCAL_[A-Za-z0-9_]+)\s*(?:\+=|:=|\?=|=)\s*(.*?)\s*$", line)
    if not match:
        return None
    return match.group(1), match.group(2).strip()


def parse_android_mk(text: str) -> dict:
    """Parse Android.mk module blocks bounded by CLEAR_VARS/BUILD_* includes."""
    lines = _logical_make_lines(text)
    modules: list[dict] = []
    build_includes: list[str] = []
    current: dict = {}

    def flush() -> None:
        nonlocal current
        if current.get("module"):
            modules.append(current)
        current = {}

    for line in lines:
        if re.search(r"\$\(CLEAR_VARS\)", line):
            flush()
            continue

        assignment = _local_assignment(line)
        if assignment:
            key, value = assignment
            if key in {"LOCAL_MODULE", "LOCAL_MODULE_CLASS", "LOCAL_PATH"}:
                current[{"LOCAL_MODULE": "module", "LOCAL_MODULE_CLASS": "module_class", "LOCAL_PATH": "local_path"}[key]] = value
            elif key in {
                "LOCAL_SRC_FILES",
                "LOCAL_SHARED_LIBRARIES",
                "LOCAL_STATIC_LIBRARIES",
                "LOCAL_REQUIRED_MODULES",
                "LOCAL_C_INCLUDES",
            }:
                field = {
                    "LOCAL_SRC_FILES": "src_files",
                    "LOCAL_SHARED_LIBRARIES": "shared_libraries",
                    "LOCAL_STATIC_LIBRARIES": "static_libraries",
                    "LOCAL_REQUIRED_MODULES": "required_modules",
                    "LOCAL_C_INCLUDES": "c_includes",
                }[key]
                current[field] = _unique_sorted(
                    [*(current.get(field, [])), *_make_tokens(value)]
                )
            continue

        build_match = re.search(r"^\s*include\s+\$\((BUILD_[A-Za-z0-9_]+)\)\s*$", line)
        if build_match:
            build_includes.append(build_match.group(1))
            if current:
                current["build_template"] = build_match.group(1)
            flush()

    flush()
    modules.sort(key=lambda item: item.get("module", ""))
    return {
        "schema": SCHEMA,
        "file": "Android.mk",
        "build_includes": _unique_sorted(build_includes),
        "modules": modules,
    }


def parse_extract_files_sh(text: str) -> dict:
    """Extract conservative references from common Lineage-style shell scripts."""
    sourced_scripts: list[str] = []
    proprietary_file_lists: list[str] = []
    extract_calls: list[dict] = []

    for raw in text.splitlines():
        line = raw.strip()
        if not line or line.startswith("#"):
            continue
        source_match = re.match(r"^(?:source|\.)\s+([^\s#]+)", line)
        if source_match:
            sourced_scripts.append(source_match.group(1).strip("\"'"))

        for token in re.findall(r"[^\s\"']+", line):
            cleaned = token.strip("\"'(),")
            if cleaned.endswith("proprietary-files.txt") or cleaned.endswith("proprietary-files"):
                proprietary_file_lists.append(cleaned)

        call = re.match(r"^(extract(?:_vendor_files)?)\b\s*(.*)$", line)
        if call and not call.group(1).startswith("extract-"):
            extract_calls.append({"command": call.group(1), "arguments": call.group(2).strip()})

    return {
        "schema": SCHEMA,
        "file": "extract-files.sh",
        "sourced_scripts": _unique_sorted(sourced_scripts),
        "proprietary_file_lists": _unique_sorted(proprietary_file_lists),
        "extract_calls": sorted(extract_calls, key=lambda item: (item["command"], item["arguments"])),
    }


def _split_proprietary_mapping(value: str) -> tuple[str, str]:
    if ":" in value and not value.startswith(("http:", "https:")):
        source, destination = value.split(":", 1)
        return source.strip(), destination.strip()
    if "|" in value:
        source, destination = value.split("|", 1)
        return source.strip(), destination.strip()
    return value.strip(), ""


def parse_proprietary_files_txt(text: str) -> dict:
    """Parse proprietary-files entries while preserving raw syntax and prefixes."""
    entries = []
    for raw in text.splitlines():
        line = _strip_comment(raw).strip()
        if not line:
            continue
        prefix = ""
        while line and line[0] in "-?!":
            prefix += line[0]
            line = line[1:].lstrip()
        source, destination = _split_proprietary_mapping(line)
        if not source:
            continue
        entries.append({
            "raw": raw.strip(),
            "prefix": prefix,
            "source": source,
            "destination": destination,
        })

    deduped = {}
    for entry in entries:
        deduped[(entry["raw"], entry["source"], entry["destination"], entry["prefix"])] = entry
    entries = sorted(deduped.values(), key=lambda item: (item["source"], item["destination"], item["prefix"], item["raw"]))
    return {
        "schema": SCHEMA,
        "file": "proprietary-files.txt",
        "entry_count": len(entries),
        "entries": entries,
    }
