/**
	* \file JobWzskIprCorner.cpp
	* job handler for job JobWzskIprCorner (implementation)
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

#include "JobWzskIprCorner.h"

#include "JobWzskIprCorner_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskIprCorner::Shrdat::ResultitemCorner
 ******************************************************************************/

JobWzskIprCorner::Shrdat::ResultitemCorner::ResultitemCorner() :
			Resultitem()
		{
	NCorner = 0;
	thd = 0;

	tIn = 0.0;
	tOut = 0.0;
};

JobWzskIprCorner::Shrdat::ResultitemCorner::~ResultitemCorner() {
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskIprCorner::Shrdat
 ******************************************************************************/

JobWzskIprCorner::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskIprCorner", "Shrdat")
		{
};

void JobWzskIprCorner::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	NTarget = 256;

	roiAx = -512;
	roiAy = 384;
	roiBx = 512;
	roiBy = 384;
	roiCx = 512;
	roiCy = 150;
	roiDx = -512;
	roiDy = 150;

	shift = 0;
	scoreMin = 0;
	scoreMax = 0;

	loopNotSngshot = false;

	for (unsigned int i = 0; i < 2; i++) result.append(new ResultitemCorner());

	thd = 255;
	// IP Shrdat.init --- IEND
};

void JobWzskIprCorner::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskIprCorner
 ******************************************************************************/

JobWzskIprCorner::JobWzskIprCorner(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKIPRCORNER, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcv4l2 = NULL;
	acqfpgaflg = NULL;

	// IP constructor.cust1 --- IBEGIN
	ixRiSrc = 0; ixRiSrc--;
	ixRi = shrdat.result.size();

	shift_last = 0;
	// IP constructor.cust1 --- IEND

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) {
		if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) srcv4l2 = new JobWzskSrcV4l2(xchg, dbswzsk, jref, ixWzskVLocale);
		else acqfpgaflg = new JobWzskAcqFpgaflg(xchg, dbswzsk, jref, ixWzskVLocale);
	};
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) if (srcv4l2) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, srcv4l2->jref, false, Arg(), VecVSge::READY, Clstn::VecVJactype::TRY);
	if (srvNotCli) if (acqfpgaflg) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqfpgaflg->jref, false, Arg(0,0,{},"corner",0,0.0,false,"",Arg::SREF), VecVSge::READY, Clstn::VecVJactype::TRY);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskIprCorner::~JobWzskIprCorner() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskIprCorner::Claim::Claim(
			const bool retractable
			, const bool run
			, const bool loopNotSngshot
		) :
			Sbecore::Claim(retractable, run)
		{
	this->loopNotSngshot = loopNotSngshot;
};

