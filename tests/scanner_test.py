#!/usr/bin/env python3
#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
#
"""Tests for tools/xiaomi_devices.py.

Fixtures are synthetic and use codenames that do not exist ("testdev_*"), so
test data can never be mistaken for a real device profile.
"""

import http.server
import importlib.util
import os
import json
import subprocess
import sys
import tempfile
import threading
import unittest
import urllib.parse
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
TOOL = ROOT / "tools" / "xiaomi_devices.py"

NORMAL_CONF = """\
# comment
[SKIN_MONITOR]
algo_type monitor
sensor quiet_therm
thresholds 41000 43000 45000
thresholds_clr 39000 41000 43000
actions cpu+gpu cpu+gpu cpu+gpu

[SHUTDOWN]
algo_type monitor
sensor battery
thresholds 60000
actions shutdown
"""
ENCRYPTED_CONF = "\x00\x13\x9f\x82binary\x01\x02\x03" * 20

FIXTURE = {
    "testdev_a": {
        # GRF: the vendor partition keeps its launch release (12), the system runs 14.
        "vendor/build.prop": "ro.product.vendor.device=testdev_a\nro.product.vendor.brand=redmi\n"
        "ro.product.vendor.model=TEST-A\nro.board.platform=testsoc\nro.vendor.build.version.release=12\n",
        "system/system/build.prop": "ro.system.build.version.release=14\n",
        "odm/etc/build.prop": "ro.product.odm.marketname=Test Phone A\n",
        # Qualcomm style: thermal-engine declared in a general init script.
        "vendor/etc/init/hw/init.qcom.rc": "service thermal-engine /vendor/bin/thermal-engine\n"
        "service qcom-sh /vendor/bin/init.qcom.sh\n",
        # Plain-text thermal-engine syntax (millidegrees) and an encrypted config.
        "vendor/etc/thermal-normal.conf": NORMAL_CONF,
        "vendor/etc/thermal-tgame.conf": ENCRYPTED_CONF,
        "vendor/etc/media_codecs.xml": "",
        "vendor/etc/init/init.mi_thermald.rc": "service mi_thermald /vendor/bin/mi_thermald\n    class main\n",
        "vendor/etc/init/android.hardware.thermal-service.rc":
            "service vendor.thermal-hal /vendor/bin/hw/android.hardware.thermal-service\n",
        "vendor/etc/init/init.camera.rc": "service camera /vendor/bin/camera\n",
    },
    "testdev_b": {
        "vendor/build.prop": "ro.product.vendor.device=testdev_b\nro.product.vendor.brand=POCO\nro.product.vendor.model=TEST-B\n",
        "vendor/etc/init/thermal-engine.rc": "service thermal-engine /vendor/bin/thermal-engine\n"
        "service bad;name /x\n",
    },
    # Pre-Treble dump: no vendor partition, everything under system/.
    "testdev_c": {
        "system/build.prop": "ro.product.device=testdev_c\nro.product.brand=Xiaomi\nro.product.model=TEST-C\n"
        "ro.build.version.release=7.1.1\n",
        "system/etc/thermal-engine.conf": "[CPU_MONITOR]\nalgo_type monitor\nsensor tsens_tz_sensor5\n"
        "thresholds 70 80\nactions cpu cpu\n",
    },
    # Regional variant of testdev_a with less thermal information: listed, not a second record.
    "testdev_a_global": {
        "vendor/build.prop": "ro.product.vendor.device=testdev_a\nro.product.vendor.brand=redmi\n",
    },
    "broken": {"README": "no partitions here"},
}

# Large files every real dump has; sparse mode must never download them.
BULK = {
    "system/system/app/Big/Big.apk": 2 * 1024 * 1024,
    "vendor/firmware/modem.bin": 1024 * 1024,
}


def git(*args, cwd=None):
    subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True,
                   env={**os.environ, "GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t",
                        "GIT_COMMITTER_NAME": "t", "GIT_COMMITTER_EMAIL": "t@t"})


