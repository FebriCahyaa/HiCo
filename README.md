# HiCo Phase 2 Final Local Cleanup

Apply this bundle from the real HiCo checkout:

```bash
cd ~/workspace/HiCo
bash /path/to/HiCo-final-cleanup/apply_hico_cleanup.sh "$PWD"
```

The script:

- repairs `tests/hico_discovery_test.py`
- makes `tests/repository_index_merge_test.py` test the integrated merge logic in `hico_discovery.py`
- keeps the discovery snapshot source-scoped while `sources/repositories.json` remains the merged index
- removes transitional `docs/PHASE2.1_DISCOVERY_MERGE.md`
- removes obsolete `docs/COMMIT_SERIES.md`
- removes redundant `tools/merge_repository_indexes.py`
- keeps `docs/UNIVERSAL_DISCOVERY.md` and refreshes it for the current architecture
- normalizes permissions outside `.git`
- creates a timestamped backup before modifying local files
