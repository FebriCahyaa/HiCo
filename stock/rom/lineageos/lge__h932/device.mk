#
# Copyright (C) 2018-2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/lge/h932

PRODUCT_SOONG_NAMESPACES += \
    $(DEVICE_PATH)

# common v30
$(call inherit-product, device/lge/joan-common/joan.mk)

# Inherit proprietary blobs
$(call inherit-product, vendor/lge/h932/h932-vendor.mk)
