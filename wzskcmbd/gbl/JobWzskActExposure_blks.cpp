/**
	* \file JobWzskActExposure_blks.cpp
	* job handler for job JobWzskActExposure (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskActExposure::VecVMethod
 ******************************************************************************/

uint JobWzskActExposure::VecVMethod::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "setexposure") return SETEXPOSURE;
	if (s == "setfocus") return SETFOCUS;

	return(0);
};

string JobWzskActExposure::VecVMethod::getSref(
			const uint ix
		) {
	if (ix == SETEXPOSURE) return("setExposure");
	if (ix == SETFOCUS) return("setFocus");

	return("");
};

void JobWzskActExposure::VecVMethod::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskActExposure::VecVVar
 ******************************************************************************/

uint JobWzskActExposure::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "autonotmanualtexp") return AUTONOTMANUALTEXP;
	if (s == "focus") return FOCUS;

	return(0);
};

string JobWzskActExposure::VecVVar::getSref(
			const uint ix
		) {
	if (ix == AUTONOTMANUALTEXP) return("autoNotManualTexp");
	if (ix == FOCUS) return("focus");

	return("");
};

void JobWzskActExposure::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};
