/**
	* \file CrdWzskNav_evals.cpp
	* job handler for job CrdWzskNav (implementation of availability/activation evaluation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool CrdWzskNav::evalPnlpreAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.refObj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalPnladminAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsg()|pre.ixCrdaccUsr()|pre.ixCrdaccPrs()|pre.ixCrdaccScf()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSCF, jref) != 0);
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
	// pre.ixCrdaccLlv()|pre.ixCrdaccLiv()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLIV, jref) != 0);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalPnlgaleryAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgr()|pre.ixCrdaccObj()|pre.ixCrdaccSes()|pre.ixCrdaccSht()|pre.ixCrdaccFil()

	vector<bool> args;
	bool a, b;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) != 0);
	args.push_back(a);
	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalMitSesSpsAvail(
			DbsWzsk* dbswzsk
		) {
	// stgwzskappearance.suspsessEq(true)

	vector<bool> args;
	bool a;

	a = false; a = (xchg->stgwzskappearance.suspsess == true);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMspCrd1Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdUsgAvail()|MitCrdUsrAvail()|MitCrdPrsAvail()|MitCrdScfAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdUsgAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdUsrAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdPrsAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdScfAvail(dbswzsk);
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

bool CrdWzskNav::evalMitCrdScfAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccScf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSCF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMspCrd2Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdLlvAvail()|MitCrdLivAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdLlvAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdLivAvail(dbswzsk);
	args.push_back(a);
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

bool CrdWzskNav::evalMitCrdLivAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLiv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLIV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMspCrd3Avail(
			DbsWzsk* dbswzsk
		) {
	// MitCrdOgrAvail()|MitCrdObjAvail()|MitCrdSesAvail()|MitCrdShtAvail()|MitCrdFilAvail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMitCrdOgrAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdObjAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdSesAvail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMitCrdShtAvail(dbswzsk);
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
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdOgrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdObjAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdSesAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSes()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool CrdWzskNav::evalMitCrdShtAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
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

	a = false; {uint cnt = 0; dbswzsk->loadUintBySQL("SELECT COUNT(ref) FROM TblWzskMUser WHERE sref <> 'temp'", cnt); a = (cnt == 0);};
	args.push_back(a);

	return(args.back());
};

