#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from motorola sdm632-common
-include device/motorola/sdm632-common/BoardConfigCommon.mk

DEVICE_PATH := device/motorola/channel

# Assertions
TARGET_BOARD_INFO_FILE := $(DEVICE_PATH)/board-info.txt
TARGET_OTA_ASSERT_DEVICE := channel

# Display
TARGET_SCREEN_DENSITY := 280

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_CONFIG := channel_defconfig
BOARD_RAMDISK_USE_XZ := true

# Low Memory
MALLOC_SVELTE := true

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 33554432        #    32768 * 1024 mmcblk0p41-42
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2466250752    #  2408448 * 1024 mmcblk0p62-63
BOARD_SYSTEM_EXTIMAGE_PARTITION_SIZE := 285212672 #   278528 * 1024 mmcblk0p58-59 (OEM)
BOARD_VENDORIMAGE_PARTITION_SIZE := 335544320     #   841316 * 1024 mmcblk0p60-61

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += $(DEVICE_PATH)

# inherit from the proprietary version
include vendor/motorola/channel/BoardConfigVendor.mk
