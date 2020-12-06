/**
	* \file WzskQSesList.cpp
	* API code for table TblWzskQSesList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQSesList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQSesList
 ******************************************************************************/

WzskQSesList::WzskQSesList(
			const uint jnum
			, const string stubRefWzskMUser
			, const string ftmStart
			, const string ftmStop
			, const string Ip
		) {
	this->jnum = jnum;
	this->stubRefWzskMUser = stubRefWzskMUser;
	this->ftmStart = ftmStart;
	this->ftmStop = ftmStop;
	this->Ip = Ip;
};

bool WzskQSesList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQSesList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRefWzskMUser", "usr", stubRefWzskMUser);
		extractStringUclc(docctx, basexpath, "ftmStart", "sta", ftmStart);
		extractStringUclc(docctx, basexpath, "ftmStop", "sto", ftmStop);
		extractStringUclc(docctx, basexpath, "Ip", "ip", Ip);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQSesList
 ******************************************************************************/

ListWzskQSesList::ListWzskQSesList() {
};

ListWzskQSesList::ListWzskQSesList(
			const ListWzskQSesList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQSesList(*(src.nodes[i]));
};

ListWzskQSesList& ListWzskQSesList::operator=(
			const ListWzskQSesList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQSesList(*(src.nodes[i]));

	return *this;
};

ListWzskQSesList::~ListWzskQSesList() {
	clear();
};

void ListWzskQSesList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQSesList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQSesList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQSesList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQSesList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQSesList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQSesList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
