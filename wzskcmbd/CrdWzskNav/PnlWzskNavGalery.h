/**
	* \file PnlWzskNavGalery.h
	* job handler for job PnlWzskNavGalery (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef PNLWZSKNAVGALERY_H
#define PNLWZSKNAVGALERY_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskNavGaleryDo PnlWzskNavGalery::VecVDo

#define ContIacWzskNavGalery PnlWzskNavGalery::ContIac
#define StatAppWzskNavGalery PnlWzskNavGalery::StatApp
#define StatShrWzskNavGalery PnlWzskNavGalery::StatShr
#define TagWzskNavGalery PnlWzskNavGalery::Tag

#define DpchAppWzskNavGaleryData PnlWzskNavGalery::DpchAppData
#define DpchAppWzskNavGaleryDo PnlWzskNavGalery::DpchAppDo
#define DpchEngWzskNavGaleryData PnlWzskNavGalery::DpchEngData

/**
	* PnlWzskNavGalery
	*/
class PnlWzskNavGalery : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskNavGaleryDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTOGRVIEWCLICK = 1;
		static const Sbecore::uint BUTOGRNEWCRDCLICK = 2;
		static const Sbecore::uint BUTOBJVIEWCLICK = 3;
		static const Sbecore::uint BUTOBJNEWCRDCLICK = 4;
		static const Sbecore::uint BUTSESVIEWCLICK = 5;
		static const Sbecore::uint BUTSESNEWCRDCLICK = 6;
		static const Sbecore::uint BUTSHTVIEWCLICK = 7;
		static const Sbecore::uint BUTSHTNEWCRDCLICK = 8;
		static const Sbecore::uint BUTFILVIEWCLICK = 9;
		static const Sbecore::uint BUTFILNEWCRDCLICK = 10;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskNavGalery)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFLSTOGR = 1;
		static const Sbecore::uint NUMFLSTOBJ = 2;
		static const Sbecore::uint NUMFLSTSES = 3;
		static const Sbecore::uint NUMFLSTSHT = 4;
		static const Sbecore::uint NUMFLSTFIL = 5;

	public:
		ContIac(const Sbecore::uint numFLstOgr = 1, const Sbecore::uint numFLstObj = 1, const Sbecore::uint numFLstSes = 1, const Sbecore::uint numFLstSht = 1, const Sbecore::uint numFLstFil = 1);

	public:
		Sbecore::uint numFLstOgr;
		Sbecore::uint numFLstObj;
		Sbecore::uint numFLstSes;
		Sbecore::uint numFLstSht;
		Sbecore::uint numFLstFil;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
		* StatApp (full: StatAppWzskNavGalery)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstOgrAlt = true, const bool LstObjAlt = true, const bool LstSesAlt = true, const bool LstShtAlt = true, const bool LstFilAlt = true, const Sbecore::uint LstOgrNumFirstdisp = 1, const Sbecore::uint LstObjNumFirstdisp = 1, const Sbecore::uint LstSesNumFirstdisp = 1, const Sbecore::uint LstShtNumFirstdisp = 1, const Sbecore::uint LstFilNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzskNavGalery)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint LSTOGRAVAIL = 1;
		static const Sbecore::uint BUTOGRVIEWACTIVE = 2;
		static const Sbecore::uint LSTOBJAVAIL = 3;
		static const Sbecore::uint BUTOBJVIEWACTIVE = 4;
		static const Sbecore::uint LSTSESAVAIL = 5;
		static const Sbecore::uint BUTSESVIEWACTIVE = 6;
		static const Sbecore::uint LSTSHTAVAIL = 7;
		static const Sbecore::uint BUTSHTVIEWACTIVE = 8;
		static const Sbecore::uint LSTFILAVAIL = 9;
		static const Sbecore::uint BUTFILVIEWACTIVE = 10;

	public:
		StatShr(const bool LstOgrAvail = true, const bool ButOgrViewActive = true, const bool LstObjAvail = true, const bool ButObjViewActive = true, const bool LstSesAvail = true, const bool ButSesViewActive = true, const bool LstShtAvail = true, const bool ButShtViewActive = true, const bool LstFilAvail = true, const bool ButFilViewActive = true);

	public:
		bool LstOgrAvail;
		bool ButOgrViewActive;
		bool LstObjAvail;
		bool ButObjViewActive;
		bool LstSesAvail;
		bool ButSesViewActive;
		bool LstShtAvail;
		bool ButShtViewActive;
		bool LstFilAvail;
		bool ButFilViewActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskNavGalery)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskNavGaleryData)
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

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavGaleryDo)
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
		* DpchEngData (full: DpchEngWzskNavGaleryData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTFIL = 3;
		static const Sbecore::uint FEEDFLSTOBJ = 4;
		static const Sbecore::uint FEEDFLSTOGR = 5;
		static const Sbecore::uint FEEDFLSTSES = 6;
		static const Sbecore::uint FEEDFLSTSHT = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, Sbecore::Xmlio::Feed* feedFLstFil = NULL, Sbecore::Xmlio::Feed* feedFLstObj = NULL, Sbecore::Xmlio::Feed* feedFLstOgr = NULL, Sbecore::Xmlio::Feed* feedFLstSes = NULL, Sbecore::Xmlio::Feed* feedFLstSht = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		Sbecore::Xmlio::Feed feedFLstFil;
		Sbecore::Xmlio::Feed feedFLstObj;
		Sbecore::Xmlio::Feed feedFLstOgr;
		Sbecore::Xmlio::Feed feedFLstSes;
		Sbecore::Xmlio::Feed feedFLstSht;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalLstOgrAvail(DbsWzsk* dbswzsk);
	bool evalButOgrViewActive(DbsWzsk* dbswzsk);
	bool evalLstObjAvail(DbsWzsk* dbswzsk);
	bool evalButObjViewActive(DbsWzsk* dbswzsk);
	bool evalLstSesAvail(DbsWzsk* dbswzsk);
	bool evalButSesViewActive(DbsWzsk* dbswzsk);
	bool evalLstShtAvail(DbsWzsk* dbswzsk);
	bool evalButShtViewActive(DbsWzsk* dbswzsk);
	bool evalLstFilAvail(DbsWzsk* dbswzsk);
	bool evalButFilViewActive(DbsWzsk* dbswzsk);

public:
	PnlWzskNavGalery(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskNavGalery();

public:
	ContIac contiac;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstFil;
	Sbecore::Xmlio::Feed feedFLstObj;
	Sbecore::Xmlio::Feed feedFLstOgr;
	Sbecore::Xmlio::Feed feedFLstSes;
	Sbecore::Xmlio::Feed feedFLstSht;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstOgr(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshOgr(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshLstObj(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshObj(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshLstSes(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshSes(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshLstSht(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshSht(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
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

	void handleDpchAppDoButOgrViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButOgrNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButObjViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButObjNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButSesViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButSesNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButShtViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButShtNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButFilViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButFilNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskHusrRunvMod_crdUsrEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif

