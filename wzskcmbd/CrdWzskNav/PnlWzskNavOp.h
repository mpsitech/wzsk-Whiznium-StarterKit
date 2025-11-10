/**
	* \file PnlWzskNavOp.h
	* job handler for job PnlWzskNavOp (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVOP_H
#define PNLWZSKNAVOP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskNavOpDo PnlWzskNavOp::VecVDo

#define ContIacWzskNavOp PnlWzskNavOp::ContIac
#define StatAppWzskNavOp PnlWzskNavOp::StatApp
#define StatShrWzskNavOp PnlWzskNavOp::StatShr
#define TagWzskNavOp PnlWzskNavOp::Tag

#define DpchAppWzskNavOpData PnlWzskNavOp::DpchAppData
#define DpchAppWzskNavOpDo PnlWzskNavOp::DpchAppDo
#define DpchEngWzskNavOpData PnlWzskNavOp::DpchEngData

/**
	* PnlWzskNavOp
	*/
class PnlWzskNavOp : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskNavOpDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTLLVNEWCRDCLICK = 1;
		static const Sbecore::uint BUTVTRNEWCRDCLICK = 2;
		static const Sbecore::uint BUTHWCNEWCRDCLICK = 3;
		static const Sbecore::uint BUTFILVIEWCLICK = 4;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskNavOp)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTFIL = 1;

	public:
		ContIac(const Sbecore::uint numFLstFil = 1);

	public:
		Sbecore::uint numFLstFil;

	public:
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWzskNavOp)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstFilAlt = true, const Sbecore::uint LstFilNumFirstdisp = 1);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstFilAlt = true, const Sbecore::uint LstFilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzskNavOp)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint BUTLLVNEWCRDAVAIL = 1;
		static const Sbecore::uint BUTVTRNEWCRDAVAIL = 2;
		static const Sbecore::uint BUTHWCNEWCRDAVAIL = 3;
		static const Sbecore::uint LSTFILAVAIL = 4;
		static const Sbecore::uint BUTFILVIEWACTIVE = 5;

	public:
		StatShr(const bool ButLlvNewcrdAvail = true, const bool ButVtrNewcrdAvail = true, const bool ButHwcNewcrdAvail = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool ButLlvNewcrdAvail;
		bool ButVtrNewcrdAvail;
		bool ButHwcNewcrdAvail;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskNavOp)
		*/
	class Tag {

	public:
		static void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup, std::string difftag = "");
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskNavOpData)
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
		* DpchAppDo (full: DpchAppWzskNavOpDo)
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
		* DpchEngData (full: DpchEngWzskNavOpData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Feed* feedFLstFil = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstFil;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButLlvNewcrdAvail(DbsWzsk* dbswzsk);
	bool evalButVtrNewcrdAvail(DbsWzsk* dbswzsk);
	bool evalButHwcNewcrdAvail(DbsWzsk* dbswzsk);
	bool evalLstFilAvail(DbsWzsk* dbswzsk);
	bool evalButFilViewActive(DbsWzsk* dbswzsk);

public:
	PnlWzskNavOp(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskNavOp();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Feed feedFLstFil;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstFil(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshFil(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButLlvNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButVtrNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButHwcNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskHusrRunvMod_crdUsrEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
