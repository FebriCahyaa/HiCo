#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    aosp_pyxis_mainline:$(LOCAL_DIR)/aosp_pyxis_mainline.mk \
    lineage_pyxis_mainline:$(LOCAL_DIR)/lineage_pyxis_mainline.mk

$(foreach build_type, user userdebug eng, \
    $(eval COMMON_LUNCH_CHOICES += aosp_pyxis_mainline-$(build_type)) \
    $(eval COMMON_LUNCH_CHOICES += lineage_pyxis_mainline-$(build_type)))
