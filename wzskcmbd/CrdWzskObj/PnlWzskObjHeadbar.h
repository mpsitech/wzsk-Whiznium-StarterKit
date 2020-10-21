/**
	* \file PnlWzskObjHeadbar.h
	* job handler for job PnlWzskObjHeadbar (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

#ifndef PNLWZSKOBJHEADBAR_H
#define PNLWZSKOBJHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWzskObjHeadbar PnlWzskObjHeadbar::StgInf
#define TagWzskObjHeadbar PnlWzskObjHeadbar::Tag

#define DpchEngWzskObjHeadbarData PnlWzskObjHeadbar::DpchEngData

/**
	* PnlWzskObjHeadbar
	*/
class PnlWzskObjHeadbar : public JobWzsk {

public:
	/**
		* StgInf (full: StgInfWzskObjHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWzskObjHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWzskObjHeadbarData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STGINF = 2;
		static const Sbecore::uint TAG = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	PnlWzskObjHeadbar(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskObjHeadbar();

public:

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

};

#endif

