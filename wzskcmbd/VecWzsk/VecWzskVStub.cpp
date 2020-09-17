/**
	* \file VecWzskVStub.cpp
	* vector VecWzskVStub (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

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

	if (s == "stubwzskshtstd") return STUBWZSKSHTSTD;
	if (s == "stubwzskogrhsref") return STUBWZSKOGRHSREF;
	if (s == "stubwzskogrstd") return STUBWZSKOGRSTD;
	if (s == "stubwzskobjstd") return STUBWZSKOBJSTD;
	if (s == "stubwzskgroup") return STUBWZSKGROUP;
	if (s == "stubwzskusgstd") return STUBWZSKUSGSTD;
	if (s == "stubwzskowner") return STUBWZSKOWNER;
	if (s == "stubwzskusrstd") return STUBWZSKUSRSTD;
	if (s == "stubwzskprsstd") return STUBWZSKPRSSTD;
	if (s == "stubwzsksesmenu") return STUBWZSKSESMENU;
	if (s == "stubwzsksesstd") return STUBWZSKSESSTD;
	if (s == "stubwzskfilstd") return STUBWZSKFILSTD;

	return(0);
};

string VecWzskVStub::getSref(
			const uint ix
		) {
	if (ix == STUBWZSKSHTSTD) return("StubWzskShtStd");
	if (ix == STUBWZSKOGRHSREF) return("StubWzskOgrHsref");
	if (ix == STUBWZSKOGRSTD) return("StubWzskOgrStd");
	if (ix == STUBWZSKOBJSTD) return("StubWzskObjStd");
	if (ix == STUBWZSKGROUP) return("StubWzskGroup");
	if (ix == STUBWZSKUSGSTD) return("StubWzskUsgStd");
	if (ix == STUBWZSKOWNER) return("StubWzskOwner");
	if (ix == STUBWZSKUSRSTD) return("StubWzskUsrStd");
	if (ix == STUBWZSKPRSSTD) return("StubWzskPrsStd");
	if (ix == STUBWZSKSESMENU) return("StubWzskSesMenu");
	if (ix == STUBWZSKSESSTD) return("StubWzskSesStd");
	if (ix == STUBWZSKFILSTD) return("StubWzskFilStd");

	return("");
};

