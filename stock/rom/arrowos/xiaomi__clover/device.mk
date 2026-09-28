#
# Copyright (C) 2018-2020 The LineageOS Project
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
#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# Inherit from sdm660-common
$(call inherit-product, device/xiaomi/sdm660-common/sdm660.mk)

DEVICE_PATH := device/xiaomi/clover

# Inherit device properties
$(call inherit-product, $(DEVICE_PATH)/properties.mk)

# Setup dalvik vm configs
$(call inherit-product, frameworks/native/build/phone-xhdpi-4096-dalvik-heap.mk)

# Boot animation
TARGET_SCREEN_HEIGHT := 1920
TARGET_SCREEN_WIDTH := 1200

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    $(DEVICE_PATH)/overlay \
    $(DEVICE_PATH)/overlay-arrow

# Audio
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/audio/audio_platform_info.xml:$(TARGET_COPY_OUT_VENDOR)/etc/audio_platform_info_intcodec.xml \
    $(DEVICE_PATH)/audio/mixer_paths.xml:$(TARGET_COPY_OUT_VENDOR)/etc/mixer_paths.xml \
    $(DEVICE_PATH)/audio/sound_trigger_mixer_paths.xml:$(TARGET_COPY_OUT_VENDOR)/etc/sound_trigger_mixer_paths.xml \
    $(DEVICE_PATH)/audio/sound_trigger_platform_info.xml:$(TARGET_COPY_OUT_VENDOR)/etc/sound_trigger_platform_info.xml

# Display calibration
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/display/qdcm_calib_data_NT51021_BOE_BOE.xml:$(TARGET_COPY_OUT_VENDOR)/etc/qdcm_calib_data_NT51021_BOE_BOE.xml \
    $(DEVICE_PATH)/configs/display/qdcm_calib_data_NT51021_BOE_BOE10.xml:$(TARGET_COPY_OUT_VENDOR)/etc/qdcm_calib_data_NT51021_BOE_BOE10.xml

# Folio daemon
PRODUCT_PACKAGES += \
    folio_daemon

# HW crypto
PRODUCT_PACKAGES += \
    vendor.qti.hardware.cryptfshw@1.0-service-qti.qsee

# Init
PRODUCT_PACKAGES += \
    init.device.rc \
    fstab.qcom

# RIL
PRODUCT_PACKAGES += \
    CarrierConfig \
    Dialer

# Sensors
PRODUCT_COPY_FILES += \
    $(DEVICE_PATH)/configs/sensors/hals.conf:$(TARGET_COPY_OUT_VENDOR)/etc/sensors/hals.conf \
    $(DEVICE_PATH)/configs/sensors/sensor_def_qcomdev.conf:$(TARGET_COPY_OUT_VENDOR)/etc/sensors/sensor_def_qcomdev.conf

# Touchscreen
PRODUCT_PACKAGES += \
    libtinyxml2

# USB
PRODUCT_PACKAGES += \
    android.hardware.usb@1.0-service

# Inherit proprietary files
$(call inherit-product-if-exists, vendor/xiaomi/clover/clover-vendor.mk)
