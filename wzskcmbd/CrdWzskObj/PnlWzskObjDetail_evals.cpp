/**
	* \file PnlWzskObjDetail_evals.cpp
	* job handler for job PnlWzskObjDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskObjDetail::evalButSaveAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskObjDetail::evalButSaveActive(
			DbsWzsk* dbswzsk
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzskObjDetail::evalTxfTitActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskObjDetail::evalTxtOgrActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskObjDetail::evalButOgrViewAvail(
			DbsWzsk* dbswzsk
		) {
	// obj.ogrEq(0)|(pre.ixCrdaccOgr())

	vector<bool> args;
	bool a, b;

	a = false; a = (recObj.refWzskMObjgroup == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskObjDetail::evalButOgrViewActive(
			DbsWzsk* dbswzsk
		) {
	// !obj.ogrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recObj.refWzskMObjgroup == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzskObjDetail::evalTxfCmtActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObjIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

