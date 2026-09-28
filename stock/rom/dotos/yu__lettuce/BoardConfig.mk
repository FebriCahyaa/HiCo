#
# Copyright (C) 2016 The CyanogenMod Project
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

include device/cyanogen/msm8916-common/BoardConfigCommon.mk

include device/yu/lettuce/board/*.mk

# Assertions
ADD_RADIO_FILES ?= true
TARGET_RELEASETOOLS_EXTENSIONS := device/yu/lettuce

# inherit from proprietary files
-include vendor/yu/lettuce/BoardConfigVendor.mk

TARGET_KERNEL_CROSS_COMPILE_PREFIX := $(ANDROID_BUILD_TOP)/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-android-4.9-kernel/bin/aarch64-linux-android-
