#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: 2024 The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

from extract_utils.fixups_blob import (
    blob_fixup,
    blob_fixups_user_type,
)
from extract_utils.main import (
    ExtractUtils,
    ExtractUtilsModule,
)

namespace_imports = [
    'device/nothing/camera-Spacewar',
    'vendor/nothing/Spacewar',
]

blob_fixups: blob_fixups_user_type = {
    'system/priv-app/NTCamera/NTCamera.apk': blob_fixup()
        .apktool_patch('blob-patches/NTCamera'),
}

module = ExtractUtilsModule(
    'camera-Spacewar',
    'nothing',
    blob_fixups=blob_fixups,
    namespace_imports=namespace_imports,
)

if __name__ == '__main__':
    utils = ExtractUtils.device(module)
    utils.run()
