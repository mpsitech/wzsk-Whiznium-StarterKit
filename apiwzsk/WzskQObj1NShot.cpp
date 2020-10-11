/**
	* \file WzskQObj1NShot.cpp
	* API code for table TblWzskQObj1NShot (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "WzskQObj1NShot.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQObj1NShot
 ******************************************************************************/

WzskQObj1NShot::WzskQObj1NShot(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzskQObj1NShot::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQObj1NShot");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQObj1NShot
 ******************************************************************************/

ListWzskQObj1NShot::ListWzskQObj1NShot() {
};

ListWzskQObj1NShot::ListWzskQObj1NShot(
			const ListWzskQObj1NShot& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQObj1NShot(*(src.nodes[i]));
};

ListWzskQObj1NShot& ListWzskQObj1NShot::operator=(
			const ListWzskQObj1NShot& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQObj1NShot(*(src.nodes[i]));

	return *this;
};

ListWzskQObj1NShot::~ListWzskQObj1NShot() {
	clear();
};

void ListWzskQObj1NShot::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQObj1NShot::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQObj1NShot* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQObj1NShot");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQObj1NShot", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQObj1NShot(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQObj1NShot[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

