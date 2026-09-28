#
# Copyright (C) 2023 LibreMobileOS Foundation
#
# SPDX-License-Identifier: Apache-2.0
#

PRODUCT_MAKEFILES := \
    lmodroid_zahedan:$(LOCAL_DIR)/zahedan/lmodroid_zahedan.mk \
    lmodroid_algiz:$(LOCAL_DIR)/algiz/lmodroid_algiz.mk

COMMON_LUNCH_CHOICES := \
    lmodroid_zahedan-user \
    lmodroid_zahedan-userdebug \
    lmodroid_zahedan-eng \
    lmodroid_algiz-user \
    lmodroid_algiz-userdebug \
    lmodroid_algiz-eng
