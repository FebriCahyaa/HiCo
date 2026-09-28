LOCAL_PATH := $(call my-dir)

# Version string baked into hicod; compile_zip.sh passes the release code.
HICO_VERSION ?= $(strip $(shell cat $(LOCAL_PATH)/../version))

include $(CLEAR_VARS)
LOCAL_MODULE := hicod

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include

LOCAL_SRC_FILES := $(wildcard $(LOCAL_PATH)/src/*.cpp)
# Vendored Ed25519 + SHA-256 (jni/src/vendor/*/NOTICE.md): verify release signatures on device.
LOCAL_SRC_FILES += $(wildcard $(LOCAL_PATH)/src/vendor/ed25519/*.c)
LOCAL_SRC_FILES += $(wildcard $(LOCAL_PATH)/src/vendor/sha256/*.c)
LOCAL_SRC_FILES := $(LOCAL_SRC_FILES:$(LOCAL_PATH)/%=%)

# Architecture-tuned flags
ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
  HICO_ARCH_FLAGS := -march=armv8.2-a+crypto+dotprod+fp16 -mtune=cortex-a55 -mfpu=neon-fp-armv8
else ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
  HICO_ARCH_FLAGS := -march=armv7-a -mfloat-abi=softfp -mfpu=neon-vfpv4 -mtune=cortex-a53
else
  HICO_ARCH_FLAGS :=
endif

LOCAL_CPPFLAGS += -std=c++20 -fexceptions -O3 -flto -DHICO_VERSION=\"$(HICO_VERSION)\"
LOCAL_CPPFLAGS += -fomit-frame-pointer -fno-plt -fdata-sections -ffunction-sections
LOCAL_CPPFLAGS += $(HICO_ARCH_FLAGS)
LOCAL_CPPFLAGS += -Wpedantic -Wall -Wextra -Werror -Wformat -Wuninitialized
# Hardening: the daemon runs as root.
LOCAL_CPPFLAGS += -fstack-protector-strong -D_FORTIFY_SOURCE=2
LOCAL_LDFLAGS += -flto -Wl,-z,relro,-z,now -Wl,--gc-sections -Wl,--icf=safe -Wl,-O2

include $(BUILD_EXECUTABLE)
