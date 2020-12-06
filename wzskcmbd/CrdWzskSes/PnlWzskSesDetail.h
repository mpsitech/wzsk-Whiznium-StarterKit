/**
	* \file PnlWzskSesDetail.h
	* job handler for job PnlWzskSesDetail (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKSESDETAIL_H
#define PNLWZSKSESDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskSesDetailDo PnlWzskSesDetail::VecVDo

#define ContIacWzskSesDetail PnlWzskSesDetail::ContIac
#define ContInfWzskSesDetail PnlWzskSesDetail::ContInf
#define StatAppWzskSesDetail PnlWzskSesDetail::StatApp
#define StatShrWzskSesDetail PnlWzskSesDetail::StatShr
#define TagWzskSesDetail PnlWzskSesDetail::Tag

#define DpchAppWzskSesDetailData PnlWzskSesDetail::DpchAppData
#define DpchAppWzskSesDetailDo PnlWzskSesDetail::DpchAppDo
#define DpchEngWzskSesDetailData PnlWzskSesDetail::DpchEngData

/**
	* PnlWzskSesDetail
	*/
class PnlWzskSesDetail : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskSesDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTUSRVIEWCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskSesDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFSTA = 1;
		static const Sbecore::uint TXFSTO = 2;
		static const Sbecore::uint TXFIP = 3;

	public:
		ContIac(const std::string& TxfSta = "", const std::string& TxfSto = "", const std::string& TxfIp = "");

	public:
		std::string TxfSta;
		std::string TxfSto;
		std::string TxfIp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskSesDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTUSR = 1;

	public:
		ContInf(const std::string& TxtUsr = "");

	public:
		std::string TxtUsr;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskSesDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzskSesDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTUSRACTIVE = 3;
		static const Sbecore::uint BUTUSRVIEWAVAIL = 4;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 5;
		static const Sbecore::uint TXFSTAACTIVE = 6;
		static const Sbecore::uint TXFSTOACTIVE = 7;
		static const Sbecore::uint TXFIPACTIVE = 8;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtUsrActive = true, const bool ButUsrViewAvail = true, const bool ButUsrViewActive = true, const bool TxfStaActive = true, const bool TxfStoActive = true, const bool TxfIpActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtUsrActive;
		bool ButUsrViewAvail;
		bool ButUsrViewActive;
		bool TxfStaActive;
		bool TxfStoActive;
		bool TxfIpActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskSesDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskSesDetailData)
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
		* DpchAppDo (full: DpchAppWzskSesDetailDo)
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
		* DpchEngData (full: DpchEngWzskSesDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzsk* dbswzsk);
	bool evalButSaveActive(DbsWzsk* dbswzsk);
	bool evalTxtUsrActive(DbsWzsk* dbswzsk);
	bool evalButUsrViewAvail(DbsWzsk* dbswzsk);
	bool evalButUsrViewActive(DbsWzsk* dbswzsk);
	bool evalTxfStaActive(DbsWzsk* dbswzsk);
	bool evalTxfStoActive(DbsWzsk* dbswzsk);
	bool evalTxfIpActive(DbsWzsk* dbswzsk);

public:
	PnlWzskSesDetail(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskSesDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	WzskMSession recSes;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshRecSes(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButUsrViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSesUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskSes_usrEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif
