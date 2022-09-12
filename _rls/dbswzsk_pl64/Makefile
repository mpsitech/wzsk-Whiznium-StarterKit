# file Makefile
# make file for Wzsk database access library, release dbswzsk_pl64 (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Sep 2022
# IP header --- ABOVE

LIBROOT = ${SYSROOT}${WHIZSDKROOT}/lib

CPP = ${TCHROOT}/aarch64-xilinx-linux-g++
CPPFLAGS = --sysroot=${SYSROOT} --sysroot=${SYSROOT} -std=c++11 -march=armv8-a -mtune=cortex-a53 -g -Wall -Os -pthread

STATLIB = ${TCHROOT}/aarch64-xilinx-linux-ar
STATLIBFLAGS = rcs

INCPATH = -I=${WHIZSDKROOT}/build -I=/usr/include -I=/usr/include/libxml2

PCHS = DbsWzsk.h.gch

OBJS = DbsWzsk.o
OBJS += WzskAccRMUserUniversal.o WzskAMPersonDetail.o WzskAMShotPar.o WzskAMUserAccess.o WzskAMUsergroupAccess.o WzskAVControlPar.o WzskAVKeylistKey.o WzskAVValuelistVal.o WzskCFile.o WzskHistRMUserUniversal.o WzskJAVKeylistKey.o WzskJMObjgroupTitle.o WzskJMPersonLastname.o WzskJMUserState.o WzskMFile.o WzskMObject.o WzskMObjgroup.o WzskMPerson.o WzskMSession.o WzskMShot.o WzskMUser.o WzskMUsergroup.o WzskRMUsergroupUniversal.o WzskRMUserMUsergroup.o
OBJS += WzskQFilList.o WzskQObj1NShot.o WzskQObjList.o WzskQObjRef1NFile.o WzskQOgr1NObject.o WzskQOgrList.o WzskQOgrSup1NObjgroup.o WzskQPreselect.o WzskQPrsADetail.o WzskQPrsList.o WzskQSelect.o WzskQSes1NShot.o WzskQSesList.o WzskQShtAPar.o WzskQShtList.o WzskQShtRef1NFile.o WzskQUsgAAccess.o WzskQUsgList.o WzskQUsgMNUser.o WzskQUsr1NSession.o WzskQUsrAAccess.o WzskQUsrList.o WzskQUsrMNUsergroup.o

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
