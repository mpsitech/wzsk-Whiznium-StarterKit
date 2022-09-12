/**
	* \file JobWzskAcqFpgaflg.cpp
	* job handler for job JobWzskAcqFpgaflg (implementation)
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

#include "JobWzskAcqFpgaflg.h"

#include "JobWzskAcqFpgaflg_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskAcqFpgaflg::Shrdat::ResultitemFlg
 ******************************************************************************/

JobWzskAcqFpgaflg::Shrdat::ResultitemFlg::ResultitemFlg() :
			Resultitem()
		{
	unsigned int w, h;
	size_t sizeBuf;

	thdNotCorner = false;
	thdDeltaNotAbs = false;

	Wzsk::getFlgWh(w, h); // buffer size is invariant
	sizeBuf = w * h / 8;

	buf = new unsigned char[sizeBuf + 2];

	tixVThdstate = 0;
	t = 0.0;

	shift = 0;
	scoreMin = 0;
	scoreMax = 0;
};

JobWzskAcqFpgaflg::Shrdat::ResultitemFlg::~ResultitemFlg() {
	if (buf) delete[] buf;
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskAcqFpgaflg::Shrdat
 ******************************************************************************/

JobWzskAcqFpgaflg::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqFpgaflg", "Shrdat")
		{
};

void JobWzskAcqFpgaflg::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	flg = 0;

	thdNotCorner = false;
	thdDeltaNotAbs = false;

	cornerLinNotLog = false;
	cornerThd = 0;

	thdLvlFirst = 0;
	thdLvlSecond = 0;

	cancelFlg = false;

	for (unsigned int i = 0; i < 2; i++) resultFlg.append(new ResultitemFlg());
	// IP Shrdat.init --- IEND
};

void JobWzskAcqFpgaflg::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqFpgaflg
 ******************************************************************************/

JobWzskAcqFpgaflg::JobWzskAcqFpgaflg(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQFPGAFLG, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcmercbb = NULL;
	srcmcvevp = NULL;
	srcicicle = NULL;
	srcclnxevb = NULL;
	srcarty = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) {
		if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::ARTY) srcarty = new JobWzskSrcArty(xchg, dbswzsk, jref, ixWzskVLocale);
		else if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::CLNXEVB) srcclnxevb = new JobWzskSrcClnxevb(xchg, dbswzsk, jref, ixWzskVLocale);
		else if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::ICICLE) srcicicle = new JobWzskSrcIcicle(xchg, dbswzsk, jref, ixWzskVLocale);
		else if (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::MCVEVP) srcmcvevp = new JobWzskSrcMcvevp(xchg, dbswzsk, jref, ixWzskVLocale);
	};
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKCALLBACK, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), VecVSge::RNG, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqFpgaflg::~JobWzskAcqFpgaflg() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskAcqFpgaflg::Claim::Claim(
			const bool retractable
			, const bool run
			, const bool thdNotCorner
			, const bool thdDeltaNotAbs
			, const bool cornerLinNotLog
			, const utinyint cornerThd
			, const utinyint thdLvlFirst
			, const utinyint thdLvlSecond
		) :
			Sbecore::Claim(retractable, run)
		{
	this->thdNotCorner = thdNotCorner;
	this->thdDeltaNotAbs = thdDeltaNotAbs;

	this->cornerLinNotLog = cornerLinNotLog;
	this->cornerThd = cornerThd;

	this->thdLvlFirst = thdLvlFirst;
	this->thdLvlSecond = thdLvlSecond;
};

