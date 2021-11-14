# file Makefile
# make file for Wzsk API library, release apiwzsk_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 14 Nov 2021
# IP header --- ABOVE

LIBROOT = ${WHIZSDKROOT}/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I${WHIZSDKROOT}/build -I/usr/include/jsoncpp -I/usr/include/libxml2

PCHS = ApiWzsk.h.gch

OBJS = ApiWzsk_blks.o ApiWzsk.o
OBJS += VecWzskVDpch.o  VecWzskVExpstate.o VecWzskVPvwmode.o VecWzskVReqitmode.o VecWzskVSqrgrp.o VecWzskVTarget.o
OBJS += WzskQFilList.o WzskQObj1NShot.o WzskQObjList.o WzskQObjRef1NFile.o WzskQOgr1NObject.o WzskQOgrList.o WzskQOgrSup1NObjgroup.o WzskQPrsADetail.o WzskQPrsList.o WzskQSes1NShot.o WzskQSesList.o WzskQShtAPar.o WzskQShtList.o WzskQShtRef1NFile.o WzskQUsgAAccess.o WzskQUsgList.o WzskQUsgMNUser.o WzskQUsr1NSession.o WzskQUsrAAccess.o WzskQUsrList.o WzskQUsrMNUsergroup.o
OBJS += CrdWzskFil.o CrdWzskLiv.o CrdWzskLlv.o CrdWzskNav.o CrdWzskObj.o CrdWzskOgr.o CrdWzskPrs.o CrdWzskScf.o CrdWzskSes.o CrdWzskSht.o CrdWzskUsg.o CrdWzskUsr.o DlgWzskFilDownload.o DlgWzskNavLoaini.o DlgWzskObjNew.o DlgWzskOgrNew.o DlgWzskScfCameramat.o DlgWzskScfLaserpos.o DlgWzskScfTtablecoord.o M2msessWzsk.o PnlWzskFilDetail.o PnlWzskFilHeadbar.o PnlWzskFilList.o PnlWzskFilRec.o PnlWzskLiv2DView.o PnlWzskLiv3DView.o PnlWzskLivHeadbar.o PnlWzskLivSysmon.o PnlWzskLlvCamera.o PnlWzskLlvHeadbar.o PnlWzskLlvLaser.o PnlWzskLlvTermArty.o PnlWzskLlvTermClnxevb.o PnlWzskLlvTermIcicle.o PnlWzskLlvTermMcvevp.o PnlWzskLlvTermUvbdvk.o PnlWzskLlvTtable.o PnlWzskNavAdmin.o PnlWzskNavGlry.o PnlWzskNavHeadbar.o PnlWzskNavOp.o PnlWzskNavPre.o PnlWzskObj1NShot.o PnlWzskObjDetail.o PnlWzskObjHeadbar.o PnlWzskObjList.o PnlWzskObjRec.o PnlWzskObjRef1NFile.o PnlWzskOgr1NObject.o PnlWzskOgrDetail.o PnlWzskOgrHeadbar.o PnlWzskOgrList.o PnlWzskOgrRec.o PnlWzskOgrSup1NObjgroup.o PnlWzskPrsADetail.o PnlWzskPrsDetail.o PnlWzskPrsHeadbar.o PnlWzskPrsList.o PnlWzskPrsRec.o PnlWzskScfConn.o PnlWzskScfGeom.o PnlWzskScfHeadbar.o PnlWzskSes1NShot.o PnlWzskSesDetail.o PnlWzskSesHeadbar.o PnlWzskSesList.o PnlWzskSesRec.o PnlWzskShtAPar.o PnlWzskShtDetail.o PnlWzskShtHeadbar.o PnlWzskShtList.o PnlWzskShtRec.o PnlWzskShtRef1NFile.o PnlWzskUsgAAccess.o PnlWzskUsgDetail.o PnlWzskUsgHeadbar.o PnlWzskUsgList.o PnlWzskUsgMNUser.o PnlWzskUsgRec.o PnlWzskUsr1NSession.o PnlWzskUsrAAccess.o PnlWzskUsrDetail.o PnlWzskUsrHeadbar.o PnlWzskUsrList.o PnlWzskUsrMNUsergroup.o PnlWzskUsrRec.o QryWzskFilList.o QryWzskObj1NShot.o QryWzskObjList.o QryWzskObjRef1NFile.o QryWzskOgr1NObject.o QryWzskOgrList.o QryWzskOgrSup1NObjgroup.o QryWzskPrsADetail.o QryWzskPrsList.o QryWzskSes1NShot.o QryWzskSesList.o QryWzskShtAPar.o QryWzskShtList.o QryWzskShtRef1NFile.o QryWzskUsgAAccess.o QryWzskUsgList.o QryWzskUsgMNUser.o QryWzskUsr1NSession.o QryWzskUsrAAccess.o QryWzskUsrList.o QryWzskUsrMNUsergroup.o RootWzsk.o SessWzsk.o

LIB = libapiwzsk

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
