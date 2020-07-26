/**
	* \file DlgWzskNavLoaini.cpp
	* job handler for job DlgWzskNavLoaini (implementation)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "DlgWzskNavLoaini.h"

#include "DlgWzskNavLoaini_blks.cpp"
#include "DlgWzskNavLoaini_evals.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class DlgWzskNavLoaini
 ******************************************************************************/

DlgWzskNavLoaini::DlgWzskNavLoaini(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::DLGWZSKNAVLOAINI, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFMcbAlert.tag = "FeedFMcbAlert";
	feedFDse.tag = "FeedFDse";
	VecVDit::fillFeed(ixWzskVLocale, feedFDse);
	feedFSge.tag = "FeedFSge";
	VecVSge::fillFeed(feedFSge);

	iex = NULL;

	// IP constructor.cust1 --- INSERT

	ixVDit = VecVDit::IFI;

	iex = new JobWzskIexIni(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	// IP constructor.cust3 --- INSERT

	// IP constructor.spec3 --- INSERT
};

DlgWzskNavLoaini::~DlgWzskNavLoaini() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- INSERT

DpchEngWzsk* DlgWzskNavLoaini::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &continfimp, &continflfi, &feedFDse, &feedFSge, &statshr, &statshrifi, &statshrimp, &statshrlfi, items);
	};

	return dpcheng;
};

void DlgWzskNavLoaini::refreshIfi(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShrIfi oldStatshrifi(statshrifi);

	// IP refreshIfi --- BEGIN
	// statshrifi
	statshrifi.UldActive = evalIfiUldActive(dbswzsk);

	// IP refreshIfi --- END
	if (statshrifi.diff(&oldStatshrifi).size() != 0) insert(moditems, DpchEngData::STATSHRIFI);
};

void DlgWzskNavLoaini::refreshImp(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShrImp oldStatshrimp(statshrimp);
	ContInfImp oldContinfimp(continfimp);

	// IP refreshImp --- RBEGIN
	// continfimp
	continfimp.TxtPrg = getSquawk(dbswzsk);

	// statshrimp
	statshrimp.ButRunActive = evalImpButRunActive(dbswzsk);
	statshrimp.ButStoActive = evalImpButStoActive(dbswzsk);

	// IP refreshImp --- REND
	if (statshrimp.diff(&oldStatshrimp).size() != 0) insert(moditems, DpchEngData::STATSHRIMP);
	if (continfimp.diff(&oldContinfimp).size() != 0) insert(moditems, DpchEngData::CONTINFIMP);
};

void DlgWzskNavLoaini::refreshLfi(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShrLfi oldStatshrlfi(statshrlfi);
	ContInfLfi oldContinflfi(continflfi);

	// IP refreshLfi --- RBEGIN
	// statshrlfi
	statshrlfi.DldActive = evalLfiDldActive(dbswzsk);

	// continflfi
	continflfi.Dld = "log.txt";

	// IP refreshLfi --- REND
	if (statshrlfi.diff(&oldStatshrlfi).size() != 0) insert(moditems, DpchEngData::STATSHRLFI);
	if (continflfi.diff(&oldContinflfi).size() != 0) insert(moditems, DpchEngData::CONTINFLFI);
};

void DlgWzskNavLoaini::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
		) {
	StatShr oldStatshr(statshr);
	ContIac oldContiac(contiac);
	ContInf oldContinf(continf);

	// IP refresh --- BEGIN
	// statshr
	statshr.ButDneActive = evalButDneActive(dbswzsk);

	// contiac
	contiac.numFDse = ixVDit;

	// continf
	continf.numFSge = ixVSge;

	// IP refresh --- END
	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);
	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);
	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	refreshIfi(dbswzsk, moditems);
	refreshImp(dbswzsk, moditems);
	refreshLfi(dbswzsk, moditems);
};

