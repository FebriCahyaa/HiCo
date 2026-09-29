#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

COMMON_PATH := device/amlogic/gx-common

## Architecture
TARGET_CPU_VARIANT_RUNTIME := cortex-a53

## BUILD_BROKEN_*
# Needed for systemcontrol blobs copy-files to recovery via TARGET_RECOVERY_DEVICE_DIRS
BUILD_BROKEN_ELF_PREBUILT_PRODUCT_COPY_FILES := true

## Kernel
BOARD_KERNEL_CMDLINE := use_uvm=1
ifeq ($(TARGET_BOOTDEVICE),usb)
  BOARD_KERNEL_CMDLINE += androidboot.boot_devices=c9000000.dwc3
else ifeq ($(TARGET_BOOTDEVICE),sdcard)
  BOARD_KERNEL_CMDLINE += androidboot.boot_devices=d0072000.sd
else
  BOARD_KERNEL_CMDLINE += androidboot.boot_devices=d0074000.emmc
endif
TARGET_KERNEL_CONFIG := g12a_defconfig gxl.config
TARGET_KERNEL_SOURCE := kernel/amlogic/linux-4.9

ifeq ($(WITH_CONSOLE),true)
  BOARD_KERNEL_CMDLINE += console=ttyS0,115200 no_console_suspend ignore_loglevel
  BOARD_KERNEL_CMDLINE += earlycon=aml-uart,0xff803000
endif

## Kernel modules
TARGET_KERNEL_EXT_MODULE_ROOT := kernel/amlogic/kernel-modules
TARGET_KERNEL_EXT_MODULES += \
    mali-driver/utgard \
    media-4.9

ifneq ($(TARGET_HAS_TEE),false)
TARGET_KERNEL_EXT_MODULES += \
    optee
endif

## Partitions
SSI_PARTITIONS := system
TREBLE_PARTITIONS := odm vendor
ALL_PARTITIONS := $(SSI_PARTITIONS) $(TREBLE_PARTITIONS)

BOARD_ODMIMAGE_PARTITION_SIZE ?= 134217728
BOARD_SYSTEMIMAGE_PARTITION_SIZE ?= 1656750080
BOARD_VENDORIMAGE_PARTITION_SIZE ?= 335544320

## Properties
TARGET_SYSTEM_PROP += $(COMMON_PATH)/system.prop
TARGET_VENDOR_PROP += $(COMMON_PATH)/vendor.prop

## Recovery
TARGET_RECOVERY_DEVICE_DIRS += vendor/amlogic/gx-common/proprietary
ifneq ($(strip $(TARGET_BOOTDEVICE)),)
  TARGET_RECOVERY_FSTAB := $(COMMON_PATH)/init/fstab.$(TARGET_BOOTDEVICE).amlogic
else
  TARGET_RECOVERY_FSTAB := $(COMMON_PATH)/init/fstab.amlogic
endif

## Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := $(COMMON_PATH)/releasetools

## Updater
AB_OTA_UPDATER := false

## Vendor SPL
VENDOR_SECURITY_PATCH := 2019-04-05

## Include the main common tree BoardConfig makefile
include device/amlogic/common/BoardConfigAmlogic.mk

## Include the common proprietary BoardConfig makefile
include vendor/amlogic/gx-common/BoardConfigVendor.mk
