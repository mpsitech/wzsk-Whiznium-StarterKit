/**
	* \file PnlWzskPrsRec_evals.cpp
	* job handler for job PnlWzskPrsRec (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskPrsRec::evalButRegularizeActive(
			DbsWzsk* dbswzsk
		) {
	// pre.refPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};
