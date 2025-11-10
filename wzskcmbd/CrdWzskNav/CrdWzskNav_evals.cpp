/**
	* \file CrdWzskNav_evals.cpp
	* job handler for job CrdWzskNav (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWzskNav::evalPnladminAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()|pre.ixCrdaccPrf()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRF, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalPnlopAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLlv()|pre.ixCrdaccVtr()|pre.ixCrdaccHwc()|pre.ixCrdaccFil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCVTR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCHWC, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalMitSesSpsAvail(
			DbsWzsk* dbswzsk
		) {
	// stgwzskbehavior.suspsessEq(true)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwzskbehavior.suspsess == true);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMspCrd1Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdPrfAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdPrfAvail(dbswzsk);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdUsgAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdUsrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdPrsAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdPrfAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMspCrd2Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdLlvAvail()|MitCrdVtrAvail()|MitCrdHwcAvail()|MitCrdFilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdLlvAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdVtrAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdHwcAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdFilAvail(dbswzsk);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdLlvAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLlv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdVtrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccVtr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCVTR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdHwcAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccHwc()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCHWC, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdFilAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMspApp2Avail(
			DbsWzsk* dbswzsk
		) {
	// MitAppLoiAvail()

	vector<bool> args;
	bool a;

	a = false; a = evalMitAppLoiAvail(dbswzsk);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitAppLoiAvail(
			DbsWzsk* dbswzsk
		) {
	// virgin()

	vector<bool> args;
	bool a;

	a = false; {ubigint ref = 0; a = dbswzsk->loadRefBySQL("SELECT ref FROM TblWzskMUsergroup WHERE ref = " + to_string(xchg->getRefPreset(VecWzskVPreset::PREWZSKGROUP, jref)) + " AND sref = 'temp'", ref);};
	args.push_back(a);

	return(args.back());
};
