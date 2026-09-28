#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm8250-common
include device/xiaomi/sm8250-common/BoardConfigCommon.mk

DEVICE_PATH := device/xiaomi/psyche

# Display
TARGET_SCREEN_DENSITY := 440

# Device VINTF
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_CONFIG := \
    vendor/kona-perf_defconfig \
    vendor/xiaomi/sm8250-common.config \
    vendor/xiaomi/psyche.config

# OTA assert
TARGET_OTA_ASSERT_DEVICE := psyche

# Properties
TARGET_SYSTEM_EXT_PROP += $(DEVICE_PATH)/system_ext.prop
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Inherit from the proprietary version
include vendor/xiaomi/psyche/BoardConfigVendor.mk
