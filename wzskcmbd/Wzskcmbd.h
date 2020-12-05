/**
	* \file Wzskcmbd.h
	* inter-thread exchange object for Wzsk combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKCMBD_H
#define WZSKCMBD_H

#ifdef __CYGWIN__
	#include <sys/select.h>
#endif

#include <unistd.h>

#ifndef _WIN32
	#include <sys/socket.h>
#endif
#ifdef _WIN32
	#include <windows.h>
	#include <winsock.h>
	typedef int socklen_t;
#endif

#include <sys/stat.h>

#include <microhttpd.h>

#include <sbecore/Txtrd.h>
#include <sbecore/TxtMon.h>

#include "Wzsk.h"

// IP include.cust --- INSERT

class XchgWzskcmbd;
typedef XchgWzskcmbd XchgWzsk;

/**
	* DpchAppWzsk
	*/
class DpchAppWzsk : public DpchWzsk {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchAppWzsk(const Sbecore::uint ixWzskVDpch = 0);
	virtual ~DpchAppWzsk();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();

	virtual void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWzskAlert
	*/
class DpchAppWzskAlert : public DpchAppWzsk {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint NUMFMCB = 2;

public:
	DpchAppWzskAlert();

public:
	Sbecore::uint numFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();

	void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
};

/**
	* DpchAppWzskInit
	*/
class DpchAppWzskInit : public DpchAppWzsk {

public:
	DpchAppWzskInit();
};

/**
	* DpchAppWzskResume
	*/
class DpchAppWzskResume : public DpchAppWzsk {

public:
	DpchAppWzskResume();
};

/**
	* DpchEngWzsk
	*/
class DpchEngWzsk : public DpchWzsk {

public:
	static const Sbecore::uint JREF = 1;

public:
	DpchEngWzsk(const Sbecore::uint ixWzskVDpch = 0, const Sbecore::ubigint jref = 0);
	virtual ~DpchEngWzsk();

public:
	Sbecore::ubigint jref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	virtual std::string getSrefsMask();
	virtual void merge(DpchEngWzsk* dpcheng);

	virtual void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWzskAck
	*/
class DpchEngWzskAck : public DpchEngWzsk {

public:
	DpchEngWzskAck(const Sbecore::ubigint jref = 0);
};

/**
	* DpchEngWzskAlert
	*/
class DpchEngWzskAlert : public DpchEngWzsk {

public:
	static const Sbecore::uint JREF = 1;
	static const Sbecore::uint CONTINF = 2;
	static const Sbecore::uint FEEDFMCB = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWzskAlert(const Sbecore::ubigint jref = 0, ContInfWzskAlert* continf = NULL, Sbecore::Xmlio::Feed* feedFMcb = NULL, const std::set<Sbecore::uint>& mask = {NONE});

public:
	ContInfWzskAlert continf;
	Sbecore::Xmlio::Feed feedFMcb;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWzsk* dpcheng);

	void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWzskConfirm
	*/
class DpchEngWzskConfirm : public DpchEngWzsk {

public:
	static const Sbecore::uint ACCEPTED = 1;
	static const Sbecore::uint JREF = 2;
	static const Sbecore::uint SREF = 3;
	static const Sbecore::uint ALL = 4;

public:
	DpchEngWzskConfirm(const bool accepted = false, const Sbecore::ubigint jref = 0, const std::string& sref = "", const std::set<Sbecore::uint>& mask = {ALL});

public:
	bool accepted;
	std::string sref;

public:
	static bool all(const std::set<Sbecore::uint>& items);
	std::string getSrefsMask();
	void merge(DpchEngWzsk* dpcheng);

	void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
};

/**
	* DpchEngWzskSuspend
	*/
class DpchEngWzskSuspend : public DpchEngWzsk {

public:
	DpchEngWzskSuspend(const Sbecore::ubigint jref = 0);
};

/**
	* StgWzskAppearance
	*/
class StgWzskAppearance : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint HISTLENGTH = 1;
	static const Sbecore::uint SUSPSESS = 2;

public:
	StgWzskAppearance(const Sbecore::usmallint histlength = 20, const bool suspsess = true);

public:
	Sbecore::usmallint histlength;
	bool suspsess;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskAppearance* comp);
	std::set<Sbecore::uint> diff(const StgWzskAppearance* comp);
};

