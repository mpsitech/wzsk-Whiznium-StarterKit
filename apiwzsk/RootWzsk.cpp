/**
	* \file RootWzsk.cpp
	* API code for job RootWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#include "RootWzsk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class RootWzsk::DpchAppLogin
 ******************************************************************************/

RootWzsk::DpchAppLogin::DpchAppLogin(
			const string& scrJref
			, const string& username
			, const string& password
			, const bool m2mNotReg
			, const bool chksuspsess
			, const set<uint>& mask
		) :
			DpchAppWzsk(VecWzskVDpch::DPCHAPPROOTWZSKLOGIN, scrJref)
		{
	if (find(mask, ALL)) this->mask = {SCRJREF, USERNAME, PASSWORD, M2MNOTREG, CHKSUSPSESS};
	else this->mask = mask;

	this->username = username;
	this->password = password;
	this->m2mNotReg = m2mNotReg;
	this->chksuspsess = chksuspsess;
};

string RootWzsk::DpchAppLogin::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(USERNAME)) ss.push_back("username");
	if (has(PASSWORD)) ss.push_back("password");
	if (has(M2MNOTREG)) ss.push_back("m2mNotReg");
	if (has(CHKSUSPSESS)) ss.push_back("chksuspsess");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWzsk::DpchAppLogin::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchAppRootWzskLogin");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		if (has(SCRJREF)) writeString(wr, "scrJref", scrJref);
		if (has(USERNAME)) writeString(wr, "username", username);
		if (has(PASSWORD)) writeString(wr, "password", password);
		if (has(M2MNOTREG)) writeBool(wr, "m2mNotReg", m2mNotReg);
		if (has(CHKSUSPSESS)) writeBool(wr, "chksuspsess", chksuspsess);
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class RootWzsk::DpchEngData
 ******************************************************************************/

RootWzsk::DpchEngData::DpchEngData() :
			DpchEngWzsk(VecWzskVDpch::DPCHENGROOTWZSKDATA)
		{
	feedFEnsSps.tag = "FeedFEnsSps";
};

string RootWzsk::DpchEngData::getSrefsMask() {
	vector<string> ss;
	string srefs;

	if (has(SCRJREF)) ss.push_back("scrJref");
	if (has(FEEDFENSSPS)) ss.push_back("feedFEnsSps");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

void RootWzsk::DpchEngData::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchEngRootWzskData");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
		if (feedFEnsSps.readXML(docctx, basexpath, true)) add(FEEDFENSSPS);
	} else {
		feedFEnsSps.clear();
	};
};

