# Canonical Source Evidence

Phase 2.4e introduces a small, deterministic evidence layer for relationship resolution.

## Purpose

The collector already preserves complete thermal-source manifests under `thermal-data/`, but the
relationship resolver should not depend on a temporary path such as `/tmp/hico-smoke-data`.
Canonical evidence copies only the source files needed to establish source relationships and records
where each file came from.

Current relationship evidence:

- `lineage.dependencies`
- root `BoardConfig.mk`

The layer deliberately does **not** copy an entire repository or the full collected tree.

## Layout

```text
sources/evidence/
├── index.json
└── github/
    └── LineageOS/
        └── android_device_xiaomi_garnet/
            └── <commit>/
                ├── manifest.json
                ├── lineage.dependencies
                └── BoardConfig.mk
```

The commit directory makes the evidence immutable by source revision. The manifest records provider,
repository, branch, commit, URL, source manifest, SHA-256 and file size.

## Extract from collected data

For the Garnet smoke dataset:

```bash
python3 tools/hico_evidence.py extract \
  --data /tmp/hico-smoke-data \
  --output sources/evidence \
  --source github/LineageOS/android_device_xiaomi_garnet
```

Verify the canonical evidence:

```bash
python3 tools/hico_evidence.py verify --root sources/evidence
```

The extraction is deterministic for the same collector manifests and source commit. No timestamp is
embedded in the manifest, so regenerating the same evidence does not create noisy diffs.

## Relationship resolver integration

The relationship resolver uses `sources/evidence` as its canonical evidence root by default. An explicit
`--evidence-root` still overrides that default for isolated diagnostics.
## CI verification

Phase 2.5a verifies the committed canonical evidence and universal relationship graph in both the Build and
Database workflows. CI runs the evidence and relationship regression tests, verifies `sources/evidence` file
hashes and sizes, regenerates `sources/relationships.json` deterministically, and requires a clean diff.

This verification reads only the committed repository index and canonical evidence. It does not collect or clone
the retained thermal candidates.

```bash
python3 tools/hico_relationships.py
```

After canonical Garnet evidence is present, the resolver can produce the same dependency and
`BoardConfig.mk` relationship edges without accessing `/tmp`.

## Provenance policy

Canonical evidence must keep the original source commit. Evidence is valid only as a representation of
the specific repository revision recorded in its manifest. Relationship inference must not collapse two
repositories merely because they share a platform token such as `sm7435`.

When evidence files become large, the layer should prefer hashes/metadata over copying large blobs.
The current v1 hard limit is 512 KiB per evidence file.
