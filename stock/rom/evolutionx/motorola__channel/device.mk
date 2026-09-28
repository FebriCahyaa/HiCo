#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Vendor blobs
$(call inherit-product, vendor/motorola/channel/channel-vendor.mk)

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xhdpi

# Audio
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/audio/audio_effects.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_effects.xml \
    $(LOCAL_PATH)/audio/audio_platform_info_tas2560.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_platform_info_tas2560.xml \
    $(LOCAL_PATH)/audio/audio_platform_info.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_platform_info.xml \
    $(LOCAL_PATH)/audio/audio_ext_spkr.conf:$(TARGET_COPY_OUT_VENDOR)/etc/audio_ext_spkr.conf \
    $(LOCAL_PATH)/audio/audio_policy_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_volumes.xml \
    $(LOCAL_PATH)/audio/default_volume_tables.xml:$(TARGET_COPY_OUT_VENDOR)/etc/default_volume_tables.xml \
    $(LOCAL_PATH)/audio/mixer_paths_tas2560.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths_tas2560.xml \
    $(LOCAL_PATH)/audio/mixer_paths.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths.xml

# Boot animation
TARGET_SCREEN_HEIGHT := 1512
TARGET_SCREEN_WIDTH := 720

# Health
$(call soong_config_set,lineage_health,charging_control_charging_path,/sys/class/power_supply/battery/battery_charging_enabled)

# Init
PRODUCT_PACKAGES += \
    init.audio.specified_para.sh \
    init.channel.rc

# LiveDisplay
PRODUCT_PACKAGES += \
    vendor.lineage.livedisplay@2.0-service-sysfs

# Moto Camera 2
TARGET_MOTCAMERA2 := denali-2
TARGET_USES_MOTCAMERA2 := true

$(call inherit-product, vendor/motorola/MotCamera2/motcamera2.mk)

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

# Radio
PRODUCT_PACKAGES += \
    android.hardware.secure_element@1.0.vendor:64

# Shipping API
PRODUCT_SHIPPING_API_LEVEL := 28

# Inherit from motorola sdm632-common
$(call inherit-product, device/motorola/sdm632-common/common.mk)
