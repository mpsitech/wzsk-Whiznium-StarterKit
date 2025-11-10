/**
	* \file PnlWzskNavAdmin.h
	* API code for job PnlWzskNavAdmin (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKNAVADMIN_H
#define PNLWZSKNAVADMIN_H

#include "ApiWzsk_blks.h"

#define VecVWzskNavAdminDo PnlWzskNavAdmin::VecVDo

#define ContIacWzskNavAdmin PnlWzskNavAdmin::ContIac
#define StatAppWzskNavAdmin PnlWzskNavAdmin::StatApp
#define StatShrWzskNavAdmin PnlWzskNavAdmin::StatShr
#define TagWzskNavAdmin PnlWzskNavAdmin::Tag

#define DpchAppWzskNavAdminData PnlWzskNavAdmin::DpchAppData
#define DpchAppWzskNavAdminDo PnlWzskNavAdmin::DpchAppDo
#define DpchEngWzskNavAdminData PnlWzskNavAdmin::DpchEngData

/**
	* PnlWzskNavAdmin
	*/
namespace PnlWzskNavAdmin {
	/**
		* VecVDo (full: VecVWzskNavAdminDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTUSGVIEWCLICK = 1;
		static const Sbecore::uint BUTUSGNEWCRDCLICK = 2;
		static const Sbecore::uint BUTUSRVIEWCLICK = 3;
		static const Sbecore::uint BUTUSRNEWCRDCLICK = 4;
		static const Sbecore::uint BUTPRSVIEWCLICK = 5;
		static const Sbecore::uint BUTPRSNEWCRDCLICK = 6;
		static const Sbecore::uint BUTPRFNEWCRDCLICK = 7;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskNavAdmin)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint NUMFLSTUSG = 1;
		static const Sbecore::uint NUMFLSTUSR = 2;
		static const Sbecore::uint NUMFLSTPRS = 3;

	public:
		ContIac(const Sbecore::uint numFLstUsg = 1, const Sbecore::uint numFLstUsr = 1, const Sbecore::uint numFLstPrs = 1);

	public:
		Sbecore::uint numFLstUsg;
		Sbecore::uint numFLstUsr;
		Sbecore::uint numFLstPrs;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatApp (full: StatAppWzskNavAdmin)
	  */
	class StatApp : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint LSTUSGALT = 2;
		static const Sbecore::uint LSTUSRALT = 3;
		static const Sbecore::uint LSTPRSALT = 4;
		static const Sbecore::uint LSTUSGNUMFIRSTDISP = 5;
		static const Sbecore::uint LSTUSRNUMFIRSTDISP = 6;
		static const Sbecore::uint LSTPRSNUMFIRSTDISP = 7;

	public:
		StatApp(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool LstUsgAlt = true, const bool LstUsrAlt = true, const bool LstPrsAlt = true, const Sbecore::uint LstUsgNumFirstdisp = 1, const Sbecore::uint LstUsrNumFirstdisp = 1, const Sbecore::uint LstPrsNumFirstdisp = 1);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool LstUsgAlt;
		bool LstUsrAlt;
		bool LstPrsAlt;
		Sbecore::uint LstUsgNumFirstdisp;
		Sbecore::uint LstUsrNumFirstdisp;
		Sbecore::uint LstPrsNumFirstdisp;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatApp* comp);
		std::set<Sbecore::uint> diff(const StatApp* comp);
	};

	/**
	  * StatShr (full: StatShrWzskNavAdmin)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint LSTUSGAVAIL = 1;
		static const Sbecore::uint BUTUSGVIEWACTIVE = 2;
		static const Sbecore::uint LSTUSRAVAIL = 3;
		static const Sbecore::uint BUTUSRVIEWACTIVE = 4;
		static const Sbecore::uint LSTPRSAVAIL = 5;
		static const Sbecore::uint BUTPRSVIEWACTIVE = 6;
		static const Sbecore::uint BUTPRFNEWCRDAVAIL = 7;

	public:
		StatShr(const bool LstUsgAvail = true, const bool ButUsgViewActive = true, const bool LstUsrAvail = true, const bool ButUsrViewActive = true, const bool LstPrsAvail = true, const bool ButPrsViewActive = true, const bool ButPrfNewcrdAvail = true);

	public:
		bool LstUsgAvail;
		bool ButUsgViewActive;
		bool LstUsrAvail;
		bool ButUsrViewActive;
		bool LstPrsAvail;
		bool ButPrsViewActive;
		bool ButPrfNewcrdAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskNavAdmin)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTUSG = 2;
		static const Sbecore::uint CPTUSR = 3;
		static const Sbecore::uint CPTPRS = 4;
		static const Sbecore::uint CPTPRF = 5;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptUsg = "", const std::string& CptUsr = "", const std::string& CptPrs = "", const std::string& CptPrf = "");

	public:
		std::string Cpt;
		std::string CptUsg;
		std::string CptUsr;
		std::string CptPrs;
		std::string CptPrf;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskNavAdminData)
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
		* DpchAppDo (full: DpchAppWzskNavAdminDo)
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
		* DpchEngData (full: DpchEngWzskNavAdminData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFLSTPRS = 3;
		static const Sbecore::uint FEEDFLSTUSG = 4;
		static const Sbecore::uint FEEDFLSTUSR = 5;
		static const Sbecore::uint STATAPP = 6;
		static const Sbecore::uint STATSHR = 7;
		static const Sbecore::uint TAG = 8;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFLstPrs;
		Sbecore::Feed feedFLstUsg;
		Sbecore::Feed feedFLstUsr;
		StatApp statapp;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
