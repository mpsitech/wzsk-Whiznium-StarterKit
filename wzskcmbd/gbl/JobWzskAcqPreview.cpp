/**
	* \file JobWzskAcqPreview.cpp
	* job handler for job JobWzskAcqPreview (implementation)
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

#include "JobWzskAcqPreview.h"

#include "JobWzskAcqPreview_blks.cpp"
#include "JobWzskAcqPreview_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

using namespace Dbecore; // IP ns.cust --- ILINE

// IP ns.spec --- INSERT

// IP Shrdat.subs --- IBEGIN
/******************************************************************************
 class JobWzskAcqPreview::Shrdat::Resultitem
 ******************************************************************************/

JobWzskAcqPreview::Shrdat::Resultitem::Resultitem(
			XchgWzsk* xchg
		) :
			w(xchg->stgwzskcamera.NColRaw/2/6)
			, h(xchg->stgwzskcamera.NRowRaw/2/6)
			, rgbNotGray(true)
			, edge(6)
			, sizeBuf(1024*stg.sizePvwbuf)
			, lenBuf(w*h*3)
			, t(0.0)
		{
	buf = new unsigned char[sizeBuf];
};

JobWzskAcqPreview::Shrdat::Resultitem::~Resultitem() {
	if (buf) delete[] buf;
};

void JobWzskAcqPreview::Shrdat::Resultitem::config(
			const unsigned int _w
			, const unsigned int _h
			, const bool _rgbNotGray
		) {
	w = _w;
	h = _h;
	rgbNotGray = _rgbNotGray;

	lenBuf = w*h * ((rgbNotGray) ? 3 : 1);
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
	pvw = 0;

	calcDecim(xchg, false, 0);

	cancelPvw = false;

	for (unsigned int i = 0; i < 2; i++) resultPvw.append(new Resultitem(xchg));
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

JobWzskAcqPreview::~JobWzskAcqPreview() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
/******************************************************************************
 class JobWzskAcqPreview::Claim
 ******************************************************************************/

JobWzskAcqPreview::Claim::Claim(
			const bool retractable
			, const bool run
			, const bool rgbNotGray
			, const utinyint edge
		) :
			Sbecore::Claim(retractable, run)
			, rgbNotGray(rgbNotGray)
			, edge(edge)
		{
};

/******************************************************************************
 class JobWzskAcqPreview
 ******************************************************************************/

void* JobWzskAcqPreview::runPvw(
			void* arg
		) {
	JobWzskAcqPreview* srv = (JobWzskAcqPreview*) arg;

	Call call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg());
	ExtcallWzsk extcall(srv->xchg, &call);

	uint ixRi = shrdat.resultPvw.size();
	Shrdat::Resultitem* ri = NULL;

	bool rgbNotGray = shrdat.rgbNotGray_next;
	uint8_t edge = shrdat.edge_next;
	uint16_t edge2 = shrdat.edge2_next;
	uint16_t NDecim;

	uint8_t tixVState;
	uint32_t tkst;

	size_t datalen;

	timespec deltatPoll = {.tv_sec = 0, .tv_nsec = 1000000}; // 1 ms
	timespec deltatFrame = {.tv_sec = 0, .tv_nsec = 15000000}; // 15 ms

	UntWskdZuvsp& zuvsp = JobWzskSrcZuvsp::shrdat.hw;

	bool first = true;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanupPvw, arg);

	try {
		// - loop
		while (true) {
			if (shrdat.cancelPvw) break;

			shrdat.mPvw.lock("JobWzskAcqPreview", "runPvw[1]");

			if ((first) || ((rgbNotGray != shrdat.rgbNotGray_next) || (edge != shrdat.edge_next))) {
				if (srv->srczuvsp) zuvsp.decim->set(false); // rng={false,true}

				first = false;

				rgbNotGray = shrdat.rgbNotGray_next;
				edge = shrdat.edge_next;
				edge2 = shrdat.edge2_next;

				NDecim = (srv->xchg->stgwzskcamera.NColRaw/2/edge)*(srv->xchg->stgwzskcamera.NRowRaw/2/edge) * ((rgbNotGray) ? 3 : 1);

				cout << "JobWzskAcqPreview::runPvw re-configuring to " << ((rgbNotGray) ? "rgb" : "gray") << ", edge = " << ((int) edge) << ", edge2 = " << ((int) edge2) << ", NDecim = " << ((int) NDecim) << endl;

				if (srv->srczuvsp) zuvsp.decim->config(
							rgbNotGray // rgbNotGray={false,true}
							, edge // edge=[uint8]
							, edge2 // edge2=[uint16]
							, NDecim // NDecim=[uint16]
						);

				if (srv->srczuvsp) {
					zuvsp.decim->set(true); // rng={false,true}
					if (ri) zuvsp.decim->acquire(0); // ixTExp=[uint8]
				};
			};

			shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[1]");

			if (ri) {
				shrdat.mPvw.lock("JobWzskAcqPreview", "runPvw[2]");

				tixVState = 0;

				if (srv->srczuvsp) zuvsp.decim->getInfo(tixVState, tkst); // tixVState{idle,acq,lock},tkst[uint32]

				if (tixVState == VecVWskdZuvspDecimState::LOCK) {
					cout << "JobWzskAcqPreview::runPvw locked" << endl;

					ri->config(srv->xchg->stgwzskcamera.NColRaw/2/edge, srv->xchg->stgwzskcamera.NRowRaw/2/edge, rgbNotGray);

					try {
						cout << "JobWzskAcqPreview::runPvw reading " << ri->sizeBuf << " bytes" << endl;

						if (srv->srczuvsp) zuvsp.readPvwbufFromDecim(ri->sizeBuf, ri->buf, datalen);

					} catch (DbeException& e) {
						shrdat.resultPvw.unlock(srv->jref, ixRi); // put result item back in queue and try again

						ri = NULL;
					};

					if (srv->srczuvsp) zuvsp.decim->unlock();

					if (ri) {
						if (srv->srczuvsp) ri->t = srv->srczuvsp->tkstToT(tkst);

						call.argInv = Arg(ixRi, 0, {}, "", 0, 0.0, false, "", Arg::IX);
						XchgWzsk::runExtcall(&extcall);

						ri = NULL;
					};
				};

				shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[2]");

			} else if (shrdat.resultPvw.dequeue(ixRi)) {
				ri = (Shrdat::Resultitem*) shrdat.resultPvw[ixRi];

				if (srv->srczuvsp) zuvsp.decim->acquire(0); // ixTExp=[uint8]
			};

			if (ri) nanosleep(&deltatPoll, NULL);
			else nanosleep(&deltatFrame, NULL);
		};

	} catch (DbeException& e) {
		cout << e.err << endl;

		call.argInv = Arg(0, 0, {}, "err", 0, 0.0, false, "", Arg::SREF);
		XchgWzsk::runExtcall(&extcall);

		shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[3]");
	};

	try {
		// - clean up
		if (srv->srczuvsp) zuvsp.decim->set(false); // rng={false,true}

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	pthread_cleanup_pop(0);

	shrdat.pvw = 0;

	return NULL;
};

