#
# Copyright (C) 2020 The MoKee Open Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from meizu sdm710-common
-include device/meizu/sdm710-common/BoardConfigCommon.mk

DEVICE_PATH := device/meizu/m1852

# Assertion
TARGET_OTA_ASSERT_DEVICE := m1852,M1852

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth/include

# Kernel
BOARD_KERNEL_CMDLINE += g_android.luns=1 g_android.removable=1 g_android.cdrom=1
TARGET_PREBUILT_KERNEL := $(DEVICE_PATH)/prebuilt/Image.gz-dtb

# HAX: Remove ASAP
BOARD_KERNEL_CMDLINE += androidboot.selinux=permissive

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Properties
TARGET_SYSTEM_PROP += $(DEVICE_PATH)/system.prop

# Releasetools
TARGET_BOARD_INFO_FILE := $(DEVICE_PATH)/board-info.txt

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += $(DEVICE_PATH)

# inherit from the proprietary version
-include vendor/meizu/m1852/BoardConfigVendor.mk

# Treble
# we gonna try that hope it works
BOARD_PROPERTY_OVERRIDES_SPLIT_ENABLED := true
BOARD_VNDK_VERSION := current
PRODUCT_VENDOR_MOVE_ENABLED := true
