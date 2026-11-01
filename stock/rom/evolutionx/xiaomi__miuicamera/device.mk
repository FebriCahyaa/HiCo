#
# Copyright (C) 2023-2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

MIUICAMERA_DIR := device/xiaomi/miuicamera

# Inherit from the proprietary version
$(call inherit-product, vendor/xiaomi/miuicamera/miuicamera-vendor.mk)

# MiuiCamera permission
PRODUCT_COPY_FILES += \
    $(MIUICAMERA_DIR)/configs/privapp-permissions-miuicamera.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/permissions/privapp-permissions-miuicamera.xml \
    $(MIUICAMERA_DIR)/configs/miuicamera-permissions.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/default-permissions/miuicamera-permissions.xml \
    $(MIUICAMERA_DIR)/configs/public.libraries-xiaomi.txt:$(TARGET_COPY_OUT_SYSTEM)/etc/public.libraries-xiaomi.txt \
    $(MIUICAMERA_DIR)/configs/raphael.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/device_features/raphael.xml \
    $(MIUICAMERA_DIR)/configs/raphaelin.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/device_features/raphaelin.xml

# JNI libraries MiuiCamera loads by name (see configs/public.libraries-xiaomi.txt)
PRODUCT_PACKAGES += \
    libcamera_algoup_jni.xiaomi \
    libcamera_mianode_jni.xiaomi

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(MIUICAMERA_DIR)

# Sysconfig
PRODUCT_COPY_FILES += \
    $(MIUICAMERA_DIR)/configs/miuicamera-hiddenapi-package-whitelist.xml:$(TARGET_COPY_OUT_SYSTEM)/etc/sysconfig/miuicamera-hiddenapi-package-whitelist.xml

