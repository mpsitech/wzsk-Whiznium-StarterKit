/**
	* \file DlgWzskObjNew_evals.cpp
	* job handler for job DlgWzskObjNew (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWzskObjNew::evalButCncActive(
			DbsWzsk* dbswzsk
		) {
	// !sge(create)

	vector<bool> args;
	bool a;

	a = false; a = (ixVSge == VecVSge::CREATE);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);

	return(args.back());
};

bool DlgWzskObjNew::evalButCreActive(
			DbsWzsk* dbswzsk
		) {
	// sge(idle)&valid()

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = valid;
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);

	return(args.back());
};