/**
	* StgWzskAppsrv
	*/
class StgWzskAppsrv : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint PORT = 1;
	static const Sbecore::uint HTTPS = 2;

public:
	StgWzskAppsrv(const Sbecore::usmallint port = 13100, const bool https = false);

public:
	Sbecore::usmallint port;
	bool https;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskAppsrv* comp);
	std::set<Sbecore::uint> diff(const StgWzskAppsrv* comp);
};

/**
	* StgWzskCamera
	*/
class StgWzskCamera : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint HPIX = 1;
	static const Sbecore::uint F = 2;
	static const Sbecore::uint FN = 3;

public:
	StgWzskCamera(const float hpix = 1.4, const float f = 3.78, const float fn = 3);

public:
	float hpix;
	float f;
	float fn;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskCamera* comp);
	std::set<Sbecore::uint> diff(const StgWzskCamera* comp);
};

/**
	* StgWzskcmbd
	*/
class StgWzskcmbd : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint JOBPRCN = 1;
	static const Sbecore::uint OPPRCN = 2;
	static const Sbecore::uint APPSRV = 3;
	static const Sbecore::uint DDSPUB = 4;
	static const Sbecore::uint UASRV = 5;

public:
	StgWzskcmbd(const Sbecore::usmallint jobprcn = 4, const Sbecore::usmallint opprcn = 1, const bool appsrv = true, const bool ddspub = true, const bool uasrv = true);

public:
	Sbecore::usmallint jobprcn;
	Sbecore::usmallint opprcn;
	bool appsrv;
	bool ddspub;
	bool uasrv;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskcmbd* comp);
	std::set<Sbecore::uint> diff(const StgWzskcmbd* comp);
};

/**
	* StgWzskDatabase
	*/
class StgWzskDatabase : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint IXDBSVDBSTYPE = 1;
	static const Sbecore::uint DBSPATH = 2;
	static const Sbecore::uint DBSNAME = 3;
	static const Sbecore::uint USERNAME = 4;
	static const Sbecore::uint PASSWORD = 5;
	static const Sbecore::uint IP = 6;
	static const Sbecore::uint PORT = 7;

public:
	StgWzskDatabase(const Sbecore::uint ixDbsVDbstype = 0, const std::string& dbspath = "./DbsWzsk.sql", const std::string& dbsname = "DbsWzsk", const std::string& username = "default", const std::string& password = "asdf1234", const std::string& ip = "127.0.0.1", const Sbecore::usmallint port = 3306);

public:
	Sbecore::uint ixDbsVDbstype;
	std::string dbspath;
	std::string dbsname;
	std::string username;
	std::string password;
	std::string ip;
	Sbecore::usmallint port;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskDatabase* comp);
	std::set<Sbecore::uint> diff(const StgWzskDatabase* comp);
};

/**
	* StgWzskDdspub
	*/
class StgWzskDdspub : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint USERNAME = 1;
	static const Sbecore::uint PASSWORD = 2;

public:
	StgWzskDdspub(const std::string& username = "", const std::string& password = "");

public:
	std::string username;
	std::string password;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskDdspub* comp);
	std::set<Sbecore::uint> diff(const StgWzskDdspub* comp);
};

/**
	* StgWzskFramegeo
	*/
class StgWzskFramegeo : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint WACQ = 1;
	static const Sbecore::uint HACQ = 2;
	static const Sbecore::uint WHACQ = 3;
	static const Sbecore::uint X0RGB = 4;
	static const Sbecore::uint WRGB = 5;
	static const Sbecore::uint Y0RGB = 6;
	static const Sbecore::uint HRGB = 7;
	static const Sbecore::uint X0GRRD = 8;
	static const Sbecore::uint WGRRD = 9;
	static const Sbecore::uint Y0GRRD = 10;
	static const Sbecore::uint HGRRD = 11;

public:
	StgWzskFramegeo(const Sbecore::uint wAcq = 2592, const Sbecore::uint hAcq = 1944, const Sbecore::uint whAcq = 5038848, const Sbecore::uint x0Rgb = 16, const Sbecore::uint wRgb = 1280, const Sbecore::uint y0Rgb = 12, const Sbecore::uint hRgb = 960, const Sbecore::uint x0Grrd = 272, const Sbecore::uint wGrrd = 1024, const Sbecore::uint y0Grrd = 204, const Sbecore::uint hGrrd = 768);

