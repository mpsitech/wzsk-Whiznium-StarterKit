/**
	* \file PnlWzskLiv2DView.cpp
	* job handler for job PnlWzskLiv2DView (implementation)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "PnlWzskLiv2DView.h"

#include "PnlWzskLiv2DView_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

/******************************************************************************
 class PnlWzskLiv2DView
 ******************************************************************************/

PnlWzskLiv2DView::PnlWzskLiv2DView(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			JobWzsk(xchg, VecWzskVJob::PNLWZSKLIV2DVIEW, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	feedFPupPvm.tag = "FeedFPupPvm";
	VecWzskVPvwmode::fillFeed(ixWzskVLocale, feedFPupPvm);

	iprtrace = NULL;
	iprcorner = NULL;
	actservo = NULL;
	actlaser = NULL;
	actexposure = NULL;
	acqpreview = NULL;

	// IP constructor.cust1 --- IBEGIN
	if (xchg->stgwzskglobal.fpgaNotV4l2gpio) feedFPupPvm[VecWzskVPvwmode::BINREDDOM]->Avail = false;

	initdoneAlign = false;

	snapshotArmed = false;
	// IP constructor.cust1 --- IEND

	iprtrace = new JobWzskIprTrace(xchg, dbswzsk, jref, ixWzskVLocale);
	iprcorner = new JobWzskIprCorner(xchg, dbswzsk, jref, ixWzskVLocale);
	actservo = new JobWzskActServo(xchg, dbswzsk, jref, ixWzskVLocale);
	actlaser = new JobWzskActLaser(xchg, dbswzsk, jref, ixWzskVLocale);
	actexposure = new JobWzskActExposure(xchg, dbswzsk, jref, ixWzskVLocale);
	acqpreview = new JobWzskAcqPreview(xchg, dbswzsk, jref, ixWzskVLocale);

	// IP constructor.cust2 --- INSERT

	set<uint> moditems;
	refresh(dbswzsk, moditems);

	xchg->addClstn(VecWzskVCall::CALLWZSKSTGCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSGECHG, jref, Clstn::VecVJobmask::SPEC, actservo->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, iprcorner->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, iprtrace->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, actlaser->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKRESULTNEW, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::TRY);
	xchg->addClstn(VecWzskVCall::CALLWZSKSHRDATCHG, jref, Clstn::VecVJobmask::SPEC, actexposure->jref, false, Arg(), 0, Clstn::VecVJactype::WEAK);
	xchg->addClstn(VecWzskVCall::CALLWZSKCLAIMCHG, jref, Clstn::VecVJobmask::IMM, 0, false, Arg(), 0, Clstn::VecVJactype::WEAK);

	// IP constructor.cust3 --- IBEGIN
	refreshAlign(moditems);
	// IP constructor.cust3 --- IEND

};

PnlWzskLiv2DView::~PnlWzskLiv2DView() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void PnlWzskLiv2DView::refreshAlign(
			set<uint>& moditems
		) {
	if (muteRefresh) return;
	muteRefresh = true;

	ContIacCorner oldContiaccorner(contiaccorner);

	iprcorner->shrdat.rlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	contiaccorner.roiAx = iprcorner->shrdat.roiAx;
	contiaccorner.roiAy = iprcorner->shrdat.roiAy;
	contiaccorner.roiBx = iprcorner->shrdat.roiBx;
	contiaccorner.roiBy = iprcorner->shrdat.roiBy;
	contiaccorner.roiCx = iprcorner->shrdat.roiCx;
	contiaccorner.roiCy = iprcorner->shrdat.roiCy;
	contiaccorner.roiDx = iprcorner->shrdat.roiDx;
	contiaccorner.roiDy = iprcorner->shrdat.roiDy;

	iprcorner->shrdat.runlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	if (contiaccorner.diff(&oldContiaccorner).size() != 0) insert(moditems, DpchEngAlign::CONTIACCORNER);

	ContIacTrace oldContiactrace(contiactrace);

	iprtrace->shrdat.rlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	contiactrace.roiAx = iprtrace->shrdat.roiAx;
	contiactrace.roiAy = iprtrace->shrdat.roiAy;
	contiactrace.roiBx = iprtrace->shrdat.roiBx;
	contiactrace.roiBy = iprtrace->shrdat.roiBy;
	contiactrace.roiCx = iprtrace->shrdat.roiCx;
	contiactrace.roiCy = iprtrace->shrdat.roiCy;
	contiactrace.roiDx = iprtrace->shrdat.roiDx;
	contiactrace.roiDy = iprtrace->shrdat.roiDy;

	iprtrace->shrdat.runlockAccess("PnlWzskLiv2DView", "refreshAlign", "jref=" + to_string(jref));

	if (contiactrace.diff(&oldContiactrace).size() != 0) insert(moditems, DpchEngAlign::CONTIACTRACE);

	muteRefresh = false;
};

void PnlWzskLiv2DView::takeSnapshot(
			DbsWzsk* dbswzsk
			, const uint ixWzskVPvwmode
			, uint8_t* gr8
			, uint8_t* r8
			, uint8_t* g8
			, uint8_t* b8
		) {
	if (!(gr8 || (r8 && g8 && b8))) return;

	unsigned char* pngbuf = NULL;

	time_t now;
	time(&now);

	unsigned int w, h;

	string pngfile;

	uint refIxVTbl;
	ubigint refUref;

	string Filename;

	Wzsk::getPvwWh(ixWzskVPvwmode, w, h);

	pngbuf = new unsigned char[4 * w * h];
	memset(pngbuf, 0, 4 * w * h);

	if (gr8) {
		for (unsigned int i = 0; i < w*h; i++) {
			pngbuf[4 * i + 1] = gr8[i];
			pngbuf[4 * i + 2] = gr8[i];
			pngbuf[4 * i + 3] = gr8[i];
		};

	} else {
		for (unsigned int i = 0; i < w*h; i++) {
			pngbuf[4 * i + 1] = r8[i]; // red
			pngbuf[4 * i + 2] = g8[i]; // green
			pngbuf[4 * i + 3] = b8[i]; // blue
		};
	};

	refUref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFSHT, jref);
	if (refUref != 0) refIxVTbl = VecWzskVMFileRefTbl::SHT;
	else {
		refIxVTbl = VecWzskVMFileRefTbl::OBJ;
		refUref = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);
	};
	
	if (refUref != 0) {
		pngfile = Tmp::newfile(xchg->tmppath, "png");
		takeSnapshot_writePng(xchg->tmppath + "/" + pngfile, pngbuf, w, h);

		Filename = VecWzskVPvwmode::getSref(ixWzskVPvwmode) + "1.png";
		if (dbswzsk->loadStringBySQL("SELECT Filename FROM TblWzskMFile WHERE refIxVTbl = " + to_string(refIxVTbl) + " AND refUref = " + to_string(refUref) + " AND Filename LIKE '" + VecWzskVPvwmode::getSref(ixWzskVPvwmode) + "%.png' ORDER BY ref DESC LIMIT 1", Filename)) {
			Filename = Filename.substr(0, Filename.rfind(".png"));
			Filename = VecWzskVPvwmode::getSref(ixWzskVPvwmode) + to_string(atoi(Filename.substr(VecWzskVPvwmode::getSref(ixWzskVPvwmode).length()).c_str()) + 1) + ".png";
		};

		Acv::addfile(dbswzsk, xchg->acvpath, xchg->tmppath + "/" + pngfile, xchg->getRefPreset(VecWzskVPreset::PREWZSKGROUP, jref), xchg->getRefPreset(VecWzskVPreset::PREWZSKOWNER, jref), refIxVTbl, refUref, "pvwsnap", Filename, "png", "");
		xchg->triggerCall(dbswzsk, VecWzskVCall::CALLWZSKFILMOD, jref);
		xchg->triggerIxRefCall(dbswzsk, VecWzskVCall::CALLWZSKFILMOD_RETREUEQ, jref, refIxVTbl, refUref);
	};

	delete[] pngbuf;
};

