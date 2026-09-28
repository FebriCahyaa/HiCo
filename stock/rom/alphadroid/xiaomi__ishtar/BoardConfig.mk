#
# Copyright (C) 2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/xiaomi/ishtar

# NFC
TARGET_USES_ST_NFC := true

# Inherit from xiaomi sm8550-common
include device/xiaomi/sm8550-common/BoardConfigCommon.mk

# NFC
TARGET_KERNEL_EXT_MODULES := $(filter-out nxp/opensource/driver,$(TARGET_KERNEL_EXT_MODULES))
BOARD_VENDOR_KERNEL_MODULES_LOAD := $(filter-out nxp-nci.ko,$(BOARD_VENDOR_KERNEL_MODULES_LOAD))

# Display
TARGET_SCREEN_DENSITY := 560

# Kernel
TARGET_KERNEL_EXT_MODULE_ROOT := kernel/xiaomi/sm8550-modules
TARGET_KERNEL_EXT_MODULES += \
	st/opensource/driver

BOARD_VENDOR_KERNEL_MODULES_LOAD += \
	stm_nfc_i2c.ko \
	cs35l41_dlkm.ko \
	goodix_fod.ko \
	fts_touch_spi.ko \
	mi_thermal_interface.ko \
	qcom_pm8008-regulator.ko \
	stmvl53l5.ko \
	wl2866d.ko

BOARD_VENDOR_RAMDISK_RECOVERY_KERNEL_MODULES_LOAD += \
	fts_touch_spi.ko

BOOT_KERNEL_MODULES += \
	fts_touch_spi.ko

# Properties
TARGET_ODM_PROP += $(DEVICE_PATH)/properties/odm.prop
TARGET_PRODUCT_PROP += $(DEVICE_PATH)/properties/product.prop
TARGET_VENDOR_PROP += $(DEVICE_PATH)/properties/vendor.prop

# Sepolicy
BOARD_VENDOR_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy/vendor

# Inherit from the proprietary version
include vendor/xiaomi/ishtar/BoardConfigVendor.mk
