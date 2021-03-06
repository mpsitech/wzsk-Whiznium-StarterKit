# file Makefile
# make file for Wzsk combined daemon, release wzskcmbd_riscv (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 11 Mar 2021
# IP header --- ABOVE

include Makefile.inc

CPP = ${TCHROOT}/riscv64-oe-linux-g++
CPPFLAGS = --sysroot=${SYSROOT} --sysroot=${SYSROOT} -std=c++11 -fstack-protector-strong -g -Wall -Os -pthread -DWZSKCMBD

LINK = ${TCHROOT}/riscv64-oe-linux-g++
LINKFLAGS = --sysroot=${SYSROOT}

INCPATH = -I=$(BUILDROOT)/dbswzsk -I=$(BUILDROOT)/wzskcmbd/VecWzsk -I=$(BUILDROOT)/wzskcmbd/IexWzsk -I=$(BUILDROOT)/wzskcmbd
INCPATH += -I=$(BUILDROOT)/wzskcmbd/CrdWzskUsg -I=$(BUILDROOT)/wzskcmbd/CrdWzskUsr -I=$(BUILDROOT)/wzskcmbd/CrdWzskPrs -I=$(BUILDROOT)/wzskcmbd/CrdWzskScf -I=$(BUILDROOT)/wzskcmbd/CrdWzskNav -I=$(BUILDROOT)/wzskcmbd/CrdWzskLlv -I=$(BUILDROOT)/wzskcmbd/CrdWzskLiv -I=$(BUILDROOT)/wzskcmbd/CrdWzskOgr -I=$(BUILDROOT)/wzskcmbd/CrdWzskObj -I=$(BUILDROOT)/wzskcmbd/CrdWzskSes -I=$(BUILDROOT)/wzskcmbd/CrdWzskSht -I=$(BUILDROOT)/wzskcmbd/CrdWzskFil
INCPATH += -I=${WHIZSDKROOT}/build -I=${WHIZSDKROOT}/build/ezdevwskd -I=/usr/include -I=/usr/include/libxml2

PCHS = Wzskcmbd.h.gch

OBJS = Wzsk.o WzskcmbdAppsrv.o WzskcmbdJobprc.o WzskcmbdOpprc.o Wzskcmbd.o
OBJS += RootWzsk.o M2msessWzsk.o SessWzsk.o JobWzskAcqFpgaflg.o JobWzskAcqFpgapvw.o JobWzskAcqPreview.o JobWzskAcqPtcloud.o JobWzskActExposure.o JobWzskActLaser.o JobWzskActServo.o JobWzskIprAngle.o JobWzskIprCorner.o JobWzskIprTrace.o JobWzskSrcFpga.o JobWzskSrcSysinfo.o JobWzskSrcV4l2.o
OBJS += Wzskcmbd_exe.o

LIBPATH = -L=$(LIBROOT)
LIBPATH += -L=$(LIBROOT)/wzskcmbd
LIBPATH += -L=${WHIZSDKROOT}/lib -L=/usr/lib
LIBPATH += -L=/lib

LIBS = -lcrdwzskusg -lcrdwzskusr -lcrdwzskprs -lcrdwzskscf -lcrdwzsknav -lcrdwzskllv -lcrdwzskliv -lcrdwzskogr -lcrdwzskobj -lcrdwzskses -lcrdwzsksht -lcrdwzskfil
LIBS += -liexwzsk -lvecwzsk -ldbswzsk
LIBS += -lezdevwskd -lmicrohttpd -lpng -lsbecore_lite -lsbecore_mon
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
	mv $(EXE) ${SYSROOT}$(BINROOT)/wzskcmbd/

clean:
	rm -f *.gch
	rm -f *.o
