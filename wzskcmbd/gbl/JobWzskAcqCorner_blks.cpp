/**
	* \file JobWzskAcqCorner_blks.cpp
	* job handler for job JobWzskAcqCorner (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqCorner::VecVMethod
 ******************************************************************************/

uint JobWzskAcqCorner::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setroi") return SETROI;

	return(0);
};

string JobWzskAcqCorner::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETROI) return("setRoi");

	return("");
};

void JobWzskAcqCorner::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqCorner::VecVSge
 ******************************************************************************/

uint JobWzskAcqCorner::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "acq") return ACQ;
	if (s == "calcidle") return CALCIDLE;
	if (s == "calc") return CALC;
	if (s == "done") return DONE;

	return(0);
};

string JobWzskAcqCorner::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == ACQ) return("acq");
	if (ix == CALCIDLE) return("calcidle");
	if (ix == CALC) return("calc");
	if (ix == DONE) return("done");

	return("");
};

void JobWzskAcqCorner::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqCorner::VecVVar
 ******************************************************************************/

uint JobWzskAcqCorner::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "roix0roiy0roix1roiy1") return ROIX0ROIY0ROIX1ROIY1;
	if (s == "shiftscoreminscoremax") return SHIFTSCOREMINSCOREMAX;

	return(0);
};

string JobWzskAcqCorner::VecVVar::getSref(
			const uint ix
		) {
	if (ix == ROIX0ROIY0ROIX1ROIY1) return("roiX0RoiY0RoiX1RoiY1");
	if (ix == SHIFTSCOREMINSCOREMAX) return("shiftScoreMinScoreMax");

	return("");
};

void JobWzskAcqCorner::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqCorner::Stg
 ******************************************************************************/

JobWzskAcqCorner::Stg::Stg(
			const usmallint row0
			, const usmallint col0
			, const usmallint w
			, const usmallint h
		) :
			Block()
			, row0(row0)
			, col0(col0)
			, w(w)
			, h(h)
		{
	mask = {ROW0, COL0, W, H};
};

bool JobWzskAcqCorner::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskAcqCorner");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskAcqCorner";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "row0", row0)) add(ROW0);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "col0", col0)) add(COL0);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "w", w)) add(W);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "h", h)) add(H);
	};

	return basefound;
};

void JobWzskAcqCorner::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskAcqCorner";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskAcqCorner";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "row0", row0);
		writeUsmallintAttr(wr, itemtag, "sref", "col0", col0);
		writeUsmallintAttr(wr, itemtag, "sref", "w", w);
		writeUsmallintAttr(wr, itemtag, "sref", "h", h);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskAcqCorner::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (row0 == comp->row0) insert(items, ROW0);
	if (col0 == comp->col0) insert(items, COL0);
	if (w == comp->w) insert(items, W);
	if (h == comp->h) insert(items, H);

	return(items);
};

set<uint> JobWzskAcqCorner::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ROW0, COL0, W, H};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
