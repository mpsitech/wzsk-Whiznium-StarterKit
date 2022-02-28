/**
	* \file RootWzsk.h
	* job handler for job RootWzsk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef ROOTWZSK_H
#define ROOTWZSK_H

#include <signal.h>

// IP include.cust --- INSERT

#include "SessWzsk.h"
#include "M2msessWzsk.h"
#include "JobWzskAcqFpgaflg.h"
#include "JobWzskAcqFpgapvw.h"
#include "JobWzskAcqPreview.h"
#include "JobWzskAcqPtcloud.h"
#include "JobWzskActExposure.h"
#include "JobWzskActLaser.h"
#include "JobWzskActServo.h"
#include "JobWzskIprAngle.h"
#include "JobWzskIprCorner.h"
#include "JobWzskIprTrace.h"
#include "JobWzskSrcArty.h"
#include "JobWzskSrcClnxevb.h"
#include "JobWzskSrcIcicle.h"
#include "JobWzskSrcMcvevp.h"
#include "JobWzskSrcSysinfo.h"
#include "JobWzskSrcUvbdvk.h"
#include "JobWzskSrcUzediocc.h"
#include "JobWzskSrcV4l2.h"

#define DpchAppRootWzskLogin RootWzsk::DpchAppLogin
#define DpchEngRootWzskData RootWzsk::DpchEngData

/**
	* RootWzsk
	*/
class RootWzsk : public JobWzsk {

public:
	/**
		* DpchAppLogin (full: DpchAppRootWzskLogin)
		*/
	class DpchAppLogin : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint USERNAME = 2;
		static const Sbecore::uint PASSWORD = 3;
		static const Sbecore::uint M2MNOTREG = 4;
		static const Sbecore::uint CHKSUSPSESS = 5;

	public:
		DpchAppLogin();

	public:
		std::string username;
		std::string password;
		bool m2mNotReg;
		bool chksuspsess;

	public:
		std::string getSrefsMask();

		void readJSON(Json::Value& sup, bool addbasetag = false);
		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngRootWzskData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint FEEDFENSSPS = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Feed* feedFEnsSps = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeJSON(const Sbecore::uint ixWzskVLocale, Json::Value& sup);
		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	RootWzsk(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const bool _clearAll);
	~RootWzsk();

public:

	std::map<Sbecore::ubigint, JobWzsk*> sesss;
	std::map<Sbecore::ubigint, JobWzsk*> m2msesss;
	JobWzskAcqFpgaflg* acqfpgaflg;
	JobWzskAcqFpgapvw* acqfpgapvw;
	JobWzskAcqPreview* acqpreview;
	JobWzskAcqPtcloud* acqptcloud;
	JobWzskActExposure* actexposure;
	JobWzskActLaser* actlaser;
	JobWzskActServo* actservo;
	JobWzskIprAngle* iprangle;
	JobWzskIprCorner* iprcorner;
	JobWzskIprTrace* iprtrace;
	JobWzskSrcArty* srcarty;
	JobWzskSrcClnxevb* srcclnxevb;
	JobWzskSrcIcicle* srcicicle;
	JobWzskSrcMcvevp* srcmcvevp;
	JobWzskSrcSysinfo* srcsysinfo;
	JobWzskSrcUvbdvk* srcuvbdvk;
	JobWzskSrcUzediocc* srcuzediocc;
	JobWzskSrcV4l2* srcv4l2;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsWzsk* dbswzsk);
	void clearQtb(DbsWzsk* dbswzsk);

	bool authenticate(DbsWzsk* dbswzsk, const std::string& username, const std::string& password, Sbecore::ubigint& refWzskMUser);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:
	bool handleClearAll(DbsWzsk* dbswzsk);
	bool handleCreateSess(DbsWzsk* dbswzsk);
	bool handleEraseSess(DbsWzsk* dbswzsk);
	bool handleTest(DbsWzsk* dbswzsk);

	void handleDpchAppLogin(DbsWzsk* dbswzsk, DpchAppLogin* dpchapplogin, const std::string ip, DpchEngWzsk** dpcheng);

	void handleTimerWithSrefWarnterm(DbsWzsk* dbswzsk);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskLogout(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const bool boolvalInv);
	bool handleCallWzskSuspsess(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskRefPreSet(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);

};

#endif
