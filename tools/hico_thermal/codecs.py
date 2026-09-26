from __future__ import annotations

import subprocess
import tempfile
from abc import ABC, abstractmethod
from pathlib import Path

from .artifacts import detect_format, is_probably_text


class CodecError(RuntimeError):
    pass


class Codec(ABC):
    name: str
    can_encode: bool = False
    can_decode: bool = False

    @abstractmethod
    def matches(self, path: Path, data: bytes) -> bool:
        raise NotImplementedError

    def decode(self, data: bytes, path: Path) -> bytes:
        raise CodecError(f"codec {self.name} does not support decode")

    def encode(self, data: bytes, path: Path) -> bytes:
        raise CodecError(f"codec {self.name} does not support encode")


class PlainCodec(Codec):
    name = "plain"
    can_encode = True
    can_decode = True

    def matches(self, path: Path, data: bytes) -> bool:
        return detect_format(path, data) in {"text", "thermal-engine-text", "json", "xml"}

    def decode(self, data: bytes, path: Path) -> bytes:
        if not is_probably_text(data):
            raise CodecError("plain codec only accepts text")
        return data

    def encode(self, data: bytes, path: Path) -> bytes:
        if not is_probably_text(data):
            raise CodecError("plain codec only accepts text")
        return data


class MiThermaldCodec(Codec):
    """Adapter for Xiaomi's existing mi_thermald AES format via hicod MiCrypt."""

    name = "mi_thermald_aes"
    can_encode = True
    can_decode = True

    def __init__(self, hicod: str | Path):
        self.hicod = str(hicod)

    def matches(self, path: Path, data: bytes) -> bool:
        normalized = str(path).replace("\\", "/").lower()
        if path.suffix.lower() != ".conf":
            return False
        if is_probably_text(data) or not data or len(data) % 16:
            return False
        return "thermal" in path.name.lower() or "thermald" in path.name.lower() or "/thermal/" in normalized

    def _run(self, mode: str, data: bytes, path: Path) -> bytes:
        with tempfile.TemporaryDirectory(prefix="hico-codec-") as td:
            source = Path(td) / path.name
            target = Path(td) / (path.name + ".out")
            source.write_bytes(data)
            proc = subprocess.run(
                [self.hicod, "thermal", mode, str(source), str(target)],
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                timeout=30,
                check=False,
            )
            if proc.returncode != 0 or not target.is_file():
                detail = proc.stderr.decode("utf-8", errors="replace").strip()
                raise CodecError(f"hicod thermal {mode} failed for {path}: {detail or proc.returncode}")
            return target.read_bytes()

    def decode(self, data: bytes, path: Path) -> bytes:
        plain = self._run("decrypt", data, path)
        if not is_probably_text(plain):
            raise CodecError("not an encrypted mi_thermald config")
        return plain

    def encode(self, data: bytes, path: Path) -> bytes:
        if not is_probably_text(data):
            raise CodecError("mi_thermald encoder requires plaintext config")
        return self._run("encrypt", data, path)


class CodecRegistry:
    def __init__(self, hicod: str | Path | None = None):
        self._codecs: list[Codec] = [PlainCodec()]
        if hicod:
            self._codecs.append(MiThermaldCodec(hicod))

    def list(self) -> list[dict]:
        return [{"name": c.name, "can_encode": c.can_encode, "can_decode": c.can_decode} for c in self._codecs]

    def get(self, name: str) -> Codec:
        for codec in self._codecs:
            if codec.name == name:
                return codec
        raise CodecError(f"unknown codec {name}; available: {', '.join(c.name for c in self._codecs)}")

    def candidates(self, path: Path, data: bytes) -> list[Codec]:
        return [codec for codec in reversed(self._codecs) if codec.matches(path, data)]

    def find(self, path: Path, data: bytes) -> Codec | None:
        candidates = self.candidates(path, data)
        return candidates[0] if candidates else None

    def decode(self, path: Path, codec_name: str | None = None) -> tuple[str, bytes]:
        data = path.read_bytes()
        codec = self.get(codec_name) if codec_name else self.find(path, data)
        if codec is None or not codec.can_decode:
            raise CodecError(f"no decoder for {path}")
        return codec.name, codec.decode(data, path)

    def encode(self, path: Path, data: bytes, codec_name: str | None = None) -> tuple[str, bytes]:
        if codec_name:
            codec = self.get(codec_name)
        else:
            original = path.read_bytes()
            codec = self.find(path, original)
        if codec is None or not codec.can_encode:
            raise CodecError(f"no encoder for {path}")
        return codec.name, codec.encode(data, path)
