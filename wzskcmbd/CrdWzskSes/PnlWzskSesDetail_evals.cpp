/**
	* \file PnlWzskSesDetail_evals.cpp
	* job handler for job PnlWzskSesDetail (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskSesDetail::evalButSaveAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSesIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSesDetail::evalButSaveActive(
			DbsWzsk* dbswzsk
		) {
	// dirty()

	vector<bool> args;
	bool a;

	a = false; a = dirty;
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSesDetail::evalTxtUsrActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSesIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSesDetail::evalButUsrViewAvail(
			DbsWzsk* dbswzsk
		) {
	// ses.usrEq(0)|(pre.ixCrdaccUsr())

	vector<bool> args;
	bool a, b;

	a = false; a = (recSes.refWzskMUser == 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskSesDetail::evalButUsrViewActive(
			DbsWzsk* dbswzsk
		) {
	// !ses.usrEq(0)

	vector<bool> args;
	bool a;

	a = false; a = (recSes.refWzskMUser == 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool PnlWzskSesDetail::evalTxfStaActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSesIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSesDetail::evalTxfStoActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSesIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSesDetail::evalTxfIpActive(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSesIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

