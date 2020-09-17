/**
	* \file WzskQOgrSup1NObjgroup.cpp
	* API code for table TblWzskQOgrSup1NObjgroup (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "WzskQOgrSup1NObjgroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQOgrSup1NObjgroup
 ******************************************************************************/

WzskQOgrSup1NObjgroup::WzskQOgrSup1NObjgroup(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzskQOgrSup1NObjgroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQOgrSup1NObjgroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQOgrSup1NObjgroup
 ******************************************************************************/

ListWzskQOgrSup1NObjgroup::ListWzskQOgrSup1NObjgroup() {
};

ListWzskQOgrSup1NObjgroup::ListWzskQOgrSup1NObjgroup(
			const ListWzskQOgrSup1NObjgroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQOgrSup1NObjgroup(*(src.nodes[i]));
};

ListWzskQOgrSup1NObjgroup& ListWzskQOgrSup1NObjgroup::operator=(
			const ListWzskQOgrSup1NObjgroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQOgrSup1NObjgroup(*(src.nodes[i]));

	return *this;
};

ListWzskQOgrSup1NObjgroup::~ListWzskQOgrSup1NObjgroup() {
	clear();
};

void ListWzskQOgrSup1NObjgroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQOgrSup1NObjgroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQOgrSup1NObjgroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQOgrSup1NObjgroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQOgrSup1NObjgroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQOgrSup1NObjgroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQOgrSup1NObjgroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

