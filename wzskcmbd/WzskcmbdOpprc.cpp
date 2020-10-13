/**
	* \file WzskcmbdOpprc.cpp
	* operation processor for Wzsk combined daemon (implementation)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#include "Wzskcmbd.h"

#include "WzskcmbdOpprc.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace WzskcmbdOpprc
 ******************************************************************************/

void* WzskcmbdOpprc::run(
			void* arg
		) {
	XchgWzskcmbd* xchg = (XchgWzskcmbd*) arg;

	ReqWzsk* req = NULL;
	DpchInvWzsk* inv = NULL;

	// thread settings
	pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, 0);
	pthread_cleanup_push(&cleanup, arg);

	cout << Mt::getTid() << flush;

	// open database connection
	DbsWzsk dbswzsk;
	int contry = 10;

	while (contry > 0) {
		try {
			dbswzsk.init(xchg->stgwzskdatabase.ixDbsVDbstype, xchg->stgwzskdatabase.dbspath, xchg->stgwzskdatabase.dbsname, xchg->stgwzskdatabase.ip
						, xchg->stgwzskdatabase.port, xchg->stgwzskdatabase.username, xchg->stgwzskdatabase.password);
			break;

		} catch (SbeException& e) {
			contry--;

			if (contry == 0) {
				e.vals["tid"] = Mt::getTid();
				e.vals["object"] = "WzskcmbdOpprc";
				e.vals["member"] = "run";

				throw;
			};
		};
	};

	xchg->cStable.signal("WzskcmbdOpprc", "run");

	try {
		// main loop: wait for operation invocations
		while (true) {
			xchg->cOpprcs.lockMutex("WzskcmbdOpprc", "run");
			inv = xchg->pullFirstInv();

			while (!inv) {
				xchg->cOpprcs.wait("WzskcmbdOpprc", "run");
				inv = xchg->pullFirstInv();
			};

			xchg->cOpprcs.unlockMutex("WzskcmbdOpprc", "run");

			// re-signal condition to avoid using broadcast
			xchg->cOpprcs.signal("WzskcmbdOpprc", "run");

			// prepare request
			req = new ReqWzsk(ReqWzsk::VecVBasetype::DPCHRET);

			req->jref = inv->jref;
			req->dpchinv = inv;

			// perform op

			if (req->dpchret) {
				req->dpchret->oref = req->dpchinv->oref;
				req->dpchret->jref = req->dpchinv->jref;

				xchg->addReq(req);

			} else {
				delete req;
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

void WzskcmbdOpprc::cleanup(
			void* arg
		) {
	XchgWzskcmbd* xchg = (XchgWzskcmbd*) arg;

	xchg->cOpprcs.unlockMutex("WzskcmbdOpprc", "cleanup");
};

