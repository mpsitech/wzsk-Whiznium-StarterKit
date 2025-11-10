/**
	* \file PnlWzskVtrMonitor.cpp
	* job handler for job PnlWzskVtrMonitor (implementation)
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

#include "PnlWzskVtrMonitor.h"

#include "PnlWzskVtrMonitor_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskVtrMonitor
 ******************************************************************************/

PnlWzskVtrMonitor::PnlWzskVtrMonitor(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKVTRMONITOR, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	actvistorot = NULL;

	// IP constructor.cust1 --- INSERT

	actvistorot = new JobWzskActVistorot(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

};

PnlWzskVtrMonitor::~PnlWzskVtrMonitor() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskVtrMonitor::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskVtrMonitor::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- RBEGIN
	// IP refresh --- REND

	muteRefresh = false;
};

void PnlWzskVtrMonitor::handleRequest(
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

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKINIT) {
			handleDpchAppWzskInit(dbswzsk, (DpchAppWzskInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKVTRMONITORDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

bool PnlWzskVtrMonitor::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- IBEGIN
cout << "a" << endl;

if (statshr.ixWzskVExpstate == VecWzskVExpstate::REGD) {
cout << "b" << endl;

		vector<float> ts = {-20.000, -19.833, -19.667, -19.500, -19.333, -19.167, -19.000, -18.833, -18.667, -18.500, -18.333, -18.167, -18.000, -17.833, -17.667, -17.500, -17.333, -17.167, -17.000, -16.833, -16.667, -16.500, -16.333, -16.167, -16.000, -15.833, -15.667, -15.500, -15.333, -15.167, -15.000, -14.833, -14.667, -14.500, -14.333, -14.167, -14.000, -13.833, -13.667, -13.500, -13.333, -13.167, -13.000, -12.833, -12.667, -12.500, -12.333, -12.167, -12.000, -11.833, -11.667, -11.500, -11.333, -11.167, -11.000, -10.833, -10.667, -10.500, -10.333, -10.167, -10.000, -9.833, -9.667, -9.500, -9.333, -9.167, -9.000, -8.833, -8.667, -8.500, -8.333, -8.167, -8.000, -7.833, -7.667, -7.500, -7.333, -7.167, -7.000, -6.833, -6.667, -6.500, -6.333, -6.167, -6.000, -5.833, -5.667, -5.500, -5.333, -5.167, -5.000, -4.833, -4.667, -4.500, -4.333, -4.167, -4.000, -3.833, -3.667, -3.500, -3.333, -3.167, -3.000, -2.833, -2.667, -2.500, -2.333, -2.167, -2.000, -1.833, -1.667, -1.500, -1.333, -1.167, -1.000, -0.833, -0.667, -0.500, -0.333, -0.167, 0.000};
		vector<float> phis = {-60.00, -58.50, -57.00, -55.50, -54.00, -52.50, -51.00, -49.50, -48.00, -46.50, -45.00, -43.50, -42.00, -40.50, -39.00, -37.50, -36.00, -34.50, -33.00, -31.67, -30.50, -29.50, -28.67, -28.00, -27.50, -27.17, -27.00, -27.00, -27.00, -27.00, -25.50, -24.00, -22.50, -21.00, -19.50, -18.00, -16.50, -15.00, -13.50, -12.00, -10.50, -9.00, -7.50, -6.00, -4.50, -3.00, -1.50, 0.00, 1.50, 3.00, 4.50, 6.00, 7.50, 9.00, 10.50, 11.94, 13.23, 14.37, 15.38, 16.29, 17.09, 17.80, 18.43, 19.00, 19.50, 19.94, 20.34, 20.69, 21.00, 21.28, 21.53, 21.74, 21.94, 22.11, 22.27, 22.40, 22.53, 22.63, 22.73, 22.82, 22.89, 22.96, 23.02, 23.07, 23.12, 23.16, 23.20, 23.23, 23.26, 23.29, 23.31, 23.33, 23.35, 23.37, 23.38, 23.40, 23.41, 23.42, 23.43, 23.44, 23.44, 23.45, 23.45, 23.46, 23.46, 23.47, 23.47, 23.47, 23.48, 23.48, 23.48, 23.48, 23.49, 23.49, 23.49, 23.49, 23.49, 23.49, 23.49, 23.49, 23.49};
		vector<float> omegas = {9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 8.000, 7.000, 6.000, 5.000, 4.000, 3.000, 2.000, 1.000, 0.000, 0.000, 0.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 9.000, 8.667, 7.704, 6.848, 6.087, 5.411, 4.809, 4.275, 3.800, 3.378, 3.002, 2.669, 2.372, 2.109, 1.874, 1.666, 1.481, 1.316, 1.170, 1.040, 0.925, 0.822, 0.731, 0.649, 0.577, 0.513, 0.456, 0.405, 0.360, 0.320, 0.285, 0.253, 0.225, 0.200, 0.178, 0.158, 0.140, 0.125, 0.111, 0.099, 0.088, 0.078, 0.069, 0.062, 0.055, 0.049, 0.043, 0.038, 0.034, 0.030, 0.027, 0.024, 0.021, 0.019, 0.017, 0.015, 0.013, 0.012, 0.011, 0.009, 0.008, 0.007, 0.007, 0.006, 0.005, 0.005, 0.004, 0.004};

		xchg->submitDpch(new DpchEngLive(jref, ts, phis, -180.0, 180.0, omegas, -9.0, 9.0, {DpchEngLive::ALL}));

cout << "c" << endl;
	};

	// IP handleTest --- IEND
	return retval;
};

void PnlWzskVtrMonitor::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskVtrMonitor::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskVtrMonitor::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};
