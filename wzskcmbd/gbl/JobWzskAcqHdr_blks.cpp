/**
	* \file JobWzskAcqHdr_blks.cpp
	* job handler for job JobWzskAcqHdr (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 14 Nov 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqHdr::VecVSge
 ******************************************************************************/

uint JobWzskAcqHdr::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "rng") return RNG;

	return(0);
};

string JobWzskAcqHdr::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RNG) return("rng");

	return("");
};

void JobWzskAcqHdr::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqHdr::Stg
 ******************************************************************************/

JobWzskAcqHdr::Stg::Stg(
			const string& path
			, const utinyint NChunk
			, const utinyint sizeChunk
		) :
			Block()
			, path(path)
			, NChunk(NChunk)
			, sizeChunk(sizeChunk)
		{
	mask = {PATH, NCHUNK, SIZECHUNK};
};

bool JobWzskAcqHdr::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskAcqHdr");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskAcqHdr";

	if (basefound) {
		if (extractStringAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "path", path)) add(PATH);
		if (extractUtinyintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "NChunk", NChunk)) add(NCHUNK);
		if (extractUtinyintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sizeChunk", sizeChunk)) add(SIZECHUNK);
	};

	return basefound;
};

void JobWzskAcqHdr::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskAcqHdr";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskAcqHdr";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "path", path);
		writeUtinyintAttr(wr, itemtag, "sref", "NChunk", NChunk);
		writeUtinyintAttr(wr, itemtag, "sref", "sizeChunk", sizeChunk);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskAcqHdr::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (path == comp->path) insert(items, PATH);
	if (NChunk == comp->NChunk) insert(items, NCHUNK);
	if (sizeChunk == comp->sizeChunk) insert(items, SIZECHUNK);

	return(items);
};

set<uint> JobWzskAcqHdr::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {PATH, NCHUNK, SIZECHUNK};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
