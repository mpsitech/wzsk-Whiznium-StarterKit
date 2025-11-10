/**
	* \file VecWzskVStub.cpp
	* vector VecWzskVStub (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "VecWzskVStub.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVStub
 ******************************************************************************/

uint VecWzskVStub::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "stubwzskfilstd") return STUBWZSKFILSTD;
	if (s == "stubwzskprsstd") return STUBWZSKPRSSTD;
	if (s == "stubwzsksesmenu") return STUBWZSKSESMENU;
	if (s == "stubwzsksesstd") return STUBWZSKSESSTD;
	if (s == "stubwzskowner") return STUBWZSKOWNER;
	if (s == "stubwzskusrstd") return STUBWZSKUSRSTD;
	if (s == "stubwzskgroup") return STUBWZSKGROUP;
	if (s == "stubwzskusgstd") return STUBWZSKUSGSTD;

	return(0);
};

string VecWzskVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWZSKFILSTD) return("StubWzskFilStd");
	if (ix == STUBWZSKPRSSTD) return("StubWzskPrsStd");
	if (ix == STUBWZSKSESMENU) return("StubWzskSesMenu");
	if (ix == STUBWZSKSESSTD) return("StubWzskSesStd");
	if (ix == STUBWZSKOWNER) return("StubWzskOwner");
	if (ix == STUBWZSKUSRSTD) return("StubWzskUsrStd");
	if (ix == STUBWZSKGROUP) return("StubWzskGroup");
	if (ix == STUBWZSKUSGSTD) return("StubWzskUsgStd");

	return("");
};
