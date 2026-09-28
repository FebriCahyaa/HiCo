#
# Copyright (C) 2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from xiaomi sm8550-common
$(call inherit-product, device/xiaomi/sm8550-common/common.mk)

# Audio
# The common audio product installs generic kalama MTP files to these same
# destinations. Drop those entries before installing ishtar's Cirrus/TDM
# topology so PRODUCT_COPY_FILES de-duplication cannot select the WSA config.
# sm8550-common's backend_conf also lacks WCD RX-1; replace it with stock.
PRODUCT_COPY_FILES := $(filter-out \
    %:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_kalama/mixer_paths_kalama_mtp.xml \
    %:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_kalama/resourcemanager_kalama_mtp.xml \
    %:$(TARGET_COPY_OUT_ODM)/etc/backend_conf.xml, \
    $(PRODUCT_COPY_FILES))

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/audio/mixer_paths_kalama_mtp.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_kalama/mixer_paths_kalama_mtp.xml \
    $(LOCAL_PATH)/audio/resourcemanager_kalama_mtp.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_kalama/resourcemanager_kalama_mtp.xml \
    $(LOCAL_PATH)/audio/usecaseKvManager.xml:$(TARGET_COPY_OUT_VENDOR)/etc/usecaseKvManager.xml \
    $(LOCAL_PATH)/audio/backend_conf.xml:$(TARGET_COPY_OUT_ODM)/etc/backend_conf.xml
    
# Fingerprint
TARGET_HAS_UDFPS := true

# Haptics
PRODUCT_COPY_FILES += \
    vendor/xiaomi/ishtar/proprietary/vendor/etc/vibrator/effect_0.bin:$(TARGET_COPY_OUT_VENDOR)/etc/vibrator/primitive_effect_1.bin \
    vendor/xiaomi/ishtar/proprietary/vendor/etc/vibrator/effect_2.bin:$(TARGET_COPY_OUT_VENDOR)/etc/vibrator/primitive_effect_7.bin

# IFAAService
PRODUCT_PACKAGES += \
    IFAAService

# Init
PRODUCT_PACKAGES += \
    init.ishtar.rc

# NFC
TARGET_USES_ST_NFC := true

# Overlay
PRODUCT_PACKAGES += \
    ApertureOverlayIshtar \
    FrameworkResOverlayIshtar \
    SettingsOverlayIshtar \
    SettingsProviderResIshtar \
    SystemUIOverlayIshtar \
    WifiResIshtar

# PowerShare
$(call soong_config_set,lineage_powershare,powershare_path,/sys/class/qcom-battery/reverse_chg_mode)
PRODUCT_PACKAGES += \
    vendor.lineage.powershare-service.default

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Vibrator
PRODUCT_COPY_FILES += \
    vendor/xiaomi/ishtar/proprietary/vendor/etc/vibrator/effect_0.bin:$(TARGET_COPY_OUT_VENDOR)/etc/vibrator/primitive_effect_1.bin \
    vendor/xiaomi/ishtar/proprietary/vendor/etc/vibrator/effect_2.bin:$(TARGET_COPY_OUT_VENDOR)/etc/vibrator/primitive_effect_7.bin

# Inherit from the proprietary version
$(call inherit-product, vendor/xiaomi/ishtar/ishtar-vendor.mk)
