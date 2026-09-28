#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

USES_DEVICE_VIRT_VIRTIO_ARM64 := true

# Boot manager
TARGET_BOOT_MANAGER ?= grub

# Inherit from common
include device/virt/virtio-common/BoardConfigCommon.mk

# Arch
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv8-a
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := generic

# GRUB
TARGET_GRUB_ARCH := arm64-efi
TARGET_GRUB_HOST_PREBUILT_TAG := linux-arm64
TARGET_GRUB_BOOT_EFI_PREBUILT := $(DEVICE_PATH)/bootmgr/grub/prebuilt/boot/BOOTAA64.EFI
TARGET_GRUB_INSTALL_EFI_PREBUILT := $(DEVICE_PATH)/bootmgr/grub/prebuilt/install/BOOTAA64.EFI

# Kernel
TARGET_KERNEL_CONFIG_EXT += \
    $(DEVICE_PATH)/configs/kernel/virtio_arm64.config

BOARD_KERNEL_IMAGE_NAME := Image
BOARD_LINUX_SERIAL_DEVICE := ttyAMA0
TARGET_KERNEL_ARCH := arm64

# Partitions
ifeq ($(TARGET_LOGICAL_PARTITIONS_FILE_SYSTEM_TYPE),ext4)
    ifneq ($(WITH_GMS),true)
        BOARD_PRODUCTIMAGE_PARTITION_RESERVED_SIZE := 1073741824 # 1 GB
    endif
endif

# SELinux
BOARD_VENDOR_SEPOLICY_DIRS += \
    $(DEVICE_PATH)/sepolicy/vendor

# Virtual Machine template
TARGET_VM_UTM_TEMPLATE_DIR := $(DEVICE_PATH)/vm_templates/utm