void DlgWzskNavLoaini::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKNAVLOAINIDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPDLGWZSKNAVLOAINIDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTDNECLICK) {
					handleDpchAppDoButDneClick(dbswzsk, &(req->dpcheng));
				};

			} else if (dpchappdo->ixVDoImp != 0) {
				if (dpchappdo->ixVDoImp == VecVDoImp::BUTRUNCLICK) {
					handleDpchAppDoImpButRunClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDoImp == VecVDoImp::BUTSTOCLICK) {
					handleDpchAppDoImpButStoClick(dbswzsk, &(req->dpcheng));
				};

			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKALERT) {
			handleDpchAppWzskAlert(dbswzsk, (DpchAppWzskAlert*) (req->dpchapp), &(req->dpcheng));

		};

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::UPLOAD) {
		if (ixVSge == VecVSge::IDLE) handleUploadInSgeIdle(dbswzsk, req->filename);

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::DOWNLOAD) {
		req->filename = handleDownload(dbswzsk);

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if (ixVSge == VecVSge::PRSIDLE) handleTimerInSgePrsidle(dbswzsk, req->sref);
		else if ((req->sref == "mon") && (ixVSge == VecVSge::IMPORT)) handleTimerWithSrefMonInSgeImport(dbswzsk);
		else if (ixVSge == VecVSge::IMPIDLE) handleTimerInSgeImpidle(dbswzsk, req->sref);
	};
};

void DlgWzskNavLoaini::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void DlgWzskNavLoaini::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);

	if (has(diffitems, ContIac::NUMFDSE)) {
		if ((_contiac->numFDse >= VecVDit::IFI) && (_contiac->numFDse <= VecVDit::LFI)) ixVDit = _contiac->numFDse;
		refresh(dbswzsk, moditems);
	};

	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void DlgWzskNavLoaini::handleDpchAppDoButDneClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButDneClick --- IBEGIN
	if (statshr.ButDneActive) {
		*dpcheng = new DpchEngWzskConfirm(true, jref, "");
		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKDLGCLOSE, jref);
	};
	// IP handleDpchAppDoButDneClick --- IEND
};

void DlgWzskNavLoaini::handleDpchAppDoImpButRunClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoImpButRunClick --- BEGIN
	if (statshrimp.ButRunActive) {
		changeStage(dbswzsk, VecVSge::IMPIDLE, dpcheng);
	};
	// IP handleDpchAppDoImpButRunClick --- END
};

void DlgWzskNavLoaini::handleDpchAppDoImpButStoClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoImpButStoClick --- INSERT
};

void DlgWzskNavLoaini::handleDpchAppWzskAlert(
			DbsWzsk* dbswzsk
			, DpchAppWzskAlert* dpchappwzskalert
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppWzskAlert --- IBEGIN
	if (ixVSge == VecVSge::ALRWZSKPER) {
		changeStage(dbswzsk, nextIxVSgeSuccess);
	} else if (ixVSge == VecVSge::ALRWZSKIER) {
		if (dpchappwzskalert->numFMcb == 2) iex->reverse(dbswzsk);
		changeStage(dbswzsk, nextIxVSgeSuccess);
	};
	// IP handleDpchAppWzskAlert --- IEND
};

void DlgWzskNavLoaini::handleUploadInSgeIdle(
			DbsWzsk* dbswzsk
			, const string& filename
		) {
	infilename = filename; // IP handleUploadInSgeIdle --- ILINE
	changeStage(dbswzsk, VecVSge::PRSIDLE);
};

string DlgWzskNavLoaini::handleDownload(
			DbsWzsk* dbswzsk
		) {
	return(""); // IP handleDownload --- LINE
};

void DlgWzskNavLoaini::handleTimerInSgePrsidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void DlgWzskNavLoaini::handleTimerWithSrefMonInSgeImport(
			DbsWzsk* dbswzsk
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 250000, true);
	refreshWithDpchEng(dbswzsk); // IP handleTimerWithSrefMonInSgeImport --- ILINE
};

void DlgWzskNavLoaini::handleTimerInSgeImpidle(
			DbsWzsk* dbswzsk
			, const string& sref
		) {
	changeStage(dbswzsk, nextIxVSgeSuccess);
};