void JobWzskIprCorner::scoreV4l2(
			uint16_t* gr16
			, uint16_t* score16
			, const bool linNotLog
			, utinyint& shift
			, utinyint& _scoreMin
			, utinyint& _scoreMax
		) {
	int64_t* score = NULL; // 1024 x 768

	int64_t* fiverowXsqr;
	int64_t* fiverowYsqr;
	int64_t* fiverowXy;

	int64_t dx, dy;
	
	int64_t sumX, sumY, sumXY;
	int64_t termI, termII, termIIIk;
	int64_t r;

	int64_t scoreMin, scoreMax;

	utinyint testshift;
	int64_t test = 0;

	vector<unsigned int> hist;

	uint16_t r16;

	unsigned int ldix;
	unsigned int stix;

	unsigned int ixFiverow;

	score = new int64_t[xchg->stgwzskframegeo.wGrrd * xchg->stgwzskframegeo.hGrrd];

	fiverowXsqr = new int64_t[5 * xchg->stgwzskframegeo.wGrrd];
	fiverowYsqr = new int64_t[5 * xchg->stgwzskframegeo.wGrrd];
	fiverowXy = new int64_t[5 * xchg->stgwzskframegeo.wGrrd];

	scoreMin = numeric_limits<int64_t>::max();
	scoreMax = numeric_limits<int64_t>::min();

	ixFiverow = 0;
	
	for (unsigned int i = 1; i < xchg->stgwzskframegeo.hGrrd; i++) {
		ixFiverow = (i - 1) % 5;

		for (unsigned int j = 1; j < xchg->stgwzskframegeo.wGrrd; j++) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;
			stix = ixFiverow * xchg->stgwzskframegeo.wGrrd + j;

			dx = gr16[ldix] - gr16[ldix - 1];
			dy = gr16[ldix] - gr16[ldix - xchg->stgwzskframegeo.wGrrd];

			fiverowXsqr[stix] = dx * dx;
			fiverowYsqr[stix] = dy * dy;
			fiverowXy[stix] = dx * dy;
		};

		if (i >= 5) {
			for (unsigned int j = 5; j < xchg->stgwzskframegeo.wGrrd; j++) {
				sumX = 0;
				sumY = 0;
				sumXY = 0;
				
				for (unsigned int k = 0; k < 5; k++)
					for (unsigned int l = 0; l < 5; l++) {
						sumX += fiverowXsqr[k * xchg->stgwzskframegeo.wGrrd + j - l];
						sumY += fiverowYsqr[k * xchg->stgwzskframegeo.wGrrd + j - l];
						sumXY += fiverowXy[k * xchg->stgwzskframegeo.wGrrd + j - l];
					};

				termI = sumX * sumY;
				termII = sumXY * sumXY;

				termIIIk = sumX + sumY;
				termIIIk = termIIIk * termIIIk;
				termIIIk = (5 * termIIIk) / 128;

				r = termI - termII - termIIIk;

				if (r < scoreMin) scoreMin = r;
				if (r > scoreMax) scoreMax = r;

				stix = (i - 2) * xchg->stgwzskframegeo.wGrrd + j - 2;
				score[stix] = r;
			};
		};
	};

	if (!linNotLog) {
		shift = 0;

	} else {
		for (test = 1, shift = 0; ; test *= 2, shift++) if (test >= scoreMax)  break;
		if (shift >= 8) shift -= 8;
	};

	_scoreMin = 255;
	_scoreMax = 0;

	hist.resize(256, 0);

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i++) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j++) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;

			r = score[ldix];

			if (!linNotLog) {
				if (r <= 0) r16 = 0;
				else {
					// format: EEEEEEMM
					// ex. 0x0002 = 0b0000 0000 0000 0010 => E = 0, M 0b10 => 0b0000 0010

					// ex. 0x0004 = 0b0000 0000 0000 0100 => E = 1, M 0b00 => 0b0000 0100
					// ex. 0x0005 = 0b0000 0000 0000 0101 => E = 1, M 0b01 => 0b0000 0101
					// ex. 0x0009 = 0b0000 0000 0000 1001 => E = 2, M 0b00 => 0b0000 1000

					if (r < 4) r16 = r;
					else
						for (test = 8, testshift = 1; ; test *= 2, testshift++)
							if (r < test) {
								r16 = (testshift << 2) + ((r >> (testshift - 1)) & 0x0003);
								break;
							};
				};

			} else {
				if (r < 0) r16 = 0;
				else r16 = (r >> shift);
			};

			if (r16 < _scoreMin) _scoreMin = r16;
			if (r16 > _scoreMax) _scoreMax = r16;

			score16[ldix] = r16;
			hist[r16]++;
		};
	};

/*
	cout << "score histogram" << endl;
	for (unsigned int i = 0; i < hist.size(); i++) {
		if ((i % 16) != 0) cout << "\t";
		cout << hist[i];
		if ((i % 16) == 15) cout << endl;
	};
*/

	delete[] score;

	delete[] fiverowXsqr;
	delete[] fiverowYsqr;
	delete[] fiverowXy;
};

