#
# Copyright (C) 2021-2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Include the common OEM chipset BoardConfig.
include device/oneplus/sm6375-common/BoardConfigCommon.mk

DEVICE_PATH := device/oneplus/gunnar

# Audio
AUDIO_FEATURE_ENABLED_EXT_AMPLIFIER := true

# Kernel
BOARD_ONEPLUS_DYNAMIC_PARTITIONS_SIZE := 5591007232
BOARD_SUPER_PARTITION_SIZE = 11190403072

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_ADDITIONAL_FLAGS := OPLUS_FEATURE_AOD_RAMLESS=yes OPLUS_FEATURE_CAMERA_GUNNAR=yes OPLUS_FEATURE_AUDIO_TFA98XX=yes

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Recovery
TARGET_RECOVERY_UI_MARGIN_HEIGHT := 103

# Include the proprietary files BoardConfig.
include vendor/oneplus/gunnar/BoardConfigVendor.mk
