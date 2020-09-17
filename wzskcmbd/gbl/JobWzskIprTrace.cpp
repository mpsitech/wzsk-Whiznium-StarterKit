/**
	* \file JobWzskIprTrace.cpp
	* job handler for job JobWzskIprTrace (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskIprTrace.h"

#include "JobWzskIprTrace_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskIprTrace::Shrdat::ResultitemTrace
 ******************************************************************************/

JobWzskIprTrace::Shrdat::ResultitemTrace::ResultitemTrace() :
			Resultitem()
		{
	tIn = 0.0;
	tOut = 0.0;

	Nleft = 0;
	Nright = 0;
};

JobWzskIprTrace::Shrdat::ResultitemTrace::~ResultitemTrace() {
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskIprTrace::Shrdat
 ******************************************************************************/

JobWzskIprTrace::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskIprTrace", "Shrdat")
		{
};

void JobWzskIprTrace::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	pOnLeft = 0.5;
	pOnRight = 0.5;

	levelOn = 255;
	levelOff = 245;

	roiAx = -300;
	roiAy = -200;
	roiBx = 300;
	roiBy = -200;
	roiCx = 300;
	roiCy = 400;
	roiDx = -300;
	roiDy = 400;

	loopNotSngshot = false;

	for (unsigned int i = 0; i < 2; i++) result.append(new ResultitemTrace());
	// IP Shrdat.init --- IEND
};

void JobWzskIprTrace::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskIprTrace
 ******************************************************************************/

JobWzskIprTrace::JobWzskIprTrace(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKIPRTRACE, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcv4l2 = NULL;
	acqfpgaflg = NULL;
	actlaser = NULL;

	// IP constructor.cust1 --- IBEGIN
	ixRiSrcOn = 0; ixRiSrcOn--;
	ixRiSrc = 0; ixRiSrc--;

	ixRi = shrdat.result.size();
	// IP constructor.cust1 --- IEND

	// IP constructor.spec1 --- INSERT

	if (srvNotCli) actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) {
		if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) srcv4l2 = new JobWzskSrcV4l2(xchg, dbswzsk, jref, ixWzskVLocale);
		else acqfpgaflg = new JobWzskAcqFpgaflg(xchg, dbswzsk, jref, ixWzskVLocale);
	};
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) if (acqfpgaflg) xchg->addClstn(VecWzskVCall::CALLWZSKWAITSECOND, jref, Clstn::VecVJobmask::SPEC, acqfpgaflg->jref, false, Arg(), VecVSge::RIGHTON, Clstn::VecVJactype::LOCK);
	if (srvNotCli) if (acqfpgaflg) xchg->addClstn(VecWzskVCall::CALLWZSKWAITSECOND, jref, Clstn::VecVJobmask::SPEC, acqfpgaflg->jref, false, Arg(), VecVSge::LEFTON, Clstn::VecVJactype::LOCK);
	if (srvNotCli) if (srcv4l2) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, srcv4l2->jref, false, Arg(), 0, Clstn::VecVJactype::TRY);
	if (srvNotCli) if (acqfpgaflg) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqfpgaflg->jref, false, Arg(0,0,{},"thddelta",0,0.0,false,"",Arg::SREF), 0, Clstn::VecVJactype::LOCK);

	// IP constructor.cust3 --- IBEGIN
	flg16 = NULL;
	// IP constructor.cust3 --- IEND

	// IP constructor.spec3 --- INSERT
};

JobWzskIprTrace::~JobWzskIprTrace() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- IBEGIN
	if (flg16) delete[] flg16;
	// IP destructor.cust --- IEND

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskIprTrace::Claim::Claim(
			const bool retractable
			, const bool run
			, const bool loopNotSngshot
		) :
			Sbecore::Claim(retractable, run)
		{
	this->loopNotSngshot = loopNotSngshot;
};