void PnlWzskLiv2DView::takeSnapshot_writePng(
			const string& path
			, unsigned char* imgdat
			, const unsigned int width
			, const unsigned int height
		) {
	string outfile;
	FILE* fp;

	unsigned char** rowptr;

	png_structp png_ptr;
	png_infop info_ptr;

	// create and open file
	fp = fopen(path.c_str(), "wb");

	// set row pointers
	rowptr = new unsigned char*[height];
	for (unsigned int k = 0; k < height; k++) rowptr[k] = &(imgdat[4*width*(height-k-1)]);

	// allocate structures
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	info_ptr = png_create_info_struct(png_ptr);

	// set error handling
	setjmp(png_jmpbuf(png_ptr));

	// set up output control
	png_init_io(png_ptr, fp);

	// set file information
	png_set_IHDR(png_ptr, info_ptr, width, height, 8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	// write file information
	png_write_info(png_ptr, info_ptr);

	// pack RGB into 3 bytes
	png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);

	// write image
	png_write_image(png_ptr, rowptr);

	// write rest of file
	png_write_end(png_ptr, info_ptr);

	// clean up
	png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);

	delete[] rowptr;

	// close file
	fclose(fp);
};
// IP cust --- IEND

DpchEngWzsk* PnlWzskLiv2DView::getNewDpchEng(
			set<uint> items
		) {
	DpchEngWzsk* dpcheng = NULL;

	if (items.empty()) {
		dpcheng = new DpchEngWzskConfirm(true, jref, "");
	} else {
		insert(items, DpchEngData::JREF);
		dpcheng = new DpchEngData(jref, &contiac, &continf, &feedFPupPvm, &statshr, items);
	};

	return dpcheng;
};