def make_bare_repos(root: Path, allow_filter: bool = True) -> dict:
    """One bare repository per fixture project (branch main-branch), plus bulk files."""
    urls = {}
    for project, files in FIXTURE.items():
        work = root / "work" / project
        for rel, content in files.items():
            f = work / rel
            f.parent.mkdir(parents=True, exist_ok=True)
            f.write_text(content)
        for rel, size in BULK.items():
            f = work / rel
            f.parent.mkdir(parents=True, exist_ok=True)
            f.write_bytes(os.urandom(size))
        git("init", "-q", "-b", "main-branch", str(work))
        git("add", "-A", cwd=work)
        git("commit", "-qm", "dump", cwd=work)
        bare = root / "bare" / f"{project}.git"
        git("clone", "-q", "--bare", str(work), str(bare))
        git("config", "uploadpack.allowFilter", "true" if allow_filter else "false", cwd=bare)
        urls[project] = f"file://{bare}"
    return urls


def load_tool():
    spec = importlib.util.spec_from_file_location("xiaomi_devices", TOOL)
    mod = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = mod  # dataclasses look the module up while it loads
    spec.loader.exec_module(mod)
    return mod


def make_fixture(root: Path) -> None:
    for project, files in FIXTURE.items():
        for rel, content in files.items():
            f = root / project / rel
            f.parent.mkdir(parents=True, exist_ok=True)
            f.write_text(content)


def run_tool(*args: str) -> subprocess.CompletedProcess:
    return subprocess.run([sys.executable, str(TOOL), *args], capture_output=True, text=True, timeout=120)


def read_prop(path: Path) -> dict:
    return dict(line.split("=", 1) for line in path.read_text().splitlines() if line and not line.startswith("#"))


