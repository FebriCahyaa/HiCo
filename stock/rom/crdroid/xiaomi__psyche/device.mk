#
# Copyright (C) 2021 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Fingerprint
TARGET_HAS_UDFPS := true

# Inherit from sm8250-common
$(call inherit-product, device/xiaomi/sm8250-common/kona.mk)

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

# A/B
TARGET_IS_VAB := true

# Audio configs
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/audio/,$(TARGET_COPY_OUT_VENDOR)/etc)

# Boot animation
TARGET_SCREEN_HEIGHT := 2400
TARGET_SCREEN_WIDTH := 1080

# Camera
PRODUCT_PACKAGES += \
    libpiex_shim

$(call inherit-product-if-exists, vendor/xiaomi/camera/miuicamera.mk)

# Init
$(call soong_config_set,xiaomi_kona,variant_lib,//$(LOCAL_PATH):libvariant_xiaomi_psyche)

# Overlays
PRODUCT_PACKAGES += \
    ApertureOverlayDevice \
    FrameworkResOverlayDevice \
    SettingsCNOverlayDevice \
    SettingsGLOverlayDevice \
    SettingsOverlayDevice \
    SettingsProviderOverlayDevice \
    SystemUIOverlayDevice

# Shipping API level
PRODUCT_SHIPPING_API_LEVEL := 30

# Sensors
PRODUCT_PACKAGES += \
    sensors.udfps

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/sensors/hals.conf:$(TARGET_COPY_OUT_VENDOR)/etc/sensors/hals.conf

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Set support hide display cutout feature
PRODUCT_PRODUCT_PROPERTIES += \
    ro.support_hide_display_cutout=true

PRODUCT_PACKAGES += \
    NoCutoutOverlay \
    AvoidAppsInCutoutOverlay

# Thermal Config
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/configs/thermal/,$(TARGET_COPY_OUT_VENDOR)/etc/)

# WiFi
PRODUCT_PACKAGES += \
    WifiResourcesOverlayDevice

# Inherit from vendor blobs
$(call inherit-product, vendor/xiaomi/psyche/psyche-vendor.mk)
