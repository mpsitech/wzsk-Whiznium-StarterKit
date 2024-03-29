/**
	* \file JobWzskAcqPreview.cpp
	* job handler for job JobWzskAcqPreview (implementation)
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

#include "JobWzskAcqPreview.h"

#include "JobWzskAcqPreview_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskAcqPreview::Shrdat::ResultitemGray
 ******************************************************************************/

JobWzskAcqPreview::Shrdat::ResultitemGray::ResultitemGray(
			const uint ixWzskVTarget
		) :
			Resultitem()
		{
	unsigned int w, h;

	Wzsk::getPvwWh(ixWzskVTarget, VecWzskVPvwmode::BINGRAY, w, h);
	sizeBuf = w * h;

	gr8 = new uint8_t[sizeBuf];

	// 16 byte alignment required for SSE2 load/store
	posix_memalign((void**) &gr16, 16, sizeBuf * sizeof(uint16_t));

	tIn = 0.0;
	tOut = 0.0;
};

JobWzskAcqPreview::Shrdat::ResultitemGray::~ResultitemGray() {
	if (gr8) delete[] gr8;
	if (gr16) delete[] gr16;
};

/******************************************************************************
 class JobWzskAcqPreview::Shrdat::ResultitemRgb
 ******************************************************************************/

JobWzskAcqPreview::Shrdat::ResultitemRgb::ResultitemRgb(
			const uint ixWzskVTarget
		) :
			Resultitem()
		{
	unsigned int w, h;

	Wzsk::getPvwWh(ixWzskVTarget, VecWzskVPvwmode::BINRGB, w, h);
	sizeBuf = w * h;

	r8 = new uint8_t[sizeBuf];
	g8 = new uint8_t[sizeBuf];
	b8 = new uint8_t[sizeBuf];

	posix_memalign((void**) &r16, 16, sizeBuf * sizeof(uint16_t));
	posix_memalign((void**) &g16, 16, sizeBuf * sizeof(uint16_t));
	posix_memalign((void**) &b16, 16, sizeBuf * sizeof(uint16_t));

	tIn = 0.0;
	tOut = 0.0;
};

JobWzskAcqPreview::Shrdat::ResultitemRgb::~ResultitemRgb() {
	if (r8) delete[] r8;
	if (g8) delete[] g8;
	if (b8) delete[] b8;

	if (r16) delete[] r16;
	if (g16) delete[] g16;
	if (b16) delete[] b16;
};
// IP Shrdat.subs --- IEND

/******************************************************************************
 class JobWzskAcqPreview::Shrdat
 ******************************************************************************/

JobWzskAcqPreview::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskAcqPreview", "Shrdat")
		{
};

void JobWzskAcqPreview::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	for (unsigned int i = 0; i < 2; i++) resultBingray.append(new ResultitemGray(xchg->stgwzskglobal.ixWzskVTarget));
	for (unsigned int i = 0; i < 2; i++) resultBinreddom.append(new ResultitemGray(xchg->stgwzskglobal.ixWzskVTarget));
	for (unsigned int i = 0; i < 2; i++) resultBinrgb.append(new ResultitemRgb(xchg->stgwzskglobal.ixWzskVTarget));

	for (unsigned int i = 0; i < 2; i++) resultRawgray.append(new ResultitemGray(xchg->stgwzskglobal.ixWzskVTarget));
	for (unsigned int i = 0; i < 2; i++) resultRawrgb.append(new ResultitemRgb(xchg->stgwzskglobal.ixWzskVTarget));
	// IP Shrdat.init --- IEND
};

void JobWzskAcqPreview::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskAcqPreview
 ******************************************************************************/

JobWzskAcqPreview::JobWzskAcqPreview(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKACQPREVIEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcv4l2 = NULL;
	acqfpgapvw = NULL;

	// IP constructor.cust1 --- IBEGIN
	ixRiSrc = 0; ixRiSrc--;

	ixRiBingray = shrdat.resultBingray.size();
	ixRiBinreddom = shrdat.resultBinreddom.size();
	ixRiBinrgb = shrdat.resultBinrgb.size();
	ixRiRawgray = shrdat.resultRawgray.size();
	ixRiRawrgb = shrdat.resultRawrgb.size();
	// IP constructor.cust1 --- IEND

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- IBEGIN
	if (srvNotCli) {
		if ((xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::APALIS) || (xchg->stgwzskglobal.ixWzskVTarget == VecWzskVTarget::WS)) srcv4l2 = new JobWzskSrcV4l2(xchg, dbswzsk, jref, ixWzskVLocale);
		else acqfpgapvw = new JobWzskAcqFpgapvw(xchg, dbswzsk, jref, ixWzskVLocale);
	};
	// IP constructor.cust2 --- IEND

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) if (srcv4l2) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, srcv4l2->jref, false, Arg(), VecVSge::READY, Clstn::VecVJactype::TRY);
	if (srvNotCli) if (acqfpgapvw) xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::SPEC, acqfpgapvw->jref, false, Arg(), VecVSge::READY, Clstn::VecVJactype::TRY);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqPreview::~JobWzskAcqPreview() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
