#
# Copyright (C) 2018 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Include the common OEM chipset BoardConfig.
include device/oneplus/sm7250-common/BoardConfigCommon.mk

DEVICE_PATH := device/oneplus/ebba

# Display
TARGET_SCREEN_DENSITY := 450

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_CONFIG += vendor/ebba.config

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Partitions
ifeq (,$(filter true, $(WITHOUT_RESERVED_SIZE) $(WITH_GMS)))
BOARD_PRODUCTIMAGE_PARTITION_RESERVED_SIZE := 1000000000
endif
BOARD_ONEPLUS_DYNAMIC_PARTITIONS_SIZE := 5096079360
BOARD_SUPER_PARTITION_SIZE := 10200547328

# Recovery
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/init/fstab.qcom
TARGET_RECOVERY_UI_MARGIN_HEIGHT := 103

# Security
VENDOR_SECURITY_PATCH := 2026-01-01

# Include the proprietary files BoardConfig.
include vendor/oneplus/ebba/BoardConfigVendor.mk
