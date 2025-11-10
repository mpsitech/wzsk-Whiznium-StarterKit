/**
	* \file PnlWzskPrfDaemon.h
	* API code for job PnlWzskPrfDaemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
	*/
// IP header --- ABOVE

#ifndef PNLWZSKPRFDAEMON_H
#define PNLWZSKPRFDAEMON_H

#include "ApiWzsk_blks.h"

#define VecVWzskPrfDaemonDo PnlWzskPrfDaemon::VecVDo

#define ContIacWzskPrfDaemon PnlWzskPrfDaemon::ContIac
#define StatShrWzskPrfDaemon PnlWzskPrfDaemon::StatShr
#define TagWzskPrfDaemon PnlWzskPrfDaemon::Tag

#define DpchAppWzskPrfDaemonData PnlWzskPrfDaemon::DpchAppData
#define DpchAppWzskPrfDaemonDo PnlWzskPrfDaemon::DpchAppDo
#define DpchEngWzskPrfDaemonData PnlWzskPrfDaemon::DpchEngData

/**
	* PnlWzskPrfDaemon
	*/
namespace PnlWzskPrfDaemon {
	/**
		* VecVDo (full: VecVWzskPrfDaemonDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTREGULARIZECLICK = 1;
		static const Sbecore::uint BUTMINIMIZECLICK = 2;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContIac (full: ContIacWzskPrfDaemon)
	  */
	class ContIac : public Sbecore::Block {

	public:
		static const Sbecore::uint TXF2 = 1;
		static const Sbecore::uint CHK3 = 2;
		static const Sbecore::uint TXF4 = 3;
		static const Sbecore::uint TXF5 = 4;
		static const Sbecore::uint TXF6 = 5;
		static const Sbecore::uint TXF102 = 6;
		static const Sbecore::uint CHK103 = 7;
		static const Sbecore::uint TXF104 = 8;
		static const Sbecore::uint TXF202 = 9;
		static const Sbecore::uint TXF203 = 10;
		static const Sbecore::uint CHK204 = 11;
		static const Sbecore::uint CHK205 = 12;
		static const Sbecore::uint CHK206 = 13;
		static const Sbecore::uint NUMFPUP302 = 14;
		static const Sbecore::uint TXF303 = 15;
		static const Sbecore::uint TXF304 = 16;
		static const Sbecore::uint TXF305 = 17;
		static const Sbecore::uint TXF306 = 18;
		static const Sbecore::uint TXF307 = 19;
		static const Sbecore::uint TXF308 = 20;
		static const Sbecore::uint TXF402 = 21;
		static const Sbecore::uint TXF403 = 22;
		static const Sbecore::uint TXF404 = 23;
		static const Sbecore::uint TXF405 = 24;
		static const Sbecore::uint TXF406 = 25;
		static const Sbecore::uint TXF407 = 26;
		static const Sbecore::uint TXF502 = 27;
		static const Sbecore::uint TXF503 = 28;
		static const Sbecore::uint TXF602 = 29;
		static const Sbecore::uint TXF603 = 30;
		static const Sbecore::uint TXF604 = 31;
		static const Sbecore::uint TXF605 = 32;
		static const Sbecore::uint TXF606 = 33;

	public:
		ContIac(const std::string& Txf2 = "", const bool Chk3 = false, const std::string& Txf4 = "", const std::string& Txf5 = "", const std::string& Txf6 = "", const std::string& Txf102 = "", const bool Chk103 = false, const std::string& Txf104 = "", const std::string& Txf202 = "", const std::string& Txf203 = "", const bool Chk204 = false, const bool Chk205 = false, const bool Chk206 = false, const Sbecore::uint numFPup302 = 1, const std::string& Txf303 = "", const std::string& Txf304 = "", const std::string& Txf305 = "", const std::string& Txf306 = "", const std::string& Txf307 = "", const std::string& Txf308 = "", const std::string& Txf402 = "", const std::string& Txf403 = "", const std::string& Txf404 = "", const std::string& Txf405 = "", const std::string& Txf406 = "", const std::string& Txf407 = "", const std::string& Txf502 = "", const std::string& Txf503 = "", const std::string& Txf602 = "", const std::string& Txf603 = "", const std::string& Txf604 = "", const std::string& Txf605 = "", const std::string& Txf606 = "");

