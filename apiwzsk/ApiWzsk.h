/**
	* \file ApiWzsk.h
	* Wzsk API library global functionality (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef APIWZSK_H
#define APIWZSK_H

#define WZSK_VERSION "1.0.11"
#define WZSK_VERSION_MAJOR 1
#define WZSK_VERSION_MINOR 0
#define WZSK_VERSION_SUB 11

#include "ApiWzsk_blks.h"

#include "WzskQFilList.h"
#include "WzskQObj1NShot.h"
#include "WzskQObjList.h"
#include "WzskQObjRef1NFile.h"
#include "WzskQOgr1NObject.h"
#include "WzskQOgrList.h"
#include "WzskQOgrSup1NObjgroup.h"
#include "WzskQPrsADetail.h"
#include "WzskQPrsList.h"
#include "WzskQSes1NShot.h"
#include "WzskQSesList.h"
#include "WzskQShtAPar.h"
#include "WzskQShtList.h"
#include "WzskQShtRef1NFile.h"
#include "WzskQUsgAAccess.h"
#include "WzskQUsgList.h"
#include "WzskQUsgMNUser.h"
#include "WzskQUsr1NSession.h"
#include "WzskQUsrAAccess.h"
#include "WzskQUsrList.h"
#include "WzskQUsrMNUsergroup.h"

#include "CrdWzskFil.h"
#include "CrdWzskLiv.h"
#include "CrdWzskLlv.h"
#include "CrdWzskNav.h"
#include "CrdWzskObj.h"
#include "CrdWzskOgr.h"
#include "CrdWzskPrs.h"
#include "CrdWzskScf.h"
#include "CrdWzskSes.h"
#include "CrdWzskSht.h"
#include "CrdWzskUsg.h"
#include "CrdWzskUsr.h"
#include "DlgWzskFilDownload.h"
#include "DlgWzskNavLoaini.h"
#include "DlgWzskObjNew.h"
#include "DlgWzskOgrNew.h"
#include "DlgWzskScfCameramat.h"
#include "DlgWzskScfLaserpos.h"
#include "DlgWzskScfTtablecoord.h"
#include "M2msessWzsk.h"
#include "PnlWzskFilDetail.h"
#include "PnlWzskFilHeadbar.h"
#include "PnlWzskFilList.h"
#include "PnlWzskFilRec.h"
#include "PnlWzskLiv2DView.h"
#include "PnlWzskLiv3DView.h"
#include "PnlWzskLivHeadbar.h"
#include "PnlWzskLivSysmon.h"
#include "PnlWzskLlvCamera.h"
#include "PnlWzskLlvHeadbar.h"
#include "PnlWzskLlvLaser.h"
#include "PnlWzskLlvTermArty.h"
#include "PnlWzskLlvTermClnxevb.h"
#include "PnlWzskLlvTermIcicle.h"
#include "PnlWzskLlvTermMcvevp.h"
#include "PnlWzskLlvTermUvbdvk.h"
#include "PnlWzskLlvTtable.h"
#include "PnlWzskNavAdmin.h"
#include "PnlWzskNavGlry.h"
#include "PnlWzskNavHeadbar.h"
#include "PnlWzskNavOp.h"
#include "PnlWzskNavPre.h"
#include "PnlWzskObj1NShot.h"
#include "PnlWzskObjDetail.h"
#include "PnlWzskObjHeadbar.h"
#include "PnlWzskObjList.h"
#include "PnlWzskObjRec.h"
#include "PnlWzskObjRef1NFile.h"
#include "PnlWzskOgr1NObject.h"
#include "PnlWzskOgrDetail.h"
#include "PnlWzskOgrHeadbar.h"
#include "PnlWzskOgrList.h"
#include "PnlWzskOgrRec.h"
#include "PnlWzskOgrSup1NObjgroup.h"
#include "PnlWzskPrsADetail.h"
#include "PnlWzskPrsDetail.h"
#include "PnlWzskPrsHeadbar.h"
#include "PnlWzskPrsList.h"
#include "PnlWzskPrsRec.h"
#include "PnlWzskScfConn.h"
#include "PnlWzskScfGeom.h"
#include "PnlWzskScfHeadbar.h"
#include "PnlWzskSes1NShot.h"
#include "PnlWzskSesDetail.h"
#include "PnlWzskSesHeadbar.h"
#include "PnlWzskSesList.h"
#include "PnlWzskSesRec.h"
#include "PnlWzskShtAPar.h"
#include "PnlWzskShtDetail.h"
#include "PnlWzskShtHeadbar.h"
#include "PnlWzskShtList.h"
#include "PnlWzskShtRec.h"
#include "PnlWzskShtRef1NFile.h"
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
#include "QryWzskFilList.h"
#include "QryWzskObj1NShot.h"
#include "QryWzskObjList.h"
#include "QryWzskObjRef1NFile.h"
#include "QryWzskOgr1NObject.h"
#include "QryWzskOgrList.h"
#include "QryWzskOgrSup1NObjgroup.h"
#include "QryWzskPrsADetail.h"
#include "QryWzskPrsList.h"
#include "QryWzskSes1NShot.h"
#include "QryWzskSesList.h"
#include "QryWzskShtAPar.h"
#include "QryWzskShtList.h"
#include "QryWzskShtRef1NFile.h"
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
