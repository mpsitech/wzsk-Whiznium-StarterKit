/**
	* \file RootWzsk.h
	* job handler for job RootWzsk (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef ROOTWZSK_H
#define ROOTWZSK_H

#include <signal.h>

// IP include.cust --- INSERT

#include "SessWzsk.h"
#include "M2msessWzsk.h"
#include "JobWzskAcqCorner.h"
#include "JobWzskAcqHdr.h"
#include "JobWzskAcqMemtrack.h"
#include "JobWzskAcqPreview.h"
#include "JobWzskAcqTrace.h"
#include "JobWzskAcqVtrtrack.h"
#include "JobWzskActLaser.h"
#include "JobWzskActRotary.h"
#include "JobWzskActVistorot.h"
#include "JobWzskPrcAngle.h"
#include "JobWzskPrcWavelet.h"
#include "JobWzskSrcDcvsp.h"
#include "JobWzskSrcFpgainfo.h"
#include "JobWzskSrcSysinfo.h"
#include "JobWzskSrcTivsp.h"
#include "JobWzskSrcZuvsp.h"

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

		void readJSON(const Json::Value& sup, bool addbasetag = false);
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
	JobWzskAcqCorner* acqcorner;
	JobWzskAcqHdr* acqhdr;
	JobWzskAcqMemtrack* acqmemtrack;
	JobWzskAcqPreview* acqpreview;
	JobWzskAcqTrace* acqtrace;
	JobWzskAcqVtrtrack* acqvtrtrack;
	JobWzskActLaser* actlaser;
	JobWzskActRotary* actrotary;
	JobWzskActVistorot* actvistorot;
	JobWzskPrcAngle* prcangle;
	JobWzskPrcWavelet* prcwavelet;
	JobWzskSrcDcvsp* srcdcvsp;
	JobWzskSrcFpgainfo* srcfpgainfo;
	JobWzskSrcSysinfo* srcsysinfo;
	JobWzskSrcTivsp* srctivsp;
	JobWzskSrcZuvsp* srczuvsp;

	// IP vars.spec --- INSERT

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	void clearAll(DbsWzsk* dbswzsk);
	void clearQtb(DbsWzsk* dbswzsk);

	bool authenticate(DbsWzsk* dbswzsk, const std::string& username, const std::string& password, Sbecore::ubigint& refWzskMUser);
	void termSess(DbsWzsk* dbswzsk, const Sbecore::ubigint jref);

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
