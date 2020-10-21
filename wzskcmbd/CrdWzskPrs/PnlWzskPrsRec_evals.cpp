/**
	* \file PnlWzskPrsRec_evals.cpp
	* job handler for job PnlWzskPrsRec (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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

