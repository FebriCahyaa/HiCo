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

include device/nvidia/foster/BoardConfig.mk

# Boot image
BOARD_CUSTOM_BOOTIMG    := flase
BOARD_CUSTOM_BOOTIMG_MK :=
BOARD_MKBOOTIMG_ARGS    :=

# Bootloader Versions
TARGET_BOARD_INFO_FILE :=

# Kernel
TARGET_KERNEL_SOURCE          := kernel/nvidia/shield
TARGET_KERNEL_CONFIG          := tegra21_android_defconfig
TARGET_KERNEL_RECOVERY_CONFIG :=
BOARD_KERNEL_IMAGE_NAME       := zImage

# Graphics
ifeq ($(TARGET_TEGRA_GPU),nvgpu-r29)
TARGET_LD_SHIM_LIBS += \
    /vendor/lib64/libglcore.so|/system/lib64/libutilscallstack.so \
    /vendor/lib/egl/libEGL_tegra.so|/vendor/lib/libnvos_shim.so \
    /vendor/lib64/egl/libEGL_tegra.so|/vendor/lib64/libnvos_shim.so
endif

# Legacy memfd
TARGET_HAS_MEMFD_BACKPORT := true

# Nvmm shims
ifeq ($(TARGET_TEGRA_OMX),nvmm-r29)
TARGET_LD_SHIM_LIBS += \
  /vendor/lib/libnvomxadaptor.so|/system/lib/libmedia_omx.so \
  /vendor/lib/libnvomxadaptor.so|/vendor/lib/libnvmm_shim.so
endif

# Recovery
TARGET_RECOVERY_PIXEL_FORMAT :=

# Treble
BOARD_PROPERTY_OVERRIDES_SPLIT_ENABLED := false
BOARD_VNDK_VERSION                     :=
PRODUCT_FULL_TREBLE_OVERRIDE           := false

# Releasetools
TARGET_RELEASETOOLS_EXTENSIONS := device/nvidia/loki/releasetools

include device/nvidia/icera/BoardConfigIcera.mk
include device/nvidia/touch/BoardConfigTouch.mk
