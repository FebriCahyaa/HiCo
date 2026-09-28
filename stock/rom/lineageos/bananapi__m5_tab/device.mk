#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

# GMS
ifeq ($(WITH_GMS),true)
GMS_MAKEFILE=gms_minimal.mk
WITH_GMS_COMMS_SUITE := false
endif

$(call inherit-product, device/bananapi/m5/device.mk)
