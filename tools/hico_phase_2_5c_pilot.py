#!/usr/bin/env python3
from __future__ import annotations
import argparse, json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
OEM_ORDER=("xiaomi","motorola","samsung","oneplus","oppo","realme")

def vendor(repo):
    v=str(repo.get("vendor","")).strip().lower()
    if v: return v
    name=str(repo.get("full_name","")).split("/")
    if len(name)>=2 and name[-2]=="LineageOS" and name[-1].startswith("android_device_"):
        bits=name[-1].split("_")
        if len(bits)>=3: return bits[2].lower()
    return ""

def main():
    ap=argparse.ArgumentParser()
    ap.add_argument("--input",default=str(ROOT/"sources/thermal-candidates.json"))
    ap.add_argument("--output",default=str(ROOT/"build/phase-2.5c/pilot-index.json"))
    ap.add_argument("--per-oem",type=int,default=2)
    args=ap.parse_args()
    data=json.loads(Path(args.input).read_text(encoding="utf-8"))
    repos=[dict(r) for r in data.get("repositories",[])
           if str(r.get("provider","")).strip()=="github"
           and str(r.get("repository_role","")).strip().lower()=="device"
           and str(r.get("branch","")).strip()=="lineage-23.2"]
    selected=[]; used=set()
    for oem in OEM_ORDER:
        matches=sorted([r for r in repos if vendor(r)==oem],key=lambda r:str(r.get("full_name","")))
        for repo in matches[:args.per_oem]:
            key=f"{repo.get('provider','')}/{repo.get('full_name','')}"
            if key not in used: selected.append(repo); used.add(key)
    if len(selected)<len(OEM_ORDER):
        missing=[o for o in OEM_ORDER if not any(vendor(r)==o for r in selected)]
        raise SystemExit("insufficient pilot coverage; missing OEMs: "+", ".join(missing))
    output=Path(args.output); output.parent.mkdir(parents=True,exist_ok=True)
    payload={"schema":"hico.repositories.v1","description":"Bounded Phase 2.5c multi-OEM evidence pilot.",
             "generated_from":str(Path(args.input).resolve().relative_to(ROOT)).replace("\\","/"),
             "repository_count":len(selected),"repositories":selected}
    output.write_text(json.dumps(payload,indent=2,sort_keys=True)+"\n",encoding="utf-8")
    print(json.dumps({"repository_count":len(selected),"oems":OEM_ORDER,
                      "output":str(output),"repositories":[r["full_name"] for r in selected]},indent=2))
if __name__=="__main__": raise SystemExit(main())
