/**
	* \file WzskQOgrList.cpp
	* API code for table TblWzskQOgrList (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskQOgrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQOgrList
 ******************************************************************************/

WzskQOgrList::WzskQOgrList(
			const uint jnum
			, const string sref
			, const string Title
			, const string stubSupRefWzskMObjgroup
		) {
	this->jnum = jnum;
	this->sref = sref;
	this->Title = Title;
	this->stubSupRefWzskMObjgroup = stubSupRefWzskMObjgroup;
};

bool WzskQOgrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQOgrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "stubSupRefWzskMObjgroup", "sup", stubSupRefWzskMObjgroup);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQOgrList
 ******************************************************************************/

ListWzskQOgrList::ListWzskQOgrList() {
};

ListWzskQOgrList::ListWzskQOgrList(
			const ListWzskQOgrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQOgrList(*(src.nodes[i]));
};

ListWzskQOgrList& ListWzskQOgrList::operator=(
			const ListWzskQOgrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQOgrList(*(src.nodes[i]));

	return *this;
};

ListWzskQOgrList::~ListWzskQOgrList() {
	clear();
};

void ListWzskQOgrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQOgrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQOgrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQOgrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQOgrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQOgrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQOgrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

