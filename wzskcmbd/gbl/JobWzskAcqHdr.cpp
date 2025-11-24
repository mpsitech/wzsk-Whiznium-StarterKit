/**
	* \file JobWzskAcqHdr.cpp
	* job handler for job JobWzskAcqHdr (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskAcqHdr.h"

#include "JobWzskAcqHdr_blks.cpp"
#include "JobWzskAcqHdr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskAcqHdr::Shrdat::Resultitem
 ******************************************************************************/

JobWzskAcqHdr::Shrdat::Resultitem::Resultitem(
			Shrdat& super
			, XchgWzsk* xchg
			, const uint ixDma
		) :
			Sbecore::Resultitem()
			, w(xchg->stgwzskcamera.NColRaw/2)
			, h(xchg->stgwzskcamera.NRowRaw/2)
			, t(0.0)
		{
	buf = &(((unsigned char*) super.buf)[ixDma * JobWzskAcqHdr::stg.sizeChunk * 1048576]);
	lenBuf = 4*w*h;
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskAcqHdr::Shrdat
 ******************************************************************************/

JobWzskAcqHdr::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqHdr", "Shrdat")
		{
};

void JobWzskAcqHdr::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	bool success;

	fd = -1;
	buf = NULL;

	try {
		fd = open(stg.path.c_str(), O_RDWR);

		success = (fd != -1);
		if (!success) throw WzskException(0, {{"msg","error opening reserved memory device (" + string(strerror(errno)) + ")"}});

		if (success) {
			buf = mmap(NULL, stg.NChunk * stg.sizeChunk * 1048576, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // PROT_WRITE for debug functionality

			success = (buf != MAP_FAILED);
			if (!success) throw WzskException(0, {{"msg","error mapping reserved memory (" + string(strerror(errno)) + ")"}});
		};

		if (success) {
			memset(buf, 0, stg.NChunk * stg.sizeChunk * 1048576);

			for (unsigned int i = 0; i < stg.NChunk; i++) resultHdr.append(new Resultitem(*this, xchg, i));
		};

		if (!success && (fd != -1)) {
			close(fd);
			fd = 0;
		};

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
	};

	bufDummy = NULL;

	hdr = 0;

	cancelHdr = false;
	// IP Shrdat.init --- IEND
};

void JobWzskAcqHdr::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- IBEGIN
	if (buf) munmap(buf, stg.NChunk * stg.sizeChunk * 1048576);

	if (bufDummy) delete[] bufDummy;

	if (fd != -1) {
		close(fd);
		fd = 0;
	};
	// IP Shrdat.term --- IEND
};

/******************************************************************************
 class JobWzskAcqHdr
 ******************************************************************************/

