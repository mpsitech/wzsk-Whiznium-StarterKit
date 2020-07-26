/**
	* \file PnlWzskNavOp.h
	* job handler for job PnlWzskNavOp (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef PNLWZSKNAVOP_H
#define PNLWZSKNAVOP_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVWzskNavOpDo PnlWzskNavOp::VecVDo

#define StatAppWzskNavOp PnlWzskNavOp::StatApp
#define StatShrWzskNavOp PnlWzskNavOp::StatShr
#define TagWzskNavOp PnlWzskNavOp::Tag

#define DpchAppWzskNavOpDo PnlWzskNavOp::DpchAppDo
#define DpchEngWzskNavOpData PnlWzskNavOp::DpchEngData

/**
	* PnlWzskNavOp
	*/
class PnlWzskNavOp : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskNavOpDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTLLVNEWCRDCLICK = 1;
		static const Sbecore::uint BUTLIVNEWCRDCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* StatApp (full: StatAppWzskNavOp)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);
	};

	/**
		* StatShr (full: StatShrWzskNavOp)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTLLVNEWCRDAVAIL = 1;
		static const Sbecore::uint BUTLIVNEWCRDAVAIL = 2;

	public:
		StatShr(const bool ButLlvNewcrdAvail = true, const bool ButLivNewcrdAvail = true);

	public:
		bool ButLlvNewcrdAvail;
		bool ButLivNewcrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskNavOp)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavOpDo)
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
		* DpchEngData (full: DpchEngWzskNavOpData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATAPP = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalButLlvNewcrdAvail(DbsWzsk* dbswzsk);
	bool evalButLivNewcrdAvail(DbsWzsk* dbswzsk);

public:
	PnlWzskNavOp(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskNavOp();

public:
	StatShr statshr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems);

	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButLlvNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoButLivNewcrdClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

};

#endif
