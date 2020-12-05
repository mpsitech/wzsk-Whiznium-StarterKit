/**
	* \file PnlWzskNavAdmin_evals.cpp
	* job handler for job PnlWzskNavAdmin (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskNavAdmin::evalLstUsgAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavAdmin::evalButUsgViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstUsg.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsg != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavAdmin::evalLstUsrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavAdmin::evalButUsrViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstUsr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstUsr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavAdmin::evalLstPrsAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavAdmin::evalButPrsViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstPrs.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstPrs != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavAdmin::evalButScfNewcrdAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccScf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSCF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

