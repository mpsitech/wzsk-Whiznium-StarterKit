/**
	* \file RootWzsk.cpp
	* job handler for job RootWzsk (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "RootWzsk.h"

#include "RootWzsk_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

/******************************************************************************
 class RootWzsk
 ******************************************************************************/

RootWzsk::RootWzsk(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const bool _clearAll
		) :
			JobWzsk(xchg, VecWzskVJob::ROOTWZSK, jrefSup, VecWzskVLocale::ENUS)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcv4l2 = NULL;
	srcuvbdvk = NULL;
	srcsysinfo = NULL;
	srcmcvevp = NULL;
	srcicicle = NULL;
	srcclnxevb = NULL;
	srcarty = NULL;
	iprtrace = NULL;
	iprcorner = NULL;
	iprangle = NULL;
	actservo = NULL;
	actlaser = NULL;
	actexposure = NULL;
	acqptcloud = NULL;
	acqpreview = NULL;
	acqfpgapvw = NULL;
	acqfpgaflg = NULL;

	// IP constructor.cust1 --- INSERT

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbswzsk);
	else clearQtb(dbswzsk);

	srcv4l2 = new JobWzskSrcV4l2(xchg, dbswzsk, jref, ixWzskVLocale);
	srcuvbdvk = new JobWzskSrcUvbdvk(xchg, dbswzsk, jref, ixWzskVLocale);
	srcsysinfo = new JobWzskSrcSysinfo(xchg, dbswzsk, jref, ixWzskVLocale);
	srcmcvevp = new JobWzskSrcMcvevp(xchg, dbswzsk, jref, ixWzskVLocale);
	srcicicle = new JobWzskSrcIcicle(xchg, dbswzsk, jref, ixWzskVLocale);
	srcclnxevb = new JobWzskSrcClnxevb(xchg, dbswzsk, jref, ixWzskVLocale);
	srcarty = new JobWzskSrcArty(xchg, dbswzsk, jref, ixWzskVLocale);
	iprtrace = new JobWzskIprTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	iprcorner = new JobWzskIprCorner(xchg, dbswzsk, jref, ixWzskVLocale);
	iprangle = new JobWzskIprAngle(xchg, dbswzsk, jref, ixWzskVLocale);
	actservo = new JobWzskActServo(xchg, dbswzsk, jref, ixWzskVLocale);
	actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);
	actexposure = new JobWzskActExposure(xchg, dbswzsk, jref, ixWzskVLocale);
	acqptcloud = new JobWzskAcqPtcloud(xchg, dbswzsk, jref, ixWzskVLocale);
	acqpreview = new JobWzskAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);
	acqfpgapvw = new JobWzskAcqFpgapvw(xchg, dbswzsk, jref, ixWzskVLocale);
	acqfpgaflg = new JobWzskAcqFpgaflg(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKREFPRESET, jref, Clstn::VecVJobmask::TREE, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	if (xchg->stgwzskappearance.roottterm != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * xchg->stgwzskappearance.roottterm);
};

