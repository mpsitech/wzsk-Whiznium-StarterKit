/**
	* \file PnlWzskShtRef1NFile_evals.cpp
	* job handler for job PnlWzskShtRef1NFile (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskShtRef1NFile::evalButViewAvail(
			DbsWzsk* dbswzsk
		) {
	// !sel()|((pre.ixCrdaccFil()&pre.refObj())|(pre.ixCrdaccFil()))

	vector<bool> args;
	bool a, b;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);
	a = args.back(); args.pop_back();
	args.push_back(!a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskShtRef1NFile::evalButViewActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtRef1NFile::evalButNewAvail(
			DbsWzsk* dbswzsk
		) {
	// (pre.ixCrdaccFilIncl(edit)&pre.refObj())|(pre.ixCrdaccFilIncl(edit))

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);
	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a && b);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskShtRef1NFile::evalButDeleteAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccShtIncl(edit)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) & VecWzskWAccess::EDIT);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskShtRef1NFile::evalButDeleteActive(
			DbsWzsk* dbswzsk
		) {
	// sel()

	vector<bool> args;
	bool a;

	a = false; a = (qry->stgiac.jnum != 0);
	args.push_back(a);

	return(args.back());
};