void JobWzskIprTrace::flagV4l2(
			uint16_t* rd16
			, uint16_t* flg16
			, const uint16_t thd16
			, const bool deltaNotAbs
		) {
	uint16x8_t rd;

	const uint16_t one16 = 1;
	const int16x8_t shl = {7, 6, 5, 4, 3, 2, 1, 0};

	register uint16_t acc;

	unsigned int ldix0, ldix1;
	unsigned int stix;

	uint16x8_t d, e;

	d = vld1q_dup_u16(&one16);
	e = vld1q_dup_u16(&thd16);

	unsigned int NFlag = 0;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i++) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j += 16) {
			ldix0 = i * xchg->stgwzskframegeo.wGrrd + j;
			ldix1 = ldix0 + 8;

			rd = vld1q_u16(&(rd16[ldix0]));
			rd = vcgtq_u16(rd, e);
			rd = vandq_u16(rd, d);
			rd = vshlq_u16(rd, shl);

			acc = vgetq_lane_u16(rd, 7);
			acc |= vgetq_lane_u16(rd, 6);
			acc |= vgetq_lane_u16(rd, 5);
			acc |= vgetq_lane_u16(rd, 4);
			acc |= vgetq_lane_u16(rd, 3);
			acc |= vgetq_lane_u16(rd, 2);
			acc |= vgetq_lane_u16(rd, 1);
			acc |= vgetq_lane_u16(rd, 0);
			acc <<= 8;

			rd = vld1q_u16(&(rd16[ldix1]));
			rd = vcgtq_u16(rd, e);
			rd = vandq_u16(rd, d);
			rd = vshlq_u16(rd, shl);

			acc |= vgetq_lane_u16(rd, 7);
			acc |= vgetq_lane_u16(rd, 6);
			acc |= vgetq_lane_u16(rd, 5);
			acc |= vgetq_lane_u16(rd, 4);
			acc |= vgetq_lane_u16(rd, 3);
			acc |= vgetq_lane_u16(rd, 2);
			acc |= vgetq_lane_u16(rd, 1);
			acc |= vgetq_lane_u16(rd, 0);

			stix = i * xchg->stgwzskframegeo.wGrrd/16 + j/16;

			if (deltaNotAbs) acc = flg16[stix] & ~acc; // ~acc when using 2x gt as compared to gt/lt

			for (unsigned int r = 32768; r > 0; r >>= 1) if (acc & r) NFlag++;

			flg16[stix] = acc;
		};
	};

/*
	cout << "NFlag_raw = " << NFlag << " in ";
	if (!deltaNotAbs) cout << "abs";
	else cout << "delta";
	cout << " mode" << endl;
*/
};

void JobWzskIprTrace::deltaV4l2(
			uint16_t* on16
			, uint16_t* off16
			, uint16_t* flg16
			, const uint16_t thd16
		) {
	uint16x8_t on, off;
	int16x8_t delta;
	uint16x8_t flg;

	const uint16_t one16 = 1;
	const int16x8_t shl = {7, 6, 5, 4, 3, 2, 1, 0};

	register uint16_t acc;

	unsigned int ldix0, ldix1;
	unsigned int stix;

	uint16x8_t d;
	int16x8_t e;

	d = vld1q_dup_u16(&one16);
	e = vld1q_dup_s16((const int16_t*) &thd16);

	//unsigned int NFlag = 0;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i++) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j += 16) {
			ldix0 = i * xchg->stgwzskframegeo.wGrrd + j;
			ldix1 = ldix0 + 8;

			on = vld1q_u16(&(on16[ldix0]));
			off = vld1q_u16(&(off16[ldix0]));

			delta = vsubq_s16(vreinterpretq_s16_u16(on), vreinterpretq_s16_u16(off));
			flg = vcgtq_s16(delta, e);
			flg = vandq_u16(flg, d);
			flg = vshlq_u16(flg, shl);

			acc = vgetq_lane_u16(flg, 7);
			acc |= vgetq_lane_u16(flg, 6);
			acc |= vgetq_lane_u16(flg, 5);
			acc |= vgetq_lane_u16(flg, 4);
			acc |= vgetq_lane_u16(flg, 3);
			acc |= vgetq_lane_u16(flg, 2);
			acc |= vgetq_lane_u16(flg, 1);
			acc |= vgetq_lane_u16(flg, 0);
			acc <<= 8;

			on = vld1q_u16(&(on16[ldix1]));
			off = vld1q_u16(&(off16[ldix1]));

			delta = vsubq_s16(vreinterpretq_s16_u16(on), vreinterpretq_s16_u16(off));
			flg = vcgtq_s16(delta, e);
			flg = vandq_u16(flg, d);
			flg = vshlq_u16(flg, shl);

			acc |= vgetq_lane_u16(flg, 7);
			acc |= vgetq_lane_u16(flg, 6);
			acc |= vgetq_lane_u16(flg, 5);
			acc |= vgetq_lane_u16(flg, 4);
			acc |= vgetq_lane_u16(flg, 3);
			acc |= vgetq_lane_u16(flg, 2);
			acc |= vgetq_lane_u16(flg, 1);
			acc |= vgetq_lane_u16(flg, 0);

			stix = i * xchg->stgwzskframegeo.wGrrd/16 + j/16;

			//for (unsigned int r = 32768; r > 0; r >>= 1) if (acc & r) NFlag++;

			flg16[stix] = acc;
		};
	};
};
// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskIprTrace::setLevel(
			DbsWzsk* dbswzsk
			, const utinyint levelOn
			, const utinyint levelOff
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskIprTrace*) srv)->setLevel(dbswzsk, levelOn, levelOff);

		} else retval = false;

		return retval;
	};

	lockAccess("setLevel");

	// IP setLevel --- IBEGIN
	shrdat.wlockAccess(jref, "setLevel");

	shrdat.levelOn = levelOn;
	shrdat.levelOff = levelOff;

	shrdat.wunlockAccess(jref, "setLevel");

	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTGCHG, jref);
	// IP setLevel --- IEND

	unlockAccess("setLevel");

	return retval;
};

