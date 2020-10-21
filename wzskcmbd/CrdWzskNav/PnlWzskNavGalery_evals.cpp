/**
	* \file PnlWzskNavGalery_evals.cpp
	* job handler for job PnlWzskNavGalery (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskNavGalery::evalLstOgrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalButOgrViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstOgr.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstOgr != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalLstObjAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalButObjViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstObj.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstObj != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalLstSesAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSes()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalButSesViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstSes.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSes != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalLstShtAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalButShtViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstSht.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstSht != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalLstFilAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavGalery::evalButFilViewActive(
			DbsWzsk* dbswzsk
		) {
	// LstFil.sel()

	vector<bool> args;
	bool a;

	a = false; a = (contiac.numFLstFil != 0);
	args.push_back(a);

	return(args.back());
};

