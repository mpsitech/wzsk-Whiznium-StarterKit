#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 18 Oct 2020
# modified: 18 Oct 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set REPROOT=${WHIZROOT_CCH}/srcrep

cd $REPROOT/wzsk/_rls/wzskcmbd_arty
./checkout.sh

cd $SRCROOT/wzskcmbd

./make.sh "$@"

