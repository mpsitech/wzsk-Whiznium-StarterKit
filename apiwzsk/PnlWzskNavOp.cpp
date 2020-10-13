/**
	* \file PnlWzskNavOp.cpp
	* API code for job PnlWzskNavOp (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "PnlWzskNavOp.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavOp::VecVDo
 ******************************************************************************/

uint PnlWzskNavOp::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butllvnewcrdclick") return BUTLLVNEWCRDCLICK;
	if (s == "butlivnewcrdclick") return BUTLIVNEWCRDCLICK;

	return(0);
};

string PnlWzskNavOp::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTLLVNEWCRDCLICK) return("ButLlvNewcrdClick");
	if (ix == BUTLIVNEWCRDCLICK) return("ButLivNewcrdClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavOp::StatApp
 ******************************************************************************/

PnlWzskNavOp::StatApp::StatApp(
			const uint ixWzskVExpstate
		) :
			Block()
		{
	this->ixWzskVExpstate = ixWzskVExpstate;

	mask = {IXWZSKVEXPSTATE};
};

bool PnlWzskNavOp::StatApp::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxWzskVExpstate;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatAppWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemAppWzskNavOp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "srefIxWzskVExpstate", srefIxWzskVExpstate)) {
			ixWzskVExpstate = VecWzskVExpstate::getIx(srefIxWzskVExpstate);
			add(IXWZSKVEXPSTATE);
		};
	};

	return basefound;
};

set<uint> PnlWzskNavOp::StatApp::comm(
			const StatApp* comp
		) {
	set<uint> items;

	if (ixWzskVExpstate == comp->ixWzskVExpstate) insert(items, IXWZSKVEXPSTATE);

	return(items);
};

set<uint> PnlWzskNavOp::StatApp::diff(
			const StatApp* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {IXWZSKVEXPSTATE};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::StatShr
 ******************************************************************************/

PnlWzskNavOp::StatShr::StatShr(
			const bool ButLlvNewcrdAvail
			, const bool ButLivNewcrdAvail
		) :
			Block()
		{
	this->ButLlvNewcrdAvail = ButLlvNewcrdAvail;
	this->ButLivNewcrdAvail = ButLivNewcrdAvail;

	mask = {BUTLLVNEWCRDAVAIL, BUTLIVNEWCRDAVAIL};
};

bool PnlWzskNavOp::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskNavOp";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLlvNewcrdAvail", ButLlvNewcrdAvail)) add(BUTLLVNEWCRDAVAIL);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ButLivNewcrdAvail", ButLivNewcrdAvail)) add(BUTLIVNEWCRDAVAIL);
	};

	return basefound;
};

set<uint> PnlWzskNavOp::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (ButLlvNewcrdAvail == comp->ButLlvNewcrdAvail) insert(items, BUTLLVNEWCRDAVAIL);
	if (ButLivNewcrdAvail == comp->ButLivNewcrdAvail) insert(items, BUTLIVNEWCRDAVAIL);

	return(items);
};

set<uint> PnlWzskNavOp::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {BUTLLVNEWCRDAVAIL, BUTLIVNEWCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavOp::Tag
 ******************************************************************************/

PnlWzskNavOp::Tag::Tag(
			const string& Cpt
			, const string& CptLlv
			, const string& CptLiv
		) :
			Block()
		{
	this->Cpt = Cpt;
	this->CptLlv = CptLlv;
	this->CptLiv = CptLiv;

	mask = {CPT, CPTLLV, CPTLIV};
};

bool PnlWzskNavOp::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskNavOp");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskNavOp";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "Cpt", Cpt)) add(CPT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLlv", CptLlv)) add(CPTLLV);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptLiv", CptLiv)) add(CPTLIV);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskNavOp::DpchAppDo
 ******************************************************************************/

PnlWzskNavOp::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVOPDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskNavOp::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavOpDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavOp::DpchEngData
 ******************************************************************************/

PnlWzskNavOp::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVOPDATA)
		{
};

string PnlWzskNavOp::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATAPP)) ss.push_back("statapp");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavOp::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskNavOpData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statapp.readXML(docctx, basexpath, true)) add(STATAPP);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		statapp = StatApp();
		statshr = StatShr();
		tag = Tag();
	};
};

