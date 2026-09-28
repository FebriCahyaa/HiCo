#
# Copyright (C) 2018-2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from joan-common
include device/lge/joan-common/BoardConfigCommon.mk

DEVICE_PATH := device/lge/h932

TARGET_OTA_ASSERT_DEVICE := v30,h932,joan

# inherit from the proprietary version
include vendor/lge/h932/BoardConfigVendor.mk
