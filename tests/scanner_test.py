#!/usr/bin/env python3
#
# Copyright (C) 2026 FebriCahyaa
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
"""Tests for tools/xiaomi_devices.py.

Fixtures are synthetic and use codenames that do not exist ("testdev_*"), so
test data can never be mistaken for a real device profile.
"""

import http.server
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

FIXTURE = {
    "testdev_a": {
        "vendor/build.prop": "ro.product.vendor.device=testdev_a\nro.product.vendor.brand=redmi\n"
        "ro.product.vendor.model=TEST-A\nro.board.platform=testsoc\nro.vendor.build.version.release=14\n",
        "product/etc/build.prop": "ro.product.product.marketname=Test Phone A\n",
        "vendor/etc/thermal-normal.conf": "",
        "vendor/etc/thermal-tgame.conf": "",
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
    "broken": {"README": "no partitions here"},
}


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
        self.assertEqual(a["android"], "14")
        self.assertEqual(a["mi_thermald"], "1")
        self.assertEqual(a["thermal_services"], "mi_thermald,vendor.thermal-hal")  # camera rc not read
        self.assertEqual(a["thermal_configs"], "thermal-normal.conf,thermal-tgame.conf")
        self.assertIn(source_hint, a["source"])

        b = read_prop(out / "devices/xiaomi/testdev_b.prop")
        self.assertEqual(b["thermal_services"], "thermal-engine")  # invalid service name dropped
        self.assertEqual(b["mi_thermald"], "0")

        self.assertFalse((out / "devices/xiaomi/broken.prop").exists())
        doc = (out / "docs/DEVICES.md").read_text()
        self.assertIn("**2 devices**", doc)
        self.assertIn("| Redmi Test Phone A | `testdev_a` |", doc)

    def test_local(self):
        with tempfile.TemporaryDirectory() as tmp:
            dumps, out = Path(tmp, "dumps"), Path(tmp, "out")
            make_fixture(dumps)
            r = run_tool("--local", str(dumps), "--out", str(out))
            self.assertEqual(r.returncode, 0, r.stderr)
            self.check_output(out, "testdev_a")

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


class FakeGitLab(http.server.BaseHTTPRequestHandler):
    """Just enough of GitLab's v4 API, with pagination (one project and one tree entry per page)."""

    projects = sorted(FIXTURE)

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
            return self.send([{"id": page, "path": name, "default_branch": "main-branch",
                               "web_url": f"{base}/dumps/xiaomi/{name}"}], {"X-Next-Page": nxt})

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
