/**
	* \file CrdWzskPrf.h
	* API code for job CrdWzskPrf (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef CRDWZSKPRF_H
#define CRDWZSKPRF_H

#include "ApiWzsk_blks.h"

#define VecVWzskPrfDo CrdWzskPrf::VecVDo
#define VecVWzskPrfSge CrdWzskPrf::VecVSge

#define ContInfWzskPrf CrdWzskPrf::ContInf
#define StatAppWzskPrf CrdWzskPrf::StatApp
#define StatShrWzskPrf CrdWzskPrf::StatShr
#define TagWzskPrf CrdWzskPrf::Tag

#define DpchAppWzskPrfDo CrdWzskPrf::DpchAppDo
#define DpchEngWzskPrfData CrdWzskPrf::DpchEngData

/**
	* CrdWzskPrf
	*/
namespace CrdWzskPrf {
	/**
		* VecVDo (full: VecVWzskPrfDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDRVRCLICK = 3;
		static const Sbecore::uint MITCRDSTOCLICK = 4;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskPrfSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZSKABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskPrf)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;
		static const Sbecore::uint MRLAPPHLP = 2;

	public:
		ContInf(const Sbecore::uint numFSge = 1, const std::string& MrlAppHlp = "");

	public:
		Sbecore::uint numFSge;
		std::string MrlAppHlp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppWzskPrf)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONEHEADBAR = 5;
		static const Sbecore::uint INITDONEDAEMON = 6;
		static const Sbecore::uint INITDONEGLOBAL = 7;
		static const Sbecore::uint INITDONEACQCORNER = 8;
		static const Sbecore::uint INITDONEACQHDR = 9;
		static const Sbecore::uint INITDONEACQPREVIEW = 10;
		static const Sbecore::uint INITDONEACQTRACE = 11;
		static const Sbecore::uint INITDONEACTLASER = 12;
		static const Sbecore::uint INITDONEACTROTARY = 13;
		static const Sbecore::uint INITDONEACTVISTOROT = 14;
		static const Sbecore::uint INITDONESRCDCVSP = 15;
		static const Sbecore::uint INITDONESRCSYSINFO = 16;
		static const Sbecore::uint INITDONESRCTIVSP = 17;
		static const Sbecore::uint INITDONESRCZUVSP = 18;

	public:
		StatApp(const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneHeadbar = false, const bool initdoneDaemon = false, const bool initdoneGlobal = false, const bool initdoneAcqCorner = false, const bool initdoneAcqHdr = false, const bool initdoneAcqPreview = false, const bool initdoneAcqTrace = false, const bool initdoneActLaser = false, const bool initdoneActRotary = false, const bool initdoneActVistorot = false, const bool initdoneSrcDcvsp = false, const bool initdoneSrcSysinfo = false, const bool initdoneSrcTivsp = false, const bool initdoneSrcZuvsp = false);

	public:
		Sbecore::uint ixWzskVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneHeadbar;
		bool initdoneDaemon;
		bool initdoneGlobal;
		bool initdoneAcqCorner;
		bool initdoneAcqHdr;
		bool initdoneAcqPreview;
		bool initdoneAcqTrace;
		bool initdoneActLaser;
		bool initdoneActRotary;
		bool initdoneActVistorot;
		bool initdoneSrcDcvsp;
		bool initdoneSrcSysinfo;
		bool initdoneSrcTivsp;
		bool initdoneSrcZuvsp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrf)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint SCRJREFHEADBAR = 1;
		static const Sbecore::uint SCRJREFDAEMON = 2;
		static const Sbecore::uint SCRJREFGLOBAL = 3;
		static const Sbecore::uint SCRJREFACQCORNER = 4;
		static const Sbecore::uint SCRJREFACQHDR = 5;
		static const Sbecore::uint SCRJREFACQPREVIEW = 6;
		static const Sbecore::uint SCRJREFACQTRACE = 7;
		static const Sbecore::uint SCRJREFACTLASER = 8;
		static const Sbecore::uint SCRJREFACTROTARY = 9;
		static const Sbecore::uint SCRJREFACTVISTOROT = 10;
		static const Sbecore::uint SCRJREFSRCDCVSP = 11;
		static const Sbecore::uint SCRJREFSRCSYSINFO = 12;
		static const Sbecore::uint SCRJREFSRCTIVSP = 13;
		static const Sbecore::uint SCRJREFSRCZUVSP = 14;

	public:
		StatShr(const std::string& scrJrefHeadbar = "", const std::string& scrJrefDaemon = "", const std::string& scrJrefGlobal = "", const std::string& scrJrefAcqCorner = "", const std::string& scrJrefAcqHdr = "", const std::string& scrJrefAcqPreview = "", const std::string& scrJrefAcqTrace = "", const std::string& scrJrefActLaser = "", const std::string& scrJrefActRotary = "", const std::string& scrJrefActVistorot = "", const std::string& scrJrefSrcDcvsp = "", const std::string& scrJrefSrcSysinfo = "", const std::string& scrJrefSrcTivsp = "", const std::string& scrJrefSrcZuvsp = "");

	public:
		std::string scrJrefHeadbar;
		std::string scrJrefDaemon;
		std::string scrJrefGlobal;
		std::string scrJrefAcqCorner;
		std::string scrJrefAcqHdr;
		std::string scrJrefAcqPreview;
		std::string scrJrefAcqTrace;
		std::string scrJrefActLaser;
		std::string scrJrefActRotary;
		std::string scrJrefActVistorot;
		std::string scrJrefSrcDcvsp;
		std::string scrJrefSrcSysinfo;
		std::string scrJrefSrcTivsp;
		std::string scrJrefSrcZuvsp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskPrf)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDRVR = 3;
		static const Sbecore::uint MITCRDSTO = 4;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdRvr = "", const std::string& MitCrdSto = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdRvr;
		std::string MitCrdSto;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskPrfDo)
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
		* DpchEngData (full: DpchEngWzskPrfData)
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
