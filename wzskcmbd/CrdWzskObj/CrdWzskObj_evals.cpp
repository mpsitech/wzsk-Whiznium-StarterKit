/**
	* \file CrdWzskObj_evals.cpp
	* job handler for job CrdWzskObj (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWzskObj::evalMspCrd1Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswzsk);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskObj::evalMitCrdNewAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

