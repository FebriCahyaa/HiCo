#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

CAMERA_PATH := device/xiaomi/taoyao-camera

# Properties
TARGET_PRODUCT_PROP += $(CAMERA_PATH)/product.prop
TARGET_SYSTEM_PROP += $(CAMERA_PATH)/system.prop

# Sepolicy
BOARD_VENDOR_SEPOLICY_DIRS += $(CAMERA_PATH)/sepolicy/vendor