bool JobWzskIprTrace::setRoi(
			DbsWzsk* dbswzsk
			, const int roiAx
			, const int roiAy
			, const int roiBx
			, const int roiBy
			, const int roiCx
			, const int roiCy
			, const int roiDx
			, const int roiDy
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskIprTrace*) srv)->setRoi(dbswzsk, roiAx, roiAy, roiBx, roiBy, roiCx, roiCy, roiDx, roiDy);

		} else retval = false;

		return retval;
	};

	lockAccess("setRoi");

	// IP setRoi --- IBEGIN
	shrdat.wlockAccess(jref, "setRoi");

	shrdat.roiAx = roiAx;
	shrdat.roiAy = roiAy;
	shrdat.roiBx = roiBx;
	shrdat.roiBy = roiBy;
	shrdat.roiCx = roiCx;
	shrdat.roiCy = roiCy;
	shrdat.roiDx = roiDx;
	shrdat.roiDy = roiDy;

	shrdat.wunlockAccess(jref, "setRoi");

	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "roiAxRoiAyRoiBxRoiByRoiCxRoiCyRoiDxRoiDy");
	// IP setRoi --- IEND

	unlockAccess("setRoi");

	return retval;
};

bool JobWzskIprTrace::setRoiNotFull(
			DbsWzsk* dbswzsk
			, const bool roiNotFull
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskIprTrace*) srv)->setRoiNotFull(dbswzsk, roiNotFull);

		} else retval = false;

		return retval;
	};

	lockAccess("setRoiNotFull");

	// IP setRoiNotFull --- IBEGIN
	stg.roiNotFull = roiNotFull;

	xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKSTGCHG, jref);
	// IP setRoiNotFull --- IEND

	unlockAccess("setRoiNotFull");

	return retval;
};

void JobWzskIprTrace::handleRequest(
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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRTRACEMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETLEVEL) && (req->method->parsInv.size() == 2) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setLevel(dbswzsk, *((const utinyint*) (req->method->parsInv[0])), *((const utinyint*) (req->method->parsInv[1])));
		} else if ((ixVMethod == VecVMethod::SETROI) && (req->method->parsInv.size() == 8) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setRoi(dbswzsk, *((const int*) (req->method->parsInv[0])), *((const int*) (req->method->parsInv[1])), *((const int*) (req->method->parsInv[2])), *((const int*) (req->method->parsInv[3])), *((const int*) (req->method->parsInv[4])), *((const int*) (req->method->parsInv[5])), *((const int*) (req->method->parsInv[6])), *((const int*) (req->method->parsInv[7])));
		} else if ((ixVMethod == VecVMethod::SETROINOTFULL) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setRoiNotFull(dbswzsk, *((const bool*) (req->method->parsInv[0])));
		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRCIDLE) handleTimerInSgePrcidle(dbswzsk, req->sref);
		else if ((req->sref == "srcstop") && (ixVSge == VecVSge::DONE)) handleTimerWithSrefSrcstopInSgeDone(dbswzsk);
	};
};

