/**
	* \file JobWzskAcqFpgapvw.cpp
	* job handler for job JobWzskAcqFpgapvw (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskAcqFpgapvw.h"

#include "JobWzskAcqFpgapvw_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskAcqFpgapvw::Shrdat::ResultitemPvw
 ******************************************************************************/

JobWzskAcqFpgapvw::Shrdat::ResultitemPvw::ResultitemPvw() :
			Resultitem()
		{
	ixWzskVPvwmode = 0;

	buf = NULL;
	sizeBuf = 0;

	t = 0.0;
};

JobWzskAcqFpgapvw::Shrdat::ResultitemPvw::~ResultitemPvw() {
	if (buf) delete[] buf;
};

void JobWzskAcqFpgapvw::Shrdat::ResultitemPvw::setPvwmode(
			const uint ixWzskVPvwmode
		) {
	unsigned int w, h;

	this->ixWzskVPvwmode = ixWzskVPvwmode;

	Wzsk::getPvwWh(ixWzskVPvwmode, w, h);

	if ((w * h) != sizeBuf) {
		sizeBuf = w * h;

		if (buf) delete[] buf;
		buf = new unsigned char[sizeBuf + 2];
	};
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskAcqFpgapvw::Shrdat
 ******************************************************************************/

JobWzskAcqFpgapvw::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqFpgapvw", "Shrdat")
		{
};

void JobWzskAcqFpgapvw::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	pvw = 0;

	ixWzskVPvwmode = 0;

	cancelPvw = false;

	for (unsigned int i = 0; i < 2; i++) resultPvw.append(new ResultitemPvw());
	// IP Shrdat.init --- IEND
};

void JobWzskAcqFpgapvw::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqFpgapvw
 ******************************************************************************/

JobWzskAcqFpgapvw::JobWzskAcqFpgapvw(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQFPGAPVW, jrefSup, ixWzskVLocale)
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

JobWzskAcqFpgapvw::~JobWzskAcqFpgapvw() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskAcqFpgapvw::Claim::Claim(
			const bool retractable
			, const bool run
			, const Sbecore::uint ixWzskVPvwmode
		) :
			Sbecore::Claim(retractable, run)
		{
	this->ixWzskVPvwmode = ixWzskVPvwmode;
};

void* JobWzskAcqFpgapvw::runPvw(
			void* arg
		) {
	JobWzskAcqFpgapvw* srv = (JobWzskAcqFpgapvw*) arg;

	UntWskdArty& fpga = srv->srcfpga->shrdat.hw;

	uint ixWzskVPvwmode = 0;
	unsigned int w, h;
	size_t sizeBuf;

	Wzsk::getPvwWh(VecWzskVPvwmode::BINRGB, w, h); // the larger of both possible buffer sizes
	sizeBuf = 3 * w * h;

	unsigned char* auxbuf = new unsigned char[sizeBuf + 2]; // used if no external buffer is assigned
	unsigned char* buf = NULL;

	size_t datalen;

	uint ixRi;
	Shrdat::ResultitemPvw* ri = NULL;

	utinyint tixVPvwbufstate;
	uint tkst;

	timespec deltat;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupPvw, arg);

	try {
		// - prepare
		shrdat.mPvw.lock("JobWzskSrcFpga", "runPvw[1]");

		srv->srcfpga->camacq_setPvw(false, 0, 0);
		srv->srcfpga->camif_setRng(true);

		shrdat.mPvw.unlock("JobWzskSrcFpga", "runPvw[1]");

		// - loop
		while (true) {
			if (shrdat.cancelPvw) break;

			if (shrdat.ixWzskVPvwmode != ixWzskVPvwmode) {
				// allow preview mode changes while thread running
				srv->srcfpga->camacq_setPvw(true, Wzsk::getPvwRawNotBin(shrdat.ixWzskVPvwmode), Wzsk::getPvwGrayNotRgb(shrdat.ixWzskVPvwmode));

				ixWzskVPvwmode = shrdat.ixWzskVPvwmode;
				Wzsk::getPvwWh(ixWzskVPvwmode, w, h);
				sizeBuf = 3 * w * h;

				// sleep for 1/4Hz - 10ms = 240ms
				deltat = {.tv_sec = 0, .tv_nsec = 240000000};
				nanosleep(&deltat, NULL);

				continue;
			};

			shrdat.mPvw.lock("JobWzskSrcFpga", "runPvw[2]");

			srv->srcfpga->camacq_getPvwinfo(tixVPvwbufstate, tkst);
			//cout << "tixVPvwbufstate = " << VecVWskdArtyCamacqPvwbufstate::getSref(tixVPvwbufstate) << ", tkst = " << tkst << endl;

			if ((tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::ABUF) || (tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::BBUF)) {
				ri = NULL;
				if (shrdat.resultPvw.dequeue(ixRi)) ri = (Shrdat::ResultitemPvw*) shrdat.resultPvw[ixRi];

				if (ri) {
					ri->setPvwmode(ixWzskVPvwmode);
					ri->t = srv->srcfpga->tkstToT(tkst);

					buf = ri->buf;

				} else buf = auxbuf;

				if (tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::ABUF) fpga.readPvwabufFromCamacq(sizeBuf, buf, datalen);
				else if (tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::BBUF) fpga.readPvwbbufFromCamacq(sizeBuf, buf, datalen);

				if (ri) XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(ixRi, 0, {}, VecWzskVPvwmode::getSref(ixWzskVPvwmode), 0, 0.0, false, "", Arg::IX + Arg::SREF))));

				shrdat.mPvw.unlock("JobWzskSrcFpga", "runPvw[2]");

				// sleep for 1/4Hz - 10ms = 240ms
				deltat = {.tv_sec = 0, .tv_nsec = 240000000};
				nanosleep(&deltat, NULL);

			} else {
				shrdat.mPvw.unlock("JobWzskSrcFpga", "runPvw[3]");

				// sleep for ten milliseconds
				deltat = {.tv_sec = 0, .tv_nsec = 10000000};
				nanosleep(&deltat, NULL);
			};
		};

	} catch (DbeException& e) {
		cout << e.err << endl;

		XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg())));

		shrdat.mPvw.unlock("JobWzskSrcFpga", "runPvw[4]");
	};

	delete[] auxbuf;

	pthread_cleanup_pop(0);

	shrdat.pvw = 0;

	return NULL;
};

