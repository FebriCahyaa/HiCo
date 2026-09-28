#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/xiaomi/apollo

BUILD_BROKEN_DUP_RULES := true
BUILD_BROKEN_MISSING_REQUIRED_MODULES := true
BUILD_BROKEN_ELF_PREBUILT_PRODUCT_COPY_FILES := true
BUILD_BROKEN_VENDOR_PROPERTY_NAMESPACE := true
BUILD_BROKEN_ENFORCE_SYSPROP_OWNER := true

# Display
TARGET_HAS_WIDE_COLOR_DISPLAY := true
TARGET_SCREEN_DENSITY := 440

# HWUI
HWUI_COMPILE_FOR_PERF := true

# Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):init_xiaomi_apollo
TARGET_RECOVERY_DEVICE_MODULES := init_xiaomi_apollo

# Kernel
TARGET_KERNEL_CONFIG := vendor/apollo_defconfig

# LED
TARGET_LED_WHITE_ONLY := true

# Inherit from xiaomi sm8250-common
include device/xiaomi/sm8250-common/BoardConfigCommon.mk

# inherit from the proprietary version
include vendor/xiaomi/apollo/BoardConfigVendor.mk
