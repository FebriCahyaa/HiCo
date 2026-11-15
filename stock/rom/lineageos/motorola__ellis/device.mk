#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Setup dalvik vm configs
$(call inherit-product, frameworks/native/build/phone-xhdpi-2048-dalvik-heap.mk)

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xhdpi

# Display
TARGET_SCREEN_HEIGHT := 1600
TARGET_SCREEN_WIDTH := 720

# Overlays
PRODUCT_PACKAGES += \
    FrameworkResOverlayEllis \
    SettingsProviderOverlayEllis \
    SystemUIOverlayEllis

# Shipping API Level
PRODUCT_SHIPPING_API_LEVEL := 30

# Sensors
$(call soong_config_set,android_hardware_sensors_aidl_multihal,run_32bit,true)

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Inherit the proprietary files
$(call inherit-product, vendor/motorola/ellis/ellis-vendor.mk)
