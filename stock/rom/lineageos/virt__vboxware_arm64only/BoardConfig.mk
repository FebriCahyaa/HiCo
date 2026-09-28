#
# Copyright (C) 2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

USES_DEVICE_VIRT_VBOXWARE_ARM64ONLY := true

# GRUB
TARGET_GRUB_ARCH := arm64-efi
TARGET_GRUB_2ND_ARCH :=
TARGET_GRUB_HOST_PREBUILT_TAG := linux-arm64

# Inherit from vboxware
include device/virt/vboxware/BoardConfig.mk

# Arch
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic

# GRUB
TARGET_GRUB_BOOT_EFI_PREBUILT := device/virt/virtio_arm64/bootmgr/grub/prebuilt/boot/BOOTAA64.EFI
TARGET_GRUB_INSTALL_EFI_PREBUILT := device/virt/virtio_arm64/bootmgr/grub/prebuilt/install/BOOTAA64.EFI

# Kernel
BOARD_KERNEL_IMAGE_NAME := Image
TARGET_KERNEL_ARCH := arm64

# Partitions
ifeq ($(TARGET_LOGICAL_PARTITIONS_FILE_SYSTEM_TYPE),ext4)
    ifneq ($(WITH_GMS),true)
        BOARD_PRODUCTIMAGE_PARTITION_RESERVED_SIZE := 1073741824 # 1 GB
    endif
endif
