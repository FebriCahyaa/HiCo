#
# Copyright (C) 2026 FebriCahyaa. All rights reserved.
#
# HiCo Thermal is proprietary software. Use is governed by EULA.md;
# copying, redistribution or modification without written permission
# from the author is prohibited.
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
