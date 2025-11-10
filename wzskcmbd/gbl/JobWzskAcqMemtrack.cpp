/**
	* \file JobWzskAcqMemtrack.cpp
	* job handler for job JobWzskAcqMemtrack (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Oct 2025
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskAcqMemtrack.h"

#include "JobWzskAcqMemtrack_blks.cpp"
#include "JobWzskAcqMemtrack_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

using namespace Dbecore; // IP ns.cust --- ILINE

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskAcqMemtrack::Shrdat
 ******************************************************************************/

JobWzskAcqMemtrack::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqMemtrack", "Shrdat")
		{
};

void JobWzskAcqMemtrack::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	track = 0;

	cancelTrack = false;

	refWzskMFile = 0;
	// IP Shrdat.init --- IEND
};

void JobWzskAcqMemtrack::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqMemtrack
 ******************************************************************************/

JobWzskAcqMemtrack::JobWzskAcqMemtrack(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQMEMTRACK, jrefSup, ixWzskVLocale)
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

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKCALLBACK, jref, Clstn::VecVJobmask::SELF, 0, false, Arg(), VecVSge::RNG, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqMemtrack::~JobWzskAcqMemtrack() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
/******************************************************************************
 class JobWzskAcqMemtrack::Claim
 ******************************************************************************/

 JobWzskAcqMemtrack::Claim::Claim(
			const bool retractable
			, const bool run
			, const string path
		) :
			Sbecore::Claim(retractable, run)
			, path(path)
		{
};

void* JobWzskAcqMemtrack::runTrack(
			void* arg
		) {
	JobWzskAcqMemtrack* srv = (JobWzskAcqMemtrack*) arg;

	Call call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg());
	ExtcallWzsk extcall(srv->xchg, &call);

	UntWskdZuvsp& zuvsp = srv->srczuvsp->shrdat.hw;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupTrack, arg);

	const double fMemclk = 300.0e6;

	timespec deltatPause = {.tv_sec = 0, .tv_nsec = 1000000}; // 1 ms

	utinyint memTixVState;

	uint32_t memTCapt;
	uint16_t memPtr0Seqbuf;

	const size_t sizeSeqbuf = 1024 * 4;
	unsigned char seqbuf[sizeSeqbuf];
			
	unsigned char* bufptr = NULL;
	size_t len;

	vector<string> toc;
	vector<unsigned int> ts;
	vector<unsigned int> keys;
	vector<string> vals;

	Vcdwr vcdwr("Wskd", "Zuvsp", 1.0/fMemclk, 1);

	Gptrack memtrack("memtrack", VecVWskdZuvspMemtrackCapture::getSref, 4*1024, fMemclk);

	// - acquisition
	zuvsp.memtrack->select(
				VecVWskdZuvspMemtrackTrigger::VSYNC, // staTixVTrigger
				false, // staFallingNotRising
				VecVWskdZuvspMemtrackTrigger::VOID, // stoTixVTrigger
				false // stoFallingNotRising
			);

	zuvsp.memtrack->set(
				true, // rng
				fMemclk // TCaptMax: typ. stop when full but limit to one second
			);

	memTixVState = 0xFF;

	while (true) {
		utinyint memTixVState_last = memTixVState;

		if (memTixVState != VecVWskdZuvspMemtrackState::DONE) {
			zuvsp.memtrack->getInfo(memTixVState, memTCapt, memPtr0Seqbuf);
			//if (memTixVState != memTixVState_last) cout << "memory tracking now is in state " << VecVWskdZuvspMemtrackState::getSref(rxTixVState) << endl;
		};

		if (memTixVState == VecVWskdZuvspMemtrackState::DONE) break;

		nanosleep(&deltatPause, NULL);
	};

	// - read-out and analysis
	bufptr = seqbuf;

	zuvsp.readSeqbufFromMemtrack(sizeSeqbuf, bufptr, len);
	memtrack.analyzeSeqbuf(seqbuf, memTCapt, memPtr0Seqbuf); // memPtr0Seqbuf should be 0

	memtrack.getVcd(toc, ts, keys, vals);
	vcdwr.append(toc, 0, 1, ts, keys, vals);

	// - write .vcd file
	vcdwr.writeVcd(shrdat.fullpath);

	XchgWzsk::runExtcall(&extcall);

	pthread_cleanup_pop(0);

	shrdat.track = 0;

	return NULL;
};

