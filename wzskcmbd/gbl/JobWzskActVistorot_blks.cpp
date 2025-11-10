/**
	* \file JobWzskActVistorot_blks.cpp
	* job handler for job JobWzskActVistorot (implementation of blocks)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 class JobWzskActVistorot::Stg
 ******************************************************************************/

JobWzskActVistorot::Stg::Stg(
			const float omegaMax
			, const float P
			, const float I
		) :
			Block()
			, omegaMax(omegaMax)
			, P(P)
			, I(I)
		{
	mask = {OMEGAMAX, _P, _I};
};

bool JobWzskActVistorot::Stg::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "StgJobWzskActVistorot");
	else
		basefound = checkXPath(docctx, basexpath);

	string itemtag = "StgitemJobWzskActVistorot";

	if (basefound) {
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "omegaMax", omegaMax)) add(OMEGAMAX);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "P", P)) add(_P);
		if (extractFloatAttrUclc(docctx, basexpath, itemtag, "Si", "sref", "I", I)) add(_I);
	};

	return basefound;
};

void JobWzskActVistorot::Stg::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "StgJobWzskActVistorot";

	string itemtag;
	if (shorttags) itemtag = "Si";
	else itemtag = "StgitemJobWzskActVistorot";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeFloatAttr(wr, itemtag, "sref", "omegaMax", omegaMax);
		writeFloatAttr(wr, itemtag, "sref", "P", P);
		writeFloatAttr(wr, itemtag, "sref", "I", I);
	xmlTextWriterEndElement(wr);
};

set<uint> JobWzskActVistorot::Stg::comm(
			const Stg* comp
		) {
	set<uint> items;

	if (compareFloat(omegaMax, comp->omegaMax) < 1.0e-4) insert(items, OMEGAMAX);
	if (compareFloat(P, comp->P) < 1.0e-4) insert(items, _P);
	if (compareFloat(I, comp->I) < 1.0e-4) insert(items, _I);

	return(items);
};

set<uint> JobWzskActVistorot::Stg::diff(
			const Stg* comp
		) {
	set<uint> commitems;
	set<uint> diffitems;

	commitems = comm(comp);

	diffitems = {OMEGAMAX, _P, _I};
	for (auto it = commitems.begin(); it != commitems.end(); it++) diffitems.erase(*it);

	return(diffitems);
};
