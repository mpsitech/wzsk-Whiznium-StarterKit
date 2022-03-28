#!/bin/bash
# file checkout.sh
# checkout script for Wzsk database access library, release dbswzsk_riscv (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Mar 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build

mkdir $BUILDROOT/dbswzsk

cp makeall.sh $BUILDROOT/dbswzsk/

cp Makefile $BUILDROOT/dbswzsk/

cp ../../dbswzsk/DbsWzsk.h $BUILDROOT/dbswzsk/
cp ../../dbswzsk/DbsWzsk_vecs.cpp $BUILDROOT/dbswzsk/
cp ../../dbswzsk/DbsWzsk.cpp $BUILDROOT/dbswzsk/

cp ../../dbswzsk/Wzsk*.h $BUILDROOT/dbswzsk/
cp ../../dbswzsk/Wzsk*.cpp $BUILDROOT/dbswzsk/
