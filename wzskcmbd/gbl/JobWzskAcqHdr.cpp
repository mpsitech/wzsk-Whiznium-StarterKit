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

#include "JobWzskAcqHdr_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

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

	Frdp::Cubeinfo& ci = xchg->shrdatJobprc.cubeinfo;

	fd = -1;
	buf = NULL;

	try {
		fd = open(stg.path.c_str(), O_RDWR);

		success = (fd != -1);
		if (!success) throw FrdpException(0, {{"msg","error opening reserved memory device (" + string(strerror(errno)) + ")"}});

		if (success) {
			buf = mmap(NULL, stg.NChunk * stg.sizeChunk * 1048576, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); // PROT_WRITE for debug functionality

			success = (buf != MAP_FAILED);
			if (!success) throw FrdpException(0, {{"msg","error mapping reserved memory (" + string(strerror(errno)) + ")"}});
		};

		if (success) {
			memset(buf, 0, stg.NChunk * stg.sizeChunk * 1048576);

			for (unsigned int i = 0; i < stg.NChunk; i++) resultCube.append(new Resultitem(*this, ci, i));
		};

		if (!success && (fd != -1)) {
			close(fd);
			fd = 0;
		};

	} catch (FrdpException& e) {
		cout << e.getSquawk(VecFrdpVError::getIx, VecFrdpVError::getTitle, VecFrdpVLocale::ENUS) << endl;
	};

	bufDummy = NULL;

	cube = 0;

	cancelCube = false;
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

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

