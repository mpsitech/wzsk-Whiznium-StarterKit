/**
	* \file JobWzskActLaser_blks.cpp
	* job handler for job JobWzskActLaser (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskActLaser::VecVMethod
 ******************************************************************************/

uint JobWzskActLaser::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setleft") return SETLEFT;
	if (s == "setright") return SETRIGHT;

	return(0);
};

string JobWzskActLaser::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETLEFT) return("setLeft");
	if (ix == SETRIGHT) return("setRight");

	return("");
};

void JobWzskActLaser::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActLaser::VecVVar
 ******************************************************************************/

uint JobWzskActLaser::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "leftright") return LEFTRIGHT;

	return(0);
};

string JobWzskActLaser::VecVVar::getSref(
			const uint ix
		) {
	if (ix == LEFTRIGHT) return("leftRight");

	return("");
};

void JobWzskActLaser::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActLaser::Stg
 ******************************************************************************/

JobWzskActLaser::Stg::Stg(
			const usmallint leftMin
			, const usmallint leftMax
			, const usmallint rightMin
			, const usmallint rightMax
		) :
			Block()
			, leftMin(leftMin)
			, leftMax(leftMax)
			, rightMin(rightMin)
			, rightMax(rightMax)
		{
	mask = {LEFTMIN, LEFTMAX, RIGHTMIN, RIGHTMAX};
};

bool JobWzskActLaser::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskActLaser");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskActLaser";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "leftMin", leftMin)) add(LEFTMIN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "leftMax", leftMax)) add(LEFTMAX);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "rightMin", rightMin)) add(RIGHTMIN);
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "rightMax", rightMax)) add(RIGHTMAX);
	};

	return basefound;
};

void JobWzskActLaser::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskActLaser";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskActLaser";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "leftMin", leftMin);
		writeUsmallintAttr(wr, itemtag, "sref", "leftMax", leftMax);
		writeUsmallintAttr(wr, itemtag, "sref", "rightMin", rightMin);
		writeUsmallintAttr(wr, itemtag, "sref", "rightMax", rightMax);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskActLaser::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (leftMin == comp->leftMin) insert(items, LEFTMIN);
	if (leftMax == comp->leftMax) insert(items, LEFTMAX);
	if (rightMin == comp->rightMin) insert(items, RIGHTMIN);
	if (rightMax == comp->rightMax) insert(items, RIGHTMAX);

	return(items);
};

set<uint> JobWzskActLaser::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LEFTMIN, LEFTMAX, RIGHTMIN, RIGHTMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
