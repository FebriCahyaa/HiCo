#
# SPDX-FileCopyrightText: 2025 The Evolution X Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from the proprietary version
include vendor/xiaomi/miuicamera-beryllium/BoardConfigVendor.mk

MIUICAMERA_PATH := device/xiaomi/miuicamera-beryllium

# Properties
TARGET_SYSTEM_PROP += $(MIUICAMERA_PATH)/system.prop
TARGET_PRODUCT_PROP += $(MIUICAMERA_PATH)/product.prop

# Sepolicy
SYSTEM_EXT_PRIVATE_SEPOLICY_DIRS += \
    $(MIUICAMERA_PATH)/sepolicy/private
