/**
	* \file PnlWzskUsgRec_evals.cpp
	* job handler for job PnlWzskUsgRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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

