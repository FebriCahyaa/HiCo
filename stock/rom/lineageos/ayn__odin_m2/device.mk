#
# Copyright (C) 2026 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sdm845-common
$(call inherit-product, device/ayn/sdm845-common/sdm845.mk)

# Input
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/idc/synaptics_dsx.idc:$(TARGET_COPY_OUT_VENDOR)/usr/idc/synaptics_dsx.idc

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)
