/**
	* \file PnlWzskFilRec_evals.cpp
	* job handler for job PnlWzskFilRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskFilRec::evalButRegularizeActive(
			DbsWzsk* dbswzsk
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

