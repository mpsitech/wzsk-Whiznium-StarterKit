/**
	* \file M2msessWzsk.h
	* job handler for job M2msessWzsk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef M2MSESSWZSK_H
#define M2MSESSWZSK_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskAcqCorner.h"
#include "JobWzskAcqTrace.h"
#include "JobWzskActLaser.h"
#include "JobWzskActRotary.h"
#include "JobWzskSrcFpgainfo.h"
#include "JobWzskSrcSysinfo.h"

#define StatShrM2msessWzsk M2msessWzsk::StatShr

#define DpchEngM2msessWzskData M2msessWzsk::DpchEngData

/**
	* M2msessWzsk
	*/
class M2msessWzsk : public JobWzsk {

public:
	/**
		* StatShr (full: StatShrM2msessWzsk)
		*/
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint JREFACQCORNER = 1;
		static const Sbecore::uint JREFACQTRACE = 2;
		static const Sbecore::uint JREFACTLASER = 3;
		static const Sbecore::uint JREFACTROTARY = 4;
		static const Sbecore::uint JREFSRCFPGAINFO = 5;
		static const Sbecore::uint JREFSRCSYSINFO = 6;

	public:
		StatShr(const Sbecore::ubigint jrefAcqcorner = 0, const Sbecore::ubigint jrefAcqtrace = 0, const Sbecore::ubigint jrefActlaser = 0, const Sbecore::ubigint jrefActrotary = 0, const Sbecore::ubigint jrefSrcfpgainfo = 0, const Sbecore::ubigint jrefSrcsysinfo = 0);

	public:
		Sbecore::ubigint jrefAcqcorner;
		Sbecore::ubigint jrefAcqtrace;
		Sbecore::ubigint jrefActlaser;
		Sbecore::ubigint jrefActrotary;
		Sbecore::ubigint jrefSrcfpgainfo;
		Sbecore::ubigint jrefSrcsysinfo;

	public:
		void writeJSON(Json::Value& sup, std::string difftag = "");
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* DpchEngData (full: DpchEngM2msessWzskData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	M2msessWzsk(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWzskMUser, const std::string& ip);
	~M2msessWzsk();

public:
	StatShr statshr;

	JobWzskAcqCorner* acqcorner;
	JobWzskAcqTrace* acqtrace;
	JobWzskActLaser* actlaser;
	JobWzskActRotary* actrotary;
	JobWzskSrcFpgainfo* srcfpgainfo;
	JobWzskSrcSysinfo* srcsysinfo;

	std::multimap<Sbecore::featix_t,Sbecore::uint> accs;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void term(DbsWzsk* dbswzsk);

	Sbecore::uint addAccBase(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVFeatgroup, const bool adm, ListWzskRMUserMUsergroup& urus, const Sbecore::ubigint refWzskMUser);
	void addAcc(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVFeatgroup, const std::string& srefIxVFeature, ListWzskRMUserMUsergroup& urus, const Sbecore::ubigint refWzskMUser, const Sbecore::uint ixWzskWAccessBase);

	void getIxAcc(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVFeatgroup, const std::string& srefIxVFeature, const bool adm, ListWzskRMUserMUsergroup& urus, const Sbecore::ubigint refWzskMUser, Sbecore::uint& ixWzskWAccess);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskAccess(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const std::string& srefInv, Sbecore::uint& ixRet);

};

#endif
