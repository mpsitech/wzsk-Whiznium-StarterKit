/**
	* \file CrdWzskPrf.h
	* job handler for job CrdWzskPrf (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef CRDWZSKPRF_H
#define CRDWZSKPRF_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskPrfHeadbar.h"
#include "PnlWzskPrfDaemon.h"
#include "PnlWzskPrfGlobal.h"
#include "PnlWzskPrfAcqCorner.h"
#include "PnlWzskPrfAcqPreview.h"
#include "PnlWzskPrfAcqTrace.h"
#include "PnlWzskPrfActLaser.h"
#include "PnlWzskPrfActVistorot.h"
#include "PnlWzskPrfSrcDcvsp.h"
#include "PnlWzskPrfSrcSysinfo.h"
#include "PnlWzskPrfSrcTivsp.h"
#include "PnlWzskPrfSrcZuvsp.h"

#define VecVWzskPrfDo CrdWzskPrf::VecVDo
#define VecVWzskPrfSge CrdWzskPrf::VecVSge

#define ContInfWzskPrf CrdWzskPrf::ContInf
#define StatAppWzskPrf CrdWzskPrf::StatApp
#define StatShrWzskPrf CrdWzskPrf::StatShr
#define TagWzskPrf CrdWzskPrf::Tag

#define DpchAppWzskPrfDo CrdWzskPrf::DpchAppDo
#define DpchEngWzskPrfData CrdWzskPrf::DpchEngData

/**
	* CrdWzskPrf
	*/
class CrdWzskPrf : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskPrfDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDRVRCLICK = 3;
		static const Sbecore::uint MITCRDSTOCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskPrfSge)
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
	  * ContInf (full: ContInfWzskPrf)
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
		* StatApp (full: StatAppWzskPrf)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneDaemon = false, const bool initdoneGlobal = false, const bool initdoneAcqCorner = false, const bool initdoneAcqPreview = false, const bool initdoneAcqTrace = false, const bool initdoneActLaser = false, const bool initdoneActVistorot = false, const bool initdoneSrcDcvsp = false, const bool initdoneSrcSysinfo = false, const bool initdoneSrcTivsp = false, const bool initdoneSrcZuvsp = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneDaemon = false, const bool initdoneGlobal = false, const bool initdoneAcqCorner = false, const bool initdoneAcqPreview = false, const bool initdoneAcqTrace = false, const bool initdoneActLaser = false, const bool initdoneActVistorot = false, const bool initdoneSrcDcvsp = false, const bool initdoneSrcSysinfo = false, const bool initdoneSrcTivsp = false, const bool initdoneSrcZuvsp = false);
	};

	/**
		* StatShr (full: StatShrWzskPrf)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFHEADBAR = 1;
		static const Sbecore::uint JREFDAEMON = 2;
		static const Sbecore::uint JREFGLOBAL = 3;
		static const Sbecore::uint JREFACQCORNER = 4;
		static const Sbecore::uint JREFACQPREVIEW = 5;
		static const Sbecore::uint JREFACQTRACE = 6;
		static const Sbecore::uint JREFACTLASER = 7;
		static const Sbecore::uint JREFACTVISTOROT = 8;
		static const Sbecore::uint JREFSRCDCVSP = 9;
		static const Sbecore::uint JREFSRCSYSINFO = 10;
		static const Sbecore::uint JREFSRCTIVSP = 11;
		static const Sbecore::uint JREFSRCZUVSP = 12;

	public:
		StatShr(const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefDaemon = 0, const Sbecore::ubigint jrefGlobal = 0, const Sbecore::ubigint jrefAcqCorner = 0, const Sbecore::ubigint jrefAcqPreview = 0, const Sbecore::ubigint jrefAcqTrace = 0, const Sbecore::ubigint jrefActLaser = 0, const Sbecore::ubigint jrefActVistorot = 0, const Sbecore::ubigint jrefSrcDcvsp = 0, const Sbecore::ubigint jrefSrcSysinfo = 0, const Sbecore::ubigint jrefSrcTivsp = 0, const Sbecore::ubigint jrefSrcZuvsp = 0);

	public:
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefDaemon;
		Sbecore::ubigint jrefGlobal;
		Sbecore::ubigint jrefAcqCorner;
		Sbecore::ubigint jrefAcqPreview;
		Sbecore::ubigint jrefAcqTrace;
		Sbecore::ubigint jrefActLaser;
		Sbecore::ubigint jrefActVistorot;
		Sbecore::ubigint jrefSrcDcvsp;
		Sbecore::ubigint jrefSrcSysinfo;
		Sbecore::ubigint jrefSrcTivsp;
		Sbecore::ubigint jrefSrcZuvsp;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskPrf)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskPrfDo)
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
		* DpchEngData (full: DpchEngWzskPrfData)
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
	CrdWzskPrf(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~CrdWzskPrf();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWzskPrfHeadbar* pnlheadbar;
	PnlWzskPrfDaemon* pnldaemon;
	PnlWzskPrfGlobal* pnlglobal;
	PnlWzskPrfAcqCorner* pnlacqcorner;
	PnlWzskPrfAcqPreview* pnlacqpreview;
	PnlWzskPrfAcqTrace* pnlacqtrace;
	PnlWzskPrfActLaser* pnlactlaser;
	PnlWzskPrfActVistorot* pnlactvistorot;
	PnlWzskPrfSrcDcvsp* pnlsrcdcvsp;
	PnlWzskPrfSrcSysinfo* pnlsrcsysinfo;
	PnlWzskPrfSrcTivsp* pnlsrctivsp;
	PnlWzskPrfSrcZuvsp* pnlsrczuvsp;

	// IP vars.cust --- INSERT

public:
	// IP cust --- BEGIN
	void setPref(DbsWzsk* dbswzsk);
	void storePref();
	// IP cust --- END

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
	void handleDpchAppDoMitCrdRvrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdStoClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
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