public:
	Sbecore::uint wAcq;
	Sbecore::uint hAcq;
	Sbecore::uint whAcq;

	Sbecore::uint x0Rgb;
	Sbecore::uint wRgb;
	Sbecore::uint y0Rgb;
	Sbecore::uint hRgb;

	Sbecore::uint x0Grrd;
	Sbecore::uint wGrrd;
	Sbecore::uint y0Grrd;
	Sbecore::uint hGrrd;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskFramegeo* comp);
	std::set<Sbecore::uint> diff(const StgWzskFramegeo* comp);
};

/**
	* StgWzskGlobal
	*/
class StgWzskGlobal : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint FPGANOTV4L2GPIO = 1;

public:
	StgWzskGlobal(const bool fpgaNotV4l2gpio = false);

public:
	bool fpgaNotV4l2gpio;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskGlobal* comp);
	std::set<Sbecore::uint> diff(const StgWzskGlobal* comp);
};

/**
	* StgWzskPath
	*/
class StgWzskPath : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint ACVPATH = 1;
	static const Sbecore::uint KEYPATH = 2;
	static const Sbecore::uint MONPATH = 3;
	static const Sbecore::uint TMPPATH = 4;
	static const Sbecore::uint WEBPATH = 5;
	static const Sbecore::uint HELPURL = 6;

public:
	StgWzskPath(const std::string& acvpath = "${WHIZROOT}/acv/wzsk", const std::string& keypath = "", const std::string& monpath = "${WHIZROOT}/mon/wzsk", const std::string& tmppath = "${WHIZROOT}/tmp/wzsk", const std::string& webpath = "${WHIZROOT}/web/appwzsk", const std::string& helpurl = "http://www.mpsitech.com/wzsk");

public:
	std::string acvpath;
	std::string keypath;
	std::string monpath;
	std::string tmppath;
	std::string webpath;
	std::string helpurl;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskPath* comp);
	std::set<Sbecore::uint> diff(const StgWzskPath* comp);
};

/**
	* StgWzskUasrv
	*/
class StgWzskUasrv : public Sbecore::Xmlio::Block {

public:
	static const Sbecore::uint PROFILE = 1;
	static const Sbecore::uint PORT = 2;
	static const Sbecore::uint CYCLE = 3;
	static const Sbecore::uint MAXBROWSE = 4;
	static const Sbecore::uint MAXMON = 5;

public:
	StgWzskUasrv(const std::string& profile = "./EmbeddedProfile_StandardNodes.xml", const Sbecore::usmallint port = 4840, const Sbecore::usmallint cycle = 100, const Sbecore::uint maxbrowse = 1000, const Sbecore::uint maxmon = 10000);

public:
	std::string profile;
	Sbecore::usmallint port;
	Sbecore::usmallint cycle;
	Sbecore::uint maxbrowse;
	Sbecore::uint maxmon;

public:
	bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	std::set<Sbecore::uint> comm(const StgWzskUasrv* comp);
	std::set<Sbecore::uint> diff(const StgWzskUasrv* comp);
};

/**
	* AlrWzsk
	*/
namespace AlrWzsk {
	DpchEngWzskAlert* prepareAlrAbt(const Sbecore::ubigint jref, const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feedFMcbAlert);
	DpchEngWzskAlert* prepareAlrIer(const Sbecore::ubigint jref, const Sbecore::uint ixWzskVLocale, const std::string& iexsqk, Sbecore::Xmlio::Feed& feedFMcbAlert);
	DpchEngWzskAlert* prepareAlrPer(const Sbecore::ubigint jref, const Sbecore::uint ixWzskVLocale, const std::string& iexsqk, Sbecore::Xmlio::Feed& feedFMcbAlert);
	DpchEngWzskAlert* prepareAlrSav(const Sbecore::ubigint jref, const Sbecore::uint ixWzskVLocale, Sbecore::Xmlio::Feed& feedFMcbAlert);
};

/**
	* ReqWzsk
	*/