void JobWzskIprCorner::scoreV4l2Fp(
			uint16_t* gr16
			, uint16_t* score16
			, const bool linNotLog
			, utinyint& shift
			, utinyint& _scoreMin
			, utinyint& _scoreMax
		) {
	float* scoreFp = NULL; // 1024 x 768

	float* fiverowXsqr;
	float* fiverowYsqr;
	float* fiverowXy;

	float dx, dy;
	
	float sumX, sumY, sumXY;
	float termI, termII, termIIIk;

	float r;
	uint32_t r_bits;

	float scoreMin, scoreMax;

	float test = 0.0;

	vector<unsigned int> hist;

	uint16_t r16;

	unsigned int ldix;
	unsigned int stix;

	unsigned int ixFiverow;

	scoreFp = new float[xchg->stgwzskframegeo.wGrrd * xchg->stgwzskframegeo.hGrrd];

	fiverowXsqr = new float[5 * xchg->stgwzskframegeo.wGrrd];
	fiverowYsqr = new float[5 * xchg->stgwzskframegeo.wGrrd];
	fiverowXy = new float[5 * xchg->stgwzskframegeo.wGrrd];

	scoreMin = numeric_limits<float>::max();
	scoreMax = numeric_limits<float>::min();

	ixFiverow = 0;
	
	for (unsigned int i = 1; i < xchg->stgwzskframegeo.hGrrd; i++) {
		ixFiverow = (i - 1) % 5;

		for (unsigned int j = 1; j < xchg->stgwzskframegeo.wGrrd; j++) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;
			stix = ixFiverow * xchg->stgwzskframegeo.wGrrd + j;

			dx = gr16[ldix] - gr16[ldix - 1];
			dy = gr16[ldix] - gr16[ldix - xchg->stgwzskframegeo.wGrrd];

			fiverowXsqr[stix] = dx * dx;
			fiverowYsqr[stix] = dy * dy;
			fiverowXy[stix] = dx * dy;
		};

		if (i >= 5) {
			for (unsigned int j = 5; j < xchg->stgwzskframegeo.wGrrd; j++) {
				sumX = 0;
				sumY = 0;
				sumXY = 0;
				
				for (unsigned int k = 0; k < 5; k++)
					for (unsigned int l = 0; l < 5; l++) {
						sumX += fiverowXsqr[k * xchg->stgwzskframegeo.wGrrd + j - l];
						sumY += fiverowYsqr[k * xchg->stgwzskframegeo.wGrrd + j - l];
						sumXY += fiverowXy[k * xchg->stgwzskframegeo.wGrrd + j - l];
					};

				termI = sumX * sumY;
				termII = sumXY * sumXY;

				termIIIk = sumX + sumY;
				termIIIk = termIIIk * termIIIk;
				termIIIk = (5.0 * termIIIk) / 128.0;

				r = termI - termII - termIIIk;

				if (r < scoreMin) scoreMin = r;
				if (r > scoreMax) scoreMax = r;

				stix = (i - 2) * xchg->stgwzskframegeo.wGrrd + j - 2;
				scoreFp[stix] = r;
			};
		};
	};

	if (!linNotLog) {
		shift = 0;

	} else {
		for (test = 1.0, shift = 0; ; test *= 2.0, shift++) if (test >= scoreMax)  break;

		if (shift >= 8) shift -= 8;
		test = pow(2.0, shift);
	};

	_scoreMin = 255;
	_scoreMax = 0;

	hist.resize(256, 0);

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i++) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j++) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;

			r = scoreFp[ldix];

			if (!linNotLog) {
				if (r < 0.0) r16 = 0;
				else {
					// format: EEEEEEMM, using r[31] = sign, r[30:23] = exponent, r[22:0] = mantissa
					uint32_t r_bits = *((uint32_t*) &r);

					if (r < 4.0) r16 = r;
					else r16 = (((r_bits >> 23) - 128) << 2) + ((r_bits & 0x007FFFFF) >> 21);
				};

			} else {
				if (r < 0.0) r16 = 0.0;
				else r16 = (uint16_t) (r/test);
			};

			if (r16 < _scoreMin) _scoreMin = r16;
			if (r16 > _scoreMax) _scoreMax = r16;

			score16[ldix] = r16;
			hist[r16]++;
		};
	};

