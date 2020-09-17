# file Makefile
# make file for Wzsk database access library, release dbswzsk_linux
# author Catherine Johnson
# date created: 16 Sep 2020
# modified: 16 Sep 2020

LIBROOT = ${WHIZROOT}/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I${WHIZROOT}/src -I/usr/include -I/usr/include/libxml2 -I/usr/include/mysql

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

