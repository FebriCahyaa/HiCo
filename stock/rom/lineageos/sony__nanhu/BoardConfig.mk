USE_CAMERA_STUB := true

# inherit from the proprietary version
-include vendor/sony/nanhu/BoardConfigVendor.mk

#inherit from the common tamsui definitions
-include device/sony/tamsui-common/BoardConfigCommon.mk

TARGET_SPECIFIC_HEADER_PATH += device/sony/nanhu/include

TARGET_KERNEL_CONFIG := cm_tamsui_nan_defconfig
BOARD_KERNEL_CMDLINE := device/sony/nanhu/config/cmdline.txt

# Partition information
BOARD_VOLD_MAX_PARTITIONS := 17

# Recovery
TARGET_RECOVERY_INITRC := device/sony/nanhu/recovery/init.rc
BOARD_BOOTIMAGE_PARTITION_SIZE := 0x01400000
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 0x01400000
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 524288000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 2147483648
BOARD_FLASH_BLOCK_SIZE := 131072

BOARD_HAS_NO_SELECT_BUTTON := true
TARGET_USERIMAGES_USE_EXT4 := true

# Bluetooth
BOARD_HAVE_BLUETOOTH_CSR := true
TARGET_CUSTOM_BLUEDROID := ../../../device/sony/nanhu/bluedroid/bluetooth.c

# Wifi
BOARD_WLAN_DEVICE := ath6kl
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_ath6kl
WIFI_DRIVER_MODULE_PATH := "/system/lib/modules/ath6kl_sdio.ko"
WIFI_DRIVER_MODULE_NAME := ath6kl_sdio
WIFI_DRIVER_LOADER_DELAY := 1000000

BOARD_SDCARD_INTERNAL_DEVICE := /dev/block/mmcblk0p17

# Custom vibrator
BOARD_HAS_VIBRATOR_IMPLEMENTATION := ../../device/sony/nanhu/vibrator/vibrator.c

TARGET_OTA_ASSERT_DEVICE := C1505,C1505,nanhu