class ReqWzsk {

public:
	/**
		* VecVBasetype
		*/
	class VecVBasetype {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint REDIRECT = 1; // web client triggered root request (GET)
		static const Sbecore::uint WEB = 2; // web client triggered ui file request (GET)
		static const Sbecore::uint CMD = 3; // command line request
		static const Sbecore::uint DPCHAPP = 4; // web client triggered Dpch request (POST+DpchApp)
		static const Sbecore::uint NOTIFY = 5; // web client triggered notify-on-Dpch request (GET)
		static const Sbecore::uint POLL = 6; // web client triggered Dpch poll request (GET)
		static const Sbecore::uint UPLOAD = 7; // web client triggered file upload request (POST)
		static const Sbecore::uint DOWNLOAD = 8; // web client triggered file download request (GET)
		static const Sbecore::uint DPCHRET = 9; // op engine or opprc triggered op return (DpchRet)
		static const Sbecore::uint METHOD = 10; // M2M interface triggered method request
		static const Sbecore::uint TIMER = 11; // timer triggered request
		static const Sbecore::uint EXTCALL = 12; // externally triggered call request
	};

	/**
		* VecVState
		*/
	class VecVState {

	public:
		static const Sbecore::uint NONE = 0; // invalid
		static const Sbecore::uint RECEIVE = 1; // during data reception - appsrv internal
		static const Sbecore::uint WAITPRC = 2; // before caught by job processor that is idle - in reqs list
		static const Sbecore::uint PRC = 3; // while being processesd by job processor ; appsrv thread waiting on cReply
		static const Sbecore::uint REPLY = 4; // after being processed by job processor
	};

public:
	ReqWzsk(const Sbecore::uint ixVBasetype = VecVBasetype::NONE, const Sbecore::uint ixVState = VecVState::RECEIVE, const std::string& ip = "");
	~ReqWzsk();

public:
	Sbecore::uint ixVBasetype;
	Sbecore::uint ixVState;

	// specific data for base type CMD
	std::string cmd;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD
	std::string ip;

	// specific data for base types DPCHAPP, NOTIFY, POLL, UPLOAD
	MHD_PostProcessor* pp;

	// specific data for base types CMD, DPCHAPP, NOTIFY, UPLOAD, DOWNLOAD, METHOD
	bool retain;
	Sbecore::Cond cReady; // mutex also protects compare/set of ixVState to REPLY

	// specific data for base types WEB, UPLOAD, DOWNLOAD
	std::string filename; // full path
	std::fstream* file;
	size_t filelen;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* request;
	size_t requestlen;

	// specific data for base types CMD, DPCHAPP, NOTIFY, POLL, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	Sbecore::ubigint jref;

	// specific data for base type TIMER
	Sbecore::ubigint wref;
	std::string sref;

	// specific data for base type EXTCALL
	Sbecore::Call* call;

	// specific data for base types CMD, DPCHAPP, UPLOAD, DOWNLOAD, DPCHRET, TIMER
	bool weak;

	// specific data for base type DPCHAPP
	DpchAppWzsk* dpchapp;

	// specific data for base types DPCHAPP, NOTIFY, POLL
	DpchEngWzsk* dpcheng;
	Sbecore::uint ixWzskVLocale;

	// specific data for base type DPCHRET
	DpchInvWzsk* dpchinv;
	DpchRetWzsk* dpchret;

	// specific data for base types DPCHAPP, NOTIFY, POLL, DPCHRET
	char* reply;
	size_t replylen;

	// specific data for base type METHOD
	Sbecore::Method* method;

public:
	void setStateReply();
};

/**
	* DcolWzsk
	*/
class DcolWzsk {

public:
	DcolWzsk(const Sbecore::ubigint jref = 0, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS);
	~DcolWzsk();

public:
	Sbecore::ubigint jref;

	Sbecore::uint ixWzskVLocale;

	Sbecore::Mutex mAccess;

	bool hot;

	std::list<DpchEngWzsk*> dpchs;

	ReqWzsk* req;

public:
	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* JobWzsk
	*/
class JobWzsk {

public:
	JobWzsk(XchgWzsk* xchg, const Sbecore::uint ixWzskVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS);
	virtual ~JobWzsk();

public:
	XchgWzsk* xchg;

