/**
	* \file JobWzskSrcFpgainfo_blks.cpp
	* job handler for job JobWzskSrcFpgainfo (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 2 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskSrcFpgainfo::VecVSge
 ******************************************************************************/

uint JobWzskSrcFpgainfo::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "run") return RUN;

	return(0);
};

string JobWzskSrcFpgainfo::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == RUN) return("run");

	return("");
};

void JobWzskSrcFpgainfo::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskSrcFpgainfo::VecVVar
 ******************************************************************************/

uint JobWzskSrcFpgainfo::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "hdrdrdhdrdwr") return HDRDRDHDRDWR;
	if (s == "rnddrdrnddwr") return RNDDRDRNDDWR;

	return(0);
};

string JobWzskSrcFpgainfo::VecVVar::getSref(
			const uint ix
		) {
	if (ix == HDRDRDHDRDWR) return("hdrDRdHdrDWr");
	if (ix == RNDDRDRNDDWR) return("rndDRdRndDWr");

	return("");
};

void JobWzskSrcFpgainfo::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};
