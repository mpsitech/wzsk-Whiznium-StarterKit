/**
	* \file DlgWzskScfTtablecoord_evals.cpp
	* job handler for job DlgWzskScfTtablecoord (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool DlgWzskScfTtablecoord::evalButDneActive(
			DbsWzsk* dbswzsk
		) {
	// sge(idle|done)

	vector<bool> args;
	bool a, b;

	a = false; a = (ixVSge == VecVSge::IDLE);
	args.push_back(a);
	a = false; a = (ixVSge == VecVSge::DONE);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

