#!/usr/bin/env python3
from __future__ import annotations
import json, subprocess, tempfile
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
TOOL=ROOT/"tools/hico_evidence_audit.py"

with tempfile.TemporaryDirectory(prefix="hico-evidence-audit-") as td:
    root=Path(td)
    candidates=root/"candidates.json"; evidence=root/"evidence.json"; relationships=root/"relationships.json"
    repos=[
      {"provider":"github","full_name":"LineageOS/android_device_xiaomi_garnet","vendor":"xiaomi"},
      {"provider":"github","full_name":"LineageOS/android_device_motorola_berlin","vendor":"motorola"},
      {"provider":"github","full_name":"LineageOS/android_device_samsung_a52q","vendor":"samsung"},
      {"provider":"github","full_name":"LineageOS/android_device_oneplus_avalon","vendor":"oneplus"},
    ]
    candidates.write_text(json.dumps({"repositories":repos}),encoding="utf-8")
    evidence.write_text(json.dumps({"sources":[{"source":f"github/{r['full_name']}"} for r in repos]}),encoding="utf-8")
    relationships.write_text(json.dumps({"relationships":[
      {"type":"dependency-source","confidence":"high"},
      {"type":"build-path-reference","confidence":"high"},
      {"type":"dependency-source-unresolved","confidence":"medium"},
    ]}),encoding="utf-8")
    p=subprocess.run(["python3",str(TOOL),"--candidates",str(candidates),"--evidence-index",str(evidence),
                      "--relationships",str(relationships),"--strict","--min-sources","4","--min-oems","4"],
                     text=True,capture_output=True)
    assert p.returncode==0,p.stderr
    r=json.loads(p.stdout)
    assert r["candidate_count"]==4
    assert r["covered_candidate_count"]==4
    assert r["coverage_percent"]==100.0
    assert r["covered_oem_count"]==4
    assert r["evidence_relationship_count"]==3
    assert r["unresolved_dependency_relationship_count"]==1
    assert r["relationship_confidence"]=={"high":2,"medium":1}
print("HiCo evidence coverage audit test: PASS")