void JobWzskAcqMemtrack::cleanupTrack(
			void* arg
		) {
	shrdat.mTrack.lock("JobWzskAcqMemtrack", "cleanupTrack");

	shrdat.track = 0;

	shrdat.mTrack.unlock("JobWzskAcqMemtrack", "cleanupTrack");
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskAcqMemtrack::handleRequest(
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

bool JobWzskAcqMemtrack::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqMemtrack::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::RNG)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk);
	};
};

bool JobWzskAcqMemtrack::handleCallWzskCallbackFromSelfInSgeRng(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IBEGIN
	WzskMFile* fil = NULL;

	struct stat st;

	lockAccess("handleCallWzskCallbackFromSelfInSgeRng");

	if (dbswzsk->tblwzskmfile->loadRecByRef(shrdat.refWzskMFile, &fil)) {
		// update archive file size
		stat(shrdat.fullpath.c_str(), &st);
		fil->Size = st.st_size / 1024;

		dbswzsk->tblwzskmfile->updateRec(fil);

		delete fil;
	};

	// inform super-jobs about new result
	Arg argRet;
	xchg->triggerArgToArgCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, Arg(0, shrdat.refWzskMFile, {}, "", 0, 0.0, false, "", Arg::REF + Arg::SREF), argRet);

	shrdat.path = "";
	shrdat.refWzskMFile = 0;

	// cancel thread
	changeStage(dbswzsk, VecVSge::IDLE);

	unlockAccess("handleCallWzskCallbackFromSelfInSgeRng");
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IEND
	return retval;
};

void JobWzskAcqMemtrack::changeStage(
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

string JobWzskAcqMemtrack::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::RNG) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::RNG) retval = "tracking signals";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskAcqMemtrack::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	pthread_t oldTrack;

	shrdat.cancelTrack = true;

	shrdat.mTrack.lock("JobWzskAcqMemtrack", "enterSgeIdle");

	oldTrack = shrdat.track; // original will be set 0 in the process

	if (oldTrack != 0) {
		shrdat.mTrack.unlock("JobWzskAcqMemtrack", "enterSgeIdle[1]");

		pthread_join(oldTrack, NULL);

	} else shrdat.mTrack.unlock("JobWzskAcqMemtrack", "enterSgeIdle[2]");

	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqMemtrack::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqMemtrack::enterSgeRng(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RNG;

	// IP enterSgeRng --- IBEGIN
	int res;
	pthread_attr_t attr;

	fstream outfile;
	string path;

	if ((nextIxVSgeFailure == VecVSge::IDLE) || (shrdat.track != 0) || (shrdat.path == "")) retval = VecVSge::IDLE;
	else {
		shrdat.mTrack.lock("JobWzskAcqMemtrack", "enterSgeRng");

		path = xchg->tmppath + "/" + Tmp::newfile(xchg->tmppath, "");

		outfile.open(path.c_str(), ios::out);
		outfile.close();

		shrdat.refWzskMFile = Acv::addfile(dbswzsk, xchg->acvpath, path, 0, 0, VecWzskVMFileRefTbl::VOID, 0, "memtrack", shrdat.path, "vcd", "");
		shrdat.fullpath = xchg->acvpath + "/" + Acv::getfile(dbswzsk, shrdat.refWzskMFile);

		shrdat.cancelTrack = false;

		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&shrdat.track, &attr, &runTrack, (void*) this);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "JobWzskAcqMemtrack::enterSgeRng() error creating track thread (" << res << ")" << endl;

		shrdat.mTrack.unlock("JobWzskAcqMemtrack", "enterSgeRng");
	};
	// IP enterSgeRng --- IEND

	return retval;
};

void JobWzskAcqMemtrack::leaveSgeRng(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRng --- INSERT
};

bool JobWzskAcqMemtrack::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - no modification when running
	// - exactly one claim can be fulfilled
	// - change stage to rng if fulfilled claim is run

	if (ixVSge != VecVSge::IDLE) return false;

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;

	string path;

	bool available;
	bool reattributed;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			path = claim->path;

			break;
		};
	};

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					run = claim->run;
					path = claim->path;

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
	if (!run) {
		changeStage(dbswzsk, VecVSge::IDLE);

	} else if (run && (ixVSge == VecVSge::IDLE)) {
		shrdat.path = path;

		nextIxVSgeFailure = VecVSge::RNG;
		changeStage(dbswzsk, VecVSge::RNG);
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};
