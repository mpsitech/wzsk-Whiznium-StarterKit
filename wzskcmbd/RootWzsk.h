/**
	* \file RootWzsk.h
	* job handler for job RootWzsk (declarations)
	* \author Catherine Johnson
	* \date created: 23 Jul 2020
	* \date modified: 23 Jul 2020
	*/

#ifndef ROOTWZSK_H
#define ROOTWZSK_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "JobWzskSrcV4l2.h"
#include "JobWzskSrcFpga.h"
#include "JobWzskIprTrace.h"
#include "JobWzskIprCorner.h"
#include "JobWzskIprAngle.h"
#include "JobWzskActServo.h"
#include "JobWzskActLaser.h"
#include "JobWzskAcqPtcloud.h"
#include "JobWzskAcqPreview.h"
#include "JobWzskAcqFpgapvw.h"
#include "JobWzskAcqFpgaflg.h"
#include "M2msessWzsk.h"
#include "SessWzsk.h"

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
		DpchEngData(const Sbecore::ubigint jref = 0, Sbecore::Xmlio::Feed* feedFEnsSps = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::Xmlio::Feed feedFEnsSps;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	RootWzsk(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const bool _clearAll);
	~RootWzsk();

public:

	JobWzskSrcV4l2* srcv4l2;
	JobWzskSrcFpga* srcfpga;
	JobWzskIprTrace* iprtrace;
	JobWzskIprCorner* iprcorner;
	JobWzskIprAngle* iprangle;
	JobWzskActServo* actservo;
	JobWzskActLaser* actlaser;
	JobWzskAcqPtcloud* acqptcloud;
	JobWzskAcqPreview* acqpreview;
	JobWzskAcqFpgapvw* acqfpgapvw;
	JobWzskAcqFpgaflg* acqfpgaflg;
	std::list<M2msessWzsk*> m2msesss;
	std::list<SessWzsk*> sesss;

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

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskSuspsess(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);
	bool handleCallWzskLogout(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig, const bool boolvalInv);

};

#endif