RootWzsk::~RootWzsk() {
	// log
	xchg->appendToLogfile("root job deleted");

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

void RootWzsk::clearAll(
			DbsWzsk* dbswzsk
		) {
	WzskMUsergroup* usg = NULL;
	WzskRMUserMUsergroup* uru = NULL;
	WzskMUser* usr = NULL;
	WzskMPerson* prs = NULL;

	time_t now;

	string s;

	// empty out tables
	dbswzsk->executeQuery("DELETE FROM TblWzskAccRMUserUniversal");
	dbswzsk->executeQuery("DELETE FROM TblWzskAMPersonDetail");
	dbswzsk->executeQuery("DELETE FROM TblWzskAMShotPar");
	dbswzsk->executeQuery("DELETE FROM TblWzskAMUserAccess");
	dbswzsk->executeQuery("DELETE FROM TblWzskAMUsergroupAccess");
	dbswzsk->executeQuery("DELETE FROM TblWzskAVControlPar");
	dbswzsk->executeQuery("DELETE FROM TblWzskAVKeylistKey");
	dbswzsk->executeQuery("DELETE FROM TblWzskAVValuelistVal");
	if (dbswzsk->ixDbsVDbstype == VecDbsVDbstype::MY) dbswzsk->executeQuery("DELETE FROM TblWzskCFile");
	else if (dbswzsk->ixDbsVDbstype == VecDbsVDbstype::PG) dbswzsk->executeQuery("ALTER SEQUENCE TblWzskCFile RESTART WITH 1");
	dbswzsk->executeQuery("DELETE FROM TblWzskHistRMUserUniversal");
	dbswzsk->executeQuery("DELETE FROM TblWzskJAVKeylistKey");
	dbswzsk->executeQuery("DELETE FROM TblWzskJMObjgroupTitle");
	dbswzsk->executeQuery("DELETE FROM TblWzskJMPersonLastname");
	dbswzsk->executeQuery("DELETE FROM TblWzskJMUserState");
	dbswzsk->executeQuery("DELETE FROM TblWzskMFile");
	dbswzsk->executeQuery("DELETE FROM TblWzskMObject");
	dbswzsk->executeQuery("DELETE FROM TblWzskMObjgroup");
	dbswzsk->executeQuery("DELETE FROM TblWzskMPerson");
	dbswzsk->executeQuery("DELETE FROM TblWzskMSession");
	dbswzsk->executeQuery("DELETE FROM TblWzskMShot");
	dbswzsk->executeQuery("DELETE FROM TblWzskMUser");
	dbswzsk->executeQuery("DELETE FROM TblWzskMUsergroup");
	dbswzsk->executeQuery("DELETE FROM TblWzskRMUsergroupUniversal");
	dbswzsk->executeQuery("DELETE FROM TblWzskRMUserMUsergroup");

	clearQtb(dbswzsk);

	// generate a temporary user such that a session can be generated
	time(&now);

	dbswzsk->tblwzskmusergroup->insertNewRec(&usg, 0, 0, "temp", "temporary user group for system initialization");
	dbswzsk->tblwzskamusergroupaccess->insertNewRec(NULL, usg->ref, VecWzskVFeatgroup::VECWZSKVCARD, "CrdWzskNav", VecWzskWAccess::EDIT + VecWzskWAccess::EXEC + VecWzskWAccess::VIEW);
	dbswzsk->tblwzskrmusermusergroup->insertNewRec(&uru, 0, usg->ref, VecWzskVUserlevel::GADM);
	dbswzsk->tblwzskmuser->insertNewRec(&usr, usg->ref, 0, uru->ref, usg->ref, 0, "temp", 0, VecWzskVMUserState::DUE, VecWzskVLocale::ENUS, VecWzskVUserlevel::GADM, "asdf1234", "", "temporary user for system initialization");
	usr->refJState = dbswzsk->tblwzskjmuserstate->insertNewRec(NULL, usr->ref, 0, VecWzskVMUserState::DUE);
	dbswzsk->tblwzskjmuserstate->insertNewRec(NULL, usr->ref, now + 24*3600, VecWzskVMUserState::EXP);
	usr->refWzskMPerson = dbswzsk->tblwzskmperson->insertNewRec(&prs, usg->ref, usr->ref, VecWzskWMPersonDerivate::USR, VecWzskVMPersonSex::M, "Mr.", "Jack", 0, "Smith", 0, "", 0, "", "Dear Jack");

	prs->refJLastname = dbswzsk->tblwzskjmpersonlastname->insertNewRec(NULL, prs->ref, 0, "Smith");

	usg->grp = usg->ref;
	usg->own = usr->ref;
	dbswzsk->tblwzskmusergroup->updateRec(usg);

	uru->refWzskMUser = usr->ref;
	dbswzsk->tblwzskrmusermusergroup->updateRec(uru);

	dbswzsk->tblwzskmuser->updateRec(usr);

	dbswzsk->tblwzskmperson->updateRec(prs);

	cout << "\ttemporary account created for user 'temp', expires " << Ftm::stamp(now + 24*3600) << "; use password 'asdf1234' to log in" << endl;

	xchg->appendToLogfile("database cleared");

	delete usg;
	delete uru;
	delete usr;
	delete prs;
};

void RootWzsk::clearQtb(
			DbsWzsk* dbswzsk
		) {
	dbswzsk->executeQuery("DELETE FROM TblWzskQFilList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQObj1NShot");
	dbswzsk->executeQuery("DELETE FROM TblWzskQObjList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQObjRef1NFile");
	dbswzsk->executeQuery("DELETE FROM TblWzskQOgr1NObject");
	dbswzsk->executeQuery("DELETE FROM TblWzskQOgrList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQOgrSup1NObjgroup");
	dbswzsk->executeQuery("DELETE FROM TblWzskQPreselect");
	dbswzsk->executeQuery("DELETE FROM TblWzskQPrsADetail");
	dbswzsk->executeQuery("DELETE FROM TblWzskQPrsList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQSelect");
	dbswzsk->executeQuery("DELETE FROM TblWzskQSes1NShot");
	dbswzsk->executeQuery("DELETE FROM TblWzskQSesList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQShtAPar");
	dbswzsk->executeQuery("DELETE FROM TblWzskQShtList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQShtRef1NFile");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsgAAccess");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsgList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsgMNUser");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsr1NSession");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsrAAccess");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsrList");
	dbswzsk->executeQuery("DELETE FROM TblWzskQUsrMNUsergroup");
};