bool JobWzskIprTrace::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskIprTrace::handleTimerInSgePrcidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void JobWzskIprTrace::handleTimerWithSrefSrcstopInSgeDone(
			DbsWzsk* dbswzsk
		) {
	changeStage(dbswzsk, VecVSge::IDLE);
};

void JobWzskIprTrace::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKWAITSECOND) && ([&](){bool match = false; if (acqfpgaflg) if (call->jref == acqfpgaflg->jref) match = true; return match;}()) && (ixVSge == VecVSge::RIGHTON)) {
		call->abort = handleCallWzskWaitsecondFromAcqfpgaflgInSgeRighton(dbswzsk);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKWAITSECOND) && ([&](){bool match = false; if (acqfpgaflg) if (call->jref == acqfpgaflg->jref) match = true; return match;}()) && (ixVSge == VecVSge::LEFTON)) {
		call->abort = handleCallWzskWaitsecondFromAcqfpgaflgInSgeLefton(dbswzsk);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && ([&](){bool match = false; if (srcv4l2) if (call->jref == srcv4l2->jref) match = true; return match;}())) {
		call->abort = handleCallWzskResultNewFromSrcv4l2(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && ([&](){bool match = false; if (acqfpgaflg) if (call->jref == acqfpgaflg->jref) match = true; return match;}()) && (call->argInv.sref == "thddelta")) {
		call->abort = handleCallWzskResultNewFromAcqfpgaflgWithSrefThddelta(dbswzsk, call->argInv.ix);
	};
};

bool JobWzskIprTrace::handleCallWzskWaitsecondFromAcqfpgaflgInSgeRighton(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	changeStage(dbswzsk, VecVSge::RIGHTOFF); // IP handleCallWzskWaitsecondFromAcqfpgaflgInSgeRighton --- ILINE
	return retval;
};

bool JobWzskIprTrace::handleCallWzskWaitsecondFromAcqfpgaflgInSgeLefton(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	changeStage(dbswzsk, VecVSge::LEFTOFF); // IP handleCallWzskWaitsecondFromAcqfpgaflgInSgeLefton --- ILINE
	return retval;
};

bool JobWzskIprTrace::handleCallWzskResultNewFromSrcv4l2(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromSrcv4l2 --- IBEGIN
	ShrdatJobWzskSrcV4l2::ResultitemAcq* riSrcv4l2 = NULL;

	if ( (tMin != 0.0) && ((ixVSge == VecVSge::LEFTON) || (ixVSge == VecVSge::LEFTOFF) || (ixVSge == VecVSge::RIGHTON) || (ixVSge == VecVSge::RIGHTOFF)) ) {
		riSrcv4l2 = (ShrdatJobWzskSrcV4l2::ResultitemAcq*) srcv4l2->shrdat.resultAcq[ixInv];

		if (riSrcv4l2->t > (tMin + 1.0/7.5)) { // preliminary, relevant for v4l2 as capture start time not known
			srcv4l2->shrdat.resultAcq.lock(jref, ixInv);

			if ((ixVSge == VecVSge::LEFTON) || (ixVSge == VecVSge::RIGHTON)) {
				ixRiSrcOn = ixInv;

				if (ixVSge == VecVSge::LEFTON) changeStage(dbswzsk, VecVSge::LEFTOFF);
				else changeStage(dbswzsk, VecVSge::RIGHTOFF);

			} else {
				ixRiSrc = ixInv;
				changeStage(dbswzsk, VecVSge::PRCIDLE);
			};
		};
	};
	// IP handleCallWzskResultNewFromSrcv4l2 --- IEND
	return retval;
};

bool JobWzskIprTrace::handleCallWzskResultNewFromAcqfpgaflgWithSrefThddelta(
			DbsWzsk* dbswzsk
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqfpgaflgWithSrefThddelta --- IBEGIN
	acqfpgaflg->shrdat.resultFlg.lock(jref, ixRiSrc);
	ixRiSrc = ixInv;

	changeStage(dbswzsk, VecVSge::PRCIDLE);
	// IP handleCallWzskResultNewFromAcqfpgaflgWithSrefThddelta --- IEND
	return retval;
};

