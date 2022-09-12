/**
	* \file PnlWzskLiv2DView.h
	* job handler for job PnlWzskLiv2DView (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLIV2DVIEW_H
#define PNLWZSKLIV2DVIEW_H

// IP include.spec --- INSERT

// IP include.cust --- IBEGIN
#include <png.h>
// IP include.cust --- IEND

#include "JobWzskIprTrace.h"
#include "JobWzskIprCorner.h"
#include "JobWzskActServo.h"
#include "JobWzskActLaser.h"
#include "JobWzskActExposure.h"
#include "JobWzskAcqPtcloud.h"
#include "JobWzskAcqPreview.h"

#define VecVWzskLiv2DViewDo PnlWzskLiv2DView::VecVDo

#define ContIacWzskLiv2DView PnlWzskLiv2DView::ContIac
#define ContIacWzskLiv2DViewCorner PnlWzskLiv2DView::ContIacCorner
#define ContIacWzskLiv2DViewTrace PnlWzskLiv2DView::ContIacTrace
#define ContInfWzskLiv2DView PnlWzskLiv2DView::ContInf
#define StatShrWzskLiv2DView PnlWzskLiv2DView::StatShr
#define TagWzskLiv2DView PnlWzskLiv2DView::Tag

#define DpchAppWzskLiv2DViewAlign PnlWzskLiv2DView::DpchAppAlign
#define DpchAppWzskLiv2DViewData PnlWzskLiv2DView::DpchAppData
#define DpchAppWzskLiv2DViewDo PnlWzskLiv2DView::DpchAppDo
#define DpchEngWzskLiv2DViewAlign PnlWzskLiv2DView::DpchEngAlign
#define DpchEngWzskLiv2DViewData PnlWzskLiv2DView::DpchEngData
#define DpchEngWzskLiv2DViewLive PnlWzskLiv2DView::DpchEngLive

/**
	* PnlWzskLiv2DView
	*/
