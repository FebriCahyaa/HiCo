#
# Copyright (C) 2014 The CyanogenMod Project
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

include device/lge/g2-common/BoardConfigCommon.mk

BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.hardware=z user_debug=31 msm_rtb.filter=0x0 mdss_mdp.panel=1:dsi:0:qcom,mdss_dsi_lgd_poled_720p_video

### Temporary until proper changes are added to kernel/lge/msm8974
BOARD_MKBOOTIMG_ARGS  := --ramdisk_offset 0x05000000 --dt device/lge/zee/dt.img --tags_offset 0x04800000
TARGET_PREBUILT_KERNEL := device/lge/zee/kernel ## For initial recovery builds
BOARD_KERNEL_SEPARATED_DT := ## For prebuilt kernel use to bypass g2-common
BOARD_CUSTOM_BOOTIMG_MK := ## For prebuilt kernel use to bypass g2-common
TARGET_KERNEL_SOURCE := #kernel/lge/zee
### End Temporary ###

## Recovery
BOARD_RECOVERY_SWIPE := true
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_15x24.h\"

TARGET_OTA_ASSERT_DEVICE := zee
