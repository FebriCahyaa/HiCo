#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Vendor blobs
$(call inherit-product, vendor/motorola/ocean/ocean-vendor.mk)

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xhdpi

# Audio
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/audio/audio_effects.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_effects.xml \
    $(LOCAL_PATH)/audio/audio_platform_info_tfa987x.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_platform_info_tfa987x.xml \
    $(LOCAL_PATH)/audio/audio_platform_info.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_platform_info.xml \
    $(LOCAL_PATH)/audio/audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_configuration.xml \
    $(LOCAL_PATH)/audio/audio_policy_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_volumes.xml \
    $(LOCAL_PATH)/audio/audio_ext_spkr.conf:$(TARGET_COPY_OUT_VENDOR)/etc/audio_ext_spkr.conf \
    $(LOCAL_PATH)/audio/default_volume_tables.xml:$(TARGET_COPY_OUT_VENDOR)/etc/default_volume_tables.xml \
    $(LOCAL_PATH)/audio/mixer_paths.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths.xml \
    $(LOCAL_PATH)/audio/mixer_paths_tfa987x.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths_tfa987x.xml

# Boot animation
TARGET_SCREEN_HEIGHT := 1520
TARGET_SCREEN_WIDTH := 720

# Init
PRODUCT_PACKAGES += \
    init.ocean.rc

# Lineage Health
PRODUCT_PACKAGES += \
    vendor.lineage.health-service.default

# LiveDisplay
PRODUCT_PACKAGES += \
    vendor.lineage.livedisplay@2.0-service-sysfs

# Moto Camera 2
TARGET_MOTCAMERA2 := denali-2
TARGET_USES_MOTCAMERA2 := true

$(call inherit-product, vendor/motorola/MotCamera2/motcamera2.mk)

# NFC and Secure Element packages
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.nfc.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_nfc/android.hardware.nfc.xml \
    frameworks/native/data/etc/android.hardware.nfc.hce.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_nfc/android.hardware.nfc.hce.xml \
    frameworks/native/data/etc/android.hardware.nfc.hcef.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_nfc/android.hardware.nfc.hcef.xml \
    frameworks/native/data/etc/android.hardware.nfc.uicc.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_nfc/android.hardware.nfc.uicc.xml

PRODUCT_PACKAGES += \
    com.android.nfc_extras \
    Tag \
    android.hardware.nfc@1.2-service.st \
    android.hardware.secure_element@1.0.vendor:64

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    $(LOCAL_PATH)/overlay-lineage

PRODUCT_PACKAGES += \
    FrameworksResDevice \
    SettingsProviderResDevice \
    SystemUIResDevice

PRODUCT_PACKAGES += \
    AvoidAppsInCutoutOverlay \
    NoCutoutOverlay

# Shipping API
PRODUCT_SHIPPING_API_LEVEL := 28

# Telephony
PRODUCT_VENDOR_PROPERTY_BLACKLIST := \
    ro.telephony.default_network \
    ro.vendor.telephony.default_network

# Inherit from motorola sdm632-common
$(call inherit-product, device/motorola/sdm632-common/common.mk)
