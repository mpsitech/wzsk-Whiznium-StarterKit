/**
	* \file WzskMPerson_vecs.cpp
	* database access for table TblWzskMPerson (implementation of vectors)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzskMPerson::VecVSex
 ******************************************************************************/

uint TblWzskMPerson::VecVSex::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "f") return F;
	if (s == "m") return M;

	return(0);
};

string TblWzskMPerson::VecVSex::getSref(
			const uint ix
		) {
	if (ix == F) return("f");
	if (ix == M) return("m");

	return("");
};

string TblWzskMPerson::VecVSex::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == F) return("female");
		if (ix == M) return("male");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == F) return("weiblich");
		if (ix == M) return("m\\u00e4nnlich");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblWzskMPerson::VecVSex::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

/******************************************************************************
 class TblWzskMPerson::VecWDerivate
 ******************************************************************************/

uint TblWzskMPerson::VecWDerivate::getIx(
			const string& srefs
		) {
	uint ix = 0;

	vector<string> ss;
	StrMod::srefsToVector(StrMod::lc(srefs), ss);

	for (unsigned int i = 0; i < ss.size(); i++) {
		if (ss[i] == "usr") ix |= USR;
	};

	return(ix);
};

void TblWzskMPerson::VecWDerivate::getIcs(
			const uint ix
			, set<uint>& ics
		) {
	ics.clear();
	for (unsigned int i = 1; i < (2*USR); i *= 2) if (ix & i) ics.insert(i);
};

string TblWzskMPerson::VecWDerivate::getSrefs(
			const uint ix
		) {
	vector<string> ss;
	string srefs;

	if (ix & USR) ss.push_back("usr");

	StrMod::vectorToString(ss, srefs);

	return(srefs);
};

string TblWzskMPerson::VecWDerivate::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == USR) return("user");
		return(getSrefs(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == USR) return("Benutzer");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblWzskMPerson::VecWDerivate::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= USR; i *= 2) feed.appendIxSrefTitles(i, getSrefs(i), getTitle(i, ixWzskVLocale));
};
