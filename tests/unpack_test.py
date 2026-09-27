#!/usr/bin/env python3
from __future__ import annotations

import tempfile
import zipfile
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))

from hico_thermal.pack import pack_directory, pack_stream
from hico_thermal.unpack import UnpackError, unpack


def main() -> int:
    with tempfile.TemporaryDirectory(prefix="hico-unpack-test-") as td:
        root = Path(td)
        source = root / "source"
        (source / "thermal").mkdir(parents=True)
        (source / "thermal/test.conf").write_text("[CPU]\nsensor soc\nthresholds 80000 90000\n")

        archive = root / "thermal.zip"
        pack_directory(source, archive, "zip")
        out = root / "zip-out"
        assert unpack(archive, out)["format"] == "zip"
        assert (out / "thermal/test.conf").is_file()

        tar = root / "thermal.tar"
        pack_directory(source, tar, "tar")
        tar_out = root / "tar-out"
        assert unpack(tar, tar_out)["format"] == "tar"
        assert (tar_out / "thermal/test.conf").is_file()

        gzip_path = root / "thermal.conf.gz"
        plain = root / "thermal.conf"
        plain.write_text("[CPU]\nsensor soc\nthresholds 80000 90000\n")
        pack_stream(plain, gzip_path, "gzip")
        assert unpack(gzip_path, root / "gzip-out")["action"] == "decompress"

        unsafe = root / "unsafe.zip"
        with zipfile.ZipFile(unsafe, "w") as zf:
            zf.writestr("../escape.txt", "must not escape")
        try:
            unpack(unsafe, root / "unsafe-out")
        except UnpackError:
            pass
        else:
            raise AssertionError("path traversal archive was accepted")

    print("HiCo unpack tests: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
