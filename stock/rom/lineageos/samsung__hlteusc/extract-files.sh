#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=hlteusc
./../../$VENDOR/hlte-common/extract-files.sh $@
