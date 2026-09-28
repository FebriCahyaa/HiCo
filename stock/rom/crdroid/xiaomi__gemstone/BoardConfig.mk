#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/xiaomi/gemstone

# Inherit from sm6375-common
include device/xiaomi/sm6375-common/BoardConfigCommon.mk

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := gemstone

# Kernel
TARGET_KERNEL_CONFIG := moonstone_defconfig

# OTA assert
TARGET_OTA_ASSERT_DEVICE := moonstone,sunstone,gemstone

# Properties
TARGET_ODM_PROP += $(DEVICE_PATH)/odm.prop
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Security patch
BOOT_SECURITY_PATCH := 2026-02-01
VENDOR_SECURITY_PATCH := $(BOOT_SECURITY_PATCH)

# Inherit the proprietary files
include vendor/xiaomi/gemstone/BoardConfigVendor.mk
