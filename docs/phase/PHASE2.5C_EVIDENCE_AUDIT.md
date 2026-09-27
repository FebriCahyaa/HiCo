# Phase 2.5c — Evidence Coverage & Confidence Audit

Phase 2.5c expands the Phase 2.5b multi-OEM evidence pilot without changing the metadata-first relationship architecture.

## Objectives

- Measure canonical evidence coverage against `sources/thermal-candidates.json`.
- Count evidence-backed relationships by confidence.
- Track unresolved `lineage.dependencies` relationships explicitly.
- Detect canonical evidence that no longer corresponds to a thermal candidate.
- Expand the pilot deterministically across six OEM families.

## Pilot

The bounded pilot selects up to two `LineageOS` device repositories on `lineage-23.2` for each:

- Xiaomi
- Motorola
- Samsung
- OnePlus
- Oppo
- Realme

Only repositories already present in `sources/thermal-candidates.json` are eligible.

## Audit

```bash
python3 tools/hico_evidence_audit.py
```

Controlled gate:

```bash
python3 tools/hico_evidence_audit.py --strict --min-sources 4 --min-oems 4
```

The report contains candidate/evidence counts, coverage percentage, OEM diversity,
evidence-backed relationship count, unresolved dependency count, and confidence distribution.

## Confidence policy

Existing relationship semantics remain unchanged:

- `high`: explicit repository identity, uniquely resolved dependency, or explicit `BoardConfig.mk` relationship.
- `medium`: unresolved dependency or other non-identity evidence.
- platform hints remain platform relationships and never become device identity solely because a platform token matches.

## Completion gate

- no orphan canonical evidence;
- at least four evidence-backed repositories;
- at least four OEM families;
- evidence verification clean;
- relationship regeneration deterministic;
- Build, Database, and Tools workflows green.
