/**
	* \file PnlWzskNavHeadbar_evals.cpp
	* job handler for job PnlWzskNavHeadbar (implementation of availability/activation evaluation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

bool PnlWzskNavHeadbar::evalMenCrdAvail(
			DbsWzsk* dbswzsk
		) {
	// MspCrd1Avail()|MspCrd2Avail()|MspCrd3Avail()

	vector<bool> args;
	bool a, b;

	a = false; a = evalMspCrd1Avail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMspCrd2Avail(dbswzsk);
	args.push_back(a);
	a = false; a = evalMspCrd3Avail(dbswzsk);
	args.push_back(a);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);
	b = args.back(); args.pop_back();
	a = args.back(); args.pop_back();
	args.push_back(a || b);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMspCrd1Avail(
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

bool PnlWzskNavHeadbar::evalMitCrdUsgAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsg()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSG, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdUsrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccUsr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCUSR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdPrsAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccPrs()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCPRS, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdScfAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccScf()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSCF, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMspCrd2Avail(
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

bool PnlWzskNavHeadbar::evalMitCrdLlvAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLlv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLLV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdLivAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccLiv()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCLIV, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMspCrd3Avail(
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

bool PnlWzskNavHeadbar::evalMitCrdOgrAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccOgr()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOGR, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdObjAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccObj()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCOBJ, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdSesAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSes()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSES, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdShtAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccSht()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCSHT, jref) != 0);
	args.push_back(a);

	return(args.back());
};

bool PnlWzskNavHeadbar::evalMitCrdFilAvail(
			DbsWzsk* dbswzsk
		) {
	// pre.ixCrdaccFil()

	vector<bool> args;
	bool a;

	a = false; a = (xchg->getIxPreset(VecWzskVPreset::PREWZSKIXCRDACCFIL, jref) != 0);
	args.push_back(a);

	return(args.back());
};

