#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Partitions
BOARD_SUPER_PARTITION_SIZE := 14612955136

# Include the common OEM chipset BoardConfig.
include device/oneplus/sm8850-common/BoardConfigCommon.mk

DEVICE_PATH := device/oneplus/iceland

# Assert
TARGET_OTA_ASSERT_DEVICE := OP6547L1,OP657AL1

# Display
TARGET_SCREEN_DENSITY := 420

# Kernel
TARGET_KERNEL_BAZEL_FLAGS += --//vendor/oneplus/sm8850:dtbo_config=//vendor/oneplus/sm8850-devicetrees:iceland_dtbo_config

# Properties
TARGET_ODM_PROP += $(DEVICE_PATH)/properties/odm.prop
TARGET_VENDOR_PROP += $(DEVICE_PATH)/properties/vendor.prop

# Recovery
TARGET_RECOVERY_UI_MARGIN_HEIGHT := 90
TARGET_RECOVERY_DEFAULT_TOUCH_ROTATION := ROTATION_RIGHT

# SEPolicy
include $(DEVICE_PATH)/sepolicy/SEPolicy.mk

# Include the proprietary files BoardConfig.
include vendor/oneplus/iceland/BoardConfigVendor.mk
