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

MODDIR=${0%/*}
HICOD="$MODDIR/system/bin/hicod"

# The daemon rewrites the description with its live state; start clean each boot.
[ -f "$MODDIR/module.prop.orig" ] && cp "$MODDIR/module.prop.orig" "$MODDIR/module.prop"

while [ "$(getprop sys.boot_completed)" != "1" ]; do
	sleep 2
done

# hicod waits for fluxd itself (Flux starts in parallel), keeps stock thermal
# while Flux is missing, and replays any journal left by an unclean stop.
"$HICOD" daemon
