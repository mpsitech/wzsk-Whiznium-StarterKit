/**
	* \file PnlWzskUsrRec.h
	* job handler for job PnlWzskUsrRec (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef PNLWZSKUSRREC_H
#define PNLWZSKUSRREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskUsrMNUsergroup.h"
#include "PnlWzskUsr1NSession.h"
#include "PnlWzskUsrAAccess.h"
#include "PnlWzskUsrDetail.h"

#define VecVWzskUsrRecDo PnlWzskUsrRec::VecVDo

#define ContInfWzskUsrRec PnlWzskUsrRec::ContInf
#define StatAppWzskUsrRec PnlWzskUsrRec::StatApp
#define StatShrWzskUsrRec PnlWzskUsrRec::StatShr
#define TagWzskUsrRec PnlWzskUsrRec::Tag

#define DpchAppWzskUsrRecDo PnlWzskUsrRec::DpchAppDo
#define DpchEngWzskUsrRecData PnlWzskUsrRec::DpchEngData

/**
	* PnlWzskUsrRec
	*/
class PnlWzskUsrRec : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskUsrRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskUsrRec)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTREF = 1;

	public:
		ContInf(const std::string& TxtRef = "");

	public:
		std::string TxtRef;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskUsrRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAAccess = false, const bool initdone1NSession = false, const bool initdoneMNUsergroup = false);
	};

	/**
		* StatShr (full: StatShrWzskUsrRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAACCESS = 3;
		static const Sbecore::uint JREF1NSESSION = 4;
		static const Sbecore::uint JREFMNUSERGROUP = 5;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAAccess = 0, const Sbecore::ubigint jref1NSession = 0, const Sbecore::ubigint jrefMNUsergroup = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAAccess;
		Sbecore::ubigint jref1NSession;
		Sbecore::ubigint jrefMNUsergroup;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskUsrRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskUsrRecDo)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskUsrRecData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButRegularizeActive(DbsWzsk* dbswzsk);

public:
	PnlWzskUsrRec(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskUsrRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWzskUsrMNUsergroup* pnlmnusergroup;
	PnlWzskUsr1NSession* pnl1nsession;
	PnlWzskUsrAAccess* pnlaaccess;
	PnlWzskUsrDetail* pnldetail;

	WzskMUser recUsr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);
	void minimize(DbsWzsk* dbswzsk, const bool notif = false, DpchEngWzsk** dpcheng = NULL);
	void regularize(DbsWzsk* dbswzsk, const bool notif = false, DpchEngWzsk** dpcheng = NULL);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskUsrUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskUsr_usgEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzskUsr_prsEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

