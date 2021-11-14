# file Makefile
# make file for Wzsk combined daemon, release wzskcmbd_riscv_mpsi (jack cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 14 Nov 2021
# IP header --- ABOVE

include Makefile.inc

CPP = ${TCHROOT}/riscv64-oe-linux-g++
CPPFLAGS = --sysroot=/home/mpsitech/emb/icicle/wzsk/sdk/sysroots/riscv64-oe-linux --sysroot=${SYSROOT} -std=c++11 -fstack-protector-strong -g -Wall -Os -pthread -DWZSKCMBD

LINK = ${TCHROOT}/riscv64-oe-linux-g++
LINKFLAGS = --sysroot=/home/mpsitech/emb/icicle/wzsk/sdk/sysroots/riscv64-oe-linux

INCPATH = -I=$(BUILDROOT)/dbswzsk -I=$(BUILDROOT)/wzskcmbd/VecWzsk -I=$(BUILDROOT)/wzskcmbd/IexWzsk -I=$(BUILDROOT)/wzskcmbd
INCPATH += -I=$(BUILDROOT)/wzskcmbd/CrdWzskNav -I=$(BUILDROOT)/wzskcmbd/CrdWzskUsg -I=$(BUILDROOT)/wzskcmbd/CrdWzskUsr -I=$(BUILDROOT)/wzskcmbd/CrdWzskPrs -I=$(BUILDROOT)/wzskcmbd/CrdWzskScf -I=$(BUILDROOT)/wzskcmbd/CrdWzskLlv -I=$(BUILDROOT)/wzskcmbd/CrdWzskLiv -I=$(BUILDROOT)/wzskcmbd/CrdWzskOgr -I=$(BUILDROOT)/wzskcmbd/CrdWzskObj -I=$(BUILDROOT)/wzskcmbd/CrdWzskSes -I=$(BUILDROOT)/wzskcmbd/CrdWzskSht -I=$(BUILDROOT)/wzskcmbd/CrdWzskFil
INCPATH += -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/atomic/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/file/linux_windows -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/library/linux_windows -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/locks/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/ref_count/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/tcpip/windows_linux_sockets_select_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/thread_pool/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/timers/any_platform_polled -I=${UASDKROOT}/SDK_Source/interface/common/portable/address_space -I=${UASDKROOT}/SDK_Source/interface/common/portable/address_space/helpers -I=${UASDKROOT}/SDK_Source/interface/common/portable/data_types -I=${UASDKROOT}/SDK_Source/interface/common/portable/data_types/helper -I=${UASDKROOT}/SDK_Source/interface/common/portable/miscellaneous -I=${UASDKROOT}/SDK_Source/interface/common/portable/smart_pointers -I=${UASDKROOT}/SDK_Source/interface/common/portable/ua_messages -I=${UASDKROOT}/SDK_Source/interface/server/platform_specific/server_class/windows_linux_st -I=${UASDKROOT}/SDK_Source/interface/server/portable -I=${UASDKROOT}/SDK_Source/internals -I=${WHIZSDKROOT}/build -I=${WHIZSDKROOT}/build/ezdevwskd -I=/usr/include -I=/usr/include/libxml2

PCHS = Wzskcmbd.h.gch

OBJS = Wzsk.o WzskcmbdAppsrv.o WzskcmbdJobprc.o WzskcmbdOpprc.o Wzskcmbd.o
OBJS += WzskcmbdUasrv.o
OBJS += RootWzsk.o M2msessWzsk.o SessWzsk.o JobWzskAcqFpgaflg.o JobWzskAcqFpgapvw.o JobWzskAcqPreview.o JobWzskAcqPtcloud.o JobWzskActExposure.o JobWzskActLaser.o JobWzskActServo.o JobWzskIprAngle.o JobWzskIprCorner.o JobWzskIprTrace.o JobWzskSrcArty.o JobWzskSrcClnxevb.o JobWzskSrcIcicle.o JobWzskSrcMcvevp.o JobWzskSrcSysinfo.o JobWzskSrcUvbdvk.o JobWzskSrcV4l2.o
OBJS += Wzskcmbd_exe.o

LIBPATH = -L=$(LIBROOT)
LIBPATH += -L=$(LIBROOT)/wzskcmbd
LIBPATH += -L=${WHIZSDKROOT}/lib -L=/usr/lib
LIBPATH += -L=/lib

LIBS = -lcrdwzsknav -lcrdwzskusg -lcrdwzskusr -lcrdwzskprs -lcrdwzskscf -lcrdwzskllv -lcrdwzskliv -lcrdwzskogr -lcrdwzskobj -lcrdwzskses -lcrdwzsksht -lcrdwzskfil
LIBS += -liexwzsk -lvecwzsk -ldbswzsk
LIBS += -lezdevwskd -lmicrohttpd -lopcua -lpng -lsbecore_lite -lsbecore_mon
LIBS += -ldbecore -lsbecore_plus -lsqlite3
LIBS += -lsbecore
LIBS += -ljsoncpp -lxml2
LIBS += -lpthread

EXE = Wzskcmbd

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(PCHS) $(EXE)

$(EXE):	$(OBJS)
	$(LINK) $(LINKFLAGS) $(OBJS) $(LIBPATH) $(LIBS) -o $(EXE)
	rm -f *.o

pch:	$(PCHS)

install:
	mv $(EXE) /home/mpsitech/emb/icicle/wzsk/sdk/sysroots/riscv64-oe-linux$(BINROOT)/wzskcmbd/

clean:
	rm -f *.gch
	rm -f *.o
