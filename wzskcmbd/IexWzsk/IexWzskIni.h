/**
	* \file IexWzskIni.h
	* data blocks and readers/writers for import/export complex IexWzskIni (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef IEXWZSKINI_H
#define IEXWZSKINI_H

#include <sbecore/Engtypes.h>
#include <sbecore/Txtrd.h>

#include "DbsWzsk.h"
#include "VecWzskVIop.h"

#define VecVIexWzskIniIme IexWzskIni::VecVIme

#define ImeitemIWzskIniAVControlPar IexWzskIni::ImeitemIAVControlPar
#define ImeIWzskIniAVControlPar IexWzskIni::ImeIAVControlPar
#define VecWImeIWzskIniAVControlParIel IexWzskIni::ImeIAVControlPar::VecWIel

#define ImeitemIWzskIniJAVKeylistKey IexWzskIni::ImeitemIJAVKeylistKey
#define ImeIWzskIniJAVKeylistKey IexWzskIni::ImeIJAVKeylistKey
#define VecWImeIWzskIniJAVKeylistKeyIel IexWzskIni::ImeIJAVKeylistKey::VecWIel

#define ImeitemIWzskIniAVKeylistKey IexWzskIni::ImeitemIAVKeylistKey
#define ImeIWzskIniAVKeylistKey IexWzskIni::ImeIAVKeylistKey
#define VecWImeIWzskIniAVKeylistKeyIel IexWzskIni::ImeIAVKeylistKey::VecWIel

#define ImeitemIWzskIniAVValuelistVal IexWzskIni::ImeitemIAVValuelistVal
#define ImeIWzskIniAVValuelistVal IexWzskIni::ImeIAVValuelistVal
#define VecWImeIWzskIniAVValuelistValIel IexWzskIni::ImeIAVValuelistVal::VecWIel

#define ImeitemIWzskIniMFile IexWzskIni::ImeitemIMFile
#define ImeIWzskIniMFile IexWzskIni::ImeIMFile
#define VecWImeIWzskIniMFileIel IexWzskIni::ImeIMFile::VecWIel

#define ImeitemIWzskIniAMUsergroupAccess IexWzskIni::ImeitemIAMUsergroupAccess
#define ImeIWzskIniAMUsergroupAccess IexWzskIni::ImeIAMUsergroupAccess
#define VecWImeIWzskIniAMUsergroupAccessIel IexWzskIni::ImeIAMUsergroupAccess::VecWIel

#define ImeitemIWzskIniAMUserAccess IexWzskIni::ImeitemIAMUserAccess
#define ImeIWzskIniAMUserAccess IexWzskIni::ImeIAMUserAccess
#define VecWImeIWzskIniAMUserAccessIel IexWzskIni::ImeIAMUserAccess::VecWIel

#define ImeitemIWzskIniJMUserState IexWzskIni::ImeitemIJMUserState
#define ImeIWzskIniJMUserState IexWzskIni::ImeIJMUserState
#define VecWImeIWzskIniJMUserStateIel IexWzskIni::ImeIJMUserState::VecWIel

#define ImeitemIWzskIniJMPersonLastname IexWzskIni::ImeitemIJMPersonLastname
#define ImeIWzskIniJMPersonLastname IexWzskIni::ImeIJMPersonLastname
#define VecWImeIWzskIniJMPersonLastnameIel IexWzskIni::ImeIJMPersonLastname::VecWIel

#define ImeitemIWzskIniMPerson IexWzskIni::ImeitemIMPerson
#define ImeIWzskIniMPerson IexWzskIni::ImeIMPerson
#define VecWImeIWzskIniMPersonIel IexWzskIni::ImeIMPerson::VecWIel

#define ImeitemIWzskIniMUser IexWzskIni::ImeitemIMUser
#define ImeIWzskIniMUser IexWzskIni::ImeIMUser
#define VecWImeIWzskIniMUserIel IexWzskIni::ImeIMUser::VecWIel

#define ImeitemIWzskIniMUsergroup IexWzskIni::ImeitemIMUsergroup
#define ImeIWzskIniMUsergroup IexWzskIni::ImeIMUsergroup
#define VecWImeIWzskIniMUsergroupIel IexWzskIni::ImeIMUsergroup::VecWIel

/**
	* IexWzskIni
	*/
