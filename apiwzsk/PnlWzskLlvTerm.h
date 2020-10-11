/**
	* \file PnlWzskLlvTerm.h
	* API code for job PnlWzskLlvTerm (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef PNLWZSKLLVTERM_H
#define PNLWZSKLLVTERM_H

#include "ApiWzsk_blks.h"

#define VecVWzskLlvTermDo PnlWzskLlvTerm::VecVDo

#define ContIacWzskLlvTerm PnlWzskLlvTerm::ContIac
#define ContInfWzskLlvTerm PnlWzskLlvTerm::ContInf
#define StatShrWzskLlvTerm PnlWzskLlvTerm::StatShr
#define TagWzskLlvTerm PnlWzskLlvTerm::Tag

#define DpchAppWzskLlvTermData PnlWzskLlvTerm::DpchAppData
#define DpchAppWzskLlvTermDo PnlWzskLlvTerm::DpchAppDo
#define DpchEngWzskLlvTermData PnlWzskLlvTerm::DpchEngData

/**
	* PnlWzskLlvTerm
	*/
namespace PnlWzskLlvTerm {
	/**
		* VecVDo (full: VecVWzskLlvTermDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;
		static const Sbecore::uint BUTCLAIMCLICK = 3;
		static const Sbecore::uint BUTAPDCLICK = 4;
		static const Sbecore::uint BUTSMTCLICK = 5;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskLlvTerm)
	  */
	class ContIac : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint NUMFPUPCMD = 1;
		static const Sbecore::uint TXFCSQ = 2;

	public:
		ContIac(const Sbecore::uint numFPupCmd = 1, const std::string& TxfCsq = "");

	public:
		Sbecore::uint numFPupCmd;
		std::string TxfCsq;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * ContInf (full: ContInfWzskLlvTerm)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint BUTCLAIMON = 1;
		static const Sbecore::uint TXTCST = 2;
		static const Sbecore::uint TXTDATLOG = 3;

	public:
		ContInf(const bool ButClaimOn = false, const std::string& TxtCst = "", const std::string& TxtDatLog = "");

	public:
		bool ButClaimOn;
		std::string TxtCst;
		std::string TxtDatLog;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
	  * StatShr (full: StatShrWzskLlvTerm)
	  */
	class StatShr : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint BUTCLAIMACTIVE = 2;
		static const Sbecore::uint BUTSMTACTIVE = 3;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool ButClaimActive = true, const bool ButSmtActive = true);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool ButClaimActive;
		bool ButSmtActive;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskLlvTerm)
	  */
	class Tag : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint CPTCST = 2;
		static const Sbecore::uint HDGDIO = 3;
		static const Sbecore::uint HDGCEX = 4;
		static const Sbecore::uint CPTCMD = 5;
		static const Sbecore::uint BUTAPD = 6;
		static const Sbecore::uint CPTCSQ = 7;
		static const Sbecore::uint BUTSMT = 8;

	public:
		Tag(const std::string& Cpt = "", const std::string& CptCst = "", const std::string& HdgDio = "", const std::string& HdgCex = "", const std::string& CptCmd = "", const std::string& ButApd = "", const std::string& CptCsq = "", const std::string& ButSmt = "");

	public:
		std::string Cpt;
		std::string CptCst;
		std::string HdgDio;
		std::string HdgCex;
		std::string CptCmd;
		std::string ButApd;
		std::string CptCsq;
		std::string ButSmt;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskLlvTermData)
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
		* DpchAppDo (full: DpchAppWzskLlvTermDo)
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
		* DpchEngData (full: DpchEngWzskLlvTermData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint CONTINF = 3;
		static const Sbecore::uint FEEDFPUPCMD = 4;
		static const Sbecore::uint STATSHR = 5;
		static const Sbecore::uint TAG = 6;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		ContInf continf;
		Sbecore::Xmlio::Feed feedFPupCmd;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif

