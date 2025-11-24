# file Makefile
# make file for Wzsk combined daemon, release wzskcmbd_riscv32 (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

include Makefile.inc

CPP = ${TCHROOT}/riscv32-buildroot-linux-gnu-g++
CPPFLAGS = --sysroot=${SYSROOT} -std=c++11 -fstack-protector-strong -g -Wall -Os -pthread -DWZSKCMBD

LINK = ${TCHROOT}/riscv32-buildroot-linux-gnu-g++
LINKFLAGS = --sysroot=${SYSROOT}

INCPATH = -I=$(BUILDROOT)/dbswzsk -I=$(BUILDROOT)/wzskcmbd/VecWzsk -I=$(BUILDROOT)/wzskcmbd/IexWzsk -I=$(BUILDROOT)/wzskcmbd
INCPATH += -I=$(BUILDROOT)/wzskcmbd/CrdWzskNav -I=$(BUILDROOT)/wzskcmbd/CrdWzskUsg -I=$(BUILDROOT)/wzskcmbd/CrdWzskUsr -I=$(BUILDROOT)/wzskcmbd/CrdWzskPrs -I=$(BUILDROOT)/wzskcmbd/CrdWzskPrf -I=$(BUILDROOT)/wzskcmbd/CrdWzskLlv -I=$(BUILDROOT)/wzskcmbd/CrdWzskVtr -I=$(BUILDROOT)/wzskcmbd/CrdWzskHwc -I=$(BUILDROOT)/wzskcmbd/CrdWzskFil
INCPATH += -I=${WHIZSDKROOT}/build -I=${WHIZSDKROOT}/build/ezdevwskd -I=/usr/include -I=/usr/include/libxml2

PCHS = Wzskcmbd.h.gch

OBJS = Wzsk.o WzskcmbdAppsrv.o WzskcmbdJobprc.o WzskcmbdOpprc.o Wzskcmbd.o
OBJS += RootWzsk.o M2msessWzsk.o SessWzsk.o JobWzskAcqCorner.o JobWzskAcqHdr.o JobWzskAcqMemtrack.o JobWzskAcqPreview.o JobWzskAcqTrace.o JobWzskAcqVtrtrack.o JobWzskActLaser.o JobWzskActRotary.o JobWzskActVistorot.o JobWzskPrcAngle.o JobWzskPrcWavelet.o JobWzskSrcDcvsp.o JobWzskSrcFpgainfo.o JobWzskSrcSysinfo.o JobWzskSrcTivsp.o JobWzskSrcZuvsp.o
OBJS += Wzskcmbd_exe.o

LIBPATH = -L=$(LIBROOT)
LIBPATH += -L=$(LIBROOT)/wzskcmbd
LIBPATH += -L=${WHIZSDKROOT}/lib -L=/usr/lib
LIBPATH += -L=/lib

LIBS = -lcrdwzsknav -lcrdwzskusg -lcrdwzskusr -lcrdwzskprs -lcrdwzskprf -lcrdwzskllv -lcrdwzskvtr -lcrdwzskhwc -lcrdwzskfil
LIBS += -liexwzsk -lvecwzsk -ldbswzsk
LIBS += -lezdevwskd -lmicrohttpd -lsbecore_lite -lsbecore_mon
LIBS += -ldbecore -lsqlite3
LIBS += -lsbecore_plus
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

pch:	$(PCHS)

install:
	mv $(EXE) ${SYSROOT}$(BINROOT)/wzskcmbd/

clean:
	rm -f *.gch
	rm -f *.o