/*
	cout << "score histogram" << endl;
	for (unsigned int i = 0; i < hist.size(); i++) {
		if ((i % 16) != 0) cout << "\t";
		cout << hist[i];
		if ((i % 16) == 15) cout << endl;
	};
*/

	delete[] scoreFp;

	delete[] fiverowXsqr;
	delete[] fiverowYsqr;
	delete[] fiverowXy;
};

void JobWzskIprCorner::maxselV4l2(
			uint16_t* score16
			, uint16_t* corner16
			, uint& NCorner
		) {
	memset(corner16, 0, sizeof(uint16_t) * xchg->stgwzskframegeo.wGrrd/16 * xchg->stgwzskframegeo.hGrrd);

	uint16_t* fiveByFive = NULL;

	unsigned int ldix;

	unsigned int stixColFbf, cmpixFbf;

	unsigned int stix;
	unsigned char bitcnt;

	uint16_t cmp;
	bool ismax;

	uint16_t corner;

	fiveByFive = new uint16_t[5 * 5];

	stix = 2 * xchg->stgwzskframegeo.wGrrd/16;

	for (unsigned int i = 2; (i + 2) < xchg->stgwzskframegeo.hGrrd; i++) {
		bitcnt = 2;
		corner = 0;

		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j++) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;

			stixColFbf = j % 5;

			for (int k = -2; k <= 2; k++) fiveByFive[(k + 2) * 5 + stixColFbf] = score16[ldix + k * xchg->stgwzskframegeo.wGrrd];

			if (j < 4) continue;

			cmpixFbf = 2 * 5 + ((j - 2) % 5);
			cmp = fiveByFive[cmpixFbf];

			if (cmp >= shrdat.thd) {
				ismax = true;

				for (unsigned int k = 0; k < 5 * 5; k++)
					if (k != cmpixFbf)
						if (fiveByFive[k] >= cmp) {
							ismax = false;
							break;
						};

				if (ismax) {
					corner |= ((uint16_t) 32768) >> (bitcnt - 1);
					NCorner++;
				};
			};

			if (bitcnt == 15) {
				corner16[stix] = corner;
				stix++;

				bitcnt = 0;
				corner = 0;
				
			} else bitcnt++;
		};

		if (bitcnt != 0) { // should be 14 at this stage
			corner16[stix] = corner;
			stix++;
		};
	};

	//cout << "NCorner_raw = " << NCorner << endl;

	delete[] fiveByFive;
};

// IP cust --- IEND

// IP spec --- INSERT

bool JobWzskIprCorner::setNTarget(
			DbsWzsk* dbswzsk
			, const usmallint NTarget
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskIprCorner*) srv)->setNTarget(dbswzsk, NTarget);

		} else retval = false;

		return retval;
	};

	lockAccess("setNTarget");

	// IP setNTarget --- IBEGIN
	shrdat.wlockAccess(jref, "setNTarget");

	shrdat.NTarget = NTarget;

	shrdat.wunlockAccess(jref, "setNTarget");

	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "NTarget");
	// IP setNTarget --- IEND

	unlockAccess("setNTarget");

	return retval;
};