JobWzskAcqPreview::Claim::Claim(
			const bool retractable
			, const bool run
			, const Sbecore::uint ixWzskVPvwmode
		) :
			Sbecore::Claim(retractable, run)
		{
	this->ixWzskVPvwmode = ixWzskVPvwmode;
};

void JobWzskAcqPreview::binGrrd(
			uint16_t* grrd16
			, uint16_t* pvwgrrd16
		) {
#ifdef __arm__
	// hard-wired to 4x4 super-pixels
	const uint64_t zero64 = 0;

	uint16x8_t data;
	uint32x4_t dataAcc2;
	uint64x2_t dataAcc4;

	uint64x2_t acc;
	uint16_t acc16;

	unsigned int ldix, stix;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i += 4) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j += 8) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;
			
			acc = vld1q_dup_u64(&zero64);

			for (unsigned int k = 0; k < 4; k++) {
				data = vld1q_u16(&(grrd16[ldix]));
				dataAcc2 = vpaddlq_u16(data);
				dataAcc4 = vpaddlq_u32(dataAcc2);

				acc = vaddq_u64(acc, dataAcc4);
				
				ldix += xchg->stgwzskframegeo.wGrrd;
			};

			stix = i/4 * xchg->stgwzskframegeo.wGrrd/4 + j/4;

			acc16 = vgetq_lane_u16(vreinterpretq_u16_u64(acc), 0);
			pvwgrrd16[stix] = acc16 >> 4;

			stix++;

			acc16 = vgetq_lane_u16(vreinterpretq_u16_u64(acc), 4);
			pvwgrrd16[stix] = acc16 >> 4;
		};
	};
#elif __x86_64__
	// hard-wired to 2x2 super-pixels
	uint16_t* buf = NULL;

	__m128i dataeven, dataodd, datashift;

	unsigned int ldix, stix;

	posix_memalign((void**) &buf, 16, xchg->stgwzskframegeo.wGrrd * sizeof(uint16_t));

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i += 2) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j += 8) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;
			dataeven = _mm_load_si128((const __m128i*) &(grrd16[ldix]));

			ldix += xchg->stgwzskframegeo.wGrrd;
			dataodd = _mm_load_si128((const __m128i*) &(grrd16[ldix]));

			dataeven = _mm_add_epi16(dataeven, dataodd);
			datashift = _mm_slli_si128(dataeven, 2);

			dataeven = _mm_add_epi16(dataeven, datashift);
			dataeven = _mm_srli_epi16(dataeven, 2);

			stix = i/2 * xchg->stgwzskframegeo.wGrrd/2 + j/2;
			_mm_store_si128 ((__m128i*) buf, dataeven);
			pvwgrrd16[stix++] = buf[1];
			pvwgrrd16[stix++] = buf[3];
			pvwgrrd16[stix++] = buf[5];
			pvwgrrd16[stix] = buf[7];
			//pvwgrrd16[stix++] = _mm_extract_epi16(dataeven, 1);
			//pvwgrrd16[stix++] = _mm_extract_epi16(dataeven, 3);
			//pvwgrrd16[stix++] = _mm_extract_epi16(dataeven, 5);
			//pvwgrrd16[stix] = _mm_extract_epi16(dataeven, 7);
		};
	};

	delete[] buf;
#else
	// hard-wired to 2x2 super-pixels
	unsigned int ldix, stix;

	uint32_t acc;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd; i += 2) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wGrrd; j += 2) {
			ldix = i * xchg->stgwzskframegeo.wGrrd + j;

			acc = 0;

			for (unsigned int k = 0; k < 2; k++) {
				for (unsigned int l = 0; l < 2; l++) acc += grrd16[ldix+l];

				ldix += xchg->stgwzskframegeo.wGrrd;
			};

			stix = i/2 * xchg->stgwzskframegeo.wGrrd/2 + j/2;

			pvwgrrd16[stix] = acc >> 2;
		};
	};
#endif
};

void JobWzskAcqPreview::binRgb(
			uint16_t* r16
			, uint16_t* g16
			, uint16_t* b16
			, uint16_t* pvwr16
			, uint16_t* pvwg16
			, uint16_t* pvwb16
		) {
	binRgb_component(r16, pvwr16);
	binRgb_component(g16, pvwg16);
	binRgb_component(b16, pvwb16);
};

void JobWzskAcqPreview::binRgb_component(
			uint16_t* src
			, uint16_t* dest
		) {
#ifdef __arm__
	// hard-wired to 8x8 super-pixels
	const uint64_t zero64 = 0;

	uint16x8_t data;
	uint32x4_t dataAcc2;
	uint64x2_t dataAcc4;

	uint64x2_t acc;
	uint16_t acc16;

	unsigned int ldix, stix;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hRgb; i += 8) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wRgb; j += 8) {
			ldix = i * xchg->stgwzskframegeo.wRgb + j;
			
			acc = vld1q_dup_u64(&zero64);

			for (unsigned int k = 0; k < 8; k++) {
				data = vld1q_u16(&(src[ldix]));
				dataAcc2 = vpaddlq_u16(data);
				dataAcc4 = vpaddlq_u32(dataAcc2);

				acc = vaddq_u64(acc, dataAcc4);
				
				ldix += xchg->stgwzskframegeo.wRgb;
			};

			stix = i/8 * xchg->stgwzskframegeo.wRgb/8 + j/8;

			acc16 = vgetq_lane_u16(vreinterpretq_u16_u64(acc), 4) + vgetq_lane_u16(vreinterpretq_u16_u64(acc), 0);
			dest[stix] = acc16 >> 6;
		};
	};
