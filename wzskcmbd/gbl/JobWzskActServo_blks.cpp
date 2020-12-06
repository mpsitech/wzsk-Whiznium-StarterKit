/**
	* \file JobWzskActServo_blks.cpp
	* job handler for job JobWzskActServo (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskActServo::VecVMethod
 ******************************************************************************/

uint JobWzskActServo::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "moveto") return MOVETO;
	if (s == "stop") return STOP;
	if (s == "turn") return TURN;
	if (s == "zero") return ZERO;

	return(0);
};

string JobWzskActServo::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == MOVETO) return("moveto");
	if (ix == STOP) return("stop");
	if (ix == TURN) return("turn");
	if (ix == ZERO) return("zero");

	return("");
};

void JobWzskActServo::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActServo::VecVSge
 ******************************************************************************/

uint JobWzskActServo::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "move") return MOVE;

	return(0);
};

string JobWzskActServo::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == MOVE) return("move");

	return("");
};

void JobWzskActServo::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActServo::VecVVar
 ******************************************************************************/

uint JobWzskActServo::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "angletarget") return ANGLETARGET;

	return(0);
};

string JobWzskActServo::VecVVar::getSref(
			const uint ix
		) {
	if (ix == ANGLETARGET) return("angleTarget");

	return("");
};

void JobWzskActServo::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActServo::Stg
 ******************************************************************************/

JobWzskActServo::Stg::Stg(
			const string& pathroot
			, const bool halfstepNotTorque
			, const float omega
		) :
			Block()
		{
	this->pathroot = pathroot;
	this->halfstepNotTorque = halfstepNotTorque;
	this->omega = omega;
	mask = {PATHROOT, HALFSTEPNOTTORQUE, OMEGA};
};

bool JobWzskActServo::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskActServo");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskActServo";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "pathroot", pathroot)) add(PATHROOT);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "halfstepNotTorque", halfstepNotTorque)) add(HALFSTEPNOTTORQUE);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "omega", omega)) add(OMEGA);
	};

	return basefound;
};

void JobWzskActServo::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskActServo";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskActServo";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "pathroot", pathroot);
		writeBoolAttr(wr, itemtag, "sref", "halfstepNotTorque", halfstepNotTorque);
		writeFloatAttr(wr, itemtag, "sref", "omega", omega);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskActServo::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (pathroot == comp->pathroot) insert(items, PATHROOT);
	if (halfstepNotTorque == comp->halfstepNotTorque) insert(items, HALFSTEPNOTTORQUE);
	if (compareFloat(omega, comp->omega) < 1.0e-4) insert(items, OMEGA);

	return(items);
};

set<uint> JobWzskActServo::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATHROOT, HALFSTEPNOTTORQUE, OMEGA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
