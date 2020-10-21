/**
	* \file PnlWzskPrsDetail.h
	* job handler for job PnlWzskPrsDetail (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef PNLWZSKPRSDETAIL_H
#define PNLWZSKPRSDETAIL_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskPrsDetailDo PnlWzskPrsDetail::VecVDo

#define ContIacWzskPrsDetail PnlWzskPrsDetail::ContIac
#define ContInfWzskPrsDetail PnlWzskPrsDetail::ContInf
#define StatAppWzskPrsDetail PnlWzskPrsDetail::StatApp
#define StatShrWzskPrsDetail PnlWzskPrsDetail::StatShr
#define TagWzskPrsDetail PnlWzskPrsDetail::Tag

#define DpchAppWzskPrsDetailData PnlWzskPrsDetail::DpchAppData
#define DpchAppWzskPrsDetailDo PnlWzskPrsDetail::DpchAppDo
#define DpchEngWzskPrsDetailData PnlWzskPrsDetail::DpchEngData

/**
	* PnlWzskPrsDetail
	*/
class PnlWzskPrsDetail : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskPrsDetailDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTSAVECLICK = 1;
		static const Sbecore::uint BUTJEDITCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrsDetail)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXFTIT = 1;
		static const Sbecore::uint TXFFNM = 2;
		static const Sbecore::uint NUMFPUPJ = 3;
		static const Sbecore::uint NUMSFLSTDRV = 4;
		static const Sbecore::uint NUMFPUPSEX = 5;
		static const Sbecore::uint TXFTEL = 6;
		static const Sbecore::uint TXFEML = 7;
		static const Sbecore::uint TXFSAL = 8;

	public:
		ContIac(const std::string& TxfTit = "", const std::string& TxfFnm = "", const Sbecore::uint numFPupJ = 1, const std::vector<Sbecore::uint>& numsFLstDrv = {}, const Sbecore::uint numFPupSex = 1, const std::string& TxfTel = "", const std::string& TxfEml = "", const std::string& TxfSal = "");

	public:
		std::string TxfTit;
		std::string TxfFnm;
		Sbecore::uint numFPupJ;
		std::vector<Sbecore::uint> numsFLstDrv;
		Sbecore::uint numFPupSex;
		std::string TxfTel;
		std::string TxfEml;
		std::string TxfSal;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskPrsDetail)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTLNM = 1;
		static const Sbecore::uint TXTDRV = 2;

	public:
		ContInf(const std::string& TxtLnm = "", const std::string& TxtDrv = "");

	public:
		std::string TxtLnm;
		std::string TxtDrv;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskPrsDetail)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstDrvAlt = true, const Sbecore::uint LstDrvNumFirstdisp = 1);
	};

	/**
		* StatShr (full: StatShrWzskPrsDetail)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTSAVEAVAIL = 1;
		static const Sbecore::uint BUTSAVEACTIVE = 2;
		static const Sbecore::uint TXFTITACTIVE = 3;
		static const Sbecore::uint TXFFNMACTIVE = 4;
		static const Sbecore::uint PUPJACTIVE = 5;
		static const Sbecore::uint BUTJEDITAVAIL = 6;
		static const Sbecore::uint TXTLNMACTIVE = 7;
		static const Sbecore::uint LSTDRVACTIVE = 8;
		static const Sbecore::uint PUPSEXACTIVE = 9;
		static const Sbecore::uint TXFTELACTIVE = 10;
		static const Sbecore::uint TXFEMLACTIVE = 11;
		static const Sbecore::uint TXFSALACTIVE = 12;

	public:
		StatShr(const bool ButSaveAvail = true, const bool ButSaveActive = true, const bool TxfTitActive = true, const bool TxfFnmActive = true, const bool PupJActive = true, const bool ButJEditAvail = true, const bool TxtLnmActive = true, const bool LstDrvActive = true, const bool PupSexActive = true, const bool TxfTelActive = true, const bool TxfEmlActive = true, const bool TxfSalActive = true);

	public:
		bool ButSaveAvail;
		bool ButSaveActive;
		bool TxfTitActive;
		bool TxfFnmActive;
		bool PupJActive;
		bool ButJEditAvail;
		bool TxtLnmActive;
		bool LstDrvActive;
		bool PupSexActive;
		bool TxfTelActive;
		bool TxfEmlActive;
		bool TxfSalActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskPrsDetail)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrsDetailData)
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
		* DpchAppDo (full: DpchAppWzskPrsDetailDo)
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
		* DpchEngData (full: DpchEngWzskPrsDetailData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFLSTDRV = 4;
		static const Sbecore::uint FEEDFPUPJ = 5;
		static const Sbecore::uint FEEDFPUPSEX = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;
		static const Sbecore::uint ALL = 10;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContIac* contiac = NULL, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFLstDrv = NULL, Sbecore::Xmlio::Feed* feedFPupJ = NULL, Sbecore::Xmlio::Feed* feedFPupSex = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFLstDrv;
		Sbecore::Xmlio::Feed feedFPupJ;
		Sbecore::Xmlio::Feed feedFPupSex;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButSaveAvail(DbsWzsk* dbswzsk);
	bool evalButSaveActive(DbsWzsk* dbswzsk);
	bool evalTxfTitActive(DbsWzsk* dbswzsk);
	bool evalTxfFnmActive(DbsWzsk* dbswzsk);
	bool evalPupJActive(DbsWzsk* dbswzsk);
	bool evalButJEditAvail(DbsWzsk* dbswzsk);
	bool evalTxtLnmActive(DbsWzsk* dbswzsk);
	bool evalLstDrvActive(DbsWzsk* dbswzsk);
	bool evalPupSexActive(DbsWzsk* dbswzsk);
	bool evalTxfTelActive(DbsWzsk* dbswzsk);
	bool evalTxfEmlActive(DbsWzsk* dbswzsk);
	bool evalTxfSalActive(DbsWzsk* dbswzsk);

public:
	PnlWzskPrsDetail(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskPrsDetail();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFLstDrv;
	Sbecore::Xmlio::Feed feedFPupJ;
	Sbecore::Xmlio::Feed feedFPupSex;

	WzskMPerson recPrs;

	WzskJMPersonLastname recPrsJlnm;

	bool dirty;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refreshJ(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshTxtDrv(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void refreshRecPrs(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);
	void refreshRecPrsJlnm(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

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

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskPrsJlnmMod_prsEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskPrsUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

};

#endif

