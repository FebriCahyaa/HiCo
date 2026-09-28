# Inherit from vendor
$(call inherit-product-if-exists, vendor/samsung/j7ltespr/j7ltespr-vendor.mk)

# Inherit from common
$(call inherit-product, device/samsung/j7lte-common/j7lte.mk)

LOCAL_PATH := device/samsung/j7ltespr

# Common overlay
DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay
