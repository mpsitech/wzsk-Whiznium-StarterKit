# file Makefile
# make file for Wzsk API library, release apiwzsk_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

LIBROOT = ${WHIZSDKROOT}/lib

CPP = g++
CPPFLAGS = -std=c++11 -g -Wall -Os -pthread

STATLIB = ar
STATLIBFLAGS = rcs

INCPATH = -I${WHIZSDKROOT}/build -I/usr/include/jsoncpp -I/usr/include/libxml2

PCHS = ApiWzsk.h.gch

OBJS = ApiWzsk_blks.o ApiWzsk.o
OBJS += VecWzskVDpch.o  VecWzskVExpstate.o VecWzskVReqitmode.o VecWzskVTarget.o
OBJS += WzskQFilList.o WzskQPrsADetail.o WzskQPrsList.o WzskQUsgAAccess.o WzskQUsgList.o WzskQUsgMNUser.o WzskQUsr1NSession.o WzskQUsrAAccess.o WzskQUsrList.o WzskQUsrMNUsergroup.o
OBJS += CrdWzskFil.o CrdWzskHwc.o CrdWzskLlv.o CrdWzskNav.o CrdWzskPrf.o CrdWzskPrs.o CrdWzskUsg.o CrdWzskUsr.o CrdWzskVtr.o DlgWzskFilDownload.o DlgWzskNavLoaini.o M2msessWzsk.o PnlWzskFilDetail.o PnlWzskFilHeadbar.o PnlWzskFilList.o PnlWzskFilRec.o PnlWzskHwcAsys.o PnlWzskHwcConfig.o PnlWzskHwcDebug.o PnlWzskHwcHeadbar.o PnlWzskLlvHeadbar.o PnlWzskLlvIdent.o PnlWzskLlvLaser.o PnlWzskLlvRotary.o PnlWzskLlvSysmon.o PnlWzskLlvTermDcvsp.o PnlWzskLlvTermTivsp.o PnlWzskLlvTermZuvsp.o PnlWzskNavAdmin.o PnlWzskNavHeadbar.o PnlWzskNavOp.o PnlWzskPrfAcqCorner.o PnlWzskPrfAcqHdr.o PnlWzskPrfAcqPreview.o PnlWzskPrfAcqTrace.o PnlWzskPrfActLaser.o PnlWzskPrfActRotary.o PnlWzskPrfActVistorot.o PnlWzskPrfDaemon.o PnlWzskPrfGlobal.o PnlWzskPrfHeadbar.o PnlWzskPrfSrcDcvsp.o PnlWzskPrfSrcSysinfo.o PnlWzskPrfSrcTivsp.o PnlWzskPrfSrcZuvsp.o PnlWzskPrsADetail.o PnlWzskPrsDetail.o PnlWzskPrsHeadbar.o PnlWzskPrsList.o PnlWzskPrsRec.o PnlWzskUsgAAccess.o PnlWzskUsgDetail.o PnlWzskUsgHeadbar.o PnlWzskUsgList.o PnlWzskUsgMNUser.o PnlWzskUsgRec.o PnlWzskUsr1NSession.o PnlWzskUsrAAccess.o PnlWzskUsrDetail.o PnlWzskUsrHeadbar.o PnlWzskUsrList.o PnlWzskUsrMNUsergroup.o PnlWzskUsrRec.o PnlWzskVtrConfig.o PnlWzskVtrDebug.o PnlWzskVtrHeadbar.o PnlWzskVtrMonitor.o QryWzskFilList.o QryWzskPrsADetail.o QryWzskPrsList.o QryWzskUsgAAccess.o QryWzskUsgList.o QryWzskUsgMNUser.o QryWzskUsr1NSession.o QryWzskUsrAAccess.o QryWzskUsrList.o QryWzskUsrMNUsergroup.o RootWzsk.o SessWzsk.o

LIB = libapiwzsk

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
