/**
	* \file PnlWzskNavOp_evals.cpp
	* job handler for job PnlWzskNavOp (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

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

