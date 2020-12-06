/**
	* \file PnlWzskNavPre.cpp
	* API code for job PnlWzskNavPre (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "PnlWzskNavPre.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavPre::VecVDo
 ******************************************************************************/

uint PnlWzskNavPre::VecVDo::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "butobjremoveclick") return BUTOBJREMOVECLICK;

	return(0);
};

string PnlWzskNavPre::VecVDo::getSref(
			const uint ix
		) {
	if (ix == BUTOBJREMOVECLICK) return("ButObjRemoveClick");

	return("");
};

/******************************************************************************
 class PnlWzskNavPre::ContInf
 ******************************************************************************/

PnlWzskNavPre::ContInf::ContInf(
			const string& TxtObj
		) :
			Block()
		{
	this->TxtObj = TxtObj;

	mask = {TXTOBJ};
};

bool PnlWzskNavPre::ContInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ContInfWzskNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "ContitemInfWzskNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ci", "sref", "TxtObj", TxtObj)) add(TXTOBJ);
	};

	return basefound;
};

set<uint> PnlWzskNavPre::ContInf::comm(
			const ContInf* comp
		) {
	set<uint> items;

	if (TxtObj == comp->TxtObj) insert(items, TXTOBJ);

	return(items);
};

set<uint> PnlWzskNavPre::ContInf::diff(
			const ContInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTOBJ};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavPre::StatShr
 ******************************************************************************/

PnlWzskNavPre::StatShr::StatShr(
			const bool TxtObjAvail
		) :
			Block()
		{
	this->TxtObjAvail = TxtObjAvail;

	mask = {TXTOBJAVAIL};
};

bool PnlWzskNavPre::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskNavPre";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "TxtObjAvail", TxtObjAvail)) add(TXTOBJAVAIL);
	};

	return basefound;
};

set<uint> PnlWzskNavPre::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (TxtObjAvail == comp->TxtObjAvail) insert(items, TXTOBJAVAIL);

	return(items);
};

set<uint> PnlWzskNavPre::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {TXTOBJAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavPre::Tag
 ******************************************************************************/

PnlWzskNavPre::Tag::Tag(
			const string& CptObj
		) :
			Block()
		{
	this->CptObj = CptObj;

	mask = {CPTOBJ};
};

bool PnlWzskNavPre::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskNavPre");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskNavPre";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "CptObj", CptObj)) add(CPTOBJ);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskNavPre::DpchAppDo
 ******************************************************************************/

PnlWzskNavPre::DpchAppDo::DpchAppDo(
			const string& scrJref
			, const uint ixVDo
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPWZSKNAVPREDO, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, IXVDO};
	else this->mask = mask;

	this->ixVDo = ixVDo;
};

string PnlWzskNavPre::DpchAppDo::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(IXVDO)) ss.push_back("ixVDo");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavPre::DpchAppDo::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppWzskNavPreDo");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(IXVDO)) writeString(wr, "srefIxVDo", VecVDo::getSref(ixVDo));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class PnlWzskNavPre::DpchEngData
 ******************************************************************************/

PnlWzskNavPre::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVPREDATA)
		{
};

string PnlWzskNavPre::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(CONTINF)) ss.push_back("continf");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavPre::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskNavPreData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (continf.readXML(docctx, basexpath, true)) add(CONTINF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		continf = ContInf();
		statshr = StatShr();
		tag = Tag();
	};
};