bool JobWzskIprCorner::setRoi(
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
			retval = ((JobWzskIprCorner*) srv)->setRoi(dbswzsk, roiAx, roiAy, roiBx, roiBy, roiCx, roiCy, roiDx, roiDy);

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

bool JobWzskIprCorner::setRoiNotFull(
			DbsWzsk* dbswzsk
			, const bool roiNotFull
		) {
	bool retval = true;

	if (!srvNotCli) {
		if (srv) {
			retval = ((JobWzskIprCorner*) srv)->setRoiNotFull(dbswzsk, roiNotFull);

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

void JobWzskIprCorner::handleRequest(
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

	} else if ((req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) && (req->method->ixVFeatgroup == VecWzskVFeatgroup::VECVJOBWZSKIPRCORNERMETHOD)) {
		uint ixVMethod = VecVMethod::getIx(req->method->srefIxVMethod);

		if ((ixVMethod == VecVMethod::SETNTARGET) && (req->method->parsInv.size() == 1) && (req->method->parsRet.size() == 1)) {
			*((bool*) (req->method->parsRet[0])) = setNTarget(dbswzsk, *((const usmallint*) (req->method->parsInv[0])));
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

bool JobWzskIprCorner::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskIprCorner::handleTimerInSgePrcidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void JobWzskIprCorner::handleTimerWithSrefSrcstopInSgeDone(
			DbsWzsk* dbswzsk
		) {
	changeStage(dbswzsk, VecVSge::IDLE);
};

void JobWzskIprCorner::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && ([&](){bool match = false; if (srcv4l2) if (call->jref == srcv4l2->jref) match = true; return match;}()) && (ixVSge == VecVSge::READY)) {
		call->abort = handleCallWzskResultNewFromSrcv4l2InSgeReady(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && ([&](){bool match = false; if (acqfpgaflg) if (call->jref == acqfpgaflg->jref) match = true; return match;}()) && (call->argInv.sref == "corner") && (ixVSge == VecVSge::READY)) {
		call->abort = handleCallWzskResultNewFromAcqfpgaflgWithSrefCornerInSgeReady(dbswzsk, call->argInv.ix);
	};
};

bool JobWzskIprCorner::handleCallWzskResultNewFromSrcv4l2InSgeReady(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromSrcv4l2InSgeReady --- IBEGIN
	srcv4l2->shrdat.resultAcq.lock(jref, ixInv);
	ixRiSrc = ixInv;

	changeStage(dbswzsk, VecVSge::PRCIDLE);
	// IP handleCallWzskResultNewFromSrcv4l2InSgeReady --- IEND
	return retval;
};

bool JobWzskIprCorner::handleCallWzskResultNewFromAcqfpgaflgWithSrefCornerInSgeReady(
			DbsWzsk* dbswzsk
			, const uint ixInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqfpgaflgWithSrefCornerInSgeReady --- IBEGIN
	acqfpgaflg->shrdat.resultFlg.lock(jref, ixInv);
	ixRiSrc = ixInv;

	changeStage(dbswzsk, VecVSge::PRCIDLE);
	// IP handleCallWzskResultNewFromAcqfpgaflgWithSrefCornerInSgeReady --- IEND
	return retval;
};

void JobWzskIprCorner::changeStage(
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
				case VecVSge::DONE: leaveSgeDone(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbswzsk, reenter); break;
			case VecVSge::PRCIDLE: _ixVSge = enterSgePrcidle(dbswzsk, reenter); break;
			case VecVSge::PROCESS: _ixVSge = enterSgeProcess(dbswzsk, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskIprCorner::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::READY) || (ixVSge == VecVSge::PROCESS) || (ixVSge == VecVSge::DONE) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::READY) retval = "ready";
			else if (ixVSge == VecVSge::PROCESS) retval = "processing";
			else if (ixVSge == VecVSge::DONE) retval = "done";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
			else if (ixVSge == VecVSge::PROCESS) retval = "Verarbeitung";
			else if (ixVSge == VecVSge::DONE) retval = "fertig";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskIprCorner::enterSgeIdle(
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
		if (srcFulfilled) xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, false, false, false));
	};

	if ((ixRiSrc + 1) != 0) {
		if (srcv4l2) srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		else if (acqfpgaflg) acqfpgaflg->shrdat.resultFlg.unlock(jref, ixRiSrc);

		ixRiSrc = 0; ixRiSrc--;
	};

	if (ixRi != shrdat.result.size()) {
		shrdat.result.unlock(0, ixRi);
		ixRi = shrdat.result.size();

		shift_last = 0;
	};
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskIprCorner::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskIprCorner::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- IBEGIN
	Shrdat::ResultitemCorner* ri = NULL;

	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	else if (!reenter) {
		if (shrdat.result.dequeue(ixRi)) {
			ri = (Shrdat::ResultitemCorner*) shrdat.result[ixRi];

			ri->NCorner = 0;
			ri->thd = 0;

			ri->tIn = 0.0;
			ri->tOut = 0.0;

			ri->x.clear();
			ri->y.clear();

			// set source claim to run
			if (srcv4l2) xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, true));
			else if (acqfpgaflg) xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, true, false, false, stg.linNotLog, shrdat.thd, 0, 0));

		} else retval = VecVSge::IDLE;
	};
	// IP enterSgeReady --- IEND

	return retval;
};

