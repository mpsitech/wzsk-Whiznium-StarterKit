/**
	* \file PnlWzskNavPre.h
	* API code for job PnlWzskNavPre (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKNAVPRE_H
#define PNLWZSKNAVPRE_H

#include "ApiWzsk_blks.h"

#define VecVWzskNavPreDo PnlWzskNavPre::VecVDo

#define ContInfWzskNavPre PnlWzskNavPre::ContInf
#define StatShrWzskNavPre PnlWzskNavPre::StatShr
#define TagWzskNavPre PnlWzskNavPre::Tag

#define DpchAppWzskNavPreDo PnlWzskNavPre::DpchAppDo
#define DpchEngWzskNavPreData PnlWzskNavPre::DpchEngData

/**
	* PnlWzskNavPre
	*/
namespace PnlWzskNavPre {
	/**
		* VecVDo (full: VecVWzskNavPreDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTOBJREMOVECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfWzskNavPre)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTOBJ = 1;

	public:
		ContInf(const std::string& TxtObj = "");

	public:
		std::string TxtObj;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskNavPre)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint TXTOBJAVAIL = 1;

	public:
		StatShr(const bool TxtObjAvail = true);

	public:
		bool TxtObjAvail;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskNavPre)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPTOBJ = 1;

	public:
		Tag(const std::string& CptObj = "");

	public:
		std::string CptObj;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskNavPreDo)
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
		* DpchEngData (full: DpchEngWzskNavPreData)
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

