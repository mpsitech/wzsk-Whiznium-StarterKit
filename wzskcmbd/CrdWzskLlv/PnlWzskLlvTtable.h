/**
	* \file PnlWzskLlvTtable.h
	* job handler for job PnlWzskLlvTtable (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef PNLWZSKLLVTTABLE_H
#define PNLWZSKLLVTTABLE_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskActServo.h"

#define VecVWzskLlvTtableDo PnlWzskLlvTtable::VecVDo

#define ContIacWzskLlvTtable PnlWzskLlvTtable::ContIac
#define ContInfWzskLlvTtable PnlWzskLlvTtable::ContInf
#define StatShrWzskLlvTtable PnlWzskLlvTtable::StatShr
#define TagWzskLlvTtable PnlWzskLlvTtable::Tag

#define DpchAppWzskLlvTtableData PnlWzskLlvTtable::DpchAppData
#define DpchAppWzskLlvTtableDo PnlWzskLlvTtable::DpchAppDo
#define DpchEngWzskLlvTtableData PnlWzskLlvTtable::DpchEngData

/**
	* PnlWzskLlvTtable
	*/
class PnlWzskLlvTtable : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskLlvTtableDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTMVECLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLlvTtable)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SLDTRG = 1;

	public:
		ContIac(const double SldTrg = 0.0);

	public:
		double SldTrg;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLlvTtable)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTSTE = 2;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtSte = "");

	public:
		bool ButClaimOn;
		std::string TxtSte;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatShr (full: StatShrWzskLlvTtable)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint SLDTRGMIN = 3;
		static const Sbecore::uint SLDTRGMAX = 4;
		static const Sbecore::uint BUTMVEACTIVE = 5;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const double SldTrgMin = 0, const double SldTrgMax = 360, const bool ButMveActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		double SldTrgMin;
		double SldTrgMax;
		bool ButMveActive;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskLlvTtable)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppData (full: DpchAppWzskLlvTtableData)
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
		* DpchAppDo (full: DpchAppWzskLlvTtableDo)
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
		* DpchEngData (full: DpchEngWzskLlvTtableData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;
		static const Sbecore::uint ALL = 6;

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

	bool evalButClaimActive(DbsWzsk* dbswzsk);
	bool evalButMveActive(DbsWzsk* dbswzsk);

public:
	PnlWzskLlvTtable(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskLlvTtable();

public:
	ContIac contiac;
	ContInf continf;
	StatShr statshr;

	JobWzskActServo* actservo;

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
	void handleDpchAppDataContiac(DbsWzsk* dbswzsk, ContIac* _contiac, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButRegularizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMinimizeClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButClaimClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButMveClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSgeChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskShrdatChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& srefInv);
	bool handleCallWzskClaimChg(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

};

#endif
