/**
	* \file PnlWzskObjList_evals.cpp
	* job handler for job PnlWzskObjList (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskObjList::evalButDeleteActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

