#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

include device/radxa/radxa02/BoardConfig.mk

## Kernel
TARGET_KERNEL_CONFIG += aml_tab.config

## Wi-Fi
WIFI_HIDL_FEATURE_DUAL_INTERFACE := true