void* JobWzskAcqFpgaflg::runFlg(
			void* arg
		) {
	JobWzskAcqFpgaflg* srv = (JobWzskAcqFpgaflg*) arg;

	unsigned int w, h;
	size_t sizeBuf;
	
	Wzsk::getFlgWh(w, h);
	sizeBuf = w * h / 8;

	unsigned char* auxbuf = new unsigned char[sizeBuf + 2]; // used if no external buffer is assigned
	unsigned char* buf = NULL;

	uint ixRi;
	Shrdat::ResultitemFlg* ri = NULL;

	string srefRi;

	utinyint cornerThd = shrdat.cornerThd;

	bool triggered;

	utinyint tixVFlgbufstate;
	utinyint tixVThdstate;
	uint tkst;

	size_t datalen;

	timespec deltat;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupFlg, arg);

	try {
		// - prepare
		shrdat.mFlg.lock("JobWzskAcqFpgaflg", "runFlg[1]");

		if (srv->srcarty) {
			srv->srcarty->camacq_setGrrd(false, false);
			srv->srcarty->featdet_set(false, false, false);

			srv->srcarty->camif_setRng(true);
			srv->srcarty->camacq_setGrrd(true, shrdat.thdNotCorner);
			if (!shrdat.thdNotCorner) srv->srcarty->featdet_setCorner(shrdat.cornerLinNotLog, shrdat.cornerThd);
			else srv->srcarty->featdet_setThd(shrdat.thdLvlFirst, shrdat.thdLvlSecond);
			srv->srcarty->featdet_set(true, shrdat.thdNotCorner, shrdat.thdDeltaNotAbs);
			if (shrdat.thdNotCorner) srv->srcarty->featdet_triggerThd();

		} else if (srv->srcicicle) {
			srv->srcicicle->camacq_setGrrd(false, false);
			srv->srcicicle->featdet_set(false, false, false);

			srv->srcicicle->camif_setRng(true);
			srv->srcicicle->camacq_setGrrd(true, shrdat.thdNotCorner);
			if (!shrdat.thdNotCorner) srv->srcicicle->featdet_setCorner(shrdat.cornerLinNotLog, shrdat.cornerThd);
			else srv->srcicicle->featdet_setThd(shrdat.thdLvlFirst, shrdat.thdLvlSecond);
			srv->srcicicle->featdet_set(true, shrdat.thdNotCorner, shrdat.thdDeltaNotAbs);
			if (shrdat.thdNotCorner) srv->srcicicle->featdet_triggerThd();
		};

		triggered = false;

		shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[1]");

		// - loop
		while (true) {
			if (shrdat.cancelFlg) break;

			if (!shrdat.thdNotCorner && (shrdat.cornerThd != cornerThd)) {
				// allow corner threshold to change while thread running
				if (srv->srcarty) srv->srcarty->featdet_setCorner(shrdat.cornerLinNotLog, shrdat.cornerThd);
				else if (srv->srcicicle) srv->srcicicle->featdet_setCorner(shrdat.cornerLinNotLog, shrdat.cornerThd);

				cornerThd = shrdat.cornerThd;
			};

			shrdat.mFlg.lock("JobWzskAcqFpgaflg", "runFlg[2]");

			if (srv->srcarty) srv->srcarty->featdet_getInfo(tixVFlgbufstate, tixVThdstate, tkst);
			else if (srv->srcicicle) srv->srcicicle->featdet_getInfo(tixVFlgbufstate, tixVThdstate, tkst);
			//cout << "tixVThdstate = " << VecVWskdArtyFeatdetThdstate::getSref(tixVThdstate) << endl;

			if (shrdat.thdNotCorner && shrdat.thdDeltaNotAbs && (tixVThdstate == VecVWskdArtyFeatdetThdstate::WAITSECOND) && !triggered) {
				shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[2]");

				shrdat.cFlg.lockMutex("JobWzskAcqFpgaflg", "runFlg");

				//cout << "waiting for trigger to obtain second frame" << endl;
				XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(0, 0, {}, "waitsecond", 0, 0.0, false, "", Arg::SREF))));

				shrdat.cFlg.wait();
				shrdat.cFlg.unlockMutex("JobWzskAcqFpgaflg", "runFlg");

				if (!shrdat.cancelFlg) {
					if (srv->srcarty) srv->srcarty->featdet_triggerThd();
					else if (srv->srcicicle) srv->srcicicle->featdet_triggerThd();

					triggered = true;
				};

			} else if (tixVFlgbufstate == VecVWskdArtyFeatdetFlgbufstate::FULL) {
				ri = NULL;
				if (shrdat.resultFlg.dequeue(ixRi)) ri = (Shrdat::ResultitemFlg*) shrdat.resultFlg[ixRi];

				if (ri) {
					ri->thdNotCorner = shrdat.thdNotCorner;
					ri->thdDeltaNotAbs = shrdat.thdDeltaNotAbs;

					if (!shrdat.thdNotCorner) srefRi = "corner";
					else {
						if (!shrdat.thdDeltaNotAbs) srefRi = "thdabs";
						else srefRi = "thddelta";
					};

					ri->tixVThdstate = tixVThdstate;

					if (srv->srcarty) ri->t = srv->srcarty->tkstToT(tkst);
					else if (srv->srcicicle) ri->t = srv->srcicicle->tkstToT(tkst);

					buf = ri->buf;

				} else buf = auxbuf;

				if (ri && !shrdat.thdNotCorner) {
					if (srv->srcarty) srv->srcarty->featdet_getCornerinfo(ri->shift, ri->scoreMin, ri->scoreMax);
					else if (srv->srcicicle) srv->srcicicle->featdet_getCornerinfo(ri->shift, ri->scoreMin, ri->scoreMax);

					//cout << "shift = " << ((int) ri->shift) << ", scoreMin = " << ((int) ri->scoreMin) << ", scoreMax = " << ((int) ri->scoreMax) << endl;
				};

				try {
					if (srv->srcarty) srv->srcarty->shrdat.hw.readFlgbufFromFeatdet(sizeBuf, buf, datalen);
					else if (srv->srcicicle) srv->srcicicle->shrdat.hw.readFlgbufFromFeatdet(sizeBuf, buf, datalen);

				} catch (DbeException& e) {
					if (ri) {
						shrdat.resultFlg.unlock(srv->jref, ixRi); // put result item back in queue and try again, starting from featdet_getInfo()
						ri = NULL;
					};
				};

				if (ri) XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(ixRi, 0, {}, srefRi, 0, 0.0, false, "", Arg::IX + Arg::SREF))));

				shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[3]");

				if (ri) {
					if (!shrdat.thdNotCorner) {
						// sleep for 1/4Hz - 10ms = 240ms
						deltat = {.tv_sec = 0, .tv_nsec = 240000000};
						//nanosleep(&deltat, NULL);

					} else break; // thd is one-shot
				};

			} else {
				shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[4]");

				// sleep for ten milliseconds
				deltat = {.tv_sec = 0, .tv_nsec = 10000000};
				nanosleep(&deltat, NULL);
			};
		};

	} catch (DbeException& e) {
		cout << e.err << endl;

		XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg())));

		shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[5]");
	};

	try {
		// - clean up
		if (srv->srcarty) {
			srv->srcarty->camacq_setGrrd(false, false);
			srv->srcarty->featdet_set(false, false, false);

		} else if (srv->srcicicle) {
			srv->srcicicle->camacq_setGrrd(false, false);
			srv->srcicicle->featdet_set(false, false, false);
		};

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	delete[] auxbuf;

	pthread_cleanup_pop(0);

	shrdat.flg = 0;

	return NULL;
};

