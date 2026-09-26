from __future__ import annotations

import bz2
import gzip
import lzma
import shutil
import subprocess
import tarfile
import zipfile
from pathlib import Path


class PackError(RuntimeError):
    pass


def _run_checked(cmd: list[str], description: str) -> None:
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True, check=False)
    if proc.returncode != 0:
        detail = proc.stderr.strip() or proc.stdout.strip()
        raise PackError(f"{description} failed: {detail or proc.returncode}")


def pack_directory(source: str | Path, target: str | Path, fmt: str) -> dict:
    src = Path(source)
    dst = Path(target)
    if not src.is_dir():
        raise PackError(f"input is not a directory: {src}")
    dst.parent.mkdir(parents=True, exist_ok=True)
    if fmt == "zip":
        with zipfile.ZipFile(dst, "w", compression=zipfile.ZIP_DEFLATED) as zf:
            for path in sorted(src.rglob("*")):
                if path.is_file():
                    zf.write(path, path.relative_to(src).as_posix())
    elif fmt == "tar":
        with tarfile.open(dst, "w") as tf:
            for path in sorted(src.rglob("*")):
                tf.add(path, arcname=path.relative_to(src).as_posix(), recursive=False)
    else:
        raise PackError(f"directory pack format is unsupported: {fmt}")
    return {"input": str(src), "output": str(dst), "format": fmt}


def pack_stream(source: str | Path, target: str | Path, fmt: str) -> dict:
    src = Path(source)
    dst = Path(target)
    if not src.is_file():
        raise PackError(f"input is not a regular file: {src}")
    dst.parent.mkdir(parents=True, exist_ok=True)
    if fmt == "zstd":
        exe = shutil.which("zstd")
        if not exe:
            raise PackError("zstd stream requested but zstd is not installed")
        _run_checked([exe, "-q", "-f", str(src), "-o", str(dst)], "zstd compression")
        return {"input": str(src), "output": str(dst), "format": fmt}
    opener = {"gzip": gzip.open, "xz": lzma.open, "bzip2": bz2.open}.get(fmt)
    if opener is None:
        raise PackError(f"stream pack format is unsupported: {fmt}")
    with src.open("rb") as inp, opener(dst, "wb") as out:
        shutil.copyfileobj(inp, out, length=1024 * 1024)
    return {"input": str(src), "output": str(dst), "format": fmt}


def pack_sparse(source: str | Path, target: str | Path) -> dict:
    src = Path(source)
    dst = Path(target)
    exe = shutil.which("img2simg")
    if not exe:
        raise PackError("raw Android image provided but img2simg is not installed")
    dst.parent.mkdir(parents=True, exist_ok=True)
    _run_checked([exe, str(src), str(dst)], "img2simg")
    return {"input": str(src), "output": str(dst), "format": "android-sparse"}
