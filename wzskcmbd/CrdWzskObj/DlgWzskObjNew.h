/**
	* \file DlgWzskObjNew.h
	* job handler for job DlgWzskObjNew (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef DLGWZSKOBJNEW_H
#define DLGWZSKOBJNEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWzskObjNewDo DlgWzskObjNew::VecVDo
#define VecVDlgWzskObjNewSge DlgWzskObjNew::VecVSge

#define ContIacDlgWzskObjNew DlgWzskObjNew::ContIac
#define ContInfDlgWzskObjNew DlgWzskObjNew::ContInf
#define StatAppDlgWzskObjNew DlgWzskObjNew::StatApp
#define StatShrDlgWzskObjNew DlgWzskObjNew::StatShr
#define TagDlgWzskObjNew DlgWzskObjNew::Tag

#define DpchAppDlgWzskObjNewData DlgWzskObjNew::DpchAppData
#define DpchAppDlgWzskObjNewDo DlgWzskObjNew::DpchAppDo
#define DpchEngDlgWzskObjNewData DlgWzskObjNew::DpchEngData

/**
	* DlgWzskObjNew
	*/
class DlgWzskObjNew : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVDlgWzskObjNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWzskObjNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContIac (full: ContIacDlgWzskObjNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPOGR = 1;
		static const Sbecore::uint TXFTIT = 2;
		static const Sbecore::uint TXFCMT = 3;

	public:
		ContIac(const Sbecore::uint numFPupOgr = 1, const std::string& TxfTit = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupOgr;
		std::string TxfTit;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWzskObjNew)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWzskObjNew)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* StatShr (full: StatShrDlgWzskObjNew)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCNCACTIVE = 1;
		static const Sbecore::uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagDlgWzskObjNew)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppDlgWzskObjNewData)
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
		* DpchAppDo (full: DpchAppDlgWzskObjNewDo)
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
		* DpchEngData (full: DpchEngDlgWzskObjNewData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPOGR = 4;
		static const Sbecore::uint FEEDFSGE = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;
		static const Sbecore::uint ALL = 9;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupOgr = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupOgr;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButCncActive(DbsWzsk* dbswzsk);
	bool evalButCreActive(DbsWzsk* dbswzsk);

public:
	DlgWzskObjNew(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~DlgWzskObjNew();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupOgr;
	Sbecore::Xmlio::Feed feedFSge;

	bool valid;

	// IP vars.cust --- INSERT

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

	void handleDpchAppDoButCncClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButCreClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge, DpchEngWzsk** dpcheng = NULL);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeCreate(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeCreate(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeDone(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeDone(DbsWzsk* dbswzsk);

};

#endif