void JobWzskIprTrace::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::READY: leaveSgeReady(dbswzsk); break;
				case VecVSge::PRCIDLE: leaveSgePrcidle(dbswzsk); break;
				case VecVSge::PROCESS: leaveSgeProcess(dbswzsk); break;
				case VecVSge::LEFTON: leaveSgeLefton(dbswzsk); break;
				case VecVSge::LEFTOFF: leaveSgeLeftoff(dbswzsk); break;
				case VecVSge::RIGHTON: leaveSgeRighton(dbswzsk); break;
				case VecVSge::RIGHTOFF: leaveSgeRightoff(dbswzsk); break;
				case VecVSge::DONE: leaveSgeDone(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			//cout << "JobWzskIprTrace entering stage " << VecVSge::getSref(_ixVSge) << endl; // IP changeStage.refresh1 --- ILINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbswzsk, reenter); break;
			case VecVSge::PRCIDLE: _ixVSge = enterSgePrcidle(dbswzsk, reenter); break;
			case VecVSge::PROCESS: _ixVSge = enterSgeProcess(dbswzsk, reenter); break;
			case VecVSge::LEFTON: _ixVSge = enterSgeLefton(dbswzsk, reenter); break;
			case VecVSge::LEFTOFF: _ixVSge = enterSgeLeftoff(dbswzsk, reenter); break;
			case VecVSge::RIGHTON: _ixVSge = enterSgeRighton(dbswzsk, reenter); break;
			case VecVSge::RIGHTOFF: _ixVSge = enterSgeRightoff(dbswzsk, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskIprTrace::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::READY) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::LEFTON) || (ixVSge == VecVSge::LEFTOFF) || (ixVSge == VecVSge::RIGHTON) || (ixVSge == VecVSge::RIGHTOFF) || (ixVSge == VecVSge::DONE) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::READY) retval = "ready";
			else if (ixVSge == VecVSge::PROCESS) retval = "processing";
			else if (ixVSge == VecVSge::LEFTON) retval = "left line laser on";
			else if (ixVSge == VecVSge::LEFTOFF) retval = "left line laser off";
			else if (ixVSge == VecVSge::RIGHTON) retval = "right line laser on";
			else if (ixVSge == VecVSge::RIGHTOFF) retval = "right line laser off";
			else if (ixVSge == VecVSge::DONE) retval = "done";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
			else if (ixVSge == VecVSge::PROCESS) retval = "Verarbeitung";
			else if (ixVSge == VecVSge::LEFTON) retval = "linker Linienlaser ein";
			else if (ixVSge == VecVSge::LEFTOFF) retval = "linker Linienlaser aus";
			else if (ixVSge == VecVSge::RIGHTON) retval = "rechter Linienlaser ein";
			else if (ixVSge == VecVSge::RIGHTOFF) retval = "rechter Linienlaser aus";
			else if (ixVSge == VecVSge::DONE) retval = "fertig";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskIprTrace::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	bool srcTakenNotAvailable, srcFulfilled;

	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);

	// set source claim to stop
	if (srcv4l2) {
		xchg->getCsjobClaim(srcv4l2, srcTakenNotAvailable, srcFulfilled);
		if (srcFulfilled) xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, false));

	} else if (acqfpgaflg) {
		xchg->getCsjobClaim(acqfpgaflg, srcTakenNotAvailable, srcFulfilled);
		if (srcFulfilled) xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, false, true, true));
	};

	if ((ixRiSrc + 1) != 0) {
		if (srcv4l2) srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		else if (acqfpgaflg) acqfpgaflg->shrdat.resultFlg.unlock(jref, ixRiSrc);

		ixRiSrc = 0; ixRiSrc--;
	};

	if ((ixRiSrcOn + 1) != 0) {
		if (srcv4l2) srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrcOn);
		ixRiSrcOn = 0; ixRiSrcOn--;
	};

	if (ixRi != shrdat.result.size()) {
		shrdat.result.unlock(0, ixRi);
		ixRi = shrdat.result.size();
	};
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskIprTrace::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- IBEGIN
	Shrdat::ResultitemTrace* ri = NULL;

	if (srcv4l2 && !flg16) flg16 = new uint16_t[xchg->stgwzskframegeo.wGrrd/16 * xchg->stgwzskframegeo.hGrrd];

	if (stg.leftOnNotOff || stg.rightOnNotOff) {
		if (shrdat.result.dequeue(ixRi)) {
			ri = (Shrdat::ResultitemTrace*) shrdat.result[ixRi];

			ri->tIn = 0.0;
			ri->tOut = 0.0;

			ri->Nleft = 0;
			ri->Nright = 0;

			ri->x.clear();
			ri->y.clear();

			// set source claim to run
			if (srcv4l2) xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, true));
			else if (acqfpgaflg) xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, true, true, true));

			if (stg.leftOnNotOff) retval = VecVSge::LEFTON;
			else retval = VecVSge::RIGHTON;

		} else {
			retval = VecVSge::IDLE;
		};

	} else retval = VecVSge::IDLE;
	// IP enterSgeReady --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobWzskIprTrace::enterSgePrcidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRCIDLE;
	nextIxVSgeSuccess = VecVSge::PROCESS;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrcidle --- INSERT

	return retval;
};

