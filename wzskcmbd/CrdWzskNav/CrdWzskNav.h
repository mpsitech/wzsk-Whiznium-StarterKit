/**
	* \file CrdWzskNav.h
	* job handler for job CrdWzskNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef CRDWZSKNAV_H
#define CRDWZSKNAV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "DlgWzskNavLoaini.h"
#include "PnlWzskNavHeadbar.h"
#include "PnlWzskNavAdmin.h"
#include "PnlWzskNavOp.h"

#define VecVWzskNavDo CrdWzskNav::VecVDo
#define VecVWzskNavSge CrdWzskNav::VecVSge

#define ContInfWzskNav CrdWzskNav::ContInf
#define StatAppWzskNav CrdWzskNav::StatApp
#define StatShrWzskNav CrdWzskNav::StatShr
#define TagWzskNav CrdWzskNav::Tag

#define DpchAppWzskNavDo CrdWzskNav::DpchAppDo
#define DpchEngWzskNavData CrdWzskNav::DpchEngData

/**
	* CrdWzskNav
	*/
class CrdWzskNav : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDPRFCLICK = 8;
		static const Sbecore::uint MITCRDLLVCLICK = 9;
		static const Sbecore::uint MITCRDVTRCLICK = 10;
		static const Sbecore::uint MITCRDHWCCLICK = 11;
		static const Sbecore::uint MITCRDFILCLICK = 12;
		static const Sbecore::uint MITAPPLOICLICK = 13;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZSKABT = 2;
		static const Sbecore::uint ALRWZSKTRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWzskNav)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskNav)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneOp = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneOp = false);
	};

	/**
		* StatShr (full: StatShrWzskNav)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFDLGLOAINI = 1;
		static const Sbecore::uint JREFHEADBAR = 2;
		static const Sbecore::uint JREFADMIN = 3;
		static const Sbecore::uint PNLADMINAVAIL = 4;
		static const Sbecore::uint JREFOP = 5;
		static const Sbecore::uint PNLOPAVAIL = 6;
		static const Sbecore::uint MITSESSPSAVAIL = 7;
		static const Sbecore::uint MSPCRD1AVAIL = 8;
		static const Sbecore::uint MITCRDUSGAVAIL = 9;
		static const Sbecore::uint MITCRDUSRAVAIL = 10;
		static const Sbecore::uint MITCRDPRSAVAIL = 11;
		static const Sbecore::uint MITCRDPRFAVAIL = 12;
		static const Sbecore::uint MSPCRD2AVAIL = 13;
		static const Sbecore::uint MITCRDLLVAVAIL = 14;
		static const Sbecore::uint MITCRDVTRAVAIL = 15;
		static const Sbecore::uint MITCRDHWCAVAIL = 16;
		static const Sbecore::uint MITCRDFILAVAIL = 17;
		static const Sbecore::uint MSPAPP2AVAIL = 18;
		static const Sbecore::uint MITAPPLOIAVAIL = 19;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefOp = 0, const bool pnlopAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdPrfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLlvAvail = true, const bool MitCrdVtrAvail = true, const bool MitCrdHwcAvail = true, const bool MitCrdFilAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		Sbecore::ubigint jrefDlgloaini;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefAdmin;
		bool pnladminAvail;
		Sbecore::ubigint jrefOp;
		bool pnlopAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdPrfAvail;
		bool MspCrd2Avail;
		bool MitCrdLlvAvail;
		bool MitCrdVtrAvail;
		bool MitCrdHwcAvail;
		bool MitCrdFilAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskNav)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavDo)
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
		* DpchEngData (full: DpchEngWzskNavData)
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

	bool evalPnladminAvail(DbsWzsk* dbswzsk);
	bool evalPnlopAvail(DbsWzsk* dbswzsk);
	bool evalMitSesSpsAvail(DbsWzsk* dbswzsk);
	bool evalMspCrd1Avail(DbsWzsk* dbswzsk);
	bool evalMitCrdUsgAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdUsrAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdPrsAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdPrfAvail(DbsWzsk* dbswzsk);
	bool evalMspCrd2Avail(DbsWzsk* dbswzsk);
	bool evalMitCrdLlvAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdVtrAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdHwcAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdFilAvail(DbsWzsk* dbswzsk);
	bool evalMspApp2Avail(DbsWzsk* dbswzsk);
	bool evalMitAppLoiAvail(DbsWzsk* dbswzsk);

public:
	CrdWzskNav(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~CrdWzskNav();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	DlgWzskNavLoaini* dlgloaini;
	PnlWzskNavHeadbar* pnlheadbar;
	PnlWzskNavAdmin* pnladmin;
	PnlWzskNavOp* pnlop;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void warnTerm(DbsWzsk* dbswzsk);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoClose(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitSesSpsClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdPrfClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdLlvClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdVtrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdHwcClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
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
	Sbecore::uint enterSgeAlrwzsktrm(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeAlrwzsktrm(DbsWzsk* dbswzsk);

};

#endif
