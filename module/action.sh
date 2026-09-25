#!/system/bin/sh
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