void DlgWzskNavLoaini::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
			, DpchEngWzsk** dpcheng
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::PRSIDLE: leaveSgePrsidle(dbswzsk); break;
				case VecVSge::PARSE: leaveSgeParse(dbswzsk); break;
				case VecVSge::ALRWZSKPER: leaveSgeAlrwzskper(dbswzsk); break;
				case VecVSge::PRSDONE: leaveSgePrsdone(dbswzsk); break;
				case VecVSge::IMPIDLE: leaveSgeImpidle(dbswzsk); break;
				case VecVSge::IMPORT: leaveSgeImport(dbswzsk); break;
				case VecVSge::ALRWZSKIER: leaveSgeAlrwzskier(dbswzsk); break;
				case VecVSge::DONE: leaveSgeDone(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			if (!muteRefresh) refreshWithDpchEng(dbswzsk, dpcheng); // IP changeStage.refresh1 --- LINE
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::PRSIDLE: _ixVSge = enterSgePrsidle(dbswzsk, reenter); break;
			case VecVSge::PARSE: _ixVSge = enterSgeParse(dbswzsk, reenter); break;
			case VecVSge::ALRWZSKPER: _ixVSge = enterSgeAlrwzskper(dbswzsk, reenter); break;
			case VecVSge::PRSDONE: _ixVSge = enterSgePrsdone(dbswzsk, reenter); break;
			case VecVSge::IMPIDLE: _ixVSge = enterSgeImpidle(dbswzsk, reenter); break;
			case VecVSge::IMPORT: _ixVSge = enterSgeImport(dbswzsk, reenter); break;
			case VecVSge::ALRWZSKIER: _ixVSge = enterSgeAlrwzskier(dbswzsk, reenter); break;
			case VecVSge::DONE: _ixVSge = enterSgeDone(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string DlgWzskNavLoaini::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- RBEGIN
	if ( (ixVSge == VecVSge::PARSE) || (ixVSge == VecVSge::ALRWZSKPER) || (ixVSge == VecVSge::PRSDONE) || (ixVSge == VecVSge::IMPORT) || (ixVSge == VecVSge::ALRWZSKIER) ) {
		if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::PARSE) retval = "lese Initialisierungsdaten ein";
			else if (ixVSge == VecVSge::ALRWZSKPER) retval = "Fehler beim Einlesen";
			else if (ixVSge == VecVSge::PRSDONE) retval = "Initialisierungsdaten eingelesen";
			else if (ixVSge == VecVSge::IMPORT) retval = "importiere Initialisierungsdaten (" + to_string(iex->impcnt) + " Datens\\u00e4tze hinzugef\\u00fcgt)";
			else if (ixVSge == VecVSge::ALRWZSKIER) retval = "Fehler beim Importieren";
		} else if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::PARSE) retval = "parsing initialization data";
			else if (ixVSge == VecVSge::ALRWZSKPER) retval = "parse error";
			else if (ixVSge == VecVSge::PRSDONE) retval = "initialization data parsed";
			else if (ixVSge == VecVSge::IMPORT) retval = "importing initialization data (" + to_string(iex->impcnt) + " records added)";
			else if (ixVSge == VecVSge::ALRWZSKIER) retval = "import error";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- REND
	return retval;
};

uint DlgWzskNavLoaini::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void DlgWzskNavLoaini::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint DlgWzskNavLoaini::enterSgePrsidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRSIDLE;
	nextIxVSgeSuccess = VecVSge::PARSE;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgePrsidle --- INSERT

	return retval;
};

void DlgWzskNavLoaini::leaveSgePrsidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrsidle --- INSERT
};

uint DlgWzskNavLoaini::enterSgeParse(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::PRSDONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZSKPER;

	// IP enterSgeParse --- IBEGIN
	ifstream ififile;

	char* buf;
	string s;

	bool ifitxt;
	bool ifixml;

	iex->reset(dbswzsk);

	// check file type
	ififile.open(infilename.c_str(), ifstream::in);

	buf = new char[16];
	ififile.get(buf, 16);
	s = string(buf);

	ifitxt = (s.find("- ") == 0);
	ifixml = (s.find("<?xml") == 0);		

	delete[] buf;
	ififile.close();

	// parse file accordingly
	if (ifitxt) iex->parseFromFile(dbswzsk, infilename, false);
	else if (ifixml) iex->parseFromFile(dbswzsk, infilename, true);

	if (iex->ixVSge != JobWzskIexIni::VecVSge::PRSDONE) {
		if (reqCmd) {
			if (iex->ixVSge == JobWzskIexIni::VecVSge::PRSERR) cout << "\t" << iex->getSquawk(dbswzsk) << endl;
			else cout << "\tneither text-based nor XML file format recognized" << endl;

			retval = VecVSge::IDLE;

		} else {
			retval = nextIxVSgeFailure;
		};
	};
	// IP enterSgeParse --- IEND

	return retval;
};

