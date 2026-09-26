from __future__ import annotations

import bz2
import gzip
import lzma
import os
import shutil
import stat
import subprocess
import tarfile
import zipfile
from pathlib import Path

from .artifacts import detect_format


class UnpackError(RuntimeError):
    pass


def _safe_member(root: Path, name: str) -> Path:
    if not name or name.startswith(("/", "\\")):
        raise UnpackError(f"archive member is absolute: {name!r}")
    dest = (root / name).resolve()
    root_resolved = root.resolve()
    try:
        dest.relative_to(root_resolved)
    except ValueError as exc:
        raise UnpackError(f"archive member escapes output directory: {name}") from exc
    return dest


def _copy_regular(src, dest: Path) -> None:
    dest.parent.mkdir(parents=True, exist_ok=True)
    with dest.open("wb") as dst:
        shutil.copyfileobj(src, dst, length=1024 * 1024)


def _extract_tar(path: Path, out: Path) -> list[str]:
    extracted: list[str] = []
    with tarfile.open(path, mode="r:*") as tf:
        for member in tf.getmembers():
            dest = _safe_member(out, member.name)
            if member.isdir():
                dest.mkdir(parents=True, exist_ok=True)
                continue
            if not member.isreg():
                continue
            source = tf.extractfile(member)
            if source is None:
                continue
            _copy_regular(source, dest)
            extracted.append(str(dest.relative_to(out)))
    return extracted


def _extract_zip(path: Path, out: Path) -> list[str]:
    extracted: list[str] = []
    with zipfile.ZipFile(path) as zf:
        for info in zf.infolist():
            dest = _safe_member(out, info.filename)
            if info.is_dir():
                dest.mkdir(parents=True, exist_ok=True)
                continue
            mode = (info.external_attr >> 16) & 0xFFFF
            if mode and stat.S_ISLNK(mode):
                continue
            dest.parent.mkdir(parents=True, exist_ok=True)
            with zf.open(info) as src:
                _copy_regular(src, dest)
            extracted.append(str(dest.relative_to(out)))
    return extracted


def _single_stream(path: Path, out: Path, kind: str) -> list[str]:
    if kind == "gzip":
        opener = gzip.open
        suffix = ".gz"
    elif kind == "xz":
        opener = lzma.open
        suffix = ".xz"
    elif kind == "bzip2":
        opener = bz2.open
        suffix = ".bz2"
    else:
        raise UnpackError(f"unsupported stream format: {kind}")
    name = path.name[:-len(suffix)] if path.name.lower().endswith(suffix) else path.name + ".out"
    dest = out / name
    with opener(path, "rb") as src, dest.open("wb") as dst:
        shutil.copyfileobj(src, dst, length=1024 * 1024)
    return [name]


def _run_checked(cmd: list[str], description: str, *, cwd: Path | None = None) -> None:
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=False, text=True, cwd=cwd)
    if proc.returncode != 0:
        detail = proc.stderr.strip() or proc.stdout.strip()
        raise UnpackError(f"{description} failed: {detail or proc.returncode}")


def _unpack_super(source: Path, target: Path) -> dict:
    exe = shutil.which("lpunpack")
    if not exe:
        raise UnpackError("Android super image detected but lpunpack is not installed")
    _run_checked([exe, str(source), str(target)], "lpunpack")
    return {
        "files": sorted(str(p.relative_to(target)) for p in target.rglob("*") if p.is_file()),
        "action": "super-unpack",
    }


def unpack(path: str | Path, out: str | Path, *, allow_filesystem_extract: bool = False) -> dict:
    source = Path(path)
    target = Path(out)
    if not source.is_file():
        raise UnpackError(f"input is not a regular file: {source}")
    target.mkdir(parents=True, exist_ok=True)
    fmt = detect_format(source)
    result = {"input": str(source), "format": fmt, "output": str(target), "files": [], "action": None}

    if fmt == "zip":
        result["files"] = _extract_zip(source, target)
        result["action"] = "extract"
    elif fmt == "tar":
        result["files"] = _extract_tar(source, target)
        result["action"] = "extract"
    elif fmt in {"gzip", "xz", "bzip2"}:
        result["files"] = _single_stream(source, target, fmt)
        result["action"] = "decompress"
    elif fmt == "zstd":
        exe = shutil.which("zstd")
        if not exe:
            raise UnpackError("zstd stream detected but zstd is not installed")
        name = source.name[:-4] if source.name.lower().endswith(".zst") else source.name + ".out"
        dest = target / name
        with dest.open("wb") as dst:
            proc = subprocess.run([exe, "-q", "-d", "-c", str(source)], stdout=dst, stderr=subprocess.PIPE, text=False, check=False)
        if proc.returncode != 0:
            dest.unlink(missing_ok=True)
            detail = proc.stderr.decode("utf-8", errors="replace").strip()
            raise UnpackError(f"zstd decompression failed: {detail or proc.returncode}")
        result["files"] = [name]
        result["action"] = "decompress"
    elif fmt == "android-sparse":
        exe = shutil.which("simg2img")
        if not exe:
            raise UnpackError("Android sparse image detected but simg2img is not installed")
        raw = target / (source.stem + ".raw.img")
        _run_checked([exe, str(source), str(raw)], "simg2img")
        result["files"] = [raw.name]
        result["action"] = "sparse-to-raw"
    elif fmt == "android-super":
        result.update(_unpack_super(source, target))
    elif fmt == "erofs":
        if not allow_filesystem_extract:
            result["action"] = "detected-only"
            result["reason"] = "EROFS extraction is disabled by default; use --filesystem-extract"
        else:
            exe = shutil.which("fsck.erofs")
            if not exe:
                raise UnpackError("EROFS image detected but fsck.erofs is not installed")
            _run_checked([exe, "--extract=" + str(target), str(source)], "fsck.erofs extraction")
            result["action"] = "erofs-extract"
            result["files"] = sorted(str(p.relative_to(target)) for p in target.rglob("*") if p.is_file())
    elif fmt == "ext4":
        if not allow_filesystem_extract:
            result["action"] = "detected-only"
            result["reason"] = "ext4 extraction is disabled by default; use --filesystem-extract"
        else:
            debugfs = shutil.which("debugfs")
            if not debugfs:
                raise UnpackError("ext4 image detected but debugfs is not installed")
            if any(c.isspace() for c in str(target)):
                raise UnpackError("ext4 extraction output path must not contain whitespace")
            _run_checked([debugfs, "-R", f"rdump / {target}", str(source)], "debugfs rdump")
            result["action"] = "ext4-extract"
            result["files"] = sorted(str(p.relative_to(target)) for p in target.rglob("*") if p.is_file())
    else:
        raise UnpackError(f"format {fmt} has no unpacker")

    return result
