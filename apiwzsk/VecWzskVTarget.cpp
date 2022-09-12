/**
	* \file VecWzskVTarget.cpp
	* vector VecWzskVTarget (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 25 Oct 2021
  */
// IP header --- ABOVE

#include "VecWzskVTarget.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVTarget
 ******************************************************************************/

uint VecWzskVTarget::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "apalis") return APALIS;
	if (s == "arty") return ARTY;
	if (s == "clnxevb") return CLNXEVB;
	if (s == "icicle") return ICICLE;
	if (s == "mcvevp") return MCVEVP;
	if (s == "mercbb") return MERCBB;
	if (s == "ws") return WS;

	return(0);
};

string VecWzskVTarget::getSref(
			const uint ix
		) {
	if (ix == APALIS) return("apalis");
	if (ix == ARTY) return("arty");
	if (ix == CLNXEVB) return("clnxevb");
	if (ix == ICICLE) return("icicle");
	if (ix == MCVEVP) return("mcvevp");
	if (ix == MERCBB) return("mercbb");
	if (ix == WS) return("ws");

	return("");
};
