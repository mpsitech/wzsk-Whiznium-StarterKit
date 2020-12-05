/**
	* \file WzskQObjList.cpp
	* API code for table TblWzskQObjList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQObjList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQObjList
 ******************************************************************************/

WzskQObjList::WzskQObjList(
			const uint jnum
			, const string Title
			, const string stubRefWzskMObjgroup
		) {
	this->jnum = jnum;
	this->Title = Title;
	this->stubRefWzskMObjgroup = stubRefWzskMObjgroup;
};

bool WzskQObjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQObjList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubRefWzskMObjgroup", "ogr", stubRefWzskMObjgroup);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQObjList
 ******************************************************************************/

ListWzskQObjList::ListWzskQObjList() {
};

ListWzskQObjList::ListWzskQObjList(
			const ListWzskQObjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQObjList(*(src.nodes[i]));
};

ListWzskQObjList& ListWzskQObjList::operator=(
			const ListWzskQObjList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQObjList(*(src.nodes[i]));

	return *this;
};

ListWzskQObjList::~ListWzskQObjList() {
	clear();
};

void ListWzskQObjList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQObjList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQObjList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQObjList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQObjList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQObjList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQObjList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

