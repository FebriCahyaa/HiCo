#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm6375-common
-include device/oneplus/sm6375-common/BoardConfigCommon.mk

DEVICE_PATH := device/oneplus/larry

# Partitions
BOARD_ONEPLUS_DYNAMIC_PARTITIONS_SIZE := 12880707584
BOARD_SUPER_PARTITION_SIZE := 12884901888

# Inherit the proprietary files
-include vendor/oneplus/larry/BoardConfigVendor.mk
