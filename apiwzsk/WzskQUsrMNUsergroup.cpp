/**
	* \file WzskQUsrMNUsergroup.cpp
	* API code for table TblWzskQUsrMNUsergroup (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "WzskQUsrMNUsergroup.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsrMNUsergroup
 ******************************************************************************/

WzskQUsrMNUsergroup::WzskQUsrMNUsergroup(
			const uint jnum
			, const string stubMref
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) {
	this->jnum = jnum;
	this->stubMref = stubMref;
	this->srefIxWzskVUserlevel = srefIxWzskVUserlevel;
	this->titIxWzskVUserlevel = titIxWzskVUserlevel;
};

bool WzskQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubMref", "mref", stubMref);
		extractStringUclc(docctx, basexpath, "srefIxWzskVUserlevel", "ulv", srefIxWzskVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWzskVUserlevel", "ulv2", titIxWzskVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQUsrMNUsergroup
 ******************************************************************************/

ListWzskQUsrMNUsergroup::ListWzskQUsrMNUsergroup() {
};

ListWzskQUsrMNUsergroup::ListWzskQUsrMNUsergroup(
			const ListWzskQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrMNUsergroup(*(src.nodes[i]));
};

ListWzskQUsrMNUsergroup& ListWzskQUsrMNUsergroup::operator=(
			const ListWzskQUsrMNUsergroup& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrMNUsergroup(*(src.nodes[i]));

	return *this;
};

ListWzskQUsrMNUsergroup::~ListWzskQUsrMNUsergroup() {
	clear();
};

void ListWzskQUsrMNUsergroup::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQUsrMNUsergroup::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQUsrMNUsergroup* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQUsrMNUsergroup");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQUsrMNUsergroup", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQUsrMNUsergroup(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQUsrMNUsergroup[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

