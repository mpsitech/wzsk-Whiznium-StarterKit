/**
	* \file SessWzsk.h
	* job handler for job SessWzsk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef SESSWZSK_H
#define SESSWZSK_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "CrdWzskFil.h"
#include "CrdWzskSht.h"
#include "CrdWzskSes.h"
#include "CrdWzskObj.h"
#include "CrdWzskOgr.h"
#include "CrdWzskLiv.h"
#include "CrdWzskLlv.h"
#include "CrdWzskNav.h"
#include "CrdWzskScf.h"
#include "CrdWzskPrs.h"
#include "CrdWzskUsr.h"
#include "CrdWzskUsg.h"

#define StatShrSessWzsk SessWzsk::StatShr

#define DpchEngSessWzskData SessWzsk::DpchEngData

/**
	* SessWzsk
	*/
class SessWzsk : public JobWzsk {

public:
	/**
		* StatShr (full: StatShrSessWzsk)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFCRDNAV = 1;

	public:
		StatShr(const Sbecore::ubigint jrefCrdnav = 0);

	public:
		Sbecore::ubigint jrefCrdnav;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngSessWzskData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSEC = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint ALL = 4;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSec = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSec;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	SessWzsk(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWzskMUser, const std::string& ip);
	~SessWzsk();

public:
	StatShr statshr;

	std::list<CrdWzskFil*> crdfils;
	std::list<CrdWzskSht*> crdshts;
	std::list<CrdWzskSes*> crdsess;
	std::list<CrdWzskObj*> crdobjs;
	std::list<CrdWzskOgr*> crdogrs;
	std::list<CrdWzskLiv*> crdlivs;
	std::list<CrdWzskLlv*> crdllvs;
	CrdWzskNav* crdnav;
	std::list<CrdWzskScf*> crdscfs;
	std::list<CrdWzskPrs*> crdprss;
	std::list<CrdWzskUsr*> crdusrs;
	std::list<CrdWzskUsg*> crdusgs;

	std::map<Sbecore::ubigint,Sbecore::uint> usgaccs;

	std::map<Sbecore::ubigint,std::string> scr;
	std::map<std::string,Sbecore::ubigint> descr;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void warnTerm(DbsWzsk* dbswzsk);
	void term(DbsWzsk* dbswzsk);

	Sbecore::uint checkCrdActive(const Sbecore::uint ixWzskVCard);
	Sbecore::uint evalCrdshtActive();
	Sbecore::uint evalCrdfilActive();

	Sbecore::uint checkCrdaccess(const Sbecore::uint ixWzskVCard);
	void getIxCrdacc(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCard, const bool adm, ListWzskRMUserMUsergroup& urus, const Sbecore::ubigint refWzskMUser, Sbecore::uint& ixWzskWAccess);

	Sbecore::uint checkRecaccess(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCard, const Sbecore::ubigint ref);
	void logRecaccess(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint preUref, const Sbecore::uint ixWzskVCard, const Sbecore::ubigint unvUref);

	Sbecore::uint crdToMtb(const Sbecore::uint ixWzskVCard);
	Sbecore::uint preToMtb(const Sbecore::uint ixWzskVPreset);
	bool hasActive(const Sbecore::uint ixWzskVCard);
	bool hasGrpown(const Sbecore::uint ixWzskVMaintable);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleCreateCrdfil(DbsWzsk* dbswzsk);
	bool handleCreateCrdliv(DbsWzsk* dbswzsk);
	bool handleCreateCrdllv(DbsWzsk* dbswzsk);
	bool handleCreateCrdobj(DbsWzsk* dbswzsk);
	bool handleCreateCrdogr(DbsWzsk* dbswzsk);
	bool handleCreateCrdprs(DbsWzsk* dbswzsk);
	bool handleCreateCrdscf(DbsWzsk* dbswzsk);
	bool handleCreateCrdses(DbsWzsk* dbswzsk);
	bool handleCreateCrdsht(DbsWzsk* dbswzsk);
	bool handleCreateCrdusg(DbsWzsk* dbswzsk);
	bool handleCreateCrdusr(DbsWzsk* dbswzsk);
	bool handleEraseCrdfil(DbsWzsk* dbswzsk);
	bool handleEraseCrdliv(DbsWzsk* dbswzsk);
	bool handleEraseCrdllv(DbsWzsk* dbswzsk);
	bool handleEraseCrdobj(DbsWzsk* dbswzsk);
	bool handleEraseCrdogr(DbsWzsk* dbswzsk);
	bool handleEraseCrdprs(DbsWzsk* dbswzsk);
	bool handleEraseCrdscf(DbsWzsk* dbswzsk);
	bool handleEraseCrdses(DbsWzsk* dbswzsk);
	bool handleEraseCrdsht(DbsWzsk* dbswzsk);
	bool handleEraseCrdusg(DbsWzsk* dbswzsk);
	bool handleEraseCrdusr(DbsWzsk* dbswzsk);

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskRefPreSet(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool handleCallWzskCrdClose(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv);
	bool handleCallWzskCrdActive(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, Sbecore::uint& ixRet);
	bool handleCallWzskRecaccess(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool handleCallWzskLog(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool handleCallWzskCrdOpen(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);

};

#endif
