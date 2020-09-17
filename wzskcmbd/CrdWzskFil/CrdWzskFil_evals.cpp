/**
	* \file CrdWzskFil_evals.cpp
	* job handler for job CrdWzskFil (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWzskFil::evalMitCrdDldAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccFilIncl(exec)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) & VecWzskWAccess::EXEC);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskFil::evalMitCrdDldActive(
			DbsWzsk* dbswzsk
		) {
	// pre.refFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

