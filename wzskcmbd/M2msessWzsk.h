/**
	* \file M2msessWzsk.h
	* job handler for job M2msessWzsk (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef M2MSESSWZSK_H
#define M2MSESSWZSK_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcSysinfo.h"
#include "JobWzskIprTrace.h"
#include "JobWzskIprCorner.h"
#include "JobWzskActServo.h"
#include "JobWzskActLaser.h"
#include "JobWzskActExposure.h"
#include "JobWzskAcqPtcloud.h"
#include "JobWzskAcqPreview.h"

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
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFACQPREVIEW = 1;
		static const Sbecore::uint JREFACQPTCLOUD = 2;
		static const Sbecore::uint JREFACTEXPOSURE = 3;
		static const Sbecore::uint JREFACTLASER = 4;
		static const Sbecore::uint JREFACTSERVO = 5;
		static const Sbecore::uint JREFIPRCORNER = 6;
		static const Sbecore::uint JREFIPRTRACE = 7;
		static const Sbecore::uint JREFSRCSYSINFO = 8;

	public:
		StatShr(const Sbecore::ubigint jrefAcqpreview = 0, const Sbecore::ubigint jrefAcqptcloud = 0, const Sbecore::ubigint jrefActexposure = 0, const Sbecore::ubigint jrefActlaser = 0, const Sbecore::ubigint jrefActservo = 0, const Sbecore::ubigint jrefIprcorner = 0, const Sbecore::ubigint jrefIprtrace = 0, const Sbecore::ubigint jrefSrcsysinfo = 0);

	public:
		Sbecore::ubigint jrefAcqpreview;
		Sbecore::ubigint jrefAcqptcloud;
		Sbecore::ubigint jrefActexposure;
		Sbecore::ubigint jrefActlaser;
		Sbecore::ubigint jrefActservo;
		Sbecore::ubigint jrefIprcorner;
		Sbecore::ubigint jrefIprtrace;
		Sbecore::ubigint jrefSrcsysinfo;

	public:
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

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	M2msessWzsk(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::ubigint refWzskMUser, const std::string& ip);
	~M2msessWzsk();

public:
	StatShr statshr;

	JobWzskSrcSysinfo* srcsysinfo;
	JobWzskIprTrace* iprtrace;
	JobWzskIprCorner* iprcorner;
	JobWzskActServo* actservo;
	JobWzskActLaser* actlaser;
	JobWzskActExposure* actexposure;
	JobWzskAcqPtcloud* acqptcloud;
	JobWzskAcqPreview* acqpreview;

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

