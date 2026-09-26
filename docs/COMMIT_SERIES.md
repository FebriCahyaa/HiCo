# HiCo Thermal Commit Series

The repository does not include a `.git` directory in the source ZIP, so the changes are accompanied by `scripts/commit_series.sh`. Run it from the real Git checkout after replacing the repository contents with this ZIP.

The script creates separate, reviewable commits for the functional layers. Each commit has a detailed subject/body pair and the helper uses `git add -A` so the removal of the legacy workflow is staged correctly. Run it only after placing this source tree over a clean checkout of the previous HiCo revision; unrelated changes remain outside the listed paths and are not staged by the script.

1. `feat(tools): add generic thermal codec and unpack pipeline`
2. `feat(database): add multi-source thermal ingestion and mapping`
3. `ci: replace Xiaomi-only device workflow with unified pipelines`
4. `docs: document thermal database architecture and provenance`
5. `data: seed normalized thermal database from repository records`
6. `refactor(monitor): make live monitoring thermal-only`
7. `feat(database): add original-versus-candidate thermal tables`
8. `ci(release): build the thermal Monitor WebUI in release packages`

The monitor commit includes `tests/thermal_scope_test.py` and `tests/cli_test.sh` so the thermal-only
contract is tested in native and CLI coverage. `tools.yml` remains responsible for thermal tooling and
database remapping only; release packaging remains isolated in `release.yml`.