void JobWzskIprTrace::leaveSgePrcidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrcidle --- INSERT
};

uint JobWzskIprTrace::enterSgeProcess(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PROCESS;

	// IP enterSgeProcess --- IBEGIN
	// shorthands
	const uint wGrrd = xchg->stgwzskframegeo.wGrrd;
	const uint hGrrd = xchg->stgwzskframegeo.hGrrd;
	//

	ShrdatJobWzskSrcV4l2::ResultitemAcq* riSrcv4l2On = NULL;
	ShrdatJobWzskSrcV4l2::ResultitemAcq* riSrcv4l2 = NULL;

	ShrdatJobWzskAcqFpgaflg::ResultitemFlg* riSrcfpga = NULL;

	Shrdat::ResultitemTrace* ri = NULL;

	string srefRi;

	ri = (Shrdat::ResultitemTrace*) shrdat.result[ixRi];

	if (ri->tIn == 0.0) ri->tIn = Wzsk::getNow();

	if (srcv4l2 && !stg.v4l2RdNotDelta) {
		// should only arrive here after LEFTOFF or RIGHTOFF
		riSrcv4l2On = (ShrdatJobWzskSrcV4l2::ResultitemAcq*) srcv4l2->shrdat.resultAcq[ixRiSrcOn];
		riSrcv4l2 = (ShrdatJobWzskSrcV4l2::ResultitemAcq*) srcv4l2->shrdat.resultAcq[ixRiSrc];

		//deltaV4l2(riSrcv4l2On->rd16, riSrcv4l2->rd16, flg16, shrdat.levelOn - shrdat.levelOff);
		deltaV4l2(riSrcv4l2On->gr16, riSrcv4l2->gr16, flg16, shrdat.levelOn - shrdat.levelOff);

		Wzsk::bitmapToXy((unsigned char*) flg16, true, wGrrd, hGrrd, ri->x, ri->y, stg.flgPerRowMax, stg.roiNotFull, {shrdat.roiAx,shrdat.roiBx,shrdat.roiCx,shrdat.roiDx}, {shrdat.roiAy,shrdat.roiBy,shrdat.roiCy,shrdat.roiDy}, rightNotLeft);
		//cout << "NFlag = " << ri->x.size() << endl;

		ri->tOut = Wzsk::getNow();

		srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrcOn);
		ixRiSrcOn = 0; ixRiSrcOn--;

		srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;

	} else if (srcv4l2 && stg.v4l2RdNotDelta) {
		riSrcv4l2 = (ShrdatJobWzskSrcV4l2::ResultitemAcq*) srcv4l2->shrdat.resultAcq[ixRiSrc];

		//flagV4l2(riSrcv4l2->rd16, flg16, (onNotOff) ? shrdat.levelOn : shrdat.levelOff, !onNotOff);
		flagV4l2(riSrcv4l2->gr16, flg16, (onNotOff) ? shrdat.levelOn : shrdat.levelOff, !onNotOff);
		if (!onNotOff) {
			Wzsk::bitmapToXy((unsigned char*) flg16, true, wGrrd, hGrrd, ri->x, ri->y, stg.flgPerRowMax, stg.roiNotFull, {shrdat.roiAx,shrdat.roiBx,shrdat.roiCx,shrdat.roiDx}, {shrdat.roiAy,shrdat.roiBy,shrdat.roiCy,shrdat.roiDy}, rightNotLeft);
			//cout << "NFlag = " << ri->x.size() << endl;
		};

		ri->tOut = Wzsk::getNow();

		srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;

	} else if (acqfpgaflg) {
		// should only arrive here after LEFTOFF or RIGHTOFF
		riSrcfpga = (ShrdatJobWzskAcqFpgaflg::ResultitemFlg*) acqfpgaflg->shrdat.resultFlg[ixRiSrc];

		Wzsk::bitmapToXy(riSrcfpga->buf, false, wGrrd, hGrrd, ri->x, ri->y, stg.flgPerRowMax, stg.roiNotFull, {shrdat.roiAx,shrdat.roiBx,shrdat.roiCx,shrdat.roiDx}, {shrdat.roiAy,shrdat.roiBy,shrdat.roiCy,shrdat.roiDy}, rightNotLeft);

		ri->tOut = Wzsk::getNow();

		acqfpgaflg->shrdat.resultFlg.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;
	};

	if (!onNotOff) {
		if (!rightNotLeft) ri->Nleft = ri->x.size();
		else ri->Nright = ri->x.size() - ri->Nleft;
	};

	if (!rightNotLeft && onNotOff) {
		retval = VecVSge::LEFTOFF;

	} else if (!rightNotLeft && !onNotOff) {
		if (stg.rightOnNotOff) retval = VecVSge::RIGHTON;
		else {
			srefRi = "left";

			if (!shrdat.loopNotSngshot) retval = VecVSge::DONE;
			else retval = VecVSge::READY;
		};

	} else if (rightNotLeft && onNotOff) {
		retval = VecVSge::RIGHTOFF;

	} else {
		if (!stg.leftOnNotOff) srefRi = "right";
		else srefRi = "leftRight";
	
		if (!shrdat.loopNotSngshot) retval = VecVSge::DONE;
		else retval = VecVSge::READY;
	};

	if ((retval == VecVSge::READY) || (retval == VecVSge::DONE)) {
		// update shrdat
		shrdat.wlockAccess(jref, "enterSgeProcess");

		shrdat.left.clear();
		shrdat.left.resize(wGrrd * hGrrd, false);

		shrdat.right.clear();
		shrdat.right.resize(wGrrd * hGrrd, false);

		for (unsigned int i = 0; i < ri->Nleft; i++) shrdat.left[(ri->y[i] + hGrrd/2) * wGrrd + (ri->x[i] + wGrrd/2)] = true;
		for (unsigned int i = ri->Nleft; i < ri->x.size(); i++) shrdat.right[(ri->y[i] + hGrrd/2) * wGrrd + (ri->x[i] + wGrrd/2)] = true;

		shrdat.wunlockAccess(jref, "enterSgeProcess");

		xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "leftRight");

		// inform super-jobs
		xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRi, srefRi);

		shrdat.result.unlock(0, ixRi); // hadn't been locked within this class
		ixRi = shrdat.result.size();
	};
	// IP enterSgeProcess --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeProcess(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeProcess --- INSERT
};

