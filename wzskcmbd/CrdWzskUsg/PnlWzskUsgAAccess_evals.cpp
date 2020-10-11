/**
	* \file PnlWzskUsgAAccess_evals.cpp
	* job handler for job PnlWzskUsgAAccess (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskUsgAAccess::evalButNewAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgAAccess::evalButDuplicateAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgAAccess::evalButDuplicateActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgAAccess::evalButDeleteAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsgIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskUsgAAccess::evalButDeleteActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

