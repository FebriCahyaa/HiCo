#!/usr/bin/env python3
from __future__ import annotations

import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import hico_discovery as hd


def git(*args: str, cwd: Path | None = None) -> None:
    env = {
        **os.environ,
        "GIT_AUTHOR_NAME": "HiCo Test",
        "GIT_AUTHOR_EMAIL": "test@example.invalid",
        "GIT_COMMITTER_NAME": "HiCo Test",
        "GIT_COMMITTER_EMAIL": "test@example.invalid",
    }
    subprocess.run(["git", *args], cwd=cwd, env=env, check=True,
                   stdout=subprocess.PIPE, stderr=subprocess.PIPE)


def main() -> int:
    page = """
    <a href="/LineageOS/android_device_xiaomi_garnet">device</a>
    <a href="/LineageOS/android_device_xiaomi_garnet/issues">issue</a>
    <a href="/LineageOS/android_kernel_xiaomi_garnet">kernel</a>
    <a href="/LineageOS/android_frameworks_base">framework</a>
    """
    links = hd.github_repo_links(page, "LineageOS")
    assert links == {
        "https://github.com/LineageOS/android_device_xiaomi_garnet",
        "https://github.com/LineageOS/android_frameworks_base",
        "https://github.com/LineageOS/android_kernel_xiaomi_garnet",
    }
    assert hd.role_hint("LineageOS/android_device_xiaomi_garnet", "lineageos", "custom-rom") == "device"
    assert hd.role_hint("LineageOS/android_frameworks_base", "lineageos", "custom-rom") == "rom"
    assert hd.device_hint("LineageOS/android_device_xiaomi_garnet") == "garnet"

    source = {"id": "lineageos", "type": "github_org", "family": "lineageos", "organization": "LineageOS"}
    record = hd.make_repository_record(
        hd.Candidate(source, "https://github.com/LineageOS/android_device_xiaomi_garnet"),
        "lineage-23.2",
    )
    assert record["ecosystem"] == "custom-rom"
    assert record["vendor"] == "xiaomi"
    assert record["device"] == "garnet"
    assert record["repository_role"] == "device"

    with tempfile.TemporaryDirectory(prefix="hico-discovery-test-") as td:
        tmp = Path(td)
        work = tmp / "work"
        remote = tmp / "remote.git"
        work.mkdir()
        git("init", "-q", "-b", "main", str(work))
        (work / "README").write_text("test\n", encoding="utf-8")
        git("add", ".", cwd=work)
        git("commit", "-qm", "initial", cwd=work)
        git("clone", "-q", "--bare", str(work), str(remote))
        assert hd.probe_default_branch(f"file://{remote}", timeout=20) == ("ok", "main")

        empty_remote = tmp / "empty.git"
        subprocess.run(["git", "init", "--bare", str(empty_remote)], check=True,
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        assert hd.probe_default_branch(f"file://{empty_remote}", timeout=20) == ("empty", None)

    print("HiCo universal discovery test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
