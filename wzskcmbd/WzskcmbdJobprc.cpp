/**
	* \file WzskcmbdJobprc.cpp
	* job processor for Wzsk combined daemon (implementation)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#include "Wzskcmbd.h"

#include "WzskcmbdJobprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzskcmbdJobprc
 ******************************************************************************/

void* WzskcmbdJobprc::run(
			void* arg
		) {
	XchgWzskcmbd* xchg = (XchgWzskcmbd*) arg;

	ReqWzsk* req = NULL;
	JobWzsk* job = NULL;

	ubigint eref;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWzsk dbswzsk;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswzsk.init(xchg->stgwzskdatabase.ixDbsVDbstype, xchg->stgwzskdatabase.dbspath, xchg->stgwzskdatabase.dbsname, xchg->stgwzskdatabase.ip,
						xchg->stgwzskdatabase.port, xchg->stgwzskdatabase.username, xchg->stgwzskdatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WzskcmbdJobprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WzskcmbdJobprc", "run");

	try {
		// main loop: wait for requests
		while (true) {
			xchg->cJobprcs.lockMutex("WzskcmbdJobprc", "run");
			req = xchg->pullFirstReq();

			while (!req) {
				xchg->cJobprcs.wait("WzskcmbdJobprc", "run");
				req = xchg->pullFirstReq();
			};

			xchg->cJobprcs.unlockMutex("WzskcmbdJobprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cJobprcs.signal("WzskcmbdJobprc", "run");

			// --- handle request
			if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
				xchg->mon.eventHandleReqCmd(req->jref, req->cmd);

				// pass on to job
				accessJob(xchg, &dbswzsk, req);

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
				if (req->dpchapp) {
					//cout << "WzskcmbdJobprc::run() DPCHAPP request:'" << VecWzskVDpch::getSref(req->dpchapp->ixWzskVDpch) << "'" << endl;
					eref = xchg->mon.eventHandleReqDpchapp(req->jref, VecWzskVDpch::getSref(req->dpchapp->ixWzskVDpch), req->dpchapp->getSrefsMask(), "");

					// pass on to job
					accessJob(xchg, &dbswzsk, req);
				};

				if (!req->dpcheng) req->dpcheng = new DpchEngWzskAck(req->jref);
				xchg->mon.eventReplyReqDpchapp(eref, req->jref, VecWzskVDpch::getSref(req->dpcheng->ixWzskVDpch), req->dpcheng->getSrefsMask(), "");

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::UPLOAD) {
				//cout << "WzskcmbdJobprc::run() UPLOAD request file name: '" << req->filename << "'" << endl;
				xchg->mon.eventHandleReqUpload(req->jref, req->filename);

				// pass on to job
				accessJob(xchg, &dbswzsk, req);

				// usually the job leaves req unchanged

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DOWNLOAD) {
				eref = xchg->mon.eventHandleReqDownload(req->jref);

				// pass on to job
				accessJob(xchg, &dbswzsk, req);

				xchg->mon.eventReplyReqDownload(eref, req->jref, req->filename);

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHRET) {
				if (req->dpchret) {
					//cout << "WzskcmbdJobprc::run() DPCHRET request: '" << VecWzskVDpch::getSref(req->dpchret->ixWzskVDpch) << "'" << endl;

					job = xchg->getJobByJref(req->jref);
					if (job) job->removeOp(req->dpchret->oref);

					xchg->mon.eventHandleReqDpchret(req->jref, VecWzskVDpch::getSref(req->dpchret->ixWzskVDpch), "", req->dpchret->oref);

					accessJob(xchg, &dbswzsk, req);
				};

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::METHOD) {
				if (req->method) {
					//cout << "WzskcmbdJobprc::run() METHOD request: '" << VecWzskVFeatgroup::getSref(req->method->ixVFeatgroup) << "." << req->method->srefIxVMethod << "'" << endl;
					xchg->mon.eventHandleReqMethod(req->jref, VecWzskVFeatgroup::getSref(req->method->ixVFeatgroup), req->method->srefIxVMethod);

					// pass on to job
					accessJob(xchg, &dbswzsk, req);
				};

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
				// pass on to job
				job = xchg->getJobByJref(req->jref);

				if (job) if (req->wref >= job->wrefMin) {
					xchg->mon.eventHandleReqTimer(req->jref, req->sref);
					accessJob(xchg, &dbswzsk, req);
				};

			} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::EXTCALL) {
				xchg->triggerCall(&dbswzsk, req->call);
			};

			if ((req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHRET) || (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) || (req->ixVBasetype == ReqWzsk::VecVBasetype::EXTCALL)) {
				// ret, timer and extcall requests can be deleted here
				delete req;

			} else {
				// all other requests are being waited for for further processing
				if (!(req->retain)) req->setStateReply();
			};
		};

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
		throw;
	};

	pthread_cleanup_pop(0);

	return(NULL);
};

void WzskcmbdJobprc::cleanup(
			void* arg
		) {
	XchgWzskcmbd* xchg = (XchgWzskcmbd*) arg;

	xchg->cJobprcs.unlockMutex("WzskcmbdJobprc", "cleanup");
};

void WzskcmbdJobprc::accessJob(
			XchgWzskcmbd* xchg
			, DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	JobWzsk* job = NULL;
	
	job = xchg->getJobByJref(req->jref);
	if (job) {
		if (!req->weak) job->lockAccess("WzskcmbdJobprc", "accessJob");

		req->ixWzskVLocale = job->ixWzskVLocale;
		job->handleRequest(dbswzsk, req);
	};

	if (!req->weak) {
		job = xchg->getJobByJref(req->jref);
		if (job) job->unlockAccess("WzskcmbdJobprc", "accessJob");
	};
};

