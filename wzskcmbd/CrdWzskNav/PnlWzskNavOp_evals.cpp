/**
	* \file PnlWzskNavOp_evals.cpp
	* job handler for job PnlWzskNavOp (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskNavOp::evalButLlvNewcrdAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLlv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavOp::evalButLivNewcrdAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLiv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLIV, jref) != 0);
	args.push_back(a);

	return(args.back());
};
