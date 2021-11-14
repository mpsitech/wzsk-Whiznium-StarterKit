#!/bin/bash
# file checkout.sh
# checkout script for Wzsk combined daemon, release wzskcmbd_mcv (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 14 Nov 2021
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
mkdir $BUILDROOT/wzskcmbd/CrdWzskScf
mkdir $BUILDROOT/wzskcmbd/CrdWzskLlv
mkdir $BUILDROOT/wzskcmbd/CrdWzskLiv
mkdir $BUILDROOT/wzskcmbd/CrdWzskOgr
mkdir $BUILDROOT/wzskcmbd/CrdWzskObj
mkdir $BUILDROOT/wzskcmbd/CrdWzskSes
mkdir $BUILDROOT/wzskcmbd/CrdWzskSht
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

cp Makefile_CrdWzskScf $BUILDROOT/wzskcmbd/CrdWzskScf/Makefile

cp ../../wzskcmbd/CrdWzskScf/*.h $BUILDROOT/wzskcmbd/CrdWzskScf/
cp ../../wzskcmbd/CrdWzskScf/*.cpp $BUILDROOT/wzskcmbd/CrdWzskScf/

cp Makefile_CrdWzskLlv $BUILDROOT/wzskcmbd/CrdWzskLlv/Makefile

cp ../../wzskcmbd/CrdWzskLlv/*.h $BUILDROOT/wzskcmbd/CrdWzskLlv/
cp ../../wzskcmbd/CrdWzskLlv/*.cpp $BUILDROOT/wzskcmbd/CrdWzskLlv/

cp Makefile_CrdWzskLiv $BUILDROOT/wzskcmbd/CrdWzskLiv/Makefile

cp ../../wzskcmbd/CrdWzskLiv/*.h $BUILDROOT/wzskcmbd/CrdWzskLiv/
cp ../../wzskcmbd/CrdWzskLiv/*.cpp $BUILDROOT/wzskcmbd/CrdWzskLiv/

cp Makefile_CrdWzskOgr $BUILDROOT/wzskcmbd/CrdWzskOgr/Makefile

cp ../../wzskcmbd/CrdWzskOgr/*.h $BUILDROOT/wzskcmbd/CrdWzskOgr/
cp ../../wzskcmbd/CrdWzskOgr/*.cpp $BUILDROOT/wzskcmbd/CrdWzskOgr/

cp Makefile_CrdWzskObj $BUILDROOT/wzskcmbd/CrdWzskObj/Makefile

cp ../../wzskcmbd/CrdWzskObj/*.h $BUILDROOT/wzskcmbd/CrdWzskObj/
cp ../../wzskcmbd/CrdWzskObj/*.cpp $BUILDROOT/wzskcmbd/CrdWzskObj/

cp Makefile_CrdWzskSes $BUILDROOT/wzskcmbd/CrdWzskSes/Makefile

cp ../../wzskcmbd/CrdWzskSes/*.h $BUILDROOT/wzskcmbd/CrdWzskSes/
cp ../../wzskcmbd/CrdWzskSes/*.cpp $BUILDROOT/wzskcmbd/CrdWzskSes/

cp Makefile_CrdWzskSht $BUILDROOT/wzskcmbd/CrdWzskSht/Makefile

cp ../../wzskcmbd/CrdWzskSht/*.h $BUILDROOT/wzskcmbd/CrdWzskSht/
cp ../../wzskcmbd/CrdWzskSht/*.cpp $BUILDROOT/wzskcmbd/CrdWzskSht/

cp Makefile_CrdWzskFil $BUILDROOT/wzskcmbd/CrdWzskFil/Makefile

cp ../../wzskcmbd/CrdWzskFil/*.h $BUILDROOT/wzskcmbd/CrdWzskFil/
cp ../../wzskcmbd/CrdWzskFil/*.cpp $BUILDROOT/wzskcmbd/CrdWzskFil/