	Sbecore::ubigint jref;

	Sbecore::uint ixWzskVJob;

	Sbecore::uint ixWzskVLocale;

	Sbecore::Mutex mAccess;

	bool muteRefresh;

	Sbecore::uint ixVSge;
	Sbecore::uint nextIxVSgeSuccess;
	Sbecore::uint nextIxVSgeFailure;

	std::string lasterror;

	Sbecore::uint opN;
	Sbecore::uint opNSuccess;
	Sbecore::uint opNFailure;

	std::vector<DpchInvWzsk*> invs;

	Sbecore::Mutex mOps;
	std::list<Sbecore::Op*> ops;
	std::string opsqkLast;

	Sbecore::ubigint wrefLast;
	Sbecore::ubigint wrefMin;

	ReqWzsk* reqCmd;

public:
	virtual DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	virtual void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void refreshWithDpchEng(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng = NULL, const bool unmute = false);

	virtual std::string getSquawk(DbsWzsk* dbswzsk);

	virtual void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);
	virtual void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

	void lockAccess(const std::string& srefObject, const std::string& srefMember);
	bool trylockAccess(const std::string& srefObject, const std::string& srefMember);
	void unlockAccess(const std::string& srefObject, const std::string& srefMember);

	void lockAccess(const std::string& srefMember);
	bool trylockAccess(const std::string& srefMember);
	void unlockAccess(const std::string& srefMember);

	void setStage(DbsWzsk* dbswzsk, const Sbecore::uint _ixVSge);

	void clearInvs();
	Sbecore::ubigint addInv(DpchInvWzsk* inv);
	void addInvs(std::vector<DpchInvWzsk*>& _invs);
	void submitInvs(DbsWzsk* dbswzsk, const Sbecore::uint nextIxVSgeEmpty, Sbecore::uint& _ixVSge);

	void clearOps();
	void addOp(DbsWzsk* dbswzsk, DpchInvWzsk* inv);
	void removeOp(const Sbecore::ubigint oref);
	std::string getOpsqkLast();

	void callback(const Sbecore::uint nextIxVSge);
	void invalidateWakeups();
};

/**
	* CsjobWzsk
	*/
class CsjobWzsk : public JobWzsk {

public:
	CsjobWzsk(XchgWzsk* xchg, const Sbecore::uint ixWzskVJob = 0, const Sbecore::ubigint jrefSup = 0, const Sbecore::uint ixWzskVLocale = VecWzskVLocale::ENUS);

public:
	bool srvNotCli;
	CsjobWzsk* srv; // client

public:
	virtual bool handleClaim(DbsWzsk* dbswzsk, std::map<Sbecore::ubigint,Sbecore::Claim*>& claims, const Sbecore::ubigint jrefNewest); // server
};

/**
	* ShrdatWzsk
	*/
class ShrdatWzsk {

public:
	ShrdatWzsk(const std::string& srefSupclass, const std::string& srefObject);
	~ShrdatWzsk();

public:
	std::string srefSupclass;
	std::string srefObject;

	Sbecore::Rwmutex rwmAccess;

public:
	virtual void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
	virtual void term(XchgWzsk* xchg);

	void rlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void runlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void rlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void runlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);

	void wlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wunlockAccess(const std::string& srefObject, const std::string& srefMember, const std::string& args = "");
	void wlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
	void wunlockAccess(const Sbecore::ubigint jref, const std::string& srefMember);
};

/**
	* StmgrWzsk
	*/
class StmgrWzsk {

public:
	StmgrWzsk(XchgWzsk* xchg, const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	~StmgrWzsk();

public:
	XchgWzsk* xchg;

	Sbecore::ubigint jref;
	Sbecore::uint ixVNonetype;

	Sbecore::Stcch* stcch;

	Sbecore::Mutex mAccess;

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);
	bool refresh(DbsWzsk* dbswzsk, Sbecore::Stcchitem* stit);

	void begin();
	void commit();

	void lockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
	void unlockAccess(const std::string& srefObject = "", const std::string& srefMember = "");
};

/**
	* WakeupWzsk
	*/
