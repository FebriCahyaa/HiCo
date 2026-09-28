#!/bin/sh

set -e

export DEVICE=hltecan
export VENDOR=samsung
./../hlte-common/extract-files.sh $@