void JobWzskAcqFpgaflg::cleanupFlg(
			void* arg
		) {
	shrdat.mFlg.lock("JobWzskAcqFpgaflg", "cleanupFlg");

	shrdat.flg = 0;

	shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "cleanupFlg");
};

void JobWzskAcqFpgaflg::trigger() {
	shrdat.cFlg.signal("JobWzskAcqFpgaflg", "trigger");
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskAcqFpgaflg::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

bool JobWzskAcqFpgaflg::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqFpgaflg::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::RNG)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqFpgaflg::handleCallWzskCallbackFromSelfInSgeRng(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IBEGIN
	if (trylockAccess("handleCallWzskCallbackFromSelfInSgeRng")) {
		if (nextIxVSgeFailure != VecVSge::RNG) {
			// claim run attribute has been retracted
			changeStage(dbswzsk, VecVSge::IDLE);

		} else if (srefInv == "") {
			// something went wrong, cancel thread
			changeStage(dbswzsk, VecVSge::IDLE);

		} else if (srefInv == "waitsecond") {
			// waiting for trigger before acquiring second frame
			xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKWAITSECOND, jref);

		} else {
			// new result available
			shrdat.resultFlg.lock(jref, ixInv);

			// inform super-jobs about new result
			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixInv, srefInv);

			shrdat.resultFlg.unlock(jref, ixInv);

			changeStage(dbswzsk, VecVSge::IDLE);
		};

		unlockAccess("handleCallWzskCallbackFromSelfInSgeRng");

	} else {
		if ((srefInv != "") && (srefInv != "waitsecond")) shrdat.resultFlg.unlock(jref, ixInv);
	};
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IEND
	return retval;
};

