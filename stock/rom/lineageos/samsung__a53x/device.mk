#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit the common tree
$(call inherit-product, device/samsung/s5e8825-common/common.mk)

# Inherit the phone-specific configuration
$(call inherit-product, device/samsung/s5e8825-common/products/phone/product.mk)

# Inherit the device-specific vendor configuration
$(call inherit-product, vendor/samsung/a53x/a53x-vendor.mk)

# Audio - Configuration
PRODUCT_PACKAGES += mixer_paths.xml

# Audio - Effects - SoundBooster
$(call soong_config_set,samsungAudioVars,soundbooster_dsp_library,//vendor/samsung/a53x:lib_SoundBooster_ver1100)

# Display - AOD
$(call inherit-product, device/samsung/s5e8825-common/products/aod/product.mk)

# Display - Configuration
PRODUCT_PACKAGES += displayconfig.xml

# Fingerprint
$(call inherit-product, device/samsung/s5e8825-common/products/udfps/product.mk)

# Init
PRODUCT_PACKAGES += init.a53x.rc

# Installer
TARGET_ANDROID_INFO_EXTRA_FILE := device/samsung/a53x/configs/installer/android-info-extra.txt

# NFC
$(call inherit-product, device/samsung/s5e8825-common/products/sec_nfc/product.mk)

# NFC - eSE
PRODUCT_PACKAGES += android.hardware.secure_element-service.thales-st33

# Overlays
PRODUCT_PACKAGES += \
    FrameworkResOverlayDevice \
    SettingsProviderOverlayDevice \
    SystemUIOverlayDevice \
    WiFiOverlayDevice

# Permissions
PRODUCT_PACKAGES += \
    android.hardware.nfc.ese.prebuilt.xml \
    android.hardware.se.omapi.ese.prebuilt.xml

# Properties
TARGET_VENDOR_PROP += device/samsung/a53x/configs/props/vendor.prop

# RIL
TARGET_HAS_RIL := true

# Shipping level
PRODUCT_SHIPPING_API_LEVEL := 31

# Soong - Namespaces
PRODUCT_SOONG_NAMESPACES += device/samsung/a53x

# Unify
$(call inherit-product, device/samsung/s5e8825-common/products/unify/product.mk)
