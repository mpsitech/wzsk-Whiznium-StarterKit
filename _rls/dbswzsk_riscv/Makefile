# file Makefile
# make file for Wzsk database access library, release dbswzsk_riscv (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 15 Dec 2020
# IP header --- ABOVE

LIBROOT = ${SYSROOT}${WHIZSDKROOT}/lib

CPP = 
CPPFLAGS = --sysroot=${SYSROOT}

STATLIB = 
STATLIBFLAGS = rcs

INCPATH = -I=${WHIZSDKROOT}/build -I=/usr/include/libxml2

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
	rm -f *.o

install:
	mv $(LIB).a $(LIBROOT)/

clean:
	rm -f *.gch
	rm -f *.o