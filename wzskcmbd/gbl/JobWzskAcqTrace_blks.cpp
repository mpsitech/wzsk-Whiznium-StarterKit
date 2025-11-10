/**
	* \file JobWzskAcqTrace_blks.cpp
	* job handler for job JobWzskAcqTrace (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqTrace::VecVMethod
 ******************************************************************************/

uint JobWzskAcqTrace::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setroi") return SETROI;

	return(0);
};

string JobWzskAcqTrace::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETROI) return("setRoi");

	return("");
};

void JobWzskAcqTrace::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqTrace::VecVVar
 ******************************************************************************/

uint JobWzskAcqTrace::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "roix0roiy0roix1roiy1") return ROIX0ROIY0ROIX1ROIY1;

	return(0);
};

string JobWzskAcqTrace::VecVVar::getSref(
			const uint ix
		) {
	if (ix == ROIX0ROIY0ROIX1ROIY1) return("roiX0RoiY0RoiX1RoiY1");

	return("");
};

void JobWzskAcqTrace::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqTrace::Stg
 ******************************************************************************/

JobWzskAcqTrace::Stg::Stg(
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

bool JobWzskAcqTrace::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskAcqTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskAcqTrace";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "row0", row0)) add(ROW0);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "col0", col0)) add(COL0);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "w", w)) add(W);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "h", h)) add(H);
	};

	return basefound;
};

void JobWzskAcqTrace::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskAcqTrace";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskAcqTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "row0", row0);
		writeUsmallintAttr(wr, itemtag, "sref", "col0", col0);
		writeUsmallintAttr(wr, itemtag, "sref", "w", w);
		writeUsmallintAttr(wr, itemtag, "sref", "h", h);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskAcqTrace::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (row0 == comp->row0) insert(items, ROW0);
	if (col0 == comp->col0) insert(items, COL0);
	if (w == comp->w) insert(items, W);
	if (h == comp->h) insert(items, H);

	return(items);
};

set<uint> JobWzskAcqTrace::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ROW0, COL0, W, H};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
