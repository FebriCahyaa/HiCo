#!/usr/bin/env python3
from __future__ import annotations
import argparse, json, re
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
OEM_RE = re.compile(r"^LineageOS/android_device_([^/]+)_.+$", re.I)
EVIDENCE_TYPES = {"dependency-source", "dependency-source-unresolved", "build-path-reference"}

def load(path): return json.loads(Path(path).read_text(encoding="utf-8"))
def source_key(provider, repository): return f"{provider}/{repository}".strip("/")

def candidate_keys(data):
    out = {}
    for repo in data.get("repositories", []):
        p, n = str(repo.get("provider","")).strip(), str(repo.get("full_name","")).strip()
        if p and n: out[source_key(p,n)] = repo
    return out

def evidence_keys(index):
    return {str(x.get("source","")).strip() for x in index.get("sources",[]) if str(x.get("source","")).strip()}

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--candidates", default=str(ROOT/"sources/thermal-candidates.json"))
    ap.add_argument("--evidence-index", default=str(ROOT/"sources/evidence/index.json"))
    ap.add_argument("--relationships", default=str(ROOT/"sources/relationships.json"))
    ap.add_argument("--min-sources", type=int, default=4)
    ap.add_argument("--min-oems", type=int, default=4)
    ap.add_argument("--strict", action="store_true")
    args = ap.parse_args()

    candidates = candidate_keys(load(args.candidates))
    evidence = load(args.evidence_index)
    evidence_set = evidence_keys(evidence)
    relationships = load(args.relationships).get("relationships", [])

    covered = sorted(evidence_set & set(candidates))
    orphan = sorted(evidence_set - set(candidates))
    uncovered = sorted(set(candidates) - evidence_set)

    confidence, evidence_relationships, unresolved = Counter(), 0, 0
    for rel in relationships:
        if not isinstance(rel, dict): continue
        typ = str(rel.get("type",""))
        if typ in EVIDENCE_TYPES:
            evidence_relationships += 1
            confidence[str(rel.get("confidence","unknown"))] += 1
            unresolved += typ == "dependency-source-unresolved"

    oems = set()
    for key in covered:
        repo = candidates[key]
        vendor = str(repo.get("vendor","")).strip().lower()
        if vendor: oems.add(vendor); continue
        m = OEM_RE.match(str(repo.get("full_name","")))
        if m: oems.add(m.group(1).lower())

    total = len(candidates)
    result = {
        "schema":"hico.evidence-audit.v1",
        "candidate_count":total,
        "evidence_source_count":len(evidence_set),
        "covered_candidate_count":len(covered),
        "uncovered_candidate_count":len(uncovered),
        "orphan_evidence_count":len(orphan),
        "coverage_percent":round(len(covered)/total*100.0,3) if total else 0.0,
        "covered_oem_count":len(oems),
        "covered_oems":sorted(oems),
        "evidence_relationship_count":evidence_relationships,
        "unresolved_dependency_relationship_count":unresolved,
        "relationship_confidence":dict(sorted(confidence.items())),
        "minimums":{"min_sources":args.min_sources,"min_oems":args.min_oems},
        "covered_sources":covered,
        "uncovered_sources":uncovered,
        "orphan_evidence_sources":orphan,
    }
    print(json.dumps(result, indent=2, sort_keys=True))

    failures=[]
    if args.strict:
        if len(covered)<args.min_sources: failures.append(f"covered sources {len(covered)} < minimum {args.min_sources}")
        if len(oems)<args.min_oems: failures.append(f"covered OEMs {len(oems)} < minimum {args.min_oems}")
        if orphan: failures.append(f"orphan evidence sources: {len(orphan)}")
    return 1 if failures else 0

if __name__ == "__main__":
    raise SystemExit(main())
