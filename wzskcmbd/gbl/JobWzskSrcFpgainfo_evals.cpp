/**
	* \file JobWzskSrcFpgainfo_evals.cpp
	* job handler for job JobWzskSrcFpgainfo (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Oct 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool JobWzskSrcFpgainfo::evalSrcdcvspConstr(
			DbsWzsk* dbswzsk
		) {
	// stgwzskglobal.ixwzskvtargetEq(disco)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::DISCO);
	args.push_back(a);

	return(args.back());
};

bool JobWzskSrcFpgainfo::evalSrctivspConstr(
			DbsWzsk* dbswzsk
		) {
	// stgwzskglobal.ixwzskvtargetEq(titdvk)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::TITDVK);
	args.push_back(a);

	return(args.back());
};

bool JobWzskSrcFpgainfo::evalSrczuvspConstr(
			DbsWzsk* dbswzsk
		) {
	// stgwzskglobal.ixwzskvtargetEq(zudvk)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::ZUDVK);
	args.push_back(a);

	return(args.back());
};