void JobWzskAcqPreview::cleanupPvw(
			void* arg
		) {
	shrdat.mPvw.lock("JobWzskAcqPreview", "cleanupPvw");

	shrdat.pvw = 0;

	shrdat.mPvw.unlock("JobWzskAcqPreview", "cleanupPvw");
};

void JobWzskAcqPreview::calcDecim(
			XchgWzsk* xchg
			, const bool rgbNotGray
			, const utinyint _edge
		) {
	unsigned int edge, edge2;

	double d;

	// calculate minimal edge (decimation factor) so that decimated frame still fits in the preview buffer
	d = xchg->stgwzskcamera.NColRaw/2 * xchg->stgwzskcamera.NRowRaw/2 * ((rgbNotGray) ? 3 : 1);
	d = d / ((double) (stg.sizePvwbuf * 1024));
	edge = ceil(sqrt(d));

	if (_edge > edge) edge = _edge;
	if (edge < 6) edge = 6;
	if (edge > 16) edge = 16;

	// calculate pre >> 12 multiplier for best approximation of integer division
	d = 1.0 / ((double) (edge*edge));
	edge2 = floor(d/(1.0/4096.0));

	shrdat.rgbNotGray_next = rgbNotGray;
	shrdat.edge_next = edge;
	shrdat.edge2_next = edge2;
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

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	};
};