class WakeupWzsk {

public:
	WakeupWzsk(XchgWzsk* xchg, const Sbecore::ubigint wref, const Sbecore::ubigint jref, const std::string sref, const unsigned int deltat = 0, const bool weak = false);

public:
	XchgWzsk* xchg;

	Sbecore::ubigint wref;

	Sbecore::ubigint jref;
	std::string sref;
	unsigned int deltat;
	bool weak;
};

/**
	* ExtcallWzsk
	*/
class ExtcallWzsk {

public:
	ExtcallWzsk(XchgWzsk* xchg, Sbecore::Call* call);

public:
	XchgWzsk* xchg;
	Sbecore::Call* call;
};

/**
	* XchgWzskcmbd
	*/
class XchgWzskcmbd {

public:
	/**
		* ShrdatJobprc
		*/
	class ShrdatJobprc : public ShrdatWzsk {

	public:
		// IP ShrdatJobprc.subs --- INSERT

	public:
		ShrdatJobprc();

	public:
		// IP ShrdatJobprc.vars --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

	/**
		* ShrdatOpprc
		*/
	class ShrdatOpprc : public ShrdatWzsk {

	public:
		// IP ShrdatOpprc.subs --- INSERT

	public:
		ShrdatOpprc();

	public:
		// IP ShrdatOpprc.vars --- INSERT

	public:
		void init(XchgWzsk* xchg, DbsWzsk* dbswzsk);
		void term(XchgWzsk* xchg);
	};

public:
	XchgWzskcmbd();
	~XchgWzskcmbd();

public:
	StgWzskAppearance stgwzskappearance;
	StgWzskAppsrv stgwzskappsrv;
	StgWzskCamera stgwzskcamera;
	StgWzskcmbd stgwzskcmbd;
	StgWzskDatabase stgwzskdatabase;
	StgWzskDdspub stgwzskddspub;
	StgWzskFramegeo stgwzskframegeo;
	StgWzskGlobal stgwzskglobal;
	StgWzskPath stgwzskpath;
	StgWzskUasrv stgwzskuasrv;

	ShrdatJobprc shrdatJobprc;
	ShrdatOpprc shrdatOpprc;

public:
	// IP cust --- INSERT

public:
	// executable/archive/temporary folder paths and help URL
	std::string exedir;
	std::string acvpath;
	std::string tmppath;
	std::string helpurl;

	std::string key;
	std::string cert;

	// condition for thread start-up
	Sbecore::Cond cStable;

	// root job
	Sbecore::ubigint jrefRoot;

	// job receiving commands
	Sbecore::ubigint jrefCmd;

	// monitor object
	Sbecore::TxtMon mon;

	// log file
	Sbecore::Mutex mLogfile;

	// condition for job processors
	Sbecore::Cond cJobprcs;

	// condition for op processors
	Sbecore::Cond cOpprcs;

#if defined(SBECORE_DDS)
	// condition for DDS publisher
	Sbecore::Cond cDdspub;
#endif

#if defined(SBECORE_UA)
	// condition for OPC UA server
	Sbecore::Cond cUasrv;
#endif

	// request list
	Sbecore::Mutex mReqs;
	std::list<ReqWzsk*> reqs;

	// operation invocation list
	Sbecore::Refseq orefseq;
	Sbecore::Mutex mInvs;
	std::list<DpchInvWzsk*> invs;

	// presetting list
	Sbecore::Rwmutex rwmPresets;
	std::multimap<Sbecore::presetref_t,Sbecore::Preset*> presets;

	// stub manager list
	Sbecore::Rwmutex rwmStmgrs;
	std::map<Sbecore::ubigint,StmgrWzsk*> stmgrs;

	// call listener list
	Sbecore::Rwmutex rwmClstns;
	std::multimap<Sbecore::clstnref_t,Sbecore::Clstn*> clstns;
	std::multimap<Sbecore::clstnref2_t,Sbecore::clstnref_t> cref2sClstns;

	// dispatch collector list
	Sbecore::Rwmutex rwmDcols;
	std::map<Sbecore::ubigint,DcolWzsk*> dcols;

	// job list
	Sbecore::Refseq jrefseq;
	Sbecore::Rwmutex rwmJobs;
	std::map<Sbecore::ubigint,JobWzsk*> jobs;
	std::map<Sbecore::ubigint,Sbecore::uint> ixWzskVJobs;
	std::map<Sbecore::ubigint,Sbecore::Jobinfo*> jobinfos;