#elif __x86_64__
	uint16_t* buf = NULL;

	__m128i dataeven, dataodd, datashift;

	unsigned int ldix, stix;

	posix_memalign((void**) &buf, 16, xchg->stgwzskframegeo.wRgb * sizeof(uint16_t));

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hRgb; i += 2) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wRgb; j += 8) {
			ldix = i * xchg->stgwzskframegeo.wRgb + j;
			dataeven = _mm_load_si128((const __m128i*) &(src[ldix]));

			ldix += xchg->stgwzskframegeo.wRgb;
			dataodd = _mm_load_si128((const __m128i*) &(src[ldix]));

			dataeven = _mm_add_epi16(dataeven, dataodd);
			datashift = _mm_slli_si128(dataeven, 2);

			dataeven = _mm_add_epi16(dataeven, datashift);
			dataeven = _mm_srli_epi16(dataeven, 2);

			stix = i/2 * xchg->stgwzskframegeo.wRgb/2 + j/2;
			_mm_store_si128 ((__m128i*) buf, dataeven);
			dest[stix++] = buf[1];
			dest[stix++] = buf[3];
			dest[stix++] = buf[5];
			dest[stix] = buf[7];
		};
	};

	delete[] buf;
#else
	// hard-wired to 2x2 super-pixels (non-SIMD)
	unsigned int ldix, stix;

	uint32_t acc;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hRgb; i += 2) {
		for (unsigned int j = 0; j < xchg->stgwzskframegeo.wRgb; j += 2) {
			ldix = i * xchg->stgwzskframegeo.wRgb + j;

			acc = 0;

			for (unsigned int k = 0; k < 2; k++) {
				for (unsigned int l = 0; l < 2; l++) acc += src[ldix+l];

				ldix += xchg->stgwzskframegeo.wRgb;
			};

			stix = i/2 * xchg->stgwzskframegeo.wRgb/2 + j/2;

			dest[stix] = acc >> 2;
		};
	};
#endif
};

void JobWzskAcqPreview::rawGr(
			uint16_t* grrd16
			, uint16_t* pvwgrrd16
		) {
#ifdef __arm__
	// hard-wired to /4 reduction
	const unsigned int x0 = (xchg->stgwzskframegeo.wGrrd - xchg->stgwzskframegeo.wGrrd/4) / 2;
	const unsigned int y0 = (xchg->stgwzskframegeo.hGrrd - xchg->stgwzskframegeo.hGrrd/4) / 2;

	unsigned int ldix, stix;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd/4; i++) {
		ldix = (y0 + i) * xchg->stgwzskframegeo.wGrrd + x0;
		stix = i * xchg->stgwzskframegeo.wGrrd/4;

		memcpy(&(pvwgrrd16[stix]), &(grrd16[ldix]), 2 * xchg->stgwzskframegeo.wGrrd/4);
	};
#else
	// hard-wired to /2 reduction (non-SIMD)
	const unsigned int x0 = (xchg->stgwzskframegeo.wGrrd - xchg->stgwzskframegeo.wGrrd/2) / 2;
	const unsigned int y0 = (xchg->stgwzskframegeo.hGrrd - xchg->stgwzskframegeo.hGrrd/2) / 2;

	unsigned int ldix, stix;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hGrrd/2; i++) {
		ldix = (y0 + i) * xchg->stgwzskframegeo.wGrrd + x0;
		stix = i * xchg->stgwzskframegeo.wGrrd/2;

		memcpy(&(pvwgrrd16[stix]), &(grrd16[ldix]), 2 * xchg->stgwzskframegeo.wGrrd/2);
	};
#endif
};

void JobWzskAcqPreview::rawRgb(
			uint16_t* r16
			, uint16_t* g16
			, uint16_t* b16
			, uint16_t* pvwr16
			, uint16_t* pvwg16
			, uint16_t* pvwb16
		) {
#ifdef __arm__
	// hard-wired to /8 reduction
	const unsigned int x0 = (xchg->stgwzskframegeo.wRgb - xchg->stgwzskframegeo.wRgb/8) / 2;
	const unsigned int y0 = (xchg->stgwzskframegeo.hRgb - xchg->stgwzskframegeo.hRgb/8) / 2;

	unsigned int ldix, stix;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hRgb/8; i++) {
		ldix = (y0 + i) * xchg->stgwzskframegeo.wRgb + x0;
		stix = i * xchg->stgwzskframegeo.wRgb/8;

		memcpy(&(pvwr16[stix]), &(r16[ldix]), 2 * xchg->stgwzskframegeo.wRgb/8);
		memcpy(&(pvwg16[stix]), &(g16[ldix]), 2 * xchg->stgwzskframegeo.wRgb/8);
		memcpy(&(pvwb16[stix]), &(b16[ldix]), 2 * xchg->stgwzskframegeo.wRgb/8);
	};
