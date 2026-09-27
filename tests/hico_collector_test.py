#!/usr/bin/env python3
from __future__ import annotations

import json
import os
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOL = ROOT / "tools" / "hico_collector.py"


def git(*args: str, cwd: Path | None = None, env: dict[str, str] | None = None) -> None:
    merged = {**os.environ, **(env or {})}
    subprocess.run(["git", *args], cwd=cwd, env=merged, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)


def main() -> int:
    with tempfile.TemporaryDirectory(prefix="hico-collector-test-") as td:
        tmp = Path(td)
        work = tmp / "work"
        remote = tmp / "remote.git"
        cache = tmp / "cache"
        data = tmp / "thermal-data"
        index = tmp / "repositories.json"
        state = tmp / "state.json"
        report = tmp / "report.json"
        (work / "vendor/etc").mkdir(parents=True)
        (work / "vendor/etc/thermal-engine.conf").write_text(
            "[CPU_MONITOR]\n"
            "algo_type monitor\n"
            "sensor cpu\n"
            "thresholds 45000 50000\n"
            "actions cpu cpu\n"
        )
        (work / "vendor/build.prop").write_text(
            "ro.product.device=collector_test\n"
            "ro.product.brand=Xiaomi\n"
            "ro.board.platform=sm7435\n"
            "ro.build.version.release=15\n"
            "ro.lineage.version=23.2\n"
        )
        env = {
            "GIT_AUTHOR_NAME": "HiCo Test",
            "GIT_AUTHOR_EMAIL": "test@example.invalid",
            "GIT_COMMITTER_NAME": "HiCo Test",
            "GIT_COMMITTER_EMAIL": "test@example.invalid",
        }
        git("init", "-q", "-b", "main", str(work), env=env)
        git("add", ".", cwd=work, env=env)
        git("commit", "-qm", "initial", cwd=work, env=env)
        git("clone", "-q", "--bare", str(work), str(remote), env=env)

        index.write_text(json.dumps({
            "schema": "hico.repositories.v1",
            "repositories": [{
                "provider": "github",
                "source_id": "smoke",
                "full_name": "SmokeOrg/android_device_smoke",
                "branch": "main",
                "web_url": "https://github.com/SmokeOrg/android_device_smoke",
                "clone_url": f"file://{remote}",
                "ecosystem": "custom-rom",
                "rom_family": "lineageos",
                "vendor": "xiaomi",
            }],
        }, indent=2) + "\n")

        command = [
            sys.executable, str(TOOL), "sync",
            "--repo-index", str(index),
            "--cache", str(cache),
            "--data", str(data),
            "--state", str(state),
            "--report", str(report),
            "--workers", "1",
        ]
        first = subprocess.run(command, text=True, capture_output=True)
        assert first.returncode == 0, first.stderr
        manifests = list(data.rglob("manifest.json"))
        assert len(manifests) == 1
        manifest = json.loads(manifests[0].read_text())
        assert manifest["identity"]["device"] == "collector_test"
        assert manifest["identity"]["rom_family"] == "lineageos"
        assert manifest["identity"]["platform"] == "sm7435"
        assert (manifests[0].parent / "raw/vendor/etc/thermal-engine.conf").is_file()

        second = subprocess.run(command, text=True, capture_output=True)
        assert second.returncode == 0, second.stderr
        assert "UNCHANGED" in second.stdout

    # Candidate-gate resolution defaults to thermal-candidates.json, while an explicit
    # repository index remains supported for backwards-compatible/manual runs.
    import importlib.util

    spec = importlib.util.spec_from_file_location("hico_collector", TOOL)
    assert spec and spec.loader
    collector = importlib.util.module_from_spec(spec)
    sys.modules[spec.name] = collector
    spec.loader.exec_module(collector)

    from argparse import Namespace

    candidate = tmp / "thermal-candidates.json"
    args = Namespace(
        all_repositories=False,
        repo_index="",
        candidate_index=str(candidate),
    )
    resolved, mode = collector.resolve_sync_index(args)
    assert resolved == candidate
    assert mode == "thermal-candidates"

    explicit = tmp / "repositories.json"
    args.repo_index = str(explicit)
    resolved, mode = collector.resolve_sync_index(args)
    assert resolved == explicit
    assert mode == "explicit"

    args.repo_index = ""
    args.all_repositories = True
    resolved, mode = collector.resolve_sync_index(args)
    assert resolved == collector.ROOT / "sources" / "repositories.json"
    assert mode == "all"

    args.repo_index = str(explicit)
    try:
        collector.resolve_sync_index(args)
    except ValueError:
        pass
    else:
        raise AssertionError("--all-repositories must reject --repo-index")

    print("HiCo local collector test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
