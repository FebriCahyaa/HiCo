#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Inherit from common msm8953-common
-include device/xiaomi/msm8953-common/BoardConfigCommon.mk

DEVICE_PATH := device/xiaomi/daisy

# Filesystem
BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := ext4

# HIDL
DEVICE_MANIFEST_FILE += $(DEVICE_PATH)/manifest.xml

# Kernel
TARGET_KERNEL_CONFIG := sakura_defconfig
TARGET_KERNEL_VERSION := 4.9

# Partitions
BOARD_BUILD_SYSTEM_ROOT_IMAGE := true
BOARD_HAS_REMOVABLE_STORAGE := true
BOARD_USES_RECOVERY_AS_BOOT := true
TARGET_COPY_OUT_VENDOR := vendor
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2684354560
BOARD_VENDORIMAGE_PARTITION_SIZE := 805306368
TARGET_NO_RECOVERY := true
TARGET_USES_MKE2FS := true
TARGET_USERIMAGES_SPARSE_EXT_DISABLED := false

# Power
TARGET_TAP_TO_WAKE_NODE := "/proc/touchpanel/wakeup_gesture"

# RIL
ENABLE_VENDOR_RIL_SERVICE := true

# Security Patch Level
VENDOR_SECURITY_PATCH := 2020-02-05

# Sepolicy
BOARD_SEPOLICY_DIRS += $(DEVICE_PATH)/sepolicy

# Inherit from the proprietary version
-include vendor/xiaomi/daisy/BoardConfigVendor.mk
