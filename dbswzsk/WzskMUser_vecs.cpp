/**
	* \file WzskMUser_vecs.cpp
	* database access for table TblWzskMUser (implementation of vectors)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class TblWzskMUser::VecVState
 ******************************************************************************/

uint TblWzskMUser::VecVState::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "act") return ACT;
	if (s == "dsg") return DSG;
	if (s == "due") return DUE;
	if (s == "exp") return EXP;

	return(0);
};

string TblWzskMUser::VecVState::getSref(
			const uint ix
		) {
	if (ix == ACT) return("act");
	if (ix == DSG) return("dsg");
	if (ix == DUE) return("due");
	if (ix == EXP) return("exp");

	return("");
};

string TblWzskMUser::VecVState::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == ACT) return("active");
		if (ix == DSG) return("designated");
		if (ix == DUE) return("due for expiration");
		if (ix == EXP) return("expired");
		return(getSref(ix));
	} else if (ixWzskVLocale == 2) {
		if (ix == ACT) return("aktiv");
		if (ix == DSG) return("vorgesehen");
		if (ix == DUE) return("l\\u00e4uft ab");
		if (ix == EXP) return("abgelaufen");
		return(getTitle(ix, 1));
	};

	return("");
};

void TblWzskMUser::VecVState::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};

