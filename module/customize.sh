#
# Copyright (C) 2026 FebriCahyaa
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# shellcheck disable=SC1091,SC2034
SKIPUNZIP=1

HICO_CONFIG="/data/adb/.config/hico"
FLUX_DIR="/data/adb/modules/flux"
FLUX_UPDATE_DIR="/data/adb/modules_update/flux"
FLUX_RELEASES="https://github.com/FebriCahyaa/Flux/releases"
# Oldest supported Flux build (v1.2.0). Keep in sync with FLUX_MIN_VERSION_CODE in jni/include/HiCo.hpp.
FLUX_MIN_VERSION_CODE=46

abort_box() {
	ui_print "*********************************************************"
	for line in "$@"; do ui_print "! $line"; done
	abort "*********************************************************"
}

prop_value() { # <file> <key>
	sed -n "s/^$2=//p" "$1" 2>/dev/null | head -n 1
}

# ── Ecosystem gate: HiCo Thermal is a Flux Tweaks add-on ─────────────────────
# fluxd detects games (game list, focus, PID tracking, screen state) and HiCo
# follows it, so HiCo cannot work alone. A Flux flashed in the same session
# (modules_update) counts: both become active after the reboot.
check_flux() {
	if [ -f "$FLUX_UPDATE_DIR/module.prop" ]; then
		flux_prop="$FLUX_UPDATE_DIR/module.prop"
	elif [ -f "$FLUX_DIR/module.prop" ] && [ -f "$FLUX_DIR/system/bin/fluxd" ]; then
		flux_prop="$FLUX_DIR/module.prop"
		if [ -f "$FLUX_DIR/disable" ] || [ -f "$FLUX_DIR/remove" ]; then
			abort_box "Flux Tweaks is disabled or scheduled for removal." \
				"HiCo Thermal works only together with Flux Tweaks." \
				"Enable Flux Tweaks in your root manager, reboot," \
				"then install HiCo Thermal again."
		fi
	else
		abort_box "Flux Tweaks is not installed." \
			"HiCo Thermal is part of the Flux ecosystem: Flux detects" \
			"your games and HiCo unlocks thermal while they run." \
			"Install Flux Tweaks first:" \
			"$FLUX_RELEASES"
	fi

	flux_code=$(prop_value "$flux_prop" versionCode)
	case "$flux_code" in '' | *[!0-9]*) flux_code=0 ;; esac
	if [ "$flux_code" -gt 0 ] && [ "$flux_code" -lt "$FLUX_MIN_VERSION_CODE" ]; then
		abort_box "Flux Tweaks $(prop_value "$flux_prop" version) is too old for HiCo Thermal." \
			"Update Flux Tweaks to v1.2.0 or newer:" \
			"$FLUX_RELEASES"
	fi
	ui_print "- Flux Tweaks $(prop_value "$flux_prop" version) found"
}

[ "$API" -lt 28 ] && abort_box "Android 9 (Pie) or newer is required."

case $ARCH in
arm64) ABI="arm64-v8a" ;;
arm) ABI="armeabi-v7a" ;;
*) abort_box "Unsupported architecture: $ARCH" ;;
esac

check_flux

# Integrity: every extracted file is checked against its SHA-256.
ui_print "- Verifying module files"
unzip -o "$ZIPFILE" 'verify.sh' -d "$TMPDIR" >&2
[ -f "$TMPDIR/verify.sh" ] || abort_box "Unable to extract verify.sh, the zip may be corrupted."
. "$TMPDIR/verify.sh"

ui_print "- Extracting module files"
for f in module.prop service.sh uninstall.sh action.sh LICENSE; do
	extract "$ZIPFILE" "$f" "$MODPATH"
done
cp "$MODPATH/module.prop" "$MODPATH/module.prop.orig"

extract "$ZIPFILE" "libs/$ABI/hicod" "$TMPDIR"
mkdir -p "$MODPATH/system/bin"
cp "$TMPDIR/libs/$ABI/hicod" "$MODPATH/system/bin/hicod"
rm -rf "$TMPDIR/libs"

ui_print "- Extracting WebUI"
for f in index.html app.js style.css; do
	extract "$ZIPFILE" "webroot/$f" "$MODPATH"
done

# Device profile generated from this phone's stock firmware dump, when one ships.
codename=$(getprop ro.product.vendor.device | tr '[:upper:]' '[:lower:]')
[ -z "$codename" ] && codename=$(getprop ro.product.device | tr '[:upper:]' '[:lower:]')
case "$codename" in
'' | *[!a-z0-9_]*) codename="" ;;
esac
if [ -n "$codename" ] && unzip -l "$ZIPFILE" "devices/xiaomi/$codename.prop" >/dev/null 2>&1; then
	mkdir -p "$MODPATH/devices/xiaomi"
	extract "$ZIPFILE" "devices/xiaomi/$codename.prop" "$MODPATH"
	model=$(sed -n 's/^model=//p' "$MODPATH/devices/xiaomi/$codename.prop")
	ui_print "- Device profile: $model ($codename), from its stock firmware"
else
	ui_print "- No device profile for '${codename:-unknown}': runtime detection only"
fi

set_perm_recursive "$MODPATH" 0 0 0755 0644
set_perm "$MODPATH/system/bin/hicod" 0 0 0755

if [ "$KSU" = "true" ] || [ "$APATCH" = "true" ]; then
	# Nothing in /system needs overlaying: expose hicod on the manager's PATH instead.
	touch "$MODPATH/skip_mount"
	for dir in /data/adb/ksu/bin /data/adb/ap/bin; do
		[ -d "$dir" ] && ln -sf "/data/adb/modules/hico/system/bin/hicod" "$dir/hicod"
	done
fi

# Settings survive updates; new keys get their defaults and old values are validated.
ui_print "- Preparing settings"
mkdir -p "$HICO_CONFIG"
chmod 0700 "$HICO_CONFIG"
"$MODPATH/system/bin/hicod" config upgrade || abort_box "hicod does not run on this device ($ABI)."

ui_print "- HiCo Thermal installed. Reboot to activate."
ui_print "  Daily use keeps stock thermal; games launched through"
ui_print "  Flux unlock it automatically, with a temperature guard."
