#
# Copyright (C) 2024 Paranoid Android
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm8550-common
$(call inherit-product, device/xiaomi/sm8550-common/common.mk)

# Get non-open-source specific aspects
$(call inherit-product, vendor/xiaomi/nuwa/nuwa-vendor.mk)

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Kernel Binary
KERNEL_PREBUILT_DIR := device/xiaomi/nuwa-kernel

# Overlays
PRODUCT_PACKAGES += \
    NuwaFrameworks \
    NuwaSettings2210132C \
    NuwaSettings2210132G \
    NuwaSettingsProvider \
    NuwaSystemUI \
    NuwaWifiRes \
    NuwaWifiResMainline \

# Sensors
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.sensor.barometer.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.barometer.xml
