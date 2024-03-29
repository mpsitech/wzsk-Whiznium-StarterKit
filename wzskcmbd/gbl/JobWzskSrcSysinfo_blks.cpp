/**
	* \file JobWzskSrcSysinfo_blks.cpp
	* job handler for job JobWzskSrcSysinfo (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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

	if (s == "currch0voltch0") return CURRCH0VOLTCH0;
	if (s == "currch1voltch1") return CURRCH1VOLTCH1;
	if (s == "currch2voltch2") return CURRCH2VOLTCH2;
	if (s == "currch3voltch3") return CURRCH3VOLTCH3;
	if (s == "loadallloadcore0loadcore1loadcore2loadcore3") return LOADALLLOADCORE0LOADCORE1LOADCORE2LOADCORE3;
	if (s == "temp") return TEMP;

	return(0);
};

string JobWzskSrcSysinfo::VecVVar::getSref(
			const uint ix
		) {
	if (ix == CURRCH0VOLTCH0) return("currCh0VoltCh0");
	if (ix == CURRCH1VOLTCH1) return("currCh1VoltCh1");
	if (ix == CURRCH2VOLTCH2) return("currCh2VoltCh2");
	if (ix == CURRCH3VOLTCH3) return("currCh3VoltCh3");
	if (ix == LOADALLLOADCORE0LOADCORE1LOADCORE2LOADCORE3) return("loadAllLoadCore0LoadCore1LoadCore2LoadCore3");
	if (ix == TEMP) return("temp");

	return("");
};

void JobWzskSrcSysinfo::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcSysinfo::Stg
 ******************************************************************************/

JobWzskSrcSysinfo::Stg::Stg(
			const string& pathrootCurrVolt
			, const string& pathStat
			, const string& pathThermal
			, const string& pathrootXadc
		) :
			Block()
		{
	this->pathrootCurrVolt = pathrootCurrVolt;
	this->pathStat = pathStat;
	this->pathThermal = pathThermal;
	this->pathrootXadc = pathrootXadc;
	mask = {PATHROOTCURRVOLT, PATHSTAT, PATHTHERMAL, PATHROOTXADC};
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
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathrootCurrVolt", pathrootCurrVolt)) add(PATHROOTCURRVOLT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathStat", pathStat)) add(PATHSTAT);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathThermal", pathThermal)) add(PATHTHERMAL);
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathrootXadc", pathrootXadc)) add(PATHROOTXADC);
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
		writeStringAttr(wr, itemtag, "sref", "pathrootCurrVolt", pathrootCurrVolt);
		writeStringAttr(wr, itemtag, "sref", "pathStat", pathStat);
		writeStringAttr(wr, itemtag, "sref", "pathThermal", pathThermal);
		writeStringAttr(wr, itemtag, "sref", "pathrootXadc", pathrootXadc);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskSrcSysinfo::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (pathrootCurrVolt == comp->pathrootCurrVolt) insert(items, PATHROOTCURRVOLT);
	if (pathStat == comp->pathStat) insert(items, PATHSTAT);
	if (pathThermal == comp->pathThermal) insert(items, PATHTHERMAL);
	if (pathrootXadc == comp->pathrootXadc) insert(items, PATHROOTXADC);

	return(items);
};

set<uint> JobWzskSrcSysinfo::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATHROOTCURRVOLT, PATHSTAT, PATHTHERMAL, PATHROOTXADC};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
