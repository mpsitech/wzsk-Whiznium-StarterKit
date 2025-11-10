/**
	* \file PnlWzskLlvSysmon.cpp
	* job handler for job PnlWzskLlvSysmon (implementation)
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

#include "PnlWzskLlvSysmon.h"

#include "PnlWzskLlvSysmon_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskLlvSysmon
 ******************************************************************************/

PnlWzskLlvSysmon::PnlWzskLlvSysmon(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLLVSYSMON, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	srcfpgainfo = NULL;
	srcsysinfo = NULL;

	// IP constructor.cust1 --- INSERT

	srcfpgainfo = new JobWzskSrcFpgainfo(xchg, dbswzsk, jref, ixWzskVLocale);
	srcsysinfo = new JobWzskSrcSysinfo(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, srcfpgainfo->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, srcsysinfo->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- INSERT

};

PnlWzskLlvSysmon::~PnlWzskLlvSysmon() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* PnlWzskLlvSysmon::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &continf, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskLlvSysmon::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	// IP refresh --- RBEGIN

	// continf
	ContInf oldContinf(continf);

	if (srcsysinfo->shrdat.temp.size() > 0) continf.TxtCtp = to_string(srcsysinfo->shrdat.temp[0]);

	continf.TxtDhr = to_string(srcfpgainfo->shrdat.hdrDRd);
	continf.TxtDhw = to_string(srcfpgainfo->shrdat.hdrDWr);
	continf.TxtDrr = to_string(srcfpgainfo->shrdat.rndDRd);
	continf.TxtDrw = to_string(srcfpgainfo->shrdat.rndDWr);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// IP refresh --- REND

	muteRefresh = false;
};

void PnlWzskLlvSysmon::handleRequest(
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

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DPCHAPP) {
		if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKINIT) {
			handleDpchAppWzskInit(dbswzsk, (DpchAppWzskInit*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLLVSYSMONDO) {
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

void PnlWzskLlvSysmon::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLlvSysmon::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButRegularizeClick --- END
};

void PnlWzskLlvSysmon::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLlvSysmon::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == srcfpgainfo->jref)) {
		call->abort = handleCallWzskShrdatChgFromSrcfpgainfo(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == srcsysinfo->jref)) {
		call->abort = handleCallWzskShrdatChgFromSrcsysinfo(dbswzsk, call->argInv.ix, call->argInv.sref);
	};
};

bool PnlWzskLlvSysmon::handleCallWzskShrdatChgFromSrcfpgainfo(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromSrcfpgainfo --- IBEGIN

	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

	// IP handleCallWzskShrdatChgFromSrcfpgainfo --- IEND
	return retval;
};

bool PnlWzskLlvSysmon::handleCallWzskShrdatChgFromSrcsysinfo(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromSrcsysinfo --- IBEGIN
	set<uint> moditems;

	vector<float> ts;

	vector<float> cldtots;
	vector<float> cld1s;
	vector<float> cld2s;
	vector<float> cld3s;
	vector<float> cld4s;

	if (statshr.ixWzskVExpstate == VecWzskVExpstate::REGD) {
		if (srefInv == "temp") {
			// temperature
			refresh(dbswzsk, moditems);
			if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));

		} else if (srefInv == "loadAllLoadCore0LoadCore1LoadCore2LoadCore3") {
			// load
			if (srcsysinfo->shrdat.NCore > 0) {
				cldtots = srcsysinfo->shrdat.loadAll;
				for (unsigned int i = 0; i < cldtots.size(); i++) cldtots[i] *= 100.0;
				add(moditems, DpchEngLive::CLDTOTS);

				cld1s = srcsysinfo->shrdat.loadCore0;
				for (unsigned int i = 0; i < cld1s.size(); i++) cld1s[i] *= 100.0;
				add(moditems, DpchEngLive::CLD1S);

				if (srcsysinfo->shrdat.NCore > 1) {
					cld2s = srcsysinfo->shrdat.loadCore1;
					for (unsigned int i = 0; i < cld2s.size(); i++) cld2s[i] *= 100.0;
					add(moditems, DpchEngLive::CLD2S);

					if (srcsysinfo->shrdat.NCore > 2) {
						cld3s = srcsysinfo->shrdat.loadCore2;
						for (unsigned int i = 0; i < cld3s.size(); i++) cld3s[i] *= 100.0;
						add(moditems, DpchEngLive::CLD3S);

						if (srcsysinfo->shrdat.NCore > 3) {
							cld4s = srcsysinfo->shrdat.loadCore3;
							for (unsigned int i = 0; i < cld4s.size(); i++) cld4s[i] *= 100.0;
							add(moditems, DpchEngLive::CLD4S);
						};
					};
				};
			};

			if (!moditems.empty()) {
				add(moditems, DpchEngLive::JREF);

				ts.resize(srcsysinfo->shrdat.loadAll.size());
				for (int i = 0; i < ts.size(); i++) ts[i] = -i;

				add(moditems, DpchEngLive::TS);

				xchg->submitDpch(new DpchEngLive(jref, ts, cldtots, cld1s, cld2s, cld3s, cld4s, moditems));
			};
		};
	};
	// IP handleCallWzskShrdatChgFromSrcsysinfo --- IEND
	return retval;
};
