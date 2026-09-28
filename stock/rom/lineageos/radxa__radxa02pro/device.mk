#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

## Bluetooth
PRODUCT_PACKAGES += \
    BluetoothOverlayTarget \
    libbt-vendor

$(call soong_config_set,brcm_libbt,bdroid_buildcfg_include_dir,$(LOCAL_PATH)/bluetooth/include)
$(call soong_config_set,brcm_libbt,custom_bt_config,//$(LOCAL_PATH):vnd_radxa02pro.txt)

## Bluetooth firmware
include kernel/amlogic/kernel-modules/dhd-driver/firmware/bluetooth/bluetooth.mk

## Factory
PRODUCT_HOST_PACKAGES += \
    aml_image_packer

## Init
PRODUCT_PACKAGES += \
    init.amlogic.wifi_buildin.rc

## Platform
TARGET_AMLOGIC_SOC := g12b

## TEE
TARGET_HAS_TEE := false

## Soong Namespaces
PRODUCT_SOONG_NAMESPACES += \
    $(LOCAL_PATH) \
    hardware/broadcom/libbt

## Wi-Fi firmware
include kernel/amlogic/kernel-modules/dhd-driver/firmware/wifi/wifi.mk

## Inherit from the common tree product makefile
$(call inherit-product, device/amlogic/g12-common/g12.mk)

## Inherit from the proprietary files makefile
$(call inherit-product, vendor/radxa/radxa02pro/radxa02pro-vendor.mk)
