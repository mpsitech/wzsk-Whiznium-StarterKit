/**
	* \file PnlWzskOgrDetail.h
	* job handler for job PnlWzskOgrDetail (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKOGRDETAIL_H
#define PNLWZSKOGRDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskOgrDetailDo PnlWzskOgrDetail::VecVDo

#define ContIacWzskOgrDetail PnlWzskOgrDetail::ContIac
#define ContInfWzskOgrDetail PnlWzskOgrDetail::ContInf
#define StatAppWzskOgrDetail PnlWzskOgrDetail::StatApp
#define StatShrWzskOgrDetail PnlWzskOgrDetail::StatShr
#define TagWzskOgrDetail PnlWzskOgrDetail::Tag

#define DpchAppWzskOgrDetailData PnlWzskOgrDetail::DpchAppData
#define DpchAppWzskOgrDetailDo PnlWzskOgrDetail::DpchAppDo
#define DpchEngWzskOgrDetailData PnlWzskOgrDetail::DpchEngData

/**
	* PnlWzskOgrDetail
	*/
class PnlWzskOgrDetail : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskOgrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;
		static const Sbecore::uint BUTSUPVIEWCLICK = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskOgrDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJ = 1;
		static const Sbecore::uint TXFCMT = 2;

	public:
		ContIac(const Sbecore::uint numFPupJ = 1, const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJ;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskOgrDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTTIT = 2;
		static const Sbecore::uint TXTSUP = 3;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtTit = "", const std::string& TxtSup = "");

	public:
		std::string TxtSrf;
		std::string TxtTit;
		std::string TxtSup;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskOgrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzskOgrDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTSRFACTIVE = 3;
		static const Sbecore::uint PUPJACTIVE = 4;
		static const Sbecore::uint BUTJEDITAVAIL = 5;
		static const Sbecore::uint TXTTITACTIVE = 6;
		static const Sbecore::uint TXTSUPACTIVE = 7;
		static const Sbecore::uint BUTSUPVIEWAVAIL = 8;
		static const Sbecore::uint BUTSUPVIEWACTIVE = 9;
		static const Sbecore::uint TXFCMTACTIVE = 10;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtSrfActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtTitActive = true, const bool TxtSupActive = true, const bool ButSupViewAvail = true, const bool ButSupViewActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtSrfActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtTitActive;
		bool TxtSupActive;
		bool ButSupViewAvail;
		bool ButSupViewActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskOgrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskOgrDetailData)
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
		* DpchAppDo (full: DpchAppWzskOgrDetailDo)
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
		* DpchEngData (full: DpchEngWzskOgrDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJ = 4;
		static const Sbecore::uint STATAPP = 5;
		static const Sbecore::uint STATSHR = 6;
		static const Sbecore::uint TAG = 7;
		static const Sbecore::uint ALL = 8;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupJ = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJ;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzsk* dbswzsk);
	bool evalButSaveActive(DbsWzsk* dbswzsk);
	bool evalTxtSrfActive(DbsWzsk* dbswzsk);
	bool evalPupJActive(DbsWzsk* dbswzsk);
	bool evalButJEditAvail(DbsWzsk* dbswzsk);
	bool evalTxtTitActive(DbsWzsk* dbswzsk);
	bool evalTxtSupActive(DbsWzsk* dbswzsk);
	bool evalButSupViewAvail(DbsWzsk* dbswzsk);
	bool evalButSupViewActive(DbsWzsk* dbswzsk);
	bool evalTxfCmtActive(DbsWzsk* dbswzsk);

public:
	PnlWzskOgrDetail(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskOgrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupJ;

	WzskMObjgroup recOgr;

	WzskJMObjgroupTitle recOgrJtit;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJ(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refreshRecOgr(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshRecOgrJtit(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButJEditClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButSupViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskOgrJtitMod_ogrEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskOgrUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskOgr_supEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

