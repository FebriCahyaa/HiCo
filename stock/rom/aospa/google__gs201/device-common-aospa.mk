#
# Copyright (C) 2022 Paranoid Android
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

# Enable updating of APEXes
$(call inherit-product, $(SRC_TARGET_DIR)/product/updatable_apex.mk)

# Camera
PRODUCT_PRODUCT_PROPERTIES += \
    ro.vendor.camera.extensions.package=com.google.android.apps.camera.services \
    ro.vendor.camera.extensions.service=com.google.android.apps.camera.services.extensions.service.PixelExtensions

# ConnectivityThermalPowermanager
include hardware/google/pixel/connectivity_thermal_power_manager/connectivity_thermal_power_manager.mk

# EUICC
PRODUCT_PACKAGES += \
    EuiccSupportPixelOverlay

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.telephony.euicc.xml:$(TARGET_COPY_OUT_PRODUCT)/etc/permissions/android.hardware.telephony.euicc.xml

# Manifests
DEVICE_MANIFEST_FILE += \
    device/google/gs201/android.hardware.security.rkp-service.citadel.xml \
    device/google/gs201/manifest_radio_ds.xml

# Properties
TARGET_VENDOR_PROP := device/google/gs201/vendor.prop

# Remove Packages
PRODUCT_PACKAGES += \
    RemovePackages

# Soong Namespaces
PRODUCT_SOONG_NAMESPACES += \
    packages/modules/Bluetooth/android/app

# Telephony
PRODUCT_PACKAGES += \
    TelephonyOverlay
