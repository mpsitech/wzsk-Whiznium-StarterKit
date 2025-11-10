/**
	* \file PnlWzskPrfSrcTivsp.h
	* job handler for job PnlWzskPrfSrcTivsp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 12 Oct 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFSRCTIVSP_H
#define PNLWZSKPRFSRCTIVSP_H

// IP include.spec --- INSERT

#include "JobWzskSrcTivsp.h" // IP include.cust --- LINE

#define VecVWzskPrfSrcTivspDo PnlWzskPrfSrcTivsp::VecVDo

#define ContIacWzskPrfSrcTivsp PnlWzskPrfSrcTivsp::ContIac
#define StatShrWzskPrfSrcTivsp PnlWzskPrfSrcTivsp::StatShr
#define TagWzskPrfSrcTivsp PnlWzskPrfSrcTivsp::Tag

#define DpchAppWzskPrfSrcTivspData PnlWzskPrfSrcTivsp::DpchAppData
#define DpchAppWzskPrfSrcTivspDo PnlWzskPrfSrcTivsp::DpchAppDo
#define DpchEngWzskPrfSrcTivspData PnlWzskPrfSrcTivsp::DpchEngData

/**
	* PnlWzskPrfSrcTivsp
	*/
class PnlWzskPrfSrcTivsp : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskPrfSrcTivspDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfSrcTivsp)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF1 = 1;

	public:
		ContIac(const std::string& Txf1 = "");

	public:
		std::string Txf1;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatShr (full: StatShrWzskPrfSrcTivsp)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF1CLEAN = 2;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf1Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf1Clean;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskPrfSrcTivsp)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfSrcTivspData)
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
		* DpchAppDo (full: DpchAppWzskPrfSrcTivspDo)
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
		* DpchEngData (full: DpchEngWzskPrfSrcTivspData)
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
	PnlWzskPrfSrcTivsp(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskPrfSrcTivsp();

public:
	ContIac contiac;
	StatShr statshr;

	// IP vars.cust --- BEGIN
	JobWzskSrcTivsp::Stg stgjobwzsksrctivsp;
	// IP vars.cust --- END

public:
	// IP cust --- BEGIN
	void getPref(JobWzskSrcTivsp::Stg*& _stgjobwzsksrctivsp);
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
