/**
	* \file PnlWzskUsgRec_evals.cpp
	* job handler for job PnlWzskUsgRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskUsgRec::evalButRegularizeActive(
			DbsWzsk* dbswzsk
		) {
	// pre.refUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};
