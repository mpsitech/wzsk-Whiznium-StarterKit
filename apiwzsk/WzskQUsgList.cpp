/**
	* \file WzskQUsgList.cpp
	* API code for table TblWzskQUsgList (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskQUsgList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsgList
 ******************************************************************************/

WzskQUsgList::WzskQUsgList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string sref
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->sref = sref;
};

bool WzskQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQUsgList
 ******************************************************************************/

ListWzskQUsgList::ListWzskQUsgList() {
};

ListWzskQUsgList::ListWzskQUsgList(
			const ListWzskQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsgList(*(src.nodes[i]));
};

ListWzskQUsgList& ListWzskQUsgList::operator=(
			const ListWzskQUsgList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsgList(*(src.nodes[i]));

	return *this;
};

ListWzskQUsgList::~ListWzskQUsgList() {
	clear();
};

void ListWzskQUsgList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQUsgList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQUsgList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQUsgList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQUsgList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQUsgList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQUsgList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

