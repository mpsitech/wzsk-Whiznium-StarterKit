/**
	* \file ApiWzsk.h
	* Wzsk API library global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef APIWZSK_H
#define APIWZSK_H

#define WZSK_VERSION "1.2.12"
#define WZSK_VERSION_MAJOR 1
#define WZSK_VERSION_MINOR 2
#define WZSK_VERSION_SUB 12

#include "ApiWzsk_blks.h"

#include "WzskQFilList.h"
#include "WzskQPrsADetail.h"
#include "WzskQPrsList.h"
#include "WzskQUsgAAccess.h"
#include "WzskQUsgList.h"
#include "WzskQUsgMNUser.h"
#include "WzskQUsr1NSession.h"
#include "WzskQUsrAAccess.h"
#include "WzskQUsrList.h"
#include "WzskQUsrMNUsergroup.h"

#include "CrdWzskFil.h"
#include "CrdWzskHwc.h"
#include "CrdWzskLlv.h"
#include "CrdWzskNav.h"
#include "CrdWzskPrf.h"
#include "CrdWzskPrs.h"
#include "CrdWzskUsg.h"
#include "CrdWzskUsr.h"
#include "CrdWzskVtr.h"
#include "DlgWzskFilDownload.h"
#include "DlgWzskNavLoaini.h"
#include "M2msessWzsk.h"
#include "PnlWzskFilDetail.h"
#include "PnlWzskFilHeadbar.h"
#include "PnlWzskFilList.h"
#include "PnlWzskFilRec.h"
#include "PnlWzskHwcAsys.h"
#include "PnlWzskHwcConfig.h"
#include "PnlWzskHwcDebug.h"
#include "PnlWzskHwcHeadbar.h"
#include "PnlWzskLlvHeadbar.h"
#include "PnlWzskLlvIdent.h"
#include "PnlWzskLlvLaser.h"
#include "PnlWzskLlvRotary.h"
#include "PnlWzskLlvSysmon.h"
#include "PnlWzskLlvTermDcvsp.h"
#include "PnlWzskLlvTermTivsp.h"
#include "PnlWzskLlvTermZuvsp.h"
#include "PnlWzskNavAdmin.h"
#include "PnlWzskNavHeadbar.h"
#include "PnlWzskNavOp.h"
#include "PnlWzskPrfAcqCorner.h"
#include "PnlWzskPrfAcqHdr.h"
#include "PnlWzskPrfAcqPreview.h"
#include "PnlWzskPrfAcqTrace.h"
#include "PnlWzskPrfActLaser.h"
#include "PnlWzskPrfActRotary.h"
#include "PnlWzskPrfActVistorot.h"
#include "PnlWzskPrfDaemon.h"
#include "PnlWzskPrfGlobal.h"
#include "PnlWzskPrfHeadbar.h"
#include "PnlWzskPrfSrcDcvsp.h"
#include "PnlWzskPrfSrcSysinfo.h"
#include "PnlWzskPrfSrcTivsp.h"
#include "PnlWzskPrfSrcZuvsp.h"
#include "PnlWzskPrsADetail.h"
#include "PnlWzskPrsDetail.h"
#include "PnlWzskPrsHeadbar.h"
#include "PnlWzskPrsList.h"
#include "PnlWzskPrsRec.h"
#include "PnlWzskUsgAAccess.h"
#include "PnlWzskUsgDetail.h"
#include "PnlWzskUsgHeadbar.h"
#include "PnlWzskUsgList.h"
#include "PnlWzskUsgMNUser.h"
#include "PnlWzskUsgRec.h"
#include "PnlWzskUsr1NSession.h"
#include "PnlWzskUsrAAccess.h"
#include "PnlWzskUsrDetail.h"
#include "PnlWzskUsrHeadbar.h"
#include "PnlWzskUsrList.h"
#include "PnlWzskUsrMNUsergroup.h"
#include "PnlWzskUsrRec.h"
#include "PnlWzskVtrConfig.h"
#include "PnlWzskVtrDebug.h"
#include "PnlWzskVtrHeadbar.h"
#include "PnlWzskVtrMonitor.h"
#include "QryWzskFilList.h"
#include "QryWzskPrsADetail.h"
#include "QryWzskPrsList.h"
#include "QryWzskUsgAAccess.h"
#include "QryWzskUsgList.h"
#include "QryWzskUsgMNUser.h"
#include "QryWzskUsr1NSession.h"
#include "QryWzskUsrAAccess.h"
#include "QryWzskUsrList.h"
#include "QryWzskUsrMNUsergroup.h"
#include "RootWzsk.h"
#include "SessWzsk.h"

/**
	* StgWzskapi
	*/
class StgWzskapi : public Sbecore::Block {

public:
	static const Sbecore::uint ENGIP = 1;
	static const Sbecore::uint ENGPORT = 2;
	static const Sbecore::uint USERNAME = 3;
	static const Sbecore::uint PASSWORD = 4;

public:
	StgWzskapi(const std::string engip = "", const Sbecore::uint engport = 0, const std::string username = "", const std::string password = "");

public:
	std::string engip;
	Sbecore::uint engport;
	std::string username;
	std::string password;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> compare(const StgWzskapi* comp);
};

/**
	* ApiWzsk
	*/
namespace ApiWzsk {
	Sbecore::uint readDpchEng(char* buf, unsigned long buflen, DpchEngWzsk** dpcheng);
	void writeDpchApp(DpchAppWzsk* dpchapp, char** buf, unsigned long& buflen, unsigned long ofs = 0);
};

#endif
