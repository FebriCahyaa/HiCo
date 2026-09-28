#
# Copyright 2014 The Android Open Source Project
#
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

ifneq ($(filter beckham, $(TARGET_DEVICE)),)
include $(call all-makefiles-under,$(LOCAL_PATH))

MODS_LIBS := libmodhw.so libvibratorhw.so
MODS_SYMLINKS := $(addprefix $(TARGET_OUT)/priv-app/ModFmwkProxyService/lib/arm64/,$(notdir $(MODS_LIBS)))
$(MODS_SYMLINKS): $(LOCAL_INSTALLED_MODULE)
	@echo "MODS lib link: $@"
	@mkdir -p $(dir $@)
	@rm -rf $@
	$(hide) ln -sf /system/lib64/$(notdir $@) $@

ALL_DEFAULT_INSTALLED_MODULES += $(MODS_SYMLINKS)

endif
