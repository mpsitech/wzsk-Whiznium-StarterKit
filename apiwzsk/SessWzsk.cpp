/**
	* \file SessWzsk.cpp
	* API code for job SessWzsk (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "SessWzsk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class SessWzsk::StatShr
 ******************************************************************************/

SessWzsk::StatShr::StatShr(
			const string& scrJrefCrdnav
		) :
			Block()
		{
	this->scrJrefCrdnav = scrJrefCrdnav;

	mask = {SCRJREFCRDNAV};
};

bool SessWzsk::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrSessWzsk");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrSessWzsk";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefCrdnav", scrJrefCrdnav)) add(SCRJREFCRDNAV);
	};

	return basefound;
};

set<uint> SessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefCrdnav == comp->scrJrefCrdnav) insert(items, SCRJREFCRDNAV);

	return(items);
};

set<uint> SessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFCRDNAV};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class SessWzsk::DpchEngData
 ******************************************************************************/

SessWzsk::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGSESSWZSKDATA)
		{
	feedFEnsSec.tag = "FeedFEnsSec";
};

string SessWzsk::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSEC)) ss.push_back("feedFEnsSec");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void SessWzsk::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngSessWzskData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSec.readXML(docctx, basexpath, true)) add(FEEDFENSSEC);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		feedFEnsSec.clear();
		statshr = StatShr();
	};
};

