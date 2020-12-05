/**
	* \file WzskQUsgMNUser.cpp
	* API code for table TblWzskQUsgMNUser (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQUsgMNUser.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsgMNUser
 ******************************************************************************/

WzskQUsgMNUser::WzskQUsgMNUser(
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

bool WzskQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQUsgMNUser");
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
 class ListWzskQUsgMNUser
 ******************************************************************************/

ListWzskQUsgMNUser::ListWzskQUsgMNUser() {
};

ListWzskQUsgMNUser::ListWzskQUsgMNUser(
			const ListWzskQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsgMNUser(*(src.nodes[i]));
};

ListWzskQUsgMNUser& ListWzskQUsgMNUser::operator=(
			const ListWzskQUsgMNUser& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsgMNUser(*(src.nodes[i]));

	return *this;
};

ListWzskQUsgMNUser::~ListWzskQUsgMNUser() {
	clear();
};

void ListWzskQUsgMNUser::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQUsgMNUser::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQUsgMNUser* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQUsgMNUser");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQUsgMNUser", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQUsgMNUser(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQUsgMNUser[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