void JobWzskIprCorner::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobWzskIprCorner::enterSgePrcidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRCIDLE;
	nextIxVSgeSuccess = VecVSge::PROCESS;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrcidle --- INSERT

	return retval;
};

void JobWzskIprCorner::leaveSgePrcidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrcidle --- INSERT
};

uint JobWzskIprCorner::enterSgeProcess(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PROCESS;

	// IP enterSgeProcess --- IBEGIN
	// shorthands
	const uint wGrrd = xchg->stgwzskframegeo.wGrrd;
	const uint hGrrd = xchg->stgwzskframegeo.hGrrd;
	//

	ShrdatJobWzskSrcV4l2::ResultitemAcq* riSrcv4l2 = NULL;
	ShrdatJobWzskAcqFpgaflg::ResultitemFlg* riSrcfpga = NULL;

	Shrdat::ResultitemCorner* ri = (Shrdat::ResultitemCorner*) shrdat.result[ixRi];

	utinyint shift, scoreMin, scoreMax;

	ri->thd = shrdat.thd;

	// intermediate results
	uint16_t* score16 = NULL; // 1024 x 768

	uint16_t* corner16 = NULL; // 64 x 768

	if (srcv4l2) {
		riSrcv4l2 = (ShrdatJobWzskSrcV4l2::ResultitemAcq*) srcv4l2->shrdat.resultAcq[ixRiSrc];

		ri->tIn = riSrcv4l2->t;

		// calculate score
		score16 = new uint16_t[wGrrd * hGrrd];

		//scoreV4l2(riSrcv4l2->gr16, score16, stg.linNotLog, shift, scoreMin, scoreMax);
		scoreV4l2Fp(riSrcv4l2->gr16, score16, stg.linNotLog, shift, scoreMin, scoreMax);

		srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;

		// select maxima
		corner16 = new uint16_t[wGrrd/16 * hGrrd];

		maxselV4l2(score16, corner16, ri->NCorner);

		Wzsk::bitmapToXy((unsigned char*) corner16, true, wGrrd, hGrrd, ri->x, ri->y, wGrrd + 1, stg.roiNotFull, {shrdat.roiAx,shrdat.roiBx,shrdat.roiCx,shrdat.roiDx}, {shrdat.roiAy,shrdat.roiBy,shrdat.roiCy,shrdat.roiDy}, false, false);

		delete[] score16;

		delete[] corner16;

	} else {
		riSrcfpga = (ShrdatJobWzskAcqFpgaflg::ResultitemFlg*) acqfpgaflg->shrdat.resultFlg[ixRiSrc];

		ri->tIn = riSrcfpga->t;

		shift = riSrcfpga->shift;
		scoreMin = riSrcfpga->scoreMin;
		scoreMax = riSrcfpga->scoreMax;

		Wzsk::bitmapToXy(riSrcfpga->buf, false, wGrrd, hGrrd, ri->x, ri->y, wGrrd + 1, stg.roiNotFull, {shrdat.roiAx,shrdat.roiBx,shrdat.roiCx,shrdat.roiDx}, {shrdat.roiAy,shrdat.roiBy,shrdat.roiCy,shrdat.roiDy}, false, false);

		acqfpgaflg->shrdat.resultFlg.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;
	};

	ri->NCorner = ri->x.size();
	//cout << "NCorner_roi = " << ri->NCorner << endl;

	ri->tOut = Wzsk::getNow();

	// update shrdat
	shrdat.wlockAccess(jref, "enterSgeProcess");

	if (shrdat.thd == 255) {
		// adapt initial threshold
		shrdat.thd = scoreMax;

	} else {
		// adapt threshold for subsequent frame
		if (!stg.linNotLog) {
			if ((ri->NCorner > shrdat.NTarget) && (shrdat.thd < 255)) shrdat.thd++;
			else if ((ri->NCorner < shrdat.NTarget) && (shrdat.thd > 0)) shrdat.thd--;

		} else {
			if (shift > shrdat.shift) shrdat.thd << (shift - shrdat.shift);
			else if (shift < shrdat.shift) shrdat.thd >> (shrdat.shift - shift);
			else {
				if ((ri->NCorner > shrdat.NTarget) && (shrdat.thd < 255)) shrdat.thd++;
				else if ((ri->NCorner < shrdat.NTarget) && (shrdat.thd > 0)) shrdat.thd--;
			};
		};

		//cout << "thd_new = " << ((int) shrdat.thd) << endl;
	};

	shrdat.flg.clear();
	shrdat.flg.resize(wGrrd * hGrrd, false);

	for (unsigned int i = 0; i < ri->x.size(); i++) shrdat.flg[(ri->y[i] + hGrrd/2) * wGrrd + (ri->x[i] + wGrrd/2)] = true;

	shrdat.shift = shift;
	shrdat.scoreMin = scoreMin;
	shrdat.scoreMax = scoreMax;

	shrdat.wunlockAccess(jref, "enterSgeProcess");

	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "flgShiftScoreMinScoreMax");

	// inform super-jobs
	xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRi, "corner");

	shrdat.result.unlock(0, ixRi); // hadn't been locked within this class
	ixRi = shrdat.result.size();

	if (!shrdat.loopNotSngshot) retval = VecVSge::DONE;
	else retval = VecVSge::READY;
	// IP enterSgeProcess --- IEND

	return retval;
};

