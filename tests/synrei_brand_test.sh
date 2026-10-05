#!/bin/sh
# Phase 4.5B (HiCo -> Synrei Thermal Intelligence): public labels rebranded, technical identifiers
# frozen, protected data and thermal logic untouched, every remaining HiCo reference classified.
# Read-only. Usage: synrei_brand_test.sh <repo root> [hicod binary]
root=${1:-.}
bin=$2
fail=0
ok() { :; }
bad() { echo "FAIL: $*"; fail=1; }
has() { grep -qF -- "$2" "$root/$1" || bad "$1 lacks: $2"; }
hasnt() { grep -qF -- "$2" "$root/$1" && bad "$1 still has: $2"; return 0; }

# 1, 3, 4, 5, 6. frozen technical identifiers
has jni/include/HiCo.hpp '#define HICO_CONFIG_DIR "/data/adb/.config/hico"'
has jni/include/HiCo.hpp '#define HICO_CONFIG_FILE HICO_CONFIG_DIR "/hico.conf"'
has jni/include/HiCo.hpp '#define HICO_RUNTIME_DIR "/dev/hico"'
has jni/include/HiCo.hpp '#define HICO_STATE_FILE HICO_RUNTIME_DIR "/state"'
has jni/include/HiCo.hpp '#define HICO_LOCK_FILE HICO_RUNTIME_DIR "/hicod.lock"'
has jni/include/HiCo.hpp '#define HICO_MODULE_DIR "/data/adb/modules/hico"'
has jni/include/HiCo.hpp '#define HICO_TAG "HiCoThermal"'
has module/module.prop 'id=hico'
has module/module.prop 'updateJson=https://raw.githubusercontent.com/FebriCahyaa/HiCo-Release/main/update.json'
has module/uninstall.sh 'rm -rf /data/adb/.config/hico /dev/hico'
has CMakeLists.txt 'add_executable(hicod '
has .github/workflows/release.yml "sed '1{/^# HiCo Thermal Changelog\$/d}'"
has changelog.md '/dev/hico/thermal'

# 2, 18, 19. public branding
has jni/include/HiCo.hpp '#define SYNREI_PUBLIC_NAME "Synrei Thermal Intelligence"'
has jni/include/HiCo.hpp '#define HICO_NAME SYNREI_PUBLIC_NAME'
has module/module.prop 'name=Synrei Thermal Intelligence'
has module/module.prop 'description=Synrei Thermal Intelligence (HiCo backend)'
has jni/src/main.cpp 'out(SYNREI_PUBLIC_NAME " " HICO_VERSION " - device-aware thermal management (HiCo backend)'
has module/action.sh 'Synrei Thermal Intelligence: AUTO'
has module/customize.sh 'Synrei Thermal Intelligence installed. Reboot to activate.'
has webui/index.html '<title>Synrei Thermal Intelligence</title>'
has webui/src/views/Home.vue '>Synrei Thermal Intelligence</h1>'
has webui/src/views/About.vue 'mt-3">Synrei Thermal Intelligence</p>'
has .github/workflows/release.yml '--title "Synrei Thermal Intelligence $TAG"'
hasnt webui/src/views/Home.vue '>HiCo Thermal</h1>'
# Legal attribution unchanged.
has EULA.md 'HiCo'
has webui/src/locales/en.json '"legal_summary": "HiCo Thermal is proprietary software'

# 18. CLI: the binary prints the Synrei banner and keeps hicod commands.
if [ -n "$bin" ] && [ -x "$bin" ]; then
	usage=$("$bin" 2>&1)
	echo "$usage" | grep -qF 'Synrei Thermal Intelligence' || bad "hicod usage lacks Synrei label"
	echo "$usage" | grep -qF 'Usage: hicod <command>' || bad "hicod usage lacks hicod command name"
fi

# 15, 16. still one daemon executable and no Synrei-named backend/daemon.
[ "$(grep -c 'add_executable(hicod' "$root/CMakeLists.txt")" = 1 ] || bad "hicod executable count"
grep -rqiE 'synreid|SynreiBackend|synrei_daemon' "$root/jni" "$root/module" "$root/CMakeLists.txt" && bad "second Synrei daemon/backend"

# 7-14, 21. thermal logic, schema and protected data unchanged since the pre-migration base.
# Migration-time audit only: set BRAND_AUDIT_BASE=9f20e03a to compare against the pre-migration
# commit. Off by default so later legitimate changes do not fail this test.
base=${BRAND_AUDIT_BASE:-}
if [ -n "$base" ] && git -C "$root" cat-file -e "$base^{commit}" 2>/dev/null; then
	protected="database thermal-data generated generated-thermal stock sources devices tools tests/tests.cpp tests/cli_test.sh README.md docs/phase docs/integrity :(exclude)docs/integrity/webui.sha256 EULA.md LICENSE NOTICE.md changelog.md module/webroot"
	logic=$(cd "$root" && git ls-files jni | grep -vE '^jni/include/HiCo.hpp$|^jni/src/main.cpp$|^jni/src/Daemon.cpp$')
	# shellcheck disable=SC2086
	git -C "$root" diff --quiet "$base" -- $protected $logic || bad "protected data or thermal logic changed since $base"
	deleted=$(git -C "$root" diff --name-only --diff-filter=DR "$base")
	[ -z "$deleted" ] || bad "files deleted/renamed: $deleted"
	# Only label lines changed in the three edited sources.
	changed=$(git -C "$root" diff -U0 "$base" -- jni/include/HiCo.hpp jni/src/main.cpp jni/src/Daemon.cpp | grep -E '^[-+][^-+]' | grep -viE 'synrei|HiCo Thermal|HICO_NAME|HICO_TAG|identity|label|Automatic thermal unlock for games, powered by Flux')
	[ -z "$changed" ] || bad "non-label change in daemon sources: $changed"
else
	echo "note: history checks skipped (BRAND_AUDIT_BASE unset or unavailable)"
fi

# 24. every remaining HiCo reference is classified.
reg="$root/docs/architecture/hico_identifiers.tsv"
files=$(cd "$root" && { git grep -lIi 'hico'; git ls-files | grep -i 'hico'; } | sort -u)
for f in $files; do
	best=""
	while IFS='	' read -r prefix class reason; do
		case "$prefix" in ''|'#'*) continue ;; esac
		case "$f" in "$prefix"*) [ ${#prefix} -gt ${#best} ] && best=$prefix ;; esac
	done <"$reg"
	[ -n "$best" ] || bad "unclassified: $f"
done
badclass=$(grep -v '^#' "$reg" | awk -F'\t' 'NF{print $2}' | grep -vxE 'compatibility|technical identifier|historical documentation|legal attribution|test fixture|migration documentation|intentional legacy reference')
[ -z "$badclass" ] || bad "invalid class: $badclass"

[ $fail -eq 0 ] && echo "synrei_brand_test: passed"
exit $fail
