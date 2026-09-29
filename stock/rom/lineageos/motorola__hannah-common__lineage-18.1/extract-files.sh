#!/bin/bash
#
# Copyright (C) 2016 The CyanogenMod Project
# Copyright (C) 2017-2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# If we're being sourced by the common script that we called,
# stop right here. No need to go down the rabbit hole.
if [ "${BASH_SOURCE[0]}" != "${0}" ]; then
    return
fi

set -e

export BOARD_COMMON=msm8937-common
export DEVICE_COMMON=hannah-common
export DEVICE_SPECIFIED_COMMON_DEVICE="ahannah hannah rhannah"

"./../../${VENDOR}/${BOARD_COMMON}/extract-files.sh" "$@"

DEVICE_BLOB_ROOT="../../../vendor/${VENDOR}/${DEVICE_COMMON}/proprietary"

patchelf --set-soname camera.msm8937.so "${DEVICE_BLOB_ROOT}/vendor/lib/hw/camera.msm8937.so"
patchelf --set-soname libactuator_dw9767_truly.so "${DEVICE_BLOB_ROOT}/vendor/lib/libactuator_dw9767_truly.so"
sed -i "s/ro.product.manufacturer/ro.product.nopefacturer/" "${DEVICE_BLOB_ROOT}/vendor/lib/libmmcamera2_pproc_modules.so"
sed -i 's|msm8953_mot_deen_camera.xml|msm8937_mot_camera_conf.xml|g' "${DEVICE_BLOB_ROOT}/vendor/lib/libmmcamera2_sensor_modules.so"
