/**
	* \file PnlWzskShtHeadbar.h
	* job handler for job PnlWzskShtHeadbar (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef PNLWZSKSHTHEADBAR_H
#define PNLWZSKSHTHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StgInfWzskShtHeadbar PnlWzskShtHeadbar::StgInf
#define TagWzskShtHeadbar PnlWzskShtHeadbar::Tag

#define DpchEngWzskShtHeadbarData PnlWzskShtHeadbar::DpchEngData

/**
	* PnlWzskShtHeadbar
	*/
class PnlWzskShtHeadbar : public JobWzsk {

public:
	/**
		* StgInf (full: StgInfWzskShtHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWzskShtHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWzskShtHeadbarData)
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
	PnlWzskShtHeadbar(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskShtHeadbar();

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