#else
	// hard-wired to /2 reduction (non-SIMD)
	const unsigned int x0 = (xchg->stgwzskframegeo.wRgb - xchg->stgwzskframegeo.wRgb/2) / 2;
	const unsigned int y0 = (xchg->stgwzskframegeo.hRgb - xchg->stgwzskframegeo.hRgb/2) / 2;

	unsigned int ldix, stix;

	for (unsigned int i = 0; i < xchg->stgwzskframegeo.hRgb/2; i++) {
		ldix = (y0 + i) * xchg->stgwzskframegeo.wRgb + x0;
		stix = i * xchg->stgwzskframegeo.wRgb/2;

		memcpy(&(pvwr16[stix]), &(r16[ldix]), 2 * xchg->stgwzskframegeo.wRgb/2);
		memcpy(&(pvwg16[stix]), &(g16[ldix]), 2 * xchg->stgwzskframegeo.wRgb/2);
		memcpy(&(pvwb16[stix]), &(b16[ldix]), 2 * xchg->stgwzskframegeo.wRgb/2);
	};
#endif
};

void JobWzskAcqPreview::uint16ToUint8(
			uint16_t* in16
			, uint8_t* out8
			, size_t sizeBuf
		) {
	// not using SIMD instructions for now
	for (unsigned int i = 0; i < sizeBuf; i++) out8[i] = in16[i];
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskAcqPreview::handleRequest(
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

bool JobWzskAcqPreview::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskAcqPreview::handleTimerInSgePrcidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void JobWzskAcqPreview::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && ([&](){bool match = false; if (srcv4l2) if (call->jref == srcv4l2->jref) match = true; return match;}()) && (ixVSge == VecVSge::READY)) {
		call->abort = handleCallWzskResultNewFromSrcv4l2InSgeReady(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) && ([&](){bool match = false; if (acqfpgapvw) if (call->jref == acqfpgapvw->jref) match = true; return match;}()) && (ixVSge == VecVSge::READY)) {
		call->abort = handleCallWzskResultNewFromAcqfpgapvwInSgeReady(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqPreview::handleCallWzskResultNewFromSrcv4l2InSgeReady(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromSrcv4l2InSgeReady --- IBEGIN

	// prepare for all currently claimed preview modes
	if (shrdat.bingray) shrdat.resultBingray.dequeue(ixRiBingray);
	if (shrdat.binreddom) shrdat.resultBinreddom.dequeue(ixRiBinreddom);
	if (shrdat.binrgb) shrdat.resultBinrgb.dequeue(ixRiBinrgb);
	if (shrdat.rawgray) shrdat.resultRawgray.dequeue(ixRiRawgray);
	if (shrdat.rawrgb) shrdat.resultRawrgb.dequeue(ixRiRawrgb);

	if ( (ixRiBingray != shrdat.resultBingray.size()) || (ixRiBinreddom != shrdat.resultBinreddom.size()) || (ixRiBinrgb != shrdat.resultBinrgb.size()) || (ixRiRawgray != shrdat.resultRawgray.size()) || (ixRiRawrgb != shrdat.resultRawrgb.size()) ) {
		srcv4l2->shrdat.resultAcq.lock(jref, ixInv);
		ixRiSrc = ixInv;

		changeStage(dbswzsk, VecVSge::PRCIDLE);
	};
	// IP handleCallWzskResultNewFromSrcv4l2InSgeReady --- IEND
	return retval;
};

bool JobWzskAcqPreview::handleCallWzskResultNewFromAcqfpgapvwInSgeReady(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNewFromAcqfpgapvwInSgeReady --- IBEGIN

	// binreddom is not available for fpga at this time

	if (VecWzskVPvwmode::getIx(srefInv) == VecWzskVPvwmode::BINGRAY) shrdat.resultBingray.dequeue(ixRiBingray);
	else if (VecWzskVPvwmode::getIx(srefInv) == VecWzskVPvwmode::BINRGB) shrdat.resultBinrgb.dequeue(ixRiBinrgb);
	else if (VecWzskVPvwmode::getIx(srefInv) == VecWzskVPvwmode::RAWGRAY) shrdat.resultRawgray.dequeue(ixRiRawgray);
	else if (VecWzskVPvwmode::getIx(srefInv) == VecWzskVPvwmode::RAWRGB) shrdat.resultRawrgb.dequeue(ixRiRawrgb);

	if ( (ixRiBingray != shrdat.resultBingray.size()) || (ixRiBinrgb != shrdat.resultBinrgb.size()) || (ixRiRawgray != shrdat.resultRawgray.size()) || (ixRiRawrgb != shrdat.resultRawrgb.size()) ) {
		acqfpgapvw->shrdat.resultPvw.lock(jref, ixInv);
		ixRiSrc = ixInv;

		changeStage(dbswzsk, VecVSge::PRCIDLE);
	};
	// IP handleCallWzskResultNewFromAcqfpgapvwInSgeReady --- IEND
	return retval;
};

void JobWzskAcqPreview::changeStage(
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
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			//cout << "JobWzskAcqPreview now entering stage " << VecVSge::getSref(_ixVSge) << endl; // IP changeStage.refresh1 --- ILINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::READY: _ixVSge = enterSgeReady(dbswzsk, reenter); break;
			case VecVSge::PRCIDLE: _ixVSge = enterSgePrcidle(dbswzsk, reenter); break;
			case VecVSge::PROCESS: _ixVSge = enterSgeProcess(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqPreview::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::READY) || (ixVSge == VecVSge::PROCESS) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::READY) retval = "ready";
			else if (ixVSge == VecVSge::PROCESS) retval = "processing";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::READY) retval = "bereit";
			else if (ixVSge == VecVSge::PROCESS) retval = "Verarbeitung";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskAcqPreview::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);

	if ((ixRiSrc + 1) != 0) {
		if (srcv4l2) srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		else if (acqfpgapvw) acqfpgapvw->shrdat.resultPvw.unlock(jref, ixRiSrc);

		ixRiSrc = 0; ixRiSrc--;
	};

	if (ixRiBingray != shrdat.resultBingray.size()) {
		shrdat.resultBingray.unlock(0, ixRiBingray);
		ixRiBingray = shrdat.resultBingray.size();
	};

	if (ixRiBinreddom != shrdat.resultBinreddom.size()) {
		shrdat.resultBinreddom.unlock(0, ixRiBinreddom);
		ixRiBinreddom = shrdat.resultBinreddom.size();
	};

	if (ixRiBinrgb != shrdat.resultBinrgb.size()) {
		shrdat.resultBinrgb.unlock(0, ixRiBinrgb);
		ixRiBinrgb = shrdat.resultBinrgb.size();
	};

	if (ixRiRawgray != shrdat.resultRawgray.size()) {
		shrdat.resultRawgray.unlock(0, ixRiRawgray);
		ixRiRawgray = shrdat.resultRawgray.size();
	};

	if (ixRiRawrgb != shrdat.resultRawrgb.size()) {
		shrdat.resultRawrgb.unlock(0, ixRiRawrgb);
		ixRiRawrgb = shrdat.resultRawrgb.size();
	};
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqPreview::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqPreview::enterSgeReady(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::READY;

	// IP enterSgeReady --- IBEGIN
	if (nextIxVSgeFailure == VecVSge::IDLE) retval = nextIxVSgeFailure; // claim run attribute has been retracted
	// IP enterSgeReady --- IEND

	return retval;
};

void JobWzskAcqPreview::leaveSgeReady(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeReady --- INSERT
};

uint JobWzskAcqPreview::enterSgePrcidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRCIDLE;
	nextIxVSgeSuccess = VecVSge::PROCESS;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrcidle --- INSERT

	return retval;
};

