#!/bin/bash
# file checkout.sh
# checkout script for Wzsk combined daemon, release wzskcmbd_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 16 Sep 2020
# modified: 16 Sep 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src
export set LIBROOT=${SYSROOT}${WHIZROOT}/lib
export set BINROOT=${SYSROOT}${WHIZROOT}/bin

mkdir $SRCROOT/wzskcmbd
mkdir $SRCROOT/wzskcmbd/IexWzsk
mkdir $SRCROOT/wzskcmbd/VecWzsk
mkdir $SRCROOT/wzskcmbd/CrdWzskUsg
mkdir $SRCROOT/wzskcmbd/CrdWzskUsr
mkdir $SRCROOT/wzskcmbd/CrdWzskPrs
mkdir $SRCROOT/wzskcmbd/CrdWzskScf
mkdir $SRCROOT/wzskcmbd/CrdWzskNav
mkdir $SRCROOT/wzskcmbd/CrdWzskLlv
mkdir $SRCROOT/wzskcmbd/CrdWzskLiv
mkdir $SRCROOT/wzskcmbd/CrdWzskOgr
mkdir $SRCROOT/wzskcmbd/CrdWzskObj
mkdir $SRCROOT/wzskcmbd/CrdWzskSes
mkdir $SRCROOT/wzskcmbd/CrdWzskSht
mkdir $SRCROOT/wzskcmbd/CrdWzskFil

mkdir $LIBROOT/wzskcmbd

mkdir $BINROOT/wzskcmbd

cp make.sh $SRCROOT/wzskcmbd/
cp remake.sh $SRCROOT/wzskcmbd/