JobWzskAcqHdr::~JobWzskAcqHdr() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void* JobFrdpAcqFpgacube::runCube(
			void* arg
		) {
	JobFrdpAcqFpgacube* srv = (JobFrdpAcqFpgacube*) arg;

	Call call(VecFrdpVCall::CALLFRDPCALLBACK, srv->jref, Arg());
	ExtcallFrdp extcall(srv->xchg, &call);

	uint ixRi;
	Frdp::ResultitemCube* ri = NULL;
	uint8_t tixVSuccess_expect;

	const uint8_t ixMemInvalid = 0xFF;

	uint8_t ixMem0 = ixMemInvalid;
	uint8_t ixMem1 = ixMemInvalid;

	uint8_t tixVState;
	uint8_t ixMem;
	uint8_t tixVSuccess;
	uint16_t lanefault;
	uint32_t tkst;
	uint8_t ixMemLfft;
	uint8_t ixMemSfft;

	bool resultNew;

	// at any given time, there can be at most two ixMem's assign()ed to cubeacq
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

	timespec deltatFixed, deltatFrame;

/*
	deltatFixed = {.tv_sec = 0, .tv_nsec = 500000}; // 0.5 ms

	// frame duration minus 2 ms, min. 0.5 ms
	deltatFrame.tv_sec = 0;
	deltatFrame.tv_nsec = (ci.TTrig > 2500) ? ci.TTrig : 2500;
	deltatFrame.tv_nsec -= 2000;
	if (deltatFrame.tv_nsec >= 1000000) deltatFrame.tv_nsec = 999999 * 1000;
	else deltatFrame.tv_nsec *= 1000;
*/
	deltatFixed = {.tv_sec = 0, .tv_nsec = 10000000}; // 10 ms
	deltatFrame = {.tv_sec = 0, .tv_nsec = 10000000}; // 10 ms
	
	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupCube, arg);

	try {
		// - prepare
		shrdat.mCube.lock("JobFrdpAcqFpgacube", "runCube[1]");

		// switch on
		if (srv->srcbase) {
			srv->srcbase->shrdat.hw.cubeacq->set(
						true, // rng={false,true}
						false, // ixsimNotData={false,true}
						false // ixsim4DNot3D={false,true}
					);

		} else if (srv->srcbasezero) {
			srv->srcbasezero->shrdat.hw.cubeacq->set(
						true, // rng={false,true}
						false, // ixsimNotData={false,true}
						false // ixsim4DNot3D={false,true}
					);
		};

		shrdat.mCube.unlock("JobFrdpAcqFpgacube", "runCube[1]");

		// - loop
		while (true) {
			if (shrdat.cancelCube) break;

			shrdat.mCube.lock("JobFrdpAcqFpgacube", "runCube[2]");

			resultNew = false;

			if (srv->srcbase) {
				srv->srcbase->shrdat.hw.cubeacq->getInfo(tixVState, ixMem, tixVSuccess, lanefault, tkst, ixMemLfft, ixMemSfft);

				// ixMem0: latest to have been assigned

				if (ixMem != ixMemInvalid) {
					if ((ixMem == ixMem0) || (ixMem == ixMem1)) {
						// next frame fully processed
						ri = (Frdp::ResultitemCube*) shrdat.resultCube[ixMem];

						if (ri->ixFrdpVCubeorder == VecFrdpVCubeorder::RVAE) tixVSuccess_expect = VecVFrpdBaseCubeacqSuccess::SFFT2;
						else if ((ri->ixFrdpVCubeorder == VecFrdpVCubeorder::RVA) || (ri->ixFrdpVCubeorder == VecFrdpVCubeorder::E0RVA)) tixVSuccess_expect = VecVFrpdBaseCubeacqSuccess::SFFT1;
						else if ((ri->ixFrdpVCubeorder == VecFrdpVCubeorder::RV) || (ri->ixFrdpVCubeorder == VecFrdpVCubeorder::A0RV) || (ri->ixFrdpVCubeorder == VecFrdpVCubeorder::AE0RV)) tixVSuccess_expect = VecVFrpdBaseCubeacqSuccess::SFFT0;
						else tixVSuccess_expect = VecVFrpdBaseCubeacqSuccess::LFFT;

						ri->tkst = tkst;

						ri->tIn = srv->srcbase->tkstToT(tkst);

						if (stg.verbose) cout << "[" << (((double) tkst) / 10000.0) << "] acquired new frame with ixMem = " << ((unsigned int) ixMem) << " (ixMemLfft = " << ((unsigned int) ixMemLfft) << ", ixMemSfft = " << ((unsigned int) ixMemSfft) << "); last successful FFT: " << VecVFrpdBaseCubeacqSuccess::getSref(tixVSuccess) << endl;

						resultNew = true;

						if (ixMem == ixMem0) {
							// slip case (ixMem1 result was missed)
							ixMem0 = ixMemInvalid;

							if (ixMem1 != ixMemInvalid) {
								shrdat.resultCube.unlock(srv->jref, ixMem1);
								ixMem1 = ixMemInvalid;
							};

						} else if (ixMem == ixMem1) {
							// no-slip case
							ixMem1 = ixMemInvalid;
						};

						if (stg.dummy || (tixVSuccess == tixVSuccess_expect)) {
							call.argInv = Arg(ixMem, 0, {}, VecFrdpVCubeorder::getSref(ri->ixFrdpVCubeorder), 0, 0.0, false, "", Arg::IX + Arg::SREF);
							XchgFrdp::runExtcall(&extcall);
						} else shrdat.resultCube.unlock(srv->jref, ixMem);
					};
				};

				if ((ixMem0 != ixMemInvalid) && (ixMem1 == ixMemInvalid) && ((ixMemLfft == ixMem0) || (ixMemSfft == ixMem0)) ) {
					// condition when processing at ixMem0 is in progress
					ixMem1 = ixMem0;

					if (shrdat.resultCube.dequeue(ixRi)) ixMem0 = ixRi;
					else ixMem0 = ixMemInvalid;
					srv->srcbase->shrdat.hw.cubeacq->assign(ixMem0);
					//if (ixMem0 != ixMemInvalid) cout << "assigned ixMem0 = " << ((unsigned int) ixMem0) << " on top"  << " (ixMem = " << ((unsigned int) ixMem) << ", ixMemLfft = " << ((unsigned int) ixMemLfft) << ", ixMemSfft = " << ((unsigned int) ixMemSfft) << ")" << endl;

				} else if (ixMem0 == ixMemInvalid) {
					// condition at start or after slip
					if (shrdat.resultCube.dequeue(ixRi)) ixMem0 = ixRi;
					else ixMem0 = ixMemInvalid;
					srv->srcbase->shrdat.hw.cubeacq->assign(ixMem0);
					//if (ixMem0 != ixMemInvalid) cout << "assigned ixMem0 = " << ((unsigned int) ixMem0) << " after slip"  << " (ixMem = " << ((unsigned int) ixMem) << ", ixMemLfft = " << ((unsigned int) ixMemLfft) << ", ixMemSfft = " << ((unsigned int) ixMemSfft) << ")" << endl;
				};

			} else if (srv->srcbasezero) {
				srv->srcbasezero->shrdat.hw.cubeacq->getInfo(tixVState, ixMem, tixVSuccess, lanefault, tkst, ixMemLfft);

				// ixMem0: latest to have been assigned

				if (ixMem != ixMemInvalid) {
					if ((ixMem == ixMem0) || (ixMem == ixMem1)) {
						// next frame fully processed
						ri = (Frdp::ResultitemCube*) shrdat.resultCube[ixMem];

						tixVSuccess_expect = VecVFrpdBasezeroCubeacqSuccess::LFFT;

						ri->tkst = tkst;

						ri->tIn = srv->srcbasezero->tkstToT(tkst);

						if (stg.verbose) cout << "[" << (((double) tkst) / 10000.0) << "] acquired new frame with ixMem = " << ((unsigned int) ixMem) << " (ixMemLfft = " << ((unsigned int) ixMemLfft) << "); last successful FFT: " << VecVFrpdBasezeroCubeacqSuccess::getSref(tixVSuccess) << endl;

						resultNew = true;

						if (ixMem == ixMem0) {
							// slip case (ixMem1 result was missed)
							ixMem0 = ixMemInvalid;

							if (ixMem1 != ixMemInvalid) {
								shrdat.resultCube.unlock(srv->jref, ixMem1);
								ixMem1 = ixMemInvalid;
							};

						} else if (ixMem == ixMem1) {
							// no-slip case
							ixMem1 = ixMemInvalid;
						};

						if (stg.dummy || (tixVSuccess == tixVSuccess_expect)) {
							call.argInv = Arg(ixMem, 0, {}, VecFrdpVCubeorder::getSref(ri->ixFrdpVCubeorder), 0, 0.0, false, "", Arg::IX + Arg::SREF);
							XchgFrdp::runExtcall(&extcall);
						} else shrdat.resultCube.unlock(srv->jref, ixMem);
					};
				};

				if ((ixMem0 != ixMemInvalid) && (ixMem1 == ixMemInvalid) && (ixMemLfft == ixMem0) ) {
					// condition when processing at ixMem0 is in progress
					ixMem1 = ixMem0;

					if (shrdat.resultCube.dequeue(ixRi)) ixMem0 = ixRi;
					else ixMem0 = ixMemInvalid;
					srv->srcbasezero->shrdat.hw.cubeacq->assign(ixMem0);
					//if (ixMem0 != ixMemInvalid) cout << "assigned ixMem0 = " << ((unsigned int) ixMem0) << " on top"  << " (ixMem = " << ((unsigned int) ixMem) << ", ixMemLfft = " << ((unsigned int) ixMemLfft) << ")" << endl;

				} else if (ixMem0 == ixMemInvalid) {
					// condition at start or after slip
					if (shrdat.resultCube.dequeue(ixRi)) ixMem0 = ixRi;
					else ixMem0 = ixMemInvalid;
					srv->srcbasezero->shrdat.hw.cubeacq->assign(ixMem0);
					//if (ixMem0 != ixMemInvalid) cout << "assigned ixMem0 = " << ((unsigned int) ixMem0) << " after slip"  << " (ixMem = " << ((unsigned int) ixMem) << ", ixMemLfft = " << ((unsigned int) ixMemLfft) << ")" << endl;
				};
			};

			shrdat.mCube.unlock("JobFrdpAcqFpgacube", "runCube[2]");

			if (resultNew) nanosleep(&deltatFrame, NULL);
			else nanosleep(&deltatFixed, NULL);
		};

	} catch (DbeException& e) {
		cout << e.err << endl;

		call.argInv = Arg();
		XchgFrdp::runExtcall(&extcall);

		shrdat.mCube.unlock("JobFrdpAcqFpgacube", "runCube[4]");
	};

	try {
		// - clean up
		//cout << "JobFrdpAcqFpgacube::runCube() cleaning up" << endl;

		if (srv->srcbase) {
			srv->srcbase->shrdat.hw.cubeacq->set(
						false, // rng={false,true}
						false, // ixsimNotData={false,true}
						false // ixsim4DNot3D={false,true}
					);

		} else if (srv->srcbasezero) {
			srv->srcbasezero->shrdat.hw.cubeacq->set(
						false, // rng={false,true}
						false, // ixsimNotData={false,true}
						false // ixsim4DNot3D={false,true}
					);
		};

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	pthread_cleanup_pop(0);

	shrdat.cube = 0;

	return NULL;
};