void JobWzskAcqPreview::leaveSgePrcidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrcidle --- INSERT
};

uint JobWzskAcqPreview::enterSgeProcess(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PROCESS;

	// IP enterSgeProcess --- IBEGIN
	ShrdatJobWzskSrcV4l2::ResultitemAcq* riSrcv4l2 = NULL;
	ShrdatJobWzskAcqFpgapvw::ResultitemPvw* riSrcfpga = NULL;

	Shrdat::ResultitemGray* riGray = NULL;
	Shrdat::ResultitemRgb* riRgb = NULL;

	if (srcv4l2) {
		riSrcv4l2 = (ShrdatJobWzskSrcV4l2::ResultitemAcq*) srcv4l2->shrdat.resultAcq[ixRiSrc];

		if (ixRiBingray < shrdat.resultBingray.size()) {
			riGray = (Shrdat::ResultitemGray*) shrdat.resultBingray[ixRiBingray];

			riGray->tIn = riSrcv4l2->t;

			binGrrd(riSrcv4l2->gr16, riGray->gr16);
			uint16ToUint8(riGray->gr16, riGray->gr8, riGray->sizeBuf);

			riGray->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiBingray, "bingray");

			shrdat.resultBingray.unlock(0, ixRiBingray); // hadn't been locked within this class
			ixRiBingray = shrdat.resultBingray.size();
		};

		if (ixRiBinreddom < shrdat.resultBinreddom.size()) {
			riGray = (Shrdat::ResultitemGray*) shrdat.resultBinreddom[ixRiBinreddom];

			riGray->tIn = riSrcv4l2->t;

			binGrrd(riSrcv4l2->rd16, riGray->gr16);
			uint16ToUint8(riGray->gr16, riGray->gr8, riGray->sizeBuf);

			riGray->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiBinreddom, "binreddom");

			shrdat.resultBinreddom.unlock(0, ixRiBinreddom); // hadn't been locked within this class
			ixRiBinreddom = shrdat.resultBinreddom.size();
		};

		if (ixRiBinrgb < shrdat.resultBinrgb.size()) {
			riRgb = (Shrdat::ResultitemRgb*) shrdat.resultBinrgb[ixRiBinrgb];

			riRgb->tIn = riSrcv4l2->t;

			binRgb(riSrcv4l2->r16, riSrcv4l2->g16, riSrcv4l2->b16, riRgb->r16, riRgb->g16, riRgb->b16);
			uint16ToUint8(riRgb->r16, riRgb->r8, riRgb->sizeBuf);
			uint16ToUint8(riRgb->g16, riRgb->g8, riRgb->sizeBuf);
			uint16ToUint8(riRgb->b16, riRgb->b8, riRgb->sizeBuf);

			riRgb->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiBinrgb, "binrgb");

			shrdat.resultBinrgb.unlock(0, ixRiBinrgb); // hadn't been locked within this class
			ixRiBinrgb = shrdat.resultBinrgb.size();
		};

		if (ixRiRawgray < shrdat.resultRawgray.size()) {
			riGray = (Shrdat::ResultitemGray*) shrdat.resultRawgray[ixRiRawgray];

			riGray->tIn = riSrcv4l2->t;

			rawGr(riSrcv4l2->gr16, riGray->gr16);
			uint16ToUint8(riGray->gr16, riGray->gr8, riGray->sizeBuf);

			riGray->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiRawgray, "rawgray");

			shrdat.resultRawgray.unlock(0, ixRiRawgray); // hadn't been locked within this class
			ixRiRawgray = shrdat.resultRawgray.size();
		};

		if (ixRiRawrgb < shrdat.resultRawrgb.size()) {
			riRgb = (Shrdat::ResultitemRgb*) shrdat.resultRawrgb[ixRiRawrgb];

			riRgb->tIn = riSrcv4l2->t;

			rawRgb(riSrcv4l2->r16, riSrcv4l2->g16, riSrcv4l2->b16, riRgb->r16, riRgb->g16, riRgb->b16);
			uint16ToUint8(riRgb->r16, riRgb->r8, riRgb->sizeBuf);
			uint16ToUint8(riRgb->g16, riRgb->g8, riRgb->sizeBuf);
			uint16ToUint8(riRgb->b16, riRgb->b8, riRgb->sizeBuf);

			riRgb->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiRawrgb, "rawrgb");

			shrdat.resultRawrgb.unlock(0, ixRiRawrgb); // hadn't been locked within this class
			ixRiRawrgb = shrdat.resultRawrgb.size();
		};

		srcv4l2->shrdat.resultAcq.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;

	} else if (acqfpgapvw) {
		riSrcfpga = (JobWzskAcqFpgapvw::Shrdat::ResultitemPvw*) acqfpgapvw->shrdat.resultPvw[ixRiSrc];

		if (ixRiBingray < shrdat.resultBingray.size()) {
			riGray = (Shrdat::ResultitemGray*) shrdat.resultBingray[ixRiBingray];

			riGray->tIn = riSrcfpga->t;

			memcpy(riGray->gr8, riSrcfpga->buf, riGray->sizeBuf);

			riGray->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiBingray, "bingray");

			shrdat.resultBingray.unlock(0, ixRiBingray); // hadn't been locked within this class
			ixRiBingray = shrdat.resultBingray.size();

		} else if (ixRiBinrgb < shrdat.resultBinrgb.size()) {
			riRgb = (Shrdat::ResultitemRgb*) shrdat.resultBinrgb[ixRiBinrgb];

			riRgb->tIn = riSrcfpga->t;

			memcpy(riRgb->r8, riSrcfpga->buf, riRgb->sizeBuf);
			memcpy(riRgb->g8, &((riSrcfpga->buf)[riRgb->sizeBuf]), riRgb->sizeBuf);
			memcpy(riRgb->b8, &((riSrcfpga->buf)[2 * riRgb->sizeBuf]), riRgb->sizeBuf);

			//for (unsigned int i = 0, j = 0; i < riRgb->sizeBuf; i++) {
			//	riRgb->r8[i] = riSrcfpga->buf[j++];
			//	riRgb->g8[i] = riSrcfpga->buf[j++];
			//	riRgb->b8[i] = riSrcfpga->buf[j++];
			//};

			riRgb->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiBinrgb, "binrgb");

			shrdat.resultBinrgb.unlock(0, ixRiBinrgb); // hadn't been locked within this class
			ixRiBinrgb = shrdat.resultBinrgb.size();

		} else if (ixRiRawgray < shrdat.resultRawgray.size()) {
			riGray = (Shrdat::ResultitemGray*) shrdat.resultRawgray[ixRiRawgray];

			riGray->tIn = riSrcfpga->t;

			memcpy(riGray->gr8, riSrcfpga->buf, riGray->sizeBuf);

			riGray->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiRawgray, "rawgray");

			shrdat.resultRawgray.unlock(0, ixRiRawgray); // hadn't been locked within this class
			ixRiRawgray = shrdat.resultRawgray.size();

		} else if (ixRiRawrgb < shrdat.resultRawrgb.size()) {
			riRgb = (Shrdat::ResultitemRgb*) shrdat.resultRawrgb[ixRiRawrgb];

			riRgb->tIn = riSrcfpga->t;

			memcpy(riRgb->r8, riSrcfpga->buf, riRgb->sizeBuf);
			memcpy(riRgb->g8, &((riSrcfpga->buf)[riRgb->sizeBuf]), riRgb->sizeBuf);
			memcpy(riRgb->b8, &((riSrcfpga->buf)[2 * riRgb->sizeBuf]), riRgb->sizeBuf);

			//for (unsigned int i = 0, j = 0; i < riRgb->sizeBuf; i++) {
			//	riRgb->r8[i] = riSrcfpga->buf[j++];
			//	riRgb->g8[i] = riSrcfpga->buf[j++];
			//	riRgb->b8[i] = riSrcfpga->buf[j++];
			//};

			riRgb->tOut = Wzsk::getNow();

			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixRiRawrgb, "rawrgb");

			shrdat.resultRawrgb.unlock(0, ixRiRawrgb); // hadn't been locked within this class
			ixRiRawrgb = shrdat.resultRawrgb.size();
		};

		acqfpgapvw->shrdat.resultPvw.unlock(jref, ixRiSrc);
		ixRiSrc = 0; ixRiSrc--;
	};

	if (riGray || riRgb) {
		// update shrdat from result item (relevant for DDS publisher and OPC UA server)
		if (riGray) {
			shrdat.wlockAccess(jref, "enterSgeProcess[1]");

			shrdat.gray.resize(riGray->sizeBuf);
			memcpy((void*) shrdat.gray.data(), (void*) riGray->gr8, riGray->sizeBuf);

			shrdat.wunlockAccess(jref, "enterSgeProcess[1]");

			xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "gray");
		};

		// reddom not part of shrdat at this time

		if (riRgb) {
			shrdat.wlockAccess(jref, "enterSgeProcess[2]");

			shrdat.red.resize(riRgb->sizeBuf);
			memcpy((void*) shrdat.red.data(), (void*) riRgb->r8, riRgb->sizeBuf);
			shrdat.green.resize(riRgb->sizeBuf);
			memcpy((void*) shrdat.green.data(), (void*) riRgb->g8, riRgb->sizeBuf);
			shrdat.blue.resize(riRgb->sizeBuf);
			memcpy((void*) shrdat.blue.data(), (void*) riRgb->b8, riRgb->sizeBuf);

			shrdat.wunlockAccess(jref, "enterSgeProcess[2]");

			xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "redGreenBlue");
		};
	};

	retval = VecVSge::READY;
	// IP enterSgeProcess --- IEND

	return retval;
};

