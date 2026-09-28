#
# Copyright (C) 2025 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    $(LOCAL_DIR)/aosp_vboxware_arm64only.mk \
    $(LOCAL_DIR)/lineage_vboxware_arm64only.mk

$(foreach build_type, user userdebug eng, \
    $(eval COMMON_LUNCH_CHOICES += aosp_vboxware_arm64only-$(build_type)) \
    $(eval COMMON_LUNCH_CHOICES += lineage_vboxware_arm64only-$(build_type)))
