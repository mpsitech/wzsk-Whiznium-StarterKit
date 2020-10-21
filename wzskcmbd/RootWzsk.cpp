/**
	* \file RootWzsk.cpp
	* job handler for job RootWzsk (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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
	srcsysinfo = NULL;
	srcfpga = NULL;
	iprcorner = NULL;
	iprtrace = NULL;
	actservo = NULL;
	iprangle = NULL;
	actlaser = NULL;
	actexposure = NULL;
	acqptcloud = NULL;
	acqpreview = NULL;
	acqfpgaflg = NULL;
	acqfpgapvw = NULL;

	// IP constructor.cust1 --- INSERT

	// log
	xchg->appendToLogfile("root job created");

	if (_clearAll) clearAll(dbswzsk);
	else clearQtb(dbswzsk);

	srcv4l2 = new JobWzskSrcV4l2(xchg, dbswzsk, jref, ixWzskVLocale);
	srcsysinfo = new JobWzskSrcSysinfo(xchg, dbswzsk, jref, ixWzskVLocale);
	srcfpga = new JobWzskSrcFpga(xchg, dbswzsk, jref, ixWzskVLocale);
	iprcorner = new JobWzskIprCorner(xchg, dbswzsk, jref, ixWzskVLocale);
	iprtrace = new JobWzskIprTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	actservo = new JobWzskActServo(xchg, dbswzsk, jref, ixWzskVLocale);
	iprangle = new JobWzskIprAngle(xchg, dbswzsk, jref, ixWzskVLocale);
	actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);
	actexposure = new JobWzskActExposure(xchg, dbswzsk, jref, ixWzskVLocale);
	acqptcloud = new JobWzskAcqPtcloud(xchg, dbswzsk, jref, ixWzskVLocale);
	acqpreview = new JobWzskAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);
	acqfpgaflg = new JobWzskAcqFpgaflg(xchg, dbswzsk, jref, ixWzskVLocale);
	acqfpgapvw = new JobWzskAcqFpgapvw(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	xchg->addClstn(VecWzskVCall::CALLWZSKSUSPSESS, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);
	xchg->addClstn(VecWzskVCall::CALLWZSKLOGOUT, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
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

	SessWzsk* sess = NULL;

	cout << "\tuser name: ";
	cin >> input;
	cout << "\tpassword: ";
	cin >> input2;

	// verify password and create a session
	if (authenticate(dbswzsk, input, input2, refUsr)) {
		sess = new SessWzsk(xchg, dbswzsk, jref, refUsr, "127.0.0.1");
		sesss.push_back(sess);

		cout << "\tjob reference: " << sess->jref << endl;
		xchg->jrefCmd = sess->jref;

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
	uint iinput;

	SessWzsk* sess = NULL;

	cout << "\tjob reference: ";
	cin >> input;
	iinput = atoi(input.c_str());

	for (auto it = sesss.begin(); it != sesss.end();) {
		sess = *it;
		if (sess->jref == iinput) {
			it = sesss.erase(it);
			delete sess;
			break;
		} else it++;
	};

	return false;
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

	SessWzsk* sess = NULL;
	M2msessWzsk* m2msess = NULL;

	Feed feedFEnsSps("FeedFEnsSps");

	// verify password
	if (authenticate(dbswzsk, StrMod::lc(dpchapplogin->username), dpchapplogin->password, refUsr)) {
		if (!(dpchapplogin->m2mNotReg)) {
			if (xchg->stgwzskappearance.suspsess && dpchapplogin->chksuspsess) {
				// look for suspended sessions
				for (auto it = sesss.begin(); it != sesss.end(); it++) {
					sess = *it;

					if (xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, sess->jref) == refUsr) {
						if (xchg->getBoolvalPreset(VecWzskVPreset::PREWZSKSUSPSESS, sess->jref)) {
							xchg->addTxtvalPreset(VecWzskVPreset::PREWZSKIP, sess->jref, ip);
							feedFEnsSps.appendIxSrefTitles(0, Scr::scramble(sess->jref), StubWzsk::getStubSesStd(dbswzsk, xchg->getRefPreset(VecWzskVPreset::PREWZSKSESS, sess->jref)));
						};
					};
				};
			};

			if (feedFEnsSps.size() == 0) {
				// start new session
				sess = new SessWzsk(xchg, dbswzsk, jref, refUsr, ip);
				sesss.push_back(sess);

				xchg->appendToLogfile("session created for user '" + dpchapplogin->username + "' from IP " + ip);

				*dpcheng = new DpchEngWzskConfirm(true, sess->jref, "");

			} else {
				// return suspended sessions
				*dpcheng = new DpchEngData(0, &feedFEnsSps, {DpchEngData::ALL});
			};

		} else {
			m2msess = new M2msessWzsk(xchg, dbswzsk, jref, refUsr, ip);

			m2msesss.push_back(m2msess);

			xchg->appendToLogfile("M2M session created for user '" + dpchapplogin->username + "' from IP " + ip);

			*dpcheng = new DpchEngWzskConfirm(true, m2msess->jref, "");
		};

	} else {
		xchg->appendToLogfile("login refused for user '" + dpchapplogin->username + "' from IP " + ip);

		*dpcheng = new DpchEngWzskConfirm(false, 0, "");
	};
};

void RootWzsk::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSUSPSESS) {
		call->abort = handleCallWzskSuspsess(dbswzsk, call->jref);
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

bool RootWzsk::handleCallWzskLogout(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const bool boolvalInv
		) {
	bool retval = false;

	SessWzsk* sess = NULL;
	M2msessWzsk* m2msess = NULL;

	if (!boolvalInv) {
		for (auto it = sesss.begin(); it != sesss.end();) {
			sess = *it;
			if (sess->jref == jrefTrig) {
				sess->term(dbswzsk);
				it = sesss.erase(it);

				delete sess;
				break;
			} else it++;
		};

	} else {
		for (auto it = m2msesss.begin(); it != m2msesss.end();) {
			m2msess = *it;
			if (m2msess->jref == jrefTrig) {
				m2msess->term(dbswzsk);
				it = m2msesss.erase(it);

				delete m2msess;
				break;
			} else it++;
		};
	};

	return retval;
};

