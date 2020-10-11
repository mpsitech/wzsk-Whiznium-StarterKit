/**
	* \file DlgWzskFilDownload.h
	* job handler for job DlgWzskFilDownload (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef DLGWZSKFILDOWNLOAD_H
#define DLGWZSKFILDOWNLOAD_H

// IP include.spec --- INSERT

// IP include.cust --- INSERT

#define VecVDlgWzskFilDownloadDo DlgWzskFilDownload::VecVDo

#define ContInfDlgWzskFilDownload DlgWzskFilDownload::ContInf
#define StatAppDlgWzskFilDownload DlgWzskFilDownload::StatApp
#define TagDlgWzskFilDownload DlgWzskFilDownload::Tag

#define DpchAppDlgWzskFilDownloadDo DlgWzskFilDownload::DpchAppDo
#define DpchEngDlgWzskFilDownloadData DlgWzskFilDownload::DpchEngData

/**
	* DlgWzskFilDownload
	*/
class DlgWzskFilDownload : public JobWzsk {

public:
	/**
		* VecVDo (full: VecVDlgWzskFilDownloadDo)
		*/
	class VecVDo {

	public:
		static const Sbecore::uint BUTDNECLICK = 1;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
	  * ContInf (full: ContInfDlgWzskFilDownload)
	  */
	class ContInf : public Sbecore::Xmlio::Block {

	public:
		static const Sbecore::uint DLD = 1;

	public:
		ContInf(const std::string& Dld = "file");

	public:
		std::string Dld;

	public:
		void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
		std::set<Sbecore::uint> comm(const ContInf* comp);
		std::set<Sbecore::uint> diff(const ContInf* comp);
	};

	/**
		* StatApp (full: StatAppDlgWzskFilDownload)
		*/
	class StatApp {

	public:
		static void writeXML(xmlTextWriter* wr, std::string difftag = "", bool shorttags = true, const std::string& shortMenu = "");
	};

	/**
		* Tag (full: TagDlgWzskFilDownload)
		*/
	class Tag {

	public:
		static void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr, std::string difftag = "", bool shorttags = true);
	};

	/**
		* DpchAppDo (full: DpchAppDlgWzskFilDownloadDo)
		*/
	class DpchAppDo : public DpchAppWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint IXVDO = 2;

	public:
		DpchAppDo();

	public:
		Sbecore::uint ixVDo;

	public:
		std::string getSrefsMask();

		void readXML(xmlXPathContext* docctx, std::string basexpath = "", bool addbasetag = false);
	};

	/**
		* DpchEngData (full: DpchEngDlgWzskFilDownloadData)
		*/
	class DpchEngData : public DpchEngWzsk {

	public:
		static const Sbecore::uint JREF = 1;
		static const Sbecore::uint CONTINF = 2;
		static const Sbecore::uint STATAPP = 3;
		static const Sbecore::uint TAG = 4;
		static const Sbecore::uint ALL = 5;

	public:
		DpchEngData(const Sbecore::ubigint jref = 0, ContInf* continf = NULL, const std::set<Sbecore::uint>& mask = {NONE});

	public:
		ContInf continf;

	public:
		std::string getSrefsMask();
		void merge(DpchEngWzsk* dpcheng);

		void writeXML(const Sbecore::uint ixWzskVLocale, xmlTextWriter* wr);
	};

public:
	DlgWzskFilDownload(XchgWzsk* xchg, DbsWzsk* dbswzsk, const Sbecore::ubigint jrefSup, const Sbecore::uint ixWzskVLocale);
	~DlgWzskFilDownload();

public:
	ContInf continf;

	// IP vars.cust --- INSERT

public:
	// IP cust --- INSERT

public:
	DpchEngWzsk* getNewDpchEng(std::set<Sbecore::uint> items);

	void refresh(DbsWzsk* dbswzsk, std::set<Sbecore::uint>& moditems, const bool unmute = false);

public:

public:
	void handleRequest(DbsWzsk* dbswzsk, ReqWzsk* req);

private:

	void handleDpchAppWzskInit(DbsWzsk* dbswzsk, DpchAppWzskInit* dpchappwzskinit, DpchEngWzsk** dpcheng);

	void handleDpchAppDoButDneClick(DbsWzsk* dbswzsk, DpchEngWzsk** dpcheng);

	std::string handleDownload(DbsWzsk* dbswzsk);

};

#endif

