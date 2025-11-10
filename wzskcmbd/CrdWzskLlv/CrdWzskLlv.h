/**
	* \file CrdWzskLlv.h
	* job handler for job CrdWzskLlv (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef CRDWZSKLLV_H
#define CRDWZSKLLV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskLlvIdent.h"
#include "PnlWzskLlvHeadbar.h"
#include "PnlWzskLlvTermDcvsp.h"
#include "PnlWzskLlvTermTivsp.h"
#include "PnlWzskLlvLaser.h"
#include "PnlWzskLlvRotary.h"
#include "PnlWzskLlvSysmon.h"
#include "PnlWzskLlvTermZuvsp.h"

#define VecVWzskLlvDo CrdWzskLlv::VecVDo
#define VecVWzskLlvSge CrdWzskLlv::VecVSge

#define ContInfWzskLlv CrdWzskLlv::ContInf
#define StatAppWzskLlv CrdWzskLlv::StatApp
#define StatShrWzskLlv CrdWzskLlv::StatShr
#define TagWzskLlv CrdWzskLlv::Tag

#define DpchAppWzskLlvDo CrdWzskLlv::DpchAppDo
#define DpchEngWzskLlvData CrdWzskLlv::DpchEngData

/**
	* CrdWzskLlv
	*/
class CrdWzskLlv : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskLlvDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskLlvSge)
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
	  * ContInf (full: ContInfWzskLlv)
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
		* StatApp (full: StatAppWzskLlv)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneIdent = false, const bool initdoneHeadbar = false, const bool initdoneTermDcvsp = false, const bool initdoneTermTivsp = false, const bool initdoneLaser = false, const bool initdoneRotary = false, const bool initdoneSysmon = false, const bool initdoneTermZuvsp = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneIdent = false, const bool initdoneHeadbar = false, const bool initdoneTermDcvsp = false, const bool initdoneTermTivsp = false, const bool initdoneLaser = false, const bool initdoneRotary = false, const bool initdoneSysmon = false, const bool initdoneTermZuvsp = false);
	};

	/**
		* StatShr (full: StatShrWzskLlv)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFIDENT = 1;
		static const Sbecore::uint JREFHEADBAR = 2;
		static const Sbecore::uint JREFTERMDCVSP = 3;
		static const Sbecore::uint PNLTERMDCVSPAVAIL = 4;
		static const Sbecore::uint JREFTERMTIVSP = 5;
		static const Sbecore::uint PNLTERMTIVSPAVAIL = 6;
		static const Sbecore::uint JREFLASER = 7;
		static const Sbecore::uint JREFROTARY = 8;
		static const Sbecore::uint JREFSYSMON = 9;
		static const Sbecore::uint JREFTERMZUVSP = 10;
		static const Sbecore::uint PNLTERMZUVSPAVAIL = 11;

	public:
		StatShr(const Sbecore::ubigint jrefIdent = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefTermDcvsp = 0, const bool pnltermdcvspAvail = false, const Sbecore::ubigint jrefTermTivsp = 0, const bool pnltermtivspAvail = false, const Sbecore::ubigint jrefLaser = 0, const Sbecore::ubigint jrefRotary = 0, const Sbecore::ubigint jrefSysmon = 0, const Sbecore::ubigint jrefTermZuvsp = 0, const bool pnltermzuvspAvail = false);

	public:
		Sbecore::ubigint jrefIdent;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefTermDcvsp;
		bool pnltermdcvspAvail;
		Sbecore::ubigint jrefTermTivsp;
		bool pnltermtivspAvail;
		Sbecore::ubigint jrefLaser;
		Sbecore::ubigint jrefRotary;
		Sbecore::ubigint jrefSysmon;
		Sbecore::ubigint jrefTermZuvsp;
		bool pnltermzuvspAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLlv)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvDo)
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
		* DpchEngData (full: DpchEngWzskLlvData)
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

	bool evalPnltermdcvspAvail(DbsWzsk* dbswzsk);
	bool evalPnltermtivspAvail(DbsWzsk* dbswzsk);
	bool evalPnltermzuvspAvail(DbsWzsk* dbswzsk);

public:
	CrdWzskLlv(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~CrdWzskLlv();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWzskLlvIdent* pnlident;
	PnlWzskLlvHeadbar* pnlheadbar;
	PnlWzskLlvTermDcvsp* pnltermdcvsp;
	PnlWzskLlvTermTivsp* pnltermtivsp;
	PnlWzskLlvLaser* pnllaser;
	PnlWzskLlvRotary* pnlrotary;
	PnlWzskLlvSysmon* pnlsysmon;
	PnlWzskLlvTermZuvsp* pnltermzuvsp;

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
