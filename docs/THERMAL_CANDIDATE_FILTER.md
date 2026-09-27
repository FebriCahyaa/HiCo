# Universal Thermal Candidate Filter

HiCo discovery finds repositories; it does not prove that every repository contains thermal data. The
candidate filter is the metadata-only gate between discovery and collection.

## Purpose

The filter reads `sources/repositories.json` and produces a smaller collector input:

```text
sources/repositories.json
        ↓
metadata-only thermal candidate filter
        ├── candidate → sources/thermal-candidates.json
        └── reject    → sources/thermal-filter.json (diagnostic)
        ↓
hico_collector.py
        ↓
thermal-data/
```

The filter never clones a repository, never calls GitHub/GitLab APIs, and never claims that a candidate
actually contains thermal files. Thermal presence is verified only after the collector inspects repository
trees and files.

## Scoring model

Strong source-layer roles receive the largest weights:

```text
device    +70
vendor    +65
kernel    +60
hardware  +55
hal       +50
init      +45
firmware  +45
mod       +35
source    +20
rom       +15
```

Additional identity and naming signals can add points for vendor/device/Android identity and names that
explicitly mention thermal, cooling, cpufreq/devfreq, powerhal or performance controls.

The default candidate threshold is `25`. Custom-ROM framework repositories therefore remain lower weight
unless their repository name carries a thermal/performance signal.

## Safety boundary

A candidate is a collection optimization hint, not a tuning authorization. The collector remains responsible
for extracting only paths accepted by `tools/hico_thermal/artifacts.py`. Unknown or opaque thermal formats
are retained as source evidence with provenance; they are not auto-tuned without a verified parser/codec.

## Run

```bash
python3 tools/hico_thermal_filter.py \
  --input sources/repositories.json \
  --output sources/thermal-candidates.json \
  --report sources/thermal-filter.json
```

Inspect the result:

```bash
python3 - <<'PY'
import json
p = json.load(open("sources/thermal-filter.json"))
print("repositories:", p["repository_count"])
print("candidates:", p["candidate_count"])
print("rejected:", p["reject_count"])
print("verdicts:", p["verdicts"])
print("candidate_roles:", p["candidate_roles"])
PY
```

Then point the existing collector at the reduced index without changing collector semantics:

```bash
python3 tools/hico_collector.py sync --repo-index sources/thermal-candidates.json
```

## Custom-ROM ROM gate

A repository classified as `ecosystem=custom-rom` and `repository_role=rom` is not a thermal candidate
from generic ROM-family or vendor identity alone. It must contain an explicit thermal/performance naming
signal (for example `thermal`, `cooling`, `cpufreq`, `devfreq`, `powerhal`, `powerhint`, `governor`, or
`perf`). This prevents generic framework repositories such as font or build components from entering the
collector fan-out merely because they belong to a known vendor or ROM family.
