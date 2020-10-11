/**
	* \file VecWzskVReqitmode.cpp
	* vector VecWzskVReqitmode (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#include "VecWzskVReqitmode.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace VecWzskVReqitmode
 ******************************************************************************/

uint VecWzskVReqitmode::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "notify") return NOTIFY;
	if (s == "poll") return POLL;

	return(0);
};

string VecWzskVReqitmode::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == NOTIFY) return("notify");
	if (ix == POLL) return("poll");

	return("");
};

