/**
	* \file PnlWzskPrfDaemon.h
	* job handler for job PnlWzskPrfDaemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFDAEMON_H
#define PNLWZSKPRFDAEMON_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskPrfDaemonDo PnlWzskPrfDaemon::VecVDo

#define ContIacWzskPrfDaemon PnlWzskPrfDaemon::ContIac
#define StatShrWzskPrfDaemon PnlWzskPrfDaemon::StatShr
#define TagWzskPrfDaemon PnlWzskPrfDaemon::Tag

#define DpchAppWzskPrfDaemonData PnlWzskPrfDaemon::DpchAppData
#define DpchAppWzskPrfDaemonDo PnlWzskPrfDaemon::DpchAppDo
#define DpchEngWzskPrfDaemonData PnlWzskPrfDaemon::DpchEngData

/**
	* PnlWzskPrfDaemon
	*/
class PnlWzskPrfDaemon : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskPrfDaemonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfDaemon)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF2 = 1;
		static const Sbecore::uint CHK3 = 2;
		static const Sbecore::uint TXF4 = 3;
		static const Sbecore::uint TXF5 = 4;
		static const Sbecore::uint TXF6 = 5;
		static const Sbecore::uint TXF102 = 6;
		static const Sbecore::uint CHK103 = 7;
		static const Sbecore::uint TXF104 = 8;
		static const Sbecore::uint TXF202 = 9;
		static const Sbecore::uint TXF203 = 10;
		static const Sbecore::uint CHK204 = 11;
		static const Sbecore::uint CHK205 = 12;
		static const Sbecore::uint CHK206 = 13;
		static const Sbecore::uint NUMFPUP302 = 14;
		static const Sbecore::uint TXF303 = 15;
		static const Sbecore::uint TXF304 = 16;
		static const Sbecore::uint TXF305 = 17;
		static const Sbecore::uint TXF306 = 18;
		static const Sbecore::uint TXF307 = 19;
		static const Sbecore::uint TXF308 = 20;
		static const Sbecore::uint TXF402 = 21;
		static const Sbecore::uint TXF403 = 22;
		static const Sbecore::uint TXF404 = 23;
		static const Sbecore::uint TXF405 = 24;
		static const Sbecore::uint TXF406 = 25;
		static const Sbecore::uint TXF407 = 26;
		static const Sbecore::uint TXF502 = 27;
		static const Sbecore::uint TXF503 = 28;
		static const Sbecore::uint TXF602 = 29;
		static const Sbecore::uint TXF603 = 30;
		static const Sbecore::uint TXF604 = 31;
		static const Sbecore::uint TXF605 = 32;
		static const Sbecore::uint TXF606 = 33;

	public:
		ContIac(const std::string& Txf2 = "", const bool Chk3 = false, const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const std::string& Txf102 = "", const bool Chk103 = false, const std::string& Txf104 = "", const std::string& Txf202 = "", const std::string& Txf203 = "", const bool Chk204 = false, const bool Chk205 = false, const bool Chk206 = false, const Sbecore::uint numFPup302 = 1, const std::string& Txf303 = "", const std::string& Txf304 = "", const std::string& Txf305 = "", const std::string& Txf306 = "", const std::string& Txf307 = "", const std::string& Txf308 = "", const std::string& Txf402 = "", const std::string& Txf403 = "", const std::string& Txf404 = "", const std::string& Txf405 = "", const std::string& Txf406 = "", const std::string& Txf407 = "", const std::string& Txf502 = "", const std::string& Txf503 = "", const std::string& Txf602 = "", const std::string& Txf603 = "", const std::string& Txf604 = "", const std::string& Txf605 = "", const std::string& Txf606 = "");

	public:
		std::string Txf2;
		bool Chk3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		std::string Txf102;
		bool Chk103;
		std::string Txf104;
		std::string Txf202;
		std::string Txf203;
		bool Chk204;
		bool Chk205;
		bool Chk206;
		Sbecore::uint numFPup302;
		std::string Txf303;
		std::string Txf304;
		std::string Txf305;
		std::string Txf306;
		std::string Txf307;
		std::string Txf308;
		std::string Txf402;
		std::string Txf403;
		std::string Txf404;
		std::string Txf405;
		std::string Txf406;
		std::string Txf407;
		std::string Txf502;
		std::string Txf503;
		std::string Txf602;
		std::string Txf603;
		std::string Txf604;
		std::string Txf605;
		std::string Txf606;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatShr (full: StatShrWzskPrfDaemon)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF2CLEAN = 2;
		static const Sbecore::uint CHK3CLEAN = 3;
		static const Sbecore::uint TXF4CLEAN = 4;
		static const Sbecore::uint TXF5CLEAN = 5;
		static const Sbecore::uint TXF6CLEAN = 6;
		static const Sbecore::uint TXF102CLEAN = 7;
		static const Sbecore::uint CHK103CLEAN = 8;
		static const Sbecore::uint TXF104CLEAN = 9;
		static const Sbecore::uint SEP2AVAIL = 10;
		static const Sbecore::uint HDG201AVAIL = 11;
		static const Sbecore::uint TXF202AVAIL = 12;
		static const Sbecore::uint TXF202CLEAN = 13;
		static const Sbecore::uint TXF203AVAIL = 14;
		static const Sbecore::uint TXF203CLEAN = 15;
		static const Sbecore::uint CHK204AVAIL = 16;
		static const Sbecore::uint CHK204CLEAN = 17;
		static const Sbecore::uint CHK205AVAIL = 18;
		static const Sbecore::uint CHK205CLEAN = 19;
		static const Sbecore::uint CHK206AVAIL = 20;
		static const Sbecore::uint CHK206CLEAN = 21;
		static const Sbecore::uint PUP302CLEAN = 22;
		static const Sbecore::uint TXF303CLEAN = 23;
		static const Sbecore::uint TXF304CLEAN = 24;
		static const Sbecore::uint TXF305CLEAN = 25;
		static const Sbecore::uint TXF306CLEAN = 26;
		static const Sbecore::uint TXF307CLEAN = 27;
		static const Sbecore::uint TXF308CLEAN = 28;
		static const Sbecore::uint TXF402CLEAN = 29;
		static const Sbecore::uint TXF403CLEAN = 30;
		static const Sbecore::uint TXF404CLEAN = 31;
		static const Sbecore::uint TXF405CLEAN = 32;
		static const Sbecore::uint TXF406CLEAN = 33;
		static const Sbecore::uint TXF407CLEAN = 34;
		static const Sbecore::uint TXF502CLEAN = 35;
		static const Sbecore::uint TXF503CLEAN = 36;
		static const Sbecore::uint TXF602CLEAN = 37;
		static const Sbecore::uint TXF603CLEAN = 38;
		static const Sbecore::uint TXF604CLEAN = 39;
		static const Sbecore::uint TXF605CLEAN = 40;
		static const Sbecore::uint TXF606CLEAN = 41;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf2Clean = false, const bool Chk3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Txf102Clean = false, const bool Chk103Clean = false, const bool Txf104Clean = false, const bool Sep2Avail = true, const bool Hdg201Avail = true, const bool Txf202Avail = true, const bool Txf202Clean = false, const bool Txf203Avail = true, const bool Txf203Clean = false, const bool Chk204Avail = true, const bool Chk204Clean = false, const bool Chk205Avail = true, const bool Chk205Clean = false, const bool Chk206Avail = true, const bool Chk206Clean = false, const bool Pup302Clean = false, const bool Txf303Clean = false, const bool Txf304Clean = false, const bool Txf305Clean = false, const bool Txf306Clean = false, const bool Txf307Clean = false, const bool Txf308Clean = false, const bool Txf402Clean = false, const bool Txf403Clean = false, const bool Txf404Clean = false, const bool Txf405Clean = false, const bool Txf406Clean = false, const bool Txf407Clean = false, const bool Txf502Clean = false, const bool Txf503Clean = false, const bool Txf602Clean = false, const bool Txf603Clean = false, const bool Txf604Clean = false, const bool Txf605Clean = false, const bool Txf606Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf2Clean;
		bool Chk3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Txf102Clean;
		bool Chk103Clean;
		bool Txf104Clean;
		bool Sep2Avail;
		bool Hdg201Avail;
		bool Txf202Avail;
		bool Txf202Clean;
		bool Txf203Avail;
		bool Txf203Clean;
		bool Chk204Avail;
		bool Chk204Clean;
		bool Chk205Avail;
		bool Chk205Clean;
		bool Chk206Avail;
		bool Chk206Clean;
		bool Pup302Clean;
		bool Txf303Clean;
		bool Txf304Clean;
		bool Txf305Clean;
		bool Txf306Clean;
		bool Txf307Clean;
		bool Txf308Clean;
		bool Txf402Clean;
		bool Txf403Clean;
		bool Txf404Clean;
		bool Txf405Clean;
		bool Txf406Clean;
		bool Txf407Clean;
		bool Txf502Clean;
		bool Txf503Clean;
		bool Txf602Clean;
		bool Txf603Clean;
		bool Txf604Clean;
		bool Txf605Clean;
		bool Txf606Clean;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskPrfDaemon)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfDaemonData)
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
		* DpchAppDo (full: DpchAppWzskPrfDaemonDo)
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
		* DpchEngData (full: DpchEngWzskPrfDaemonData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUP302 = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFPup302 = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFPup302;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalSep2Avail(DbsWzsk* dbswzsk);
	bool evalHdg201Avail(DbsWzsk* dbswzsk);
	bool evalTxf202Avail(DbsWzsk* dbswzsk);
	bool evalTxf203Avail(DbsWzsk* dbswzsk);
	bool evalChk204Avail(DbsWzsk* dbswzsk);
	bool evalChk205Avail(DbsWzsk* dbswzsk);
	bool evalChk206Avail(DbsWzsk* dbswzsk);

public:
	PnlWzskPrfDaemon(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskPrfDaemon();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFPup302;

	// IP vars.cust --- BEGIN
	StgWzskBehavior stgwzskbehavior;
	StgWzskAppsrv stgwzskappsrv;
#ifdef WZSKCMBD
	StgWzskcmbd stgwzskcmbd;
#endif
	StgWzskDatabase stgwzskdatabase;
	StgWzskPath stgwzskpath;
	StgWzskDdspub stgwzskddspub;
	StgWzskUasrv stgwzskuasrv;
	// IP vars.cust --- END

public:
	// IP cust --- BEGIN
#ifdef WZSKD
	void getPref(StgWzskBehavior*& _stgwzskbehavior, StgWzskAppsrv*& _stgwzskappsrv, StgWzskDatabase*& _stgwzskdatabase, StgWzskPath*& _stgwzskpath, StgWzskDdspub*& _stgwzskddspub, StgWzskUasrv*& _stgwzskuasrv);
#endif
#ifdef WZSKCMBD
	void getPref(StgWzskBehavior*& _stgwzskbehavior, StgWzskAppsrv*& _stgwzskappsrv, StgWzskcmbd*& _stgwzskcmbd, StgWzskDatabase*& _stgwzskdatabase, StgWzskPath*& _stgwzskpath, StgWzskDdspub*& _stgwzskddspub, StgWzskUasrv*& _stgwzskuasrv);
#endif
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
