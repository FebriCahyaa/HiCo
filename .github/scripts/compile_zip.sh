#!/bin/env bash
# Assembles the flashable zip from the ndk-build output. Runs in GitHub Actions.
set -euo pipefail

if [ -z "${GITHUB_WORKSPACE:-}" ]; then
	echo "This script should only run on GitHub Actions!" >&2
	exit 1
fi
cd "$GITHUB_WORKSPACE"

version="$(cat version)"
version_code="$(git rev-list HEAD --count)"
release_code="$version_code-$(git rev-parse --short HEAD)-release"

stage="$(mktemp -d)"
cp -r module/. "$stage"
sed -i "s/^version=.*/version=$version ($release_code)/" "$stage/module.prop"
sed -i "s/^versionCode=.*/versionCode=$version_code/" "$stage/module.prop"

for abi in arm64-v8a armeabi-v7a; do
	[ -f "libs/$abi/hicod" ] || {
		echo "::error::libs/$abi/hicod is missing (run ndk-build first)" >&2
		exit 1
	}
	mkdir -p "$stage/libs/$abi"
	cp "libs/$abi/hicod" "$stage/libs/$abi/hicod"
done
cp LICENSE EULA.md NOTICE.md "$stage/"

# devices/ is repository data only: it is compiled into hicod (tools/gen_device_db.py)
# and never shipped as files.

# Integrity: customize.sh/verify.sh check every extracted file against these.
bash .github/scripts/gen_sha256sum.sh "$stage" >/dev/null

zipName="hico-$version-$release_code.zip"
echo "zipName=$zipName" >>"$GITHUB_OUTPUT"

(cd "$stage" && zip -r9 "$GITHUB_WORKSPACE/$zipName" . -x '*.placeholder')
zip -z "$zipName" <<EOZ
HiCo Thermal $version-$release_code
Build Date $(date +"%a %b %d %H:%M:%S %Z %Y")
EOZ
