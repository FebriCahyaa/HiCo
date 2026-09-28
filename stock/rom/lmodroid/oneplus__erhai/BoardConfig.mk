#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Partitions
BOARD_SUPER_PARTITION_SIZE := 11711471616

# Include the common OEM chipset BoardConfig.
include device/oneplus/sm8750-common/BoardConfigCommon.mk

DEVICE_PATH := device/oneplus/erhai

# Assert
TARGET_OTA_ASSERT_DEVICE := OP615EL1,OP6190L1

# Display
TARGET_SCREEN_DENSITY := 420

# Kernel
TARGET_KERNEL_ADDITIONAL_FLAGS += CONFIG_ERHAI_DTB=y OPLUS_WIFI_ONLY=true

# Power
TARGET_TAP_TO_WAKE_NODE := "/proc/touchpanel/double_tap_enable"

# Properties
TARGET_ODM_PROP += $(DEVICE_PATH)/odm.prop
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Recovery
TARGET_RECOVERY_DEFAULT_TOUCH_ROTATION := ROTATION_RIGHT

# SEPolicy
include $(DEVICE_PATH)/sepolicy/SEPolicy.mk

# Include the proprietary files BoardConfig.
include vendor/oneplus/erhai/BoardConfigVendor.mk
