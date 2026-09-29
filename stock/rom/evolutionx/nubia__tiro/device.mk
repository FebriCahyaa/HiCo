#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from nubia sm8650-common
$(call inherit-product, device/nubia/sm8650-common/common.mk)

DEVICE_PATH := device/nubia/tiro

# Audio
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/audio/mixer_paths_pineapple_mtp.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio/sku_pineapple/mixer_paths_pineapple_mtp.xml

# Display
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/display_id_4630947039571902851.xml:$(TARGET_COPY_OUT_VENDOR)/etc/displayconfig/display_id_4630947039571902851.xml

# Media
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/media_profiles_pineapple.xml:$(TARGET_COPY_OUT_VENDOR)/etc/media_profiles_pineapple.xml

# Soong
PRODUCT_SOONG_NAMESPACES += \
    $(DEVICE_PATH)

# Overlays
PRODUCT_PACKAGES += \
    SettingsProviderResTiro \
    ApertureResTiro

# NubiaParts
PRODUCT_PACKAGES += \
    NubiaFanControl \
    NubiaGameKeys

# Inherit from proprietary targets
$(call inherit-product, vendor/nubia/tiro/tiro-vendor.mk)
