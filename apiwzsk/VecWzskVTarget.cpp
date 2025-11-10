/**
	* \file VecWzskVTarget.cpp
	* vector VecWzskVTarget (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
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

	if (s == "disco") return DISCO;
	if (s == "titdvk") return TITDVK;
	if (s == "zudvk") return ZUDVK;

	return(0);
};

string VecWzskVTarget::getSref(
			const uint ix
		) {
	if (ix == DISCO) return("disco");
	if (ix == TITDVK) return("titdvk");
	if (ix == ZUDVK) return("zudvk");

	return("");
};