	public:
		std::string Txf2;
		bool Chk3;
		std::string Txf4;
		std::string Txf5;
		std::string Txf6;
		std::string Txf102;
		bool Chk103;
		std::string Txf104;
		std::string Txf202;
		std::string Txf203;
		bool Chk204;
		bool Chk205;
		bool Chk206;
		Sbecore::uint numFPup302;
		std::string Txf303;
		std::string Txf304;
		std::string Txf305;
		std::string Txf306;
		std::string Txf307;
		std::string Txf308;
		std::string Txf402;
		std::string Txf403;
		std::string Txf404;
		std::string Txf405;
		std::string Txf406;
		std::string Txf407;
		std::string Txf502;
		std::string Txf503;
		std::string Txf602;
		std::string Txf603;
		std::string Txf604;
		std::string Txf605;
		std::string Txf606;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContIac* comp);
		std::set<Sbecore::uint> diff(const ContIac* comp);
	};

	/**
	  * StatShr (full: StatShrWzskPrfDaemon)
	  */
	class StatShr : public Sbecore::Block {

	public:
		static const Sbecore::uint IXWZSKVEXPSTATE = 1;
		static const Sbecore::uint TXF2CLEAN = 2;
		static const Sbecore::uint CHK3CLEAN = 3;
		static const Sbecore::uint TXF4CLEAN = 4;
		static const Sbecore::uint TXF5CLEAN = 5;
		static const Sbecore::uint TXF6CLEAN = 6;
		static const Sbecore::uint TXF102CLEAN = 7;
		static const Sbecore::uint CHK103CLEAN = 8;
		static const Sbecore::uint TXF104CLEAN = 9;
		static const Sbecore::uint SEP2AVAIL = 10;
		static const Sbecore::uint HDG201AVAIL = 11;
		static const Sbecore::uint TXF202AVAIL = 12;
		static const Sbecore::uint TXF202CLEAN = 13;
		static const Sbecore::uint TXF203AVAIL = 14;
		static const Sbecore::uint TXF203CLEAN = 15;
		static const Sbecore::uint CHK204AVAIL = 16;
		static const Sbecore::uint CHK204CLEAN = 17;
		static const Sbecore::uint CHK205AVAIL = 18;
		static const Sbecore::uint CHK205CLEAN = 19;
		static const Sbecore::uint CHK206AVAIL = 20;
		static const Sbecore::uint CHK206CLEAN = 21;
		static const Sbecore::uint PUP302CLEAN = 22;
		static const Sbecore::uint TXF303CLEAN = 23;
		static const Sbecore::uint TXF304CLEAN = 24;
		static const Sbecore::uint TXF305CLEAN = 25;
		static const Sbecore::uint TXF306CLEAN = 26;
		static const Sbecore::uint TXF307CLEAN = 27;
		static const Sbecore::uint TXF308CLEAN = 28;
		static const Sbecore::uint TXF402CLEAN = 29;
		static const Sbecore::uint TXF403CLEAN = 30;
		static const Sbecore::uint TXF404CLEAN = 31;
		static const Sbecore::uint TXF405CLEAN = 32;
		static const Sbecore::uint TXF406CLEAN = 33;
		static const Sbecore::uint TXF407CLEAN = 34;
		static const Sbecore::uint TXF502CLEAN = 35;
		static const Sbecore::uint TXF503CLEAN = 36;
		static const Sbecore::uint TXF602CLEAN = 37;
		static const Sbecore::uint TXF603CLEAN = 38;
		static const Sbecore::uint TXF604CLEAN = 39;
		static const Sbecore::uint TXF605CLEAN = 40;
		static const Sbecore::uint TXF606CLEAN = 41;

	public:
		StatShr(const Sbecore::uint ixWzskVExpstate = VecWzskVExpstate::MIND, const bool Txf2Clean = false, const bool Chk3Clean = false, const bool Txf4Clean = false, const bool Txf5Clean = false, const bool Txf6Clean = false, const bool Txf102Clean = false, const bool Chk103Clean = false, const bool Txf104Clean = false, const bool Sep2Avail = true, const bool Hdg201Avail = true, const bool Txf202Avail = true, const bool Txf202Clean = false, const bool Txf203Avail = true, const bool Txf203Clean = false, const bool Chk204Avail = true, const bool Chk204Clean = false, const bool Chk205Avail = true, const bool Chk205Clean = false, const bool Chk206Avail = true, const bool Chk206Clean = false, const bool Pup302Clean = false, const bool Txf303Clean = false, const bool Txf304Clean = false, const bool Txf305Clean = false, const bool Txf306Clean = false, const bool Txf307Clean = false, const bool Txf308Clean = false, const bool Txf402Clean = false, const bool Txf403Clean = false, const bool Txf404Clean = false, const bool Txf405Clean = false, const bool Txf406Clean = false, const bool Txf407Clean = false, const bool Txf502Clean = false, const bool Txf503Clean = false, const bool Txf602Clean = false, const bool Txf603Clean = false, const bool Txf604Clean = false, const bool Txf605Clean = false, const bool Txf606Clean = false);

	public:
		Sbecore::uint ixWzskVExpstate;
		bool Txf2Clean;
		bool Chk3Clean;
		bool Txf4Clean;
		bool Txf5Clean;
		bool Txf6Clean;
		bool Txf102Clean;
		bool Chk103Clean;
		bool Txf104Clean;
		bool Sep2Avail;
		bool Hdg201Avail;
		bool Txf202Avail;
		bool Txf202Clean;
		bool Txf203Avail;
		bool Txf203Clean;
		bool Chk204Avail;
		bool Chk204Clean;
		bool Chk205Avail;
		bool Chk205Clean;
		bool Chk206Avail;
		bool Chk206Clean;
		bool Pup302Clean;
		bool Txf303Clean;
		bool Txf304Clean;
		bool Txf305Clean;
		bool Txf306Clean;
		bool Txf307Clean;
		bool Txf308Clean;
		bool Txf402Clean;
		bool Txf403Clean;
		bool Txf404Clean;
		bool Txf405Clean;
		bool Txf406Clean;
		bool Txf407Clean;
		bool Txf502Clean;
		bool Txf503Clean;
		bool Txf602Clean;
		bool Txf603Clean;
		bool Txf604Clean;
		bool Txf605Clean;
		bool Txf606Clean;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
		std::set<Sbecore::uint> comm(const StatShr* comp);
		std::set<Sbecore::uint> diff(const StatShr* comp);
	};

	/**
	  * Tag (full: TagWzskPrfDaemon)
	  */
	class Tag : public Sbecore::Block {

	public:
		static const Sbecore::uint CPT = 1;
		static const Sbecore::uint HDG1 = 2;
		static const Sbecore::uint CPT2 = 3;
		static const Sbecore::uint CPT3 = 4;
		static const Sbecore::uint CPT4 = 5;
		static const Sbecore::uint CPT5 = 6;
		static const Sbecore::uint CPT6 = 7;
		static const Sbecore::uint HDG101 = 8;
		static const Sbecore::uint CPT102 = 9;
		static const Sbecore::uint CPT103 = 10;
		static const Sbecore::uint CPT104 = 11;
		static const Sbecore::uint HDG201 = 12;
		static const Sbecore::uint CPT202 = 13;
		static const Sbecore::uint CPT203 = 14;
		static const Sbecore::uint CPT204 = 15;
		static const Sbecore::uint CPT205 = 16;
		static const Sbecore::uint CPT206 = 17;
		static const Sbecore::uint HDG301 = 18;
		static const Sbecore::uint CPT302 = 19;
		static const Sbecore::uint CPT303 = 20;
		static const Sbecore::uint CPT304 = 21;
		static const Sbecore::uint CPT305 = 22;
		static const Sbecore::uint CPT306 = 23;
		static const Sbecore::uint CPT307 = 24;
		static const Sbecore::uint CPT308 = 25;
		static const Sbecore::uint HDG401 = 26;
		static const Sbecore::uint CPT402 = 27;
		static const Sbecore::uint CPT403 = 28;
		static const Sbecore::uint CPT404 = 29;
		static const Sbecore::uint CPT405 = 30;
		static const Sbecore::uint CPT406 = 31;
		static const Sbecore::uint CPT407 = 32;
		static const Sbecore::uint HDG501 = 33;
		static const Sbecore::uint CPT502 = 34;
		static const Sbecore::uint CPT503 = 35;
		static const Sbecore::uint HDG601 = 36;
		static const Sbecore::uint CPT602 = 37;
		static const Sbecore::uint CPT603 = 38;
		static const Sbecore::uint CPT604 = 39;
		static const Sbecore::uint CPT605 = 40;
		static const Sbecore::uint CPT606 = 41;

	public:
		Tag(const std::string& Cpt = "", const std::string& Hdg1 = "", const std::string& Cpt2 = "", const std::string& Cpt3 = "", const std::string& Cpt4 = "", const std::string& Cpt5 = "", const std::string& Cpt6 = "", const std::string& Hdg101 = "", const std::string& Cpt102 = "", const std::string& Cpt103 = "", const std::string& Cpt104 = "", const std::string& Hdg201 = "", const std::string& Cpt202 = "", const std::string& Cpt203 = "", const std::string& Cpt204 = "", const std::string& Cpt205 = "", const std::string& Cpt206 = "", const std::string& Hdg301 = "", const std::string& Cpt302 = "", const std::string& Cpt303 = "", const std::string& Cpt304 = "", const std::string& Cpt305 = "", const std::string& Cpt306 = "", const std::string& Cpt307 = "", const std::string& Cpt308 = "", const std::string& Hdg401 = "", const std::string& Cpt402 = "", const std::string& Cpt403 = "", const std::string& Cpt404 = "", const std::string& Cpt405 = "", const std::string& Cpt406 = "", const std::string& Cpt407 = "", const std::string& Hdg501 = "", const std::string& Cpt502 = "", const std::string& Cpt503 = "", const std::string& Hdg601 = "", const std::string& Cpt602 = "", const std::string& Cpt603 = "", const std::string& Cpt604 = "", const std::string& Cpt605 = "", const std::string& Cpt606 = "");

	public:
		std::string Cpt;
		std::string Hdg1;
		std::string Cpt2;
		std::string Cpt3;
		std::string Cpt4;
		std::string Cpt5;
		std::string Cpt6;
		std::string Hdg101;
		std::string Cpt102;
		std::string Cpt103;
		std::string Cpt104;
		std::string Hdg201;
		std::string Cpt202;
		std::string Cpt203;
		std::string Cpt204;
		std::string Cpt205;
		std::string Cpt206;
		std::string Hdg301;
		std::string Cpt302;
		std::string Cpt303;
		std::string Cpt304;
		std::string Cpt305;
		std::string Cpt306;
		std::string Cpt307;
		std::string Cpt308;
		std::string Hdg401;
		std::string Cpt402;
		std::string Cpt403;
		std::string Cpt404;
		std::string Cpt405;
		std::string Cpt406;
		std::string Cpt407;
		std::string Hdg501;
		std::string Cpt502;
		std::string Cpt503;
		std::string Hdg601;
		std::string Cpt602;
		std::string Cpt603;
		std::string Cpt604;
		std::string Cpt605;
		std::string Cpt606;

	public:
		bool readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchAppData (full: DpchAppWzskPrfDaemonData)
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
		* DpchAppDo (full: DpchAppWzskPrfDaemonDo)
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
		* DpchEngData (full: DpchEngWzskPrfDaemonData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint SCRJREF = 1;
		static const Sbecore::uint CONTIAC = 2;
		static const Sbecore::uint FEEDFPUP302 = 3;
		static const Sbecore::uint STATSHR = 4;
		static const Sbecore::uint TAG = 5;

	public:
		DpchEngData();

	public:
		ContIac contiac;
		Sbecore::Feed feedFPup302;
		StatShr statshr;
		Tag tag;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

};

#endif