void JobWzskAcqPreview::leaveSgeProcess(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeProcess --- INSERT
};

bool JobWzskAcqPreview::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - fulfill any claim for srcv4l2
	// - fulfill all claims of one mode for acqfpgapvw
	// - only possible if srcv4l2/acqfpgapvw claim can be fulfilled
	// - change stage to ready if fulfilled claim is run (run is continuous)

	Claim* claim = NULL;

	set<ubigint> jrefsFulfilled;
	bool retractable = true;
	bool run = false;
	set<uint> icsWzskVPvwmode;
	uint ixWzskVPvwmode = 0;

	bool available;
	bool reattributed;

	bool srcTakenNotAvailable;
	bool srcFulfilled = false;

	// survey
	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		if (claim->fulfilled) {
			jrefsFulfilled.insert(it->first);
			if (!claim->retractable) retractable = false;
			if (claim->run) run = true;
			icsWzskVPvwmode.insert(claim->ixWzskVPvwmode);
			ixWzskVPvwmode = claim->ixWzskVPvwmode;
		};
	};

/*
	cout << "JobWzskAcqPreview::handleClaim() survey result:" << endl;

	cout << "claims.size() = " << claims.size() << endl;

	cout << "jrefsFulfilled = {";
	for (auto it = jrefsFulfilled.begin(); it != jrefsFulfilled.end(); it++) {
		if (it != jrefsFulfilled.begin()) cout << ",";
		cout << (*it);
	};
	cout << "}" << endl;

	if (!retractable) cout << "not ";
	cout << "retractable" << endl;

	if (!run) cout << "not ";
	cout << "run" << endl;

	cout << "icsWzskVPvwmode = {";
	for (auto it = icsWzskVPvwmode.begin(); it != icsWzskVPvwmode.end(); it++) {
		if (it != icsWzskVPvwmode.begin()) cout << ",";
		cout << (*it);
	};
	cout << "}" << endl;

	cout << "ixWzskVPvwmode = " << ixWzskVPvwmode << endl;
	cout << endl;
*/

	// add (preliminary) or remove claim with source
	if (srcv4l2) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcv4l2);
		else if (jrefsFulfilled.empty() && !claims.empty()) xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, false));

		xchg->getCsjobClaim(srcv4l2, srcTakenNotAvailable, srcFulfilled);
		
	} else if (acqfpgapvw) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, acqfpgapvw);
		else if (jrefsFulfilled.empty() && !claims.empty()) xchg->addCsjobClaim(dbswzsk, acqfpgapvw, new JobWzskAcqFpgapvw::Claim(false, false, ixWzskVPvwmode));

		xchg->getCsjobClaim(acqfpgapvw, srcTakenNotAvailable, srcFulfilled);
	};

	// try to fulfill
	available = srcFulfilled;
	reattributed = icsWzskVPvwmode.empty(); // here, implies new (set of) preview mode(s)

	if (!available) {
		for (auto it = jrefsFulfilled.begin(); it != jrefsFulfilled.end(); it++) claims[*it]->fulfilled = false;
		retractable = true;
		run = false;
		if (!icsWzskVPvwmode.empty()) {
			icsWzskVPvwmode.clear();
			reattributed = true;
		};

	} else {
		if (srcv4l2) {
			retractable = true;
			run = false;

			for (auto it = claims.begin(); it != claims.end(); it++) {
				claim = (Claim*) it->second;

				claim->fulfilled = true;

				if (claim->fulfilled) {
					if (claim->run) run = true;
					if (icsWzskVPvwmode.find(claim->ixWzskVPvwmode) == icsWzskVPvwmode.end()) {
						icsWzskVPvwmode.insert(claim->ixWzskVPvwmode);
						reattributed = true;
					};
				};
			};

		} else if (acqfpgapvw && !claims.empty()) {
			claim = NULL;

			if (jrefNewest != 0) claim = (Claim*) claims[jrefNewest]; // preference given to newest claim
			else claim = (Claim*) claims.begin()->second;

			if ((claim->ixWzskVPvwmode != ixWzskVPvwmode) && retractable) {
				ixWzskVPvwmode = claim->ixWzskVPvwmode;
				reattributed = true;
			};

			retractable = true;
			run = false;

			for (auto it = claims.begin(); it != claims.end(); it++) {
				claim = (Claim*) it->second;

				claim->fulfilled = (claim->ixWzskVPvwmode == ixWzskVPvwmode);

				if (claim->fulfilled) {
					if (!claim->retractable) retractable = false;
					if (claim->run) run = true;
				};
			};
		};
	};

