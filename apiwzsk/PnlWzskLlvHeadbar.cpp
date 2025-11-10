/**
	* \file PnlWzskLlvHeadbar.cpp
	* API code for job PnlWzskLlvHeadbar (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "PnlWzskLlvHeadbar.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class PnlWzskLlvHeadbar::StgInf
 ******************************************************************************/

PnlWzskLlvHeadbar::StgInf::StgInf(
			const uint MenAppCptwidth
			, const uint MenAppWidth
		) :
			Block()
			, MenAppCptwidth(MenAppCptwidth)
			, MenAppWidth(MenAppWidth)
		{
	mask = {MENAPPCPTWIDTH, MENAPPWIDTH};
};

bool PnlWzskLlvHeadbar::StgInf::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgInfWzskLlvHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemInfWzskLlvHeadbar";

	if (basefound) {
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppCptwidth", MenAppCptwidth)) add(MENAPPCPTWIDTH);
		if (extractUintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "MenAppWidth", MenAppWidth)) add(MENAPPWIDTH);
	};

	return basefound;
};

set<uint> PnlWzskLlvHeadbar::StgInf::comm(
			const StgInf* comp
		) {
	set<uint> items;

	if (MenAppCptwidth == comp->MenAppCptwidth) insert(items, MENAPPCPTWIDTH);
	if (MenAppWidth == comp->MenAppWidth) insert(items, MENAPPWIDTH);

	return(items);
};

set<uint> PnlWzskLlvHeadbar::StgInf::diff(
			const StgInf* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {MENAPPCPTWIDTH, MENAPPWIDTH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class PnlWzskLlvHeadbar::Tag
 ******************************************************************************/

PnlWzskLlvHeadbar::Tag::Tag(
			const string& MenApp
		) :
			Block()
			, MenApp(MenApp)
		{
	mask = {MENAPP};
};

bool PnlWzskLlvHeadbar::Tag::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "TagWzskLlvHeadbar");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "TagitemWzskLlvHeadbar";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Ti", "sref", "MenApp", MenApp)) add(MENAPP);
	};

	return basefound;
};

/******************************************************************************
 class PnlWzskLlvHeadbar::DpchEngData
 ******************************************************************************/

PnlWzskLlvHeadbar::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGWZSKLLVHEADBARDATA)
		{
};

string PnlWzskLlvHeadbar::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STGINF)) ss.push_back("stginf");
	if (has(TAG)) ss.push_back("tag");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void PnlWzskLlvHeadbar::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngWzskLlvHeadbarData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (stginf.readXML(docctx, basexpath, true)) add(STGINF);
		if (tag.readXML(docctx, basexpath, true)) add(TAG);
	} else {
		stginf = StgInf();
		tag = Tag();
	};
};
