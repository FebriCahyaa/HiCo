#!/usr/bin/env python3
from __future__ import annotations

import importlib.util
import json
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TOOL = ROOT / "tools" / "hico_evidence.py"
RELATIONSHIP_TOOL = ROOT / "tools" / "hico_relationships.py"

spec = importlib.util.spec_from_file_location("hico_evidence", TOOL)
assert spec and spec.loader
h = importlib.util.module_from_spec(spec)
spec.loader.exec_module(h)


def main() -> int:
    with tempfile.TemporaryDirectory(prefix="hico-evidence-test-") as td:
        root = Path(td)
        data = root / "thermal-data"
        out = root / "evidence"
        dataset = data / "custom-rom/xiaomi/lineageos/garnet/unknown/device/test"
        raw = dataset / "raw"
        raw.mkdir(parents=True)
        (raw / "lineage.dependencies").write_text(json.dumps([
            {"repository": "android_kernel_xiaomi_sm7435", "target_path": "kernel/xiaomi/sm7435"},
            {"repository": "android_hardware_xiaomi", "target_path": "hardware/xiaomi"},
        ]), encoding="utf-8")
        (raw / "BoardConfig.mk").write_text(
            "TARGET_KERNEL_SOURCE := kernel/xiaomi/sm7435\n"
            "TARGET_KERNEL_EXT_MODULE_ROOT := kernel/xiaomi/sm7435-modules\n"
            "include vendor/xiaomi/garnet/BoardConfigVendor.mk\n",
            encoding="utf-8",
        )
        (dataset / "manifest.json").write_text(json.dumps({
            "schema": "hico.thermal-source.v1",
            "source": {
                "id": "lineageos",
                "provider": "github",
                "repository": "LineageOS/android_device_xiaomi_garnet",
                "branch": "lineage-23.2",
                "commit": "abcdef1234567890abcdef1234567890abcdef12",
                "url": "https://github.com/LineageOS/android_device_xiaomi_garnet",
            },
            "files": [
                {"tree_path": "lineage.dependencies", "raw_path": str(raw / "lineage.dependencies")},
                {"tree_path": "BoardConfig.mk", "raw_path": str(raw / "BoardConfig.mk")},
            ],
        }, indent=2) + "\n", encoding="utf-8")

        result = h.extract(data, out, [])
        assert result["failures"] == []
        assert result["sources_exported"] == 1
        assert result["files_exported"] == 2

        manifests = sorted(p for p in out.rglob("manifest.json") if p.is_file())
        assert len(manifests) == 1
        manifest = json.loads(manifests[0].read_text(encoding="utf-8"))
        assert manifest["schema"] == "hico.source-evidence.v1"
        assert manifest["source"]["commit"] == "abcdef1234567890abcdef1234567890abcdef12"
        assert {x["tree_path"] for x in manifest["files"]} == {"lineage.dependencies", "BoardConfig.mk"}
        assert all(x["sha256"] and len(x["sha256"]) == 64 for x in manifest["files"])
        assert (out / "index.json").is_file()

        verified = h.verify(out)
        assert verified["errors"] == []
        assert verified["index_present"] is True

        rel_spec = importlib.util.spec_from_file_location("hico_relationships", RELATIONSHIP_TOOL)
        assert rel_spec and rel_spec.loader
        rel = importlib.util.module_from_spec(rel_spec)
        rel_spec.loader.exec_module(rel)
        loaded = rel.load_evidence_files([out])
        key = "github/LineageOS/android_device_xiaomi_garnet"
        assert key in loaded
        assert set(loaded[key]) == {"lineage.dependencies", "BoardConfig.mk"}
        fixture_repos = [
            {"provider":"github","full_name":"LineageOS/android_device_xiaomi_garnet","vendor":"xiaomi","device":"garnet","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"device"},
            {"provider":"github","full_name":"LineageOS/android_kernel_xiaomi_sm7435","vendor":"xiaomi","device":"sm7435","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"kernel"},
            {"provider":"github","full_name":"LineageOS/android_hardware_xiaomi","vendor":"xiaomi","device":"","ecosystem":"custom-rom","rom_family":"lineageos","repository_role":"hardware"},
        ]
        rels, _ = rel.build_relationships(fixture_repos, {}, [out])
        edge_set = {(x["type"], x["target"]) for x in rels if x["source_repository"] == "LineageOS/android_device_xiaomi_garnet"}
        assert ("dependency-source", "github/LineageOS/android_kernel_xiaomi_sm7435") in edge_set
        assert ("dependency-source", "github/LineageOS/android_hardware_xiaomi") in edge_set
        assert ("build-path-reference", "build-path/kernel/xiaomi/sm7435") in edge_set
        assert ("build-path-reference", "build-path/vendor/xiaomi/garnet/BoardConfigVendor.mk") in edge_set

    # The production relationship resolver should accept canonical evidence as
    # its evidence-root without requiring collector-local /tmp paths.
    py_compile = subprocess.run(
        ["python3", "-m", "py_compile", str(RELATIONSHIP_TOOL), str(TOOL)],
        text=True,
        capture_output=True,
    )
    assert py_compile.returncode == 0, py_compile.stderr

    print("HiCo canonical evidence test: PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