namespace IexWzskIni {
	/**
		* VecVIme (full: VecVIexWzskIniIme)
		*/
	class VecVIme {

	public:
		static const Sbecore::uint IMEIAMUSERACCESS = 1;
		static const Sbecore::uint IMEIAMUSERGROUPACCESS = 2;
		static const Sbecore::uint IMEIAVCONTROLPAR = 3;
		static const Sbecore::uint IMEIAVKEYLISTKEY = 4;
		static const Sbecore::uint IMEIAVVALUELISTVAL = 5;
		static const Sbecore::uint IMEIJAVKEYLISTKEY = 6;
		static const Sbecore::uint IMEIJMPERSONLASTNAME = 7;
		static const Sbecore::uint IMEIJMUSERSTATE = 8;
		static const Sbecore::uint IMEIMFILE = 9;
		static const Sbecore::uint IMEIMPERSON = 10;
		static const Sbecore::uint IMEIMUSER = 11;
		static const Sbecore::uint IMEIMUSERGROUP = 12;

		static Sbecore::uint getIx(const std::string& sref);
		static std::string getSref(const Sbecore::uint ix);
	};

	/**
		* ImeitemIAVControlPar (full: ImeitemIWzskIniAVControlPar)
		*/
	class ImeitemIAVControlPar : public WzskAVControlPar {

