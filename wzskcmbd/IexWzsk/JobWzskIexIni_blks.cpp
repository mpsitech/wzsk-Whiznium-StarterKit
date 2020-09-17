/**
	* \file JobWzskIexIni_blks.cpp
	* job handler for job JobWzskIexIni (implementation of blocks)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskIexIni::VecVSge
 ******************************************************************************/

uint JobWzskIexIni::VecVSge::getIx(
			const string& sref
		) {
	string s = StrMod::lc(sref);

	if (s == "idle") return IDLE;
	if (s == "parse") return PARSE;
	if (s == "prserr") return PRSERR;
	if (s == "prsdone") return PRSDONE;
	if (s == "import") return IMPORT;
	if (s == "imperr") return IMPERR;
	if (s == "reverse") return REVERSE;
	if (s == "collect") return COLLECT;
	if (s == "cltdone") return CLTDONE;
	if (s == "export") return EXPORT;
	if (s == "done") return DONE;

	return(0);
};

string JobWzskIexIni::VecVSge::getSref(
			const uint ix
		) {
	if (ix == IDLE) return("idle");
	if (ix == PARSE) return("parse");
	if (ix == PRSERR) return("prserr");
	if (ix == PRSDONE) return("prsdone");
	if (ix == IMPORT) return("import");
	if (ix == IMPERR) return("imperr");
	if (ix == REVERSE) return("reverse");
	if (ix == COLLECT) return("collect");
	if (ix == CLTDONE) return("cltdone");
	if (ix == EXPORT) return("export");
	if (ix == DONE) return("done");

	return("");
};

void JobWzskIexIni::VecVSge::fillFeed(
			Feed& feed
		) {
	feed.clear();

	for (unsigned int i = 1; i <= 11; i++) feed.appendIxSrefTitles(i, getSref(i), getSref(i));
};

