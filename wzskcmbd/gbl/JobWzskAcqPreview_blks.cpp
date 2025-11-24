/**
	* \file JobWzskAcqPreview_blks.cpp
	* job handler for job JobWzskAcqPreview (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqPreview::VecVSge
 ******************************************************************************/

uint JobWzskAcqPreview::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "rng") return RNG;

	return(0);
};

string JobWzskAcqPreview::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RNG) return("rng");

	return("");
};

void JobWzskAcqPreview::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqPreview::Stg
 ******************************************************************************/

JobWzskAcqPreview::Stg::Stg(
			const utinyint sizePvwbuf
		) :
			Block()
			, sizePvwbuf(sizePvwbuf)
		{
	mask = {SIZEPVWBUF};
};

bool JobWzskAcqPreview::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskAcqPreview");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskAcqPreview";

	if (basefound) {
		if (extractUtinyintAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "sizePvwbuf", sizePvwbuf)) add(SIZEPVWBUF);
	};

	return basefound;
};

void JobWzskAcqPreview::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskAcqPreview";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskAcqPreview";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeUtinyintAttr(wr, itemtag, "sref", "sizePvwbuf", sizePvwbuf);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskAcqPreview::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (sizePvwbuf == comp->sizePvwbuf) insert(items, SIZEPVWBUF);

	return(items);
};

set<uint> JobWzskAcqPreview::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {SIZEPVWBUF};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
