#
# Copyright (C) 2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# AAPT
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxxhdpi

# Boot animation
TARGET_SCREEN_HEIGHT := 2340
TARGET_SCREEN_WIDTH := 1080

# FlipFlap
PRODUCT_PACKAGES += \
    FlipFlap

# Init
PRODUCT_PACKAGES += \
    init.dm1q.rc

# Namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Overlays Lineage-Specific
PRODUCT_PACKAGES += \
	ApertureResDm1q

# Overlays
PRODUCT_PACKAGES += \
    FlipFlapResDm1q \
    FrameworksResDm1q \
    LineageResDm1q \
    SystemUIResDm1q \
    WifiResTargetDm1q

# SKU properties
PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,$(LOCAL_PATH)/configs/sku/,$(TARGET_COPY_OUT_ODM)/etc/sku_props)

# Touch features
PRODUCT_PACKAGES += \
    vendor.lineage.touch-service.samsung

# WiFi firmware symlinks
PRODUCT_PACKAGES += \
    firmware_wlanmdsp.otaupdate_symlink \
    firmware_wlan_mac.bin_symlink \
    firmware_WCNSS_qcom_cfg.ini_symlink

# Inherit from the common OEM chipset makefile.
$(call inherit-product, device/samsung/sm8550-common/common.mk)

# Inherit from the proprietary files makefile.
$(call inherit-product, vendor/samsung/dm1q/dm1q-vendor.mk)
