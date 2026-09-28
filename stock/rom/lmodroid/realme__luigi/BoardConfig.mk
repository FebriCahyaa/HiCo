#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm6375-common
-include device/realme/sm6375-common/BoardConfigCommon.mk

DEVICE_PATH := device/realme/luigi

# Partitions
BOARD_ONEPLUS_DYNAMIC_PARTITIONS_SIZE := 11806965760
BOARD_SUPER_PARTITION_SIZE := 11811160064

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Inherit the proprietary files
-include vendor/realme/luigi/BoardConfigVendor.mk
