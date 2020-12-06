/**
	* \file WzskQShtList.cpp
	* API code for table TblWzskQShtList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQShtList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQShtList
 ******************************************************************************/

WzskQShtList::WzskQShtList(
			const uint jnum
			, const string stubRefWzskMSession
			, const string stubRefWzskMObject
			, const string ftmStart
		) {
	this->jnum = jnum;
	this->stubRefWzskMSession = stubRefWzskMSession;
	this->stubRefWzskMObject = stubRefWzskMObject;
	this->ftmStart = ftmStart;
};

bool WzskQShtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQShtList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzskMSession", "ses", stubRefWzskMSession);
		extractStringUclc(docctx, basexpath, "stubRefWzskMObject", "obj", stubRefWzskMObject);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQShtList
 ******************************************************************************/

ListWzskQShtList::ListWzskQShtList() {
};

ListWzskQShtList::ListWzskQShtList(
			const ListWzskQShtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQShtList(*(src.nodes[i]));
};

ListWzskQShtList& ListWzskQShtList::operator=(
			const ListWzskQShtList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQShtList(*(src.nodes[i]));

	return *this;
};

ListWzskQShtList::~ListWzskQShtList() {
	clear();
};

void ListWzskQShtList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQShtList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQShtList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQShtList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQShtList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQShtList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQShtList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
