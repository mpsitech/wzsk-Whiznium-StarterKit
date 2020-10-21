/**
	* \file JobWzskAcqPreview_blks.cpp
	* job handler for job JobWzskAcqPreview (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskAcqPreview::VecVSge
 ******************************************************************************/

uint JobWzskAcqPreview::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "ready") return READY;
	if (s == "prcidle") return PRCIDLE;
	if (s == "process") return PROCESS;

	return(0);
};

string JobWzskAcqPreview::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == READY) return("ready");
	if (ix == PRCIDLE) return("prcidle");
	if (ix == PROCESS) return("process");

	return("");
};

void JobWzskAcqPreview::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 4; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

/******************************************************************************
 class JobWzskAcqPreview::VecVVar
 ******************************************************************************/

uint JobWzskAcqPreview::VecVVar::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "gray") return GRAY;
	if (s == "redgreenblue") return REDGREENBLUE;

	return(0);
};

string JobWzskAcqPreview::VecVVar::getSref(
			const uint ix
		) {
	if (ix == GRAY) return("gray");
	if (ix == REDGREENBLUE) return("redGreenBlue");

	return("");
};

void JobWzskAcqPreview::VecVVar::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 2; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

