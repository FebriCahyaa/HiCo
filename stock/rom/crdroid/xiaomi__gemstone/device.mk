#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm6375-common
$(call inherit-product, device/xiaomi/sm6375-common/common.mk)

# Audio
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/audio,$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_holi)

PRODUCT_COPY_FILES += \
    frameworks/av/services/audiopolicy/config/default_volume_tables.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_holi/default_volume_tables.xml

# Display
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/display_id_4630947218746568833.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_id_4630947218746568833.xml \
    $(LOCAL_PATH)/configs/qdcm_calib_data_xiaomi_m17_38_0c_0a_fhd_dsc_video_dsi_panel.xml:$(TARGET_COPY_OUT_VENDOR)/etc/qdcm_calib_data_xiaomi_m17_38_0c_0a_fhd_dsc_video_dsi_panel.xml

# Init
$(call soong_config_set,libinit,vendor_init_lib,//$(LOCAL_PATH):init_xiaomi_gemstone)

# Nfc
PRODUCT_PACKAGES += \
    com.android.nfc_extras \
    Tag

PRODUCT_PACKAGES += \
    android.hardware.nfc-service.st

$(foreach sku, moonstone_p_global sunstone_global, \
    $(eval PRODUCT_COPY_FILES += \
        frameworks/native/data/etc/android.hardware.nfc.hce.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/android.hardware.nfc.hce.xml \
        frameworks/native/data/etc/android.hardware.nfc.hcef.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/android.hardware.nfc.hcef.xml \
        frameworks/native/data/etc/android.hardware.nfc.uicc.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/android.hardware.nfc.uicc.xml \
        frameworks/native/data/etc/android.hardware.nfc.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/android.hardware.nfc.xml \
        frameworks/native/data/etc/android.hardware.se.omapi.uicc.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/android.hardware.se.omapi.uicc.xml \
        frameworks/native/data/etc/com.android.nfc_extras.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/com.android.nfc_extras.xml \
        frameworks/native/data/etc/com.nxp.mifare.xml:$(TARGET_COPY_OUT_ODM)/etc/permissions/sku_$(sku)/com.nxp.mifare.xml))

# Overlay
PRODUCT_PACKAGES += \
    ApertureOverlayGemstone \
    FrameworkOverlayGemstone \
    FrameworkOverlayMoonstoneGl \
    FrameworkOverlayMoonstoneIn \
    SettingsProviderOverlayMoonstoneGl \
    SettingsProviderOverlayMoonstoneIn \
    SettingsProviderOverlaySunstoneCn \
    SettingsProviderOverlaySunstoneGl \
    SettingsProviderOverlaySunstoneX \
    WifiOverlayMoonstoneGl \
    WifiOverlayMoonstoneIn \
    WifiOverlaySunstoneCn \
    WifiOverlaySunstoneGl \
    WifiOverlaySunstoneX

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/rro_overlays/config-odm.xml:$(TARGET_COPY_OUT_ODM)/overlay/config/config.xml

# Sku properties
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/sku/,$(TARGET_COPY_OUT_ODM)/etc)

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Rootdir
PRODUCT_PACKAGES += \
    init.device.rc

# Call the proprietary setup
$(call inherit-product, vendor/xiaomi/gemstone/gemstone-vendor.mk)
