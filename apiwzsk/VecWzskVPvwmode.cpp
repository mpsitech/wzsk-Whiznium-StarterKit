/**
	* \file VecWzskVPvwmode.cpp
	* vector VecWzskVPvwmode (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "VecWzskVPvwmode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVPvwmode
 ******************************************************************************/

uint VecWzskVPvwmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "bingray") return BINGRAY;
	if (s == "binreddom") return BINREDDOM;
	if (s == "binrgb") return BINRGB;
	if (s == "rawgray") return RAWGRAY;
	if (s == "rawrgb") return RAWRGB;

	return(0);
};

string VecWzskVPvwmode::getSref(
			const uint ix
		) {
	if (ix == BINGRAY) return("bingray");
	if (ix == BINREDDOM) return("binreddom");
	if (ix == BINRGB) return("binrgb");
	if (ix == RAWGRAY) return("rawgray");
	if (ix == RAWRGB) return("rawrgb");

	return("");
};

