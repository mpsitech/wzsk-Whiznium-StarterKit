/**
	* \file JobWzskAcqPtcloud.cpp
	* job handler for job JobWzskAcqPtcloud (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskAcqPtcloud.h"

#include "JobWzskAcqPtcloud_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskAcqPtcloud::Shrdat::ResultitemBody
 ******************************************************************************/

JobWzskAcqPtcloud::Shrdat::ResultitemBody::ResultitemBody() :
			Resultitem()
		{
	tStart = 0.0;
	tStop = 0.0;
};

JobWzskAcqPtcloud::Shrdat::ResultitemBody::~ResultitemBody() {
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskAcqPtcloud::Shrdat
 ******************************************************************************/

JobWzskAcqPtcloud::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqPtcloud", "Shrdat")
		{
};

void JobWzskAcqPtcloud::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	for (unsigned int i = 0; i < 2; i++) resultBody.append(new ResultitemBody());

	theta = 0.0;
	// IP Shrdat.init --- IEND
};

void JobWzskAcqPtcloud::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqPtcloud
 ******************************************************************************/

JobWzskAcqPtcloud::JobWzskAcqPtcloud(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQPTCLOUD, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	iprtrace = NULL;
	actservo = NULL;

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	if (srvNotCli) iprtrace = new JobWzskIprTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	if (srvNotCli) actservo = new JobWzskActServo(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::SPEC, actservo->jref, false, Arg(), VecVSge::TURN, Clstn::VecVJactype::LOCK);
	if (srvNotCli) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, iprtrace->jref, false, Arg(), VecVSge::ACQUIRE, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqPtcloud::~JobWzskAcqPtcloud() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

// IP spec --- INSERT

void JobWzskAcqPtcloud::handleRequest(
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

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRCIDLE) handleTimerInSgePrcidle(dbswzsk, req->sref);
	};
};

