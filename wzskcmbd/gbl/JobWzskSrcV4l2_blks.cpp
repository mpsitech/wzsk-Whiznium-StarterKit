/**
	* \file JobWzskSrcV4l2_blks.cpp
	* job handler for job JobWzskSrcV4l2 (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskSrcV4l2::VecVSge
 ******************************************************************************/

uint JobWzskSrcV4l2::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;
	if (s == "cnvidle") return CNVIDLE;
	if (s == "convert") return CONVERT;

	return(0);
};

string JobWzskSrcV4l2::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");
	if (ix == CNVIDLE) return("cnvidle");
	if (ix == CONVERT) return("convert");

	return("");
};

void JobWzskSrcV4l2::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcV4l2::Stg
 ******************************************************************************/

JobWzskSrcV4l2::Stg::Stg(
			const string& path
			, const bool YUV422NotYUV420
		) :
			Block()
		{
	this->path = path;
	this->YUV422NotYUV420 = YUV422NotYUV420;
	mask = {PATH, YUV422NOTYUV420};
};

bool JobWzskSrcV4l2::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskSrcV4l2");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskSrcV4l2";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "path", path)) add(PATH);
		if (extractBoolAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "YUV422NotYUV420", YUV422NotYUV420)) add(YUV422NOTYUV420);
	};

	return basefound;
};

void JobWzskSrcV4l2::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskSrcV4l2";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskSrcV4l2";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "path", path);
		writeBoolAttr(wr, itemtag, "sref", "YUV422NotYUV420", YUV422NotYUV420);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskSrcV4l2::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (path == comp->path) insert(items, PATH);
	if (YUV422NotYUV420 == comp->YUV422NotYUV420) insert(items, YUV422NOTYUV420);

	return(items);
};

set<uint> JobWzskSrcV4l2::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATH, YUV422NOTYUV420};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};

