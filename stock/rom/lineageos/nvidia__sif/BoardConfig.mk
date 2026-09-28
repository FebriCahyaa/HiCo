#
# Copyright (C) 2021 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include device/nvidia/foster/BoardConfig.mk

BOARD_RECOVERYIMAGE_PARTITION_SIZE := 28835840
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 1616904192
BOARD_VENDORIMAGE_PARTITION_SIZE   := 379584512

# Assert
TARGET_OTA_ASSERT_DEVICE := $(TARGET_OTA_ASSERT_DEVICE),sif
