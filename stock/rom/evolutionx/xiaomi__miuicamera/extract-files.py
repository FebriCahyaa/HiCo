#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: 2025 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.main import ExtractUtils, ExtractUtilsModule

module = ExtractUtilsModule(
    "miuicamera",
    "xiaomi",
    namespace_imports=[
        "hardware/qcom-caf/sm8150",
        "vendor/xiaomi/sm8150-common",
        "vendor/xiaomi/raphael",
    ],
)

if __name__ == "__main__":
    utils = ExtractUtils(module)
    utils.run()
