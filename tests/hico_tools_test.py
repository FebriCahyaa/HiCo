#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import subprocess
import shutil
import sys
import tempfile
import zipfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from hico_thermal.artifacts import detect_format
from hico_thermal.codecs import CodecError, CodecRegistry
from hico_thermal.mapping import map_roots, map_tree_deep
from hico_thermal.pack import PackError, pack_directory, pack_stream
from hico_thermal.unpack import UnpackError, unpack


def main() -> int:
    garnet = ROOT / "devices/xiaomi/garnet/thermal/thermal-normal.conf"
    hicod = os.environ.get("HICOD", str(ROOT / "build/hicod"))
    if not garnet.is_file() or not Path(hicod).is_file():
        raise SystemExit("MiCrypt fixture or hicod not available")

    assert detect_format(garnet) == "opaque-binary"
    registry = CodecRegistry(hicod)
    assert {entry["name"] for entry in registry.list()} == {"plain", "mi_thermald_aes"}

    with tempfile.TemporaryDirectory(prefix="hico-tools-test-") as td:
        root = Path(td)
        plain = root / "thermal-normal.conf"
        decoded = root / "decoded.conf"
        encrypted = root / "encrypted.conf"
        data = subprocess.run(
            [hicod, "thermal", "decrypt", str(garnet)],
            check=True,
            stdout=subprocess.PIPE,
        ).stdout
        plain.write_bytes(data)

        codec = registry.get("mi_thermald_aes")
        assert codec.matches(garnet, garnet.read_bytes())
        encoded = codec.encode(data, plain)
        encrypted.write_bytes(encoded)
        assert encrypted.read_bytes() == garnet.read_bytes()

        codec_name, decoded_data = registry.decode(garnet)
        assert codec_name == "mi_thermald_aes"
        decoded.write_bytes(decoded_data)
        assert decoded.read_bytes() == plain.read_bytes()

        plain_source = root / "plain.conf"
        plain_source.write_text("[CPU]\nsensor soc\nthresholds 80000 90000\n")
        plain_codec_name, plain_data = registry.decode(plain_source)
        assert plain_codec_name == "plain"
        assert plain_data == plain_source.read_bytes()
        assert registry.encode(plain_source, plain_data)[1] == plain_data

        safe_dir = root / "safe"
        (safe_dir / "thermal").mkdir(parents=True)
        (safe_dir / "thermal/test.conf").write_text("[CPU]\nsensor soc\nthresholds 80000 90000\n")
        safe_zip = root / "safe.zip"
        pack_directory(safe_dir, safe_zip, "zip")
        out = root / "unpacked"
        result = unpack(safe_zip, out)
        assert result["format"] == "zip"
        assert (out / "thermal/test.conf").is_file()

        safe_tar = root / "safe.tar"
        pack_directory(safe_dir, safe_tar, "tar")
        tar_out = root / "tar-out"
        assert unpack(safe_tar, tar_out)["format"] == "tar"
        assert (tar_out / "thermal/test.conf").is_file()

        zstd_path = root / "plain.conf.zst"
        if shutil.which("zstd"):
            from hico_thermal.pack import pack_stream
            pack_stream(plain_source, zstd_path, "zstd")
            assert unpack(zstd_path, root / "zstd-out")["format"] == "zstd"

        gzip_path = root / "plain.conf.gz"
        pack_stream(plain_source, gzip_path, "gzip")
        assert unpack(gzip_path, root / "gzip-out")["action"] == "decompress"

        unsafe_zip = root / "unsafe.zip"
        with zipfile.ZipFile(unsafe_zip, "w") as zf:
            zf.writestr("../escape.txt", "do not write outside")
        try:
            unpack(unsafe_zip, root / "unsafe")
        except UnpackError:
            pass
        else:
            raise AssertionError("path traversal archive was accepted")

        map_result = map_roots([ROOT / "devices/xiaomi/garnet/thermal"], hicod=hicod, decode=True)
        assert map_result["summary"]["decoded"] > 0
        assert not map_result["failures"]

        nested = root / "nested"
        (nested / "payload" / "thermal").mkdir(parents=True)
        (nested / "payload" / "thermal" / "nested.conf").write_text("[CPU]\nsensor soc\nthresholds 80000 90000\n")
        nested_zip = root / "nested.zip"
        pack_directory(nested, nested_zip, "zip")
        deep = map_tree_deep(root, hicod=hicod, decode=True, max_depth=1)
        assert deep["summary"]["expanded_containers"] >= 1
        assert any("origin_container" in item for item in deep["artifacts"])
        assert not deep["failures"]

        assert detect_format(plain_source) == "thermal-engine-text"
        assert detect_format(garnet) == "opaque-binary"
        assert CodecError and PackError

    print("HiCo thermal tools tests: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
