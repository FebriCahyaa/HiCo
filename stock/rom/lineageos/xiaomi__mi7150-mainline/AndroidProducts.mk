#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    aosp_davinci_mainline:$(LOCAL_DIR)/davinci_mainline/aosp_davinci_mainline.mk \
    lineage_davinci_mainline:$(LOCAL_DIR)/davinci_mainline/lineage_davinci_mainline.mk
#    lineage_sweet_mainline:$(LOCAL_DIR)/sweet_mainline/lineage_sweet_mainline.mk

$(foreach build_type, user userdebug eng, \
    $(eval COMMON_LUNCH_CHOICES += aosp_davinci_mainline-$(build_type)) \
    $(eval COMMON_LUNCH_CHOICES += lineage_davinci_mainline-$(build_type)))
#    $(eval COMMON_LUNCH_CHOICES += lineage_sweet_mainline-$(build_type)))