void DlgWzskNavLoaini::leaveSgeParse(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeParse --- INSERT
};

uint DlgWzskNavLoaini::enterSgeAlrwzskper(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKPER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwzskper --- RBEGIN
	ContInfWzskAlert continf;

	continf.TxtCpt = VecWzskVTag::getTitle(VecWzskVTag::ERROR, ixWzskVLocale);
	continf.TxtCpt = StrMod::cap(continf.TxtCpt);

	if (iex->ixVSge == JobWzskIexIni::VecVSge::PRSERR) continf.TxtMsg1 = iex->getSquawk(dbswzsk);
	else continf.TxtMsg1 = "neither text-based nor XML file format recognized";

	feedFMcbAlert.clear();

	VecWzskVTag::appendToFeed(VecWzskVTag::OK, ixWzskVLocale, feedFMcbAlert);
	feedFMcbAlert.cap();

	xchg->submitDpch(new DpchEngWzskAlert(jref, &continf, &feedFMcbAlert, {DpchEngWzskAlert::ALL}));
	// IP enterSgeAlrwzskper --- REND

	return retval;
};

void DlgWzskNavLoaini::leaveSgeAlrwzskper(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskper --- INSERT
};

uint DlgWzskNavLoaini::enterSgePrsdone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::PRSDONE;

	// IP enterSgePrsdone --- INSERT

	return retval;
};

void DlgWzskNavLoaini::leaveSgePrsdone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgePrsdone --- INSERT
};

uint DlgWzskNavLoaini::enterSgeImpidle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IMPIDLE;
	nextIxVSgeSuccess = VecVSge::IMPORT;

	wrefLast = xchg->addWakeup(jref, "callback", 0);

	// IP enterSgeImpidle --- INSERT

	return retval;
};

void DlgWzskNavLoaini::leaveSgeImpidle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeImpidle --- INSERT
};

uint DlgWzskNavLoaini::enterSgeImport(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval;
	nextIxVSgeSuccess = VecVSge::DONE;
	retval = nextIxVSgeSuccess;
	nextIxVSgeFailure = VecVSge::ALRWZSKIER;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 250000, true);

	// IP enterSgeImport --- IBEGIN

	iex->import(dbswzsk);

	if (iex->ixVSge == JobWzskIexIni::VecVSge::IMPERR) retval = nextIxVSgeFailure;

	// IP enterSgeImport --- IEND

	return retval;
};

void DlgWzskNavLoaini::leaveSgeImport(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups();
	// IP leaveSgeImport --- INSERT
};

uint DlgWzskNavLoaini::enterSgeAlrwzskier(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::ALRWZSKIER;
	nextIxVSgeSuccess = VecVSge::IDLE;

	// IP enterSgeAlrwzskier --- RBEGIN

	if (reqCmd) {
		cout << "\t" << iex->getSquawk(dbswzsk) << endl;
		retval = nextIxVSgeSuccess;
	} else {
		xchg->submitDpch(AlrWzsk::prepareAlrIer(jref, ixWzskVLocale, iex->getSquawk(dbswzsk), feedFMcbAlert));
	};

	// IP enterSgeAlrwzskier --- REND

	return retval;
};

void DlgWzskNavLoaini::leaveSgeAlrwzskier(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeAlrwzskier --- INSERT
};

uint DlgWzskNavLoaini::enterSgeDone(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::DONE;

	// IP enterSgeDone --- INSERT

	return retval;
};

void DlgWzskNavLoaini::leaveSgeDone(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeDone --- INSERT
};



