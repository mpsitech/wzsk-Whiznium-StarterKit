/**
	* \file QryWzskOgrList.h
	* job handler for job QryWzskOgrList (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef QRYWZSKOGRLIST_H
#define QRYWZSKOGRLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWzskOgrListOrd QryWzskOgrList::VecVOrd

#define StatAppQryWzskOgrList QryWzskOgrList::StatApp
#define StatShrQryWzskOgrList QryWzskOgrList::StatShr
#define StgIacQryWzskOgrList QryWzskOgrList::StgIac

/**
	* QryWzskOgrList
	*/
class QryWzskOgrList : public JobWzsk {

public:
	/**
		* VecVOrd (full: VecVQryWzskOgrListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint SUP = 1;
		static const Sbecore::uint TIT = 2;
		static const Sbecore::uint SRF = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWzskOgrList)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 3, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWzskOgrList)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NTOT = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StatShr(const Sbecore::uint ntot = 0, const Sbecore::uint jnumFirstload = 0, const Sbecore::uint nload = 0);

	public:
		Sbecore::uint ntot;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWzskOgrList)
		*/
	class StgIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JNUM = 1;
		static const Sbecore::uint JNUMFIRSTLOAD = 2;
		static const Sbecore::uint NLOAD = 3;

	public:
		StgIac(const Sbecore::uint jnum = 0, const Sbecore::uint jnumFirstload = 1, const Sbecore::uint nload = 100);

	public:
		Sbecore::uint jnum;
		Sbecore::uint jnumFirstload;
		Sbecore::uint nload;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWzskOgrList(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~QryWzskOgrList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWzskQOgrList rst;

	Sbecore::uint ixWzskVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWzsk* dbswzsk, const bool call = false);
	void rerun_filtSQL(std::string& sqlstr, const std::string& preSrf, const std::string& preTit, const Sbecore::ubigint preSup, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWzsk* dbswzsk);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WzskQOgrList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleRerun(DbsWzsk* dbswzsk);
	bool handleShow(DbsWzsk* dbswzsk);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskOgrUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskOgrMod(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskStubChgFromSelf(DbsWzsk* dbswzsk);

};

#endif

