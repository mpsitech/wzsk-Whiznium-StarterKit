/**
	* \file CrdWzskLlv.h
	* job handler for job CrdWzskLlv (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZSKLLV_H
#define CRDWZSKLLV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskLlvLaser.h"
#include "PnlWzskLlvTtable.h"
#include "PnlWzskLlvCamera.h"
#include "PnlWzskLlvTermUvbdvk.h"
#include "PnlWzskLlvTermMcvevp.h"
#include "PnlWzskLlvTermIcicle.h"
#include "PnlWzskLlvTermArty.h"
#include "PnlWzskLlvTermClnxevb.h"
#include "PnlWzskLlvHeadbar.h"

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
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneTermArty = false, const bool initdoneTermClnxevb = false, const bool initdoneTermIcicle = false, const bool initdoneTermMcvevp = false, const bool initdoneTermUvbdvk = false, const bool initdoneCamera = false, const bool initdoneTtable = false, const bool initdoneLaser = false);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneTermArty = false, const bool initdoneTermClnxevb = false, const bool initdoneTermIcicle = false, const bool initdoneTermMcvevp = false, const bool initdoneTermUvbdvk = false, const bool initdoneCamera = false, const bool initdoneTtable = false, const bool initdoneLaser = false);
	};

	/**
		* StatShr (full: StatShrWzskLlv)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFHEADBAR = 1;
		static const Sbecore::uint JREFTERMARTY = 2;
		static const Sbecore::uint PNLTERMARTYAVAIL = 3;
		static const Sbecore::uint JREFTERMCLNXEVB = 4;
		static const Sbecore::uint PNLTERMCLNXEVBAVAIL = 5;
		static const Sbecore::uint JREFTERMICICLE = 6;
		static const Sbecore::uint PNLTERMICICLEAVAIL = 7;
		static const Sbecore::uint JREFTERMMCVEVP = 8;
		static const Sbecore::uint PNLTERMMCVEVPAVAIL = 9;
		static const Sbecore::uint JREFTERMUVBDVK = 10;
		static const Sbecore::uint PNLTERMUVBDVKAVAIL = 11;
		static const Sbecore::uint JREFCAMERA = 12;
		static const Sbecore::uint JREFTTABLE = 13;
		static const Sbecore::uint JREFLASER = 14;

	public:
		StatShr(const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefTermArty = 0, const bool pnltermartyAvail = false, const Sbecore::ubigint jrefTermClnxevb = 0, const bool pnltermclnxevbAvail = false, const Sbecore::ubigint jrefTermIcicle = 0, const bool pnltermicicleAvail = false, const Sbecore::ubigint jrefTermMcvevp = 0, const bool pnltermmcvevpAvail = false, const Sbecore::ubigint jrefTermUvbdvk = 0, const bool pnltermuvbdvkAvail = false, const Sbecore::ubigint jrefCamera = 0, const Sbecore::ubigint jrefTtable = 0, const Sbecore::ubigint jrefLaser = 0);

	public:
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefTermArty;
		bool pnltermartyAvail;
		Sbecore::ubigint jrefTermClnxevb;
		bool pnltermclnxevbAvail;
		Sbecore::ubigint jrefTermIcicle;
		bool pnltermicicleAvail;
		Sbecore::ubigint jrefTermMcvevp;
		bool pnltermmcvevpAvail;
		Sbecore::ubigint jrefTermUvbdvk;
		bool pnltermuvbdvkAvail;
		Sbecore::ubigint jrefCamera;
		Sbecore::ubigint jrefTtable;
		Sbecore::ubigint jrefLaser;

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

		void readJSON(Json::Value& sup, bool addbasetag = false);
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

	bool evalPnltermartyAvail(DbsWzsk* dbswzsk);
	bool evalPnltermclnxevbAvail(DbsWzsk* dbswzsk);
	bool evalPnltermicicleAvail(DbsWzsk* dbswzsk);
	bool evalPnltermmcvevpAvail(DbsWzsk* dbswzsk);
	bool evalPnltermuvbdvkAvail(DbsWzsk* dbswzsk);

public:
	CrdWzskLlv(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~CrdWzskLlv();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Feed feedFMcbAlert;
	Sbecore::Feed feedFSge;

	PnlWzskLlvLaser* pnllaser;
	PnlWzskLlvTtable* pnlttable;
	PnlWzskLlvCamera* pnlcamera;
	PnlWzskLlvTermUvbdvk* pnltermuvbdvk;
	PnlWzskLlvTermMcvevp* pnltermmcvevp;
	PnlWzskLlvTermIcicle* pnltermicicle;
	PnlWzskLlvTermArty* pnltermarty;
	PnlWzskLlvTermClnxevb* pnltermclnxevb;
	PnlWzskLlvHeadbar* pnlheadbar;

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
