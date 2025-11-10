/**
	* \file CrdWzskNav.h
	* API code for job CrdWzskNav (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

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
		static const Sbecore::uint MITCRDPRFCLICK = 8;
		static const Sbecore::uint MITCRDLLVCLICK = 9;
		static const Sbecore::uint MITCRDVTRCLICK = 10;
		static const Sbecore::uint MITCRDHWCCLICK = 11;
		static const Sbecore::uint MITCRDFILCLICK = 12;
		static const Sbecore::uint MITAPPLOICLICK = 13;

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
		static const Sbecore::uint ALRWZSKTRM = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskNav)
	  */
	class ContInf : public Sbecore::Block {

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
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONEADMIN = 6;
		static const Sbecore::uint INITDONEOP = 7;

	public:
		StatApp(const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneAdmin = false, const bool initdoneOp = false);

	public:
		Sbecore::uint ixWzskVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneAdmin;
		bool initdoneOp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskNav)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFDLGLOAINI = 1;
		static const Sbecore::uint SCRJREFHEADBAR = 2;
		static const Sbecore::uint SCRJREFADMIN = 3;
		static const Sbecore::uint PNLADMINAVAIL = 4;
		static const Sbecore::uint SCRJREFOP = 5;
		static const Sbecore::uint PNLOPAVAIL = 6;
		static const Sbecore::uint MITSESSPSAVAIL = 7;
		static const Sbecore::uint MSPCRD1AVAIL = 8;
		static const Sbecore::uint MITCRDUSGAVAIL = 9;
		static const Sbecore::uint MITCRDUSRAVAIL = 10;
		static const Sbecore::uint MITCRDPRSAVAIL = 11;
		static const Sbecore::uint MITCRDPRFAVAIL = 12;
		static const Sbecore::uint MSPCRD2AVAIL = 13;
		static const Sbecore::uint MITCRDLLVAVAIL = 14;
		static const Sbecore::uint MITCRDVTRAVAIL = 15;
		static const Sbecore::uint MITCRDHWCAVAIL = 16;
		static const Sbecore::uint MITCRDFILAVAIL = 17;
		static const Sbecore::uint MSPAPP2AVAIL = 18;
		static const Sbecore::uint MITAPPLOIAVAIL = 19;

	public:
		StatShr(const std::string& scrJrefDlgloaini = "", const std::string& scrJrefHeadbar = "", const std::string& scrJrefAdmin = "", const bool pnladminAvail = false, const std::string& scrJrefOp = "", const bool pnlopAvail = false, const bool MitSesSpsAvail = true, const bool MspCrd1Avail = true, const bool MitCrdUsgAvail = true, const bool MitCrdUsrAvail = true, const bool MitCrdPrsAvail = true, const bool MitCrdPrfAvail = true, const bool MspCrd2Avail = true, const bool MitCrdLlvAvail = true, const bool MitCrdVtrAvail = true, const bool MitCrdHwcAvail = true, const bool MitCrdFilAvail = true, const bool MspApp2Avail = true, const bool MitAppLoiAvail = true);

	public:
		std::string scrJrefDlgloaini;
		std::string scrJrefHeadbar;
		std::string scrJrefAdmin;
		bool pnladminAvail;
		std::string scrJrefOp;
		bool pnlopAvail;
		bool MitSesSpsAvail;
		bool MspCrd1Avail;
		bool MitCrdUsgAvail;
		bool MitCrdUsrAvail;
		bool MitCrdPrsAvail;
		bool MitCrdPrfAvail;
		bool MspCrd2Avail;
		bool MitCrdLlvAvail;
		bool MitCrdVtrAvail;
		bool MitCrdHwcAvail;
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
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITSESSPS = 3;
		static const Sbecore::uint MITSESTRM = 4;
		static const Sbecore::uint MITCRDUSG = 5;
		static const Sbecore::uint MITCRDUSR = 6;
		static const Sbecore::uint MITCRDPRS = 7;
		static const Sbecore::uint MITCRDPRF = 8;
		static const Sbecore::uint MITCRDLLV = 9;
		static const Sbecore::uint MITCRDVTR = 10;
		static const Sbecore::uint MITCRDHWC = 11;
		static const Sbecore::uint MITCRDFIL = 12;
		static const Sbecore::uint MITAPPLOI = 13;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitSesSps = "", const std::string& MitSesTrm = "", const std::string& MitCrdUsg = "", const std::string& MitCrdUsr = "", const std::string& MitCrdPrs = "", const std::string& MitCrdPrf = "", const std::string& MitCrdLlv = "", const std::string& MitCrdVtr = "", const std::string& MitCrdHwc = "", const std::string& MitCrdFil = "", const std::string& MitAppLoi = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitSesSps;
		std::string MitSesTrm;
		std::string MitCrdUsg;
		std::string MitCrdUsr;
		std::string MitCrdPrs;
		std::string MitCrdPrf;
		std::string MitCrdLlv;
		std::string MitCrdVtr;
		std::string MitCrdHwc;
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
		Sbecore::Feed feedFSge;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