void PnlWzskLiv2DView::refresh(
			DbsWzsk* dbswzsk
			, set<uint>& moditems
			, const bool unmute
		) {
	if (muteRefresh && !unmute) return;
	muteRefresh = true;

	StatShr oldStatshr(statshr);

	// IP refresh --- RBEGIN
	bool takenNotAvailable, fulfilled, run;
	bool has2, takenNotAvailable2, fulfilled2, run2;

	xchg->getCsjobClaim(acqpreview, takenNotAvailable, fulfilled, run);

	ubigint refWzskMObject;
	refWzskMObject = xchg->getRefPreset(VecWzskVPreset::PREWZSKREFOBJ, jref);

	// contiac
	ContIac oldContiac(contiac);

	contiac.ChkAex = actexposure->shrdat.autoNotManual;
	contiac.SldExt = 1e3 * actexposure->shrdat.Texp;
	contiac.SldFcs = actexposure->shrdat.focus;

	contiac.UpdLlo = iprtrace->shrdat.levelOn;
	contiac.UpdLuo = iprtrace->shrdat.levelOff;

	contiac.UpdLmd = iprtrace->shrdat.levelOn - iprtrace->shrdat.levelOff;

	contiac.ChkLro = iprtrace->stg.roiNotFull;

	contiac.UpdPnt = iprcorner->shrdat.NTarget;

	contiac.ChkPro = iprcorner->stg.roiNotFull;

	if (contiac.diff(&oldContiac).size() != 0) insert(moditems, DpchEngData::CONTIAC);

	// continf
	ContInf oldContinf(continf);

	continf.ButClaimOn = fulfilled;
	if (dbswzsk) continf.TxtOaf = StubWzsk::getStubObjStd(dbswzsk, refWzskMObject, ixWzskVLocale);

	continf.ButTccOn = ((actservo->shrdat.target == -360.0) && (actservo->ixVSge == JobWzskActServo::VecVSge::MOVE));
	continf.ButTcwOn = ((actservo->shrdat.target == 360.0) && (actservo->ixVSge == JobWzskActServo::VecVSge::MOVE));

	continf.ButLleOn = (actlaser->shrdat.left != 0.0);
	continf.ButLriOn = (actlaser->shrdat.right != 0.0);

	has2 = xchg->getCsjobClaim(iprtrace, takenNotAvailable2, fulfilled2, run2);
	continf.ButLtrOn = run2;
	if (has2 && !fulfilled2) xchg->removeCsjobClaim(dbswzsk, iprtrace);

	has2 = xchg->getCsjobClaim(iprcorner, takenNotAvailable2, fulfilled2, run2);
	continf.ButPicOn = run2;
	if (has2 && !fulfilled2) xchg->removeCsjobClaim(dbswzsk, iprcorner);

	if (continf.diff(&oldContinf).size() != 0) insert(moditems, DpchEngData::CONTINF);

	// statshr
	statshr.ButClaimActive = !takenNotAvailable || fulfilled;

	statshr.ButPlayActive = fulfilled && !run;
	statshr.ButStopActive = fulfilled && run;

	statshr.ChkAexActive = fulfilled;

	statshr.SldExtAvail = !contiac.ChkAex;
	statshr.SldExtActive = fulfilled;

	statshr.SldFcsActive = fulfilled;

	statshr.TxtOafAvail = (refWzskMObject != 0);
	statshr.ButStsActive = (refWzskMObject != 0) && run;

	statshr.UpdLloAvail = xchg->stgwzskglobal.fpgaNotV4l2gpio || iprtrace->stg.v4l2RdNotDelta;
	statshr.UpdLuoAvail = xchg->stgwzskglobal.fpgaNotV4l2gpio || iprtrace->stg.v4l2RdNotDelta;

	statshr.UpdLmdAvail = !xchg->stgwzskglobal.fpgaNotV4l2gpio && !iprtrace->stg.v4l2RdNotDelta;
	// IP refresh --- REND

	if (statshr.diff(&oldStatshr).size() != 0) insert(moditems, DpchEngData::STATSHR);

	muteRefresh = false;
};

