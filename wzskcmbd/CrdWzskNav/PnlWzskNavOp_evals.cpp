/**
	* \file PnlWzskNavOp_evals.cpp
	* job handler for job PnlWzskNavOp (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
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

bool PnlWzskNavOp::evalButVtrNewcrdAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccVtr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCVTR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavOp::evalButHwcNewcrdAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccHwc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCHWC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavOp::evalLstFilAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavOp::evalButFilViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};
