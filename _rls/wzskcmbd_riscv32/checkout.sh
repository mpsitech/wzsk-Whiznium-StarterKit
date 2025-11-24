#!/bin/bash
# file checkout.sh
# checkout script for Wzsk combined daemon, release wzskcmbd_riscv32 (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${SYSROOT}${WHIZSDKROOT}/build
export set LIBROOT=${SYSROOT}${WHIZSDKROOT}/lib
export set BINROOT=${SYSROOT}${WHIZROOT}/bin

mkdir $BUILDROOT/wzskcmbd
mkdir $BUILDROOT/wzskcmbd/IexWzsk
mkdir $BUILDROOT/wzskcmbd/VecWzsk
mkdir $BUILDROOT/wzskcmbd/CrdWzskNav
mkdir $BUILDROOT/wzskcmbd/CrdWzskUsg
mkdir $BUILDROOT/wzskcmbd/CrdWzskUsr
mkdir $BUILDROOT/wzskcmbd/CrdWzskPrs
mkdir $BUILDROOT/wzskcmbd/CrdWzskPrf
mkdir $BUILDROOT/wzskcmbd/CrdWzskLlv
mkdir $BUILDROOT/wzskcmbd/CrdWzskVtr
mkdir $BUILDROOT/wzskcmbd/CrdWzskHwc
mkdir $BUILDROOT/wzskcmbd/CrdWzskFil

mkdir $LIBROOT/wzskcmbd

mkdir $BINROOT/wzskcmbd

cp make.sh $BUILDROOT/wzskcmbd/
cp remake.sh $BUILDROOT/wzskcmbd/

cp Makefile.inc $BUILDROOT/wzskcmbd/
cp Makefile $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/Wzskcmbd.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/Wzskcmbd.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdAppsrv.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdAppsrv.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdJobprc.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdJobprc.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdOpprc.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdOpprc.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/Wzskcmbd_exe.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/Wzskcmbd_exe.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/Wzsk.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/Wzsk.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/Root*.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/Root*.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/Sess*.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/Sess*.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/M2msess*.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/M2msess*.cpp $BUILDROOT/wzskcmbd/

cp ../../wzskcmbd/gbl/*.h $BUILDROOT/wzskcmbd/
cp ../../wzskcmbd/gbl/*.cpp $BUILDROOT/wzskcmbd/

cp Makefile_IexWzsk $BUILDROOT/wzskcmbd/IexWzsk/Makefile

cp ../../wzskcmbd/IexWzsk/IexWzsk*.h $BUILDROOT/wzskcmbd/IexWzsk/
cp ../../wzskcmbd/IexWzsk/IexWzsk*.cpp $BUILDROOT/wzskcmbd/IexWzsk/

cp ../../wzskcmbd/IexWzsk/JobWzskIex*.h $BUILDROOT/wzskcmbd/IexWzsk/
cp ../../wzskcmbd/IexWzsk/JobWzskIex*.cpp $BUILDROOT/wzskcmbd/IexWzsk/

cp Makefile_VecWzsk $BUILDROOT/wzskcmbd/VecWzsk/Makefile

cp ../../wzskcmbd/VecWzsk/Vec*.h $BUILDROOT/wzskcmbd/VecWzsk/
cp ../../wzskcmbd/VecWzsk/Vec*.cpp $BUILDROOT/wzskcmbd/VecWzsk/

cp Makefile_CrdWzskNav $BUILDROOT/wzskcmbd/CrdWzskNav/Makefile

cp ../../wzskcmbd/CrdWzskNav/*.h $BUILDROOT/wzskcmbd/CrdWzskNav/
cp ../../wzskcmbd/CrdWzskNav/*.cpp $BUILDROOT/wzskcmbd/CrdWzskNav/

cp Makefile_CrdWzskUsg $BUILDROOT/wzskcmbd/CrdWzskUsg/Makefile

cp ../../wzskcmbd/CrdWzskUsg/*.h $BUILDROOT/wzskcmbd/CrdWzskUsg/
cp ../../wzskcmbd/CrdWzskUsg/*.cpp $BUILDROOT/wzskcmbd/CrdWzskUsg/

cp Makefile_CrdWzskUsr $BUILDROOT/wzskcmbd/CrdWzskUsr/Makefile

cp ../../wzskcmbd/CrdWzskUsr/*.h $BUILDROOT/wzskcmbd/CrdWzskUsr/
cp ../../wzskcmbd/CrdWzskUsr/*.cpp $BUILDROOT/wzskcmbd/CrdWzskUsr/

cp Makefile_CrdWzskPrs $BUILDROOT/wzskcmbd/CrdWzskPrs/Makefile

cp ../../wzskcmbd/CrdWzskPrs/*.h $BUILDROOT/wzskcmbd/CrdWzskPrs/
cp ../../wzskcmbd/CrdWzskPrs/*.cpp $BUILDROOT/wzskcmbd/CrdWzskPrs/

cp Makefile_CrdWzskPrf $BUILDROOT/wzskcmbd/CrdWzskPrf/Makefile

cp ../../wzskcmbd/CrdWzskPrf/*.h $BUILDROOT/wzskcmbd/CrdWzskPrf/
cp ../../wzskcmbd/CrdWzskPrf/*.cpp $BUILDROOT/wzskcmbd/CrdWzskPrf/

cp Makefile_CrdWzskLlv $BUILDROOT/wzskcmbd/CrdWzskLlv/Makefile

cp ../../wzskcmbd/CrdWzskLlv/*.h $BUILDROOT/wzskcmbd/CrdWzskLlv/
cp ../../wzskcmbd/CrdWzskLlv/*.cpp $BUILDROOT/wzskcmbd/CrdWzskLlv/

cp Makefile_CrdWzskVtr $BUILDROOT/wzskcmbd/CrdWzskVtr/Makefile

cp ../../wzskcmbd/CrdWzskVtr/*.h $BUILDROOT/wzskcmbd/CrdWzskVtr/
cp ../../wzskcmbd/CrdWzskVtr/*.cpp $BUILDROOT/wzskcmbd/CrdWzskVtr/

cp Makefile_CrdWzskHwc $BUILDROOT/wzskcmbd/CrdWzskHwc/Makefile

cp ../../wzskcmbd/CrdWzskHwc/*.h $BUILDROOT/wzskcmbd/CrdWzskHwc/
cp ../../wzskcmbd/CrdWzskHwc/*.cpp $BUILDROOT/wzskcmbd/CrdWzskHwc/

cp Makefile_CrdWzskFil $BUILDROOT/wzskcmbd/CrdWzskFil/Makefile

cp ../../wzskcmbd/CrdWzskFil/*.h $BUILDROOT/wzskcmbd/CrdWzskFil/
cp ../../wzskcmbd/CrdWzskFil/*.cpp $BUILDROOT/wzskcmbd/CrdWzskFil/
