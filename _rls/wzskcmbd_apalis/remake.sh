#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 6 Oct 2020
# modified: 6 Oct 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set REPROOT=${WHIZROOT_CCH}/srcrep

cd $REPROOT/wzsk/_rls/wzskcmbd_apalis
./checkout.sh

cd $SRCROOT/wzskcmbd

./make.sh "$@"

