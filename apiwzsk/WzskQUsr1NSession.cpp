/**
	* \file WzskQUsr1NSession.cpp
	* API code for table TblWzskQUsr1NSession (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "WzskQUsr1NSession.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsr1NSession
 ******************************************************************************/

WzskQUsr1NSession::WzskQUsr1NSession(
			const uint jnum
			, const string stubRef
		) {
	this->jnum = jnum;
	this->stubRef = stubRef;
};

bool WzskQUsr1NSession::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQUsr1NSession");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubRef", "ref", stubRef);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQUsr1NSession
 ******************************************************************************/

ListWzskQUsr1NSession::ListWzskQUsr1NSession() {
};

ListWzskQUsr1NSession::ListWzskQUsr1NSession(
			const ListWzskQUsr1NSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsr1NSession(*(src.nodes[i]));
};

ListWzskQUsr1NSession& ListWzskQUsr1NSession::operator=(
			const ListWzskQUsr1NSession& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsr1NSession(*(src.nodes[i]));

	return *this;
};

ListWzskQUsr1NSession::~ListWzskQUsr1NSession() {
	clear();
};

void ListWzskQUsr1NSession::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQUsr1NSession::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQUsr1NSession* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQUsr1NSession");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQUsr1NSession", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQUsr1NSession(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQUsr1NSession[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};

