/**
	* \file PnlWzskShtList_evals.cpp
	* job handler for job PnlWzskShtList (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskShtList::evalButDeleteActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

