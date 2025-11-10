/**
	* \file ApiWzsk.cpp
	* Wzsk API library global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "ApiWzsk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class StgWzskapi
 ******************************************************************************/

StgWzskapi::StgWzskapi(
			const string engip
			, const uint engport
			, const string username
			, const string password
		) :
			Block()
			, engip(engip)
			, engport(engport)
			, username(username)
			, password(password)
		{
	mask = {ENGIP, ENGPORT, USERNAME, PASSWORD};
};

bool StgWzskapi::all(
			const set<uint>& items
		) {
	if (!find(items, ENGIP)) return false;
	if (!find(items, ENGPORT)) return false;
	if (!find(items, USERNAME)) return false;
	if (!find(items, PASSWORD)) return false;

	return true;
};

bool StgWzskapi::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgWzskapi");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemWzskapi";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engip", engip)) add(ENGIP);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "engport", engport)) add(ENGPORT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "username", username)) add(USERNAME);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "password", password)) add(PASSWORD);
	};

	return basefound;
};

void StgWzskapi::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgWzskapi";

	string itemtag;
	if (shorttags)
		itemtag = "Si";
	else
		itemtag = "StgitemWzskapi";

	// XML output
	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "engip", engip);
		writeUintAttr(wr, itemtag, "sref", "engport", engport);
		writeStringAttr(wr, itemtag, "sref", "username", username);
		writeStringAttr(wr, itemtag, "sref", "password", password);
	xmlTextWriterEndElement(wr);
};

set<uint> StgWzskapi::compare(
			const StgWzskapi* comp
		) {
	set<uint> items;

	if (engip == comp->engip) insert(items, ENGIP);
	if (engport == comp->engport) insert(items, ENGPORT);
	if (username == comp->username) insert(items, USERNAME);
	if (password == comp->password) insert(items, PASSWORD);

	return items;
};

/******************************************************************************
 namespace ApiWzsk
 ******************************************************************************/

