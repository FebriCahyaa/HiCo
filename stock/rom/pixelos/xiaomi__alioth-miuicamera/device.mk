#
# Copyright (C) 2026 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from the proprietary version
$(call inherit-product, vendor/xiaomi/alioth-miuicamera/alioth-miuicamera-vendor.mk)

# Camera
$(call soong_config_set_bool,camera,override_format_from_reserved,true)

# Public libraries
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/public.libraries-xiaomi.txt:$(TARGET_COPY_OUT_SYSTEM)/etc/public.libraries-xiaomi.txt

# Priv-app permissions
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/privapp-permissions-miuicamera.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/permissions/privapp-permissions-miuicamera.xml \
    $(LOCAL_PATH)/configs/privapp-permissions-miuiextraphoto.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/permissions/privapp-permissions-miuiextraphoto.xml

# Permissions
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/gson.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/permissions/gson.xml

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH)

# Sysconfig
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/miuicamera-hiddenapi-package-allowlist.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/sysconfig/miuicamera-hiddenapi-package-allowlist.xml

# Device features
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/device_features/alioth.xml:$(TARGET_COPY_OUT_PRODUCT)/etc/device_features/alioth.xml \
    $(LOCAL_PATH)/configs/device_features/aliothin.xml:$(TARGET_COPY_OUT_PRODUCT)/etc/device_features/aliothin.xml

# RRO Overlays
PRODUCT_PACKAGES += \
    MiuiCameraAliothOverlay


