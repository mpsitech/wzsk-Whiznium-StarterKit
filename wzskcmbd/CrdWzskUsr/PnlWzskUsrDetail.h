/**
	* \file PnlWzskUsrDetail.h
	* job handler for job PnlWzskUsrDetail (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef PNLWZSKUSRDETAIL_H
#define PNLWZSKUSRDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskUsrDetailDo PnlWzskUsrDetail::VecVDo

#define ContIacWzskUsrDetail PnlWzskUsrDetail::ContIac
#define ContInfWzskUsrDetail PnlWzskUsrDetail::ContInf
#define StatAppWzskUsrDetail PnlWzskUsrDetail::StatApp
#define StatShrWzskUsrDetail PnlWzskUsrDetail::StatShr
#define TagWzskUsrDetail PnlWzskUsrDetail::Tag

#define DpchAppWzskUsrDetailData PnlWzskUsrDetail::DpchAppData
#define DpchAppWzskUsrDetailDo PnlWzskUsrDetail::DpchAppDo
#define DpchEngWzskUsrDetailData PnlWzskUsrDetail::DpchEngData

/**
	* PnlWzskUsrDetail
	*/
class PnlWzskUsrDetail : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskUsrDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTPRSVIEWCLICK = 2;
		static const Sbecore::uint BUTUSGVIEWCLICK = 3;
		static const Sbecore::uint BUTJEDITCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskUsrDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPJ = 1;
		static const Sbecore::uint NUMFPUPSTE = 2;
		static const Sbecore::uint NUMFPUPLCL = 3;
		static const Sbecore::uint NUMFPUPULV = 4;
		static const Sbecore::uint TXFPWD = 5;
		static const Sbecore::uint TXFFKY = 6;
		static const Sbecore::uint TXFCMT = 7;

	public:
		ContIac(const Sbecore::uint numFPupJ = 1, const Sbecore::uint numFPupSte = 1, const Sbecore::uint numFPupLcl = 1, const Sbecore::uint numFPupUlv = 1, const std::string& TxfPwd = "", const std::string& TxfFky = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupJ;
		Sbecore::uint numFPupSte;
		Sbecore::uint numFPupLcl;
		Sbecore::uint numFPupUlv;
		std::string TxfPwd;
		std::string TxfFky;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskUsrDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTPRS = 1;
		static const Sbecore::uint TXTSRF = 2;
		static const Sbecore::uint TXTUSG = 3;

	public:
		ContInf(const std::string& TxtPrs = "", const std::string& TxtSrf = "", const std::string& TxtUsg = "");

	public:
		std::string TxtPrs;
		std::string TxtSrf;
		std::string TxtUsg;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskUsrDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzskUsrDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXTPRSACTIVE = 3;
		static const Sbecore::uint BUTPRSVIEWAVAIL = 4;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 5;
		static const Sbecore::uint TXTSRFACTIVE = 6;
		static const Sbecore::uint TXTUSGACTIVE = 7;
		static const Sbecore::uint BUTUSGVIEWAVAIL = 8;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 9;
		static const Sbecore::uint PUPJACTIVE = 10;
		static const Sbecore::uint BUTJEDITAVAIL = 11;
		static const Sbecore::uint PUPSTEACTIVE = 12;
		static const Sbecore::uint PUPLCLACTIVE = 13;
		static const Sbecore::uint PUPULVACTIVE = 14;
		static const Sbecore::uint TXFPWDACTIVE = 15;
		static const Sbecore::uint TXFFKYACTIVE = 16;
		static const Sbecore::uint TXFCMTACTIVE = 17;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxtPrsActive = true, const bool ButPrsViewAvail = true, const bool ButPrsViewActive = true, const bool TxtSrfActive = true, const bool TxtUsgActive = true, const bool ButUsgViewAvail = true, const bool ButUsgViewActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool PupSteActive = true, const bool PupLclActive = true, const bool PupUlvActive = true, const bool TxfPwdActive = true, const bool TxfFkyActive = true, const bool TxfCmtActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxtPrsActive;
		bool ButPrsViewAvail;
		bool ButPrsViewActive;
		bool TxtSrfActive;
		bool TxtUsgActive;
		bool ButUsgViewAvail;
		bool ButUsgViewActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool PupSteActive;
		bool PupLclActive;
		bool PupUlvActive;
		bool TxfPwdActive;
		bool TxfFkyActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskUsrDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskUsrDetailData)
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
		* DpchAppDo (full: DpchAppWzskUsrDetailDo)
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
		* DpchEngData (full: DpchEngWzskUsrDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPJ = 4;
		static const Sbecore::uint FEEDFPUPLCL = 5;
		static const Sbecore::uint FEEDFPUPSTE = 6;
		static const Sbecore::uint FEEDFPUPULV = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFPupJ = NULL, Sbecore::Xmlio::Feed* feedFPupLcl = NULL, Sbecore::Xmlio::Feed* feedFPupSte = NULL, Sbecore::Xmlio::Feed* feedFPupUlv = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupJ;
		Sbecore::Xmlio::Feed feedFPupLcl;
		Sbecore::Xmlio::Feed feedFPupSte;
		Sbecore::Xmlio::Feed feedFPupUlv;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzsk* dbswzsk);
	bool evalButSaveActive(DbsWzsk* dbswzsk);
	bool evalTxtPrsActive(DbsWzsk* dbswzsk);
	bool evalButPrsViewAvail(DbsWzsk* dbswzsk);
	bool evalButPrsViewActive(DbsWzsk* dbswzsk);
	bool evalTxtSrfActive(DbsWzsk* dbswzsk);
	bool evalTxtUsgActive(DbsWzsk* dbswzsk);
	bool evalButUsgViewAvail(DbsWzsk* dbswzsk);
	bool evalButUsgViewActive(DbsWzsk* dbswzsk);
	bool evalPupJActive(DbsWzsk* dbswzsk);
	bool evalButJEditAvail(DbsWzsk* dbswzsk);
	bool evalPupSteActive(DbsWzsk* dbswzsk);
	bool evalPupLclActive(DbsWzsk* dbswzsk);
	bool evalPupUlvActive(DbsWzsk* dbswzsk);
	bool evalTxfPwdActive(DbsWzsk* dbswzsk);
	bool evalTxfFkyActive(DbsWzsk* dbswzsk);
	bool evalTxfCmtActive(DbsWzsk* dbswzsk);

public:
	PnlWzskUsrDetail(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskUsrDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFPupJ;
	Sbecore::Xmlio::Feed feedFPupLcl;
	Sbecore::Xmlio::Feed feedFPupSte;
	Sbecore::Xmlio::Feed feedFPupUlv;

	WzskMUser recUsr;

	WzskJMUserState recUsrJste;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJ(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refreshRecUsr(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshRecUsrJste(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPrsViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButUsgViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButJEditClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskUsrJsteMod_usrEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskUsrUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskUsr_usgEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzskUsr_prsEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

