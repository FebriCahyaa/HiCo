#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxxhdpi

# Audio
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/audio/mixer_paths_kalama.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_kalama/mixer_paths_kalama_mtp.xml \
    $(LOCAL_PATH)/configs/audio/resourcemanager_kalama.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_kalama/resourcemanager_kalama_mtp.xml

# Boot animation
TARGET_SCREEN_HEIGHT := 2340
TARGET_SCREEN_WIDTH := 1080

# Displayconfig
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/display/display_id_4630947175568309891.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_id_4630947175568309891.xml \
    $(LOCAL_PATH)/configs/display/display_id_4630946481096930692.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_id_4630946481096930692.xml

# Init
PRODUCT_PACKAGES += \
    init.q5q.rc

# Namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Multi Display Bootanimation
$(call soong_config_set_bool,bootanimation,multidisplay,true)

# Overlays
PRODUCT_PACKAGES += \
    FrameworksResq5q

# Power
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/powerhint.json:$(TARGET_COPY_OUT_VENDOR)/etc/powerhint.json

# Touch features
PRODUCT_PACKAGES += \
    vendor.lineage.touch-service.samsung-foldable

# WiFi firmware symlinks
PRODUCT_PACKAGES += \
    firmware_wlanmdsp.otaupdate_symlink \
    firmware_wlan_mac.bin_symlink \
    firmware_WCNSS_qcom_cfg.ini_symlink

# Inherit from the common OEM chipset makefile.
$(call inherit-product, device/samsung/sm8550-common/common.mk)

# Inherit from the proprietary files makefile.
$(call inherit-product, vendor/samsung/q5q/q5q-vendor.mk)
