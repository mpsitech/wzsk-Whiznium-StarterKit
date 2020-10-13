/**
	* \file CrdWzskScf.h
	* API code for job CrdWzskScf (declarations)
	* \author Catherine Johnson
	* \date created: 13 Oct 2020
	* \date modified: 13 Oct 2020
	*/

#ifndef CRDWZSKSCF_H
#define CRDWZSKSCF_H

#include "ApiWzsk_blks.h"

#define VecVWzskScfDo CrdWzskScf::VecVDo
#define VecVWzskScfSge CrdWzskScf::VecVSge

#define ContInfWzskScf CrdWzskScf::ContInf
#define StatAppWzskScf CrdWzskScf::StatApp
#define StatShrWzskScf CrdWzskScf::StatShr
#define TagWzskScf CrdWzskScf::Tag

#define DpchAppWzskScfDo CrdWzskScf::DpchAppDo
#define DpchEngWzskScfData CrdWzskScf::DpchEngData

/**
	* CrdWzskScf
	*/
namespace CrdWzskScf {
	/**
		* VecVDo (full: VecVWzskScfDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;
		static const Sbecore::uint MITCRDCMMCLICK = 3;
		static const Sbecore::uint MITCRDTTCCLICK = 4;
		static const Sbecore::uint MITCRDLSPCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskScfSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZSKABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskScf)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

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
	  * StatApp (full: StatAppWzskScf)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONECONN = 5;
		static const Sbecore::uint INITDONEGEOM = 6;
		static const Sbecore::uint INITDONEHEADBAR = 7;

	public:
		StatApp(const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneConn = false, const bool initdoneGeom = false, const bool initdoneHeadbar = false);

	public:
		Sbecore::uint ixWzskVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneConn;
		bool initdoneGeom;
		bool initdoneHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskScf)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFDLGCAMERAMAT = 1;
		static const Sbecore::uint SCRJREFDLGLASERPOS = 2;
		static const Sbecore::uint SCRJREFDLGTTABLECOORD = 3;
		static const Sbecore::uint SCRJREFCONN = 4;
		static const Sbecore::uint SCRJREFGEOM = 5;
		static const Sbecore::uint SCRJREFHEADBAR = 6;

	public:
		StatShr(const std::string& scrJrefDlgcameramat = "", const std::string& scrJrefDlglaserpos = "", const std::string& scrJrefDlgttablecoord = "", const std::string& scrJrefConn = "", const std::string& scrJrefGeom = "", const std::string& scrJrefHeadbar = "");

	public:
		std::string scrJrefDlgcameramat;
		std::string scrJrefDlglaserpos;
		std::string scrJrefDlgttablecoord;
		std::string scrJrefConn;
		std::string scrJrefGeom;
		std::string scrJrefHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskScf)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;
		static const Sbecore::uint MITCRDCMM = 3;
		static const Sbecore::uint MITCRDTTC = 4;
		static const Sbecore::uint MITCRDLSP = 5;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "", const std::string& MitCrdCmm = "", const std::string& MitCrdTtc = "", const std::string& MitCrdLsp = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;
		std::string MitCrdCmm;
		std::string MitCrdTtc;
		std::string MitCrdLsp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskScfDo)
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
		* DpchEngData (full: DpchEngWzskScfData)
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

