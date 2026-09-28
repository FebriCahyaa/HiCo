#!/usr/bin/env python3
"""Offline tests for tools/ingest/*: real git repositories on file:// URLs.

Covers the whole delta cycle (fetch -> upstream commit -> diff -> refetch),
stale-file removal, empty repositories, failure bookkeeping, the repo-tool
manifest parser, repository identity rules and the PyYAML-free loader.
"""
from __future__ import annotations

import json
import os
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools" / "ingest"))
sys.path.insert(0, str(ROOT / "tools" / "verify"))

import common  # noqa: E402
import diff_manifests  # noqa: E402
import list_device_repos  # noqa: E402
import merge_fetch  # noqa: E402
import rom_sources  # noqa: E402
import sparse_fetch  # noqa: E402

GIT_ENV = {**os.environ, "GIT_AUTHOR_NAME": "t", "GIT_AUTHOR_EMAIL": "t@t", "GIT_COMMITTER_NAME": "t",
           "GIT_COMMITTER_EMAIL": "t@t", "GIT_CONFIG_NOSYSTEM": "1"}


def git(*args: str, cwd: Path) -> str:
    return subprocess.run(["git", *args], cwd=cwd, check=True, capture_output=True, text=True,
                          env=GIT_ENV).stdout.strip()


class Upstream:
    """A work tree plus a bare repository served over file:// (filters allowed)."""

    def __init__(self, base: Path, name: str):
        self.work = base / f"{name}-work"
        self.bare = base / f"{name}.git"
        self.work.mkdir()
        git("init", "-q", "-b", "main", cwd=self.work)
        subprocess.run(["git", "init", "-q", "--bare", "-b", "main", str(self.bare)], check=True, env=GIT_ENV)
        git("config", "uploadpack.allowFilter", "true", cwd=self.bare)
        git("config", "uploadpack.allowAnySHA1InWant", "true", cwd=self.bare)
        self.url = self.bare.resolve().as_uri()

    def commit(self, files: dict[str, str | None], msg: str = "c") -> str:
        for rel, text in files.items():
            p = self.work / rel
            if text is None:
                p.unlink()
                continue
            p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text(text)
        git("add", "-A", cwd=self.work)
        git("commit", "-q", "-m", msg, cwd=self.work)
        git("push", "-q", str(self.bare), "main", cwd=self.work)
        return git("rev-parse", "HEAD", cwd=self.work)


SOURCE = {"id": "testrom", "family": "rom"}
DATA = {"thermal_paths": ["**/thermal/**", "**/thermal-engine*.conf", "device.mk"]}


