/**
	* \file WzskQPrsList.cpp
	* API code for table TblWzskQPrsList (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#include "WzskQPrsList.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class WzskQPrsList
 ******************************************************************************/

WzskQPrsList::WzskQPrsList(
			const uint jnum
			, const string stubGrp
			, const string stubOwn
			, const string Title
			, const string Firstname
			, const string Lastname
			, const string srefIxVSex
			, const string titIxVSex
			, const string telVal
			, const string emlVal
		) {
	this->jnum = jnum;
	this->stubGrp = stubGrp;
	this->stubOwn = stubOwn;
	this->Title = Title;
	this->Firstname = Firstname;
	this->Lastname = Lastname;
	this->srefIxVSex = srefIxVSex;
	this->titIxVSex = titIxVSex;
	this->telVal = telVal;
	this->emlVal = emlVal;
};

bool WzskQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "WzskQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		extractStringUclc(docctx, basexpath, "stubGrp", "grp", stubGrp);
		extractStringUclc(docctx, basexpath, "stubOwn", "own", stubOwn);
		extractStringUclc(docctx, basexpath, "Title", "tit", Title);
		extractStringUclc(docctx, basexpath, "Firstname", "fnm", Firstname);
		extractStringUclc(docctx, basexpath, "Lastname", "lnm", Lastname);
		extractStringUclc(docctx, basexpath, "srefIxVSex", "sex", srefIxVSex);
		extractStringUclc(docctx, basexpath, "titIxVSex", "sex2", titIxVSex);
		extractStringUclc(docctx, basexpath, "telVal", "tel", telVal);
		extractStringUclc(docctx, basexpath, "emlVal", "eml", emlVal);
	};

	return basefound;
};

/******************************************************************************
 class ListWzskQPrsList
 ******************************************************************************/

ListWzskQPrsList::ListWzskQPrsList() {
};

ListWzskQPrsList::ListWzskQPrsList(
			const ListWzskQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQPrsList(*(src.nodes[i]));
};

ListWzskQPrsList& ListWzskQPrsList::operator=(
			const ListWzskQPrsList& src
		) {
	nodes.resize(src.nodes.size(), NULL);
	for (unsigned int i = 0; i < nodes.size(); i++) nodes[i] = new WzskQPrsList(*(src.nodes[i]));

	return *this;
};

ListWzskQPrsList::~ListWzskQPrsList() {
	clear();
};

void ListWzskQPrsList::clear() {
	for (unsigned int i = 0; i < nodes.size(); i++) if (nodes[i]) delete nodes[i];
	nodes.resize(0);
};

bool ListWzskQPrsList::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	bool basefound;

	vector<unsigned int> ics;
	vector<bool> shorttags;

	WzskQPrsList* rec = NULL;

	string s;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "ListWzskQPrsList");
	else
		basefound = checkXPath(docctx, basexpath);

	extractList(docctx, basexpath, "WzskQPrsList", "row", "jnum", ics, shorttags);

	clear();

	for (unsigned int i = 0; i < ics.size(); i++) {
		rec = new WzskQPrsList(ics[i]);

		if (shorttags[i]) s = basexpath + "/row[@jnum='" + to_string(ics[i]) + "']";
		else s = basexpath + "/WzskQPrsList[@jnum='" + to_string(ics[i]) + "']";

		if (rec->readXML(docctx, s)) nodes.push_back(rec);
		else delete rec;
	};

	return basefound;
};
