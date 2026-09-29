#!/bin/bash
#
# SPDX-FileCopyrightText: 2016 The CyanogenMod Project
# SPDX-FileCopyrightText: 2017-2024 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

set -e

# Required!
export DEVICE=vince
export VENDOR=xiaomi

export DEVICE_BRINGUP_YEAR=2019

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "${MY_DIR}" ]]; then MY_DIR="${PWD}"; fi

ANDROID_ROOT="${MY_DIR}/../../.."

HELPER="${ANDROID_ROOT}/tools/extract-utils/extract_utils.sh"
if [ ! -f "${HELPER}" ]; then
    echo "Unable to find helper script at ${HELPER}"
    exit 1
fi
source "${HELPER}"

# Default to sanitizing the vendor folder before extraction
CLEAN_VENDOR=true

SECTION=
KANG=

while [ "${#}" -gt 0 ]; do
    case "${1}" in
        -n | --no-cleanup )
                CLEAN_VENDOR=false
                ;;
        -k | --kang )
                KANG="--kang"
                ;;
        -s | --section )
                SECTION="${2}"
                shift
                CLEAN_VENDOR=false
                ;;
        * )
                SRC="${1}"
                ;;
    esac
    shift
done

if [ -z "${SRC}" ]; then
    SRC="adb"
fi

function blob_fixup() {
    case "${1}" in
        system_ext/etc/init/dpmd.rc)
	    [ "$2" = "" ] && return 0
            sed -i "s|/system/product/bin/|/system/system_ext/bin/|g" "${2}"
            ;;
        system_ext/etc/permissions/com.qti.dpmframework.xml \
        | system_ext/etc/permissions/dpmapi.xml \
        | system_ext/etc/permissions/telephonyservice.xml )
	    [ "$2" = "" ] && return 0
            sed -i "s|/system/product/framework/|/system/system_ext/framework/|g" "${2}"
            ;;
        system_ext/etc/permissions/embms.xml)
	    [ "$2" = "" ] && return 0
            sed -i "s|/product/framework/|/system_ext/framework/|g" "${2}"
            ;;
        system_ext/etc/permissions/qcrilhook.xml)
	    [ "$2" = "" ] && return 0
            sed -i 's|/product/framework/qcrilhook.jar|/system_ext/framework/qcrilhook.jar|g' "${2}"
            ;;
        system_ext/lib64/libdpmframework.so)
	    [ "$2" = "" ] && return 0
            grep -q "libcutils_shim.so" "${2}" || "${PATCHELF}" --add-needed "libcutils_shim.so" "${2}"
            ;;
        system_ext/lib64/lib-imsvideocodec.so)
	    [ "$2" = "" ] && return 0
            grep -q "libgui_shim.so" "${2}" || "${PATCHELF}" --add-needed "libgui_shim.so" "${2}"
            ;;
        vendor/bin/pm-service)
	    [ "$2" = "" ] && return 0
            grep -q "libutils-v33.so" "${2}" || "${PATCHELF}" --add-needed "libutils-v33.so" "${2}"
            ;;
        vendor/etc/init/qcrild.rc)
	    [ "$2" = "" ] && return 0
            sed -i '4d;11d' "${2}"
            ;;
        vendor/etc/init/dataqti.rc)
	    [ "$2" = "" ] && return 0
            sed -i '19d' "${2}"
            ;;
        vendor/usr/keylayout/uinput-fpc.kl|vendor/usr/keylayout/uinput-goodix.kl)
	    [ "$2" = "" ] && return 0
            sed -i '11d' "${2}"
            ;;
        vendor/lib64/libvendor.goodix.hardware.fingerprint@1.0-service.so)
	    [ "$2" = "" ] && return 0
            "${PATCHELF_0_18}" --remove-needed "libprotobuf-cpp-lite.so" "${2}"
            ;;
	vendor/lib64/hw/gf_fingerprint.goodix.default.so | vendor/lib64/libvendor.goodix.hardware.fingerprint@1.0-service.so)
	    [ "$2" = "" ] && return 0
            "${PATCHELF_0_18}" --replace-needed "libvendor.goodix.hardware.fingerprint@1.0.so" "vendor.goodix.hardware.fingerprint@1.0.so" "${2}"
            ;;
	    *)
             return 1
            ;;
    esac

# For all ELF files
    if [[ "${1}" =~ ^.*(\.so|\/bin\/.*)$ ]]; then
        "${PATCHELF_0_18}" --replace-needed "libstdc++.so" "libstdc++_vendor.so" "${2}"
    fi

    return 0
 }

 function blob_fixup_dry() {
     blob_fixup "$1" ""
}

setup_vendor "${DEVICE}" "${VENDOR}" "${ANDROID_ROOT}" false "${CLEAN_VENDOR}"

extract "${MY_DIR}/proprietary-files.txt" "${SRC}" \
        "${KANG}" --section "${SECTION}"

# Dolby
"${PATCHELF} --replace-needed "libstagefright_foundation.so" "libstagefright_foundation-v33.so" "${DEVICE_BLOB_ROOT}"/vendor/lib/libstagefright_soft_ddpdec.so"
"${PATCHELF} --replace-needed "libstagefright_foundation.so" "libstagefright_foundation-v33.so" "${DEVICE_BLOB_ROOT}"/vendor/lib/libstagefright_soft_ac4dec.so"
"${PATCHELF} --replace-needed "libstagefright_foundation.so" "libstagefright_foundation-v33.so" "${DEVICE_BLOB_ROOT}"/vendor/lib64/libdlbdsservice.so"

"${MY_DIR}/setup-makefiles.sh"
