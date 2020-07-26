/**
	* \file JobWzskAcqFpgaflg.cpp
	* job handler for job JobWzskAcqFpgaflg (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

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

	scoreMin = 0;
	scoreMax = 0;
	shift = 0;
	NCorner = 0;
	thd = 0;
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

	srcfpga = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	if (srvNotCli) srcfpga = new JobWzskSrcFpga(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

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
		) :
			Sbecore::Claim(retractable, run)
		{
	this->thdNotCorner = thdNotCorner;
	this->thdDeltaNotAbs = thdDeltaNotAbs;
};

void* JobWzskAcqFpgaflg::runFlg(
			void* arg
		) {
	JobWzskAcqFpgaflg* srv = (JobWzskAcqFpgaflg*) arg;

	UntWskdArty& fpga = srv->srcfpga->shrdat.hw;

	unsigned int w, h;
	size_t sizeBuf;
	
	Wzsk::getFlgWh(w, h);
	sizeBuf = w * h / 8;

	unsigned char* auxbuf = new unsigned char[sizeBuf + 2]; // used if no external buffer is assigned
	unsigned char* buf = NULL;

	uint ixRi;
	Shrdat::ResultitemFlg* ri = NULL;

	string srefRi;

	utinyint tixVFlgbufstate;
	utinyint tixVThdstate;
	uint tkst;

	usmallint scoreMinMsb; 
	uint scoreMinLsb;
	
	usmallint scoreMaxMsb;
	uint scoreMaxLsb;

	size_t datalen;

	timespec deltat;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupFlg, arg);

	try {
		// - prepare
		shrdat.mFlg.lock("JobWzskAcqFpgaflg", "runFlg[1]");

		srv->srcfpga->camacq_setGrrd(false, false);
		srv->srcfpga->featdet_set(false, false, false);

		srv->srcfpga->camif_setRng(true);
		srv->srcfpga->camacq_setGrrd(true, shrdat.thdNotCorner);
		srv->srcfpga->featdet_set(true, shrdat.thdNotCorner, shrdat.thdDeltaNotAbs);

		shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[1]");

		// - loop
		while (true) {
			if (shrdat.cancelFlg) break;

			shrdat.mFlg.lock("JobWzskAcqFpgaflg", "runFlg[2]");

			srv->srcfpga->featdet_getInfo(tixVFlgbufstate, tixVThdstate, tkst);
			//cout << "tixVThdstate = " << VecVWskdArtyFeatdetThdstate::getSref(tixVThdstate) << endl;

			if (shrdat.thdNotCorner && shrdat.thdDeltaNotAbs && (tixVThdstate == VecVWskdArtyFeatdetThdstate::WAITSECOND)) {
				shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[2]");

				shrdat.cFlg.lockMutex("JobWzskAcqFpgaflg", "runFlg");

				//cout << "waiting for trigger to obtain second frame" << endl;
				XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(0, 0, {}, "waitsecond", 0, 0.0, false, "", Arg::SREF))));

				shrdat.cFlg.wait();
				shrdat.cFlg.unlockMutex("JobWzskAcqFpgaflg", "runFlg");

				srv->srcfpga->featdet_triggerThd();

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
					ri->t = srv->srcfpga->tkstToT(tkst);

					buf = ri->buf;

				} else buf = auxbuf;

				if (ri && !shrdat.thdNotCorner) {
					srv->srcfpga->featdet_getCornerinfo(scoreMinMsb, scoreMinLsb, scoreMaxMsb, scoreMaxLsb, ri->shift, ri->NCorner, ri->thd);

					ri->scoreMin = scoreMinMsb;
					ri->scoreMin <<= 32;
					ri->scoreMin += scoreMinLsb;

					ri->scoreMax = scoreMaxMsb;
					ri->scoreMax <<= 32;
					ri->scoreMax += scoreMaxLsb;

					//cout << "scoreMin = " << ri->scoreMin << ", scoreMax = " << ri->scoreMax << ", shift = " << ((uint) (ri->shift)) << ", NCorner = " << ri->NCorner << ", thd = " << ((uint) (ri->thd)) << endl;
				};

				fpga.readFlgbufFromFeatdet(sizeBuf, buf, datalen);

				if (ri) XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(ixRi, 0, {}, srefRi, 0, 0.0, false, "", Arg::IX + Arg::SREF))));

				shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "runFlg[3]");

				if (!shrdat.thdNotCorner) {
					// one-shot for now
					break;

					// sleep for 1/4Hz - 10ms = 240ms
					//deltat = {.tv_sec = 0, .tv_nsec = 240000000};
					//nanosleep(&deltat, NULL);
				
				} else break;

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
		if (srefInv == "") {
			// - something went wrong, cancel thread
			changeStage(dbswzsk, VecVSge::IDLE);

		} else if (srefInv == "waitsecond") {
			// - waiting for trigger before acquiring second frame
			xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKWAITSECOND, jref);

		} else if (srefInv == "flg") {
			// - new result available
			shrdat.resultFlg.lock(jref, ixInv);

			// inform super-jobs about new result
			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixInv, srefInv);

			shrdat.resultFlg.unlock(jref, ixInv);

			changeStage(dbswzsk, VecVSge::IDLE);
		};

		unlockAccess("handleCallWzskCallbackFromSelfInSgeRng");

	} else {
		if (srefInv == "flg") shrdat.resultFlg.unlock(jref, ixInv);
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
			else if (ixVSge == VecVSge::RNG) retval = "l\\u00e4uft";
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

	shrdat.mFlg.lock("JobWzskAcqFpgaflg", "enterSgeIdle");

	oldFlg = shrdat.flg; // original will be set 0 in the process

	if (oldFlg != 0) {
		shrdat.cancelFlg = true;

		shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "enterSgeIdle[1]");

		pthread_join(oldFlg, NULL);

	} else shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "enterSgeIdle[2]");

	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);
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
	pthread_attr_t attr;

	shrdat.mFlg.lock("JobWzskAcqFpgaflg", "enterSgeRng");

	shrdat.cancelFlg = false;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&shrdat.flg, &attr, &runFlg, (void*) this);

	shrdat.mFlg.unlock("JobWzskAcqFpgaflg", "enterSgeRng");
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
			thdDeltaNotAbs = claim->thdDeltaNotAbs;
		};
	};

	// add or remove "flg" claim with srcfpga
	if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcfpga);
	else xchg->addCsjobClaim(dbswzsk, srcfpga, new JobWzskSrcFpga::Claim(false, false, true, false, false, false));

	xchg->getCsjobClaim(srcfpga, flgTakenNotAvailable, flgFulfilled);

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
	if (run && flgFulfilled && (ixVSge == VecVSge::IDLE)) {
		shrdat.thdNotCorner = thdNotCorner;
		shrdat.thdDeltaNotAbs = thdDeltaNotAbs;
		
		changeStage(dbswzsk, VecVSge::RNG);
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};


