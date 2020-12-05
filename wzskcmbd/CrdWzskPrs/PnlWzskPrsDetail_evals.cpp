/**
	* \file PnlWzskPrsDetail_evals.cpp
	* job handler for job PnlWzskPrsDetail (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskPrsDetail::evalButSaveAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalButSaveActive(
			DbsWzsk* dbswzsk
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalTxfTitActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalTxfFnmActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalPupJActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalButJEditAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalTxtLnmActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalLstDrvActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalPupSexActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalTxfTelActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalTxfEmlActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskPrsDetail::evalTxfSalActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrsIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

