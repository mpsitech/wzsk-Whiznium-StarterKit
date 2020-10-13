/**
	* \file PnlWzskLiv3DView.h
	* job handler for job PnlWzskLiv3DView (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef PNLWZSKLIV3DVIEW_H
#define PNLWZSKLIV3DVIEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqPtcloud.h"

#define VecVWzskLiv3DViewDo PnlWzskLiv3DView::VecVDo

#define ContIacWzskLiv3DView PnlWzskLiv3DView::ContIac
#define ContInfWzskLiv3DView PnlWzskLiv3DView::ContInf
#define StatAppWzskLiv3DView PnlWzskLiv3DView::StatApp
#define StatShrWzskLiv3DView PnlWzskLiv3DView::StatShr
#define TagWzskLiv3DView PnlWzskLiv3DView::Tag

#define DpchAppWzskLiv3DViewData PnlWzskLiv3DView::DpchAppData
#define DpchAppWzskLiv3DViewDo PnlWzskLiv3DView::DpchAppDo
#define DpchEngWzskLiv3DViewData PnlWzskLiv3DView::DpchEngData
#define DpchEngWzskLiv3DViewLive PnlWzskLiv3DView::DpchEngLive

/**
	* PnlWzskLiv3DView
	*/
class PnlWzskLiv3DView : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskLiv3DViewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTASRCLICK = 4;
		static const Sbecore::uint BUTAIRCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLiv3DView)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SLDAIN = 1;

	public:
		ContIac(const double SldAin = 0.0);

	public:
		double SldAin;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLiv3DView)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTAST = 2;
		static const Sbecore::uint TXTAOA = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtAst = "", const std::string& TxtAoa = "");

	public:
		bool ButClaimOn;
		std::string TxtAst;
		std::string TxtAoa;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskLiv3DView)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const bool ButPlayActive = true, const bool ButStopActive = true);
	};

	/**
		* StatShr (full: StatShrWzskLiv3DView)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint SLDTREHMIN = 3;
		static const Sbecore::uint SLDTREHMAX = 4;
		static const Sbecore::uint SLDTREVMIN = 5;
		static const Sbecore::uint SLDTREVMAX = 6;
		static const Sbecore::uint SLDAINACTIVE = 7;
		static const Sbecore::uint SLDAINMIN = 8;
		static const Sbecore::uint SLDAINMAX = 9;
		static const Sbecore::uint SLDAINRAST = 10;
		static const Sbecore::uint TXTAOAAVAIL = 11;
		static const Sbecore::uint BUTASRACTIVE = 12;
		static const Sbecore::uint BUTAIRACTIVE = 13;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const double SldTreHMin = 0.0, const double SldTreHMax = 1.0, const double SldTreVMin = 0.0, const double SldTreVMax = 1.0, const bool SldAinActive = true, const double SldAinMin = 3.0, const double SldAinMax = 60.0, const double SldAinRast = 0.5, const bool TxtAoaAvail = true, const bool ButAsrActive = true, const bool ButAirActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		double SldTreHMin;
		double SldTreHMax;
		double SldTreVMin;
		double SldTreVMax;
		bool SldAinActive;
		double SldAinMin;
		double SldAinMax;
		double SldAinRast;
		bool TxtAoaAvail;
		bool ButAsrActive;
		bool ButAirActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLiv3DView)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskLiv3DViewData)
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
		* DpchAppDo (full: DpchAppWzskLiv3DViewDo)
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
		* DpchEngData (full: DpchEngWzskLiv3DViewData)
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

	/**
		* DpchEngLive (full: DpchEngWzskLiv3DViewLive)
		*/
	class DpchEngLive : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint RNOTL = 2;
		static const Sbecore::uint X = 3;
		static const Sbecore::uint Y = 4;
		static const Sbecore::uint Z = 5;
		static const Sbecore::uint ALL = 6;

	public:
		DpchEngLive(const Sbecore::ubigint jref = 0, const std::vector<bool>& rNotL = {}, const std::vector<float>& x = {}, const std::vector<float>& y = {}, const std::vector<float>& z = {}, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		std::vector<bool> rNotL;
		std::vector<float> x;
		std::vector<float> y;
		std::vector<float> z;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalSldAinActive(DbsWzsk* dbswzsk);
	bool evalTxtAoaAvail(DbsWzsk* dbswzsk);
	bool evalButAsrActive(DbsWzsk* dbswzsk);
	bool evalButAirActive(DbsWzsk* dbswzsk);

public:
	PnlWzskLiv3DView(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLiv3DView();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	JobWzskAcqPtcloud* acqptcloud;

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

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButClaimClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButAsrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButAirClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskShrdatChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskResultNew(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskClaimChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

};

#endif