void PnlWzskLiv2DView::handleRequest(
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

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWALIGN) {
			handleDpchAppAlign(dbswzsk, (DpchAppAlign*) (req->dpchapp), &(req->dpcheng));

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDATA) {
			DpchAppData* dpchappdata = (DpchAppData*) (req->dpchapp);

			if (dpchappdata->has(DpchAppData::CONTIAC)) {
				handleDpchAppDataContiac(dbswzsk, &(dpchappdata->contiac), &(req->dpcheng));
			};

		} else if (req->dpchapp->ixWzskVDpch == VecWzskVDpch::DPCHAPPWZSKLIV2DVIEWDO) {
			DpchAppDo* dpchappdo = (DpchAppDo*) (req->dpchapp);

			if (dpchappdo->ixVDo != 0) {
				if (dpchappdo->ixVDo == VecVDo::BUTREGULARIZECLICK) {
					handleDpchAppDoButRegularizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTMINIMIZECLICK) {
					handleDpchAppDoButMinimizeClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTCLAIMCLICK) {
					handleDpchAppDoButClaimClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPLAYCLICK) {
					handleDpchAppDoButPlayClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTOPCLICK) {
					handleDpchAppDoButStopClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTSTSCLICK) {
					handleDpchAppDoButStsClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCCCLICK) {
					handleDpchAppDoButTccClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTTCWCLICK) {
					handleDpchAppDoButTcwClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLLECLICK) {
					handleDpchAppDoButLleClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLRICLICK) {
					handleDpchAppDoButLriClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTLTRCLICK) {
					handleDpchAppDoButLtrClick(dbswzsk, &(req->dpcheng));
				} else if (dpchappdo->ixVDo == VecVDo::BUTPICCLICK) {
					handleDpchAppDoButPicClick(dbswzsk, &(req->dpcheng));
				};

			};

		};
	};
};

void PnlWzskLiv2DView::handleDpchAppWzskInit(
			DbsWzsk* dbswzsk
			, DpchAppWzskInit* dpchappwzskinit
			, DpchEngWzsk** dpcheng
		) {
	*dpcheng = getNewDpchEng({DpchEngData::ALL});
};