uint JobWzskIprTrace::enterSgeLefton(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::LEFTON;

	// IP enterSgeLefton --- IBEGIN
	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	else if (!reenter) {
		rightNotLeft = false;
		onNotOff = true;

		actlaser->setLeft(dbswzsk, 1.0);
		actlaser->setRight(dbswzsk, 0.0);

		if (srcv4l2) tMin = Wzsk::getNow();
		else xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, true, true, true));
	};
	// IP enterSgeLefton --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeLefton(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeLefton --- INSERT
};

uint JobWzskIprTrace::enterSgeLeftoff(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::LEFTOFF;

	// IP enterSgeLeftoff --- IBEGIN
	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	else if (!reenter) {
		rightNotLeft = false;
		onNotOff = false;

		actlaser->setLeft(dbswzsk, 0.0);

		if (srcv4l2) tMin = Wzsk::getNow();
		else acqfpgaflg->trigger();
	};
	// IP enterSgeLeftoff --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeLeftoff(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeLeftoff --- INSERT
};

uint JobWzskIprTrace::enterSgeRighton(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RIGHTON;

	// IP enterSgeRighton --- IBEGIN
	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	else if (!reenter) {
		rightNotLeft = true;
		onNotOff = true;

		actlaser->setRight(dbswzsk, 1.0);

		if (srcv4l2) tMin = Wzsk::getNow();
		else xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, true, true, true));
	};
	// IP enterSgeRighton --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeRighton(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRighton --- INSERT
};

