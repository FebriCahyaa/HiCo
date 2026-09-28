LOCAL_PATH := $(call my-dir)
ifeq ($(TARGET_DEVICE),mini5g)
include $(call all-makefiles-under,$(LOCAL_PATH))

endif