class ScannerTest(unittest.TestCase):
    def check_output(self, out: Path, source_hint: str) -> None:
        a = read_prop(out / "devices/xiaomi/testdev_a.prop")
        self.assertEqual(a["codename"], "testdev_a")
        self.assertEqual(a["brand"], "Redmi")
        self.assertEqual(a["model"], "Test Phone A")  # market name preferred over model number
        self.assertEqual(a["platform"], "testsoc")
        self.assertEqual(a["android"], "14")  # system release, not the vendor launch release
        self.assertEqual(a["mi_thermald"], "1")
        # camera rc not read; from init.qcom.rc only the thermal service
        self.assertEqual(a["thermal_services"], "mi_thermald,thermal-engine,vendor.thermal-hal")
        self.assertEqual(a["thermal_configs"], "thermal-normal.conf,thermal-tgame.conf")
        self.assertEqual((a["thermal_files"], a["thermal_parsed"], a["thermal_encrypted"]), ("2", "1", "1"))
        self.assertEqual((a["vendor_max_trip_c"], a["vendor_shutdown_c"]), ("45", "60"))

        # The vendor files themselves are kept, with an index for review.
        tdir = out / "devices/xiaomi/testdev_a/thermal"
        self.assertEqual((tdir / "thermal-normal.conf").read_text(), NORMAL_CONF)
        self.assertEqual((tdir / "thermal-tgame.conf").read_bytes(), ENCRYPTED_CONF.encode())  # byte-exact
        index = (tdir / "index.tsv").read_text()
        self.assertRegex(index, r"thermal-normal.conf\t[0-9a-f]{64}\t\d+\ttext\t2\t45\t60")
        self.assertRegex(index, r"thermal-tgame.conf\t[0-9a-f]{64}\t\d+\tencrypted\t0\t\t")
        self.assertIn(source_hint, a["source"])

        b = read_prop(out / "devices/xiaomi/testdev_b.prop")
        self.assertEqual(b["thermal_services"], "thermal-engine")  # invalid service name dropped
        self.assertEqual(b["mi_thermald"], "0")

        c = read_prop(out / "devices/xiaomi/testdev_c.prop")
        self.assertEqual((c["model"], c["android"]), ("TEST-C", "7.1.1"))
        # Pre-Treble thermal config found under system/etc, trips in plain degrees.
        self.assertEqual((c["thermal_configs"], c["vendor_max_trip_c"]), ("thermal-engine.conf", "80"))

        self.assertFalse((out / "devices/xiaomi/broken.prop").exists())
        doc = (out / "docs/DEVICES.md").read_text()
        self.assertIn("**3 devices with a profile**, 1 more dumps listed below without one, "
                      "1 more dumps of listed devices", doc)
        self.assertIn("## Dumps without a profile", doc)
        self.assertRegex(doc, r"\| \[(xiaomi/)?broken\]\(.*\) \| no build.prop with a device codename")
        # Every dump is named: the variant is listed under its device.
        self.assertIn("## Other dumps of listed devices", doc)
        self.assertRegex(doc, r"\| \[(xiaomi/)?testdev_a_global\]\(.*\) \| `testdev_a` \|")
        self.assertIn("2 (1 text, 1 encrypted) | 45 / 60 °C", doc)
        self.assertIn("| Redmi Test Phone A | `testdev_a` |", doc)

    def test_local(self):
        with tempfile.TemporaryDirectory() as tmp:
            dumps, out = Path(tmp, "dumps"), Path(tmp, "out")
            make_fixture(dumps)
            r = run_tool("--local", str(dumps), "--out", str(out))
            self.assertEqual(r.returncode, 0, r.stderr)
            self.check_output(out, "testdev_a")

    def test_missing_group_is_skipped(self):
        server = http.server.ThreadingHTTPServer(("127.0.0.1", 0), FakeGitLab)
        threading.Thread(target=server.serve_forever, daemon=True).start()
        try:
            with tempfile.TemporaryDirectory() as tmp:
                base = f"http://127.0.0.1:{server.server_address[1]}"
                r = run_tool("--gitlab", base, "--group", "dumps/nope,dumps/xiaomi", "--out", str(Path(tmp, "out")))
                self.assertEqual(r.returncode, 0, r.stderr)
                self.assertIn("group dumps/nope not found", r.stderr)
                self.assertTrue(Path(tmp, "out/devices/xiaomi/testdev_a.prop").exists())
                r = run_tool("--gitlab", base, "--group", "dumps/nope", "--out", str(Path(tmp, "out2")))
                self.assertNotEqual(r.returncode, 0)  # no group at all is an error, not an empty database
        finally:
            server.shutdown()
            server.server_close()

    def test_thermal_parser(self):
        mod = load_tool()
        a = mod.analyze_thermal
        self.assertEqual(a("x.conf", b"")["format"], "empty")
        self.assertEqual(a("thermal-map.xml", b"<map/>")["format"], "xml")
        self.assertEqual(a("thermal_info_config.json", b'{"Sensors": []}')["format"], "json")
        self.assertEqual(a("thermal.conf", b"just some words\n")["format"], "text-unknown")
        # Threshold lines before any [section] are ignored instead of crashing.
        r = a("t.conf", b"thresholds 50000\n[S]\nthresholds 45000 999999\nactions cpu\n")
        self.assertEqual((r["format"], r["sections"], r["max_trip_c"]), ("text", 1, 45))  # 999 C rejected
        # set_point (ss algorithm) counts as a trip; shutdown thresholds are reported separately.
        r = a("t.conf", b"[SS]\nalgo_type ss\nset_point 52000\n[OFF]\nthresholds 115000\nactions shutdown\n")
        self.assertEqual((r["max_trip_c"], r["shutdown_c"]), (52, 115))

    def test_long_source_url_is_kept(self):
        mod = load_tool()
        url = "https://dumps.tadiphone.dev/dumps/xiaomi/testdev/-/tree/" + "x" * 150 + "-release-keys"
        prop = mod.Device(codename="testdev", source=url).to_prop()
        self.assertIn(f"source={url}\n", prop)

    def test_gitlab_api(self):
        server = http.server.ThreadingHTTPServer(("127.0.0.1", 0), FakeGitLab)
        threading.Thread(target=server.serve_forever, daemon=True).start()
        try:
            with tempfile.TemporaryDirectory() as tmp:
                out = Path(tmp, "out")
                base = f"http://127.0.0.1:{server.server_address[1]}"
                r = run_tool("--gitlab", base, "--group", "dumps/xiaomi", "--out", str(out))
                self.assertEqual(r.returncode, 0, r.stderr)
                self.check_output(out, f"{base}/dumps/xiaomi/testdev_a/-/tree/main-branch")
        finally:
            server.shutdown()
            server.server_close()


    def run_sparse(self, allow_filter: bool) -> tuple[subprocess.CompletedProcess, Path]:
        tmp = Path(tempfile.mkdtemp())
        FakeGitLab.git_urls = make_bare_repos(tmp, allow_filter)
        server = http.server.ThreadingHTTPServer(("127.0.0.1", 0), FakeGitLab)
        threading.Thread(target=server.serve_forever, daemon=True).start()
        try:
            base = f"http://127.0.0.1:{server.server_address[1]}"
            out = tmp / "out"
            r = run_tool("--gitlab", base, "--sparse", "--group", "dumps/xiaomi", "--out", str(out),
                         "--workdir", str(tmp))
            self.base = base
            return r, out
        finally:
            server.shutdown()
            server.server_close()
            FakeGitLab.git_urls = {}

    def test_sparse_clone(self):
        r, out = self.run_sparse(allow_filter=True)
        self.assertEqual(r.returncode, 0, r.stderr)
        self.check_output(out, f"{self.base}/dumps/xiaomi/testdev_a/-/tree/main-branch")
        leftovers = [p for p in out.parent.iterdir() if p.name.startswith("hico-dump-")]
        self.assertEqual(leftovers, [])  # clones are removed

    def test_sparse_downloads_only_needed_files(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            urls = make_bare_repos(tmp)
            mod = load_tool()
            kept = {}
            mod.shutil.rmtree = lambda path, **kw: kept.setdefault("dir", path)  # keep the clone for inspection
            src = mod.SparseGitSource("http://unused", "dumps/xiaomi", None, workdir=str(tmp))
            dev = src.scan_project({"id": 1, "path": "testdev_a", "branch": "main-branch",
                                    "url": "u", "git_url": urls["testdev_a"]})
            self.assertEqual(dev.codename, "testdev_a")
            repo = Path(kept["dir"]) / "repo"
            checked_out = sorted(str(p.relative_to(repo)) for p in repo.rglob("*")
                                 if p.is_file() and ".git" not in p.parts)
            self.assertEqual(checked_out, [
                "odm/etc/build.prop",
                "system/system/build.prop",
                "vendor/build.prop",
                "vendor/etc/init/android.hardware.thermal-service.rc",
                "vendor/etc/init/hw/init.qcom.rc",
                "vendor/etc/init/init.mi_thermald.rc",
                "vendor/etc/thermal-normal.conf",
                "vendor/etc/thermal-tgame.conf",
            ])
            # The bulk blobs were never fetched: the object store is far smaller than one of them.
            size = sum(p.stat().st_size for p in (repo / ".git").rglob("*") if p.is_file())
            self.assertLess(size, 512 * 1024)
            for rel in BULK:
                missing = subprocess.run(["git", "cat-file", "-e", f"HEAD:{rel}"], cwd=repo,
                                         capture_output=True, env={**os.environ, "GIT_NO_LAZY_FETCH": "1"})
                self.assertNotEqual(missing.returncode, 0, rel)

    def test_git_watchdog_kills_silent_hang(self):
        mod = load_tool()
        src = mod.SparseGitSource("http://unused", "dumps/xiaomi", None, timeout=1)
        with tempfile.TemporaryDirectory() as tmp:
            # An alias that sleeps without output, like a stalled network fetch.
            with self.assertRaisesRegex(RuntimeError, "timed out"):
                src._git("-c", "alias.stall=!sleep 30", "stall", cwd=tmp)

    def test_sparse_refuses_full_download(self):
        r, out = self.run_sparse(allow_filter=False)
        doc = (out / "docs/DEVICES.md").read_text()
        self.assertIn("server ignores --filter", doc)
        self.assertFalse((out / "devices/xiaomi/testdev_a.prop").exists())


GEN = ROOT / "tools" / "gen_device_db.py"


def run_gen(*args: str) -> subprocess.CompletedProcess:
    return subprocess.run([sys.executable, str(GEN), *args], capture_output=True, text=True, timeout=60)


class GeneratorTest(unittest.TestCase):
    """tools/gen_device_db.py: devices/xiaomi/*.prop -> compiled C++ table."""

    def write_profiles(self, root: Path) -> Path:
        data = root / "devices"
        data.mkdir()
        (data / "testdev_b.prop").write_text(
            "codename=testdev_b\nbrand=POCO\nmodel=Evil \"quoted\" \\ name\nplatform=mt6893\nandroid=14\n"
            "source=https://example.invalid/" + "x" * 300 + "\nthermal_services=thermal_manager,bad;name,thermal\n"
            "thermal_configs=thermal-tgame.conf,../escape.conf\n")
        (data / "testdev_a.prop").write_text(
            "codename=testdev_a\nbrand=Redmi\nmodel=Test A\nplatform=taro\nandroid=15\nsource=https://example.invalid/a\n"
            "thermal_services=\nthermal_configs=\n")
        return data

    def test_generates_compilable_sorted_table(self):
        with tempfile.TemporaryDirectory() as tmp:
            tmp = Path(tmp)
            data = self.write_profiles(tmp)
            out = tmp / "gen.cpp"
            r = run_gen("--data", str(data), "--output", str(out))
            self.assertEqual(r.returncode, 0, r.stderr)
            text = out.read_text()

            self.assertLess(text.index('"testdev_a"sv'), text.index('"testdev_b"sv'))  # sorted
            self.assertIn(r'"Evil \"quoted\" \\ name"sv', text)                      # escaped
            self.assertIn('"thermal"sv, "thermal_manager"sv', text)                    # sorted, valid only
            self.assertNotIn("bad;name", text)
            self.assertNotIn("escape.conf", text)
            self.assertIn("x" * 300, text)                                             # long source kept
            self.assertIn("(2 devices)", text)

            # Deterministic: a second run is byte-identical and --check passes.
            before = text
            run_gen("--data", str(data), "--output", str(out))
            self.assertEqual(out.read_text(), before)
            self.assertEqual(run_gen("--data", str(data), "--output", str(out), "--check").returncode, 0)

            # It is valid C++ against the real header, with a lookup that finds both records.
            probe = tmp / "probe.cpp"
            probe.write_text(
                '#include "DeviceDatabase.hpp"\n#include <cstdio>\n'
                'int main() { auto db = hico::device_db::records();\n'
                '  return db.size() == 2 && db[0].codename == "testdev_a" && db[1].services.size() == 2 '
                '&& db[0].services.empty() ? 0 : 1; }\n')
            cxx = os.environ.get("CXX", "c++")
            build = subprocess.run([cxx, "-std=c++20", "-Wall", "-Wextra", "-Werror", f"-I{ROOT / 'jni/include'}",
                                    str(out), str(probe), "-o", str(tmp / "probe")], capture_output=True, text=True)
            self.assertEqual(build.returncode, 0, build.stderr)
            self.assertEqual(subprocess.run([str(tmp / "probe")]).returncode, 0)

            # Stale table: --check fails.
            (data / "testdev_a.prop").write_text((data / "testdev_a.prop").read_text().replace("Test A", "Test A2"))
            self.assertEqual(run_gen("--data", str(data), "--output", str(out), "--check").returncode, 1)

    def test_rejects_mismatched_codename(self):
        with tempfile.TemporaryDirectory() as tmp:
            data = Path(tmp)
            (data / "renamed.prop").write_text("codename=other\n")
            r = run_gen("--data", str(data), "--output", str(data / "gen.cpp"))
            self.assertEqual(r.returncode, 1)
            self.assertIn("does not match the file name", r.stderr)

    def test_repository_table_is_current(self):
        r = run_gen("--check")
        self.assertEqual(r.returncode, 0, r.stderr)


HICOD = Path(os.environ.get("HICOD", ROOT / "build" / "hicod"))


@unittest.skipUnless(HICOD.exists(), "host hicod not built (cmake --build build)")
class TuneThermalTest(unittest.TestCase):
    """tools/tune_thermal.py drives the host hicod over collected firmware files."""

    def test_tunes_and_verifies_per_chipset(self):
        with tempfile.TemporaryDirectory() as tmp:
            data = Path(tmp, "data")
            conf = "[SKIN]\nalgo_type monitor\nsensor quiet_therm\nthresholds 41000 43000\n" \
                   "thresholds_clr 39000 41000\nactions cpu cpu\n[OFF]\nalgo_type monitor\nsensor quiet_therm\n" \
                   "thresholds 70000\nactions shutdown\n"
            for codename, platform in (("testqc", "taro"), ("testmtk", "mt6765")):
                (data / codename / "thermal").mkdir(parents=True)
                (data / f"{codename}.prop").write_text(f"codename={codename}\nbrand=Xiaomi\nplatform={platform}\n")
                (data / codename / "thermal" / "thermal-engine.conf").write_text(conf)
            (data / "testqc" / "thermal" / "thermal-tgame.conf").write_bytes(b"\x00\x13\x9fencrypted")
            (data / "testqc" / "thermal" / "thermal_info_config.json").write_text(
                '{"Sensors":[{"Name":"cpu-1-0-usr","Type":"CPU","HotThreshold":["NAN","NAN","NAN",95.0,"NAN","NAN",125.0]}]}')

            report = Path(tmp, "REPORT.md")
            r = subprocess.run([sys.executable, str(ROOT / "tools" / "tune_thermal.py"), "--hicod", str(HICOD),
                                "--data", str(data), "--report", str(report)], capture_output=True, text=True)
            self.assertEqual(r.returncode, 0, r.stderr)
            qc = (data / "testqc/tuned/thermal-engine.conf").read_text()
            mtk = (data / "testmtk/tuned/thermal-engine.conf").read_text()
            self.assertIn("thresholds 47000 49000", qc)   # Qualcomm flagship: +6 C
            self.assertIn("thresholds 45000 47000", mtk)  # MediaTek (non-Dimensity): +4 C
            self.assertIn("thresholds 70000\nactions shutdown", qc)  # shutdown untouched
            self.assertFalse((data / "testqc/tuned/thermal-tgame.conf").exists())  # encrypted: not tuned
            hal = (data / "testqc/tuned/thermal_info_config.json").read_text()
            self.assertIn('"NAN",101.0,"NAN","NAN",125.0', hal)  # thermal HAL JSON: SEVERE +6, SHUTDOWN kept
            text = report.read_text()
            self.assertIn("| `testqc` | taro | qualcomm-flagship | 6 °C | 3 | 2 | 2 | 2 of 3 |", text)
            self.assertIn("| `testmtk` | mt6765 | mediatek | 4 °C | 1 | 1 | 1 | 1 of 2 |", text)


class FakeGitLab(http.server.BaseHTTPRequestHandler):
    """Just enough of GitLab's v4 API, with pagination (one project and one tree entry per page)."""

    projects = sorted(FIXTURE)
    git_urls: dict = {}

    def log_message(self, *args):
        pass

    def send(self, body, headers=None, code=200):
        data = body if isinstance(body, bytes) else json.dumps(body).encode()
        self.send_response(code)
        for k, v in (headers or {}).items():
            self.send_header(k, v)
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def do_GET(self):
        url = urllib.parse.urlparse(self.path)
        q = dict(urllib.parse.parse_qsl(url.query))
        page = int(q.get("page", 1))
        parts = url.path.split("/")

        if url.path == "/api/v4/groups/dumps%2Fxiaomi/projects":
            name = self.projects[page - 1]
            nxt = str(page + 1) if page < len(self.projects) else ""
            base = f"http://{self.headers['Host']}"
            item = {"id": page, "path": name, "default_branch": "main-branch", "web_url": f"{base}/dumps/xiaomi/{name}"}
            if name in self.git_urls:
                item["http_url_to_repo"] = self.git_urls[name]
            return self.send([item], {"X-Next-Page": nxt})

        if len(parts) > 6 and parts[3] == "projects":
            project = self.projects[int(parts[4]) - 1]
            files = FIXTURE[project]
            if q.get("ref") != "main-branch":
                return self.send({"message": "ref"}, code=404)
            if parts[5:7] == ["repository", "tree"]:
                prefix = q["path"].rstrip("/") + "/"
                entries = sorted(f[len(prefix):] for f in files if f.startswith(prefix) and "/" not in f[len(prefix):])
                if not entries:
                    return self.send({"message": "404 Tree Not Found"}, code=404)
                entry = entries[page - 1 : page]
                nxt = str(page + 1) if page < len(entries) else ""
                return self.send([{"name": n, "type": "blob"} for n in entry], {"X-Next-Page": nxt})
            if parts[5:7] == ["repository", "files"] and parts[-1] == "raw":
                path = urllib.parse.unquote(parts[7])
                if path in files:
                    return self.send(files[path].encode())
                return self.send({"message": "404 File Not Found"}, code=404)
        self.send({"message": "not found"}, code=404)


if __name__ == "__main__":
    unittest.main(verbosity=2)