void JobWzskIprCorner::leaveSgeProcess(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeProcess --- INSERT
};

uint JobWzskIprCorner::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- IBEGIN
	wrefLast = xchg->addWakeup(jref, "srcstop", 3000000);
	// IP enterSgeDone --- IEND

	return retval;
};

void JobWzskIprCorner::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups(); // IP leaveSgeDone --- ILINE
};

bool JobWzskIprCorner::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if srcv4l2/acqfpgaflg claim can be fulfilled
	// - change stage to ready if fulfilled claim is run (run is one-shot)

	Claim* claim = NULL;

	ubigint jrefFulfilled = 0;

	bool retractable = true;
	bool run = false;
	bool loopNotSngshot = false;

	bool available;
	bool reattributed;

	bool srcTakenNotAvailable;
	bool srcFulfilled = false;;

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

	// add (preliminary) or remove claim with source
	if (srcv4l2) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcv4l2);
		else if ((jrefFulfilled == 0) && !claims.empty() && (ixVSge == VecVSge::IDLE)) xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, false));

		xchg->getCsjobClaim(srcv4l2, srcTakenNotAvailable, srcFulfilled);
		
	} else if (acqfpgaflg) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, acqfpgaflg);
		else if ((jrefFulfilled == 0) && !claims.empty() && (ixVSge == VecVSge::IDLE)) xchg->addCsjobClaim(dbswzsk, acqfpgaflg, new JobWzskAcqFpgaflg::Claim(false, false, false, false));

		xchg->getCsjobClaim(acqfpgaflg, srcTakenNotAvailable, srcFulfilled);
	};

	// try to fulfill
	reattributed = false;

	for (unsigned int i = 0; i < 2; i++) {
		for (auto it = claims.begin(); it != claims.end(); it++) {
			claim = (Claim*) it->second;

			available = retractable && srcFulfilled;

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
		if (ixVSge == VecVSge::READY) changeStage(dbswzsk, ixVSge); // re-enter

	} else if (run && srcFulfilled && ((ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::DONE))) {
		nextIxVSgeFailure = VecVSge::READY;
		changeStage(dbswzsk, VecVSge::READY); // source claim is removed / updated in stage ready
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};
