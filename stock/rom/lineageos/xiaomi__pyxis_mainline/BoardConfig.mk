#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from mi710-mainline
include device/xiaomi/mi710-mainline/BoardConfig.mk

# Boot parameters
BOARD_KERNEL_CMDLINE += \
    androidboot.hardware=pyxis \
    regulator_ignore_unused

# Display
TARGET_SCREEN_DENSITY := 440

# Kernel
TARGET_DTB_LIST_WILDCARD := \
    qcom/sdm710-xiaomi-pyxis \
    qcom/sdm710-xiaomi-vela

# OTA
TARGET_OTA_ASSERT_DEVICE := pyxis_mainline,pyxis,vela

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 134217728
