#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

include device/ayn/odin2_ack/device.mk

PRODUCT_CHARACTERISTICS := tablet

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    device/ayn/odin2_tab/overlay

PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/tablet_core_hardware.xml:system/etc/permissions/tablet_core_hardware.xml
