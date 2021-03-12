/**
	* \file PnlWzskNavGlry_evals.cpp
	* job handler for job PnlWzskNavGlry (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 11 Mar 2021
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskNavGlry::evalLstOgrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalButOgrViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstOgr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOgr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalLstObjAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalButObjViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstObj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstObj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalLstSesAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSes()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalButSesViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstSes.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSes != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalLstShtAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalButShtViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstSht.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSht != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalLstFilAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGlry::evalButFilViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};
