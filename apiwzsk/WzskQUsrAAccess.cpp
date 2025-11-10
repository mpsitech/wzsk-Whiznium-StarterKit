/**
	* \file WzskQUsrAAccess.cpp
	* API code for table TblWzskQUsrAAccess (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "WzskQUsrAAccess.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsrAAccess
 ******************************************************************************/

WzskQUsrAAccess::WzskQUsrAAccess(
			const uint jnum
			, const string srefX1IxWzskVFeatgroup
			, const string titX1IxWzskVFeatgroup
			, const string x2FeaSrefUix
			, const string srefsIxWzskWAccess
			, const string titsIxWzskWAccess
		) :
			jnum(jnum)
			, srefX1IxWzskVFeatgroup(srefX1IxWzskVFeatgroup)
			, titX1IxWzskVFeatgroup(titX1IxWzskVFeatgroup)
			, x2FeaSrefUix(x2FeaSrefUix)
			, srefsIxWzskWAccess(srefsIxWzskWAccess)
			, titsIxWzskWAccess(titsIxWzskWAccess)
		{
};

bool WzskQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "srefX1IxWzskVFeatgroup", "feg", srefX1IxWzskVFeatgroup);
		extractStringUclc(docctx, basexpath, "titX1IxWzskVFeatgroup", "feg2", titX1IxWzskVFeatgroup);
		extractStringUclc(docctx, basexpath, "x2FeaSrefUix", "fea", x2FeaSrefUix);
		extractStringUclc(docctx, basexpath, "srefsIxWzskWAccess", "acc", srefsIxWzskWAccess);
		extractStringUclc(docctx, basexpath, "titsIxWzskWAccess", "acc2", titsIxWzskWAccess);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQUsrAAccess
 ******************************************************************************/

ListWzskQUsrAAccess::ListWzskQUsrAAccess() {
};

ListWzskQUsrAAccess::ListWzskQUsrAAccess(
			const ListWzskQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrAAccess(*(src.nodes[i]));
};

ListWzskQUsrAAccess& ListWzskQUsrAAccess::operator=(
			const ListWzskQUsrAAccess& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrAAccess(*(src.nodes[i]));

	return *this;
};

ListWzskQUsrAAccess::~ListWzskQUsrAAccess() {
	clear();
};

void ListWzskQUsrAAccess::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQUsrAAccess::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQUsrAAccess* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQUsrAAccess");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQUsrAAccess", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQUsrAAccess(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQUsrAAccess[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
