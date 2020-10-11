/**
	* \file WzskQObjRef1NFile.cpp
	* API code for table TblWzskQObjRef1NFile (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "WzskQObjRef1NFile.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQObjRef1NFile
 ******************************************************************************/

WzskQObjRef1NFile::WzskQObjRef1NFile(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzskQObjRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQObjRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQObjRef1NFile
 ******************************************************************************/

ListWzskQObjRef1NFile::ListWzskQObjRef1NFile() {
};

ListWzskQObjRef1NFile::ListWzskQObjRef1NFile(
			const ListWzskQObjRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQObjRef1NFile(*(src.nodes[i]));
};

ListWzskQObjRef1NFile& ListWzskQObjRef1NFile::operator=(
			const ListWzskQObjRef1NFile& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQObjRef1NFile(*(src.nodes[i]));

	return *this;
};

ListWzskQObjRef1NFile::~ListWzskQObjRef1NFile() {
	clear();
};

void ListWzskQObjRef1NFile::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQObjRef1NFile::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQObjRef1NFile* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQObjRef1NFile");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQObjRef1NFile", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQObjRef1NFile(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQObjRef1NFile[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

