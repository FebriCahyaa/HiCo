LOCAL_PATH := $(call my-dir)

# Version string baked into hicod; compile_zip.sh passes the release code.
HICO_VERSION ?= $(strip $(shell cat $(LOCAL_PATH)/../version))

include $(CLEAR_VARS)
LOCAL_MODULE := hicod

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

LOCAL_SRC_FILES := $(wildcard $(LOCAL_PATH)/src/*.cpp)
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES:$(LOCAL_PATH)/%=%)

LOCAL_CPPFLAGS += -std=c++20 -fexceptions -O2 -flto -DHICO_VERSION=\"$(HICO_VERSION)\"
LOCAL_CPPFLAGS += -Wpedantic -Wall -Wextra -Werror -Wformat -Wuninitialized
# Hardening: the daemon runs as root.
LOCAL_CPPFLAGS += -fstack-protector-strong -D_FORTIFY_SOURCE=2
LOCAL_LDFLAGS += -flto -Wl,-z,relro,-z,now

include $(BUILD_EXECUTABLE)
