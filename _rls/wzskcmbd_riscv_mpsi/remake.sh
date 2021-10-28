#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_riscv_mpsi (jack cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Oct 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=/home/mpsitech/emb/icicle/wzsk/sdk/sysroots/riscv64-oe-linux${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wzsk/_rls/wzskcmbd_riscv_mpsi
./checkout.sh

cd $BUILDROOT/wzskcmbd

./make.sh "$@"
