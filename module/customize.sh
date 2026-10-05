#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
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
				"Synrei Thermal Intelligence works only together with Flux Tweaks." \
				"Enable Flux Tweaks in your root manager, reboot," \
				"then install Synrei Thermal Intelligence again."
		fi
	else
		abort_box "Flux Tweaks is not installed." \
			"Synrei Thermal Intelligence is part of the Flux ecosystem: Flux detects" \
			"your games and Synrei unlocks thermal while they run." \
			"Install Flux Tweaks first:" \
			"$FLUX_RELEASES"
	fi

	flux_code=$(prop_value "$flux_prop" versionCode)
	case "$flux_code" in '' | *[!0-9]*) flux_code=0 ;; esac
	if [ "$flux_code" -gt 0 ] && [ "$flux_code" -lt "$FLUX_MIN_VERSION_CODE" ]; then
		abort_box "Flux Tweaks $(prop_value "$flux_prop" version) is too old for Synrei Thermal Intelligence." \
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

ui_print "- Synrei Thermal Intelligence is private software, licensed under EULA.md"
ui_print "  (English / Bahasa Indonesia). Installing means you accept it:"
ui_print "  personal use only, no redistribution, and thermal throttling is"
ui_print "  disabled while gaming at your own risk."

# Integrity: every extracted file is checked against its SHA-256.
ui_print "- Verifying module files"
unzip -o "$ZIPFILE" 'verify.sh' -d "$TMPDIR" >&2
[ -f "$TMPDIR/verify.sh" ] || abort_box "Unable to extract verify.sh, the zip may be corrupted."
. "$TMPDIR/verify.sh"

# Build flavor: arm64 / arm zips carry one binary, the universal zip both.
flavor=universal
if unzip -l "$ZIPFILE" flavor >/dev/null 2>&1; then
	extract "$ZIPFILE" flavor "$TMPDIR"
	flavor=$(head -n 1 "$TMPDIR/flavor")
fi
abi32=$(getprop ro.product.cpu.abilist32)
if [ "$ARCH" = "arm64" ] && [ -z "$abi32" ]; then
	ui_print "- CPU: $ABI, 64-bit-only ROM (no 32-bit userspace)"
elif [ "$ARCH" = "arm64" ]; then
	ui_print "- CPU: $ABI (64-bit ROM with 32-bit support)"
else
	ui_print "- CPU: $ABI (32-bit ROM)"
fi
case "$flavor" in
arm64)
	[ "$ARCH" = "arm64" ] || abort_box "This is the 64-bit (arm64) build of Synrei Thermal Intelligence," \
		"but this ROM runs a 32-bit (armeabi-v7a) userspace." \
		"Install the 32-bit build: hico-*-arm.zip"
	;;
arm)
	[ "$ARCH" = "arm" ] || abort_box "This is the 32-bit (arm) build of Synrei Thermal Intelligence," \
		"but this ROM is 64-bit (arm64-v8a)." \
		"Install the 64-bit build: hico-*-arm64.zip"
	;;
universal) ;;
*) abort_box "Unknown build flavor '$flavor', the zip may be corrupted." ;;
esac
ui_print "- Build: $flavor"

ui_print "- Extracting module files"
for f in module.prop service.sh uninstall.sh action.sh LICENSE EULA.md NOTICE.md; do
	extract "$ZIPFILE" "$f" "$MODPATH"
done
echo "$flavor" >"$MODPATH/flavor"
cp "$MODPATH/module.prop" "$MODPATH/module.prop.orig"

extract "$ZIPFILE" "libs/$ABI/hicod" "$TMPDIR"
mkdir -p "$MODPATH/system/bin"
cp "$TMPDIR/libs/$ABI/hicod" "$MODPATH/system/bin/hicod"
rm -rf "$TMPDIR/libs"

ui_print "- Extracting WebUI"
# The Vue build names its assets by content hash: take every webroot file in the
# zip (each still verified against its .sha256 by extract).
webui_files=$(unzip -l "$ZIPFILE" 'webroot/*' 2>/dev/null | awk '{print $4}' | grep '^webroot/' | grep -v -e '\.sha256$' -e '/$')
[ -n "$webui_files" ] || abort_box "The WebUI is missing from the zip, it may be corrupted."
for f in $webui_files; do
	extract "$ZIPFILE" "$f" "$MODPATH"
done

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

# The device database is compiled into hicod; show what it knows about this phone.
device_info=$("$MODPATH/system/bin/hicod" device 2>/dev/null)
if printf '%s\n' "$device_info" | grep -q '^database: yes'; then
	ui_print "- Device: $(printf '%s\n' "$device_info" | sed -n 's/^name: //p') ($(printf '%s\n' "$device_info" | sed -n 's/^codename: //p')), tuned from its stock firmware"
else
	ui_print "- Device $(printf '%s\n' "$device_info" | sed -n 's/^codename: //p') is not in the device database: runtime detection"
fi
ui_print "  ROM: $(printf '%s\n' "$device_info" | sed -n 's/^rom: //p' | cut -d';' -f1)"
ui_print "  Thermal backends: $(printf '%s\n' "$device_info" | sed -n 's/^backends: //p')"

ui_print "- Synrei Thermal Intelligence installed. Reboot to activate."
ui_print "  Daily use keeps stock thermal; games launched through"
ui_print "  Flux unlock it automatically, with a temperature guard."