void PnlWzskLiv2DView::handleDpchAppAlign(
			DbsWzsk* dbswzsk
			, DpchAppAlign* dpchappalign
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppAlign --- IBEGIN
	set<uint> diffitems;
	set<uint> moditems;

	muteRefresh = true;

	if (dpchappalign->has(DpchAppAlign::CONTIACCORNER)) {
		ContIacCorner& c = dpchappalign->contiaccorner;

		diffitems = c.diff(&contiaccorner);

		if (!diffitems.empty()) iprcorner->setRoi(dbswzsk, c.roiAx, c.roiAy, c.roiBx, c.roiBy, c.roiCx, c.roiCy, c.roiDx, c.roiDy);

		add(moditems, DpchEngAlign::CONTIACCORNER);
	};

	if (dpchappalign->has(DpchAppAlign::CONTIACTRACE)) {
		ContIacTrace& c = dpchappalign->contiactrace;

		diffitems = c.diff(&contiactrace);

		if (!diffitems.empty()) iprtrace->setRoi(dbswzsk, c.roiAx, c.roiAy, c.roiBx, c.roiBy, c.roiCx, c.roiCy, c.roiDx, c.roiDy);

		add(moditems, DpchEngAlign::CONTIACTRACE);
	};

	muteRefresh = false;
	if (hasAny(dpchappalign->mask, {DpchAppAlign::CONTIACCORNER,DpchAppAlign::CONTIACTRACE})) refreshAlign(moditems);
	else {
		// initialization
		add(moditems, DpchAppAlign::CONTIACCORNER);
		add(moditems, DpchAppAlign::CONTIACTRACE);
	};

	add(moditems, DpchAppAlign::JREF);
	*dpcheng = new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems);
	// IP handleDpchAppAlign --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDataContiac(
			DbsWzsk* dbswzsk
			, ContIac* _contiac
			, DpchEngWzsk** dpcheng
		) {
	set<uint> diffitems;
	set<uint> moditems;

	diffitems = _contiac->diff(&contiac);
	// IP handleDpchAppDataContiac --- IBEGIN

	muteRefresh = true;

	if (has(diffitems, ContIac::NUMFPUPPVM)) {
		if (feedFPupPvm.getIxByNum(_contiac->numFPupPvm) != 0) contiac.numFPupPvm = _contiac->numFPupPvm;
		else contiac.numFPupPvm = 1;

		if (statshr.ButStopActive) {
			// allow live mode changes
			xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, true, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));
		};
	};

	if (hasAny(diffitems, {ContIac::CHKAEX,ContIac::SLDEXT}) && statshr.ChkAexActive) actexposure->setExposure(dbswzsk, _contiac->ChkAex, 1e-3 * _contiac->SldExt);

	if (has(diffitems, ContIac::SLDFCS) && statshr.SldFcsActive) actexposure->setFocus(dbswzsk, _contiac->SldFcs);

	if (has(diffitems, ContIac::UPDLLO)) iprtrace->setLevel(dbswzsk, _contiac->UpdLlo, iprtrace->shrdat.levelOff);
	if (has(diffitems, ContIac::UPDLUO)) iprtrace->setLevel(dbswzsk, iprtrace->shrdat.levelOn, _contiac->UpdLuo);

	if (has(diffitems, ContIac::UPDLMD)) iprtrace->setLevel(dbswzsk, 255, 255 - _contiac->UpdLmd);

	if (has(diffitems, ContIac::CHKLRO)) iprtrace->setRoiNotFull(dbswzsk, _contiac->ChkLro);

	if (has(diffitems, ContIac::UPDPNT)) iprcorner->setNTarget(dbswzsk, _contiac->UpdPnt);

	if (has(diffitems, ContIac::CHKPRO)) iprcorner->setRoiNotFull(dbswzsk, _contiac->ChkPro);

	refresh(dbswzsk, moditems, true);

	// IP handleDpchAppDataContiac --- IEND
	insert(moditems, DpchEngData::CONTIAC);
	*dpcheng = getNewDpchEng(moditems);
};

void PnlWzskLiv2DView::handleDpchAppDoButRegularizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButRegularizeClick --- RBEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::REGD;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});

	if (!initdoneAlign) {
		xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, {DpchEngAlign::ALL}));
		initdoneAlign = true;
	};
	// IP handleDpchAppDoButRegularizeClick --- REND
};

void PnlWzskLiv2DView::handleDpchAppDoButMinimizeClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButMinimizeClick --- BEGIN
	statshr.ixWzskVExpstate = VecWzskVExpstate::MIND;
	*dpcheng = getNewDpchEng({DpchEngData::STATSHR});
	// IP handleDpchAppDoButMinimizeClick --- END
};

