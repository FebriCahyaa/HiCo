# Host build of hicod and its unit tests.
#
# The Android binary is built with ndk-build (jni/Android.mk). This CMake
# project compiles the same sources for the build machine, where every
# device path is redirected under $HICO_ROOT, so the daemon and the tests run
# against a fake /sys, /proc and /data tree.
cmake_minimum_required(VERSION 3.20)
project(hico C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/version" HICO_VERSION)
string(STRIP "${HICO_VERSION}" HICO_VERSION)

# Vendored Ed25519 + SHA-256 (jni/src/vendor/*/NOTICE.md): built separately, without our own
# warning flags — it is third-party code we do not edit, not ours to keep -Wpedantic-clean.
file(GLOB VENDOR_CRYPTO_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/jni/src/vendor/ed25519/*.c"
     "${CMAKE_CURRENT_SOURCE_DIR}/jni/src/vendor/sha256/*.c")
add_library(vendor_crypto STATIC ${VENDOR_CRYPTO_SOURCES})
target_include_directories(vendor_crypto PUBLIC jni/src/vendor/ed25519 jni/src/vendor/sha256)

file(GLOB HICO_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/jni/src/*.cpp")
list(REMOVE_ITEM HICO_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/jni/src/main.cpp")

add_library(hico_core STATIC ${HICO_SOURCES})
target_include_directories(hico_core PUBLIC jni/include)
target_compile_definitions(hico_core PUBLIC HICO_VERSION="${HICO_VERSION}-host")
target_compile_options(hico_core PUBLIC -Wall -Wextra -Wpedantic -Werror -Wformat -Wuninitialized)
target_link_libraries(hico_core PUBLIC vendor_crypto)

add_executable(hicod jni/src/main.cpp)
target_link_libraries(hicod PRIVATE hico_core)

# Host-only signer: generates keys and signs a release manifest. Never ships on device.
add_executable(hico_sign tools/hico_sign_main.cpp)
target_link_libraries(hico_sign PRIVATE hico_core)

enable_testing()
add_executable(hico_tests tests/tests.cpp)
target_link_libraries(hico_tests PRIVATE hico_core)
add_test(NAME unit COMMAND hico_tests)
add_test(NAME cli COMMAND sh ${CMAKE_CURRENT_SOURCE_DIR}/tests/cli_test.sh $<TARGET_FILE:hicod>)