void JobFrdpAcqFpgacube::cleanupCube(
			void* arg
		) {
	shrdat.mCube.lock("JobFrdpAcqFpgacube", "cleanupCube");

	//cout << "JobFrdpAcqFpgacube::cleanupCube()" << endl;
	shrdat.cube = 0;

	shrdat.mCube.unlock("JobFrdpAcqFpgacube", "cleanupCube");
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

bool JobFrdpAcqFpgacube::handleCallFrdpCallbackFromSelfInSgeRng(
			DbsFrdp* dbsfrdp
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallFrdpCallbackFromSelfInSgeRng --- IBEGIN
	unsigned char* buf_save = NULL;

	if (trylockAccess("handleCallFrdpCallbackFromSelfInSgeRng")) {
		if (nextIxVSgeFailure != VecVSge::RNG) {
			// claim run attribute has been retracted
			changeStage(dbsfrdp, VecVSge::IDLE);

		} else if (srefInv == "") {
			// something went wrong, cancel thread
			changeStage(dbsfrdp, VecVSge::IDLE);

		} else {
			// new result available
			shrdat.resultCube.lock(jref, ixInv);

			if (stg.dummy) {
				// dummy behavior: temporarily swap out shared memory section for buffer containing dummy data
				buf_save = ((Frdp::ResultitemCube*) shrdat.resultCube[ixInv])->buf;
				((Frdp::ResultitemCube*) shrdat.resultCube[ixInv])->buf = shrdat.bufDummy;
			};

			// inform super-jobs about new result
			xchg->triggerIxSrefCall(dbsfrdp, VecFrdpVCall::CALLFRDPRESULTNEW, jref, ixInv, srefInv);

			// resetting here interferes with deferred processing in JobFrdpAcqCube
			//if (stg.dummy) ((Frdp::ResultitemCube*) shrdat.resultCube[ixInv])->buf = buf_save;

			shrdat.resultCube.unlock(jref, ixInv);
		};

		unlockAccess("handleCallFrdpCallbackFromSelfInSgeRng");

	} else {
		if (srefInv != "") shrdat.resultCube.unlock(0, ixInv);
	};
	// IP handleCallFrdpCallbackFromSelfInSgeRng --- IEND
	return retval;
};

bool JobWzskAcqHdr::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};
