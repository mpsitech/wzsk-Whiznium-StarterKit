/**
	* \file PnlWzskSesRec_evals.cpp
	* job handler for job PnlWzskSesRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskSesRec::evalButRegularizeActive(
			DbsWzsk* dbswzsk
		) {
	// pre.refSes()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSES, jref) != 0);
	args.push_back(a);

	return(args.back());
};

