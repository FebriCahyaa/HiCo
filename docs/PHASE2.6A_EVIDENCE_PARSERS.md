# Phase 2.6a — Evidence Parsers

Phase 2.6a adds a deterministic parser layer for the six rich evidence files
already captured by Phase 2.5d:

- `AndroidProducts.mk`
- `device.mk`
- `Android.bp`
- `Android.mk`
- `extract-files.sh`
- `proprietary-files.txt`

## Scope

The parser consumes text that is already present in `sources/evidence` or an
isolated test fixture. It only produces structured facts. It does **not**:

- resolve repositories;
- create or modify `sources/relationships.json`;
- infer device identity from filenames or platform equality;
- clone repositories or call GitHub/GitLab APIs;
- interpret ambiguous references as concrete relationships.

The parser contract is `hico.source-evidence-parsers.v1`.

## Parser contract

`tools/hico_evidence_parsers.py` exposes:

```python
parse_android_products_mk(text)
parse_device_mk(text)
parse_android_bp(text)
parse_android_mk(text)
parse_extract_files_sh(text)
parse_proprietary_files_txt(text)
```

The output is JSON-like Python data made from dictionaries, lists and strings.
Lists are de-duplicated/sorted where their semantics permit it. Raw
`proprietary-files.txt` entries keep their original line for provenance within
the parsed fact set.

### AndroidProducts.mk

Extracts product makefile declarations and `COMMON_LUNCH_CHOICES`.

### device.mk

Extracts includes, inherited products, package lists, copy-file mappings,
Soong namespaces and package overlays. Make is not evaluated.

### Android.bp

Uses a conservative brace-aware scanner to identify named Blueprint blocks and
selected source/dependency arrays (`srcs`, `required`, `shared_libs`,
`static_libs`, `defaults`, and include/import arrays). This is not a full
Blueprint language implementation.

### Android.mk

Recognizes module blocks bounded by `CLEAR_VARS` and `BUILD_*` includes and
captures selected `LOCAL_*` fields.

### extract-files.sh

Records sourced scripts, referenced proprietary-files lists and explicit
`extract`/`extract_vendor_files` calls. Shell is never executed.

### proprietary-files.txt

Preserves each non-comment entry, its prefix characters and a conservative
source/destination split when a mapping separator is present. Prefix semantics
are intentionally not guessed.

## Validation

```bash
python3 tests/hico_evidence_parsers_test.py
python3 -m py_compile tools/hico_evidence_parsers.py tests/hico_evidence_parsers_test.py
```

Build, Database and Tools workflows run the parser regression test.

## Phase boundary

Phase 2.6b may consume these structured facts for deterministic repository/path
resolution. Relationship generation must remain unchanged until that resolver
layer has its own tests and explicit evidence-to-edge policy.
