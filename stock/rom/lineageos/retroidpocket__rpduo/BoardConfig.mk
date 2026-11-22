#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/retroidpocket/RPDuo

# Include the common OEM chipset BoardConfig.
include device/retroidpocket/cq7790s-common/BoardConfigCommon.mk

# DTBO
TARGET_MERGE_DTBOS_WILDCARD := *retroid-pocket-duo-overlay*

# Properties
DEVICE_PROPERTIES_PATH := $(DEVICE_PATH)/properties
TARGET_VENDOR_PROP += $(DEVICE_PROPERTIES_PATH)/vendor.prop

# Recovery
TARGET_RECOVERY_DEFAULT_ROTATION := ROTATION_LEFT
TARGET_RECOVERY_DEFAULT_TOUCH_ROTATION := ROTATION_RIGHT

# Include the proprietary files BoardConfig.
include vendor/retroidpocket/RPDuo/BoardConfigVendor.mk
