/**
	* \file JobWzskIprCorner_blks.cpp
	* job handler for job JobWzskIprCorner (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

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
	if (s == "flgshiftscoreminscoremax") return FLGSHIFTSCOREMINSCOREMAX;

	return(0);
};

string JobWzskIprCorner::VecVVar::getSref(
			const uint ix
		) {
	if (ix == NTARGET) return("NTarget");
	if (ix == ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY) return("roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy");
	if (ix == FLGSHIFTSCOREMINSCOREMAX) return("flgShiftScoreMinScoreMax");

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
			const bool linNotLog
			, const bool roiNotFull
			, const utinyint flgPerRowMax
		) :
			Block()
		{
	this->linNotLog = linNotLog;
	this->roiNotFull = roiNotFull;
	this->flgPerRowMax = flgPerRowMax;
	mask = {LINNOTLOG, ROINOTFULL, FLGPERROWMAX};
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
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "linNotLog", linNotLog)) add(LINNOTLOG);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roiNotFull", roiNotFull)) add(ROINOTFULL);
		if (extractUtinyintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "flgPerRowMax", flgPerRowMax)) add(FLGPERROWMAX);
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
		writeBoolAttr(wr, itemtag, "sref", "linNotLog", linNotLog);
		writeBoolAttr(wr, itemtag, "sref", "roiNotFull", roiNotFull);
		writeUtinyintAttr(wr, itemtag, "sref", "flgPerRowMax", flgPerRowMax);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskIprCorner::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (linNotLog == comp->linNotLog) insert(items, LINNOTLOG);
	if (roiNotFull == comp->roiNotFull) insert(items, ROINOTFULL);
	if (flgPerRowMax == comp->flgPerRowMax) insert(items, FLGPERROWMAX);

	return(items);
};

set<uint> JobWzskIprCorner::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {LINNOTLOG, ROINOTFULL, FLGPERROWMAX};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
