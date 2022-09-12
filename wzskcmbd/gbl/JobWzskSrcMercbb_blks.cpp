/**
	* \file JobWzskSrcMercbb_blks.cpp
	* job handler for job JobWzskSrcMercbb (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 28 May 2022
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskSrcMercbb::VecVSge
 ******************************************************************************/

uint JobWzskSrcMercbb::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nc") return NC;
	if (s == "ready") return READY;

	return(0);
};

string JobWzskSrcMercbb::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NC) return("nc");
	if (ix == READY) return("ready");

	return("");
};

void JobWzskSrcMercbb::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcMercbb::Stg
 ******************************************************************************/

JobWzskSrcMercbb::Stg::Stg(
			const string& path
		) :
			Block()
		{
	this->path = path;
	mask = {PATH};
};

bool JobWzskSrcMercbb::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskSrcMercbb");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskSrcMercbb";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "path", path)) add(PATH);
	};

	return basefound;
};

void JobWzskSrcMercbb::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskSrcMercbb";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskSrcMercbb";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "path", path);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskSrcMercbb::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (path == comp->path) insert(items, PATH);

	return(items);
};

set<uint> JobWzskSrcMercbb::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
