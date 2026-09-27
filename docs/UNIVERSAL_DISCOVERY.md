# Universal Repository Discovery

HiCo uses a token-free, incremental repository discovery layer for OEM and custom-ROM sources.

## Pipeline

```text
sources/registry.json
        ↓
public GitHub/GitLab HTML
        ↓
repository candidates
        ↓
git ls-remote
        ├── ok    → collector-ready repository
        ├── empty → diagnostic only
        └── error → diagnostic only
        ↓
sources/discovery.json
sources/repositories.json
        ↓
universal thermal candidate filtering
        ↓
hico_collector.py
        ↓
thermal-data/
```

## Safe incremental merge

Discovery never replaces the existing repository index.

Records are merged by `(provider, full_name)`. A newly discovered record replaces only the same key; all
previously retained repositories remain intact. Legacy OEM records without `repository_role` are normalized
to `firmware`.

Empty repositories remain in `sources/discovery.json` for diagnostics but are excluded from
`sources/repositories.json`.

The discovery snapshot is source-scoped. `sources/repositories.json` is the merged collector-ready index.

## Classification

```text
android_device_*    → device
android_vendor_*    → vendor
android_kernel_*    → kernel
android_hardware_*  → hardware
frameworks/packages/system/platform → rom
```

Generic framework/platform repositories do not fabricate hardware identities.

## Run discovery

```bash
python3 tools/hico_discovery.py discover --source lineageos --workers 8
```

Inspect:

```bash
python3 - <<'PY'
import json
from collections import Counter
p = json.load(open("sources/discovery.json"))
print(json.dumps(p["summary"], indent=2))
print("ecosystem:", Counter(x["ecosystem"] for x in p["repositories"]))
print("vendor:", Counter(x["vendor"] or "unknown" for x in p["repositories"]))
print("family:", Counter(x["rom_family"] for x in p["repositories"]))
print("role:", Counter(x["repository_role"] for x in p["repositories"]))
print("empty:", len(p.get("empty_repositories", [])))
print("errors:", len(p.get("errors", [])))
PY
```

## Thermal safety boundary

Discovery coverage is not thermal coverage. Only repositories that produce thermal-relevant source evidence
should be collected into `thermal-data/`. Unknown or opaque thermal formats remain source evidence with
provenance and hashes and are not auto-tuned until a verified parser or codec exists.
