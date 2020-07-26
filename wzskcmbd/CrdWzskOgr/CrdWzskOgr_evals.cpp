/**
	* \file CrdWzskOgr_evals.cpp
	* job handler for job CrdWzskOgr (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWzskOgr::evalMspCrd1Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdNewAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitCrdNewAvail(dbswzsk);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskOgr::evalMitCrdNewAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

