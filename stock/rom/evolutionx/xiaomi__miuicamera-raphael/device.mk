#
# Copyright (C) 2023-2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from the proprietary version
$(call inherit-product, vendor/xiaomi/miuicamera/miuicamera-vendor.mk)

# Overlays
PRODUCT_PACKAGES += \
    MiuiCameraOverlay

# MiuiCamera permission
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/privapp-permissions-miuicamera.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/permissions/privapp-permissions-miuicamera.xml \
    $(LOCAL_PATH)/configs/miuicamera-permissions.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/default-permissions/miuicamera-permissions.xml \
    $(LOCAL_PATH)/configs/public.libraries-xiaomi.txt:$(TARGET_COPY_OUT_SYSTEM)/etc/public.libraries-xiaomi.txt \
    $(LOCAL_PATH)/configs/raphael.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/device_features/raphael.xml \
    $(LOCAL_PATH)/configs/raphaelin.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/device_features/raphaelin.xml

PRODUCT_COPY_FILES += \
    $(call find-copy-subdir-files,*,device/xiaomi/miuicamera/system/priv-app/MiuiCamera/lib/arm64,$(TARGET_COPY_OUT_SYSTEM)/priv-app/MiuiCamera/lib/arm64)

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Sysconfig
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/miuicamera-hiddenapi-package-whitelist.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/sysconfig/miuicamera-hiddenapi-package-whitelist.xml

