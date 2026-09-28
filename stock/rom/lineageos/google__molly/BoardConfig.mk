#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/google/molly

# Architecture
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_VARIANT := cortex-a15

# Audio
BOARD_USES_ALSA_AUDIO := true
BOARD_USES_TINY_ALSA_AUDIO := true

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(DEVICE_PATH)/bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_MRVL := true

# Board
TARGET_BOARD_PLATFORM := tegra4
TARGET_BOOTLOADER_BOARD_NAME := molly
TARGET_NO_BOOTLOADER := true
TARGET_NO_RADIOIMAGE := true

# dlmalloc
MALLOC_IMPL := dlmalloc

# Graphics
# CFLAGS: Disable Secure Discard
# CFLAGS: Disable ashmem tracking to prevent GL crash
COMMON_GLOBAL_CFLAGS += -DNO_SECURE_DISCARD -DDISABLE_ASHMEM_TRACKING
USE_OPENGL_RENDERER := true
SF_VSYNC_EVENT_PHASE_OFFSET_NS := 1

# Kernel
BOARD_KERNEL_CMDLINE := androidboot.hardware=molly console=ttyFIQ0 smsc95xx.boot_wol_config=0x07 smsc95xx.turbo_mode=N
KERNEL_TOOLCHAIN := $(ANDROID_BUILD_TOP)/prebuilts/gcc/$(HOST_OS)-x86/arm/arm-eabi-4.8/bin
KERNEL_TOOLCHAIN_PREFIX := arm-eabi-
TARGET_KERNEL_CONFIG := molly_defconfig
TARGET_KERNEL_SOURCE := kernel/google/molly

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 8388608
BOARD_CACHEIMAGE_PARTITION_SIZE := 734003200
BOARD_FLASH_BLOCK_SIZE := 4096
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 8388608
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1073741824
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13912506368
TARGET_USERIMAGES_USE_EXT4 := true

# Recovery
LZMA_RAMDISK_TARGETS := recovery
TARGET_RECOVERY_DENSITY := hdpi
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/rootdir/fstab.molly

# SELinux
BOARD_SEPOLICY_DIRS := $(DEVICE_PATH)/sepolicy

# Wi-Fi
BOARD_HAVE_MARVELL_WIFI          := true
BOARD_HOSTAPD_DRIVER             := NL80211
BOARD_HOSTAPD_PRIVATE_LIB        := lib_driver_cmd_mrvl
BOARD_WLAN_DEVICE                := mrvl
BOARD_WPA_SUPPLICANT_DRIVER      := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_mrvl
WIFI_DRIVER_FW_PATH_AP           := "/vendor/firmware/mrvl/sd8797_uapsta.bin"
WIFI_DRIVER_FW_PATH_PARAM        := "/dev/null"
WIFI_DRIVER_FW_PATH_STA          := "/vendor/firmware/mrvl/sd8797_uapsta.bin"
WPA_SUPPLICANT_VERSION           := VER_0_8_X

# Inherit proprietary configuration
include vendor/google/molly/BoardConfigVendor.mk