bool JobWzskAcqPtcloud::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqPtcloud::handleTimerInSgePrcidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void JobWzskAcqPtcloud::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) && (call->jref == actservo->jref) && (ixVSge == VecVSge::TURN)) {
		call->abort = handleCallWzskSgeChgFromActservoInSgeTurn(dbswzsk);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && (call->jref == iprtrace->jref) && (ixVSge == VecVSge::ACQUIRE)) {
		call->abort = handleCallWzskResultNewFromIprtraceInSgeAcquire(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqPtcloud::handleCallWzskSgeChgFromActservoInSgeTurn(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskSgeChgFromActservoInSgeTurn --- IBEGIN
	if (actservo->ixVSge == JobWzskActServo::VecVSge::IDLE) changeStage(dbswzsk, VecVSge::ACQUIRE);
	// IP handleCallWzskSgeChgFromActservoInSgeTurn --- IEND
	return retval;
};

bool JobWzskAcqPtcloud::handleCallWzskResultNewFromIprtraceInSgeAcquire(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromIprtraceInSgeAcquire --- IBEGIN
	iprtrace->shrdat.result.lock(jref, ixRiSrc);
	ixRiSrc = ixInv;

	changeStage(dbswzsk, VecVSge::PRCIDLE);
	// IP handleCallWzskResultNewFromIprtraceInSgeAcquire --- IEND
	return retval;
};

void JobWzskAcqPtcloud::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::READY: leaveSgeReady(dbswzsk); break;
				case VecVSge::ACQUIRE: leaveSgeAcquire(dbswzsk); break;
				case VecVSge::PRCIDLE: leaveSgePrcidle(dbswzsk); break;
				case VecVSge::PROCESS: leaveSgeProcess(dbswzsk); break;
				case VecVSge::TURN: leaveSgeTurn(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbswzsk, reenter); break;
			case VecVSge::ACQUIRE: _ixVSge = enterSgeAcquire(dbswzsk, reenter); break;
			case VecVSge::PRCIDLE: _ixVSge = enterSgePrcidle(dbswzsk, reenter); break;
			case VecVSge::PROCESS: _ixVSge = enterSgeProcess(dbswzsk, reenter); break;
			case VecVSge::TURN: _ixVSge = enterSgeTurn(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqPtcloud::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::READY) || (ixVSge == VecVSge::ACQUIRE) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::TURN) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::READY) retval = "ready";
			else if (ixVSge == VecVSge::ACQUIRE) retval = "acquiring";
			else if (ixVSge == VecVSge::PROCESS) retval = "processing";
			else if (ixVSge == VecVSge::TURN) retval = "turning";

			if ((ixVSge == VecVSge::ACQUIRE) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::TURN)) retval += " (" + to_string(shrdat.theta) + "\\u00b0 of 360\\u00b0 completed)";

		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
			else if (ixVSge == VecVSge::ACQUIRE) retval = "Aufzeichnung";
			else if (ixVSge == VecVSge::PROCESS) retval = "Verarbeitung";
			else if (ixVSge == VecVSge::TURN) retval = "Drehung";

			if ((ixVSge == VecVSge::ACQUIRE) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::TURN)) retval += " (" + to_string(shrdat.theta) + "\\u00b0 von 360\\u00b0 erledigt)";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint JobWzskAcqPtcloud::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqPtcloud::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- IBEGIN
	Shrdat::ResultitemBody* ri = NULL;

	if (shrdat.resultBody.dequeue(ixRi)) {
		ri = (Shrdat::ResultitemBody*) shrdat.resultBody[ixRi];

		ri->tStart = Wzsk::getNow();

		ri->rNotL.clear();

		ri->x.clear();
		ri->y.clear();
		ri->z.clear();

		actservo->zero(dbswzsk);

		shrdat.theta = 0.0;

		retval = VecVSge::ACQUIRE;

	} else retval = VecVSge::IDLE;
	// IP enterSgeReady --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobWzskAcqPtcloud::enterSgeAcquire(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ACQUIRE;

	// IP enterSgeAcquire --- IBEGIN
	xchg->addCsjobClaim(dbswzsk, iprtrace, new Claim(false, true));
	// IP enterSgeAcquire --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeAcquire(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAcquire --- INSERT
};

uint JobWzskAcqPtcloud::enterSgePrcidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRCIDLE;
	nextIxVSgeSuccess = VecVSge::PROCESS;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrcidle --- INSERT

	return retval;
};

void JobWzskAcqPtcloud::leaveSgePrcidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrcidle --- INSERT
};

uint JobWzskAcqPtcloud::enterSgeProcess(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PROCESS;

	// IP enterSgeProcess --- IBEGIN
	ShrdatJobWzskIprTrace::ResultitemTrace* riSrc = (ShrdatJobWzskIprTrace::ResultitemTrace*) iprtrace->shrdat.result[ixRiSrc];

	Shrdat::ResultitemBody* ri = (Shrdat::ResultitemBody*) shrdat.resultBody[ixRi];

	const double alphaLeft = atan2(stg.dWork, stg.dLeft);
	const double alphaRight = atan2(stg.dWork, stg.dRight);

	const double phiLeft = shrdat.theta * M_PI / 180.0 + alphaLeft;
	const double phiRight = shrdat.theta * M_PI / 180.0 - alphaRight;

	const double pixToDim = stg.dWork * xchg->stgwzskcamera.hpix / xchg->stgwzskcamera.f / 1000.0;

	bool rNotL;

	double x_in, y_in;
	double rho, phi, x, y, z;

	// plain core algorithm
	for (unsigned int i = 0; i < riSrc->x.size(); i++) {
		rNotL = (i >= riSrc->Nleft);

		x_in = pixToDim * ((double) (riSrc->x[i]));
		y_in = pixToDim * ((double) (riSrc->y[i]));

		if (!rNotL) {
			rho = fabs(x_in / sin(alphaLeft));
			phi = phiLeft;
		} else {
			rho = fabs(x_in / sin(alphaRight));
			phi = phiRight;
		};
		z = y_in;

		ri->rNotL.push_back(rNotL);
		ri->x.push_back(rho * cos(phi));
		ri->y.push_back(rho * sin(phi));
		ri->z.push_back(z);
	};

	iprtrace->shrdat.result.unlock(jref, ixRiSrc);

	retval = VecVSge::TURN;
	// IP enterSgeProcess --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeProcess(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeProcess --- INSERT
};

