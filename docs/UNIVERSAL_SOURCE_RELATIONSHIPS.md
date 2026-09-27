# Universal Source Relationships

Phase 2.4b adds a conservative relationship graph between discovered repositories, device identities, and platform identities.

## Rules

- Exact device identity creates a high-confidence device relationship.
- OEM dumps such as `dumps/redmi/garnet` can become `firmware-device` links when their device identity is explicit.
- Kernel/common repository names containing `sm7435` create a `platform/sm7435` edge.
- Platform equality alone does **not** create a kernel→device edge because several devices may share a platform.
- A Motorola `SM7435` source is not automatically a Xiaomi Garnet source.
- Missing OEM `repository_role` values are inferred as `firmware`; writing them back to the canonical index is opt-in via `--normalize-index`.

## Run

```bash
python3 tools/hico_relationships.py
```

To also normalize missing OEM roles in `sources/repositories.json`:

```bash
python3 tools/hico_relationships.py --normalize-index
```

Output:

```text
sources/relationships.json
```

The resolver is metadata-first. It does not clone repositories and does not call GitHub/GitLab APIs.

## Future evidence enrichment

After collection, the graph can be enriched from existing manifests and source evidence such as `BoardConfig.mk`, `lineage.dependencies`, DTS/DTBO metadata, and other repository content. Stronger evidence can add relationships without collapsing provenance.


## r1 evidence enrichment

The metadata-only graph is intentionally conservative. r1 adds optional post-collection enrichment from collector manifests:

- `lineage.dependencies` creates high-confidence `dependency-source` edges when a dependency name resolves uniquely in the repository index.
- `BoardConfig.mk` creates high-confidence `build-path-reference` edges for kernel source/module roots and vendor/hardware includes.
- Kernel repositories are no longer mislabeled as `kernel-device-exact` solely because their repository suffix contains a platform name such as `sm7435`.

Evidence enrichment is opt-in with repeated `--evidence-root` arguments. It can consume canonical `thermal-data/` or an isolated smoke-test directory.
