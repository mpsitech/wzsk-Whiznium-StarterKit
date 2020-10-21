/**
	* \file PnlWzskUsgDetail_evals.cpp
	* job handler for job PnlWzskUsgDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskUsgDetail::evalButSaveAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgDetail::evalButSaveActive(
			DbsWzsk* dbswzsk
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgDetail::evalTxtSrfActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgDetail::evalTxfCmtActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

