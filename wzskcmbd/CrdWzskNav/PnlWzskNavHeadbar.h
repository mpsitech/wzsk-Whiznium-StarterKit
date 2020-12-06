/**
	* \file PnlWzskNavHeadbar.h
	* job handler for job PnlWzskNavHeadbar (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVHEADBAR_H
#define PNLWZSKNAVHEADBAR_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define StatShrWzskNavHeadbar PnlWzskNavHeadbar::StatShr
#define StgInfWzskNavHeadbar PnlWzskNavHeadbar::StgInf
#define TagWzskNavHeadbar PnlWzskNavHeadbar::Tag

#define DpchEngWzskNavHeadbarData PnlWzskNavHeadbar::DpchEngData

/**
	* PnlWzskNavHeadbar
	*/
class PnlWzskNavHeadbar : public JobWzsk {

public:
	/**
		* StatShr (full: StatShrWzskNavHeadbar)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MENCRDAVAIL = 1;

	public:
		StatShr(const bool MenCrdAvail = true);

	public:
		bool MenCrdAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgInf (full: StgInfWzskNavHeadbar)
		*/
	class StgInf {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* Tag (full: TagWzskNavHeadbar)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchEngData (full: DpchEngWzskNavHeadbarData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint STGINF = 3;
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

	bool evalMenCrdAvail(DbsWzsk* dbswzsk);
	bool evalMspCrd1Avail(DbsWzsk* dbswzsk);
	bool evalMitCrdUsgAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdUsrAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdPrsAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdScfAvail(DbsWzsk* dbswzsk);
	bool evalMspCrd2Avail(DbsWzsk* dbswzsk);
	bool evalMitCrdLlvAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdLivAvail(DbsWzsk* dbswzsk);
	bool evalMspCrd3Avail(DbsWzsk* dbswzsk);
	bool evalMitCrdOgrAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdObjAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdSesAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdShtAvail(DbsWzsk* dbswzsk);
	bool evalMitCrdFilAvail(DbsWzsk* dbswzsk);

public:
	PnlWzskNavHeadbar(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~PnlWzskNavHeadbar();

public:
	StatShr statshr;

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
