/**
	* \file PnlWzskNavPre_evals.cpp
	* job handler for job PnlWzskNavPre (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskNavPre::evalTxtObjAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.refObj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

