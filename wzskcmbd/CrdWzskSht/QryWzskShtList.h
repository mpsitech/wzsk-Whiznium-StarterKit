/**
	* \file QryWzskShtList.h
	* job handler for job QryWzskShtList (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef QRYWZSKSHTLIST_H
#define QRYWZSKSHTLIST_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVQryWzskShtListOrd QryWzskShtList::VecVOrd

#define StatAppQryWzskShtList QryWzskShtList::StatApp
#define StatShrQryWzskShtList QryWzskShtList::StatShr
#define StgIacQryWzskShtList QryWzskShtList::StgIac

/**
	* QryWzskShtList
	*/
class QryWzskShtList : public JobWzsk {

public:
	/**
		* VecVOrd (full: VecVQryWzskShtListOrd)
		*/
	class VecVOrd {

	public:
		static const Sbecore::uint STA = 1;
		static const Sbecore::uint OBJ = 2;
		static const Sbecore::uint SES = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Feed& feed);
	};

	/**
		* StatApp (full: StatAppQryWzskShtList)
		*/
	class StatApp {

	public:
		static void writeJSON(Json::Value& sup, std::string difftag = "", const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 3, const Sbecore::uint ndisp = 25);
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint firstcol = 1, const Sbecore::uint jnumFirstdisp = 1, const Sbecore::uint ncol = 3, const Sbecore::uint ndisp = 25);
	};

	/**
		* StatShr (full: StatShrQryWzskShtList)
		*/
	class StatShr : public Sbecore::Block {

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
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* StgIac (full: StgIacQryWzskShtList)
		*/
	class StgIac : public Sbecore::Block {

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
		bool readJSON(const Json::Value& sup, bool addbasetag = false);
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StgIac* comp);
		std::set<Sbecore::uint> diff(const StgIac* comp);
	};

public:
	QryWzskShtList(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~QryWzskShtList();

public:
	StatShr statshr;
	StgIac stgiac;

	ListWzskQShtList rst;

	Sbecore::uint ixWzskVQrystate;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void refreshJnum();

	void rerun(DbsWzsk* dbswzsk, const bool call = false);
	void rerun_baseSQL(std::string& sqlstr);
	void rerun_filtSQL(std::string& sqlstr, const Sbecore::ubigint preSes, const Sbecore::ubigint preObj, const int preSta, const bool addwhere);
	void rerun_filtSQL_append(std::string& sqlstr, bool& first);
	void rerun_orderSQL(std::string& sqlstr, const Sbecore::uint preIxOrd);

	void fetch(DbsWzsk* dbswzsk);

	Sbecore::uint getJnumByRef(const Sbecore::ubigint ref);
	Sbecore::ubigint getRefByJnum(const Sbecore::uint jnum);
	WzskQShtList* getRecByJnum(const Sbecore::uint jnum);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleRerun(DbsWzsk* dbswzsk);
	bool handleShow(DbsWzsk* dbswzsk);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskShtUpd_refEq(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskShtMod(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskStubChgFromSelf(DbsWzsk* dbswzsk);

};

#endif
