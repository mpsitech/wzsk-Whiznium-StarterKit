/**
	* \file PnlWzskShtRec.h
	* job handler for job PnlWzskShtRec (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef PNLWZSKSHTREC_H
#define PNLWZSKSHTREC_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskShtRef1NFile.h"
#include "PnlWzskShtAPar.h"
#include "PnlWzskShtDetail.h"

#define VecVWzskShtRecDo PnlWzskShtRec::VecVDo

#define ContInfWzskShtRec PnlWzskShtRec::ContInf
#define StatAppWzskShtRec PnlWzskShtRec::StatApp
#define StatShrWzskShtRec PnlWzskShtRec::StatShr
#define TagWzskShtRec PnlWzskShtRec::Tag

#define DpchAppWzskShtRecDo PnlWzskShtRec::DpchAppDo
#define DpchEngWzskShtRecData PnlWzskShtRec::DpchEngData

/**
	* PnlWzskShtRec
	*/
class PnlWzskShtRec : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskShtRecDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTMINIMIZECLICK = 1;
		static const Sbecore::uint BUTREGULARIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskShtRec)
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
		* StatApp (full: StatAppWzskShtRec)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool initdoneDetail = false, const bool initdoneAPar = false, const bool initdoneRef1NFile = false);
	};

	/**
		* StatShr (full: StatShrWzskShtRec)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint JREFDETAIL = 2;
		static const Sbecore::uint JREFAPAR = 3;
		static const Sbecore::uint JREFREF1NFILE = 4;
		static const Sbecore::uint BUTREGULARIZEACTIVE = 5;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::REGD, const Sbecore::ubigint jrefDetail = 0, const Sbecore::ubigint jrefAPar = 0, const Sbecore::ubigint jrefRef1NFile = 0, const bool ButRegularizeActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		Sbecore::ubigint jrefDetail;
		Sbecore::ubigint jrefAPar;
		Sbecore::ubigint jrefRef1NFile;
		bool ButRegularizeActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskShtRec)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskShtRecDo)
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
		* DpchEngData (full: DpchEngWzskShtRecData)
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
	PnlWzskShtRec(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskShtRec();

public:
	ContInf continf;
	StatShr statshr;

	PnlWzskShtRef1NFile* pnlref1nfile;
	PnlWzskShtAPar* pnlapar;
	PnlWzskShtDetail* pnldetail;

	WzskMShot recSht;

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
	bool handleCallWzskShtUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskSht_sesEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzskSht_objEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

