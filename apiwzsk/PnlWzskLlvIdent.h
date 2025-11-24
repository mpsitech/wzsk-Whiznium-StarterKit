/**
	* \file PnlWzskLlvIdent.h
	* API code for job PnlWzskLlvIdent (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKLLVIDENT_H
#define PNLWZSKLLVIDENT_H

#include "ApiWzsk_blks.h"

#define VecVWzskLlvIdentDo PnlWzskLlvIdent::VecVDo

#define ContInfWzskLlvIdent PnlWzskLlvIdent::ContInf
#define StatShrWzskLlvIdent PnlWzskLlvIdent::StatShr
#define TagWzskLlvIdent PnlWzskLlvIdent::Tag

#define DpchAppWzskLlvIdentDo PnlWzskLlvIdent::DpchAppDo
#define DpchEngWzskLlvIdentData PnlWzskLlvIdent::DpchEngData

/**
	* PnlWzskLlvIdent
	*/
namespace PnlWzskLlvIdent {
	/**
		* VecVDo (full: VecVWzskLlvIdentDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskLlvIdent)
	  */
	class ContInf : public Sbecore::Block {

	public:
		static const Sbecore::uint TXTSRF = 1;
		static const Sbecore::uint TXTVVE = 2;
		static const Sbecore::uint TXTVGH = 3;
		static const Sbecore::uint TXTVAU = 4;
		static const Sbecore::uint TXTVFM = 5;
		static const Sbecore::uint TXTVFD = 6;

	public:
		ContInf(const std::string& TxtSrf = "", const std::string& TxtVve = "", const std::string& TxtVgh = "", const std::string& TxtVau = "", const std::string& TxtVfm = "", const std::string& TxtVfd = "");

	public:
		std::string TxtSrf;
		std::string TxtVve;
		std::string TxtVgh;
		std::string TxtVau;
		std::string TxtVfm;
		std::string TxtVfd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLlvIdent)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND);

	public:
		Sbecore::uint ixWzskVExpstate;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLlvIdent)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDGVSP = 2;
		static const Sbecore::uint CPTSRF = 3;
		static const Sbecore::uint CPTVVE = 4;
		static const Sbecore::uint CPTVGH = 5;
		static const Sbecore::uint CPTVAU = 6;
		static const Sbecore::uint CPTVFM = 7;
		static const Sbecore::uint CPTVFD = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& HdgVsp = "", const std::string& CptSrf = "", const std::string& CptVve = "", const std::string& CptVgh = "", const std::string& CptVau = "", const std::string& CptVfm = "", const std::string& CptVfd = "");

	public:
		std::string Cpt;
		std::string HdgVsp;
		std::string CptSrf;
		std::string CptVve;
		std::string CptVgh;
		std::string CptVau;
		std::string CptVfm;
		std::string CptVfd;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskLlvIdentDo)
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
		* DpchEngData (full: DpchEngWzskLlvIdentData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATSHR = 3;
		static const Sbecore::uint TAG = 4;

	public:
		DpchEngData();

	public:
		ContInf continf;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