void PnlWzskLiv2DView::handleDpchAppDoButClaimClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButClaimClick --- IBEGIN
	if (statshr.ButClaimActive) {
		muteRefresh = true;

		if (!continf.ButClaimOn) xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));
		else xchg->removeCsjobClaim(dbswzsk, acqpreview);

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButClaimClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButPlayClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPlayClick --- IBEGIN
	if (statshr.ButPlayActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, true, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButPlayClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButStopClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButStopClick --- IBEGIN
	if (statshr.ButStopActive) {
		muteRefresh = true;

		xchg->addCsjobClaim(dbswzsk, acqpreview, new JobWzskAcqPreview::Claim(true, false, feedFPupPvm.getIxByNum(contiac.numFPupPvm)));

		refreshWithDpchEng(dbswzsk, dpcheng, true);
	};
	// IP handleDpchAppDoButStopClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButStsClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	if (statshr.ButStsActive) snapshotArmed = true; // IP handleDpchAppDoButStsClick --- ILINE
};

void PnlWzskLiv2DView::handleDpchAppDoButTccClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButTccClick --- IBEGIN
	bool takenNotAvailable, fulfilled;

	muteRefresh = true;

	// try ad-hoc claim
	xchg->addCsjobClaim(dbswzsk, actservo, new Claim(true));
	xchg->getCsjobClaim(actservo, takenNotAvailable, fulfilled);

	if (fulfilled) {
		if (!continf.ButTccOn) actservo->turn(dbswzsk, true);
		else actservo->stop(dbswzsk);
	};

	xchg->removeCsjobClaim(dbswzsk, actservo);

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButTccClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButTcwClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButTcwClick --- IBEGIN
	bool takenNotAvailable, fulfilled;

	muteRefresh = true;

	// try ad-hoc claim
	xchg->addCsjobClaim(dbswzsk, actservo, new Claim(true));
	xchg->getCsjobClaim(actservo, takenNotAvailable, fulfilled);

	if (fulfilled) {
		if (!continf.ButTcwOn) actservo->turn(dbswzsk, false);
		else actservo->stop(dbswzsk);
	};
	
	xchg->removeCsjobClaim(dbswzsk, actservo);

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButTcwClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButLleClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButLleClick --- IBEGIN
	bool takenNotAvailable, fulfilled;

	muteRefresh = true;

	// try ad-hoc claim
	xchg->addCsjobClaim(dbswzsk, actlaser, new Claim(true));
	xchg->getCsjobClaim(actlaser, takenNotAvailable, fulfilled);

	if (fulfilled) {
		if (!continf.ButLleOn) actlaser->setLeft(dbswzsk, 1.0);
		else actlaser->setLeft(dbswzsk, 0.0);
	};
	
	xchg->removeCsjobClaim(dbswzsk, actlaser);

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButLleClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButLriClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButLriClick --- IBEGIN
	bool takenNotAvailable, fulfilled;

	muteRefresh = true;

	// try ad-hoc claim
	xchg->addCsjobClaim(dbswzsk, actlaser, new Claim(true));
	xchg->getCsjobClaim(actlaser, takenNotAvailable, fulfilled);

	if (fulfilled) {
		if (!continf.ButLriOn) actlaser->setRight(dbswzsk, 1.0);
		else actlaser->setRight(dbswzsk, 0.0);
	};

	xchg->removeCsjobClaim(dbswzsk, actlaser);

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButLriClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButLtrClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButLtrClick --- IBEGIN
	muteRefresh = true;

	// try ad-hoc claim
	if (!continf.ButLtrOn) xchg->addCsjobClaim(dbswzsk, iprtrace, new JobWzskIprTrace::Claim(true, true, true));
	else xchg->removeCsjobClaim(dbswzsk, iprtrace);

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButLtrClick --- IEND
};

void PnlWzskLiv2DView::handleDpchAppDoButPicClick(
			DbsWzsk* dbswzsk
			, DpchEngWzsk** dpcheng
		) {
	// IP handleDpchAppDoButPicClick --- IBEGIN
	muteRefresh = true;

	// try ad-hoc claim
	if (!continf.ButPicOn) xchg->addCsjobClaim(dbswzsk, iprcorner, new JobWzskIprCorner::Claim(true, true, true));
	else xchg->removeCsjobClaim(dbswzsk, iprcorner);

	refreshWithDpchEng(dbswzsk, dpcheng, true);
	// IP handleDpchAppDoButPicClick --- IEND
};

