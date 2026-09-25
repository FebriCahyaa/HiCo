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

HICOD="/data/adb/modules/hico/system/bin/hicod"

# Stop the daemon and put back every thermal change it made (no-op after a reboot).
[ -x "$HICOD" ] && "$HICOD" restore >/dev/null 2>&1

for dir in /data/adb/ksu/bin /data/adb/ap/bin; do
	[ -L "$dir/hicod" ] && rm -f "$dir/hicod"
done

rm -rf /data/adb/.config/hico /dev/hico
