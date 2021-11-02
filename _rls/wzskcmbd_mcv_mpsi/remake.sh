#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_mcv_mpsi (jack cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 2 Nov 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=/home/mpsitech/emb/mcv/wzsk/sdk/sysroots/cortexa9t2hf-neon-poky-linux-gnueabi${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wzsk/_rls/wzskcmbd_mcv_mpsi
./checkout.sh

cd $BUILDROOT/wzskcmbd

./make.sh "$@"
