/**
	* \file VecWzskVExpstate.cpp
	* vector VecWzskVExpstate (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#include "VecWzskVExpstate.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVExpstate
 ******************************************************************************/

uint VecWzskVExpstate::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "detd") return DETD;
	if (s == "maxd") return MAXD;
	if (s == "mind") return MIND;
	if (s == "regd") return REGD;

	return(0);
};

string VecWzskVExpstate::getSref(
			const uint ix
		) {
	if (ix == DETD) return("detd");
	if (ix == MAXD) return("maxd");
	if (ix == MIND) return("mind");
	if (ix == REGD) return("regd");

	return("");
};
