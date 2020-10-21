/**
	* \file PnlWzskSes1NShot_evals.cpp
	* job handler for job PnlWzskSes1NShot (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskSes1NShot::evalButViewAvail(
			DbsWzsk* dbswzsk
		) {
	// !sel()|((pre.ixCrdaccSht()&pre.refObj())|(pre.ixCrdaccSht()))

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskSes1NShot::evalButViewActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSes1NShot::evalButNewAvail(
			DbsWzsk* dbswzsk
		) {
	// (pre.ixCrdaccShtIncl(edit)&pre.refObj())|(pre.ixCrdaccShtIncl(edit))

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskSes1NShot::evalButDeleteAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSesIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskSes1NShot::evalButDeleteActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

