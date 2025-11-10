/**
	* \file VecWzskVQrystate.cpp
	* vector VecWzskVQrystate (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "VecWzskVQrystate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVQrystate
 ******************************************************************************/

uint VecWzskVQrystate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "mnr") return MNR;
	if (s == "ood") return OOD;
	if (s == "slm") return SLM;
	if (s == "utd") return UTD;

	return(0);
};

string VecWzskVQrystate::getSref(
			const uint ix
		) {
	if (ix == MNR) return("mnr");
	if (ix == OOD) return("ood");
	if (ix == SLM) return("slm");
	if (ix == UTD) return("utd");

	return("");
};

string VecWzskVQrystate::getTitle(
			const uint ix
			, const uint ixWzskVLocale
		) {
	if (ixWzskVLocale == 1) {
		if (ix == MNR) return("might need refresh");
		if (ix == OOD) return("out of date");
		if (ix == SLM) return("slightly modified");
		if (ix == UTD) return("up to date");
		return(getSref(ix));
	};

	return("");
};

void VecWzskVQrystate::fillFeed(
			const uint ixWzskVLocale
			, Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getTitle(i, ixWzskVLocale));
};
