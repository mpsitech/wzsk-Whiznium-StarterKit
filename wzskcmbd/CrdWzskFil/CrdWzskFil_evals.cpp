/**
	* \file CrdWzskFil_evals.cpp
	* job handler for job CrdWzskFil (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

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
