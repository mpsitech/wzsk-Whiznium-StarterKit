#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_linux
# author Catherine Johnson
# date created: 6 Oct 2020
# modified: 6 Oct 2020

export set SRCROOT=${WHIZROOT}/src
export set REPROOT=${WHIZROOT}/srcrep

cd $REPROOT/wzsk/_rls/wzskcmbd_linux
./checkout.sh

cd $SRCROOT/wzskcmbd

./make.sh "$@"

