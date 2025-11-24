/**
	* \file PnlWzskVtrDebug.h
	* job handler for job PnlWzskVtrDebug (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKVTRDEBUG_H
#define PNLWZSKVTRDEBUG_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqVtrtrack.h"

#define VecVWzskVtrDebugDo PnlWzskVtrDebug::VecVDo

#define ContIacWzskVtrDebug PnlWzskVtrDebug::ContIac
#define ContInfWzskVtrDebug PnlWzskVtrDebug::ContInf
#define StatShrWzskVtrDebug PnlWzskVtrDebug::StatShr
#define TagWzskVtrDebug PnlWzskVtrDebug::Tag

#define DpchAppWzskVtrDebugData PnlWzskVtrDebug::DpchAppData
#define DpchAppWzskVtrDebugDo PnlWzskVtrDebug::DpchAppDo
#define DpchEngWzskVtrDebugData PnlWzskVtrDebug::DpchEngData

/**
	* PnlWzskVtrDebug
	*/
class PnlWzskVtrDebug : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskVtrDebugDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTTSRCLICK = 4;
		static const Sbecore::uint BUTTSPCLICK = 5;
		static const Sbecore::uint BUTTTFVIEWCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskVtrDebug)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXFTFR = 1;

	public:
		ContIac(const std::string& TxfTfr = "");

	public:
		std::string TxfTfr;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskVtrDebug)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTTST = 2;
		static const Sbecore::uint TXTTTF = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtTst = "", const std::string& TxtTtf = "");

	public:
		bool ButClaimOn;
		std::string TxtTst;
		std::string TxtTtf;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskVtrDebug)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint TXFTFRACTIVE = 3;
		static const Sbecore::uint BUTTSRACTIVE = 4;
		static const Sbecore::uint BUTTSPACTIVE = 5;
		static const Sbecore::uint BUTTTFVIEWACTIVE = 6;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool TxfTfrActive = true, const bool ButTsrActive = true, const bool ButTspActive = true, const bool ButTtfViewActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool TxfTfrActive;
		bool ButTsrActive;
		bool ButTspActive;
		bool ButTtfViewActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskVtrDebug)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskVtrDebugData)
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
		* DpchAppDo (full: DpchAppWzskVtrDebugDo)
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
		* DpchEngData (full: DpchEngWzskVtrDebugData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalTxfTfrActive(DbsWzsk* dbswzsk);
	bool evalButTsrActive(DbsWzsk* dbswzsk);
	bool evalButTspActive(DbsWzsk* dbswzsk);
	bool evalButTtfViewActive(DbsWzsk* dbswzsk);

public:
	PnlWzskVtrDebug(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskVtrDebug();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	JobWzskAcqVtrtrack* acqvtrtrack;

	// IP vars.cust --- IBEGIN
	unsigned int numTrack;
	Sbecore::ubigint refFilTrack;
	// IP vars.cust --- IEND

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
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButClaimClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButTsrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButTspClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButTtfViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskResultNewFromAcqvtrtrack(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);

};

#endif