uint JobWzskAcqPtcloud::enterSgeTurn(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::TURN;

	// IP enterSgeTurn --- IBEGIN
	Shrdat::ResultitemBody* ri = NULL;

	shrdat.theta += stg.deltaTheta;

	if (shrdat.theta >= 360.0) {
		// done
		ri = (Shrdat::ResultitemBody*) shrdat.resultBody[ixRi];

		ri->tStop = Wzsk::getNow();

		// update shrdat
		shrdat.wlockAccess(jref, "enterSgeTurn");

		shrdat.theta = 0.0;

		shrdat.x.resize(ri->x.size());
		shrdat.y.resize(ri->x.size());
		shrdat.z.resize(ri->x.size());

		memcpy(shrdat.x.data(), ri->x.data(), shrdat.x.size() * sizeof(float));
		memcpy(shrdat.y.data(), ri->y.data(), shrdat.y.size() * sizeof(float));
		memcpy(shrdat.z.data(), ri->z.data(), shrdat.z.size() * sizeof(float));

		// preliminary to prevent DDS publisher from crashing
		if (shrdat.x.size() > 72000) {
			shrdat.x.resize(72000);
			shrdat.y.resize(72000);
			shrdat.z.resize(72000);
		};

		shrdat.wunlockAccess(jref, "enterSgeTurn");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "xYZ");

		// inform super-jobs
		xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRi, "full");

		shrdat.resultBody.unlock(0, ixRi); // hadn't been locked within this class

		retval = VecVSge::IDLE;

	} else {
		// inform super-jobs; for partial results, they must not lock the result or perform any asynchronous processing
		xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRi, "part");

		actservo->moveto(dbswzsk, shrdat.theta); // should return false
	};
	// IP enterSgeTurn --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeTurn(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeTurn --- INSERT
};

bool JobWzskAcqPtcloud::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if actservo and iprtrace claims can be fulfilled
	// - change stage to ready if fulfilled claim is run (run is one-shot)

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;

	bool available;
	bool reattributed;

	bool servoTakenNotAvailable, servoFulfilled;
	bool traceTakenNotAvailable, traceFulfilled;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			run = claim->run;
		};
	};

	// add claim with servo
	if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, actservo);
	else if ((jrefFulfilled == 0) && !claims.empty()) xchg->addCsjobClaim(dbswzsk, actservo, new Claim(false));

	xchg->getCsjobClaim(actservo, servoTakenNotAvailable, servoFulfilled);

	// add claim with trace
	if (claims.empty() || !servoFulfilled) xchg->removeCsjobClaim(dbswzsk, iprtrace);
	else if ((jrefFulfilled == 0) && !claims.empty()) xchg->addCsjobClaim(dbswzsk, iprtrace, new Claim(false, false));

	xchg->getCsjobClaim(iprtrace, traceTakenNotAvailable, traceFulfilled);

	if (servoFulfilled && !traceFulfilled) xchg->removeCsjobClaim(dbswzsk, actservo);

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && servoFulfilled && traceFulfilled;

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
	available = retractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		claim->takenNotAvailable = !available;
	};

	// initiate stage change (trace claim is removed / updated in stage acquire)
	if (run && servoFulfilled && traceFulfilled && (ixVSge == VecVSge::IDLE)) changeStage(dbswzsk, VecVSge::READY);

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



