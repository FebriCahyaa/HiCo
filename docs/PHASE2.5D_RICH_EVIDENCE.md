# Phase 2.5d — Rich Canonical Evidence & Dependency Resolution

Phase 2.5d extends the canonical evidence layer without changing the existing
metadata-first relationship semantics or the `hico.source-evidence.v1` schema.

## Objectives

- Preserve the bounded canonical evidence model.
- Capture additional small, root-level build and packaging files when they are
  already present in collector manifests.
- Resolve `lineage.dependencies` deterministically using exact full-name matching
  followed by unique-basename matching.
- Refuse ambiguous dependency matches instead of guessing.
- Keep existing relationship output semantics backward compatible.

## Rich evidence set

The canonical extractor now supports these root-level files:

- `lineage.dependencies`
- `BoardConfig.mk`
- `AndroidProducts.mk`
- `device.mk`
- `Android.bp`
- `Android.mk`
- `extract-files.sh`
- `proprietary-files.txt`

Only root-level paths are accepted for the bounded set. This prevents collisions
from repositories that contain many nested files with the same basename and keeps
the canonical evidence store small.

The extractor continues to store the source commit and SHA-256 checksum for every
canonical evidence file.

## Dependency resolver

`tools/hico_dependency_resolver.py` normalizes references such as:

```text
LineageOS/android_device_xiaomi_garnet
https://github.com/LineageOS/android_device_xiaomi_garnet.git
android_device_xiaomi_garnet
```

Resolution order is deterministic:

1. exact normalized `owner/repository`;
2. unique normalized repository basename;
3. otherwise unresolved or ambiguous.

Ambiguous references are never guessed. The relationship builder keeps the
existing `dependency-source` / `dependency-source-unresolved` semantics and
confidence policy.

## Validation

```bash
python3 tests/hico_dependency_resolver_test.py
python3 tests/hico_evidence_test.py
python3 tests/hico_relationships_test.py
python3 tools/hico_evidence_audit.py --strict --min-sources 4 --min-oems 4
python3 tools/hico_evidence.py extract --data thermal-data --output sources/evidence
python3 tools/hico_evidence.py verify --root sources/evidence
python3 tools/hico_relationships.py
```

The Build, Database, and Tools workflows run the resolver regression test as part of the
existing Phase 2.5 evidence gates.

## Deliberate non-goals

Phase 2.5d does not:

- clone additional repositories;
- replace the canonical `sources/relationships.json` model;
- infer device identity from platform equality;
- copy complete source trees;
- guess ambiguous dependencies.

Richer evidence consumption (for example, using `AndroidProducts.mk`,
`device.mk`, and kernel/build references in relationship inference) can be
introduced in Phase 2.6 after this evidence layer is stable.
