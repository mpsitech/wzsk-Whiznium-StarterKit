/**
	* \file PnlWzskUsrRec.cpp
	* API code for job PnlWzskUsrRec (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "PnlWzskUsrRec.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskUsrRec::VecVDo
 ******************************************************************************/

uint PnlWzskUsrRec::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butminimizeclick") return BUTMINIMIZECLICK;
	if (s == "butregularizeclick") return BUTREGULARIZECLICK;

	return(0);
};

string PnlWzskUsrRec::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTMINIMIZECLICK) return("ButMinimizeClick");
	if (ix == BUTREGULARIZECLICK) return("ButRegularizeClick");

	return("");
};

/******************************************************************************
 class PnlWzskUsrRec::ContInf
 ******************************************************************************/

PnlWzskUsrRec::ContInf::ContInf(
			const string& TxtRef
		) :
			Block()
		{
	this->TxtRef = TxtRef;

	mask = {TXTREF};
};

bool PnlWzskUsrRec::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskUsrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskUsrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtRef", TxtRef)) add(TXTREF);
	};

	return basefound;
};

set<uint> PnlWzskUsrRec::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtRef == comp->TxtRef) insert(items, TXTREF);

	return(items);
};

set<uint> PnlWzskUsrRec::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTREF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskUsrRec::StatApp
 ******************************************************************************/

PnlWzskUsrRec::StatApp::StatApp(
			const bool initdoneDetail
			, const bool initdoneAAccess
			, const bool initdone1NSession
			, const bool initdoneMNUsergroup
		) :
			Block()
		{
	this->initdoneDetail = initdoneDetail;
	this->initdoneAAccess = initdoneAAccess;
	this->initdone1NSession = initdone1NSession;
	this->initdoneMNUsergroup = initdoneMNUsergroup;

	mask = {INITDONEDETAIL, INITDONEAACCESS, INITDONE1NSESSION, INITDONEMNUSERGROUP};
};

bool PnlWzskUsrRec::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskUsrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskUsrRec";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneDetail", initdoneDetail)) add(INITDONEDETAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneAAccess", initdoneAAccess)) add(INITDONEAACCESS);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdone1NSession", initdone1NSession)) add(INITDONE1NSESSION);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "initdoneMNUsergroup", initdoneMNUsergroup)) add(INITDONEMNUSERGROUP);
	};

	return basefound;
};

set<uint> PnlWzskUsrRec::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (initdoneDetail == comp->initdoneDetail) insert(items, INITDONEDETAIL);
	if (initdoneAAccess == comp->initdoneAAccess) insert(items, INITDONEAACCESS);
	if (initdone1NSession == comp->initdone1NSession) insert(items, INITDONE1NSESSION);
	if (initdoneMNUsergroup == comp->initdoneMNUsergroup) insert(items, INITDONEMNUSERGROUP);

	return(items);
};

set<uint> PnlWzskUsrRec::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {INITDONEDETAIL, INITDONEAACCESS, INITDONE1NSESSION, INITDONEMNUSERGROUP};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskUsrRec::StatShr
 ******************************************************************************/

PnlWzskUsrRec::StatShr::StatShr(
			const uint ixWzskVExpstate
			, const string& scrJrefDetail
			, const string& scrJrefAAccess
			, const string& scrJref1NSession
			, const string& scrJrefMNUsergroup
			, const bool ButRegularizeActive
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;
	this->scrJrefDetail = scrJrefDetail;
	this->scrJrefAAccess = scrJrefAAccess;
	this->scrJref1NSession = scrJref1NSession;
	this->scrJrefMNUsergroup = scrJrefMNUsergroup;
	this->ButRegularizeActive = ButRegularizeActive;

	mask = {IXWZSKVEXPSTATE, SCRJREFDETAIL, SCRJREFAACCESS, SCRJREF1NSESSION, SCRJREFMNUSERGROUP, BUTREGULARIZEACTIVE};
};

bool PnlWzskUsrRec::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskUsrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskUsrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefDetail", scrJrefDetail)) add(SCRJREFDETAIL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAAccess", scrJrefAAccess)) add(SCRJREFAACCESS);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJref1NSession", scrJref1NSession)) add(SCRJREF1NSESSION);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefMNUsergroup", scrJrefMNUsergroup)) add(SCRJREFMNUSERGROUP);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButRegularizeActive", ButRegularizeActive)) add(BUTREGULARIZEACTIVE);
	};

	return basefound;
};

set<uint> PnlWzskUsrRec::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);
	if (scrJrefDetail == comp->scrJrefDetail) insert(items, SCRJREFDETAIL);
	if (scrJrefAAccess == comp->scrJrefAAccess) insert(items, SCRJREFAACCESS);
	if (scrJref1NSession == comp->scrJref1NSession) insert(items, SCRJREF1NSESSION);
	if (scrJrefMNUsergroup == comp->scrJrefMNUsergroup) insert(items, SCRJREFMNUSERGROUP);
	if (ButRegularizeActive == comp->ButRegularizeActive) insert(items, BUTREGULARIZEACTIVE);

	return(items);
};

set<uint> PnlWzskUsrRec::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE, SCRJREFDETAIL, SCRJREFAACCESS, SCRJREF1NSESSION, SCRJREFMNUSERGROUP, BUTREGULARIZEACTIVE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskUsrRec::Tag
 ******************************************************************************/

PnlWzskUsrRec::Tag::Tag(
			const string& Cpt
		) :
			Block()
		{
	this->Cpt = Cpt;

	mask = {CPT};
};

bool PnlWzskUsrRec::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskUsrRec");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskUsrRec";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskUsrRec::DpchAppDo
 ******************************************************************************/

PnlWzskUsrRec::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKUSRRECDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskUsrRec::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskUsrRec::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskUsrRecDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskUsrRec::DpchEngData
 ******************************************************************************/

PnlWzskUsrRec::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKUSRRECDATA)
		{
};

string PnlWzskUsrRec::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskUsrRec::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskUsrRecData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

