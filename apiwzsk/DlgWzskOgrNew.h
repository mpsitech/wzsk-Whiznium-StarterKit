/**
	* \file DlgWzskOgrNew.h
	* API code for job DlgWzskOgrNew (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef DLGWZSKOGRNEW_H
#define DLGWZSKOGRNEW_H

#include "ApiWzsk_blks.h"

#define VecVDlgWzskOgrNewDo DlgWzskOgrNew::VecVDo
#define VecVDlgWzskOgrNewSge DlgWzskOgrNew::VecVSge

#define ContIacDlgWzskOgrNew DlgWzskOgrNew::ContIac
#define ContInfDlgWzskOgrNew DlgWzskOgrNew::ContInf
#define StatAppDlgWzskOgrNew DlgWzskOgrNew::StatApp
#define StatShrDlgWzskOgrNew DlgWzskOgrNew::StatShr
#define TagDlgWzskOgrNew DlgWzskOgrNew::Tag

#define DpchAppDlgWzskOgrNewData DlgWzskOgrNew::DpchAppData
#define DpchAppDlgWzskOgrNewDo DlgWzskOgrNew::DpchAppDo
#define DpchEngDlgWzskOgrNewData DlgWzskOgrNew::DpchEngData

/**
	* DlgWzskOgrNew
	*/
namespace DlgWzskOgrNew {
	/**
		* VecVDo (full: VecVDlgWzskOgrNewDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTCNCCLICK = 1;
		static const Sbecore::uint BUTCRECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* VecVSge (full: VecVDlgWzskOgrNewSge)
		*/
	class VecVSge {

	public:
		static const Sbecore::uint IDLE = 1;
		static const Sbecore::uint CREATE = 2;
		static const Sbecore::uint DONE = 3;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacDlgWzskOgrNew)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPSUP = 1;
		static const Sbecore::uint TXFSRF = 2;
		static const Sbecore::uint NUMFPUPLCL = 3;
		static const Sbecore::uint TXFTIT = 4;
		static const Sbecore::uint TXFCMT = 5;

	public:
		ContIac(const Sbecore::uint numFPupSup = 1, const std::string& TxfSrf = "", const Sbecore::uint numFPupLcl = 1, const std::string& TxfTit = "", const std::string& TxfCmt = "");

	public:
		Sbecore::uint numFPupSup;
		std::string TxfSrf;
		Sbecore::uint numFPupLcl;
		std::string TxfTit;
		std::string TxfCmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfDlgWzskOgrNew)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFSGE = 1;

	public:
		ContInf(const Sbecore::uint numFSge = 1);

	public:
		Sbecore::uint numFSge;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatApp (full: StatAppDlgWzskOgrNew)
	  */
	class StatApp : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint SHORTMENU = 1;

	public:
		StatApp(const std::string& shortMenu = "");

	public:
		std::string shortMenu;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrDlgWzskOgrNew)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCNCACTIVE = 1;
		static const Sbecore::uint BUTCREACTIVE = 2;

	public:
		StatShr(const bool ButCncActive = true, const bool ButCreActive = true);

	public:
		bool ButCncActive;
		bool ButCreActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagDlgWzskOgrNew)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTSUP = 2;
		static const Sbecore::uint CPTSRF = 3;
		static const Sbecore::uint CPTLCL = 4;
		static const Sbecore::uint CPTTIT = 5;
		static const Sbecore::uint CPTCMT = 6;
		static const Sbecore::uint BUTCNC = 7;
		static const Sbecore::uint BUTCRE = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptSup = "", const std::string& CptSrf = "", const std::string& CptLcl = "", const std::string& CptTit = "", const std::string& CptCmt = "", const std::string& ButCnc = "", const std::string& ButCre = "");

	public:
		std::string Cpt;
		std::string CptSup;
		std::string CptSrf;
		std::string CptLcl;
		std::string CptTit;
		std::string CptCmt;
		std::string ButCnc;
		std::string ButCre;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppDlgWzskOgrNewData)
		*/
	class DpchAppData : public DpchAppWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint ALL = 3;

	public:
		DpchAppData(const std::string& scrJref = "", ContIac* contiac = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContIac contiac;

	public:
		std::string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWzskOgrNewDo)
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
		* DpchEngData (full: DpchEngDlgWzskOgrNewData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPLCL = 4;
		static const Sbecore::uint FEEDFPUPSUP = 5;
		static const Sbecore::uint FEEDFSGE = 6;
		static const Sbecore::uint STATAPP = 7;
		static const Sbecore::uint STATSHR = 8;
		static const Sbecore::uint TAG = 9;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupLcl;
		Sbecore::Xmlio::Feed feedFPupSup;
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

