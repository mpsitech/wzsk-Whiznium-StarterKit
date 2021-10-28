/**
	* \file ApiWzsk.cpp
	* Wzsk API library global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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
		{
	this->engip = engip;
	this->engport = engport;
	this->username = username;
	this->password = password;

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
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKOBJNEWDATA) {
			*dpcheng = new DlgWzskObjNew::DpchEngData();
			((DlgWzskObjNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKOGRNEWDATA) {
			*dpcheng = new DlgWzskOgrNew::DpchEngData();
			((DlgWzskOgrNew::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKSCFCAMERAMATDATA) {
			*dpcheng = new DlgWzskScfCameramat::DpchEngData();
			((DlgWzskScfCameramat::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKSCFLASERPOSDATA) {
			*dpcheng = new DlgWzskScfLaserpos::DpchEngData();
			((DlgWzskScfLaserpos::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGDLGWZSKSCFTTABLECOORDDATA) {
			*dpcheng = new DlgWzskScfTtablecoord::DpchEngData();
			((DlgWzskScfTtablecoord::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
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
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIV2DVIEWALIGN) {
			*dpcheng = new PnlWzskLiv2DView::DpchEngAlign();
			((PnlWzskLiv2DView::DpchEngAlign*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIV2DVIEWDATA) {
			*dpcheng = new PnlWzskLiv2DView::DpchEngData();
			((PnlWzskLiv2DView::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIV2DVIEWLIVE) {
			*dpcheng = new PnlWzskLiv2DView::DpchEngLive();
			((PnlWzskLiv2DView::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIV3DVIEWDATA) {
			*dpcheng = new PnlWzskLiv3DView::DpchEngData();
			((PnlWzskLiv3DView::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIV3DVIEWLIVE) {
			*dpcheng = new PnlWzskLiv3DView::DpchEngLive();
			((PnlWzskLiv3DView::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIVDATA) {
			*dpcheng = new CrdWzskLiv::DpchEngData();
			((CrdWzskLiv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIVHEADBARDATA) {
			*dpcheng = new PnlWzskLivHeadbar::DpchEngData();
			((PnlWzskLivHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIVSYSMONDATA) {
			*dpcheng = new PnlWzskLivSysmon::DpchEngData();
			((PnlWzskLivSysmon::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLIVSYSMONLIVE) {
			*dpcheng = new PnlWzskLivSysmon::DpchEngLive();
			((PnlWzskLivSysmon::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVCAMERADATA) {
			*dpcheng = new PnlWzskLlvCamera::DpchEngData();
			((PnlWzskLlvCamera::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVCAMERALIVE) {
			*dpcheng = new PnlWzskLlvCamera::DpchEngLive();
			((PnlWzskLlvCamera::DpchEngLive*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVDATA) {
			*dpcheng = new CrdWzskLlv::DpchEngData();
			((CrdWzskLlv::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVHEADBARDATA) {
			*dpcheng = new PnlWzskLlvHeadbar::DpchEngData();
			((PnlWzskLlvHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVLASERDATA) {
			*dpcheng = new PnlWzskLlvLaser::DpchEngData();
			((PnlWzskLlvLaser::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMARTYDATA) {
			*dpcheng = new PnlWzskLlvTermArty::DpchEngData();
			((PnlWzskLlvTermArty::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMCLNXEVBDATA) {
			*dpcheng = new PnlWzskLlvTermClnxevb::DpchEngData();
			((PnlWzskLlvTermClnxevb::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMICICLEDATA) {
			*dpcheng = new PnlWzskLlvTermIcicle::DpchEngData();
			((PnlWzskLlvTermIcicle::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMMCVEVPDATA) {
			*dpcheng = new PnlWzskLlvTermMcvevp::DpchEngData();
			((PnlWzskLlvTermMcvevp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTERMUVBDVKDATA) {
			*dpcheng = new PnlWzskLlvTermUvbdvk::DpchEngData();
			((PnlWzskLlvTermUvbdvk::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKLLVTTABLEDATA) {
			*dpcheng = new PnlWzskLlvTtable::DpchEngData();
			((PnlWzskLlvTtable::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVADMINDATA) {
			*dpcheng = new PnlWzskNavAdmin::DpchEngData();
			((PnlWzskNavAdmin::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVDATA) {
			*dpcheng = new CrdWzskNav::DpchEngData();
			((CrdWzskNav::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVGLRYDATA) {
			*dpcheng = new PnlWzskNavGlry::DpchEngData();
			((PnlWzskNavGlry::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVHEADBARDATA) {
			*dpcheng = new PnlWzskNavHeadbar::DpchEngData();
			((PnlWzskNavHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVOPDATA) {
			*dpcheng = new PnlWzskNavOp::DpchEngData();
			((PnlWzskNavOp::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKNAVPREDATA) {
			*dpcheng = new PnlWzskNavPre::DpchEngData();
			((PnlWzskNavPre::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJ1NSHOTDATA) {
			*dpcheng = new PnlWzskObj1NShot::DpchEngData();
			((PnlWzskObj1NShot::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJDATA) {
			*dpcheng = new CrdWzskObj::DpchEngData();
			((CrdWzskObj::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJDETAILDATA) {
			*dpcheng = new PnlWzskObjDetail::DpchEngData();
			((PnlWzskObjDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJHEADBARDATA) {
			*dpcheng = new PnlWzskObjHeadbar::DpchEngData();
			((PnlWzskObjHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJLISTDATA) {
			*dpcheng = new PnlWzskObjList::DpchEngData();
			((PnlWzskObjList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJRECDATA) {
			*dpcheng = new PnlWzskObjRec::DpchEngData();
			((PnlWzskObjRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOBJREF1NFILEDATA) {
			*dpcheng = new PnlWzskObjRef1NFile::DpchEngData();
			((PnlWzskObjRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGR1NOBJECTDATA) {
			*dpcheng = new PnlWzskOgr1NObject::DpchEngData();
			((PnlWzskOgr1NObject::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGRDATA) {
			*dpcheng = new CrdWzskOgr::DpchEngData();
			((CrdWzskOgr::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGRDETAILDATA) {
			*dpcheng = new PnlWzskOgrDetail::DpchEngData();
			((PnlWzskOgrDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGRHEADBARDATA) {
			*dpcheng = new PnlWzskOgrHeadbar::DpchEngData();
			((PnlWzskOgrHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGRLISTDATA) {
			*dpcheng = new PnlWzskOgrList::DpchEngData();
			((PnlWzskOgrList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGRRECDATA) {
			*dpcheng = new PnlWzskOgrRec::DpchEngData();
			((PnlWzskOgrRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKOGRSUP1NOBJGROUPDATA) {
			*dpcheng = new PnlWzskOgrSup1NObjgroup::DpchEngData();
			((PnlWzskOgrSup1NObjgroup::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
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
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSCFCONNDATA) {
			*dpcheng = new PnlWzskScfConn::DpchEngData();
			((PnlWzskScfConn::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSCFDATA) {
			*dpcheng = new CrdWzskScf::DpchEngData();
			((CrdWzskScf::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSCFGEOMDATA) {
			*dpcheng = new PnlWzskScfGeom::DpchEngData();
			((PnlWzskScfGeom::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSCFHEADBARDATA) {
			*dpcheng = new PnlWzskScfHeadbar::DpchEngData();
			((PnlWzskScfHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSES1NSHOTDATA) {
			*dpcheng = new PnlWzskSes1NShot::DpchEngData();
			((PnlWzskSes1NShot::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSESDATA) {
			*dpcheng = new CrdWzskSes::DpchEngData();
			((CrdWzskSes::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSESDETAILDATA) {
			*dpcheng = new PnlWzskSesDetail::DpchEngData();
			((PnlWzskSesDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSESHEADBARDATA) {
			*dpcheng = new PnlWzskSesHeadbar::DpchEngData();
			((PnlWzskSesHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSESLISTDATA) {
			*dpcheng = new PnlWzskSesList::DpchEngData();
			((PnlWzskSesList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSESRECDATA) {
			*dpcheng = new PnlWzskSesRec::DpchEngData();
			((PnlWzskSesRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTAPARDATA) {
			*dpcheng = new PnlWzskShtAPar::DpchEngData();
			((PnlWzskShtAPar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTDATA) {
			*dpcheng = new CrdWzskSht::DpchEngData();
			((CrdWzskSht::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTDETAILDATA) {
			*dpcheng = new PnlWzskShtDetail::DpchEngData();
			((PnlWzskShtDetail::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTHEADBARDATA) {
			*dpcheng = new PnlWzskShtHeadbar::DpchEngData();
			((PnlWzskShtHeadbar::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTLISTDATA) {
			*dpcheng = new PnlWzskShtList::DpchEngData();
			((PnlWzskShtList::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTRECDATA) {
			*dpcheng = new PnlWzskShtRec::DpchEngData();
			((PnlWzskShtRec::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
		} else if (ixWzskVDpch == VecWzskVDpch::DPCHENGWZSKSHTREF1NFILEDATA) {
			*dpcheng = new PnlWzskShtRef1NFile::DpchEngData();
			((PnlWzskShtRef1NFile::DpchEngData*) *dpcheng)->readXML(docctx, "/", true);
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
