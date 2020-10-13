/**
	* \file JobWzskAcqPtcloud.cpp
	* job handler for job JobWzskAcqPtcloud (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
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
	deltaTheta = 15.0;

	refWzskMSession = 0;
	refWzskMObject = 0;

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

	// IP constructor.cust1 --- IBEGIN
	ixRiSrc = 0; ixRiSrc--;
	ixRi = shrdat.resultBody.size();
	// IP constructor.cust1 --- IEND

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

// IP cust --- IBEGIN
JobWzskAcqPtcloud::Claim::Claim(
			const bool retractable
			, const bool run
			, const ubigint refWzskMSession
			, const ubigint refWzskMObject
		) :
			Sbecore::Claim(retractable, run)
		{
	this->refWzskMSession = refWzskMSession;
	this->refWzskMObject = refWzskMObject;
};
// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskAcqPtcloud::setDeltaTheta(
			DbsWzsk* dbswzsk
			, const float deltaTheta
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskAcqPtcloud*) srv)->setDeltaTheta(dbswzsk, deltaTheta);

		} else retval = false;

		return retval;
	};

	lockAccess("setDeltaTheta");

	// IP setDeltaTheta --- IBEGIN
	shrdat.wlockAccess(jref, "setDeltaTheta");

	shrdat.deltaTheta = deltaTheta;

	shrdat.wunlockAccess(jref, "setDeltaTheta");

	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "deltaTheta");
	// IP setDeltaTheta --- IEND

	unlockAccess("setDeltaTheta");

	return retval;
};

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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKACQPTCLOUDMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETDELTATHETA) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setDeltaTheta(dbswzsk, *((const float*) (req->method->parsInv[0])));
		};

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
				case VecVSge::SAVE: leaveSgeSave(dbswzsk); break;
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
			case VecVSge::SAVE: _ixVSge = enterSgeSave(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqPtcloud::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::READY) || (ixVSge == VecVSge::ACQUIRE) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::TURN) || (ixVSge == VecVSge::SAVE) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::READY) retval = "ready";
			else if (ixVSge == VecVSge::ACQUIRE) retval = "acquiring";
			else if (ixVSge == VecVSge::PROCESS) retval = "processing";
			else if (ixVSge == VecVSge::TURN) retval = "turning";
			else if (ixVSge == VecVSge::SAVE) retval = "saving";

			if ((ixVSge == VecVSge::ACQUIRE) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::TURN)) retval += " (" + to_string(shrdat.theta) + "\\u00b0 of 360\\u00b0 completed)";

		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
			else if (ixVSge == VecVSge::ACQUIRE) retval = "Aufzeichnung";
			else if (ixVSge == VecVSge::PROCESS) retval = "Verarbeitung";
			else if (ixVSge == VecVSge::TURN) retval = "Drehung";
			else if (ixVSge == VecVSge::SAVE) retval = "Speichern";

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

	if ((ixRiSrc + 1) != 0) {
		iprtrace->shrdat.result.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;
	};

	if (ixRi != shrdat.resultBody.size()) {
		shrdat.resultBody.unlock(0, ixRi);
		ixRi = shrdat.resultBody.size();
	};
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
	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	else if (!reenter) {
		xchg->addCsjobClaim(dbswzsk, iprtrace, new JobWzskIprTrace::Claim(false, true, false));
	};
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

	const double alphaLeft = atan2(stg.dLeft, stg.dWork + stg.dLasback);
	const double alphaRight = atan2(stg.dRight, stg.dWork + stg.dLasback);

	const double pixToDim = 1e-6 * xchg->stgwzskcamera.hpix;

	double rNotL;
	double alpha;

	double x_in, y_in;

	double rho;
	double x, y, z;

	double phi;

	// plain core algorithm
	rNotL = 1.0;
	alpha = alphaLeft;

	for (unsigned int i = 0; i < riSrc->x.size(); i++) {
		if (i == riSrc->Nleft) {
			rNotL = -1.0;
			alpha = alphaRight;
		};

		x_in = pixToDim * ((double) (riSrc->x[i]));
		y_in = pixToDim * ((double) (riSrc->y[i]));

		rho = fabs(x_in) * stg.dWork / (1e-3 * xchg->stgwzskcamera.f * sin(alpha) + fabs(x_in) * cos(alpha));

		x = rho * cos(alpha);
		y = rho * rNotL * sin(alpha);
		z = y_in / (1e-3 * xchg->stgwzskcamera.f) * (stg.dWork - rho * cos(alpha));

		phi = shrdat.theta * M_PI / 180.0;

		ri->rNotL.push_back(rNotL < 0.0);
		ri->x.push_back(x * cos(phi) - y * sin(phi));
		ri->y.push_back(x * sin(phi) + y * cos(phi));
		ri->z.push_back(z);
	};

	iprtrace->shrdat.result.unlock(jref, ixRiSrc);
	ixRiSrc = 0; ixRiSrc--;

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

	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure;
	else if (!reenter) {
		shrdat.theta += shrdat.deltaTheta;

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

			retval = VecVSge::SAVE;

		} else {
			// inform super-jobs; for partial results, they must not lock the result or perform any asynchronous processing
			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRi, "part");

			actservo->moveto(dbswzsk, shrdat.theta); // should return false
		};
	};
	// IP enterSgeTurn --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeTurn(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeTurn --- INSERT
};

uint JobWzskAcqPtcloud::enterSgeSave(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::SAVE;

	// IP enterSgeSave --- IBEGIN
	ubigint refWzskMShot;

	Shrdat::ResultitemBody* ri = NULL;

	string txtfile;
	fstream txtfi;

	string Filename;

	string s;

	ri = (Shrdat::ResultitemBody*) shrdat.resultBody[ixRi];

	if ((shrdat.refWzskMSession != 0) && (shrdat.refWzskMObject != 0)) {
		// shot / metadata
		refWzskMShot = dbswzsk->tblwzskmshot->insertNewRec(NULL, shrdat.refWzskMSession, shrdat.refWzskMObject, ri->tStart, "");

		dbswzsk->tblwzskamshotpar->insertNewRec(NULL, refWzskMShot, "deltaTheta", to_string(shrdat.deltaTheta));
		dbswzsk->tblwzskamshotpar->insertNewRec(NULL, refWzskMShot, "Npoint", to_string(ri->x.size()));

		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSHTMOD, jref);
		xchg->triggerRefCall(dbswzsk, VecWzskVCall::CALLWZSKSHTMOD_OBJEQ, jref, shrdat.refWzskMObject);
		xchg->triggerRefCall(dbswzsk, VecWzskVCall::CALLWZSKSHTMOD_SESEQ, jref, shrdat.refWzskMSession);

		// file
		txtfile = Tmp::newfile(xchg->tmppath, "txt");

		s = xchg->tmppath + "/" + txtfile;

		txtfi.open(s.c_str(), ios::out);

		for (unsigned int i = 0; i < ri->x.size(); i++) txtfi << ri->x[i] << "\t" << ri->y[i] << "\t" << ri->z[i] << endl;

		txtfi.close();

		Filename = "ptcloud1.txt";
		if (dbswzsk->loadStringBySQL("SELECT TblWzskMFile.Filename FROM TblWzskMObject, TblWzskMShot, TblWzskMFile WHERE TblWzskMObject.ref = " + to_string(shrdat.refWzskMObject)
					+ " AND TblWzskMShot.refWzskMObject = TblWzskMObject.ref AND TblWzskMFile.refIxVTbl = " + to_string(VecWzskVMFileRefTbl::SHT)
					+ " AND TblWzskMFile.refUref = TblWzskMShot.ref AND TblWzskMFile.Filename LIKE 'ptcloud%.txt' ORDER BY TblWzskMFile.ref DESC LIMIT 1", Filename)) {
			Filename = Filename.substr(0, Filename.rfind(".txt"));
			Filename = "ptcloud" + to_string(atoi(Filename.substr(7).c_str()) + 1) + ".txt";
		};

		Acv::addfile(dbswzsk, xchg->acvpath, xchg->tmppath + "/" + txtfile, xchg->getRefPreset(VecWzskVPreset::PREWZSKGROUP, jref), xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), VecWzskVMFileRefTbl::SHT, refWzskMShot, "xyz", Filename, "txt", "");
		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKFILMOD, jref);
		xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKFILMOD_RETREUEQ, jref, VecWzskVMFileRefTbl::SHT, refWzskMShot);
	};

	shrdat.resultBody.unlock(0, ixRi); // hadn't been locked within this class
	ixRi = shrdat.resultBody.size();

	retval = VecVSge::IDLE;
	// IP enterSgeSave --- IEND

	return retval;
};

void JobWzskAcqPtcloud::leaveSgeSave(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeSave --- INSERT
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
	ubigint refWzskMSession = 0;
	ubigint refWzskMObject = 0;

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
			refWzskMSession = claim->refWzskMSession;
			refWzskMObject = claim->refWzskMObject;
		};
	};

	// add claim with servo
	if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, actservo);
	else if ((jrefFulfilled == 0) && !claims.empty()) xchg->addCsjobClaim(dbswzsk, actservo, new Claim(false));

	xchg->getCsjobClaim(actservo, servoTakenNotAvailable, servoFulfilled);

	// add claim with trace
	if (claims.empty() || !servoFulfilled) xchg->removeCsjobClaim(dbswzsk, iprtrace);
	else if ((jrefFulfilled == 0) && !claims.empty()) xchg->addCsjobClaim(dbswzsk, iprtrace, new JobWzskIprTrace::Claim(false, false, false));

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
					refWzskMSession = claim->refWzskMSession;
					refWzskMObject = claim->refWzskMObject;

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
		nextIxVSgeFailure = VecVSge::IDLE;
		if ((ixVSge == VecVSge::ACQUIRE) || (ixVSge == VecVSge::TURN)) changeStage(dbswzsk, ixVSge); // re-enter

	} else if (run && servoFulfilled && traceFulfilled && (ixVSge == VecVSge::IDLE)) {
		shrdat.refWzskMSession = refWzskMSession;
		shrdat.refWzskMObject = refWzskMObject;

		nextIxVSgeFailure = VecVSge::READY;
		changeStage(dbswzsk, VecVSge::READY); // trace claim is removed / updated in stage acquire
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



