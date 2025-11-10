# file Makefile
# make file for Wzsk database access library, release dbswzsk_riscv32 (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Oct 2025
# IP header --- ABOVE

LIBROOT = ${SYSROOT}${WHIZSDKROOT}/lib

CPP = ${TCHROOT}/riscv32-buildroot-linux-gnu-g++
CPPFLAGS = --sysroot=${SYSROOT} -std=c++11 -fstack-protector-strong -g -Wall -Os -pthread

STATLIB = ${TCHROOT}/riscv32-buildroot-linux-gnu-ar
STATLIBFLAGS = rcs

INCPATH = -I=${WHIZSDKROOT}/build -I=/usr/include -I=/usr/include/libxml2

PCHS = DbsWzsk.h.gch

OBJS = DbsWzsk.o
OBJS += WzskAccRMUserUniversal.o WzskAMPersonDetail.o WzskAMUserAccess.o WzskAMUsergroupAccess.o WzskAVControlPar.o WzskAVKeylistKey.o WzskAVValuelistVal.o WzskCFile.o WzskHistRMUserUniversal.o WzskJAVKeylistKey.o WzskJMPersonLastname.o WzskJMUserState.o WzskMFile.o WzskMPerson.o WzskMSession.o WzskMUser.o WzskMUsergroup.o WzskRMUsergroupUniversal.o WzskRMUserMUsergroup.o
OBJS += WzskQFilList.o WzskQPreselect.o WzskQPrsADetail.o WzskQPrsList.o WzskQSelect.o WzskQUsgAAccess.o WzskQUsgList.o WzskQUsgMNUser.o WzskQUsr1NSession.o WzskQUsrAAccess.o WzskQUsrList.o WzskQUsrMNUsergroup.o

LIB = libdbswzsk

.SUFFIXES:	.h .h.gch .cpp

.h.h.gch :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

.cpp.o :
	$(CPP) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

all:	$(LIB)

$(LIB):	$(PCHS) $(OBJS)
	$(STATLIB) $(STATLIBFLAGS) $(LIB).a $(OBJS)

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o
