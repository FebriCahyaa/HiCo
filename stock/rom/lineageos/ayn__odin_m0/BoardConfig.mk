#
# Copyright (C) 2026 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sdm845-common
include device/ayn/sdm845-common/BoardConfigCommon.mk

DEVICE_PATH := device/ayn/odin_m0

# Assert
TARGET_OTA_ASSERT_DEVICE := odin_m0

# Kernel
TARGET_KERNEL_CONFIG += vendor/ayn/odin_m0.config

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Recovery
TARGET_RECOVERY_DEFAULT_ROTATION := ROTATION_RIGHT
TARGET_RECOVERY_DEFAULT_TOUCH_ROTATION := ROTATION_LEFT