bool RootWzsk::authenticate(
			DbsWzsk* dbswzsk
			, const string& username
			, const string& password
			, ubigint& refWzskMUser
		) {
	bool valid = false;

	ubigint ref;

	WzskMUser* usr = NULL;

	time_t now;

	refWzskMUser = 0;

	if (dbswzsk->tblwzskmuser->loadRecBySrfPwd(username, password, &usr)) {
		if ((usr->ixVState == VecWzskVMUserState::DSG) || (usr->ixVState == VecWzskVMUserState::DUE)) {
			// check if expired
			time(&now);

			if (dbswzsk->loadRefBySQL("SELECT ref FROM TblWzskJMUserState WHERE refWzskMUser = " + to_string(usr->ref) + " AND x1Start < " + to_string(now) + " AND ixVState = " + to_string(VecWzskVMUserState::EXP) + " ORDER BY x1Start DESC LIMIT 1", ref)) {
				usr->refJState = ref;
				usr->ixVState = VecWzskVMUserState::EXP;
				dbswzsk->tblwzskmuser->updateRec(usr);
			};
		};

		valid = ((usr->ixVState == VecWzskVMUserState::ACT) || (usr->ixVState == VecWzskVMUserState::DUE));

		if (valid) refWzskMUser = usr->ref;

		delete usr;
	};

	return valid;
};

void RootWzsk::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\tclearAll" << endl;
			cout << "\tcreateSess" << endl;
			cout << "\teraseSess" << endl;
			cout << "\ttest" << endl;
		} else if (req->cmd == "clearAll") {
			req->retain = handleClearAll(dbswzsk);

		} else if (req->cmd == "createSess") {
			req->retain = handleCreateSess(dbswzsk);

		} else if (req->cmd == "eraseSess") {
			req->retain = handleEraseSess(dbswzsk);

		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPROOTWZSKLOGIN) {
			handleDpchAppLogin(dbswzsk, (DpchAppLogin*) (req->dpchapp), req->ip, &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (req->sref == "warnterm") handleTimerWithSrefWarnterm(dbswzsk);
	};
};

bool RootWzsk::handleClearAll(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	clearAll(dbswzsk);
	return retval;
};

bool RootWzsk::handleCreateSess(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	string input;
	string input2;

	ubigint refUsr;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbswzsk, input, input2, refUsr)) {
		xchg->jrefCmd = insertSubjob(sesss, new SessWzsk(xchg, dbswzsk, jref, refUsr, "127.0.0.1"));
		cout << "\tjob reference: " << xchg->jrefCmd << endl;

		if ((xchg->stgwzskappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwzskappearance.sesstterm - xchg->stgwzskappearance.sesstwarn));

		xchg->appendToLogfile("command line session created for user '" + input + "'");

	} else {
		cout << "\tlogin failed." << endl;

		xchg->appendToLogfile("command line login refused for user '" + input + "'");
	};

	return retval;
};

bool RootWzsk::handleEraseSess(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;

	string input;
	ubigint iinput;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	if (!eraseSubjobByJref(sesss, iinput)) cout << "\tjob reference doesn't exist!" << endl;
	else cout << "\tsession erased." << endl;

	return retval;
};

