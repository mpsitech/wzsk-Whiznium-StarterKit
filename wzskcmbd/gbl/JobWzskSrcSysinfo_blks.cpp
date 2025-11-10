/**
	* \file JobWzskSrcSysinfo_blks.cpp
	* job handler for job JobWzskSrcSysinfo (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskSrcSysinfo::VecVSge
 ******************************************************************************/

uint JobWzskSrcSysinfo::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobWzskSrcSysinfo::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

void JobWzskSrcSysinfo::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcSysinfo::VecVVar
 ******************************************************************************/

uint JobWzskSrcSysinfo::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "loadallloadcore0loadcore1loadcore2loadcore3") return LOADALLLOADCORE0LOADCORE1LOADCORE2LOADCORE3;
	if (s == "temp") return TEMP;

	return(0);
};

string JobWzskSrcSysinfo::VecVVar::getSref(
			const uint ix
		) {
	if (ix == LOADALLLOADCORE0LOADCORE1LOADCORE2LOADCORE3) return("loadAllLoadCore0LoadCore1LoadCore2LoadCore3");
	if (ix == TEMP) return("temp");

	return("");
};

void JobWzskSrcSysinfo::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcSysinfo::Stg
 ******************************************************************************/

JobWzskSrcSysinfo::Stg::Stg(
			const string& pathStat
			, const string& pathrootThermal
		) :
			Block()
			, pathStat(pathStat)
			, pathrootThermal(pathrootThermal)
		{
	mask = {PATHSTAT, PATHROOTTHERMAL};
};

bool JobWzskSrcSysinfo::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskSrcSysinfo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskSrcSysinfo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathStat", pathStat)) add(PATHSTAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathrootThermal", pathrootThermal)) add(PATHROOTTHERMAL);
	};

	return basefound;
};

void JobWzskSrcSysinfo::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskSrcSysinfo";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskSrcSysinfo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "pathStat", pathStat);
		writeStringAttr(wr, itemtag, "sref", "pathrootThermal", pathrootThermal);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskSrcSysinfo::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (pathStat == comp->pathStat) insert(items, PATHSTAT);
	if (pathrootThermal == comp->pathrootThermal) insert(items, PATHROOTTHERMAL);

	return(items);
};

set<uint> JobWzskSrcSysinfo::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATHSTAT, PATHROOTTHERMAL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
