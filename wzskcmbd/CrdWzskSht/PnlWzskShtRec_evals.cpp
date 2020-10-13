/**
	* \file PnlWzskShtRec_evals.cpp
	* job handler for job PnlWzskShtRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskShtRec::evalButRegularizeActive(
			DbsWzsk* dbswzsk
		) {
	// pre.refSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

