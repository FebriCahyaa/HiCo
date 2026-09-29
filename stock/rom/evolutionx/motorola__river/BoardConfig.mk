#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from motorola sdm632-common
-include device/motorola/sdm632-common/BoardConfigCommon.mk

DEVICE_PATH := device/motorola/river

# Assertions
TARGET_BOARD_INFO_FILE := $(DEVICE_PATH)/board-info.txt
TARGET_OTA_ASSERT_DEVICE := river

# Display
TARGET_SCREEN_DENSITY := 420

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_CONFIG := river_defconfig

# NFC
BOARD_NFC_CHIPSET := pn553

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 33554432        #    32768 * 1024 mmcblk0p41-42
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2952790016    #  2883584 * 1024 mmcblk0p62-63
BOARD_SYSTEM_EXTIMAGE_PARTITION_SIZE := 285212672 #   278528 * 1024 mmcblk0p58-59 (OEM)
BOARD_VENDORIMAGE_PARTITION_SIZE := 861507584     #   841316 * 1024 mmcblk0p60-61

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += $(DEVICE_PATH)

# inherit from the proprietary version
include vendor/motorola/river/BoardConfigVendor.mk
