/**
	* \file PnlWzskNavHeadbar.cpp
	* API code for job PnlWzskNavHeadbar (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "PnlWzskNavHeadbar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskNavHeadbar::StatShr
 ******************************************************************************/

PnlWzskNavHeadbar::StatShr::StatShr(
			const bool MenCrdAvail
		) :
			Block()
		{
	this->MenCrdAvail = MenCrdAvail;

	mask = {MENCRDAVAIL};
};

bool PnlWzskNavHeadbar::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrWzskNavHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrWzskNavHeadbar";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdAvail", MenCrdAvail)) add(MENCRDAVAIL);
	};

	return basefound;
};

set<uint> PnlWzskNavHeadbar::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (MenCrdAvail == comp->MenCrdAvail) insert(items, MENCRDAVAIL);

	return(items);
};

set<uint> PnlWzskNavHeadbar::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENCRDAVAIL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavHeadbar::StgInf
 ******************************************************************************/

PnlWzskNavHeadbar::StgInf::StgInf(
			const uint MenAppCptwidth
			, const uint MenAppWidth
			, const uint MenSesCptwidth
			, const uint MenSesWidth
			, const uint MenCrdCptwidth
			, const uint MenCrdWidth
		) :
			Block()
		{
	this->MenAppCptwidth = MenAppCptwidth;
	this->MenAppWidth = MenAppWidth;
	this->MenSesCptwidth = MenSesCptwidth;
	this->MenSesWidth = MenSesWidth;
	this->MenCrdCptwidth = MenCrdCptwidth;
	this->MenCrdWidth = MenCrdWidth;

	mask = {MENAPPCPTWIDTH, MENAPPWIDTH, MENSESCPTWIDTH, MENSESWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
};

bool PnlWzskNavHeadbar::StgInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgInfWzskNavHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemInfWzskNavHeadbar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", MenAppCptwidth)) add(MENAPPCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppWidth", MenAppWidth)) add(MENAPPWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenSesCptwidth", MenSesCptwidth)) add(MENSESCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenSesWidth", MenSesWidth)) add(MENSESWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdCptwidth", MenCrdCptwidth)) add(MENCRDCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenCrdWidth", MenCrdWidth)) add(MENCRDWIDTH);
	};

	return basefound;
};

set<uint> PnlWzskNavHeadbar::StgInf::comm(
			const StgInf* comp
		) {
	set<uint> items;

	if (MenAppCptwidth == comp->MenAppCptwidth) insert(items, MENAPPCPTWIDTH);
	if (MenAppWidth == comp->MenAppWidth) insert(items, MENAPPWIDTH);
	if (MenSesCptwidth == comp->MenSesCptwidth) insert(items, MENSESCPTWIDTH);
	if (MenSesWidth == comp->MenSesWidth) insert(items, MENSESWIDTH);
	if (MenCrdCptwidth == comp->MenCrdCptwidth) insert(items, MENCRDCPTWIDTH);
	if (MenCrdWidth == comp->MenCrdWidth) insert(items, MENCRDWIDTH);

	return(items);
};

set<uint> PnlWzskNavHeadbar::StgInf::diff(
			const StgInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENAPPCPTWIDTH, MENAPPWIDTH, MENSESCPTWIDTH, MENSESWIDTH, MENCRDCPTWIDTH, MENCRDWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskNavHeadbar::Tag
 ******************************************************************************/

PnlWzskNavHeadbar::Tag::Tag(
			const string& MenApp
			, const string& MenSes
			, const string& MenCrd
		) :
			Block()
		{
	this->MenApp = MenApp;
	this->MenSes = MenSes;
	this->MenCrd = MenCrd;

	mask = {MENAPP, MENSES, MENCRD};
};

bool PnlWzskNavHeadbar::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskNavHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskNavHeadbar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenApp", MenApp)) add(MENAPP);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenSes", MenSes)) add(MENSES);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenCrd", MenCrd)) add(MENCRD);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskNavHeadbar::DpchEngData
 ******************************************************************************/

PnlWzskNavHeadbar::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKNAVHEADBARDATA)
		{
};

string PnlWzskNavHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATSHR)) ss.push_back("statshr");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskNavHeadbar::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskNavHeadbarData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
		if (stginf.readXML(docctx, basexpath, true)) add(STGINF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		statshr = StatShr();
		stginf = StgInf();
		tag = Tag();
	};
};