void PnlWzskLiv2DView::handleCall(
			DbsWzsk* dbswzsk
			, Call* call
		) {
	if (call->ixVCall == VecWzskVCall::CALLWZSKSTGCHG) {
		call->abort = handleCallWzskStgChg(dbswzsk, call->jref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSGECHG) && (call->jref == actservo->jref)) {
		call->abort = handleCallWzskSgeChgFromActservo(dbswzsk);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == iprcorner->jref)) {
		call->abort = handleCallWzskShrdatChgFromIprcorner(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == iprtrace->jref)) {
		call->abort = handleCallWzskShrdatChgFromIprtrace(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == actlaser->jref)) {
		call->abort = handleCallWzskShrdatChgFromActlaser(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKRESULTNEW) {
		call->abort = handleCallWzskResultNew(dbswzsk, call->jref, call->argInv.ix, call->argInv.sref);
	} else if ((call->ixVCall == VecWzskVCall::CALLWZSKSHRDATCHG) && (call->jref == actexposure->jref)) {
		call->abort = handleCallWzskShrdatChgFromActexposure(dbswzsk, call->argInv.ix, call->argInv.sref);
	} else if (call->ixVCall == VecWzskVCall::CALLWZSKCLAIMCHG) {
		call->abort = handleCallWzskClaimChg(dbswzsk, call->jref);
	};
};

