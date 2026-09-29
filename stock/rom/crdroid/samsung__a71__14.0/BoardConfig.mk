#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

-include device/samsung/a71-common/BoardConfigCommon.mk

DEVICE_PATH := device/samsung/a71

# Assert
TARGET_OTA_ASSERT_DEVICE := a71

# Board
TARGET_BOARD_NAME := SRPSF18B010

# FOD
TARGET_SURFACEFLINGER_UDFPS_LIB := //$(DEVICE_PATH):libudfps_extension.a71
TARGET_USES_FOD_ZPOS := true

# Kernel
TARGET_KERNEL_CONFIG := a71_defconfig

# NFC
TARGET_USES_NQ_NFC := true

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Security Patch Level
VENDOR_SECURITY_PATCH := 2024-02-01

# Sepolicy
BOARD_VENDOR_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy/vendor

# Get non-open-source specific aspects
include vendor/samsung/a71/BoardConfigVendor.mk
