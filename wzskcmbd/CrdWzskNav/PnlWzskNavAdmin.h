/**
	* \file PnlWzskNavAdmin.h
	* job handler for job PnlWzskNavAdmin (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVADMIN_H
#define PNLWZSKNAVADMIN_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskNavAdminDo PnlWzskNavAdmin::VecVDo

#define ContIacWzskNavAdmin PnlWzskNavAdmin::ContIac
#define StatAppWzskNavAdmin PnlWzskNavAdmin::StatApp
#define StatShrWzskNavAdmin PnlWzskNavAdmin::StatShr
#define TagWzskNavAdmin PnlWzskNavAdmin::Tag

#define DpchAppWzskNavAdminData PnlWzskNavAdmin::DpchAppData
#define DpchAppWzskNavAdminDo PnlWzskNavAdmin::DpchAppDo
#define DpchEngWzskNavAdminData PnlWzskNavAdmin::DpchEngData

/**
	* PnlWzskNavAdmin
	*/
class PnlWzskNavAdmin : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskNavAdminDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUSGVIEWCLICK = 1;
		static const Sbecore::uint BUTUSGNEWCRDCLICK = 2;
		static const Sbecore::uint BUTUSRVIEWCLICK = 3;
		static const Sbecore::uint BUTUSRNEWCRDCLICK = 4;
		static const Sbecore::uint BUTPRSVIEWCLICK = 5;
		static const Sbecore::uint BUTPRSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTPRFNEWCRDCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskNavAdmin)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTUSG = 1;
		static const Sbecore::uint NUMFLSTUSR = 2;
		static const Sbecore::uint NUMFLSTPRS = 3;

	public:
		ContIac(const Sbecore::uint numFLstUsg = 1, const Sbecore::uint numFLstUsr = 1, const Sbecore::uint numFLstPrs = 1);

	public:
		Sbecore::uint numFLstUsg;
		Sbecore::uint numFLstUsr;
		Sbecore::uint numFLstPrs;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWzskNavAdmin)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzskNavAdmin)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTUSGAVAIL = 1;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 2;
		static const Sbecore::uint LSTUSRAVAIL = 3;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 4;
		static const Sbecore::uint LSTPRSAVAIL = 5;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 6;
		static const Sbecore::uint BUTPRFNEWCRDAVAIL = 7;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool ButPrfNewcrdAvail = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool ButPrfNewcrdAvail;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskNavAdmin)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskNavAdminData)
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
		* DpchAppDo (full: DpchAppWzskNavAdminDo)
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
		* DpchEngData (full: DpchEngWzskNavAdminData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTPRS = 3;
		static const Sbecore::uint FEEDFLSTUSG = 4;
		static const Sbecore::uint FEEDFLSTUSR = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstPrs = NULL, Sbecore::Feed* feedFLstUsg = NULL, Sbecore::Feed* feedFLstUsr = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstPrs;
		Sbecore::Feed feedFLstUsg;
		Sbecore::Feed feedFLstUsr;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalLstUsgAvail(DbsWzsk* dbswzsk);
	bool evalButUsgViewActive(DbsWzsk* dbswzsk);
	bool evalLstUsrAvail(DbsWzsk* dbswzsk);
	bool evalButUsrViewActive(DbsWzsk* dbswzsk);
	bool evalLstPrsAvail(DbsWzsk* dbswzsk);
	bool evalButPrsViewActive(DbsWzsk* dbswzsk);
	bool evalButPrfNewcrdAvail(DbsWzsk* dbswzsk);

public:
	PnlWzskNavAdmin(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskNavAdmin();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstPrs;
	Sbecore::Feed feedFLstUsg;
	Sbecore::Feed feedFLstUsr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstUsg(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshUsg(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshLstUsr(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshUsr(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshLstPrs(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshPrs(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButUsgViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButUsgNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButUsrNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPrsNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPrfNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskHusrRunvMod_crdUsrEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
