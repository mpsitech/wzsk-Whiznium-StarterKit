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
			w(xchg->stgwzskcamera.NColRaw/2)
			, h(xchg->stgwzskcamera.NRowRaw/2)
			, rgbNotGray(true)
			, edge(6)
			, t(0.0)
		{
	sizeBuf = w*h * ((rgbNotGray) ? 3 : 1) * edge*edge;

	buf = new unsigned char[sizeBuf]; // allocate space for max i.e. rgb and edge 6
};

JobWzskAcqPreview::Shrdat::Resultitem::~Resultitem() {
	if (buf) delete[] buf;
};

void JobWzskAcqPreview::Shrdat::Resultitem::config(
			const bool _rgbNotGray
			, const Sbecore::utinyint _edge
		) {
	rgbNotGray = _rgbNotGray;
	edge = _edge;

	sizeBuf = w*h * ((rgbNotGray) ? 3 : 1) * edge*edge;
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

	rgbNotGray_next = false;
	edge_next = 6;

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

	uint ixWzskVPvwmode = 0;
	unsigned int w, h;
	size_t sizeBuf;

	Wzsk::getPvwWh(srv->xchg->stgwzskglobal.ixWzskVTarget, VecWzskVPvwmode::BINRGB, w, h); // the larger of both possible buffer sizes
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
		shrdat.mPvw.lock("JobWzskAcqPreview", "runPvw[1]");

		if (srv->srczuvsp) {
			srv->srczuvsp->camacq_setPvw(false, 0, 0);
			srv->srczuvsp->camif_setRng(true);
		};

		shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[1]");

		// - loop
		while (true) {
			if (shrdat.cancelPvw) break;

			if (shrdat.ixWzskVPvwmode != ixWzskVPvwmode) {
				// allow preview mode to change while thread running
				if (srv->srczuvsp) srv->srczuvsp->camacq_setPvw(true, Wzsk::getPvwRawNotBin(shrdat.ixWzskVPvwmode), Wzsk::getPvwGrayNotRgb(shrdat.ixWzskVPvwmode));

				ixWzskVPvwmode = shrdat.ixWzskVPvwmode;

				Wzsk::getPvwWh(srv->xchg->stgwzskglobal.ixWzskVTarget, ixWzskVPvwmode, w, h);
				sizeBuf = w * h;
				if (!Wzsk::getPvwGrayNotRgb(shrdat.ixWzskVPvwmode)) sizeBuf *= 3;

				// sleep for 1/4Hz - 10ms = 240ms
				deltat = {.tv_sec = 0, .tv_nsec = 240000000};
				//nanosleep(&deltat, NULL);

				continue;
			};

			shrdat.mPvw.lock("JobWzskAcqPreview", "runPvw[2]");

			if (srv->srczuvsp) srv->srczuvsp->camacq_getPvwinfo(tixVPvwbufstate, tkst);
			//cout << "tixVPvwbufstate = " << VecVWskdArtyCamacqPvwbufstate::getSref(tixVPvwbufstate) << ", tkst = " << tkst << endl;

			if ((tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::ABUF) || (tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::BBUF)) {
				ri = NULL;
				if (shrdat.resultPvw.dequeue(ixRi)) ri = (Shrdat::ResultitemPvw*) shrdat.resultPvw[ixRi];

				if (ri) {
					ri->setPvwmode(srv->xchg->stgwzskglobal.ixWzskVTarget, ixWzskVPvwmode);

					if (srv->srczuvsp) ri->t = srv->srczuvsp->tkstToT(tkst);

					buf = ri->buf;

				} else buf = auxbuf;

				try {
					if (tixVPvwbufstate == VecVWskdArtyCamacqPvwbufstate::ABUF) {
						if (srv->srczuvsp) srv->srczuvsp->shrdat.hw.readPvwabufFromCamacq(sizeBuf, buf, datalen);
					};

				} catch (DbeException& e) {
					if (ri) {
						shrdat.resultPvw.unlock(srv->jref, ixRi); // put result item back in queue and try again, starting from camacq_getPvwinfo()
						ri = NULL;
					};
				};

				if (ri) XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg(ixRi, 0, {}, VecWzskVPvwmode::getSref(ixWzskVPvwmode), 0, 0.0, false, "", Arg::IX + Arg::SREF))));

				shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[2]");

				if (ri) {
					// sleep for 1/4Hz - 10ms = 240ms
					deltat = {.tv_sec = 0, .tv_nsec = 240000000};
					//nanosleep(&deltat, NULL);
				};

			} else {
				shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[3]");

				// sleep for ten milliseconds
				deltat = {.tv_sec = 0, .tv_nsec = 10000000};
				nanosleep(&deltat, NULL);
			};
		};

	} catch (DbeException& e) {
		cout << e.err << endl;

		XchgWzsk::runExtcall(new ExtcallWzsk(srv->xchg, new Call(VecWzskVCall::CALLWZSKCALLBACK, srv->jref, Arg())));

		shrdat.mPvw.unlock("JobWzskAcqPreview", "runPvw[4]");
	};

	try {
		// - clean up
		if (srv->srczuvsp) {
			srv->srczuvsp->camacq_setPvw(false, 0, 0);
			srv->srczuvsp->camif_setRng(true);
		};

	} catch (DbeException& e) {
		cout << e.err << endl;
	};

	delete[] auxbuf;

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
		call->abort = handleCallWzskCallbackFromSelfInSgeRng(dbswzsk);
	};
};

bool JobWzskAcqPreview::handleCallWzskCallbackFromSelfInSgeRng(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskCallbackFromSelfInSgeRng --- INSERT
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
			// IP changeStage.refresh1 --- INSERT
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

	// IP enterSgeIdle --- INSERT

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

	// IP enterSgeRng --- INSERT

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

	// IP handleClaim --- INSERT

	return mod;
};