cp Makefile.inc $SRCROOT/wzskcmbd/
cp Makefile $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/Wzskcmbd.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/Wzskcmbd.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdAppsrv.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdAppsrv.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdJobprc.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdJobprc.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdOpprc.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdOpprc.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/DDS/*.hpp $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/DDS/*.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdDdspub.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdDdspub.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/SDK_Configuration/*.h $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/WzskcmbdUasrv.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/WzskcmbdUasrv.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/Wzskcmbd_exe.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/Wzskcmbd_exe.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/Wzsk.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/Wzsk.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/Root*.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/Root*.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/Sess*.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/Sess*.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/M2msess*.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/M2msess*.cpp $SRCROOT/wzskcmbd/

cp ../../wzskcmbd/gbl/*.h $SRCROOT/wzskcmbd/
cp ../../wzskcmbd/gbl/*.cpp $SRCROOT/wzskcmbd/

cp Makefile_IexWzsk $SRCROOT/wzskcmbd/IexWzsk/Makefile

cp ../../wzskcmbd/IexWzsk/IexWzsk*.h $SRCROOT/wzskcmbd/IexWzsk/
cp ../../wzskcmbd/IexWzsk/IexWzsk*.cpp $SRCROOT/wzskcmbd/IexWzsk/

cp ../../wzskcmbd/IexWzsk/JobWzskIex*.h $SRCROOT/wzskcmbd/IexWzsk/
cp ../../wzskcmbd/IexWzsk/JobWzskIex*.cpp $SRCROOT/wzskcmbd/IexWzsk/

cp Makefile_VecWzsk $SRCROOT/wzskcmbd/VecWzsk/Makefile

cp ../../wzskcmbd/VecWzsk/Vec*.h $SRCROOT/wzskcmbd/VecWzsk/
cp ../../wzskcmbd/VecWzsk/Vec*.cpp $SRCROOT/wzskcmbd/VecWzsk/

cp Makefile_CrdWzskUsg $SRCROOT/wzskcmbd/CrdWzskUsg/Makefile

cp ../../wzskcmbd/CrdWzskUsg/*.h $SRCROOT/wzskcmbd/CrdWzskUsg/
cp ../../wzskcmbd/CrdWzskUsg/*.cpp $SRCROOT/wzskcmbd/CrdWzskUsg/

cp Makefile_CrdWzskUsr $SRCROOT/wzskcmbd/CrdWzskUsr/Makefile

cp ../../wzskcmbd/CrdWzskUsr/*.h $SRCROOT/wzskcmbd/CrdWzskUsr/
cp ../../wzskcmbd/CrdWzskUsr/*.cpp $SRCROOT/wzskcmbd/CrdWzskUsr/

cp Makefile_CrdWzskPrs $SRCROOT/wzskcmbd/CrdWzskPrs/Makefile

cp ../../wzskcmbd/CrdWzskPrs/*.h $SRCROOT/wzskcmbd/CrdWzskPrs/
cp ../../wzskcmbd/CrdWzskPrs/*.cpp $SRCROOT/wzskcmbd/CrdWzskPrs/

cp Makefile_CrdWzskScf $SRCROOT/wzskcmbd/CrdWzskScf/Makefile

cp ../../wzskcmbd/CrdWzskScf/*.h $SRCROOT/wzskcmbd/CrdWzskScf/
cp ../../wzskcmbd/CrdWzskScf/*.cpp $SRCROOT/wzskcmbd/CrdWzskScf/

cp Makefile_CrdWzskNav $SRCROOT/wzskcmbd/CrdWzskNav/Makefile

cp ../../wzskcmbd/CrdWzskNav/*.h $SRCROOT/wzskcmbd/CrdWzskNav/
cp ../../wzskcmbd/CrdWzskNav/*.cpp $SRCROOT/wzskcmbd/CrdWzskNav/

cp Makefile_CrdWzskLlv $SRCROOT/wzskcmbd/CrdWzskLlv/Makefile

cp ../../wzskcmbd/CrdWzskLlv/*.h $SRCROOT/wzskcmbd/CrdWzskLlv/
cp ../../wzskcmbd/CrdWzskLlv/*.cpp $SRCROOT/wzskcmbd/CrdWzskLlv/

cp Makefile_CrdWzskLiv $SRCROOT/wzskcmbd/CrdWzskLiv/Makefile

cp ../../wzskcmbd/CrdWzskLiv/*.h $SRCROOT/wzskcmbd/CrdWzskLiv/
cp ../../wzskcmbd/CrdWzskLiv/*.cpp $SRCROOT/wzskcmbd/CrdWzskLiv/

cp Makefile_CrdWzskOgr $SRCROOT/wzskcmbd/CrdWzskOgr/Makefile

cp ../../wzskcmbd/CrdWzskOgr/*.h $SRCROOT/wzskcmbd/CrdWzskOgr/
cp ../../wzskcmbd/CrdWzskOgr/*.cpp $SRCROOT/wzskcmbd/CrdWzskOgr/

cp Makefile_CrdWzskObj $SRCROOT/wzskcmbd/CrdWzskObj/Makefile

cp ../../wzskcmbd/CrdWzskObj/*.h $SRCROOT/wzskcmbd/CrdWzskObj/
cp ../../wzskcmbd/CrdWzskObj/*.cpp $SRCROOT/wzskcmbd/CrdWzskObj/

cp Makefile_CrdWzskSes $SRCROOT/wzskcmbd/CrdWzskSes/Makefile

cp ../../wzskcmbd/CrdWzskSes/*.h $SRCROOT/wzskcmbd/CrdWzskSes/
cp ../../wzskcmbd/CrdWzskSes/*.cpp $SRCROOT/wzskcmbd/CrdWzskSes/

cp Makefile_CrdWzskSht $SRCROOT/wzskcmbd/CrdWzskSht/Makefile

cp ../../wzskcmbd/CrdWzskSht/*.h $SRCROOT/wzskcmbd/CrdWzskSht/
cp ../../wzskcmbd/CrdWzskSht/*.cpp $SRCROOT/wzskcmbd/CrdWzskSht/

cp Makefile_CrdWzskFil $SRCROOT/wzskcmbd/CrdWzskFil/Makefile

cp ../../wzskcmbd/CrdWzskFil/*.h $SRCROOT/wzskcmbd/CrdWzskFil/
cp ../../wzskcmbd/CrdWzskFil/*.cpp $SRCROOT/wzskcmbd/CrdWzskFil/