void JobWzskAcqFpgapvw::cleanupPvw(
			void* arg
		) {
	shrdat.mPvw.lock("JobWzskAcqFpgapvw", "cleanupPvw");

	shrdat.pvw = 0;

	shrdat.mPvw.unlock("JobWzskAcqFpgapvw", "cleanupPvw");
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskAcqFpgapvw::handleRequest(
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

bool JobWzskAcqFpgapvw::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqFpgapvw::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::RNG)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqFpgapvw::handleCallWzskCallbackFromSelfInSgeRng(
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

		} else {
			// new result available
			shrdat.resultPvw.lock(jref, ixInv);

			// inform super-jobs about new result
			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixInv, srefInv);

			shrdat.resultPvw.unlock(jref, ixInv);
		};

		unlockAccess("handleCallWzskCallbackFromSelfInSgeRng");

	} else {
		if (srefInv != "") shrdat.resultPvw.unlock(jref, ixInv);
	};
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IEND
	return retval;
};

void JobWzskAcqFpgapvw::changeStage(
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

string JobWzskAcqFpgapvw::getSquawk(
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

uint JobWzskAcqFpgapvw::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	pthread_t oldPvw;

	shrdat.mPvw.lock("JobWzskAcqFpgapvw", "enterSgeIdle");

	oldPvw = shrdat.pvw; // original will be set 0 in the process

	if (oldPvw != 0) {
		shrdat.cancelPvw = true;

		shrdat.mPvw.unlock("JobWzskAcqFpgapvw", "enterSgeIdle[1]");

		pthread_join(oldPvw, NULL);

	} else shrdat.mPvw.unlock("JobWzskAcqFpgapvw", "enterSgeIdle[2]");;
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqFpgapvw::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqFpgapvw::enterSgeRng(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RNG;

	// IP enterSgeRng --- IBEGIN
	pthread_attr_t attr;

	shrdat.mPvw.lock("JobWzskAcqFpgapvw", "enterSgeRng");

//	shrdat.ixWzskVPvwmode = ixWzskVPvwmode;

	shrdat.cancelPvw = false;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	pthread_create(&shrdat.pvw, &attr, &runPvw, (void*) this);

	shrdat.mPvw.unlock("JobWzskAcqFpgapvw", "enterSgeRng");
	// IP enterSgeRng --- IEND

	return retval;
};

void JobWzskAcqFpgapvw::leaveSgeRng(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRng --- INSERT
};

bool JobWzskAcqFpgapvw::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if srcfpga "pvw" claim can be fulfilled
	// - change stage to rng if fulfilled claim is run (run is continuous)

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;
	uint ixWzskVPvwmode = 0;

	bool available;
	bool reattributed;

	bool pvwTakenNotAvailable, pvwFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			run = claim->run;
			ixWzskVPvwmode = claim->ixWzskVPvwmode;
		};
	};

	// add or remove "pvw" claim with srcfpga
	if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcfpga);
	else xchg->addCsjobClaim(dbswzsk, srcfpga, new JobWzskSrcFpga::Claim(false, false, false, true, false, false));

	xchg->getCsjobClaim(srcfpga, pvwTakenNotAvailable, pvwFulfilled);

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && pvwFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					run = claim->run;
					ixWzskVPvwmode = claim->ixWzskVPvwmode;

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
	if ((!run || !pvwFulfilled) && (ixVSge != VecVSge::IDLE)) {
		// changeStage() not used, rather nextIxVSgeFailure will be detected at a point when it is safe to change to idle
		nextIxVSgeFailure = VecVSge::IDLE;

	} else if (run && pvwFulfilled) {
		shrdat.ixWzskVPvwmode = ixWzskVPvwmode; // mode can be changed on-the-fly

		if (ixVSge == VecVSge::IDLE) {
			nextIxVSgeFailure = VecVSge::RNG;
			changeStage(dbswzsk, VecVSge::RNG);
		};
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