JobWzskAcqHdr::JobWzskAcqHdr(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQHDR, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcdcvsp = NULL;
	srctivsp = NULL;
	srczuvsp = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	if (srvNotCli) if (evalSrcdcvspConstr(dbswzsk)) srcdcvsp = new JobWzskSrcDcvsp(xchg, dbswzsk, jref, ixWzskVLocale);
	if (srvNotCli) if (evalSrctivspConstr(dbswzsk)) srctivsp = new JobWzskSrcTivsp(xchg, dbswzsk, jref, ixWzskVLocale);
	if (srvNotCli) if (evalSrczuvspConstr(dbswzsk)) srczuvsp = new JobWzskSrcZuvsp(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKCALLBACK, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), VecVSge::RNG, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqHdr::~JobWzskAcqHdr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void* JobWzskAcqHdr::runHdr(
			void* arg
		) {
	JobWzskAcqHdr* srv = (JobWzskAcqHdr*) arg;

	Call call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg());
	ExtcallWzsk extcall(srv->xchg, &call);

	uint ixRi;
	Shrdat::Resultitem* ri = NULL;

	const uint8_t ixMemInvalid = 0xFF;

	uint8_t ixMem0 = ixMemInvalid;
	uint8_t ixMem1 = ixMemInvalid;

	uint8_t tixVState;
	uint32_t tkst;
	uint8_t ixMem;
	uint8_t ixMemAcq;

	bool resultNew;

	// at any given time, there can be at most two ixMem's assign()ed to hdreng
	// accordingly, new results can only be associated with either ixMem0 or ixMem1

	// - prepare
	// set(rng=true)

	// - loop
	// poll: getInfo(ixMem)
	// if ixMem match: resultNew (ixMem0 or ixMem1)
	//		if ixMem == ixMem0: resultNew(ixMem0), ixMem0 = ixMem1
	//		if ixMem == ixMem1: resultNew(ixMem1), slip detected, give up on ixMem0
	// if ixMem0 invalid: assign(ixMem0)
	// else if ixMem1 invalid and ixMem0 in progress: assign(ixMem1)

	timespec deltatPoll = {.tv_sec = 0, .tv_nsec = 1000000}; // 1 ms
	timespec deltatFrame = {.tv_sec = 0, .tv_nsec = 100000000}; // 100 ms

	UntWskdZuvsp& zuvsp = JobWzskSrcZuvsp::shrdat.hw;

	uint32_t tkst_last = 0;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupHdr, arg);

	try {
		// - prepare
		shrdat.mHdr.lock("JobWzskAcqHdr", "runHdr[1]");

		// switch on
		if (srv->srczuvsp) zuvsp.hdreng->set(true); // rng={false,true}

		shrdat.mHdr.unlock("JobWzskAcqHdr", "runHdr[1]");

		// - loop
		while (true) {
			if (shrdat.cancelHdr) break;

			shrdat.mHdr.lock("JobWzskAcqHdr", "runHdr[2]");

			resultNew = false;

			if (srv->srczuvsp) zuvsp.hdreng->getInfo(tixVState, tkst, ixMem, ixMemAcq); // tixVState{idle,acq,stall},tkst[uint32],ixMem[uint8],ixMemAcq[uint8]

			// ixMem0: latest to have been assigned

			if (ixMem != ixMemInvalid) {
				if ((ixMem == ixMem0) || (ixMem == ixMem1)) {
					// next frame fully processed
					ri = (Shrdat::Resultitem*) shrdat.resultHdr[ixMem];

					if (srv->srczuvsp) ri->t = srv->srczuvsp->tkstToT(tkst);

					cout << "[" << (((double) tkst) / 10000.0) << "] acquired new frame with ixMem = " << ((unsigned int) ixMem) << " (ixMemAcq = " << ((unsigned int) ixMemAcq) << ")" << endl;

					resultNew = true;

					if (ixMem == ixMem0) {
						// slip case (ixMem1 result was missed)
						ixMem0 = ixMemInvalid;

						if (ixMem1 != ixMemInvalid) {
							shrdat.resultHdr.unlock(srv->jref, ixMem1);
							ixMem1 = ixMemInvalid;
						};

					} else if (ixMem == ixMem1) {
						// no-slip case
						ixMem1 = ixMemInvalid;
					};

					call.argInv = Arg(ixMem, 0, {}, "", 0, 0.0, false, "", Arg::IX);
					XchgWzsk::runExtcall(&extcall);
				};
			};

			if ((ixMem0 != ixMemInvalid) && (ixMem1 == ixMemInvalid) && (ixMemAcq == ixMem0) ) {
				// condition when processing at ixMem0 is in progress
				ixMem1 = ixMem0;

				if (shrdat.resultHdr.dequeue(ixRi)) ixMem0 = ixRi;
				else ixMem0 = ixMemInvalid;

				if (srv->srczuvsp) zuvsp.hdreng->assign(ixMem0);
				//if (ixMem0 != ixMemInvalid) cout << "assigned ixMem0 = " << ((unsigned int) ixMem0) << " on top"  << " (ixMem = " << ((unsigned int) ixMem) << ", ixMemAcq = " << ((unsigned int) ixMemAcq) << ")" << endl;

			} else if (ixMem0 == ixMemInvalid) {
				// condition at start or after slip
				if (shrdat.resultHdr.dequeue(ixRi)) ixMem0 = ixRi;
				else ixMem0 = ixMemInvalid;

				if (srv->srczuvsp) zuvsp.hdreng->assign(ixMem0);
				//if (ixMem0 != ixMemInvalid) cout << "assigned ixMem0 = " << ((unsigned int) ixMem0) << " after slip"  << " (ixMem = " << ((unsigned int) ixMem) << ", ixMemAcq = " << ((unsigned int) ixMemAcq) << ")" << endl;
			};
			///

			shrdat.mHdr.unlock("JobWzskAcqHdr", "runHdr[2]");

			if (resultNew) nanosleep(&deltatFrame, NULL);
			else nanosleep(&deltatPoll, NULL);
		};

	} catch (DbeException& e) {
		cout << e.err << endl;

		call.argInv = Arg(0, 0, {}, "err", 0, 0.0, false, "", Arg::SREF);
		XchgWzsk::runExtcall(&extcall);

		shrdat.mHdr.unlock("JobWzskAcqHdr", "runHdr[4]");
	};

	try {
		// - clean up
		if (srv->srczuvsp) zuvsp.hdreng->set(false); // rng={false,true}

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	pthread_cleanup_pop(0);

	shrdat.hdr = 0;

	return NULL;
};

