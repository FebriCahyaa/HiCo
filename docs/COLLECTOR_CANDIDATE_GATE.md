# HiCo Collector Candidate Gate

Phase 2.4 connects the local thermal collector to the metadata-only candidate index produced by Phase 2.3.

## Default selection

`tools/hico_collector.py sync` now uses:

```text
sources/thermal-candidates.json
```

by default. This prevents a normal synchronization from cloning every repository in the universal discovery index.

## Explicit modes

Use an explicit repository index for manual or compatibility runs:

```shell
python3 tools/hico_collector.py sync --repo-index path/to/repositories.json
```

Use the complete universal repository index deliberately with:

```shell
python3 tools/hico_collector.py sync --all-repositories
```

`--all-repositories` cannot be combined with `--repo-index`.

## Safety properties

The candidate gate is a selection optimization, not proof of thermal-source presence. After cloning, the collector still performs its existing path/content relevance analysis and preserves source provenance.

The collector never silently falls back from a missing candidate index to the full repository index. A missing default candidate index is an error and tells the operator to regenerate it with `tools/hico_thermal_filter.py` or provide `--repo-index` explicitly.

The collector run report records the selected index and selection mode so the source set used by a run is auditable.

## Pipeline

```text
sources/registry.json
        ↓
Universal discovery
        ↓
sources/repositories.json
        ↓
Thermal candidate filter
        ↓
sources/thermal-candidates.json
        ↓
Collector candidate gate   ← Phase 2.4
        ↓
clone / fetch
        ↓
thermal relevance analysis
        ↓
thermal-data/
```