bool RootWzsk::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void RootWzsk::handleDpchAppLogin(
			DbsWzsk* dbswzsk
			, DpchAppLogin* dpchapplogin
			, const string ip
			, DpchEngWzsk** dpcheng
		) {
	ubigint refUsr;

	ubigint jrefSess;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbswzsk, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgwzskappearance.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					jrefSess = it->second->jref;

					if (xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jrefSess) == refUsr) {
						if (xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKSUSPSESS, jrefSess)) {
							xchg->addTxtvalPreset(VecWzskVPreset::PREWZSKIP, jrefSess, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(jrefSess), StubWzsk::getStubSesStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKSESS, jrefSess)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				jrefSess = insertSubjob(sesss, new SessWzsk(xchg, dbswzsk, jref, refUsr, ip));

				if ((xchg->stgwzskappearance.sesstterm != 0) && (sesss.size() == 1)) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (xchg->stgwzskappearance.sesstterm - xchg->stgwzskappearance.sesstwarn));

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngWzskConfirm(true, jrefSess, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		} else {
			jrefSess = insertSubjob(m2msesss, new M2msessWzsk(xchg, dbswzsk, jref, refUsr, ip));

			xchg->appendToLogfile("M2M session created for user '" + dpchapplogin->username + "' from IP " + ip);

			*dpcheng = new DpchEngWzskConfirm(true, jrefSess, "");
		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngWzskConfirm(false, 0, "");
	};
};

void RootWzsk::handleTimerWithSrefWarnterm(
			DbsWzsk* dbswzsk
		) {
	SessWzsk* sess = NULL;

	time_t tlast;
	time_t tnext = 0;

	time_t rawtime;
	time(&rawtime);

	bool term;

	if (xchg->stgwzskappearance.sesstterm != 0) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = (SessWzsk*) it->second;

			term = false;

			tlast = xchg->getRefPreset(VecWzskVPreset::PREWZSKTLAST, sess->jref);

			if ((tlast + ((int) xchg->stgwzskappearance.sesstterm)) <= rawtime) term = true;
			else if ((tlast + ((int) xchg->stgwzskappearance.sesstterm) - ((int) xchg->stgwzskappearance.sesstwarn)) <= rawtime) {
				sess->warnTerm(dbswzsk);
				if ((tnext == 0) || ((tlast + ((int) xchg->stgwzskappearance.sesstterm)) < tnext)) tnext = tlast + ((int) xchg->stgwzskappearance.sesstterm);
			} else if ((tnext == 0) || ((tlast + ((int) xchg->stgwzskappearance.sesstterm) - ((int) xchg->stgwzskappearance.sesstwarn)) < tnext)) tnext = tlast + xchg->stgwzskappearance.sesstterm - xchg->stgwzskappearance.sesstwarn;

			if (term) {
				sess->term(dbswzsk);
				it = sesss.erase(it);

				delete sess;

			} else it++;
		};
	};

	term = false;

	if (xchg->stgwzskappearance.roottterm != 0) {
		tlast = xchg->getRefPreset(VecWzskVPreset::PREWZSKTLAST, jref);

		if ((tlast + ((int) xchg->stgwzskappearance.roottterm)) <= rawtime) term = true;
		else if ((tnext == 0) || ((tlast + ((int) xchg->stgwzskappearance.roottterm)) < tnext)) tnext = tlast + xchg->stgwzskappearance.roottterm;
	};

	if (term) {
		cout << endl << "\tterminating due to inactivity" << endl;
		kill(getpid(), SIGTERM);
	} else if (tnext != 0) wrefLast = xchg->addWakeup(jref, "warnterm", 1e6 * (tnext - rawtime));
};

void RootWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSUSPSESS) {
		call->abort = handleCallWzskSuspsess(dbswzsk, call->jref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKREFPRESET) {
		call->abort = handleCallWzskRefPreSet(dbswzsk, call->jref, call->argInv.ix, call->argInv.ref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKLOGOUT) {
		call->abort = handleCallWzskLogout(dbswzsk, call->jref, call->argInv.boolval);
	};
};

bool RootWzsk::handleCallWzskSuspsess(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;

	xchg->addBoolvalPreset(VecWzskVPreset::PREWZSKSUSPSESS, jrefTrig, true);
	xchg->removeDcolsByJref(jrefTrig);

	return retval;
};

bool RootWzsk::handleCallWzskRefPreSet(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const ubigint refInv
		) {
	bool retval = false;

	if (ixInv == VecWzskVPreset::PREWZSKTLAST) {
		xchg->addRefPreset(ixInv, jref, refInv);
	};

	return retval;
};

bool RootWzsk::handleCallWzskLogout(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	time_t rawtime;

	if (!boolvalInv) {
		eraseSubjobByJref(sesss, jrefTrig);

		if (xchg->stgwzskappearance.roottterm) {
			time(&rawtime);
			xchg->addRefPreset(VecWzskVPreset::PREWZSKTLAST, jref, rawtime);
		};

	} else {
		eraseSubjobByJref(m2msesss, jrefTrig);
	};

	return retval;
};
