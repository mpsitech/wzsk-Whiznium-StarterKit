/**
	* \file JobWzskSrcPwmonusb_blks.cpp
	* job handler for job JobWzskSrcPwmonusb (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 4 Jun 2022
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskSrcPwmonusb::VecVSge
 ******************************************************************************/

uint JobWzskSrcPwmonusb::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nc") return NC;
	if (s == "ready") return READY;

	return(0);
};

string JobWzskSrcPwmonusb::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NC) return("nc");
	if (ix == READY) return("ready");

	return("");
};

void JobWzskSrcPwmonusb::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcPwmonusb::Stg
 ******************************************************************************/

JobWzskSrcPwmonusb::Stg::Stg(
			const string& path
		) :
			Block()
		{
	this->path = path;
	mask = {PATH};
};

bool JobWzskSrcPwmonusb::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskSrcPwmonusb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskSrcPwmonusb";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "path", path)) add(PATH);
	};

	return basefound;
};

void JobWzskSrcPwmonusb::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskSrcPwmonusb";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskSrcPwmonusb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "path", path);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskSrcPwmonusb::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (path == comp->path) insert(items, PATH);

	return(items);
};

set<uint> JobWzskSrcPwmonusb::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
