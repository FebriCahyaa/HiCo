#
# Copyright (C) 2023 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

BOARD_HAVE_BLUETOOTH_RTK_TV := true
$(call soong_config_set,nicepool,variant,realtek)
$(call inherit-product, device/freebox/nicepool/device.mk)
