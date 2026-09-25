#!/system/bin/sh
#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
#

# Action button: toggle HiCo between automatic and off, and show the state.

HICOD="/data/adb/modules/hico/system/bin/hicod"

if [ "$("$HICOD" config get mode)" = "off" ]; then
	"$HICOD" config set mode auto
	echo "- HiCo Thermal: AUTO"
	echo "  Thermal throttling is disabled while a Flux game runs."
else
	"$HICOD" config set mode off
	echo "- HiCo Thermal: OFF"
	echo "  Stock thermal everywhere, games included."
fi

sleep 1
echo
"$HICOD" status | grep -E '^(state|game|flux|cpu_temp|battery_temp)=' | sed 's/^/  /'
[ -n "$MMRL" ] || sleep 3
