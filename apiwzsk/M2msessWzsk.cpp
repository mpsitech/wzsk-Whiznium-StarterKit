/**
	* \file M2msessWzsk.cpp
	* API code for job M2msessWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#include "M2msessWzsk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class M2msessWzsk::StatShr
 ******************************************************************************/

M2msessWzsk::StatShr::StatShr(
			const string& scrJrefAcqcorner
			, const string& scrJrefAcqtrace
			, const string& scrJrefActlaser
			, const string& scrJrefActrotary
			, const string& scrJrefSrcfpgainfo
			, const string& scrJrefSrcsysinfo
		) :
			Block()
			, scrJrefAcqcorner(scrJrefAcqcorner)
			, scrJrefAcqtrace(scrJrefAcqtrace)
			, scrJrefActlaser(scrJrefActlaser)
			, scrJrefActrotary(scrJrefActrotary)
			, scrJrefSrcfpgainfo(scrJrefSrcfpgainfo)
			, scrJrefSrcsysinfo(scrJrefSrcsysinfo)
		{
	mask = {SCRJREFACQCORNER, SCRJREFACQTRACE, SCRJREFACTLASER, SCRJREFACTROTARY, SCRJREFSRCFPGAINFO, SCRJREFSRCSYSINFO};
};

bool M2msessWzsk::StatShr::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StatShrM2msessWzsk");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StatitemShrM2msessWzsk";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqcorner", scrJrefAcqcorner)) add(SCRJREFACQCORNER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefAcqtrace", scrJrefAcqtrace)) add(SCRJREFACQTRACE);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActlaser", scrJrefActlaser)) add(SCRJREFACTLASER);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefActrotary", scrJrefActrotary)) add(SCRJREFACTROTARY);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcfpgainfo", scrJrefSrcfpgainfo)) add(SCRJREFSRCFPGAINFO);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "scrJrefSrcsysinfo", scrJrefSrcsysinfo)) add(SCRJREFSRCSYSINFO);
	};

	return basefound;
};

set<uint> M2msessWzsk::StatShr::comm(
			const StatShr* comp
		) {
	set<uint> items;

	if (scrJrefAcqcorner == comp->scrJrefAcqcorner) insert(items, SCRJREFACQCORNER);
	if (scrJrefAcqtrace == comp->scrJrefAcqtrace) insert(items, SCRJREFACQTRACE);
	if (scrJrefActlaser == comp->scrJrefActlaser) insert(items, SCRJREFACTLASER);
	if (scrJrefActrotary == comp->scrJrefActrotary) insert(items, SCRJREFACTROTARY);
	if (scrJrefSrcfpgainfo == comp->scrJrefSrcfpgainfo) insert(items, SCRJREFSRCFPGAINFO);
	if (scrJrefSrcsysinfo == comp->scrJrefSrcsysinfo) insert(items, SCRJREFSRCSYSINFO);

	return(items);
};

set<uint> M2msessWzsk::StatShr::diff(
			const StatShr* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SCRJREFACQCORNER, SCRJREFACQTRACE, SCRJREFACTLASER, SCRJREFACTROTARY, SCRJREFSRCFPGAINFO, SCRJREFSRCSYSINFO};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

/******************************************************************************
 class M2msessWzsk::DpchEngData
 ******************************************************************************/

M2msessWzsk::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGM2MSESSWZSKDATA)
		{
};

string M2msessWzsk::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(STATSHR)) ss.push_back("statshr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void M2msessWzsk::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngM2msessWzskData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (statshr.readXML(docctx, basexpath, true)) add(STATSHR);
	} else {
		statshr = StatShr();
	};
};
