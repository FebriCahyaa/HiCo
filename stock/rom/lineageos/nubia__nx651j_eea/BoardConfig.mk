#
# Copyright (C) 2018-2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from nubia sm7250-common
-include device/nubia/sm7250-common/BoardConfigCommon.mk

DEVICE_PATH := device/nubia/nx651j_eea

# Assert
TARGET_OTA_ASSERT_DEVICE := nx651j_eea,NX651J-EEA

# HIDL
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += $(DEVICE_PATH)/framework_compatibility_matrix.xml

# Kernel
TARGET_KERNEL_CONFIG := vendor/lineageos_nx651j-eea_defconfig

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Sepolicy
BOARD_VENDOR_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy/vendor

# Inherit from the proprietary version
include vendor/nubia/nx651j_eea/BoardConfigVendor.mk
