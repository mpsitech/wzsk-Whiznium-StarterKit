/**
	* \file CrdWzskHwc.h
	* job handler for job CrdWzskHwc (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef CRDWZSKHWC_H
#define CRDWZSKHWC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskHwcConfig.h"
#include "PnlWzskHwcAsys.h"
#include "PnlWzskHwcDebug.h"
#include "PnlWzskHwcHeadbar.h"

#define VecVWzskHwcDo CrdWzskHwc::VecVDo
#define VecVWzskHwcSge CrdWzskHwc::VecVSge

#define ContInfWzskHwc CrdWzskHwc::ContInf
#define StatAppWzskHwc CrdWzskHwc::StatApp
#define StatShrWzskHwc CrdWzskHwc::StatShr
#define TagWzskHwc CrdWzskHwc::Tag

#define DpchAppWzskHwcDo CrdWzskHwc::DpchAppDo
#define DpchEngWzskHwcData CrdWzskHwc::DpchEngData

/**
	* CrdWzskHwc
	*/
class CrdWzskHwc : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskHwcDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskHwcSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZSKABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWzskHwc)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskHwc)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneConfig = false, const bool initdoneAsys = false, const bool initdoneDebug = false, const bool initdoneHeadbar = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneConfig = false, const bool initdoneAsys = false, const bool initdoneDebug = false, const bool initdoneHeadbar = false);
	};

	/**
		* StatShr (full: StatShrWzskHwc)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFCONFIG = 1;
		static const Sbecore::uint JREFASYS = 2;
		static const Sbecore::uint JREFDEBUG = 3;
		static const Sbecore::uint JREFHEADBAR = 4;

	public:
		StatShr(const Sbecore::ubigint jrefConfig = 0, const Sbecore::ubigint jrefAsys = 0, const Sbecore::ubigint jrefDebug = 0, const Sbecore::ubigint jrefHeadbar = 0);

	public:
		Sbecore::ubigint jrefConfig;
		Sbecore::ubigint jrefAsys;
		Sbecore::ubigint jrefDebug;
		Sbecore::ubigint jrefHeadbar;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskHwc)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskHwcDo)
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
		* DpchEngData (full: DpchEngWzskHwcData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	CrdWzskHwc(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~CrdWzskHwc();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWzskHwcConfig* pnlconfig;
	PnlWzskHwcAsys* pnlasys;
	PnlWzskHwcDebug* pnldebug;
	PnlWzskHwcHeadbar* pnlheadbar;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoClose(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppWzskAlert(DbsWzsk* dbswzsk, DpchAppWzskAlert* dpchappwzskalert, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskDlgClose(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge, DpchEngWzsk** dpcheng = NULL);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeAlrwzskabt(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeAlrwzskabt(DbsWzsk* dbswzsk);

};

#endif
