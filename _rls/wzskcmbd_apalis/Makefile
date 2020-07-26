# file Makefile
# make file for Wzsk combined daemon, release wzskcmbd_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 23 Jul 2020
# modified: 23 Jul 2020

include Makefile.inc

CPP = ${TCHROOT}/arm-tdx-linux-gnueabi-g++
CPPFLAGS = --sysroot=${SYSROOT} -std=c++11 -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard -g -Wall -Os -pthread -DWZSKCMBD -DRTI_LINUX -DRTI_UNIX

LINK = ${TCHROOT}/arm-tdx-linux-gnueabi-g++
LINKFLAGS = --sysroot=${SYSROOT}

INCPATH = -I=$(SRCROOT)/dbswzsk -I=$(SRCROOT)/wzskcmbd/VecWzsk -I=$(SRCROOT)/wzskcmbd/IexWzsk -I=$(SRCROOT)/wzskcmbd
INCPATH += -I=$(SRCROOT)/wzskcmbd/CrdWzskNav -I=$(SRCROOT)/wzskcmbd/CrdWzskUsg -I=$(SRCROOT)/wzskcmbd/CrdWzskUsr -I=$(SRCROOT)/wzskcmbd/CrdWzskPrs -I=$(SRCROOT)/wzskcmbd/CrdWzskScf -I=$(SRCROOT)/wzskcmbd/CrdWzskLlv -I=$(SRCROOT)/wzskcmbd/CrdWzskLiv -I=$(SRCROOT)/wzskcmbd/CrdWzskOgr -I=$(SRCROOT)/wzskcmbd/CrdWzskObj -I=$(SRCROOT)/wzskcmbd/CrdWzskSes -I=$(SRCROOT)/wzskcmbd/CrdWzskSht -I=$(SRCROOT)/wzskcmbd/CrdWzskFil
INCPATH += -I=${NDDSHOME}/include -I=${NDDSHOME}/include/ndds -I=${NDDSHOME}/include/ndds/hpp -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/atomic/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/file/linux_windows -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/library/linux_windows -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/locks/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/ref_count/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/tcpip/windows_linux_sockets_select_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/thread_pool/any_platform_st -I=${UASDKROOT}/SDK_Source/interface/common/platform_specific/timers/any_platform_polled -I=${UASDKROOT}/SDK_Source/interface/common/portable/address_space -I=${UASDKROOT}/SDK_Source/interface/common/portable/address_space/helpers -I=${UASDKROOT}/SDK_Source/interface/common/portable/data_types -I=${UASDKROOT}/SDK_Source/interface/common/portable/data_types/helper -I=${UASDKROOT}/SDK_Source/interface/common/portable/miscellaneous -I=${UASDKROOT}/SDK_Source/interface/common/portable/smart_pointers -I=${UASDKROOT}/SDK_Source/interface/common/portable/ua_messages -I=${UASDKROOT}/SDK_Source/interface/server/platform_specific/server_class/windows_linux_st -I=${UASDKROOT}/SDK_Source/interface/server/portable -I=${UASDKROOT}/SDK_Source/internals -I=${WHIZROOT}/src -I=${WHIZROOT}/src/ezdevwskd -I=/usr/include -I=/usr/include/libxml2

PCHS = Wzskcmbd.h.gch

OBJS = Wzsk.o WzskcmbdAppsrv.o WzskcmbdJobprc.o WzskcmbdOpprc.o Wzskcmbd.o
OBJS += DdsWzskPlugin.o DdsWzsk.o WzskcmbdDdspub.o
OBJS += WzskcmbdUasrv.o
OBJS += RootWzsk.o M2msessWzsk.o SessWzsk.o JobWzskAcqFpgaflg.o JobWzskAcqFpgapvw.o JobWzskAcqPreview.o JobWzskActLaser.o JobWzskActServo.o JobWzskIprCorner.o JobWzskIprTrace.o JobWzskSrcFpga.o JobWzskSrcV4l2.o
OBJS += Wzskcmbd_exe.o

LIBPATH = -L=$(LIBROOT)
LIBPATH += -L=$(LIBROOT)/wzskcmbd
LIBPATH += -L=${NDDSHOME}/lib/armv7aWRLinux8gcc5.2.0 -L=${WHIZROOT}/lib -L=/usr/lib -L=/usr/local/lib
LIBPATH += -L=/lib

LIBS = -lcrdwzsknav -lcrdwzskusg -lcrdwzskusr -lcrdwzskprs -lcrdwzskscf -lcrdwzskllv -lcrdwzskliv -lcrdwzskogr -lcrdwzskobj -lcrdwzskses -lcrdwzsksht -lcrdwzskfil
LIBS += -liexwzsk -lvecwzsk -ldbswzsk
LIBS += -lezdevwskd -lmicrohttpd -lopcua -lpng -lrticonnextmsgcpp2 -lsbecore_lite -lsbecore_mon
LIBS += -ldbecore -lnddscpp2 -lsbecore_plus -lsqlite3
LIBS += -lnddsc -lsbecore
LIBS += -lnddscore -lxml2
LIBS += -lz
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
	mv $(EXE) ${SYSROOT}$(BINROOT)/wzskcmbd/

clean:
	rm -f *.gch
	rm -f *.o

