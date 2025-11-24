/**
	* \file PnlWzskHwcConfig.h
	* job handler for job PnlWzskHwcConfig (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKHWCCONFIG_H
#define PNLWZSKHWCCONFIG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqHdr.h"
#include "JobWzskAcqPreview.h"
#include "JobWzskPrcWavelet.h"

#define VecVWzskHwcConfigDo PnlWzskHwcConfig::VecVDo
#define VecVWzskHwcConfigMode PnlWzskHwcConfig::VecVMode
#define VecVWzskHwcConfigSge PnlWzskHwcConfig::VecVSge

#define ContIacWzskHwcConfig PnlWzskHwcConfig::ContIac
#define ContIacWzskHwcConfigAlign PnlWzskHwcConfig::ContIacAlign
#define ContInfWzskHwcConfig PnlWzskHwcConfig::ContInf
#define StatShrWzskHwcConfig PnlWzskHwcConfig::StatShr
#define TagWzskHwcConfig PnlWzskHwcConfig::Tag

#define DpchAppWzskHwcConfigAlign PnlWzskHwcConfig::DpchAppAlign
#define DpchAppWzskHwcConfigData PnlWzskHwcConfig::DpchAppData
#define DpchAppWzskHwcConfigDo PnlWzskHwcConfig::DpchAppDo
#define DpchEngWzskHwcConfigAlign PnlWzskHwcConfig::DpchEngAlign
#define DpchEngWzskHwcConfigData PnlWzskHwcConfig::DpchEngData
#define DpchEngWzskHwcConfigLive PnlWzskHwcConfig::DpchEngLive

/**
	* PnlWzskHwcConfig
	*/