	public:
		ImeitemIAVControlPar(const Sbecore::uint ixWzskVControl = 0, const std::string& Par = "", const std::string& Val = "");
		ImeitemIAVControlPar(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxWzskVControl;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVControlPar (full: ImeIWzskIniAVControlPar)
		*/
	class ImeIAVControlPar {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniAVControlParIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXWZSKVCONTROL = 1;
			static const Sbecore::uint PAR = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVControlPar();
		~ImeIAVControlPar();

	public:
		std::vector<ImeitemIAVControlPar*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJAVKeylistKey (full: ImeitemIWzskIniJAVKeylistKey)
		*/
	class ImeitemIJAVKeylistKey : public WzskJAVKeylistKey {

	public:
		ImeitemIJAVKeylistKey(const Sbecore::uint x1IxWzskVLocale = 0, const std::string& Title = "", const std::string& Comment = "");
		ImeitemIJAVKeylistKey(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWzskVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJAVKeylistKey (full: ImeIWzskIniJAVKeylistKey)
		*/
	class ImeIJAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniJAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZSKVLOCALE = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint COMMENT = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJAVKeylistKey();
		~ImeIJAVKeylistKey();

	public:
		std::vector<ImeitemIJAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVKeylistKey (full: ImeitemIWzskIniAVKeylistKey)
		*/
	class ImeitemIAVKeylistKey : public WzskAVKeylistKey {

	public:
		ImeitemIAVKeylistKey(const Sbecore::uint klsIxWzskVKeylist = 0, const std::string& sref = "", const std::string& Avail = "", const std::string& Implied = "", const std::string& Title = "", const std::string& Comment = "");
		ImeitemIAVKeylistKey(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefKlsIxWzskVKeylist;

		ImeIJAVKeylistKey imeijavkeylistkey;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVKeylistKey (full: ImeIWzskIniAVKeylistKey)
		*/
	class ImeIAVKeylistKey {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniAVKeylistKeyIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFKLSIXWZSKVKEYLIST = 1;
			static const Sbecore::uint SREF = 2;
			static const Sbecore::uint AVAIL = 4;
			static const Sbecore::uint IMPLIED = 8;
			static const Sbecore::uint TITLE = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVKeylistKey();
		~ImeIAVKeylistKey();

	public:
		std::vector<ImeitemIAVKeylistKey*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAVValuelistVal (full: ImeitemIWzskIniAVValuelistVal)
		*/
	class ImeitemIAVValuelistVal : public WzskAVValuelistVal {

	public:
		ImeitemIAVValuelistVal(const Sbecore::uint vlsIxWzskVValuelist = 0, const Sbecore::uint x1IxWzskVLocale = 0, const std::string& Val = "");
		ImeitemIAVValuelistVal(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefVlsIxWzskVValuelist;
		std::string srefX1IxWzskVLocale;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAVValuelistVal (full: ImeIWzskIniAVValuelistVal)
		*/
	class ImeIAVValuelistVal {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniAVValuelistValIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFVLSIXWZSKVVALUELIST = 1;
			static const Sbecore::uint SREFX1IXWZSKVLOCALE = 2;
			static const Sbecore::uint VAL = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAVValuelistVal();
		~ImeIAVValuelistVal();

	public:
		std::vector<ImeitemIAVValuelistVal*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMFile (full: ImeitemIWzskIniMFile)
		*/
	class ImeitemIMFile : public WzskMFile {

	public:
		ImeitemIMFile(const std::string& osrefKContent = "", const std::string& Filename = "", const std::string& srefKMimetype = "", const std::string& Comment = "");
		ImeitemIMFile(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMFile (full: ImeIWzskIniMFile)
		*/
	class ImeIMFile {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniMFileIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint OSREFKCONTENT = 1;
			static const Sbecore::uint FILENAME = 2;
			static const Sbecore::uint SREFKMIMETYPE = 4;
			static const Sbecore::uint COMMENT = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMFile();
		~ImeIMFile();

	public:
		std::vector<ImeitemIMFile*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUsergroupAccess (full: ImeitemIWzskIniAMUsergroupAccess)
		*/
	class ImeitemIAMUsergroupAccess : public WzskAMUsergroupAccess {

	public:
		ImeitemIAMUsergroupAccess(const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);
		ImeitemIAMUsergroupAccess(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWzskVFeatgroup;
		std::string srefsIxWzskWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUsergroupAccess (full: ImeIWzskIniAMUsergroupAccess)
		*/
	class ImeIAMUsergroupAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniAMUsergroupAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZSKVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWZSKWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUsergroupAccess();
		~ImeIAMUsergroupAccess();

	public:
		std::vector<ImeitemIAMUsergroupAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIAMUserAccess (full: ImeitemIWzskIniAMUserAccess)
		*/
	class ImeitemIAMUserAccess : public WzskAMUserAccess {

	public:
		ImeitemIAMUserAccess(const Sbecore::uint x1IxWzskVFeatgroup = 0, const std::string& x2FeaSrefUix = "", const Sbecore::uint ixWzskWAccess = 0);
		ImeitemIAMUserAccess(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefX1IxWzskVFeatgroup;
		std::string srefsIxWzskWAccess;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIAMUserAccess (full: ImeIWzskIniAMUserAccess)
		*/
	class ImeIAMUserAccess {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniAMUserAccessIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFX1IXWZSKVFEATGROUP = 1;
			static const Sbecore::uint X2FEASREFUIX = 2;
			static const Sbecore::uint SREFSIXWZSKWACCESS = 4;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIAMUserAccess();
		~ImeIAMUserAccess();

	public:
		std::vector<ImeitemIAMUserAccess*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMUserState (full: ImeitemIWzskIniJMUserState)
		*/
	class ImeitemIJMUserState : public WzskJMUserState {

	public:
		ImeitemIJMUserState(const Sbecore::uint ixVState = 0);
		ImeitemIJMUserState(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMUserState (full: ImeIWzskIniJMUserState)
		*/
	class ImeIJMUserState {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniJMUserStateIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSTATE = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMUserState();
		~ImeIJMUserState();

	public:
		std::vector<ImeitemIJMUserState*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIJMPersonLastname (full: ImeitemIWzskIniJMPersonLastname)
		*/
	class ImeitemIJMPersonLastname : public WzskJMPersonLastname {

	public:
		ImeitemIJMPersonLastname(const std::string& Lastname = "");
		ImeitemIJMPersonLastname(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIJMPersonLastname (full: ImeIWzskIniJMPersonLastname)
		*/
	class ImeIJMPersonLastname {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniJMPersonLastnameIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint LASTNAME = 1;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIJMPersonLastname();
		~ImeIJMPersonLastname();

	public:
		std::vector<ImeitemIJMPersonLastname*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMPerson (full: ImeitemIWzskIniMPerson)
		*/
	class ImeitemIMPerson : public WzskMPerson {

	public:
		ImeitemIMPerson(const Sbecore::uint ixVSex = 0, const std::string& Title = "", const std::string& Firstname = "", const std::string& Lastname = "");
		ImeitemIMPerson(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVSex;

		ImeIJMPersonLastname imeijmpersonlastname;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMPerson (full: ImeIWzskIniMPerson)
		*/
	class ImeIMPerson {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniMPersonIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREFIXVSEX = 1;
			static const Sbecore::uint TITLE = 2;
			static const Sbecore::uint FIRSTNAME = 4;
			static const Sbecore::uint LASTNAME = 8;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMPerson();
		~ImeIMPerson();

	public:
		std::vector<ImeitemIMPerson*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUser (full: ImeitemIWzskIniMUser)
		*/
	class ImeitemIMUser : public WzskMUser {

	public:
		ImeitemIMUser(const std::string& sref = "", const Sbecore::uint ixVState = 0, const Sbecore::uint ixWzskVLocale = 0, const Sbecore::uint ixWzskVUserlevel = 0, const std::string& Password = "", const std::string& Comment = "");
		ImeitemIMUser(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		std::string srefIxVState;
		std::string srefIxWzskVLocale;
		std::string srefIxWzskVUserlevel;

		ImeIAMUserAccess imeiamuseraccess;
		ImeIJMUserState imeijmuserstate;
		ImeIMPerson imeimperson;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUser (full: ImeIWzskIniMUser)
		*/
	class ImeIMUser {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniMUserIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint SREFIXVSTATE = 2;
			static const Sbecore::uint SREFIXWZSKVLOCALE = 4;
			static const Sbecore::uint SREFIXWZSKVUSERLEVEL = 8;
			static const Sbecore::uint PASSWORD = 16;
			static const Sbecore::uint COMMENT = 32;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUser();
		~ImeIMUser();

	public:
		std::vector<ImeitemIMUser*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	/**
		* ImeitemIMUsergroup (full: ImeitemIWzskIniMUsergroup)
		*/
	class ImeitemIMUsergroup : public WzskMUsergroup {

	public:
		ImeitemIMUsergroup(const std::string& sref = "", const std::string& Comment = "");
		ImeitemIMUsergroup(DbsWzsk* dbswzsk, const Sbecore::ubigint ref);

	public:
		Sbecore::uint lineno;
		Sbecore::uint ixWIelValid;

		ImeIAMUsergroupAccess imeiamusergroupaccess;
		ImeIMUser imeimuser;

	public:
		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, const std::string& basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const Sbecore::uint num, const bool shorttags = true);
	};

	/**
		* ImeIMUsergroup (full: ImeIWzskIniMUsergroup)
		*/
	class ImeIMUsergroup {

	public:
		/**
			* VecWIel (full: VecWImeIWzskIniMUsergroupIel)
			*/
		class VecWIel {

		public:
			static const Sbecore::uint SREF = 1;
			static const Sbecore::uint COMMENT = 2;

			static Sbecore::uint getIx(const std::string& srefs);
			static void getIcs(const Sbecore::uint ix, std::set<Sbecore::uint>& ics);
			static std::string getSrefs(const Sbecore::uint ix);
		};

	public:
		ImeIMUsergroup();
		~ImeIMUsergroup();

	public:
		std::vector<ImeitemIMUsergroup*> nodes;

	public:
		void clear();

		void readTxt(Sbecore::Txtrd& txtrd);
		void readXML(xmlXPathContext* docctx, std::string basexpath);

		void writeTxt(std::fstream& outfile);
		void writeXML(xmlTextWriter* wr, const bool shorttags = true);
	};

	void parseFromFile(const std::string& fullpath, const bool xmlNotTxt, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMUsergroup& imeimusergroup);
	void exportToFile(const std::string& fullpath, const bool xmlNotTxt, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMUsergroup& imeimusergroup);

	void readTxt(Sbecore::Txtrd& txtrd, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMUsergroup& imeimusergroup);
	void readXML(xmlXPathContext* docctx, std::string basexpath, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMUsergroup& imeimusergroup);

	void writeTxt(std::fstream& outfile, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMUsergroup& imeimusergroup);
	void writeXML(xmlTextWriter* wr, const bool shorttags, ImeIAVControlPar& imeiavcontrolpar, ImeIAVKeylistKey& imeiavkeylistkey, ImeIAVValuelistVal& imeiavvaluelistval, ImeIMFile& imeimfile, ImeIMUsergroup& imeimusergroup);

	std::map<Sbecore::uint,Sbecore::uint> icsWzskVIopInsAll();
	Sbecore::uint getIxWzskVIop(const std::map<Sbecore::uint,Sbecore::uint>& icsWzskVIop, const Sbecore::uint ixVIme, Sbecore::uint& ixWzskVIop);
};

#endif

