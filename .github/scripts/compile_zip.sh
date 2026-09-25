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

for abi in arm64-v8a armeabi-v7a; do
	[ -f "libs/$abi/hicod" ] || {
		echo "::error::libs/$abi/hicod is missing (run ndk-build first)" >&2
		exit 1
	}
done

# Three flavors, each with its own update channel so a root manager keeps a
# device on the build it installed:
#   arm64      64-bit only (arm64-v8a), including 64-bit-only AOSP ROMs
#   arm        32-bit only (armeabi-v7a), for ROMs with a 32-bit userspace
#   universal  both binaries, the installer picks the device's ABI
build_flavor() { # <flavor> <update json> <abi>...
	flavor=$1
	update_json=$2
	shift 2

	stage="$(mktemp -d)"
	cp -r module/. "$stage"
	sed -i "s/^version=.*/version=$version ($release_code)/" "$stage/module.prop"
	sed -i "s/^versionCode=.*/versionCode=$version_code/" "$stage/module.prop"
	sed -i "s#/main/update.json#/main/$update_json#" "$stage/module.prop"
	echo "$flavor" >"$stage/flavor"

	for abi in "$@"; do
		mkdir -p "$stage/libs/$abi"
		cp "libs/$abi/hicod" "$stage/libs/$abi/hicod"
	done
	cp LICENSE EULA.md NOTICE.md "$stage/"
	# devices/ is repository data only: it is compiled into hicod (tools/gen_device_db.py)
	# and never shipped as files.

	# Integrity: customize.sh/verify.sh check every extracted file against these.
	bash .github/scripts/gen_sha256sum.sh "$stage" >/dev/null

	zip="hico-$version-$release_code-$flavor.zip"
	rm -f "$GITHUB_WORKSPACE/$zip"
	(cd "$stage" && zip -qr9 "$GITHUB_WORKSPACE/$zip" . -x '*.placeholder')
	zip -qz "$zip" <<EOZ
HiCo Thermal $version-$release_code ($flavor)
Build Date $(date +"%a %b %d %H:%M:%S %Z %Y")
EOZ
	rm -rf "$stage"
	echo "$zip"
}

zip_arm64=$(build_flavor arm64 update-arm64.json arm64-v8a)
zip_arm=$(build_flavor arm update-arm.json armeabi-v7a)
zip_universal=$(build_flavor universal update.json arm64-v8a armeabi-v7a)

{
	echo "zipName=$zip_universal"
	echo "zipArm64=$zip_arm64"
	echo "zipArm=$zip_arm"
	echo "zips<<EOF"
	printf '%s\n' "$zip_arm64" "$zip_arm" "$zip_universal"
	echo "EOF"
} >>"$GITHUB_OUTPUT"
