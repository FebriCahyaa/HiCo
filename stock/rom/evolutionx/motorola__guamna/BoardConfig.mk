#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from sm6225-common
include device/motorola/sm6225-common/BoardConfigCommon.mk

DEVICE_PATH := device/motorola/guamna

# Bootloader
TARGET_BOOTLOADER_BOARD_NAME := guamna

# Display
TARGET_SCREEN_DENSITY := 280

# HIDL
ODM_MANIFEST_SKUS += b d f
ODM_MANIFEST_B_FILES := $(DEVICE_PATH)/sku/manifest_b.xml
ODM_MANIFEST_D_FILES := $(DEVICE_PATH)/sku/manifest_d.xml
ODM_MANIFEST_F_FILES := $(DEVICE_PATH)/sku/manifest_f.xml

# Kernel
BOARD_BOOT_HEADER_VERSION := 2
TARGET_KERNEL_CONFIG += vendor/ext_config/guamna-default.config

# Kernel Modules - Audio
TARGET_MODULE_ALIASES += \
    fs16xx_dlkm.ko:audio_snd_soc_fs16xx.ko

# Kernel Modules - Recovery
BOARD_RECOVERY_KERNEL_MODULES_LOAD := $(strip $(shell cat $(DEVICE_PATH)/modules.load.recovery))
RECOVERY_KERNEL_MODULES := $(BOARD_RECOVERY_KERNEL_MODULES_LOAD)

# Partitions
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 104857600

BOARD_SUPER_PARTITION_SIZE := 10267656192
BOARD_MOTO_DYNAMIC_PARTITIONS_SIZE := 5129633792 # (BOARD_SUPER_PARTITION_SIZE / 2) - 4MB

# Properties
TARGET_VENDOR_PROP += $(DEVICE_PATH)/vendor.prop

# Recovery
TARGET_RECOVERY_DENSITY := hdpi
TARGET_RECOVERY_FSTAB := $(DEVICE_PATH)/init/fstab.qcom
TARGET_RECOVERY_UI_MARGIN_HEIGHT := 43

# Security patch level
BOOT_SECURITY_PATCH := 2023-02-01
VENDOR_SECURITY_PATCH := $(BOOT_SECURITY_PATCH)

# Verified Boot
BOARD_AVB_ROLLBACK_INDEX := 19

# Inherit from the proprietary version
include vendor/motorola/guamna/BoardConfigVendor.mk
