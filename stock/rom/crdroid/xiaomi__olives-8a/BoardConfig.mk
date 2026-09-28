#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from common sdm439-common
include device/xiaomi/sdm439-common/BoardConfigCommon.mk

DEVICE_PATH := device/xiaomi/olives

# Asserts
TARGET_OTA_ASSERT_DEVICE := olivelite,olivewood

# Build broken rules
BUILD_BROKEN_DUP_RULES := true

# Enable real time lockscreen charging current values
BOARD_GLOBAL_CFLAGS += -DBATTERY_REAL_INFO

# Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):libinit_olives
TARGET_RECOVERY_DEVICE_MODULES := libinit_olives

# Kernel
TARGET_KERNEL_CONFIG := olive-perf_defconfig

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Partitions
BOARD_CACHEIMAGE_PARTITION_SIZE := 402653184
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 4294967296

# Security patch level
VENDOR_SECURITY_PATCH := 2021-07-01

# Inherit from the proprietary version
include vendor/xiaomi/olives/BoardConfigVendor.mk
