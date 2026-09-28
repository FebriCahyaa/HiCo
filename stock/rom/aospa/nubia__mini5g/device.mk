#
# Copyright (C) 2019 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

# Enable updating of APEXes
$(call inherit-product, $(SRC_TARGET_DIR)/product/updatable_apex.mk)

# Platform
TARGET_BOARD_PLATFORM := msmnile

# Properties
-include $(LOCAL_PATH)/system_prop.mk

# Overlays
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

# Device uses high-density artwork where available
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

# Audio
PRODUCT_PACKAGES += \
    audio.a2dp.default

# Camera
PRODUCT_PACKAGES += \
    Snap

# Display
PRODUCT_PACKAGES += \
    libvulkan

# HIDL
PRODUCT_PACKAGES += \
    libhidltransport \
    libhwbinder

# IMS
PRODUCT_PACKAGES += \
    ims-ext-common \
    ims_ext_common.xml

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.telephony.ims.xml:system/etc/permissions/android.hardware.telephony.ims.xml

# Input
PRODUCT_PACKAGES += \
    AuxiliaryKeyHandler \
    AOSPAMini5GAuxiliaryKeyHandler

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/keylayout/gpio-keys.kl:system/usr/keylayout/gpio-keys.kl

# Net
PRODUCT_PACKAGES += \
    netutils-wrapper-1.0

# QTI Components
TARGET_COMMON_QTI_COMPONENTS := \
    bt \
    display \
    gps \
    perf \
    telephony \
    wfd

# Telephony
PRODUCT_PACKAGES += \
    qti-telephony-utils \
    qti_telephony_utils.xml \
    qti-telephony-hidl-wrapper \
    qti_telephony_hidl_wrapper.xml

# TextClassifier
PRODUCT_PACKAGES += \
    textclassifier.bundle1
