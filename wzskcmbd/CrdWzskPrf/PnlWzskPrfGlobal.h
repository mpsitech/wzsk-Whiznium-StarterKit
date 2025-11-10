/**
	* \file PnlWzskPrfGlobal.h
	* job handler for job PnlWzskPrfGlobal (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFGLOBAL_H
#define PNLWZSKPRFGLOBAL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskPrfGlobalDo PnlWzskPrfGlobal::VecVDo

#define ContIacWzskPrfGlobal PnlWzskPrfGlobal::ContIac
#define StatShrWzskPrfGlobal PnlWzskPrfGlobal::StatShr
#define TagWzskPrfGlobal PnlWzskPrfGlobal::Tag

#define DpchAppWzskPrfGlobalData PnlWzskPrfGlobal::DpchAppData
#define DpchAppWzskPrfGlobalDo PnlWzskPrfGlobal::DpchAppDo
#define DpchEngWzskPrfGlobalData PnlWzskPrfGlobal::DpchEngData

/**
	* PnlWzskPrfGlobal
	*/
class PnlWzskPrfGlobal : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskPrfGlobalDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfGlobal)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF2 = 1;
		static const Sbecore::uint TXF3 = 2;
		static const Sbecore::uint TXF4 = 3;
		static const Sbecore::uint TXF5 = 4;
		static const Sbecore::uint TXF6 = 5;
		static const Sbecore::uint NUMFPUP102 = 6;

	public:
		ContIac(const std::string& Txf2 = "", const std::string& Txf3 = "", const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const Sbecore::uint numFPup102 = 1);

	public:
		std::string Txf2;
		std::string Txf3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		Sbecore::uint numFPup102;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatShr (full: StatShrWzskPrfGlobal)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF2CLEAN = 2;
		static const Sbecore::uint TXF3CLEAN = 3;
		static const Sbecore::uint TXF4CLEAN = 4;
		static const Sbecore::uint TXF5CLEAN = 5;
		static const Sbecore::uint TXF6CLEAN = 6;
		static const Sbecore::uint PUP102CLEAN = 7;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf2Clean = false, const bool Txf3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Pup102Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf2Clean;
		bool Txf3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Pup102Clean;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskPrfGlobal)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfGlobalData)
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
		* DpchAppDo (full: DpchAppWzskPrfGlobalDo)
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
		* DpchEngData (full: DpchEngWzskPrfGlobalData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUP102 = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFPup102 = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFPup102;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	PnlWzskPrfGlobal(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskPrfGlobal();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFPup102;

	// IP vars.cust --- BEGIN
	StgWzskCamera stgwzskcamera;
	// IP vars.cust --- END

public:
	// IP cust --- BEGIN
	void getPref(StgWzskCamera*& _stgwzskcamera);
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