bool PnlWzskLiv2DView::handleCallWzskStgChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskStgChg --- IBEGIN
	set<uint> moditems;

	refreshAlign(moditems);

	if (!moditems.empty()) {
		add(moditems, DpchEngAlign::JREF);
		xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems));
	};
	// IP handleCallWzskStgChg --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskSgeChgFromActservo(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleCallWzskSgeChgFromActservo --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskSgeChgFromActservo --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskShrdatChgFromIprcorner(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromIprcorner --- IBEGIN
	set<uint> moditems;

	refreshAlign(moditems);

	if (!moditems.empty()) {
		add(moditems, DpchEngAlign::JREF);
		xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems));
	};
	// IP handleCallWzskShrdatChgFromIprcorner --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskShrdatChgFromIprtrace(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromIprtrace --- IBEGIN
	set<uint> moditems;

	refreshAlign(moditems);

	if (!moditems.empty()) {
		add(moditems, DpchEngAlign::JREF);
		xchg->submitDpch(new DpchEngAlign(jref, &contiaccorner, &contiactrace, moditems));
	};
	// IP handleCallWzskShrdatChgFromIprtrace --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskShrdatChgFromActlaser(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromActlaser --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskShrdatChgFromActlaser --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskResultNew(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskResultNew --- IBEGIN
	set<uint> mask;

	bool takenNotAvailable, fulfilled, run;

	uint ixWzskVPvwmode;

	JobWzskAcqPreview::Shrdat::ResultitemGray* riGray = NULL;
	JobWzskAcqPreview::Shrdat::ResultitemRgb* riRgb = NULL;

	JobWzskIprTrace::Shrdat::ResultitemTrace* riTrace = NULL;

	JobWzskIprCorner::Shrdat::ResultitemCorner* riCorner = NULL;

	vector<utinyint> gray;

	vector<utinyint> red;
	vector<utinyint> green;
	vector<utinyint> blue;

	vector<int> xTraceL;
	vector<int> yTraceL;

	vector<int> xTraceR;
	vector<int> yTraceR;

	vector<int> xCorner;
	vector<int> yCorner;

	if (jrefTrig == acqpreview->jref) {
		xchg->getCsjobClaim(acqpreview, takenNotAvailable, fulfilled, run);

		ixWzskVPvwmode = VecWzskVPvwmode::getIx(srefInv);

		if ((ixWzskVPvwmode == feedFPupPvm.getIxByNum(contiac.numFPupPvm)) && run) {
			if (ixWzskVPvwmode == VecWzskVPvwmode::BINGRAY) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultBingray[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::BINREDDOM) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultBinreddom[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::BINRGB) riRgb = (JobWzskAcqPreview::Shrdat::ResultitemRgb*) acqpreview->shrdat.resultBinrgb[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::RAWGRAY) riGray = (JobWzskAcqPreview::Shrdat::ResultitemGray*) acqpreview->shrdat.resultRawgray[ixInv];
			else if (ixWzskVPvwmode == VecWzskVPvwmode::RAWRGB) riRgb = (JobWzskAcqPreview::Shrdat::ResultitemRgb*) acqpreview->shrdat.resultRawrgb[ixInv];

			if (riGray) {
				gray.resize(riGray->sizeBuf);
				
				memcpy(gray.data(), riGray->gr8, riGray->sizeBuf);

				insert(mask, DpchEngLive::GRAY);

				if (snapshotArmed) {
					takeSnapshot(dbswzsk, ixWzskVPvwmode, riGray->gr8, NULL, NULL, NULL);
					snapshotArmed = false;
				};

			} else if (riRgb) {
				red.resize(riRgb->sizeBuf);
				green.resize(riRgb->sizeBuf);
				blue.resize(riRgb->sizeBuf);

				memcpy(red.data(), riRgb->r8, riRgb->sizeBuf);
				memcpy(green.data(), riRgb->g8, riRgb->sizeBuf);
				memcpy(blue.data(), riRgb->b8, riRgb->sizeBuf);

				insert(mask, DpchEngLive::RED);
				insert(mask, DpchEngLive::GREEN);
				insert(mask, DpchEngLive::BLUE);

				if (snapshotArmed) {
					takeSnapshot(dbswzsk, ixWzskVPvwmode, NULL, riRgb->r8, riRgb->g8, riRgb->b8);
					snapshotArmed = false;
				};
			};
		};

	} else if (jrefTrig == iprtrace->jref) {
		xchg->getCsjobClaim(iprtrace, takenNotAvailable, fulfilled, run);

		//if (run) {
			riTrace = (JobWzskIprTrace::Shrdat::ResultitemTrace*) iprtrace->shrdat.result[ixInv];

			if (riTrace->Nleft > 0) {
				xTraceL.resize(riTrace->Nleft);
				yTraceL.resize(riTrace->Nleft);

				memcpy(xTraceL.data(), riTrace->x.data(), riTrace->Nleft * sizeof(int));
				memcpy(yTraceL.data(), riTrace->y.data(), riTrace->Nleft * sizeof(int));

				insert(mask, DpchEngLive::XTRACEL);
				insert(mask, DpchEngLive::YTRACEL);
			};

			if (riTrace->Nright > 0) {
				xTraceR.resize(riTrace->Nright);
				yTraceR.resize(riTrace->Nright);

				memcpy(xTraceR.data(), &(riTrace->x.data()[riTrace->Nleft]), riTrace->Nright * sizeof(int));
				memcpy(yTraceR.data(), &(riTrace->y.data()[riTrace->Nleft]), riTrace->Nright * sizeof(int));

				insert(mask, DpchEngLive::XTRACER);
				insert(mask, DpchEngLive::YTRACER);
			};
		//};

	} else if (jrefTrig == iprcorner->jref) {
		xchg->getCsjobClaim(iprcorner, takenNotAvailable, fulfilled, run);

		//if (run) {
			riCorner = (JobWzskIprCorner::Shrdat::ResultitemCorner*) iprcorner->shrdat.result[ixInv];

			xCorner = riCorner->x;
			yCorner = riCorner->y;

			insert(mask, DpchEngLive::XCORNER);
			insert(mask, DpchEngLive::YCORNER);
		//};
	};

	if (!mask.empty()) {
		insert(mask, DpchEngLive::JREF);
		xchg->submitDpch(new DpchEngLive(jref, gray, red, green, blue, xCorner, yCorner, xTraceL, yTraceL, xTraceR, yTraceR, mask));
	};
	// IP handleCallWzskResultNew --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskShrdatChgFromActexposure(
			DbsWzsk* dbswzsk
			, const uint ixInv
			, const string& srefInv
		) {
	bool retval = false;
	// IP handleCallWzskShrdatChgFromActexposure --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskShrdatChgFromActexposure --- IEND
	return retval;
};

bool PnlWzskLiv2DView::handleCallWzskClaimChg(
			DbsWzsk* dbswzsk
			, const ubigint jrefTrig
		) {
	bool retval = false;
	// IP handleCallWzskClaimChg --- IBEGIN
	set<uint> moditems;

	refresh(dbswzsk, moditems);
	if (!moditems.empty()) xchg->submitDpch(getNewDpchEng(moditems));
	// IP handleCallWzskClaimChg --- IEND
	return retval;
};



