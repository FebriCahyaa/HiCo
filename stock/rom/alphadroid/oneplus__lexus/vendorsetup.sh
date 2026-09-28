#!/bin/bash

# Disable duplicate libvmmem module
bash "$(dirname "${BASH_SOURCE[0]}")/scripts/fix-libvmmem.sh"