void JobWzskAcqFpgaflg::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::RNG: leaveSgeRng(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::RNG: _ixVSge = enterSgeRng(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqFpgaflg::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::RNG) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::RNG) retval = "running";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::RNG) retval = "l\\u008auft";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskAcqFpgaflg::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	pthread_t oldFlg;

	shrdat.cancelFlg = true;

	shrdat.mFlg.lock("JobWzskAcqFpgaflg", "enterSgeIdle");

	oldFlg = shrdat.flg; // original will be set 0 in the process

	if (oldFlg != 0) {
		shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "enterSgeIdle[1]");

		shrdat.cFlg.signal("JobWzskAcqFpgaflg", "enterSgeIdle"); // in case thread is stuck waiting for trigger

		pthread_join(oldFlg, NULL);

	} else shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "enterSgeIdle[2]");

	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);

	for (unsigned int i = 0; i < shrdat.resultFlg.size(); i++) shrdat.resultFlg.unlock(jref, i);
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqFpgaflg::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqFpgaflg::enterSgeRng(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RNG;

	// IP enterSgeRng --- IBEGIN
	int res;
	pthread_attr_t attr;

	if (shrdat.flg != 0) retval = VecVSge::IDLE;
	else {
		shrdat.mFlg.lock("JobWzskAcqFpgaflg", "enterSgeRng");

		shrdat.cancelFlg = false;

		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&shrdat.flg, &attr, &runFlg, (void*) this);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "JobWzskAcqFpgaflg::enterSgeRng() error creating flagging thread (" << res << ")" << endl;

		shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "enterSgeRng");
	};
	// IP enterSgeRng --- IEND

	return retval;
};

void JobWzskAcqFpgaflg::leaveSgeRng(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRng --- INSERT
};

bool JobWzskAcqFpgaflg::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if srcfpga "flg" claim can be fulfilled
	// - change stage to rng if fulfilled claim is run (run is one-shot)

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;
	bool thdNotCorner = false;
	bool thdDeltaNotAbs = false;
	bool cornerLinNotLog = false;
	utinyint cornerThd = 0;
	utinyint thdLvlFirst = 0;
	utinyint thdLvlSecond = 0;

	bool available;
	bool reattributed;

	bool flgTakenNotAvailable, flgFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			run = claim->run;
			thdNotCorner = claim->thdNotCorner;
			cornerLinNotLog = claim->cornerLinNotLog;
			cornerThd = claim->cornerThd;
			thdLvlFirst = claim->thdLvlFirst;
			thdLvlSecond = claim->thdLvlSecond;
		};
	};

	if (srcarty) {
		// add or remove "flg" claim with srcarty
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcarty);
		else xchg->addCsjobClaim(dbswzsk, srcarty, new JobWzskSrcArty::Claim(false, false, true, false, false, false));

		xchg->getCsjobClaim(srcarty, flgTakenNotAvailable, flgFulfilled);

	} else if (srcicicle) {
		// add or remove "flg" claim with srcicicle
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcicicle);
		else xchg->addCsjobClaim(dbswzsk, srcicicle, new JobWzskSrcIcicle::Claim(false, false, true, false, false, false));

		xchg->getCsjobClaim(srcicicle, flgTakenNotAvailable, flgFulfilled);
	};

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && flgFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					run = claim->run;
					thdNotCorner = claim->thdNotCorner;
					thdDeltaNotAbs = claim->thdDeltaNotAbs;
					cornerLinNotLog = claim->cornerLinNotLog;
					cornerThd = claim->cornerThd;
					thdLvlFirst = claim->thdLvlFirst;
					thdLvlSecond = claim->thdLvlSecond;

					reattributed = true;
				};

				if (reattributed) break;
			};
		};

		if (!available) break;
		if (reattributed) break;
	};

	// update taken status
	available = retractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		claim->takenNotAvailable = !available;
	};

	// initiate stage change
	if (!run || !flgFulfilled) {
		// changeStage() not used, rather nextIxVSgeFailure will be detected at a point when it is safe to change to idle
		nextIxVSgeFailure = VecVSge::IDLE;

	} else if (run && flgFulfilled) {
		shrdat.thdNotCorner = thdNotCorner;
		shrdat.thdDeltaNotAbs = thdDeltaNotAbs;
		shrdat.cornerLinNotLog = cornerLinNotLog;
		shrdat.cornerThd = cornerThd; // corner threshold can be changed on-the-fly
		shrdat.thdLvlFirst = thdLvlFirst;
		shrdat.thdLvlSecond = thdLvlSecond;

		nextIxVSgeFailure = VecVSge::RNG;

		if (ixVSge == VecVSge::IDLE) changeStage(dbswzsk, VecVSge::RNG);
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};
