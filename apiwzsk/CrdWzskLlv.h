/**
	* \file CrdWzskLlv.h
	* API code for job CrdWzskLlv (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef CRDWZSKLLV_H
#define CRDWZSKLLV_H

#include "ApiWzsk_blks.h"

#define VecVWzskLlvDo CrdWzskLlv::VecVDo
#define VecVWzskLlvSge CrdWzskLlv::VecVSge

#define ContInfWzskLlv CrdWzskLlv::ContInf
#define StatAppWzskLlv CrdWzskLlv::StatApp
#define StatShrWzskLlv CrdWzskLlv::StatShr
#define TagWzskLlv CrdWzskLlv::Tag

#define DpchAppWzskLlvDo CrdWzskLlv::DpchAppDo
#define DpchEngWzskLlvData CrdWzskLlv::DpchEngData

/**
	* CrdWzskLlv
	*/
namespace CrdWzskLlv {
	/**
		* VecVDo (full: VecVWzskLlvDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint CLOSE = 1;
		static const Sbecore::uint MITAPPABTCLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVWzskLlvSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint ALRWZSKABT = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskLlv)
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
	  * StatApp (full: StatAppWzskLlv)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVREQITMODE = 1;
		static const Sbecore::uint LATENCY = 2;
		static const Sbecore::uint SHORTMENU = 3;
		static const Sbecore::uint WIDTHMENU = 4;
		static const Sbecore::uint INITDONETERM = 5;
		static const Sbecore::uint INITDONECAMERA = 6;
		static const Sbecore::uint INITDONETTABLE = 7;
		static const Sbecore::uint INITDONELASER = 8;
		static const Sbecore::uint INITDONEHEADBAR = 9;

	public:
		StatApp(const Sbecore::uint ixWzskVReqitmode = VecWzskVReqitmode::IDLE, const Sbecore::usmallint latency = 5, const std::string& shortMenu = "", const Sbecore::uint widthMenu = 0, const bool initdoneTerm = false, const bool initdoneCamera = false, const bool initdoneTtable = false, const bool initdoneLaser = false, const bool initdoneHeadbar = false);

	public:
		Sbecore::uint ixWzskVReqitmode;
		Sbecore::usmallint latency;
		std::string shortMenu;
		Sbecore::uint widthMenu;
		bool initdoneTerm;
		bool initdoneCamera;
		bool initdoneTtable;
		bool initdoneLaser;
		bool initdoneHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLlv)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SCRJREFTERM = 1;
		static const Sbecore::uint PNLTERMAVAIL = 2;
		static const Sbecore::uint SCRJREFCAMERA = 3;
		static const Sbecore::uint SCRJREFTTABLE = 4;
		static const Sbecore::uint SCRJREFLASER = 5;
		static const Sbecore::uint SCRJREFHEADBAR = 6;

	public:
		StatShr(const std::string& scrJrefTerm = "", const bool pnltermAvail = false, const std::string& scrJrefCamera = "", const std::string& scrJrefTtable = "", const std::string& scrJrefLaser = "", const std::string& scrJrefHeadbar = "");

	public:
		std::string scrJrefTerm;
		bool pnltermAvail;
		std::string scrJrefCamera;
		std::string scrJrefTtable;
		std::string scrJrefLaser;
		std::string scrJrefHeadbar;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLlv)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint MITAPPABT = 1;
		static const Sbecore::uint MRLAPPHLP = 2;

	public:
		Tag(const std::string& MitAppAbt = "", const std::string& MrlAppHlp = "");

	public:
		std::string MitAppAbt;
		std::string MrlAppHlp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvDo)
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
		* DpchEngData (full: DpchEngWzskLlvData)
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