void JobWzskAcqPreview::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKCALLBACK) && (call->jref == jref) && (ixVSge == VecVSge::RNG)) {
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool JobWzskAcqPreview::handleCallWzskCallbackFromSelfInSgeRng(
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
			shrdat.resultPvw.lock(jref, ixInv);

			// inform super-jobs about new result
			xchg->triggerIxSrefCall(dbswzsk, VecWzskVCall::CALLWZSKRESULTNEW, jref, ixInv, srefInv);

			shrdat.resultPvw.unlock(jref, ixInv);
		};

		unlockAccess("handleCallWzskCallbackFromSelfInSgeRng");

	} else {
		if (srefInv != "err") shrdat.resultPvw.unlock(jref, ixInv);
	};
	// IP handleCallWzskCallbackFromSelfInSgeRng --- IEND
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
				case VecVSge::RNG: leaveSgeRng(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			//cout << "JobWzskAcqPreview now entering stage " << VecVSge::getSref(_ixVSge) << endl; // IP changeStage.refresh1 --- ILINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::RNG: _ixVSge = enterSgeRng(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskAcqPreview::getSquawk(
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

uint JobWzskAcqPreview::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- IBEGIN
	pthread_t oldPvw;

	shrdat.cancelPvw = true;

	shrdat.mPvw.lock("JobWzskAcqPreview", "enterSgeIdle");

	oldPvw = shrdat.pvw; // original will be set 0 in the process

	if (oldPvw != 0) {
		shrdat.mPvw.unlock("JobWzskAcqPreview", "enterSgeIdle[1]");

		pthread_join(oldPvw, NULL);

	} else shrdat.mPvw.unlock("JobWzskAcqPreview", "enterSgeIdle[2]");

	xchg->clearCsjobRun(dbswzsk, ixWzskVJob);

	for (unsigned int i = 0; i < shrdat.resultPvw.size(); i++) shrdat.resultPvw.unlock(jref, i);
	// IP enterSgeIdle --- IEND

	return retval;
};

void JobWzskAcqPreview::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskAcqPreview::enterSgeRng(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RNG;

	// IP enterSgeRng --- IBEGIN
	int res;
	pthread_attr_t attr;

	if (shrdat.pvw != 0) retval = VecVSge::IDLE;
	else {
		shrdat.mPvw.lock("JobWzskAcqPreview", "enterSgeRng");

		shrdat.cancelPvw = false;

		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

		for (unsigned int i = 0; i < 3; i++) {
			res = pthread_create(&shrdat.pvw, &attr, &runPvw, (void*) this);
			if ((res == 0) || (res != EAGAIN)) break;
		};
		if (res != 0) cout << "JobWzskAcqPreview::enterSgeRng() error creating preview thread (" << res << ")" << endl;

		shrdat.mPvw.unlock("JobWzskAcqPreview", "enterSgeRng");
	};
	// IP enterSgeRng --- IEND

	return retval;
};

void JobWzskAcqPreview::leaveSgeRng(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeRng --- INSERT
};

bool JobWzskAcqPreview::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- IBEGIN

	// claim policy:
	// - exactly one claim can be fulfilled
	// - only possible if src*vsp "decim" claim can be fulfilled
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

			rgbNotGray = claim->rgbNotGray;
			edge = claim->edge;
		};
	};

	// add or remove "decim" claim with src*vsp
	if (srcdcvsp) srcvsp = srcdcvsp;
	else if (srctivsp)  srcvsp = srctivsp;
	else if (srczuvsp) srcvsp = srczuvsp;

	if (srcvsp) {
		if (claims.empty()) xchg->removeCsjobClaim(dbswzsk, srcvsp);
		else xchg->addCsjobClaim(dbswzsk, srcvsp, new Wzsk::ClaimVsp(false, Wzsk::ClaimVsp::VecWDomain::CORNER));

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

					rgbNotGray = claim->rgbNotGray;
					edge = claim->edge;

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
		calcDecim(xchg, rgbNotGray, edge);
	
		nextIxVSgeFailure = VecVSge::RNG;

		if (ixVSge == VecVSge::IDLE) changeStage(dbswzsk, VecVSge::RNG);
	};

	mod = true; // for simplicity

	// IP handleClaim --- IEND

	return mod;
};
