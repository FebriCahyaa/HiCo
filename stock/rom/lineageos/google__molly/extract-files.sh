#!/bin/bash
#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

set -e

DEVICE=molly
VENDOR=google

# Load extract_utils and do some sanity checks
MY_DIR="${BASH_SOURCE%/*}"
if [[ ! -d "$MY_DIR" ]]; then MY_DIR="$PWD"; fi

CM_ROOT="$MY_DIR"/../../..

HELPER="$CM_ROOT"/vendor/cm/build/tools/extract_utils.sh
if [ ! -f "$HELPER" ]; then
    echo "Unable to find helper script at $HELPER"
    exit 1
fi
. "$HELPER"

while [ "$1" != "" ]; do
    case $1 in
        -n | --no-cleanup )     CLEAN_VENDOR=false
                                ;;
        -s | --section )        shift
                                SECTION=$1
                                CLEAN_VENDOR=false
                                ;;
        * )                     SRC=$1
                                ;;
    esac
    shift
done

if [ -z "$SRC" ]; then
    SRC=adb
fi

# Initialize the helper
setup_vendor "$DEVICE" "$VENDOR" "$CM_ROOT" false "$CLEAN_VENDOR"

extract "$MY_DIR"/proprietary-files.txt "$SRC" "$SECTION"

BLOB_ROOT="$CM_ROOT"/vendor/"$VENDOR"/"$DEVICE"/proprietary

# libEGL_tegra_impls.so changes to use libeglm.so
sed -i 's/NvOsLibraryLoad/molly_m_libload/g' "${BLOB_ROOT}"/lib/libEGL_tegra_impl.so
sed -i 's/libnvos\.so/libeglm.so/g' "${BLOB_ROOT}"/lib/libEGL_tegra_impl.so

"$MY_DIR"/setup-makefiles.sh
