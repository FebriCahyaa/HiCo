#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

function blob_fixup() {
    case "${1}" in
        vendor/bin/vaultkeeperd|vendor/lib64/libvkservice.so)
            sed -i 's/ro\.factory\.factory_binary/ro.vendor.factory_binary\x00/g' "${2}"
            ;;
        vendor/firmware/nvram.txt*)
            sed -i 's/disable_11ax=1/disable_11ax=0/g' "${2}"
            ;;
        vendor/lib/hw/audio.primary.exynos9825.so)
            "${PATCHELF}" --remove-needed libaudio_soundtrigger.so "${2}"
            "${PATCHELF}" --add-needed libshim_audioparams.so "${2}"
            sed -i 's/str_parms_get_str/str_parms_get_mod/g' "${2}"
            ;;
        vendor/lib64/libexynoscamera3.so)
            "${PATCHELF}" --add-needed libshim_camera.so "${2}"
            xxd -p "${2}" | sed "s/cc022036/1f2003d5/g" | xxd -r -p > "${2}".patched
            mv "${2}".patched "${2}"
            ;;
        vendor/lib*/sensors.*.so)
            "${PATCHELF}" --remove-needed libhidltransport.so "${2}"
            ;;
    esac
}

# If we're being sourced by the common script that we called,
# stop right here. No need to go down the rabbit hole.
if [ "${BASH_SOURCE[0]}" != "${0}" ]; then
    return
fi

set -e

export DEVICE=f62
export DEVICE_COMMON=exynos9820-common
export VENDOR=samsung

"./../../${VENDOR}/${DEVICE_COMMON}/extract-files.sh" "$@"
