/**
	* \file PnlWzskLiv3DView.h
	* job handler for job PnlWzskLiv3DView (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef PNLWZSKLIV3DVIEW_H
#define PNLWZSKLIV3DVIEW_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqPtcloud.h"

#define VecVWzskLiv3DViewDo PnlWzskLiv3DView::VecVDo

#define ContInfWzskLiv3DView PnlWzskLiv3DView::ContInf
#define StatShrWzskLiv3DView PnlWzskLiv3DView::StatShr
#define TagWzskLiv3DView PnlWzskLiv3DView::Tag

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
		static const Sbecore::uint BUTPLAYCLICK = 4;
		static const Sbecore::uint BUTSTOPCLICK = 5;
		static const Sbecore::uint BUTASTCLICK = 6;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
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
		static const Sbecore::uint BUTPLAYACTIVE = 7;
		static const Sbecore::uint BUTSTOPACTIVE = 8;
		static const Sbecore::uint TXTAOAAVAIL = 9;
		static const Sbecore::uint BUTASTACTIVE = 10;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const double SldTreHMin = 0.0, const double SldTreHMax = 1.0, const double SldTreVMin = 0.0, const double SldTreVMax = 1.0, const bool ButPlayActive = true, const bool ButStopActive = true, const bool TxtAoaAvail = true, const bool ButAstActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		double SldTreHMin;
		double SldTreHMax;
		double SldTreVMin;
		double SldTreVMax;
		bool ButPlayActive;
		bool ButStopActive;
		bool TxtAoaAvail;
		bool ButAstActive;

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
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
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
	bool evalButPlayActive(DbsWzsk* dbswzsk);
	bool evalButStopActive(DbsWzsk* dbswzsk);
	bool evalTxtAoaAvail(DbsWzsk* dbswzsk);
	bool evalButAstActive(DbsWzsk* dbswzsk);

public:
	PnlWzskLiv3DView(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLiv3DView();

public:
	ContInf continf;
	StatShr statshr;

	JobWzskAcqPtcloud* acqptcloud;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButClaimClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButPlayClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButStopClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButAstClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskClaimChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskResultNewFromAcqptcloud(DbsWzsk* dbswzsk, const Sbecore::uint ixInv, const std::string& srefInv);

};

#endif

