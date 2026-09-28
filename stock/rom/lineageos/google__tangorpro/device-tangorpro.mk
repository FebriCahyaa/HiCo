#
# SPDX-FileCopyrightText: 2021 The Android Open-Source Project
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-FileCopyrightText: The Calyx Institute
# SPDX-License-Identifier: Apache-2.0
#

# Kernel
TARGET_LINUX_KERNEL_VERSION := 6.1
TARGET_KERNEL_DEVICE := tangorpro
TARGET_KERNEL_DIR := device/google/$(TARGET_KERNEL_DEVICE)-kernels/$(TARGET_LINUX_KERNEL_VERSION)
TARGET_KERNEL_PLATFORM_SOURCE := google/gs-$(TARGET_LINUX_KERNEL_VERSION)

# Identify the device type.
# This flag need to be set before device/google/gs201/common.mk
TARGET_IS_TABLET := true

# Inherit from gs201
include device/google/gs201/common.mk

# GMS
WITH_GMS_COMMS_SUITE := false

# Lights HAL
PRODUCT_PACKAGES += \
    android.hardware.lights-service.tangorpro

# Overlays
PRODUCT_PACKAGES += \
    BiometricGs201Overlay \
    CompanionDeviceManagerOverlayTangorpro \
    FrameworkResOverlayProductTangorpro \
    FrameworkResOverlayTangorpro \
    FrameworkResOverlayVendorTangorpro \
    GoogleConfigSideFpsOverlay \
    LargeScreenConfigOverlay \
    PixelUwbOverlayT6proTangorpro \
    PixelWifiOverlay2023_T6proGs201 \
    PixelWifiOverlay2023_T6proTangorpro \
    SafetyRegulatoryInfoOverlayProductTangorpro \
    SconeCoexOverlayTangotron \
    SettingsGoogleNoTelephonyOverlay \
    SettingsGoogleOverlayProductTangorpro \
    SettingsGoogleTangorproOverlay \
    SettingsOverlayGTU8P \
    SettingsProviderOverlayProductTangorpro \
    SfpsOverlayGs201 \
    SfpsOverlayTabletTangorpro \
    SystemUITitanOverlayProductTangorpro \
    SystemUITitanOverlayVendorTangorpro \
    TeleServiceOverlayTangorpro \
    TelephonyProviderOverlayTangorpro \
    TitanConfigOverlay \
    TitanNexusLauncherOverlay \
    TitanSettingsOverlay \
    TitanSettingsProviderOverlay \
    TitanSysuiConfigOverlay

# Properties
TARGET_PRODUCT_PROP += $(DEVICE_PATH)/$(DEVICE_CODENAME)/product.prop
TARGET_VENDOR_PROP += $(DEVICE_PATH)/$(DEVICE_CODENAME)/vendor.prop

# Recovery
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/recovery/init.recovery.device.rc:$(TARGET_COPY_OUT_RECOVERY)/root/init.recovery.tangorpro.rc

PRODUCT_PACKAGES += \
    init.recovery.tangorpro.touch.rc

TARGET_RECOVERY_DEFAULT_ROTATION := ROTATION_LEFT
TARGET_RECOVERY_DEFAULT_TOUCH_ROTATION := $(TARGET_RECOVERY_DEFAULT_ROTATION)

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(DEVICE_PATH) \
    hardware/synaptics/wlan/synadhd/config

# Telecom
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.software.telecom.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.software.telecom.xml

# UWB
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.uwb.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.uwb.xml

# VINTF
DEVICE_MANIFEST_FILE += \
    $(DEVICE_PATH)/vintf/manifest.xml
DEVICE_PRODUCT_COMPATIBILITY_MATRIX_FILE += \
    $(DEVICE_PATH)/vintf/device_framework_matrix_product.xml