uint JobWzskIprTrace::enterSgeRightoff(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RIGHTOFF;

	// IP enterSgeRightoff --- IBEGIN
	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	else if (!reenter) {
		rightNotLeft = true;
		onNotOff = false;

		actlaser->setRight(dbswzsk, 0.0);

		if (srcv4l2) tMin = Wzsk::getNow();
		else acqfpgaflg->trigger();
	};
	// IP enterSgeRightoff --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeRightoff(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRightoff --- INSERT
};

uint JobWzskIprTrace::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN
	wrefLast = xchg->addWakeup(jref, "srcstop", 3000000);
	// IP enterSgeDone --- IEND

	return retval;
};

void JobWzskIprTrace::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups(); // IP leaveSgeDone --- ILINE
};

bool JobWzskIprTrace::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if actlaser and srcv4l2/acqfpgaflg claims can be fulfilled
	// - change stage to ready if fulfilled claim is run (run is one-shot)

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;
	bool loopNotSngshot = false;

	bool available;
	bool reattributed;

	bool laserTakenNotAvailable, laserFulfilled;

	bool srcTakenNotAvailable;
	bool srcFulfilled = false;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefFulfilled = it->first;
			retractable = claim->retractable;
			run = claim->run;
			loopNotSngshot = claim->loopNotSngshot;
		};
	};

	// add claim with laser
	if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, actlaser);
	else if ((jrefFulfilled == 0) && !claims.empty()) xchg->addCsjobClaim(dbswzsk, actlaser, new Claim(false));

	xchg->getCsjobClaim(actlaser, laserTakenNotAvailable, laserFulfilled);

	// add (preliminary) or remove claim with source
	if (srcv4l2) {
		if (claims.empty() || !laserFulfilled) xchg->removeCsjobClaim(dbswzsk, srcv4l2);
		else if ((jrefFulfilled == 0) && !claims.empty() && (ixVSge == VecVSge::IDLE)) xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, false));

		xchg->getCsjobClaim(srcv4l2, srcTakenNotAvailable, srcFulfilled);
		
	} else if (acqfpgaflg) {
		if (claims.empty() || !laserFulfilled) xchg->removeCsjobClaim(dbswzsk, acqfpgaflg);
		else if ((jrefFulfilled == 0) && !claims.empty() && (ixVSge == VecVSge::IDLE)) xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, false, true, true));

		xchg->getCsjobClaim(acqfpgaflg, srcTakenNotAvailable, srcFulfilled);
	};

	if (laserFulfilled && !srcFulfilled) xchg->removeCsjobClaim(dbswzsk, actlaser);

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && laserFulfilled && srcFulfilled;

			if (!available) break;

			if (((i == 0) && (it->first == jrefNewest)) || ((i == 1) && (it->first != jrefNewest))) {
				// preference given to newest claim
				if (it->first != jrefFulfilled) {
					if (jrefFulfilled != 0) claims[jrefFulfilled]->fulfilled = false;

					claim->fulfilled = true;
					retractable = claim->retractable;
					run = claim->run;
					loopNotSngshot = claim->loopNotSngshot;

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

	shrdat.loopNotSngshot = loopNotSngshot;

	// initiate stage change
	if (!run) {
		nextIxVSgeFailure = VecVSge::IDLE;
		if ((ixVSge == VecVSge::LEFTON) || (ixVSge == VecVSge::LEFTOFF) || (ixVSge == VecVSge::RIGHTON) || (ixVSge == VecVSge::RIGHTOFF)) changeStage(dbswzsk, ixVSge); // re-enter

	} else if (run && laserFulfilled && srcFulfilled && ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::DONE))) {
		nextIxVSgeFailure = VecVSge::READY;
		changeStage(dbswzsk, VecVSge::READY); // source claim is set to run entering stage ready and discarded entering stage idle
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};



