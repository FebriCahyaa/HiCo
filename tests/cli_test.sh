#!/bin/sh
#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
#

# End-to-end test of the host build: runs the real event loop (inotify,
# epoll, signalfd) against a fake device and plays Flux's part by rewriting
# current_profile / gameinfo like fluxd does.
#
# Usage: cli_test.sh <path to host hicod>

set -eu

HICOD=$(realpath "$1")
HICO_ROOT=$(mktemp -d)
export HICO_ROOT
trap 'kill "$PID" 2>/dev/null || true; rm -rf "$HICO_ROOT"' EXIT
PID=

fail() {
	echo "FAIL: $*" >&2
	echo "--- state"; cat "$HICO_ROOT/dev/hico/state" 2>/dev/null || true
	echo "--- log"; cat "$HICO_ROOT/log" 2>/dev/null || true
	exit 1
}

put() {
	mkdir -p "$HICO_ROOT$(dirname "$1")"
	printf '%s\n' "$2" >"$HICO_ROOT$1"
}

get() { cat "$HICO_ROOT$1" 2>/dev/null; }

wait_for() { # <file> <text>
	i=0
	while ! grep -q "$2" "$HICO_ROOT$1" 2>/dev/null; do
		i=$((i + 1))
		[ "$i" -gt 50 ] && fail "timeout waiting for '$2' in $1"
		sleep 0.1
	done
}

# ── Fake device ──────────────────────────────────────────────────────────────
Z=/sys/class/thermal/thermal_zone0
put $Z/type cpu-0-0-usr
put $Z/temp 45000
put $Z/policy step_wise
put $Z/available_policies "step_wise user_space"
put /sys/class/power_supply/battery/temp 330
put /__props__/init.svc.thermal-engine running
put /data/adb/modules/hico/module.prop "description=placeholder"
put /data/adb/modules/flux/system/bin/fluxd ""
put /data/adb/modules/flux/module.prop "versionCode=48"
put /data/adb/.config/flux/current_profile 3
put /data/adb/.config/flux/gameinfo "NULL 0 0"
put /proc/4242/comm fluxd
mkdir -p "$HICO_ROOT/dev" "$HICO_ROOT/data/adb/.config"

# ── CLI ──────────────────────────────────────────────────────────────────────
"$HICOD" version | grep -q . || fail "version"
"$HICOD" flux | grep -q "flux=ready" || fail "flux dependency not detected"
"$HICOD" config set safety_cpu_temp 150 2>/dev/null && fail "out-of-range value accepted"
"$HICOD" config set safety_cpu_temp 90 || fail "config set"
[ "$("$HICOD" config get safety_cpu_temp)" = 90 ] || fail "config get"
"$HICOD" config set exit_delay 0 || fail "config set exit_delay"
"$HICOD" config schema | grep -q '"key":"mode"' || fail "schema"
put /sys/devices/system/cpu/cpufreq/policy0/cpuinfo_max_freq 2016000
put /sys/devices/system/cpu/cpufreq/policy0/scaling_max_freq 1497600
put /sys/devices/system/cpu/cpufreq/policy0/related_cpus "0 1 2 3"
"$HICOD" monitor --json | grep -q '"schema":"hico.monitor.v2"' || fail "monitor --json schema"
"$HICOD" monitor --json | grep -q '"zones"' || fail "monitor --json zones"
"$HICOD" monitor --json | grep -q '"cooling"' || fail "monitor --json cooling"
"$HICOD" monitor --json | grep -q '"cooling_devices"' || fail "monitor --json cooling devices"
"$HICOD" monitor --once | grep -q 'zones' || fail "monitor --once"
"$HICOD" thermal table | grep -q '^ZONE' || fail "thermal table"
"$HICOD" thermal table --json | grep -q '"schema":"hico.monitor.v2"' || fail "thermal table --json"
"$HICOD" monitor --interval 0 2>/dev/null && fail "monitor accepted interval 0"
put /vendor/etc/thermal-engine.conf '[CPU0_MONITOR]
algo_type monitor
sensor cpu-0-0
thresholds 95000
thresholds_clr 90000'
"$HICOD" thermal sources --json | grep -q '"path":"/vendor/etc/thermal-engine.conf","format":"thermal-engine"' ||
	fail "thermal sources --json config"
"$HICOD" thermal sources --json | grep -q '"controller":"vendor"' || fail "thermal sources --json controller"
"$HICOD" thermal sources | grep -q '^== thermal configs' || fail "thermal sources"
put /vendor/etc/.tp/thermal.conf 'SfebGmowgWang'
put /vendor/etc/.tp/.thermal_policy_00 'x'
"$HICOD" thermal sources --json | grep -q '"path":"/vendor/etc/.tp/thermal.conf","format":"mtk-thermal-policy"[^}]*"tunable":false' ||
	fail "thermal sources MediaTek policy"
"$HICOD" thermal sources --json | grep -q '"path":"/vendor/etc/.tp/.thermal_policy_00"' || fail "thermal sources MediaTek policy file"

# ── Daemon ───────────────────────────────────────────────────────────────────
"$HICOD" run 2>"$HICO_ROOT/log" &
PID=$!
put /proc/$PID/comm hicod # the fake /proc only knows what the test puts there
wait_for /dev/hico/state "state=idle"
"$HICOD" status --json | grep -q '"running":"1"' || fail "status --json"

# fluxd starts a game: gameinfo first, then current_profile.
put /proc/31337/comm com.game
put /data/adb/.config/flux/gameinfo "com.game 31337 10100"
put /data/adb/.config/flux/current_profile 1
wait_for /dev/hico/state "state=boost"
[ "$(get /__props__/init.svc.thermal-engine)" = stopped ] || fail "thermal-engine not stopped"
[ "$(get $Z/policy)" = user_space ] || fail "zone governor not switched"
grep -q "thermal unlocked" "$HICO_ROOT/data/adb/modules/hico/module.prop" || fail "module description"

# Config change is picked up live: the guard trips at the new limit.
put $Z/temp 80000
"$HICOD" config set safety_cpu_temp 75
wait_for /dev/hico/state "state=safety"
[ "$(get $Z/policy)" = step_wise ] || fail "safety did not restore zones"
"$HICOD" config set safety_cpu_temp 95
put $Z/temp 50000
"$HICOD" config set safety_cooldown 5

# Game exits.
put /data/adb/.config/flux/gameinfo "NULL 0 0"
put /data/adb/.config/flux/current_profile 3
wait_for /dev/hico/state "state=idle"
[ "$(get /__props__/init.svc.thermal-engine)" = running ] || fail "thermal-engine not restarted"

# SIGTERM mid-game restores stock thermal.
put /data/adb/.config/flux/gameinfo "com.game 31337 10100"
put /data/adb/.config/flux/current_profile 1
wait_for /dev/hico/state "state=boost"
"$HICOD" restore >/dev/null || fail "restore"
kill -0 "$PID" 2>/dev/null && fail "daemon still running after restore"
[ "$(get $Z/policy)" = step_wise ] || fail "zone not restored on stop"
[ "$(get /__props__/init.svc.thermal-engine)" = running ] || fail "service not restored on stop"
[ -e "$HICO_ROOT/dev/hico/journal" ] && fail "journal left behind"

echo "PASS cli end-to-end"
