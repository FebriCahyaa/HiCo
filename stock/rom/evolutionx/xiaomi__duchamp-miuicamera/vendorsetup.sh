#!/bin/bash

echo "Applying MIUI Camera format fixes via sed..."

AV_DIR="frameworks/av"
AIDL_FILE="$AV_DIR/services/camera/libcameraservice/device3/aidl/AidlCamera3Device.cpp"
HIDL_FILE="$AV_DIR/services/camera/libcameraservice/device3/hidl/HidlCamera3Device.cpp"

SEARCH_STR="if (dstStream->getOriginalFormat() != HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED) {"
REPLACE_STR="if (dstStream->getOriginalFormat() != HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED \&\& dstStream->getOriginalFormat() != 0x23) {"

if [ -d "$AV_DIR" ]; then
    if grep -q "$SEARCH_STR" "$AIDL_FILE"; then
        sed -i "s/$SEARCH_STR/$REPLACE_STR/g" "$AIDL_FILE"
        echo "Patched AidlCamera3Device.cpp successfully."
    else
        echo "AidlCamera3Device.cpp already patched or string not found."
    fi

    if grep -q "$SEARCH_STR" "$HIDL_FILE"; then
        sed -i "s/$SEARCH_STR/$REPLACE_STR/g" "$HIDL_FILE"
        echo "Patched HidlCamera3Device.cpp successfully."
    else
        echo "HidlCamera3Device.cpp already patched or string not found."
    fi
else
    echo "Warning: frameworks/av not found!"
fi

echo "Applying MIUI Camera Portrait Patch to SessionConfigurationUtils.cpp..."

FILE="frameworks/av/services/camera/libcameraservice/utils/SessionConfigurationUtils.cpp"
if [ -f "$FILE" ]; then
    if grep -q "MIUI PORTRAIT PATCH" "$FILE"; then
        echo "Portrait Patch already applied."
    else
        sed -i '/format %#x defined, failed to create output stream"/,+3 s/return STATUS_ERROR(CameraService::ERROR_ILLEGAL_ARGUMENT, msg.c_str());/\/\/ MIUI PORTRAIT PATCH: return STATUS_ERROR(CameraService::ERROR_ILLEGAL_ARGUMENT, msg.c_str());/' "$FILE"
        echo "Portrait Patch applied successfully!"
    fi
else
    echo "Warning: SessionConfigurationUtils.cpp not found!"
fi

echo "Applying MTK Face Unlock Patch for CallbackProcessor..."

CB_FILE="frameworks/av/services/camera/libcameraservice/api1/client2/CallbackProcessor.cpp"
CB_SEARCH="if (imgBuffer.format != expectedFormat) {"
CB_REPLACE="if (imgBuffer.format != expectedFormat \&\& imgBuffer.format != 0x11) { \/\/ MTK_FACE_UNLOCK_PATCH"

if [ -f "$CB_FILE" ]; then
    if grep -q "MTK_FACE_UNLOCK_PATCH" "$CB_FILE"; then
        echo "CallbackProcessor.cpp already patched."
    else
        sed -i "s/$CB_SEARCH/$CB_REPLACE/g" "$CB_FILE"
        echo "Patched CallbackProcessor.cpp for Face Unlock!"
    fi
else
    echo "Warning: CallbackProcessor.cpp not found!"
fi