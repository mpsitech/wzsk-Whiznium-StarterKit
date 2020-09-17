#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 16 Sep 2020
# modified: 16 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set REPROOT=${WHIZROOT_CCH}/srcrep

cd $REPROOT/wzsk/_rls/wzskcmbd_arty
./checkout.sh

cd $SRCROOT/wzskcmbd

./make.sh "$@"

