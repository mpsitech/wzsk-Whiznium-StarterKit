/**
	* \file CrdWzskNav.h
	* job handler for job CrdWzskNav (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef CRDWZSKNAV_H
#define CRDWZSKNAV_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#include "PnlWzskNavGalery.h"
#include "PnlWzskNavOp.h"
#include "PnlWzskNavAdmin.h"
#include "PnlWzskNavPre.h"
#include "PnlWzskNavHeadbar.h"
#include "DlgWzskNavLoaini.h"

#define VecVWzskNavDo CrdWzskNav::VecVDo
#define VecVWzskNavSge CrdWzskNav::VecVSge

#define ContInfWzskNav CrdWzskNav::ContInf
#define StatAppWzskNav CrdWzskNav::StatApp
#define StatShrWzskNav CrdWzskNav::StatShr
#define TagWzskNav CrdWzskNav::Tag

#define DpchAppWzskNavDo CrdWzskNav::DpchAppDo
#define DpchEngWzskNavData CrdWzskNav::DpchEngData

/**
	* CrdWzskNav
	*/
class CrdWzskNav : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVWzskNavDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITSESSPSCLICK = 3;
		static const Sbecore::uint MITSESTRMCLICK = 4;
		static const Sbecore::uint MITCRDUSGCLICK = 5;
		static const Sbecore::uint MITCRDUSRCLICK = 6;
		static const Sbecore::uint MITCRDPRSCLICK = 7;
		static const Sbecore::uint MITCRDSCFCLICK = 8;
		static const Sbecore::uint MITCRDLLVCLICK = 9;
		static const Sbecore::uint MITCRDLIVCLICK = 10;
		static const Sbecore::uint MITCRDOGRCLICK = 11;
		static const Sbecore::uint MITCRDOBJCLICK = 12;
		static const Sbecore::uint MITCRDSESCLICK = 13;
		static const Sbecore::uint MITCRDSHTCLICK = 14;
		static const Sbecore::uint MITCRDFILCLICK = 15;
		static const Sbecore::uint MITAPPLOICLICK = 16;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskNavSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZSKABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);

		static void fillFeed(Sbecore::Xmlio::Feed& feed);
	};

	/**
	  * ContInf (full: ContInfWzskNav)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MTXSESSES1 = 3;
		static const Sbecore::uint MTXSESSES2 = 4;
		static const Sbecore::uint MTXSESSES3 = 5;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "", const std::string& MtxSesSes1 = "", const std::string& MtxSesSes2 = "", const std::string& MtxSesSes3 = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;
		std::string MtxSesSes1;
		std::string MtxSesSes2;
		std::string MtxSesSes3;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppWzskNav)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneOp = false, const bool initdoneGalery = false);
	};

	/**
		* StatShr (full: StatShrWzskNav)
		*/
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint JREFDLGLOAINI = 1;
		static const Sbecore::uint JREFHEADBAR = 2;
		static const Sbecore::uint JREFPRE = 3;
		static const Sbecore::uint PNLPREAVAIL = 4;
		static const Sbecore::uint JREFADMIN = 5;
		static const Sbecore::uint PNLADMINAVAIL = 6;
		static const Sbecore::uint JREFOP = 7;
		static const Sbecore::uint PNLOPAVAIL = 8;
		static const Sbecore::uint JREFGALERY = 9;
		static const Sbecore::uint PNLGALERYAVAIL = 10;
		static const Sbecore::uint MITSESSPSAVAIL = 11;
		static const Sbecore::uint MSPCRD1AVAIL = 12;
		static const Sbecore::uint MITCRDUSGAVAIL = 13;
		static const Sbecore::uint MITCRDUSRAVAIL = 14;
		static const Sbecore::uint MITCRDPRSAVAIL = 15;
		static const Sbecore::uint MITCRDSCFAVAIL = 16;
		static const Sbecore::uint MSPCRD2AVAIL = 17;
		static const Sbecore::uint MITCRDLLVAVAIL = 18;
		static const Sbecore::uint MITCRDLIVAVAIL = 19;
		static const Sbecore::uint MSPCRD3AVAIL = 20;
		static const Sbecore::uint MITCRDOGRAVAIL = 21;
		static const Sbecore::uint MITCRDOBJAVAIL = 22;
		static const Sbecore::uint MITCRDSESAVAIL = 23;
		static const Sbecore::uint MITCRDSHTAVAIL = 24;
		static const Sbecore::uint MITCRDFILAVAIL = 25;
		static const Sbecore::uint MSPAPP2AVAIL = 26;
		static const Sbecore::uint MITAPPLOIAVAIL = 27;

	public:
		StatShr(const Sbecore::ubigint jrefDlgloaini = 0, const Sbecore::ubigint jrefHeadbar = 0, const Sbecore::ubigint jrefPre = 0, const bool pnlpreAvail = false, const Sbecore::ubigint jrefAdmin = 0, const bool pnladminAvail = false, const Sbecore::ubigint jrefOp = 0, const bool pnlopAvail = false, const Sbecore::ubigint jrefGalery = 0, const bool pnlgaleryAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdScfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLlvAvail = true, const bool MitCrdLivAvail = true, const bool MspCrd3Avail = true, const bool MitCrdOgrAvail = true, const bool MitCrdObjAvail = true, const bool MitCrdSesAvail = true, const bool MitCrdShtAvail = true, const bool MitCrdFilAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		Sbecore::ubigint jrefDlgloaini;
		Sbecore::ubigint jrefHeadbar;
		Sbecore::ubigint jrefPre;
		bool pnlpreAvail;
		Sbecore::ubigint jrefAdmin;
		bool pnladminAvail;
		Sbecore::ubigint jrefOp;
		bool pnlopAvail;
		Sbecore::ubigint jrefGalery;
		bool pnlgaleryAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdScfAvail;
		bool MspCrd2Avail;
		bool MitCrdLlvAvail;
		bool MitCrdLivAvail;
		bool MspCrd3Avail;
		bool MitCrdOgrAvail;
		bool MitCrdObjAvail;
		bool MitCrdSesAvail;
		bool MitCrdShtAvail;
		bool MitCrdFilAvail;
		bool MspApp2Avail;
		bool MitAppLoiAvail;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
		* Tag (full: TagWzskNav)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngWzskNavData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;
		static const Sbecore::uint ALL = 7;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, Sbecore::Xmlio::Feed* feedFSge = NULL, StatShr* statshr = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatShr statshr;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

	bool evalPnlpreAvail(DbsWzsk* dbswzsk);
	bool evalPnladminAvail(DbsWzsk* dbswzsk);
	bool evalPnlopAvail(DbsWzsk* dbswzsk);
	bool evalPnlgaleryAvail(DbsWzsk* dbswzsk);
	bool evalMitSesSpsAvail(DbsWzsk* dbswzsk);
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
	bool evalMspApp2Avail(DbsWzsk* dbswzsk);
	bool evalMitAppLoiAvail(DbsWzsk* dbswzsk);

public:
	CrdWzskNav(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~CrdWzskNav();

public:
	ContInf continf;
	StatShr statshr;

	Sbecore::Xmlio::Feed feedFMcbAlert;
	Sbecore::Xmlio::Feed feedFSge;

	PnlWzskNavGalery* pnlgalery;
	PnlWzskNavOp* pnlop;
	PnlWzskNavAdmin* pnladmin;
	PnlWzskNavPre* pnlpre;
	PnlWzskNavHeadbar* pnlheadbar;
	DlgWzskNavLoaini* dlgloaini;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);
	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);
	void updatePreset(DbsWzsk* dbswzsk, const Sbecore::uint ixWzskVPreset, const Sbecore::ubigint jrefTrig, const bool notif = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoClose(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitAppAbtClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitSesSpsClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitSesTrmClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdUsgClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdUsrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdPrsClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdScfClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdLlvClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdLivClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdOgrClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdObjClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdSesClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdShtClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitCrdFilClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppDoMitAppLoiClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);
	void handleDpchAppWzskAlert(DbsWzsk* dbswzsk, DpchAppWzskAlert* dpchappwzskalert, DpchEngWzsk** dpcheng);

public:
	void handleCall(DbsWzsk* dbswzsk, Sbecore::Call* call);

private:
	bool handleCallWzskDlgClose(DbsWzsk* dbswzsk, const Sbecore::ubigint jrefTrig);

private:
	void changeStage(DbsWzsk* dbswzsk, Sbecore::uint _ixVSge, DpchEngWzsk** dpcheng = NULL);

public:
	std::string getSquawk(DbsWzsk* dbswzsk);

private:
	Sbecore::uint enterSgeIdle(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeIdle(DbsWzsk* dbswzsk);
	Sbecore::uint enterSgeAlrwzskabt(DbsWzsk* dbswzsk, const bool reenter);
	void leaveSgeAlrwzskabt(DbsWzsk* dbswzsk);

};

#endif

