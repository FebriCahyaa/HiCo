#
# Copyright (C) 2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_full.mk)

DEVICE_NAME := style3lm
PRODUCT_USE_DYNAMIC_PARTITIONS := true

# Include from common device configuration
$(call inherit-product, device/lge/sdm845-common/sdm845.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    $(LOCAL_PATH)/overlay \
    $(LOCAL_PATH)/overlay-lineage

PRODUCT_PACKAGES += \
    FrameworksOverlayStyle3

# Audio
PRODUCT_PACKAGES += \
    audio_amplifier.lge

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/audio/audio_platform_info.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_platform_info.xml \
    $(LOCAL_PATH)/audio/audio_policy_configuration.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_configuration.xml \
    $(LOCAL_PATH)/audio/audio_policy_volumes.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_policy_volumes.xml \
    $(LOCAL_PATH)/audio/default_volume_tables.xml:$(TARGET_COPY_OUT_VENDOR)/etc/default_volume_tables.xml \
    $(LOCAL_PATH)/audio/mixer_paths_tavil.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths_tavil.xml \
    $(LOCAL_PATH)/audio/sound_trigger_mixer_paths_wcd9340.xml:$(TARGET_COPY_OUT_VENDOR)/etc/sound_trigger_mixer_paths_wcd9340.xml \
    $(LOCAL_PATH)/audio/sound_trigger_platform_info.xml:$(TARGET_COPY_OUT_VENDOR)/etc/sound_trigger_platform_info.xml

# Fingerprint
PRODUCT_PACKAGES += \
    android.hardware.biometrics.fingerprint-service.lineage

# Init
PRODUCT_COPY_FILES += \
    device/lge/sdm845-common/rootdir/etc/fstab.dynamic:$(TARGET_COPY_OUT_RAMDISK)/fstab.style3lm \
    device/lge/sdm845-common/rootdir/etc/fstab.dynamic:$(TARGET_COPY_OUT_VENDOR)/etc/fstab.style3lm

# LiveDisplay
$(call soong_config_set,livedisplay_lge,enable_se,true)

# NFC
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/nfc/libnfc-cxd-RF.conf:$(TARGET_COPY_OUT_VENDOR)/etc/libnfc-cxd-RF.conf \
    $(LOCAL_PATH)/nfc/libnfc-cxd22xx.conf:$(TARGET_COPY_OUT_VENDOR)/etc/libnfc-cxd22xx.conf \
    $(LOCAL_PATH)/nfc/libnfc-nci.conf:$(TARGET_COPY_OUT_VENDOR)/etc/libnfc-nci.conf

# Permissions
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.sensor.hifi_sensors.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.sensor.hifi_sensors.xml

# Soong namespaces
PRODUCT_SOONG_NAMESPACES += \
	$(LOCAL_PATH)

# Sensors
PRODUCT_PACKAGES += \
    android.hardware.sensors@2.0-service.multihal

# Vibrator
PRODUCT_PACKAGES += \
    vendor.qti.hardware.vibrator.service

# Wi-Fi Overlay
PRODUCT_PACKAGES += \
    WifiOverlayStyle3

# Get non-open-source specific aspects
$(call inherit-product, vendor/lge/style3lm/style3lm-vendor.mk)
