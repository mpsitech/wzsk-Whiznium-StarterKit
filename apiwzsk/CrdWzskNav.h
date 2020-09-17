/**
	* \file CrdWzskNav.h
	* API code for job CrdWzskNav (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef CRDWZSKNAV_H
#define CRDWZSKNAV_H

#include "ApiWzsk_blks.h"

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
namespace CrdWzskNav {
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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskNav)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONEPRE = 6;
		static const Sbecore::uint INITDONEADMIN = 7;
		static const Sbecore::uint INITDONEOP = 8;
		static const Sbecore::uint INITDONEGALERY = 9;

	public:
		StatApp(const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdonePre = false, const bool initdoneAdmin = false, const bool initdoneOp = false, const bool initdoneGalery = false);

	public:
		Sbecore::uint ixWzskVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdonePre;
		bool initdoneAdmin;
		bool initdoneOp;
		bool initdoneGalery;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskNav)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFDLGLOAINI = 1;
		static const Sbecore::uint SCRJREFHEADBAR = 2;
		static const Sbecore::uint SCRJREFPRE = 3;
		static const Sbecore::uint PNLPREAVAIL = 4;
		static const Sbecore::uint SCRJREFADMIN = 5;
		static const Sbecore::uint PNLADMINAVAIL = 6;
		static const Sbecore::uint SCRJREFOP = 7;
		static const Sbecore::uint PNLOPAVAIL = 8;
		static const Sbecore::uint SCRJREFGALERY = 9;
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
		StatShr(const std::string& scrJrefDlgloaini = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefPre = "", const bool pnlpreAvail = false, const std::string& scrJrefAdmin = "", const bool pnladminAvail = false, const std::string& scrJrefOp = "", const bool pnlopAvail = false, const std::string& scrJrefGalery = "", const bool pnlgaleryAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdScfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLlvAvail = true, const bool MitCrdLivAvail = true, const bool MspCrd3Avail = true, const bool MitCrdOgrAvail = true, const bool MitCrdObjAvail = true, const bool MitCrdSesAvail = true, const bool MitCrdShtAvail = true, const bool MitCrdFilAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		std::string scrJrefDlgloaini;
		std::string scrJrefHeadbar;
		std::string scrJrefPre;
		bool pnlpreAvail;
		std::string scrJrefAdmin;
		bool pnladminAvail;
		std::string scrJrefOp;
		bool pnlopAvail;
		std::string scrJrefGalery;
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
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskNav)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITSESSPS = 3;
		static const Sbecore::uint MITSESTRM = 4;
		static const Sbecore::uint MITCRDUSG = 5;
		static const Sbecore::uint MITCRDUSR = 6;
		static const Sbecore::uint MITCRDPRS = 7;
		static const Sbecore::uint MITCRDSCF = 8;
		static const Sbecore::uint MITCRDLLV = 9;
		static const Sbecore::uint MITCRDLIV = 10;
		static const Sbecore::uint MITCRDOGR = 11;
		static const Sbecore::uint MITCRDOBJ = 12;
		static const Sbecore::uint MITCRDSES = 13;
		static const Sbecore::uint MITCRDSHT = 14;
		static const Sbecore::uint MITCRDFIL = 15;
		static const Sbecore::uint MITAPPLOI = 16;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitSesSps = "", const std::string& MitSesTrm = "", const std::string& MitCrdUsg = "", const std::string& MitCrdUsr = "", const std::string& MitCrdPrs = "", const std::string& MitCrdScf = "", const std::string& MitCrdLlv = "", const std::string& MitCrdLiv = "", const std::string& MitCrdOgr = "", const std::string& MitCrdObj = "", const std::string& MitCrdSes = "", const std::string& MitCrdSht = "", const std::string& MitCrdFil = "", const std::string& MitAppLoi = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitSesSps;
		std::string MitSesTrm;
		std::string MitCrdUsg;
		std::string MitCrdUsr;
		std::string MitCrdPrs;
		std::string MitCrdScf;
		std::string MitCrdLlv;
		std::string MitCrdLiv;
		std::string MitCrdOgr;
		std::string MitCrdObj;
		std::string MitCrdSes;
		std::string MitCrdSht;
		std::string MitCrdFil;
		std::string MitAppLoi;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint IXVDO = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppDo(const std::string& scrJref = "", const Sbecore::uint ixVDo = 0, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchEngData (full: DpchEngWzskNavData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint FEEDFSGE = 3;
		static const Sbecore::uint STATAPP = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContInf continf;
		Sbecore::Xmlio::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

