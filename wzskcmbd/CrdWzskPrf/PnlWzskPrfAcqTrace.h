/**
	* \file PnlWzskPrfAcqTrace.h
	* job handler for job PnlWzskPrfAcqTrace (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFACQTRACE_H
#define PNLWZSKPRFACQTRACE_H

// IP include.spec --- INSERT

#include "JobWzskAcqTrace.h" // IP include.cust --- LINE

#define VecVWzskPrfAcqTraceDo PnlWzskPrfAcqTrace::VecVDo

#define ContIacWzskPrfAcqTrace PnlWzskPrfAcqTrace::ContIac
#define StatShrWzskPrfAcqTrace PnlWzskPrfAcqTrace::StatShr
#define TagWzskPrfAcqTrace PnlWzskPrfAcqTrace::Tag

#define DpchAppWzskPrfAcqTraceData PnlWzskPrfAcqTrace::DpchAppData
#define DpchAppWzskPrfAcqTraceDo PnlWzskPrfAcqTrace::DpchAppDo
#define DpchEngWzskPrfAcqTraceData PnlWzskPrfAcqTrace::DpchEngData

/**
	* PnlWzskPrfAcqTrace
	*/
class PnlWzskPrfAcqTrace : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskPrfAcqTraceDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfAcqTrace)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF1 = 1;
		static const Sbecore::uint TXF2 = 2;
		static const Sbecore::uint TXF3 = 3;
		static const Sbecore::uint TXF4 = 4;

	public:
		ContIac(const std::string& Txf1 = "", const std::string& Txf2 = "", const std::string& Txf3 = "", const std::string& Txf4 = "");

	public:
		std::string Txf1;
		std::string Txf2;
		std::string Txf3;
		std::string Txf4;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatShr (full: StatShrWzskPrfAcqTrace)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF1CLEAN = 2;
		static const Sbecore::uint TXF2CLEAN = 3;
		static const Sbecore::uint TXF3CLEAN = 4;
		static const Sbecore::uint TXF4CLEAN = 5;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf1Clean = false, const bool Txf2Clean = false, const bool Txf3Clean = false, const bool Txf4Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf1Clean;
		bool Txf2Clean;
		bool Txf3Clean;
		bool Txf4Clean;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskPrfAcqTrace)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfAcqTraceData)
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
		* DpchAppDo (full: DpchAppWzskPrfAcqTraceDo)
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
		* DpchEngData (full: DpchEngWzskPrfAcqTraceData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	PnlWzskPrfAcqTrace(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskPrfAcqTrace();

public:
	ContIac contiac;
	StatShr statshr;

	// IP vars.cust --- BEGIN
	JobWzskAcqTrace::Stg stgjobwzskacqtrace;
	// IP vars.cust --- END

public:
	// IP cust --- BEGIN
	void getPref(JobWzskAcqTrace::Stg*& _stgjobwzskacqtrace);
	void setPref(DbsWzsk* dbswzsk, const bool _refresh = false);
	// IP cust --- END

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

};

#endif
