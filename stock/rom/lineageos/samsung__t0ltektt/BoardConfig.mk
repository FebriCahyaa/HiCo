#
# Copyright (C) 2013 The CyanogenMod Project
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
#

# This variable is set first, so it can be overridden
# by BoardConfigVendor.mk
-include device/samsung/smdk4412-common/BoardCommonConfig.mk
-include device/samsung/smdk4412-qcom-common/BoardCommonConfig.mk
-include device/samsung/t0lte/BoardCommonConfig.mk

# Use special kernel config for t0ltektt
# Needs CONFIG_MACH_T0_KOR_KT=y and CONFIG_TARGET_LOCALE_KOR=y
TARGET_KERNEL_SOURCE := kernel/samsung/smdk4412
TARGET_KERNEL_CONFIG := lineageos_t0ltektt_defconfig

# GPS
BOARD_GPS_SET_PRIVACY := true

# inherit from the proprietary version
-include vendor/samsung/t0lte/BoardConfigVendor.mk

