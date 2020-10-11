/**
	* \file JobWzskIprTrace_blks.cpp
	* job handler for job JobWzskIprTrace (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskIprTrace::VecVMethod
 ******************************************************************************/

uint JobWzskIprTrace::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setlevel") return SETLEVEL;
	if (s == "setroi") return SETROI;
	if (s == "setroinotfull") return SETROINOTFULL;

	return(0);
};

string JobWzskIprTrace::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETLEVEL) return("setLevel");
	if (ix == SETROI) return("setRoi");
	if (ix == SETROINOTFULL) return("setRoiNotFull");

	return("");
};

void JobWzskIprTrace::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 3; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskIprTrace::VecVSge
 ******************************************************************************/

uint JobWzskIprTrace::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;
	if (s == "prcidle") return PRCIDLE;
	if (s == "process") return PROCESS;
	if (s == "lefton") return LEFTON;
	if (s == "leftoff") return LEFTOFF;
	if (s == "righton") return RIGHTON;
	if (s == "rightoff") return RIGHTOFF;
	if (s == "done") return DONE;

	return(0);
};

string JobWzskIprTrace::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");
	if (ix == PRCIDLE) return("prcidle");
	if (ix == PROCESS) return("process");
	if (ix == LEFTON) return("lefton");
	if (ix == LEFTOFF) return("leftoff");
	if (ix == RIGHTON) return("righton");
	if (ix == RIGHTOFF) return("rightoff");
	if (ix == DONE) return("done");

	return("");
};

void JobWzskIprTrace::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 9; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskIprTrace::VecVVar
 ******************************************************************************/

uint JobWzskIprTrace::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "ponleftponright") return PONLEFTPONRIGHT;
	if (s == "levelonleveloff") return LEVELONLEVELOFF;
	if (s == "roiaxroiayroibxroibyroicxroicyroidxroidy") return ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY;
	if (s == "leftright") return LEFTRIGHT;

	return(0);
};

string JobWzskIprTrace::VecVVar::getSref(
			const uint ix
		) {
	if (ix == PONLEFTPONRIGHT) return("pOnLeftPOnRight");
	if (ix == LEVELONLEVELOFF) return("levelOnLevelOff");
	if (ix == ROIAXROIAYROIBXROIBYROICXROICYROIDXROIDY) return("roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy");
	if (ix == LEFTRIGHT) return("leftRight");

	return("");
};

void JobWzskIprTrace::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskIprTrace::Stg
 ******************************************************************************/

JobWzskIprTrace::Stg::Stg(
			const bool v4l2RdNotDelta
			, const bool roiNotFull
			, const utinyint flgPerRowMax
			, const bool leftOnNotOff
			, const bool rightOnNotOff
		) :
			Block()
		{
	this->v4l2RdNotDelta = v4l2RdNotDelta;
	this->roiNotFull = roiNotFull;
	this->flgPerRowMax = flgPerRowMax;
	this->leftOnNotOff = leftOnNotOff;
	this->rightOnNotOff = rightOnNotOff;
	mask = {V4L2RDNOTDELTA, ROINOTFULL, FLGPERROWMAX, LEFTONNOTOFF, RIGHTONNOTOFF};
};

bool JobWzskIprTrace::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskIprTrace");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskIprTrace";

	if (basefound) {
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "v4l2RdNotDelta", v4l2RdNotDelta)) add(V4L2RDNOTDELTA);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "roiNotFull", roiNotFull)) add(ROINOTFULL);
		if (extractUtinyintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "flgPerRowMax", flgPerRowMax)) add(FLGPERROWMAX);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "leftOnNotOff", leftOnNotOff)) add(LEFTONNOTOFF);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "rightOnNotOff", rightOnNotOff)) add(RIGHTONNOTOFF);
	};

	return basefound;
};

void JobWzskIprTrace::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskIprTrace";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskIprTrace";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeBoolAttr(wr, itemtag, "sref", "v4l2RdNotDelta", v4l2RdNotDelta);
		writeBoolAttr(wr, itemtag, "sref", "roiNotFull", roiNotFull);
		writeUtinyintAttr(wr, itemtag, "sref", "flgPerRowMax", flgPerRowMax);
		writeBoolAttr(wr, itemtag, "sref", "leftOnNotOff", leftOnNotOff);
		writeBoolAttr(wr, itemtag, "sref", "rightOnNotOff", rightOnNotOff);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskIprTrace::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (v4l2RdNotDelta == comp->v4l2RdNotDelta) insert(items, V4L2RDNOTDELTA);
	if (roiNotFull == comp->roiNotFull) insert(items, ROINOTFULL);
	if (flgPerRowMax == comp->flgPerRowMax) insert(items, FLGPERROWMAX);
	if (leftOnNotOff == comp->leftOnNotOff) insert(items, LEFTONNOTOFF);
	if (rightOnNotOff == comp->rightOnNotOff) insert(items, RIGHTONNOTOFF);

	return(items);
};

set<uint> JobWzskIprTrace::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {V4L2RDNOTDELTA, ROINOTFULL, FLGPERROWMAX, LEFTONNOTOFF, RIGHTONNOTOFF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

