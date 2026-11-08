#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: The LineageOS Project
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
    'device/samsung/s5e8825-common',
    'hardware/samsung',
    'hardware/samsung_slsi-linaro/exynos',
    'hardware/samsung_slsi-linaro/graphics',
    'vendor/samsung/s5e8825-common',
]

blob_fixups: blob_fixups_user_type = {
    # Camera
    'vendor/lib64/libexynoscamera3.so': blob_fixup()
        .add_needed('libcamera_shim.samsung.so')
        .add_needed('libui_shim.so')
        .binary_regex_replace(b'_ZN7android5Fence', b'_ZN7exynos55Fence')
        # Enable RAW support
        # Before: [
        #  mov x6,sp
        #  mov w0,#0x4
        #  mov w5,w19
        #  bl 0x0040ad40
        # ]
        # After: [
        #  ldr w0,[x20, #0xa20]
        #  orr w0,w0,#0x10
        #  str w0,[x20, #0xa20]
        #  nop
        # ]
        .sig_replace('e6 03 00 91 80 00 80 52 e5 03 13 2a c7 d2 07 94',
                     '80 22 4a b9 00 00 1c 32 80 22 0a b9 1f 20 03 d5')
        # Make checkFactoryBinProperty always return false
        # Before: [
        #  sub sp,sp,#90
        #  stp x29,x30,[sp, #70]
        # ]
        # After: [
        #  mov w0,#0
        #  ret
        # ]
        .sig_replace('d6 db 00 94 00 00 00 00 ff 43 02 d1 fd 7b 07 a9',
                     'd6 db 00 94 00 00 00 00 00 00 80 52 c0 03 5f d6'),
}  # fmt: skip

module = ExtractUtilsModule(
    'a53x',
    'samsung',
    namespace_imports=namespace_imports,
    blob_fixups=blob_fixups,
    add_firmware_proprietary_file=True,
)

module.add_proprietary_file('../s5e8825-common/proprietary-files.device.txt')
module.add_proprietary_file(
    '../s5e8825-common/products/phone/proprietary-files.device.txt'
)

if __name__ == '__main__':
    utils = ExtractUtils.device_with_common(
        module, 's5e8825-common', module.vendor
    )
    utils.run()
