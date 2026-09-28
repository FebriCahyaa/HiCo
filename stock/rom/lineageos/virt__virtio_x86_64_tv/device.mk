#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# ATV
PRODUCT_IS_ATV := true

# Inherit from device
$(call inherit-product, device/virt/virtio_x86_64/device.mk)

DEVICE_PRODUCT_PATH := device/virt/virtio_x86_64_tv

# Characteristics
PRODUCT_CHARACTERISTICS := tv

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(DEVICE_PRODUCT_PATH)
