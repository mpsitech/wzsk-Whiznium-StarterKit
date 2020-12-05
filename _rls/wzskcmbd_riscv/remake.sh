#!/bin/bash
# file remake.sh
# re-make script for Wzsk combined daemon, release wzskcmbd_riscv(ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 5 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build
export set REPROOT=${WHIZDEVROOT}/rep

cd $REPROOT/wzsk/_rls/wzskcmbd_riscv
./checkout.sh

cd $BUILDROOT/wzskcmbd

./make.sh "$@"

