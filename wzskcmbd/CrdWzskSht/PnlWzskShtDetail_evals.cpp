/**
	* \file PnlWzskShtDetail_evals.cpp
	* job handler for job PnlWzskShtDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskShtDetail::evalButSaveAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccShtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtDetail::evalButSaveActive(
			DbsWzsk* dbswzsk
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtDetail::evalTxtSesActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccShtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtDetail::evalButSesViewAvail(
			DbsWzsk* dbswzsk
		) {
	// sht.sesEq(0)|(pre.ixCrdaccSes())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSht.refWzskMSession == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskShtDetail::evalButSesViewActive(
			DbsWzsk* dbswzsk
		) {
	// !sht.sesEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSht.refWzskMSession == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzskShtDetail::evalTxtObjActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccShtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtDetail::evalButObjViewAvail(
			DbsWzsk* dbswzsk
		) {
	// sht.objEq(0)|(pre.ixCrdaccObj())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSht.refWzskMObject == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskShtDetail::evalButObjViewActive(
			DbsWzsk* dbswzsk
		) {
	// !sht.objEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSht.refWzskMObject == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzskShtDetail::evalTxfStaActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccShtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtDetail::evalTxfCmtActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccShtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