class DeltaCycle(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        base = Path(self.tmp.name)
        self.stock = base / "stock"
        self.manifests = self.stock / "manifest"
        self.manifests.mkdir(parents=True)
        self.up = Upstream(base, "android_device_acme_rocket")
        self.sha1 = self.up.commit({
            "device.mk": "PRODUCT_NAME := rocket\n",
            "configs/thermal/thermal_info_config.json": '{"Sensors": []}',
            "rootdir/etc/thermal-engine.conf": "[CPU]\nalgo_type monitor\n",
            "README.md": "not wanted",
        })
        self.dev = {"vendor": "acme", "codename": "rocket", "kind": "device", "repo": "android_device_acme_rocket",
                    "clone_url": self.up.url, "default_branch": "main", "updated_at": "2026-01-01T00:00:00Z"}
        self.write_manifest([self.dev])

    def tearDown(self):
        self.tmp.cleanup()

    def write_manifest(self, devices):
        (self.manifests / "testrom.json").write_text(json.dumps({"devices": devices}))
        (self.manifests / "index.json").write_text(json.dumps({"sources": [{"source_id": "testrom"}]}))

    def fetch(self, only=None):
        return sparse_fetch.run_source(SOURCE, DATA, jobs=2, limit=None, only_keys=only, refetch=False,
                                       stock=self.stock, manifest_dir=self.manifests)

    def diff(self, force=False):
        return diff_manifests.diff_source("testrom", force, jobs=2, manifest_dir=self.manifests)

    def dest(self) -> Path:
        return self.stock / "rom" / "testrom" / "acme__rocket"

    def test_fetch_takes_only_sparse_paths_and_records_state(self):
        self.assertEqual(self.fetch(), {"ok": 1, "empty": 0, "failed": 0})
        files = sorted(p.relative_to(self.dest()).as_posix() for p in self.dest().rglob("*") if p.is_file())
        self.assertEqual(files, ["configs/thermal/thermal_info_config.json", "device.mk",
                                 "rootdir/etc/thermal-engine.conf", "source.json"])
        meta = json.loads((self.dest() / "source.json").read_text())
        self.assertEqual(meta["commit"], self.sha1)
        self.assertEqual(meta["file_count"], 3)
        state = common.load_state("testrom", self.manifests)
        self.assertEqual(state["acme/rocket"]["commit"], self.sha1)
        self.assertEqual(state["acme/rocket"]["status"], "ok")

    def test_unchanged_upstream_is_not_in_change_set(self):
        self.fetch()
        changed, removed = self.diff()
        self.assertEqual((changed, removed), ([], []))
        # Same pushed_at: no network needed at all.
        self.assertIsNone(diff_manifests.classify(self.dev, common.load_state("testrom", self.manifests)["acme/rocket"],
                                                  False, remote_sha=lambda *_: self.fail("network used")))

    def test_upstream_commit_is_detected_and_refetched(self):
        self.fetch()
        sha2 = self.up.commit({"rootdir/etc/thermal-engine.conf": "[CPU]\nalgo_type ss\n",
                               "configs/thermal/thermal_info_config.json": None})
        # pushed_at moved in the listing -> ls-remote confirms the commit moved.
        self.dev["updated_at"] = "2026-02-01T00:00:00Z"
        self.write_manifest([self.dev])
        changed, _ = self.diff()
        self.assertEqual([(d["codename"], d["reason"]) for d in changed], [("rocket", "moved")])
        self.fetch(only={"acme/rocket"})
        self.assertFalse((self.dest() / "configs/thermal/thermal_info_config.json").exists(),
                         "file deleted upstream must disappear")
        self.assertIn("algo_type ss", (self.dest() / "rootdir/etc/thermal-engine.conf").read_text())
        self.assertEqual(json.loads((self.dest() / "source.json").read_text())["commit"], sha2)
        self.assertEqual(self.diff()[0], [])

    def test_push_to_other_branch_is_not_a_change(self):
        self.fetch()
        git("push", "-q", str(self.up.bare), "main:refs/heads/other", cwd=self.up.work)
        self.dev["updated_at"] = "2026-03-01T00:00:00Z"  # pushed_at moves for any branch
        self.write_manifest([self.dev])
        self.assertEqual(self.diff()[0], [])

    def test_repo_without_thermal_files_is_empty_and_remembered(self):
        up2 = Upstream(Path(self.tmp.name), "android_device_acme_plain")
        up2.commit({"README.md": "nothing thermal"})
        plain = {**self.dev, "codename": "plain", "clone_url": up2.url}
        self.write_manifest([self.dev, plain])
        self.assertEqual(self.fetch(), {"ok": 1, "empty": 1, "failed": 0})
        self.assertFalse((self.stock / "rom/testrom/acme__plain").exists())
        self.assertEqual(self.diff()[0], [], "an empty repository must not be refetched every run")

    def test_failed_clone_is_retried_and_keeps_last_good_commit(self):
        self.fetch()
        broken = {**self.dev, "clone_url": self.up.url + "-missing", "updated_at": "2026-04-01T00:00:00Z"}
        self.write_manifest([broken])
        self.assertEqual(self.fetch(only={"acme/rocket"})["failed"], 1)
        state = common.load_state("testrom", self.manifests)["acme/rocket"]
        self.assertEqual(state["status"], "clone-failed")
        self.assertEqual(state["commit"], self.sha1, "a failure must not erase the last fetched commit")
        self.assertTrue(self.dest().exists(), "a failure must not delete the data already fetched")
        self.assertEqual([d["reason"] for d in self.diff()[0]], ["retry"])

    def test_force_and_removed(self):
        self.fetch()
        self.assertEqual([d["reason"] for d in self.diff(force=True)[0]], ["forced"])
        self.write_manifest([])
        self.assertEqual(self.diff(), ([], ["acme/rocket"]))

    def test_resume_skips_devices_already_fetched(self):
        self.fetch()
        self.assertEqual(sparse_fetch.select([self.dev], common.load_state("testrom", self.manifests), None, False), [])

    def test_manifest_branch_missing_falls_back_then_upgrades(self):
        # A repo-tool manifest lists the repo on "next" before the repo has that branch.
        self.dev.update(default_branch="next", branches=["next", "main"], updated_at=None)
        self.write_manifest([self.dev])
        self.assertEqual(self.fetch()["ok"], 1)
        state = common.load_state("testrom", self.manifests)["acme/rocket"]
        self.assertEqual((state["branch"], state["commit"]), ("main", self.sha1))
        self.assertEqual(self.diff()[0], [], "same branch, same commit: up to date")
        git("push", "-q", str(self.up.bare), "main:refs/heads/next", cwd=self.up.work)
        self.assertEqual([d["reason"] for d in self.diff()[0]], ["moved"], "the preferred branch appeared")
        self.fetch(only={"acme/rocket"})
        self.assertEqual(common.load_state("testrom", self.manifests)["acme/rocket"]["branch"], "next")

    def test_merge_fetch_replaces_removes_and_keeps(self):
        """The CI commit job: a fetch job's artifact merged into a checkout."""
        import shutil
        self.fetch()  # the checkout's committed copy
        checkout = Path(self.tmp.name) / "checkout"
        shutil.copytree(self.stock, checkout)
        # Fetch job, in its own workspace: upstream moved.
        self.up.commit({"rootdir/etc/thermal-engine.conf": "[CPU]\nalgo_type pid\n"})
        artifacts = Path(self.tmp.name) / "artifacts"
        art = artifacts / "fetched-testrom"
        sparse_fetch.run_source(SOURCE, DATA, jobs=2, limit=None, only_keys={"acme/rocket"}, refetch=False,
                                stock=self.stock, manifest_dir=self.manifests, stage=art)
        self.assertEqual(sorted(p.name for p in art.iterdir()), ["manifest", "rom"])
        changed = {"devices": [{**self.dev, "source_id": "testrom"}]}
        counts = merge_fetch.merge(changed, artifacts, {"testrom": SOURCE}, stock=checkout,
                                   manifest_dir=checkout / "manifest")
        self.assertEqual(counts["replaced"], 1)
        conf = checkout / "rom/testrom/acme__rocket/rootdir/etc/thermal-engine.conf"
        self.assertIn("algo_type pid", conf.read_text())
        # Now upstream drops every thermal file: the merge removes the directory.
        state = json.loads((art / "manifest/testrom.state.json").read_text())
        state["devices"]["acme/rocket"]["status"] = "empty"
        (art / "manifest/testrom.state.json").write_text(json.dumps(state))
        self.assertEqual(merge_fetch.merge(changed, artifacts, {"testrom": SOURCE}, stock=checkout,
                                           manifest_dir=checkout / "manifest")["removed"], 1)
        self.assertFalse((checkout / "rom/testrom/acme__rocket").exists())

    def test_blob_source_lands_in_stock_blobs(self):
        self.assertEqual(common.dest_root({"id": "themuppets", "family": "blobs"}, self.stock),
                         self.stock / "blobs" / "themuppets")


class Identity(unittest.TestCase):
    def test_devices_and_common_trees(self):
        f = list_device_repos.identity
        self.assertEqual(f("android_device_xiaomi_alioth", "android_device_"), ("xiaomi", "alioth", "device"))
        self.assertEqual(f("android_device_xiaomi_sm8250-common", "android_device_"),
                         ("xiaomi", "sm8250-common", "common"))
        self.assertEqual(f("android_device_google_gs101", "android_device_"), ("google", "gs101", "common"))
        self.assertEqual(f("android_device_google_zuma", "android_device_"), ("google", "zuma", "common"))
        self.assertEqual(f("android_device_google_sunfish", "android_device_"), ("google", "sunfish", "device"))
        self.assertEqual(f("device_oneplus_lemonadep", "device_"), ("oneplus", "lemonadep", "device"))
        self.assertIsNone(f("android_device_qcom_sepolicy", "android_device_"))
        self.assertIsNone(f("android_vendor_lineage", "android_device_"))
        self.assertIsNone(f("android_device_redfin", "android_device_"))


class RepoManifest(unittest.TestCase):
    XML = """<?xml version="1.0" encoding="UTF-8"?>
<manifest>
  <project name="TheMuppets/proprietary_vendor_xiaomi_sm8250-common" path="vendor/xiaomi/sm8250-common"
           groups="muppets,muppets_alioth,muppets_apollon" clone-depth="1" />
  <project name="TheMuppets/proprietary_vendor_xiaomi_alioth" path="vendor/xiaomi/alioth"
           groups="muppets,muppets_alioth" clone-depth="1" />
  <project name="TheMuppets/proprietary_hardware_foo" path="hardware/foo" />
</manifest>"""

    def test_projects_and_served_devices(self):
        out = list_device_repos.parse_repo_manifest(self.XML, "TheMuppets", "proprietary_vendor_")
        self.assertEqual(sorted(out), ["xiaomi/alioth", "xiaomi/sm8250-common"])
        common_repo = out["xiaomi/sm8250-common"]
        self.assertEqual(common_repo["kind"], "common")
        self.assertEqual(common_repo["serves"], ["alioth", "apollon"])
        self.assertEqual(common_repo["clone_url"],
                         "https://github.com/TheMuppets/proprietary_vendor_xiaomi_sm8250-common.git")

    def test_newest_branch_wins(self):
        old_only = ('  <project name="TheMuppets/proprietary_vendor_xiaomi_alioth_old" '
                    'path="vendor/xiaomi/alioth_old" groups="muppets" />\n</manifest>')
        pages = {"b-new": self.XML, "b-old": self.XML.replace("</manifest>", old_only)}
        orig = list_device_repos.fetch_text
        list_device_repos.fetch_text = lambda url: next(v for k, v in pages.items() if f"/{k}/" in url)
        try:
            devs = list_device_repos.list_repo_manifest({"manifest_repo": "M/m", "manifest_file": "x.xml",
                                                         "branches": ["b-new", "b-old"], "org": "TheMuppets",
                                                         "repo_prefix": "proprietary_vendor_"})
        finally:
            list_device_repos.fetch_text = orig
        self.assertEqual(devs["xiaomi/alioth"]["default_branch"], "b-new")
        self.assertEqual(devs["xiaomi/alioth"]["branches"], ["b-new", "b-old"])
        self.assertEqual(devs["xiaomi/alioth_old"]["default_branch"], "b-old")


class Loader(unittest.TestCase):
    def test_mini_yaml_matches_pyyaml_on_the_real_file(self):
        text = (ROOT / "stock" / "sources.yaml").read_text()
        try:
            import yaml
        except ImportError:
            self.skipTest("PyYAML not installed")
        self.assertEqual(rom_sources._mini_yaml(text), yaml.safe_load(text))

    def test_mini_yaml_subset(self):
        text = 'schema: x\nsources:\n  - id: a  # c\n    branches: [b1, "b2"]\n    hint: "a\\\\d"\nlist:\n  - "p/#q"\n  - r\n'
        self.assertEqual(rom_sources._mini_yaml(text), {
            "schema": "x", "sources": [{"id": "a", "branches": ["b1", "b2"], "hint": "a\\d"}], "list": ["p/#q", "r"]})


if __name__ == "__main__":
    unittest.main(verbosity=1)
