/**
	* \file JobWzskSrcIcicle_blks.cpp
	* job handler for job JobWzskSrcIcicle (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskSrcIcicle::VecVSge
 ******************************************************************************/

uint JobWzskSrcIcicle::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "nc") return NC;
	if (s == "ready") return READY;

	return(0);
};

string JobWzskSrcIcicle::VecVSge::getSref(
			const uint ix
		) {
	if (ix == NC) return("nc");
	if (ix == READY) return("ready");

	return("");
};

void JobWzskSrcIcicle::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcIcicle::Stg
 ******************************************************************************/

JobWzskSrcIcicle::Stg::Stg(
			const string& path
		) :
			Block()
		{
	this->path = path;
	mask = {PATH};
};

bool JobWzskSrcIcicle::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskSrcIcicle");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskSrcIcicle";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "path", path)) add(PATH);
	};

	return basefound;
};

void JobWzskSrcIcicle::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskSrcIcicle";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskSrcIcicle";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "path", path);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskSrcIcicle::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (path == comp->path) insert(items, PATH);

	return(items);
};

set<uint> JobWzskSrcIcicle::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATH};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
