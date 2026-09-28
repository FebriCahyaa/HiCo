#!/usr/bin/env -S PYTHONPATH=../../../tools/extract-utils python3
#
# SPDX-FileCopyrightText: The LineageOS Project
# SPDX-License-Identifier: Apache-2.0
#

import sys
import subprocess

# Path to the script you want to run
script_path = '../radxa02/extract-files.py'

# Run the script with arguments passed to this script
subprocess.run(['python', script_path] + sys.argv[1:])