uint ApiWzsk::readDpchEng(
			char* buf
			, unsigned long buflen
			, DpchEngWzsk** dpcheng
		) {
	uint ixWzskVDpch = 0;

	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	try {
		parseBuffer(buf, buflen, &doc, &docctx);

		ixWzskVDpch = VecWzskVDpch::getIx(extractRoot(doc));

		if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKFILDOWNLOADDATA) {
			*dpcheng = new DlgWzskFilDownload::DpchEngData();
			((DlgWzskFilDownload::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKNAVLOAINIDATA) {
			*dpcheng = new DlgWzskNavLoaini::DpchEngData();
			((DlgWzskNavLoaini::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGM2MSESSWZSKDATA) {
			*dpcheng = new M2msessWzsk::DpchEngData();
			((M2msessWzsk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGROOTWZSKDATA) {
			*dpcheng = new RootWzsk::DpchEngData();
			((RootWzsk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGSESSWZSKDATA) {
			*dpcheng = new SessWzsk::DpchEngData();
			((SessWzsk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKACK) {
			*dpcheng = new DpchEngWzskAck();
			((DpchEngWzskAck*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKALERT) {
			*dpcheng = new DpchEngWzskAlert();
			((DpchEngWzskAlert*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKCONFIRM) {
			*dpcheng = new DpchEngWzskConfirm();
			((DpchEngWzskConfirm*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKFILDATA) {
			*dpcheng = new CrdWzskFil::DpchEngData();
			((CrdWzskFil::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKFILDETAILDATA) {
			*dpcheng = new PnlWzskFilDetail::DpchEngData();
			((PnlWzskFilDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKFILHEADBARDATA) {
			*dpcheng = new PnlWzskFilHeadbar::DpchEngData();
			((PnlWzskFilHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKFILLISTDATA) {
			*dpcheng = new PnlWzskFilList::DpchEngData();
			((PnlWzskFilList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKFILRECDATA) {
			*dpcheng = new PnlWzskFilRec::DpchEngData();
			((PnlWzskFilRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCASYSDATA) {
			*dpcheng = new PnlWzskHwcAsys::DpchEngData();
			((PnlWzskHwcAsys::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCCONFIGALIGN) {
			*dpcheng = new PnlWzskHwcConfig::DpchEngAlign();
			((PnlWzskHwcConfig::DpchEngAlign*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCCONFIGDATA) {
			*dpcheng = new PnlWzskHwcConfig::DpchEngData();
			((PnlWzskHwcConfig::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCCONFIGLIVE) {
			*dpcheng = new PnlWzskHwcConfig::DpchEngLive();
			((PnlWzskHwcConfig::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCDATA) {
			*dpcheng = new CrdWzskHwc::DpchEngData();
			((CrdWzskHwc::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCDEBUGDATA) {
			*dpcheng = new PnlWzskHwcDebug::DpchEngData();
			((PnlWzskHwcDebug::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKHWCHEADBARDATA) {
			*dpcheng = new PnlWzskHwcHeadbar::DpchEngData();
			((PnlWzskHwcHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVDATA) {
			*dpcheng = new CrdWzskLlv::DpchEngData();
			((CrdWzskLlv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVHEADBARDATA) {
			*dpcheng = new PnlWzskLlvHeadbar::DpchEngData();
			((PnlWzskLlvHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVIDENTDATA) {
			*dpcheng = new PnlWzskLlvIdent::DpchEngData();
			((PnlWzskLlvIdent::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVLASERDATA) {
			*dpcheng = new PnlWzskLlvLaser::DpchEngData();
			((PnlWzskLlvLaser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVROTARYDATA) {
			*dpcheng = new PnlWzskLlvRotary::DpchEngData();
			((PnlWzskLlvRotary::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVSYSMONDATA) {
			*dpcheng = new PnlWzskLlvSysmon::DpchEngData();
			((PnlWzskLlvSysmon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVSYSMONLIVE) {
			*dpcheng = new PnlWzskLlvSysmon::DpchEngLive();
			((PnlWzskLlvSysmon::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMDCVSPDATA) {
			*dpcheng = new PnlWzskLlvTermDcvsp::DpchEngData();
			((PnlWzskLlvTermDcvsp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMTIVSPDATA) {
			*dpcheng = new PnlWzskLlvTermTivsp::DpchEngData();
			((PnlWzskLlvTermTivsp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMZUVSPDATA) {
			*dpcheng = new PnlWzskLlvTermZuvsp::DpchEngData();
			((PnlWzskLlvTermZuvsp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVADMINDATA) {
			*dpcheng = new PnlWzskNavAdmin::DpchEngData();
			((PnlWzskNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVDATA) {
			*dpcheng = new CrdWzskNav::DpchEngData();
			((CrdWzskNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVHEADBARDATA) {
			*dpcheng = new PnlWzskNavHeadbar::DpchEngData();
			((PnlWzskNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVOPDATA) {
			*dpcheng = new PnlWzskNavOp::DpchEngData();
			((PnlWzskNavOp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFACQCORNERDATA) {
			*dpcheng = new PnlWzskPrfAcqCorner::DpchEngData();
			((PnlWzskPrfAcqCorner::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFACQPREVIEWDATA) {
			*dpcheng = new PnlWzskPrfAcqPreview::DpchEngData();
			((PnlWzskPrfAcqPreview::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFACQTRACEDATA) {
			*dpcheng = new PnlWzskPrfAcqTrace::DpchEngData();
			((PnlWzskPrfAcqTrace::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFACTLASERDATA) {
			*dpcheng = new PnlWzskPrfActLaser::DpchEngData();
			((PnlWzskPrfActLaser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFACTVISTOROTDATA) {
			*dpcheng = new PnlWzskPrfActVistorot::DpchEngData();
			((PnlWzskPrfActVistorot::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFDAEMONDATA) {
			*dpcheng = new PnlWzskPrfDaemon::DpchEngData();
			((PnlWzskPrfDaemon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFDATA) {
			*dpcheng = new CrdWzskPrf::DpchEngData();
			((CrdWzskPrf::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFGLOBALDATA) {
			*dpcheng = new PnlWzskPrfGlobal::DpchEngData();
			((PnlWzskPrfGlobal::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFHEADBARDATA) {
			*dpcheng = new PnlWzskPrfHeadbar::DpchEngData();
			((PnlWzskPrfHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFSRCDCVSPDATA) {
			*dpcheng = new PnlWzskPrfSrcDcvsp::DpchEngData();
			((PnlWzskPrfSrcDcvsp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFSRCSYSINFODATA) {
			*dpcheng = new PnlWzskPrfSrcSysinfo::DpchEngData();
			((PnlWzskPrfSrcSysinfo::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFSRCTIVSPDATA) {
			*dpcheng = new PnlWzskPrfSrcTivsp::DpchEngData();
			((PnlWzskPrfSrcTivsp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRFSRCZUVSPDATA) {
			*dpcheng = new PnlWzskPrfSrcZuvsp::DpchEngData();
			((PnlWzskPrfSrcZuvsp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRSADETAILDATA) {
			*dpcheng = new PnlWzskPrsADetail::DpchEngData();
			((PnlWzskPrsADetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRSDATA) {
			*dpcheng = new CrdWzskPrs::DpchEngData();
			((CrdWzskPrs::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRSDETAILDATA) {
			*dpcheng = new PnlWzskPrsDetail::DpchEngData();
			((PnlWzskPrsDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRSHEADBARDATA) {
			*dpcheng = new PnlWzskPrsHeadbar::DpchEngData();
			((PnlWzskPrsHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRSLISTDATA) {
			*dpcheng = new PnlWzskPrsList::DpchEngData();
			((PnlWzskPrsList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKPRSRECDATA) {
			*dpcheng = new PnlWzskPrsRec::DpchEngData();
			((PnlWzskPrsRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSUSPEND) {
			*dpcheng = new DpchEngWzskSuspend();
			((DpchEngWzskSuspend*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGAACCESSDATA) {
			*dpcheng = new PnlWzskUsgAAccess::DpchEngData();
			((PnlWzskUsgAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGDATA) {
			*dpcheng = new CrdWzskUsg::DpchEngData();
			((CrdWzskUsg::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGDETAILDATA) {
			*dpcheng = new PnlWzskUsgDetail::DpchEngData();
			((PnlWzskUsgDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGHEADBARDATA) {
			*dpcheng = new PnlWzskUsgHeadbar::DpchEngData();
			((PnlWzskUsgHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGLISTDATA) {
			*dpcheng = new PnlWzskUsgList::DpchEngData();
			((PnlWzskUsgList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGMNUSERDATA) {
			*dpcheng = new PnlWzskUsgMNUser::DpchEngData();
			((PnlWzskUsgMNUser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSGRECDATA) {
			*dpcheng = new PnlWzskUsgRec::DpchEngData();
			((PnlWzskUsgRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSR1NSESSIONDATA) {
			*dpcheng = new PnlWzskUsr1NSession::DpchEngData();
			((PnlWzskUsr1NSession::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRAACCESSDATA) {
			*dpcheng = new PnlWzskUsrAAccess::DpchEngData();
			((PnlWzskUsrAAccess::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRDATA) {
			*dpcheng = new CrdWzskUsr::DpchEngData();
			((CrdWzskUsr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRDETAILDATA) {
			*dpcheng = new PnlWzskUsrDetail::DpchEngData();
			((PnlWzskUsrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRHEADBARDATA) {
			*dpcheng = new PnlWzskUsrHeadbar::DpchEngData();
			((PnlWzskUsrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRLISTDATA) {
			*dpcheng = new PnlWzskUsrList::DpchEngData();
			((PnlWzskUsrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRMNUSERGROUPDATA) {
			*dpcheng = new PnlWzskUsrMNUsergroup::DpchEngData();
			((PnlWzskUsrMNUsergroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKUSRRECDATA) {
			*dpcheng = new PnlWzskUsrRec::DpchEngData();
			((PnlWzskUsrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRCONFIGALIGN) {
			*dpcheng = new PnlWzskVtrConfig::DpchEngAlign();
			((PnlWzskVtrConfig::DpchEngAlign*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRCONFIGDATA) {
			*dpcheng = new PnlWzskVtrConfig::DpchEngData();
			((PnlWzskVtrConfig::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRCONFIGLIVE) {
			*dpcheng = new PnlWzskVtrConfig::DpchEngLive();
			((PnlWzskVtrConfig::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRDATA) {
			*dpcheng = new CrdWzskVtr::DpchEngData();
			((CrdWzskVtr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRDEBUGDATA) {
			*dpcheng = new PnlWzskVtrDebug::DpchEngData();
			((PnlWzskVtrDebug::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRHEADBARDATA) {
			*dpcheng = new PnlWzskVtrHeadbar::DpchEngData();
			((PnlWzskVtrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRMONITORDATA) {
			*dpcheng = new PnlWzskVtrMonitor::DpchEngData();
			((PnlWzskVtrMonitor::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKVTRMONITORLIVE) {
			*dpcheng = new PnlWzskVtrMonitor::DpchEngLive();
			((PnlWzskVtrMonitor::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		};
	} catch (SbeException& e) {
	};

	if (docctx) xmlXPathFreeContext(docctx);
	if (doc) xmlFreeDoc(doc);
	
	return ixWzskVDpch;
};

void ApiWzsk::writeDpchApp(
			DpchAppWzsk* dpchapp
			, char** buf
			, unsigned long& buflen
			, unsigned long ofs
		) {
	xmlBuffer* xbuf = NULL;
	xmlTextWriter* wr = NULL;

	startwriteBuffer(&wr, &xbuf);
		dpchapp->writeXML(wr);
	closewriteBuffer(wr);

	buflen = xbuf->use + ofs;
	*buf = new char[buflen];
	memcpy(&((*buf)[ofs]), xbuf->content, buflen-ofs);

	xmlBufferFree(xbuf);
};