	// client/server job information
	Sbecore::Rwmutex rwmCsjobinfos;
	std::map<Sbecore::uint,Sbecore::Csjobinfo*> csjobinfos;

#if defined(SBECORE_DDS)
	// DDS publisher call
	Sbecore::Mutex mDdspubcall;
	Sbecore::Call* ddspubcall;
#endif

#if defined(SBECORE_UA)
	// OPC UA server call
	Sbecore::Mutex mUasrvcall;
	Sbecore::Call* uasrvcall;
#endif

	// sequence for wakeup references
	Sbecore::Refseq wrefseq;

public:
	// monitor object methods
	void startMon();
	void stopMon();

	// log file methods
	void appendToLogfile(const std::string& str);

	// request list methods
	void addReq(ReqWzsk* req);
	ReqWzsk* pullFirstReq();

	// operation invocation list methods
	void addInvs(DbsWzsk* dbswzsk, JobWzsk* job, std::vector<DpchInvWzsk*>& dpchinvs);
	DpchInvWzsk* pullFirstInv();

	// presetting methods
	Sbecore::Preset* addPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const Sbecore::Arg& arg);

	Sbecore::Preset* addIxPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const Sbecore::uint ix);
	Sbecore::Preset* addRefPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const Sbecore::ubigint ref);
	Sbecore::Preset* addRefsPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const std::vector<Sbecore::ubigint>& refs);
	Sbecore::Preset* addSrefPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const std::string& sref);
	Sbecore::Preset* addIntvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const int intval);
	Sbecore::Preset* addDblvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const double dblval);
	Sbecore::Preset* addBoolvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const bool boolval);
	Sbecore::Preset* addTxtvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref, const std::string& txtval);

	Sbecore::Preset* getPresetByPref(const Sbecore::presetref_t& pref);

	Sbecore::Arg getPreset(const Sbecore::uint ixWzskVPreset, Sbecore::ubigint jref);

	Sbecore::uint getIxPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	Sbecore::ubigint getRefPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	std::vector<Sbecore::ubigint> getRefsPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	std::string getSrefPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	int getIntvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	double getDblvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	bool getBoolvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	std::string getTxtvalPreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);

	void getPresetsByJref(const Sbecore::ubigint jref, std::vector<Sbecore::uint>& icsWzskVPreset, std::vector<Sbecore::Arg>& args);

	void removePreset(const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jref);
	void removePresetsByJref(const Sbecore::ubigint jref);

	// stub manager methods
	StmgrWzsk* addStmgr(const Sbecore::ubigint jref, const Sbecore::uint ixVNonetype);
	StmgrWzsk* getStmgrByJref(const Sbecore::ubigint jref);
	void removeStmgrByJref(const Sbecore::ubigint jref);

	// call listener list methods
	Sbecore::Clstn* addClstn(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig = 0, const bool chgarg = false, const Sbecore::Arg& arg = Sbecore::Arg(), const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addIxClstn(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addRefClstn(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefClstn(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);
	Sbecore::Clstn* addIxRefSrefClstn(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVJobmask, const Sbecore::ubigint jrefTrig, const bool chgarg, const Sbecore::uint ix, const Sbecore::ubigint ref, const std::string& sref, const Sbecore::uint ixVSge = 0, const Sbecore::uint ixVJactype = Sbecore::Clstn::VecVJactype::LOCK);

	Sbecore::Clstn* addClstnStmgr(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref);
#if defined(SBECORE_DDS)
	Sbecore::Clstn* addClstnDdspub(const Sbecore::ubigint jrefTrig, const std::string& sref, const bool shrdatNotDat);
#endif
#if defined(SBECORE_UA)
	Sbecore::Clstn* addClstnUasrv(const Sbecore::ubigint jrefTrig, const std::string& sref, const bool shrdatNotDat);
#endif

	Sbecore::Clstn* getClstnByCref(const Sbecore::clstnref_t& cref);
	void getClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget, std::vector<Sbecore::uint>& icsWzskVCall, std::vector<Sbecore::uint>& icsVJobmask);

	void removeClstns(const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);
	void removeClstnsByJref(const Sbecore::ubigint jref, const Sbecore::uint ixVTarget = Sbecore::Clstn::VecVTarget::JOB);

	// call methods
	void findJrefsByCall(Sbecore::Call* call, std::vector<Sbecore::ubigint>& jrefTrigs, std::vector<Sbecore::ubigint>& jrefs, std::vector<Sbecore::uint>& icsVTarget, std::vector<Sbecore::uint>& icsVJactype);

	void triggerCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

	bool triggerArgToArgCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::Arg& argInv, Sbecore::Arg& argRet);
	bool triggerCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref);
	bool triggerIxCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv);
	bool triggerRefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv);
	bool triggerIntvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const int intvalInv);
	bool triggerBoolvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const bool boolvalInv);
	bool triggerIxRefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv);
	bool triggerIxSrefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv);
	bool triggerIxSrefToIxCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& srefInv, Sbecore::uint& ixRet);
	bool triggerIxIntvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const int intvalInv);
	bool triggerIxDblvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const double dblvalInv);
	bool triggerIxTxtvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const std::string& txtvalInv);
	bool triggerSrefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const std::string& srefInv);
	bool triggerToBoolvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, bool& boolvalRet);
	bool triggerIxToBoolvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, bool& boolvalRet);
	bool triggerRefToSrefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, std::string& srefRet);
	bool triggerRefToBoolvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, bool& boolvalRet);
	bool triggerIxRefToIxCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerIxRefToRefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, Sbecore::ubigint& refRet);
	bool triggerIxRefSrefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv);
	bool triggerIxRefSrefIntvalCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv);
	bool triggerIxRefSrefIntvalToRefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::uint ixInv, const Sbecore::ubigint refInv, const std::string& srefInv, const int intvalInv, Sbecore::ubigint& refRet);
	bool triggerRefToIxCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const Sbecore::ubigint refInv, Sbecore::uint& ixRet);
	bool triggerSrefToRefCall(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVCall, const Sbecore::ubigint jref, const std::string& srefInv, Sbecore::ubigint& refRet);

	// dispatch collector list methods
	DcolWzsk* addDcol(const Sbecore::ubigint jref);
	DcolWzsk* getDcolByJref(Sbecore::ubigint jref, const bool tree = true);
	void removeDcolByJref(const Sbecore::ubigint jref);
	void removeDcolsByJref(const Sbecore::ubigint jref);

	void submitDpch(DpchEngWzsk* dpcheng);
	DpchEngWzsk* pullFirstDpch(DcolWzsk* dcol);

	// job list methods
	Sbecore::ubigint addJob(DbsWzsk* dbswzsk, JobWzsk* job, const Sbecore::ubigint jrefSup);
	JobWzsk* getJobByJref(const Sbecore::ubigint jref);
	Sbecore::Jobinfo* getJobinfoByJref(const Sbecore::ubigint jref);
	void removeJobByJref(const Sbecore::ubigint jref);

	bool getJobSup(const Sbecore::ubigint jrefSup, Sbecore::ubigint jref);
	void setJobStage(DbsWzsk* dbswzsk, JobWzsk* job, const Sbecore::uint ixVSge);

	// client/server job methods
	void addCsjobClaim(DbsWzsk* dbswzsk, CsjobWzsk* csjob, Sbecore::Claim* claim);

	bool getCsjobClaim(CsjobWzsk* csjob, bool& takenNotAvailable, bool& fulfilled, bool& run);
	bool getCsjobClaim(CsjobWzsk* csjob, bool& takenNotAvailable, bool& fulfilled);

	void clearCsjobRun(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVJob);

	void removeCsjobClaim(DbsWzsk* dbswzsk, CsjobWzsk* csjob);

	bool getCsjobNotJob(const Sbecore::uint ixWzskVJob);
	std::set<Sbecore::ubigint> getCsjobClisByJref(const Sbecore::ubigint jref);

	// timer methods
	Sbecore::ubigint addWakeup(const Sbecore::ubigint jref, const std::string sref, const unsigned int deltat = 0, const bool weak = false);
	static void* runWakeup(void* arg);

	// external call methods
	static void runExtcall(void* arg);
};
#endif

