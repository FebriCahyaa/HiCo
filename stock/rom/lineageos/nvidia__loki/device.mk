#
# Copyright (C) 2022 The LineageOS Project
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

TARGET_TEGRA_CAMERA   ?= none
TARGET_TEGRA_GPU      ?= nvgpu-r29
TARGET_TEGRA_KERNEL   ?= 3.10
TARGET_TEGRA_OMX      ?= nvmm-r29

# Only include Shield apps for first party targets
include device/nvidia/shield-common/shield.mk

$(call inherit-product, device/nvidia/foster/device.mk)
include device/nvidia/icera/icera.mk
include device/nvidia/touch/raydium.mk

$(call inherit-product, device/nvidia/loki/vendor/loki-vendor.mk)

# Overlays
DEVICE_PACKAGE_OVERLAYS += \
    device/nvidia/loki/overlay

# Init related
PRODUCT_PACKAGES += \
    rel29.rc

# HIDL
PRODUCT_ENFORCE_VINTF_MANIFEST_OVERRIDE := true
