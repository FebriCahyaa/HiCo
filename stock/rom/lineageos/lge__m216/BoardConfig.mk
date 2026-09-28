#
# Copyright (C) 2015-2016 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# inherit from common msm8916
include device/lge/msm8916-common/BoardConfigCommon.mk

LOCAL_PATH := device/lge/m216

# OTA
TARGET_OTA_ASSERT_DEVICE := m216,LG-K420ds,LG-K420n,LG-K420,LG-K10

#Kernel
TARGET_KERNEL_CONFIG := m216_defconfig
TARGET_KERNEL_SOURCE := kernel/lge/msm8916

# Partitions
BOARD_FLASH_BLOCK_SIZE := 131072
BOARD_BOOTIMAGE_PARTITION_SIZE := 25165824      # 24576 * 1024 mmcblk0p18
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 25165824  # 24576 * 1024 mmcblk0p19
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2684354560  # 2621440 * 1024 mmcblk0p37
BOARD_USERDATAIMAGE_PARTITION_SIZE := 12285097984 # 11997166 * 1024 mmcblk0p39

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# Recovery
TARGET_RECOVERY_FSTAB := $(LOCAL_PATH)/rootdir/etc/fstab.qcom

# NFC
BOARD_NFC_DEVICE := "/dev/bcm2079x"

# Init
TARGET_INIT_VENDOR_LIB := libinit_m216
TARGET_RECOVERY_DEVICE_MODULES := libinit_m216
