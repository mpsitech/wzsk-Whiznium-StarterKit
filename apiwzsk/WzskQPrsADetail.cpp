/**
	* \file WzskQPrsADetail.cpp
	* API code for table TblWzskQPrsADetail (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "WzskQPrsADetail.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQPrsADetail
 ******************************************************************************/

WzskQPrsADetail::WzskQPrsADetail(
			const uint jnum
			, const string x1SrefKType
			, const string titX1SrefKType
			, const string Val
		) :
			jnum(jnum)
			, x1SrefKType(x1SrefKType)
			, titX1SrefKType(titX1SrefKType)
			, Val(Val)
		{
};

bool WzskQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "x1SrefKType", "typ", x1SrefKType);
		extractStringUclc(docctx, basexpath, "titX1SrefKType", "typ2", titX1SrefKType);
		extractStringUclc(docctx, basexpath, "Val", "val", Val);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQPrsADetail
 ******************************************************************************/

ListWzskQPrsADetail::ListWzskQPrsADetail() {
};

ListWzskQPrsADetail::ListWzskQPrsADetail(
			const ListWzskQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQPrsADetail(*(src.nodes[i]));
};

ListWzskQPrsADetail& ListWzskQPrsADetail::operator=(
			const ListWzskQPrsADetail& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQPrsADetail(*(src.nodes[i]));

	return *this;
};

ListWzskQPrsADetail::~ListWzskQPrsADetail() {
	clear();
};

void ListWzskQPrsADetail::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQPrsADetail::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQPrsADetail* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQPrsADetail");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQPrsADetail", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQPrsADetail(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQPrsADetail[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
