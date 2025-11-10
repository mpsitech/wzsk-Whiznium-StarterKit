/**
	* \file PnlWzskVtrConfig.h
	* job handler for job PnlWzskVtrConfig (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKVTRCONFIG_H
#define PNLWZSKVTRCONFIG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqPreview.h"
#include "JobWzskActVistorot.h"

#define VecVWzskVtrConfigDo PnlWzskVtrConfig::VecVDo
#define VecVWzskVtrConfigMode PnlWzskVtrConfig::VecVMode

#define ContIacWzskVtrConfig PnlWzskVtrConfig::ContIac
#define ContIacWzskVtrConfigAlign PnlWzskVtrConfig::ContIacAlign
#define ContInfWzskVtrConfig PnlWzskVtrConfig::ContInf
#define StatShrWzskVtrConfig PnlWzskVtrConfig::StatShr
#define TagWzskVtrConfig PnlWzskVtrConfig::Tag

#define DpchAppWzskVtrConfigAlign PnlWzskVtrConfig::DpchAppAlign
#define DpchAppWzskVtrConfigData PnlWzskVtrConfig::DpchAppData
#define DpchAppWzskVtrConfigDo PnlWzskVtrConfig::DpchAppDo
#define DpchEngWzskVtrConfigAlign PnlWzskVtrConfig::DpchEngAlign
#define DpchEngWzskVtrConfigData PnlWzskVtrConfig::DpchEngData
#define DpchEngWzskVtrConfigLive PnlWzskVtrConfig::DpchEngLive

/**
	* PnlWzskVtrConfig
	*/
class PnlWzskVtrConfig : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskVtrConfigDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTSTACLICK = 4;
		static const Sbecore::uint BUTSTOCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVMode (full: VecVWzskVtrConfigMode)
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
	  * ContIac (full: ContIacWzskVtrConfig)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFRBUMDE = 1;
		static const Sbecore::uint SLDASP = 2;

	public:
		ContIac(const Sbecore::uint numFRbuMde = 1, const double SldAsp = 0.0);

	public:
		Sbecore::uint numFRbuMde;
		double SldAsp;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContIacAlign (full: ContIacWzskVtrConfigAlign)
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
	  * ContInf (full: ContInfWzskVtrConfig)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTSTE = 2;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtSte = "");

	public:
		bool ButClaimOn;
		std::string TxtSte;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskVtrConfig)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint RBUMDEACTIVE = 3;
		static const Sbecore::uint CUSIMGHEIGHT = 4;
		static const Sbecore::uint SLDASPACTIVE = 5;
		static const Sbecore::uint SLDASPMIN = 6;
		static const Sbecore::uint SLDASPMAX = 7;
		static const Sbecore::uint BUTSTAACTIVE = 8;
		static const Sbecore::uint BUTSTOACTIVE = 9;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool RbuMdeActive = true, const Sbecore::uint CusImgHeight = 384, const bool SldAspActive = true, const double SldAspMin = -180.0, const double SldAspMax = 180.0, const bool ButStaActive = true, const bool ButStoActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool RbuMdeActive;
		Sbecore::uint CusImgHeight;
		bool SldAspActive;
		double SldAspMin;
		double SldAspMax;
		bool ButStaActive;
		bool ButStoActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskVtrConfig)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppAlign (full: DpchAppWzskVtrConfigAlign)
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
		* DpchAppData (full: DpchAppWzskVtrConfigData)
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
		* DpchAppDo (full: DpchAppWzskVtrConfigDo)
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
		* DpchEngAlign (full: DpchEngWzskVtrConfigAlign)
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
		* DpchEngData (full: DpchEngWzskVtrConfigData)
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
		* DpchEngLive (full: DpchEngWzskVtrConfigLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint GRAY = 2;
		static const Sbecore::uint RED = 3;
		static const Sbecore::uint GREEN = 4;
		static const Sbecore::uint BLUE = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<Sbecore::utinyint>& gray = {}, const std::vector<Sbecore::utinyint>& red = {}, const std::vector<Sbecore::utinyint>& green = {}, const std::vector<Sbecore::utinyint>& blue = {}, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::vector<Sbecore::utinyint> gray;

		std::vector<Sbecore::utinyint> red;
		std::vector<Sbecore::utinyint> green;
		std::vector<Sbecore::utinyint> blue;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalRbuMdeActive(DbsWzsk* dbswzsk);
	bool evalSldAspActive(DbsWzsk* dbswzsk);
	bool evalButStaActive(DbsWzsk* dbswzsk);
	bool evalButStoActive(DbsWzsk* dbswzsk);

public:
	PnlWzskVtrConfig(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskVtrConfig();

public:
	ContIac contiac;
	ContIacAlign contiacalign;
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFRbuMde;

	JobWzskAcqPreview* acqpreview;
	JobWzskActVistorot* actvistorot;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

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
	void handleDpchAppDoButStaClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStoClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

};

#endif