class PnlWzskLiv2DView : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskLiv2DViewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTPLAYCLICK = 4;
		static const Sbecore::uint BUTSTOPCLICK = 5;
		static const Sbecore::uint BUTSTSCLICK = 6;
		static const Sbecore::uint BUTTCCCLICK = 7;
		static const Sbecore::uint BUTTCWCLICK = 8;
		static const Sbecore::uint BUTLLECLICK = 9;
		static const Sbecore::uint BUTLRICLICK = 10;
		static const Sbecore::uint BUTLTRCLICK = 11;
		static const Sbecore::uint BUTPICCLICK = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLiv2DView)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFPUPPVM = 1;
		static const Sbecore::uint CHKAEX = 2;
		static const Sbecore::uint SLDEXT = 3;
		static const Sbecore::uint SLDFCS = 4;
		static const Sbecore::uint UPDLLO = 5;
		static const Sbecore::uint UPDLUO = 6;
		static const Sbecore::uint UPDLMD = 7;
		static const Sbecore::uint CHKLRO = 8;
		static const Sbecore::uint UPDPNT = 9;
		static const Sbecore::uint CHKPRO = 10;
		static const Sbecore::uint SLDCWD = 11;

	public:
		ContIac(const Sbecore::uint numFPupPvm = 1, const bool ChkAex = false, const double SldExt = 0.0, const double SldFcs = 0.0, const int UpdLlo = 0, const int UpdLuo = 0, const int UpdLmd = 0, const bool ChkLro = false, const int UpdPnt = 0, const bool ChkPro = false, const double SldCwd = 0.0);

	public:
		Sbecore::uint numFPupPvm;
		bool ChkAex;
		double SldExt;
		double SldFcs;
		int UpdLlo;
		int UpdLuo;
		int UpdLmd;
		bool ChkLro;
		int UpdPnt;
		bool ChkPro;
		double SldCwd;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacCorner (full: ContIacWzskLiv2DViewCorner)
	  */
	class ContIacCorner : public Sbecore::Block {

	public:
		static const Sbecore::uint ROIAX = 1;
		static const Sbecore::uint ROIAY = 2;
		static const Sbecore::uint ROIBX = 3;
		static const Sbecore::uint ROIBY = 4;
		static const Sbecore::uint ROICX = 5;
		static const Sbecore::uint ROICY = 6;
		static const Sbecore::uint ROIDX = 7;
		static const Sbecore::uint ROIDY = 8;

	public:
		ContIacCorner(const int roiAx = 0, const int roiAy = -200, const int roiBx = 300, const int roiBy = 0, const int roiCx = 0, const int roiCy = 200, const int roiDx = -300, const int roiDy = 0);

	public:
		int roiAx;
		int roiAy;
		int roiBx;
		int roiBy;
		int roiCx;
		int roiCy;
		int roiDx;
		int roiDy;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacCorner* comp);
		std::set<Sbecore::uint> diff(const ContIacCorner* comp);
	};

	/**
	  * ContIacTrace (full: ContIacWzskLiv2DViewTrace)
	  */
	class ContIacTrace : public Sbecore::Block {

	public:
		static const Sbecore::uint ROIAX = 1;
		static const Sbecore::uint ROIAY = 2;
		static const Sbecore::uint ROIBX = 3;
		static const Sbecore::uint ROIBY = 4;
		static const Sbecore::uint ROICX = 5;
		static const Sbecore::uint ROICY = 6;
		static const Sbecore::uint ROIDX = 7;
		static const Sbecore::uint ROIDY = 8;

	public:
		ContIacTrace(const int roiAx = -300, const int roiAy = -200, const int roiBx = 300, const int roiBy = -200, const int roiCx = 300, const int roiCy = 400, const int roiDx = -300, const int roiDy = 400);

	public:
		int roiAx;
		int roiAy;
		int roiBx;
		int roiBy;
		int roiCx;
		int roiCy;
		int roiDx;
		int roiDy;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacTrace* comp);
		std::set<Sbecore::uint> diff(const ContIacTrace* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLiv2DView)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTOAF = 2;
		static const Sbecore::uint BUTTCCON = 3;
		static const Sbecore::uint BUTTCWON = 4;
		static const Sbecore::uint BUTLLEON = 5;
		static const Sbecore::uint BUTLRION = 6;
		static const Sbecore::uint BUTLTRON = 7;
		static const Sbecore::uint BUTPICON = 8;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtOaf = "", const bool ButTccOn = false, const bool ButTcwOn = false, const bool ButLleOn = false, const bool ButLriOn = false, const bool ButLtrOn = false, const bool ButPicOn = false);

	public:
		bool ButClaimOn;
		std::string TxtOaf;
		bool ButTccOn;
		bool ButTcwOn;
		bool ButLleOn;
		bool ButLriOn;
		bool ButLtrOn;
		bool ButPicOn;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskLiv2DView)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint BUTPLAYACTIVE = 3;
		static const Sbecore::uint BUTSTOPACTIVE = 4;
		static const Sbecore::uint CHKAEXACTIVE = 5;
		static const Sbecore::uint SLDEXTAVAIL = 6;
		static const Sbecore::uint SLDEXTACTIVE = 7;
		static const Sbecore::uint SLDEXTMIN = 8;
		static const Sbecore::uint SLDEXTMAX = 9;
		static const Sbecore::uint SLDEXTRAST = 10;
		static const Sbecore::uint SLDFCSACTIVE = 11;
		static const Sbecore::uint SLDFCSMIN = 12;
		static const Sbecore::uint SLDFCSMAX = 13;
		static const Sbecore::uint TXTOAFAVAIL = 14;
		static const Sbecore::uint BUTSTSACTIVE = 15;
		static const Sbecore::uint UPDLLOAVAIL = 16;
		static const Sbecore::uint UPDLLOMIN = 17;
		static const Sbecore::uint UPDLLOMAX = 18;
		static const Sbecore::uint UPDLUOAVAIL = 19;
		static const Sbecore::uint UPDLUOMIN = 20;
		static const Sbecore::uint UPDLUOMAX = 21;
		static const Sbecore::uint UPDLMDAVAIL = 22;
		static const Sbecore::uint UPDLMDMIN = 23;
		static const Sbecore::uint UPDLMDMAX = 24;
		static const Sbecore::uint UPDPNTMIN = 25;
		static const Sbecore::uint UPDPNTMAX = 26;
		static const Sbecore::uint SLDCWDMIN = 27;
		static const Sbecore::uint SLDCWDMAX = 28;
		static const Sbecore::uint SLDCWDRAST = 29;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool ButPlayActive = true, const bool ButStopActive = true, const bool ChkAexActive = true, const bool SldExtAvail = true, const bool SldExtActive = true, const double SldExtMin = 0.001, const double SldExtMax = 100.0, const double SldExtRast = 1.77828, const bool SldFcsActive = true, const double SldFcsMin = 0.0, const double SldFcsMax = 1.0, const bool TxtOafAvail = true, const bool ButStsActive = true, const bool UpdLloAvail = true, const int UpdLloMin = 0, const int UpdLloMax = 255, const bool UpdLuoAvail = true, const int UpdLuoMin = 0, const int UpdLuoMax = 255, const bool UpdLmdAvail = true, const int UpdLmdMin = 0, const int UpdLmdMax = 255, const int UpdPntMin = 0, const int UpdPntMax = 1000, const double SldCwdMin = 0.2, const double SldCwdMax = 0.38, const double SldCwdRast = 0.005);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool ButPlayActive;
		bool ButStopActive;
		bool ChkAexActive;
		bool SldExtAvail;
		bool SldExtActive;
		double SldExtMin;
		double SldExtMax;
		double SldExtRast;
		bool SldFcsActive;
		double SldFcsMin;
		double SldFcsMax;
		bool TxtOafAvail;
		bool ButStsActive;
		bool UpdLloAvail;
		int UpdLloMin;
		int UpdLloMax;
		bool UpdLuoAvail;
		int UpdLuoMin;
		int UpdLuoMax;
		bool UpdLmdAvail;
		int UpdLmdMin;
		int UpdLmdMax;
		int UpdPntMin;
		int UpdPntMax;
		double SldCwdMin;
		double SldCwdMax;
		double SldCwdRast;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLiv2DView)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppAlign (full: DpchAppWzskLiv2DViewAlign)
		*/
	class DpchAppAlign : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIACCORNER = 2;
		static const Sbecore::uint CONTIACTRACE = 3;

	public:
		DpchAppAlign();

	public:
		ContIacCorner contiaccorner;
		ContIacTrace contiactrace;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskLiv2DViewData)
		*/
	class DpchAppData : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;

	public:
		DpchAppData();

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLiv2DViewDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngAlign (full: DpchEngWzskLiv2DViewAlign)
		*/
	class DpchEngAlign : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIACCORNER = 2;
		static const Sbecore::uint CONTIACTRACE = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngAlign(const Sbecore::ubigint jref = 0, ContIacCorner* contiaccorner = NULL, ContIacTrace* contiactrace = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIacCorner contiaccorner;
		ContIacTrace contiactrace;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWzskLiv2DViewData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPPVM = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFPupPvm = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFPupPvm;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngLive (full: DpchEngWzskLiv2DViewLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint GRAY = 2;
		static const Sbecore::uint RED = 3;
		static const Sbecore::uint GREEN = 4;
		static const Sbecore::uint BLUE = 5;
		static const Sbecore::uint XCORNER = 6;
		static const Sbecore::uint YCORNER = 7;
		static const Sbecore::uint XTRACEL = 8;
		static const Sbecore::uint YTRACEL = 9;
		static const Sbecore::uint XTRACER = 10;
		static const Sbecore::uint YTRACER = 11;
		static const Sbecore::uint ALL = 12;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<Sbecore::utinyint>& gray = {}, const std::vector<Sbecore::utinyint>& red = {}, const std::vector<Sbecore::utinyint>& green = {}, const std::vector<Sbecore::utinyint>& blue = {}, const std::vector<int>& xCorner = {}, const std::vector<int>& yCorner = {}, const std::vector<int>& xTraceL = {}, const std::vector<int>& yTraceL = {}, const std::vector<int>& xTraceR = {}, const std::vector<int>& yTraceR = {}, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::vector<Sbecore::utinyint> gray;

		std::vector<Sbecore::utinyint> red;
		std::vector<Sbecore::utinyint> green;
		std::vector<Sbecore::utinyint> blue;

		std::vector<int> xCorner;
		std::vector<int> yCorner;

		std::vector<int> xTraceL;
		std::vector<int> yTraceL;

		std::vector<int> xTraceR;
		std::vector<int> yTraceR;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalButPlayActive(DbsWzsk* dbswzsk);
	bool evalButStopActive(DbsWzsk* dbswzsk);
	bool evalChkAexActive(DbsWzsk* dbswzsk);
	bool evalSldExtAvail(DbsWzsk* dbswzsk);
	bool evalSldExtActive(DbsWzsk* dbswzsk);
	bool evalSldFcsActive(DbsWzsk* dbswzsk);
	bool evalTxtOafAvail(DbsWzsk* dbswzsk);
	bool evalButStsActive(DbsWzsk* dbswzsk);
	bool evalUpdLloAvail(DbsWzsk* dbswzsk);
	bool evalUpdLuoAvail(DbsWzsk* dbswzsk);
	bool evalUpdLmdAvail(DbsWzsk* dbswzsk);

public:
	PnlWzskLiv2DView(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLiv2DView();

public:
	ContIac contiac;
	ContIacCorner contiaccorner;
	ContIacTrace contiactrace;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFPupPvm;

	JobWzskIprTrace* iprtrace;
	JobWzskIprCorner* iprcorner;
	JobWzskActServo* actservo;
	JobWzskActLaser* actlaser;
	JobWzskActExposure* actexposure;
	JobWzskAcqPtcloud* acqptcloud;
	JobWzskAcqPreview* acqpreview;

	// IP vars.cust --- IBEGIN
	bool initdoneAlign;

	bool snapshotArmed;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void refreshAlign(std::set<Sbecore::uint>& moditems);

	void takeSnapshot(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPvwmode, uint8_t* gr8, uint8_t* r8, uint8_t* g8, uint8_t* b8);
	void takeSnapshot_writePng(const std::string& path, unsigned char* imgdat, const unsigned int width, const unsigned int height);
	// IP cust --- IEND

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppAlign(DbsWzsk* dbswzsk, DpchAppAlign* dpchappalign, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButClaimClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPlayClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStopClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStsClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButTccClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButTcwClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButLleClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButLriClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButLtrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPicClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChgFromActservo(DbsWzsk* dbswzsk);
	bool handleCallWzskStgChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskShrdatChgFromIprtrace(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskShrdatChgFromIprcorner(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskShrdatChgFromActlaser(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskShrdatChgFromActexposure(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskShrdatChgFromAcqptcloud(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskResultNew(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskClaimChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

};

#endif