class PnlWzskHwcConfig : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskHwcConfigDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTPLAYCLICK = 4;
		static const Sbecore::uint BUTSTOPCLICK = 5;
		static const Sbecore::uint BUTSNAPCLICK = 6;
		static const Sbecore::uint BUTPFIVIEWCLICK = 7;
		static const Sbecore::uint BUTSTACLICK = 8;
		static const Sbecore::uint BUTSTOCLICK = 9;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMode (full: VecVWzskHwcConfigMode)
		*/
	class VecVMode {

	public:
		static const Sbecore::uint GRAY = 1;
		static const Sbecore::uint RGB = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static std::string getTitle(const Sbecore::uint ix, const Sbecore::uint ixWzskVLocale);

		static void fillFeed(const Sbecore::uint ixWzskVLocale, Sbecore::Feed& feed);
	};

	/**
		* VecVSge (full: VecVWzskHwcConfigSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CAPTURE = 2;
		static const Sbecore::uint STOIDLE = 3;
		static const Sbecore::uint STORE = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacWzskHwcConfig)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFRBUMDE = 1;
		static const Sbecore::uint UPDNFR = 2;
		static const Sbecore::uint SLDFST = 3;
		static const Sbecore::uint SLDFSP = 4;

	public:
		ContIac(const Sbecore::uint numFRbuMde = 1, const int UpdNfr = 0, const double SldFst = 0.0, const double SldFsp = 0.0);

	public:
		Sbecore::uint numFRbuMde;
		int UpdNfr;
		double SldFst;
		double SldFsp;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacAlign (full: ContIacWzskHwcConfigAlign)
	  */
	class ContIacAlign : public Sbecore::Block {

	public:
		static const Sbecore::uint ROIX0 = 1;
		static const Sbecore::uint ROIY0 = 2;
		static const Sbecore::uint ROIX1 = 3;
		static const Sbecore::uint ROIY1 = 4;

	public:
		ContIacAlign(const int roiX0 = -300, const int roiY0 = -200, const int roiX1 = 300, const int roiY1 = 200);

	public:
		int roiX0;
		int roiY0;
		int roiX1;
		int roiY1;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIacAlign* comp);
		std::set<Sbecore::uint> diff(const ContIacAlign* comp);
	};

	/**
	  * ContInf (full: ContInfWzskHwcConfig)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTPFI = 2;
		static const Sbecore::uint TXTSTE = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtPfi = "", const std::string& TxtSte = "");

	public:
		bool ButClaimOn;
		std::string TxtPfi;
		std::string TxtSte;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskHwcConfig)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint CUSIMGHEIGHT = 3;
		static const Sbecore::uint BUTPLAYACTIVE = 4;
		static const Sbecore::uint BUTSTOPACTIVE = 5;
		static const Sbecore::uint BUTSNAPACTIVE = 6;
		static const Sbecore::uint BUTPFIVIEWACTIVE = 7;
		static const Sbecore::uint UPDNFRACTIVE = 8;
		static const Sbecore::uint UPDNFRMIN = 9;
		static const Sbecore::uint UPDNFRMAX = 10;
		static const Sbecore::uint SLDFSTACTIVE = 11;
		static const Sbecore::uint SLDFSTMIN = 12;
		static const Sbecore::uint SLDFSTMAX = 13;
		static const Sbecore::uint SLDFSPACTIVE = 14;
		static const Sbecore::uint SLDFSPMIN = 15;
		static const Sbecore::uint SLDFSPMAX = 16;
		static const Sbecore::uint BUTSTAACTIVE = 17;
		static const Sbecore::uint BUTSTOACTIVE = 18;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const Sbecore::uint CusImgHeight = 384, const bool ButPlayActive = true, const bool ButStopActive = true, const bool ButSnapActive = true, const bool ButPfiViewActive = true, const bool UpdNfrActive = true, const int UpdNfrMin = 10, const int UpdNfrMax = 100, const bool SldFstActive = true, const double SldFstMin = 1, const double SldFstMax = 1000, const bool SldFspActive = true, const double SldFspMin = 1, const double SldFspMax = 1000, const bool ButStaActive = true, const bool ButStoActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		Sbecore::uint CusImgHeight;
		bool ButPlayActive;
		bool ButStopActive;
		bool ButSnapActive;
		bool ButPfiViewActive;
		bool UpdNfrActive;
		int UpdNfrMin;
		int UpdNfrMax;
		bool SldFstActive;
		double SldFstMin;
		double SldFstMax;
		bool SldFspActive;
		double SldFspMin;
		double SldFspMax;
		bool ButStaActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskHwcConfig)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppAlign (full: DpchAppWzskHwcConfigAlign)
		*/
	class DpchAppAlign : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIACALIGN = 2;

	public:
		DpchAppAlign();

	public:
		ContIacAlign contiacalign;

	public:
		std::string getSrefsMask();

		void readJSON(const Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskHwcConfigData)
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
		* DpchAppDo (full: DpchAppWzskHwcConfigDo)
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
		* DpchEngAlign (full: DpchEngWzskHwcConfigAlign)
		*/
	class DpchEngAlign : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIACALIGN = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngAlign(const Sbecore::ubigint jref = 0, ContIacAlign* contiacalign = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIacAlign contiacalign;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWzskHwcConfigData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFRBUMDE = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Feed* feedFRbuMde = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Feed feedFRbuMde;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	/**
		* DpchEngLive (full: DpchEngWzskHwcConfigLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint GRAY = 2;
		static const Sbecore::uint RGB = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<Sbecore::utinyint>& gray = {}, const std::vector<Sbecore::utinyint>& rgb = {}, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::vector<Sbecore::utinyint> gray;
		std::vector<Sbecore::utinyint> rgb;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalButPlayActive(DbsWzsk* dbswzsk);
	bool evalButStopActive(DbsWzsk* dbswzsk);
	bool evalButSnapActive(DbsWzsk* dbswzsk);
	bool evalButPfiViewActive(DbsWzsk* dbswzsk);
	bool evalUpdNfrActive(DbsWzsk* dbswzsk);
	bool evalSldFstActive(DbsWzsk* dbswzsk);
	bool evalSldFspActive(DbsWzsk* dbswzsk);
	bool evalButStaActive(DbsWzsk* dbswzsk);
	bool evalButStoActive(DbsWzsk* dbswzsk);

public:
	PnlWzskHwcConfig(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskHwcConfig();

public:
	ContIac contiac;
	ContIacAlign contiacalign;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFRbuMde;

	JobWzskAcqHdr* acqhdr;
	JobWzskAcqPreview* acqpreview;
	JobWzskPrcWavelet* prcwavelet;

	// IP vars.cust --- IBEGIN
	unsigned int scale;

	unsigned int numSshot;
	Sbecore::ubigint refFilSshot;

	Sbecore::uint ixRiHdr;
	Sbecore::uint ixRiPvw;
	// IP vars.cust --- IEND

public:
	// IP cust --- IBEGIN
	void updateScale(DbsWzsk* dbswzsk);

	void writeRGBE(const std::string& fullpath);
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
	void handleDpchAppDoButSnapClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPfiViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStaClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStoClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

	void handleTimerInSgeStoidle(DbsWzsk* dbswzsk, const std::string& sref);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskResultNewFromAcqpreview(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool handleCallWzskResultNewFromAcqhdrInSgeCapture(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge, DpchEngWzsk** dpcheng = NULL);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCapture(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCapture(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeStoidle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeStoidle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeStore(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeStore(DbsWzsk* dbswzsk);

};

#endif
