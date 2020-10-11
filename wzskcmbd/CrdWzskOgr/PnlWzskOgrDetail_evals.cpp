/**
	* \file PnlWzskOgrDetail_evals.cpp
	* job handler for job PnlWzskOgrDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskOgrDetail::evalButSaveAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalButSaveActive(
			DbsWzsk* dbswzsk
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalTxtSrfActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalPupJActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalButJEditAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalTxtTitActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalTxtSupActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalButSupViewAvail(
			DbsWzsk* dbswzsk
		) {
	// ogr.supEq(0)|(pre.ixCrdaccOgr())

	vector<bool> args;
	bool a, b;

	a = false; a = (recOgr.supRefWzskMObjgroup == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskOgrDetail::evalButSupViewActive(
			DbsWzsk* dbswzsk
		) {
	// !ogr.supEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recOgr.supRefWzskMObjgroup == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzskOgrDetail::evalTxfCmtActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgrIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

