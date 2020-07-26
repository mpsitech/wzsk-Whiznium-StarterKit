/**
	* \file JobWzskIprCorner_blks.cpp
	* job handler for job JobWzskIprCorner (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskIprCorner::VecVMethod
 ******************************************************************************/

uint JobWzskIprCorner::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setntarget") return SETNTARGET;
	if (s == "setroi") return SETROI;
	if (s == "setroinotfull") return SETROINOTFULL;

	return(0);
};

string JobWzskIprCorner::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETNTARGET) return("setNTarget");
	if (ix == SETROI) return("setRoi");
	if (ix == SETROINOTFULL) return("setRoiNotFull");

	return("");
};

void JobWzskIprCorner::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskIprCorner::VecVSge
 ******************************************************************************/

uint JobWzskIprCorner::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;
	if (s == "prcidle") return PRCIDLE;
	if (s == "process") return PROCESS;
	if (s == "done") return DONE;

	return(0);
};

string JobWzskIprCorner::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");
	if (ix == PRCIDLE) return("prcidle");
	if (ix == PROCESS) return("process");
	if (ix == DONE) return("done");

	return("");
};

void JobWzskIprCorner::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 5; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskIprCorner::VecVVar
 ******************************************************************************/

uint JobWzskIprCorner::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ntarget") return NTARGET;
	if (s == "roiaxroiayroibxroibyroicxroicyroidxroidy") return ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY;
	if (s == "flg") return FLG;

	return(0);
};

string JobWzskIprCorner::VecVVar::getSref(
			const uint ix
		) {
	if (ix == NTARGET) return("NTarget");
	if (ix == ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY) return("roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy");
	if (ix == FLG) return("flg");

	return("");
};

void JobWzskIprCorner::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskIprCorner::Stg
 ******************************************************************************/

JobWzskIprCorner::Stg::Stg(
			const bool roiNotFull
		) :
			Block()
		{
	this->roiNotFull = roiNotFull;
	mask = {ROINOTFULL};
};

bool JobWzskIprCorner::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskIprCorner");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskIprCorner";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roiNotFull", roiNotFull)) add(ROINOTFULL);
	};

	return basefound;
};

void JobWzskIprCorner::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskIprCorner";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskIprCorner";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "roiNotFull", roiNotFull);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskIprCorner::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (roiNotFull == comp->roiNotFull) insert(items, ROINOTFULL);

	return(items);
};

set<uint> JobWzskIprCorner::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {ROINOTFULL};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

