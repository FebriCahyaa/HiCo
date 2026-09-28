LOCAL_PATH := $(call my-dir)

ifeq ($(TARGET_USES_LEGACY_BOARD),true)
ifeq ($(TARGET_BOOTLOADER_BOARD_NAME),tamsui)
    include $(call all-subdir-makefiles,$(LOCAL_PATH))
endif
endif
