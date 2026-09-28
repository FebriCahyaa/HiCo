#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

USES_DEVICE_VIRT_VIRTIO_X86_64 := true

# Boot manager
TARGET_BOOT_MANAGER ?= grub

# GRUB
TARGET_GRUB_ARCH := x86_64-efi
TARGET_GRUB_2ND_ARCH := i386-pc

# Inherit from common
include device/virt/virtio-common/BoardConfigCommon.mk

# Arch
TARGET_CPU_ABI := x86_64
TARGET_ARCH := x86_64
TARGET_ARCH_VARIANT := sandybridge

# Boot manager
TARGET_GRUB_BOOT_CONFIGS += $(DEVICE_PATH)/bootmgr/grub/grub-boot.cfg

# Graphics (Allocator)
$(call soong_config_set_string_list,minigbm_upstream,cflags,-DDRV_I915 -DDRV_XE)

# Graphics (Mesa)
BOARD_MESA3D_GALLIUM_DRIVERS += crocus iris
BOARD_MESA3D_VULKAN_DRIVERS += intel intel_hasvk

# Kernel
BOARD_KERNEL_CMDLINE += \
    8250.nr_uarts=1

TARGET_KERNEL_CONFIG_EXT += \
    $(DEVICE_PATH)/configs/kernel/virtio_x86_64.config \
    $(DEVICE_PATH)/configs/kernel/passthrough_gpus.config

BOARD_KERNEL_IMAGE_NAME := bzImage
BOARD_LINUX_SERIAL_DEVICE := ttyS0
TARGET_KERNEL_ARCH := x86

# SELinux
BOARD_VENDOR_SEPOLICY_DIRS += \
    $(DEVICE_PATH)/sepolicy/vendor

# Virtual Machine template
TARGET_VM_UTM_TEMPLATE_DIR := $(DEVICE_PATH)/vm_templates/utm
