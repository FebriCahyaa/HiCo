#
# Copyright (C) 2020-2024 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

LOCAL_PATH := $(call my-dir)

ifneq ($(filter haydn lisa mars odin redwood renoir star venus vili,$(TARGET_DEVICE)),)
include $(call all-makefiles-under,$(LOCAL_PATH))

endif
