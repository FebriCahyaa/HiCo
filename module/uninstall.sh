#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
#

HICOD="/data/adb/modules/hico/system/bin/hicod"

# Stop the daemon and put back every thermal change it made (no-op after a reboot).
[ -x "$HICOD" ] && "$HICOD" restore >/dev/null 2>&1

for dir in /data/adb/ksu/bin /data/adb/ap/bin; do
	[ -L "$dir/hicod" ] && rm -f "$dir/hicod"
done

rm -rf /data/adb/.config/hico /dev/hico
