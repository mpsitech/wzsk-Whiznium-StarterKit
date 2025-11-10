/**
	* \file WzskQUsrList.cpp
	* API code for table TblWzskQUsrList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "WzskQUsrList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQUsrList
 ******************************************************************************/

WzskQUsrList::WzskQUsrList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string stubRefWzskMPerson
			, const string sref
			, const string stubRefWzskMUsergroup
			, const string srefIxVState
			, const string titIxVState
			, const string srefIxWzskVLocale
			, const string titIxWzskVLocale
			, const string srefIxWzskVUserlevel
			, const string titIxWzskVUserlevel
		) :
			jnum(jnum)
			, stubGrp(stubGrp)
			, stubOwn(stubOwn)
			, stubRefWzskMPerson(stubRefWzskMPerson)
			, sref(sref)
			, stubRefWzskMUsergroup(stubRefWzskMUsergroup)
			, srefIxVState(srefIxVState)
			, titIxVState(titIxVState)
			, srefIxWzskVLocale(srefIxWzskVLocale)
			, titIxWzskVLocale(titIxWzskVLocale)
			, srefIxWzskVUserlevel(srefIxWzskVUserlevel)
			, titIxWzskVUserlevel(titIxWzskVUserlevel)
		{
};

bool WzskQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "stubRefWzskMPerson", "prs", stubRefWzskMPerson);
		extractStringUclc(docctx, basexpath, "sref", "srf", sref);
		extractStringUclc(docctx, basexpath, "stubRefWzskMUsergroup", "usg", stubRefWzskMUsergroup);
		extractStringUclc(docctx, basexpath, "srefIxVState", "ste", srefIxVState);
		extractStringUclc(docctx, basexpath, "titIxVState", "ste2", titIxVState);
		extractStringUclc(docctx, basexpath, "srefIxWzskVLocale", "lcl", srefIxWzskVLocale);
		extractStringUclc(docctx, basexpath, "titIxWzskVLocale", "lcl2", titIxWzskVLocale);
		extractStringUclc(docctx, basexpath, "srefIxWzskVUserlevel", "ulv", srefIxWzskVUserlevel);
		extractStringUclc(docctx, basexpath, "titIxWzskVUserlevel", "ulv2", titIxWzskVUserlevel);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQUsrList
 ******************************************************************************/

ListWzskQUsrList::ListWzskQUsrList() {
};

ListWzskQUsrList::ListWzskQUsrList(
			const ListWzskQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrList(*(src.nodes[i]));
};

ListWzskQUsrList& ListWzskQUsrList::operator=(
			const ListWzskQUsrList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQUsrList(*(src.nodes[i]));

	return *this;
};

ListWzskQUsrList::~ListWzskQUsrList() {
	clear();
};

void ListWzskQUsrList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQUsrList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQUsrList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQUsrList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQUsrList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQUsrList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQUsrList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
