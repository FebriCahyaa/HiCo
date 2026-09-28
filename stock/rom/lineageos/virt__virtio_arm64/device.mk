#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from common
$(call inherit-product, device/virt/virtio-common/device-common.mk)

DEVICE_PATH := device/virt/virtio_arm64

# Kernel (Prebuilt)
TARGET_PREBUILT_KERNEL_ARCH := arm64

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(DEVICE_PATH)
