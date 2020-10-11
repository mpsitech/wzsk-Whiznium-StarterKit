/**
	* \file PnlWzskFilDetail.h
	* job handler for job PnlWzskFilDetail (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKFILDETAIL_H
#define PNLWZSKFILDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskFilDetailDo PnlWzskFilDetail::VecVDo

#define ContIacWzskFilDetail PnlWzskFilDetail::ContIac
#define ContInfWzskFilDetail PnlWzskFilDetail::ContInf
#define StatAppWzskFilDetail PnlWzskFilDetail::StatApp
#define StatShrWzskFilDetail PnlWzskFilDetail::StatShr
#define TagWzskFilDetail PnlWzskFilDetail::Tag

#define DpchAppWzskFilDetailData PnlWzskFilDetail::DpchAppData
#define DpchAppWzskFilDetailDo PnlWzskFilDetail::DpchAppDo
#define DpchEngWzskFilDetailData PnlWzskFilDetail::DpchEngData

/**
	* PnlWzskFilDetail
	*/
class PnlWzskFilDetail : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskFilDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTCLUVIEWCLICK = 2;
		static const Sbecore::uint BUTCLUCLUSTERCLICK = 3;
		static const Sbecore::uint BUTCLUUNCLUSTERCLICK = 4;
		static const Sbecore::uint BUTREUVIEWCLICK = 5;
		static const Sbecore::uint BUTCNTEDITCLICK = 6;
		static const Sbecore::uint BUTMIMEDITCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskFilDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFFNM = 1;
		static const Sbecore::uint NUMFLSTCLU = 2;
		static const Sbecore::uint NUMFPUPRET = 3;
		static const Sbecore::uint NUMFPUPCNT = 4;
		static const Sbecore::uint TXFCNT = 5;
		static const Sbecore::uint TXFACV = 6;
		static const Sbecore::uint TXFANM = 7;
		static const Sbecore::uint NUMFPUPMIM = 8;
		static const Sbecore::uint TXFMIM = 9;
		static const Sbecore::uint TXFSIZ = 10;
		static const Sbecore::uint TXFCMT = 11;

	public:
		ContIac(const std::string& TxfFnm = "", const Sbecore::uint numFLstClu = 1, const Sbecore::uint numFPupRet = 1, const Sbecore::uint numFPupCnt = 1, const std::string& TxfCnt = "", const std::string& TxfAcv = "", const std::string& TxfAnm = "", const Sbecore::uint numFPupMim = 1, const std::string& TxfMim = "", const std::string& TxfSiz = "", const std::string& TxfCmt = "");

	public:
		std::string TxfFnm;
		Sbecore::uint numFLstClu;
		Sbecore::uint numFPupRet;
		Sbecore::uint numFPupCnt;
		std::string TxfCnt;
		std::string TxfAcv;
		std::string TxfAnm;
		Sbecore::uint numFPupMim;
		std::string TxfMim;
		std::string TxfSiz;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskFilDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTCLU = 1;
		static const Sbecore::uint TXTREU = 2;

	public:
		ContInf(const std::string& TxtClu = "", const std::string& TxtReu = "");

	public:
		std::string TxtClu;
		std::string TxtReu;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskFilDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstCluAlt = true, const bool PupCntAlt = false, const bool PupMimAlt = false, const Sbecore::uint LstCluNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzskFilDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFCNTVALID = 1;
		static const Sbecore::uint TXFMIMVALID = 2;
		static const Sbecore::uint BUTSAVEAVAIL = 3;
		static const Sbecore::uint BUTSAVEACTIVE = 4;
		static const Sbecore::uint TXFFNMACTIVE = 5;
		static const Sbecore::uint LSTCLUACTIVE = 6;
		static const Sbecore::uint BUTCLUVIEWACTIVE = 7;
		static const Sbecore::uint BUTCLUCLUSTERAVAIL = 8;
		static const Sbecore::uint BUTCLUUNCLUSTERAVAIL = 9;
		static const Sbecore::uint TXTREUACTIVE = 10;
		static const Sbecore::uint BUTREUVIEWAVAIL = 11;
		static const Sbecore::uint BUTREUVIEWACTIVE = 12;
		static const Sbecore::uint PUPCNTACTIVE = 13;
		static const Sbecore::uint BUTCNTEDITAVAIL = 14;
		static const Sbecore::uint TXFACVACTIVE = 15;
		static const Sbecore::uint TXFANMACTIVE = 16;
		static const Sbecore::uint PUPMIMACTIVE = 17;
		static const Sbecore::uint BUTMIMEDITAVAIL = 18;
		static const Sbecore::uint TXFSIZACTIVE = 19;
		static const Sbecore::uint TXFCMTACTIVE = 20;

	public:
		StatShr(const bool TxfCntValid = false, const bool TxfMimValid = false, const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfFnmActive = true, const bool LstCluActive = true, const bool ButCluViewActive = true, const bool ButCluClusterAvail = true, const bool ButCluUnclusterAvail = true, const bool TxtReuActive = true, const bool ButReuViewAvail = true, const bool ButReuViewActive = true, const bool PupCntActive = true, const bool ButCntEditAvail = true, const bool TxfAcvActive = true, const bool TxfAnmActive = true, const bool PupMimActive = true, const bool ButMimEditAvail = true, const bool TxfSizActive = true, const bool TxfCmtActive = true);

	public:
		bool TxfCntValid;
		bool TxfMimValid;
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfFnmActive;
		bool LstCluActive;
		bool ButCluViewActive;
		bool ButCluClusterAvail;
		bool ButCluUnclusterAvail;
		bool TxtReuActive;
		bool ButReuViewAvail;
		bool ButReuViewActive;
		bool PupCntActive;
		bool ButCntEditAvail;
		bool TxfAcvActive;
		bool TxfAnmActive;
		bool PupMimActive;
		bool ButMimEditAvail;
		bool TxfSizActive;
		bool TxfCmtActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskFilDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskFilDetailData)
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
		* DpchAppDo (full: DpchAppWzskFilDetailDo)
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
		* DpchEngData (full: DpchEngWzskFilDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTCLU = 4;
		static const Sbecore::uint FEEDFPUPCNT = 5;
		static const Sbecore::uint FEEDFPUPMIM = 6;
		static const Sbecore::uint FEEDFPUPRET = 7;
		static const Sbecore::uint STATAPP = 8;
		static const Sbecore::uint STATSHR = 9;
		static const Sbecore::uint TAG = 10;
		static const Sbecore::uint ALL = 11;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstClu = NULL, Sbecore::Xmlio::Feed* feedFPupCnt = NULL, Sbecore::Xmlio::Feed* feedFPupMim = NULL, Sbecore::Xmlio::Feed* feedFPupRet = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstClu;
		Sbecore::Xmlio::Feed feedFPupCnt;
		Sbecore::Xmlio::Feed feedFPupMim;
		Sbecore::Xmlio::Feed feedFPupRet;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzsk* dbswzsk);
	bool evalButSaveActive(DbsWzsk* dbswzsk);
	bool evalTxfFnmActive(DbsWzsk* dbswzsk);
	bool evalLstCluActive(DbsWzsk* dbswzsk);
	bool evalButCluViewActive(DbsWzsk* dbswzsk);
	bool evalButCluClusterAvail(DbsWzsk* dbswzsk);
	bool evalButCluUnclusterAvail(DbsWzsk* dbswzsk);
	bool evalTxtReuActive(DbsWzsk* dbswzsk);
	bool evalButReuViewAvail(DbsWzsk* dbswzsk);
	bool evalButReuViewActive(DbsWzsk* dbswzsk);
	bool evalPupCntActive(DbsWzsk* dbswzsk);
	bool evalButCntEditAvail(DbsWzsk* dbswzsk);
	bool evalTxfAcvActive(DbsWzsk* dbswzsk);
	bool evalTxfAnmActive(DbsWzsk* dbswzsk);
	bool evalPupMimActive(DbsWzsk* dbswzsk);
	bool evalButMimEditAvail(DbsWzsk* dbswzsk);
	bool evalTxfSizActive(DbsWzsk* dbswzsk);
	bool evalTxfCmtActive(DbsWzsk* dbswzsk);

public:
	PnlWzskFilDetail(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskFilDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstClu;
	Sbecore::Xmlio::Feed feedFPupCnt;
	Sbecore::Xmlio::Feed feedFPupMim;
	Sbecore::Xmlio::Feed feedFPupRet;

	WzskMFile recFil;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshLstClu(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshClu(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshPupCnt(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshTxfCnt(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshCnt(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshPupMim(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshTxfMim(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshMim(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refreshRecFil(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButSaveClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButCluViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButCluClusterClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButCluUnclusterClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButReuViewClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButCntEditClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMimEditClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskFilMod_cluEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskKlsAkeyMod_klsEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWzskFilUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskFil_reuEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool handleCallWzskFil_retEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, bool& boolvalRet);
	bool handleCallWzskFil_cluEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::ubigint refInv, bool& boolvalRet);

};

#endif

