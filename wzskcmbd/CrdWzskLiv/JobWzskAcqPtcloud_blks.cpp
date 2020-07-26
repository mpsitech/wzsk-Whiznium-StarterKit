/**
	* \file JobWzskAcqPtcloud_blks.cpp
	* job handler for job JobWzskAcqPtcloud (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqPtcloud::VecVSge
 ******************************************************************************/

uint JobWzskAcqPtcloud::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;
	if (s == "acquire") return ACQUIRE;
	if (s == "prcidle") return PRCIDLE;
	if (s == "process") return PROCESS;
	if (s == "turn") return TURN;

	return(0);
};

string JobWzskAcqPtcloud::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");
	if (ix == ACQUIRE) return("acquire");
	if (ix == PRCIDLE) return("prcidle");
	if (ix == PROCESS) return("process");
	if (ix == TURN) return("turn");

	return("");
};

void JobWzskAcqPtcloud::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 6; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqPtcloud::VecVVar
 ******************************************************************************/

uint JobWzskAcqPtcloud::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "xyz") return XYZ;

	return(0);
};

string JobWzskAcqPtcloud::VecVVar::getSref(
			const uint ix
		) {
	if (ix == XYZ) return("xYZ");

	return("");
};

void JobWzskAcqPtcloud::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 1; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqPtcloud::Stg
 ******************************************************************************/

JobWzskAcqPtcloud::Stg::Stg(
			const float dLeft
			, const float dRight
			, const float dWork
			, const float deltaTheta
		) :
			Block()
		{
	this->dLeft = dLeft;
	this->dRight = dRight;
	this->dWork = dWork;
	this->deltaTheta = deltaTheta;
	mask = {DLEFT, DRIGHT, DWORK, DELTATHETA};
};

bool JobWzskAcqPtcloud::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskAcqPtcloud");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskAcqPtcloud";

	if (basefound) {
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dLeft", dLeft)) add(DLEFT);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dRight", dRight)) add(DRIGHT);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "dWork", dWork)) add(DWORK);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "deltaTheta", deltaTheta)) add(DELTATHETA);
	};

	return basefound;
};

void JobWzskAcqPtcloud::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskAcqPtcloud";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskAcqPtcloud";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeFloatAttr(wr, itemtag, "sref", "dLeft", dLeft);
		writeFloatAttr(wr, itemtag, "sref", "dRight", dRight);
		writeFloatAttr(wr, itemtag, "sref", "dWork", dWork);
		writeFloatAttr(wr, itemtag, "sref", "deltaTheta", deltaTheta);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskAcqPtcloud::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (compareFloat(dLeft, comp->dLeft) < 1.0e-4) insert(items, DLEFT);
	if (compareFloat(dRight, comp->dRight) < 1.0e-4) insert(items, DRIGHT);
	if (compareFloat(dWork, comp->dWork) < 1.0e-4) insert(items, DWORK);
	if (compareFloat(deltaTheta, comp->deltaTheta) < 1.0e-4) insert(items, DELTATHETA);

	return(items);
};

set<uint> JobWzskAcqPtcloud::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {DLEFT, DRIGHT, DWORK, DELTATHETA};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

