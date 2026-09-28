#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/khadas/kvim

## Bluetooth
BOARD_HAVE_BLUETOOTH := true

## Bootloader
TARGET_BOOTLOADER_BOARD_NAME := kvim

## DTB
TARGET_DTB_NAME := kvim

## Kernel modules
TARGET_KERNEL_EXT_MODULES := \
    dhd-driver/bcmdhd.101.10.591.x

## Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

## Wi-Fi
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_bcmdhd
BOARD_WLAN_DEVICE := bcmdhd
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_bcmdhd
WIFI_DRIVER_FW_PATH_STA := "/wifi/fw_bcm43438a1.bin"
WIFI_DRIVER_FW_PATH_PARAM := "/sys/module/dhd/parameters/firmware_path"
WPA_SUPPLICANT_VERSION := VER_0_8_X

## Include the common tree BoardConfig makefile
include device/amlogic/gx-common/BoardConfigCommon.mk

## Include the proprietary BoardConfig makefile
include vendor/khadas/kvim/BoardConfigVendor.mk
