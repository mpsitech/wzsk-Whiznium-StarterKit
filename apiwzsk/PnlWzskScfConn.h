/**
	* \file PnlWzskScfConn.h
	* API code for job PnlWzskScfConn (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifndef PNLWZSKSCFCONN_H
#define PNLWZSKSCFCONN_H

#include "ApiWzsk_blks.h"

#define VecVWzskScfConnDo PnlWzskScfConn::VecVDo

#define StatShrWzskScfConn PnlWzskScfConn::StatShr
#define TagWzskScfConn PnlWzskScfConn::Tag

#define DpchAppWzskScfConnDo PnlWzskScfConn::DpchAppDo
#define DpchEngWzskScfConnData PnlWzskScfConn::DpchEngData

/**
	* PnlWzskScfConn
	*/
namespace PnlWzskScfConn {
	/**
		* VecVDo (full: VecVWzskScfConnDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * StatShr (full: StatShrWzskScfConn)
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
	  * Tag (full: TagWzskScfConn)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;

	public:
		Tag(const std::string& Cpt = "");

	public:
		std::string Cpt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppDo (full: DpchAppWzskScfConnDo)
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
		* DpchEngData (full: DpchEngWzskScfConnData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint STATSHR = 2;
		static const Sbecore::uint TAG = 3;

	public:
		DpchEngData();

	public:
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