void JobWzskAcqHdr::cleanupHdr(
			void* arg
		) {
	shrdat.mHdr.lock("JobWzskAcqHdr", "cleanupHdr");

	//cout << "JobWzskAcqHdr::cleanupHdr()" << endl;
	shrdat.hdr = 0;

	shrdat.mHdr.unlock("JobWzskAcqHdr", "cleanupHdr");
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskAcqHdr::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

void JobWzskAcqHdr::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::RNG)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqHdr::handleCallWzskCallbackFromSelfInSgeRng(
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

		} else if (srefInv == "err") {
			// something went wrong, cancel thread
			changeStage(dbswzsk, VecVSge::IDLE);

		} else {
			// new result available
			shrdat.resultHdr.lock(jref, ixInv);

			// inform super-jobs about new result
			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixInv, srefInv);

			shrdat.resultHdr.unlock(jref, ixInv);
		};

		unlockAccess("handleCallWzskCallbackFromSelfInSgeRng");

	} else {
		if (srefInv != "err") shrdat.resultHdr.unlock(0, ixInv);
	};
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IEND
	return retval;
};

void JobWzskAcqHdr::changeStage(
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
			//cout << "JobWzskAcqHdr now entering stage " << VecVSge::getSref(_ixVSge) << endl; // IP changeStage.refresh1 --- ILINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::RNG: _ixVSge = enterSgeRng(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqHdr::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::RNG) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::RNG) retval = "acquiring frames";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskAcqHdr::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	pthread_t oldHdr;

	shrdat.cancelHdr = true;

	shrdat.mHdr.lock("JobWzskAcqHdr", "enterSgeIdle");

	oldHdr = shrdat.hdr; // original will be set 0 in the process

	if (oldHdr != 0) {
		shrdat.mHdr.unlock("JobWzskAcqHdr", "enterSgeIdle[1]");

		pthread_join(oldHdr, NULL);

	} else shrdat.mHdr.unlock("JobWzskAcqHdr", "enterSgeIdle[2]");

	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);

	for (unsigned int i = 0; i < shrdat.resultHdr.size(); i++) shrdat.resultHdr.unlock(jref, i);
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqHdr::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqHdr::enterSgeRng(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RNG;

	// IP enterSgeRng --- IBEGIN
	int res;
	pthread_attr_t attr;

	if (shrdat.hdr != 0) retval = VecVSge::IDLE;
	else {
		shrdat.mHdr.lock("JobWzskAcqHdr", "enterSgeRng");

		shrdat.cancelHdr = false;

		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&shrdat.hdr, &attr, &runHdr, (void*) this);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "JobWzskAcqHdr::enterSgeRng() error creating acquisition thread (" << res << ")" << endl;

		shrdat.mHdr.unlock("JobWzskAcqHdr", "enterSgeRng");
	};
	// IP enterSgeRng --- IEND

	return retval;
};

void JobWzskAcqHdr::leaveSgeRng(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRng --- INSERT
};

bool JobWzskAcqHdr::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if src*vsp "hdreng" claim can be fulfilled
	// - change stage to rng if fulfilled claim is run (run is continuous)

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;

	bool rgbNotGray = false;
	utinyint edge = 0;

	bool available;
	bool reattributed;

	CsjobWzsk* srcvsp = NULL;
	bool vspTakenNotAvailable, vspFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			run = claim->run;
		};
	};

	// add or remove "hdreng" claim with src*vsp
	if (srcdcvsp) srcvsp = srcdcvsp;
	else if (srctivsp)  srcvsp = srctivsp;
	else if (srczuvsp) srcvsp = srczuvsp;

	if (srcvsp) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcvsp);
		else xchg->addCsjobClaim(dbswzsk, srcvsp, new Wzsk::ClaimVsp(false, Wzsk::ClaimVsp::VecWDomain::HDRENG));

		xchg->getCsjobClaim(srcvsp, vspTakenNotAvailable, vspFulfilled);
	};

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && vspFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					run = claim->run;

					reattributed = true;
				};

				if (reattributed) break;
			};
		};

		if (!available) break;
		if (reattributed) break;
	};

	// update taken status
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;
		claim->takenNotAvailable = !retractable;
	};

	// initiate stage change
	if (!run || !vspFulfilled) {
		// changeStage() not used, rather nextIxVSgeFailure will be detected at a point when it is safe to change to idle
		nextIxVSgeFailure = VecVSge::IDLE;

	} else if (run && vspFulfilled) {
		nextIxVSgeFailure = VecVSge::RNG;
		if (ixVSge == VecVSge::IDLE) changeStage(dbswzsk, VecVSge::RNG);
	};

	mod = true; // for simplicity

	// IP handleClaim --- IEND

	return mod;
};
