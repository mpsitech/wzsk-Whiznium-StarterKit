/**
	* \file JobWzskActRotary_blks.cpp
	* job handler for job JobWzskActRotary (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskActRotary::VecVMethod
 ******************************************************************************/

uint JobWzskActRotary::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "moveto") return MOVETO;
	if (s == "stop") return STOP;
	if (s == "turn") return TURN;
	if (s == "zero") return ZERO;

	return(0);
};

string JobWzskActRotary::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == MOVETO) return("moveto");
	if (ix == STOP) return("stop");
	if (ix == TURN) return("turn");
	if (ix == ZERO) return("zero");

	return("");
};

void JobWzskActRotary::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActRotary::VecVSge
 ******************************************************************************/

uint JobWzskActRotary::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "move") return MOVE;

	return(0);
};

string JobWzskActRotary::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == MOVE) return("move");

	return("");
};

void JobWzskActRotary::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActRotary::VecVVar
 ******************************************************************************/

uint JobWzskActRotary::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "angletarget") return ANGLETARGET;

	return(0);
};

string JobWzskActRotary::VecVVar::getSref(
			const uint ix
		) {
	if (ix == ANGLETARGET) return("angleTarget");

	return("");
};

void JobWzskActRotary::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActRotary::Stg
 ******************************************************************************/

JobWzskActRotary::Stg::Stg(
			const usmallint ppr
			, const float omega
		) :
			Block()
			, ppr(ppr)
			, omega(omega)
		{
	mask = {PPR, OMEGA};
};

bool JobWzskActRotary::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskActRotary");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskActRotary";

	if (basefound) {
		if (extractUsmallintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "ppr", ppr)) add(PPR);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "omega", omega)) add(OMEGA);
	};

	return basefound;
};

void JobWzskActRotary::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskActRotary";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskActRotary";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUsmallintAttr(wr, itemtag, "sref", "ppr", ppr);
		writeFloatAttr(wr, itemtag, "sref", "omega", omega);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskActRotary::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (ppr == comp->ppr) insert(items, PPR);
	if (compareFloat(omega, comp->omega) < 1.0e-4) insert(items, OMEGA);

	return(items);
};

set<uint> JobWzskActRotary::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PPR, OMEGA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