/*
	cout << "JobWzskAcqPreview::handleClaim() fulfillment result:" << endl;

	if (!run) cout << "not ";
	cout << "run" << endl;

	cout << "icsWzskVPvwmode = {";
	for (auto it = icsWzskVPvwmode.begin(); it != icsWzskVPvwmode.end(); it++) {
		if (it != icsWzskVPvwmode.begin()) cout << ",";
		cout << (*it);
	};
	cout << "}" << endl;

	cout << "ixWzskVPvwmode = " << ixWzskVPvwmode << endl;

	if (!reattributed) cout << "not ";
	cout << "reattributed" << endl;
	cout << endl;
*/

	// update taken status
	available = retractable;

	for (auto it = claims.begin(); it != claims.end(); it++) {
		claim = (Claim*) it->second;

		claim->takenNotAvailable = !available;
	};

	// change source claim
	if (reattributed) {
		if (srcv4l2) {
			if ((!run || !srcFulfilled) && (ixVSge != VecVSge::IDLE)) {
				xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, false));

			} else if (run && srcFulfilled) {
				shrdat.bingray = has(icsWzskVPvwmode, VecWzskVPvwmode::BINGRAY);
				shrdat.binreddom = has(icsWzskVPvwmode, VecWzskVPvwmode::BINREDDOM);
				shrdat.binrgb = has(icsWzskVPvwmode, VecWzskVPvwmode::BINRGB);
				shrdat.rawgray = has(icsWzskVPvwmode, VecWzskVPvwmode::RAWGRAY);
				shrdat.rawrgb = has(icsWzskVPvwmode, VecWzskVPvwmode::RAWRGB);

				xchg->addCsjobClaim(dbswzsk, srcv4l2, new Claim(false, true));
			};

		} else if (acqfpgapvw) {
			if (run && srcFulfilled) {
				xchg->addCsjobClaim(dbswzsk, acqfpgapvw, new JobWzskAcqFpgapvw::Claim(false, true, ixWzskVPvwmode));

				if (ixVSge == VecVSge::IDLE) {
					nextIxVSgeFailure = VecVSge::READY;
					changeStage(dbswzsk, VecVSge::READY);
				};
			};
		};
	};

	// initiate stage change
	if (!run) {
		nextIxVSgeFailure = VecVSge::IDLE;
		if (ixVSge == VecVSge::READY) changeStage(dbswzsk, ixVSge); // re-enter

	} else {
		nextIxVSgeFailure = VecVSge::READY;
		if (ixVSge == VecVSge::IDLE) changeStage(dbswzsk, VecVSge::READY);
	};

	mod = true; // for simplicity
	// IP handleClaim --- IEND

	return mod;
};
