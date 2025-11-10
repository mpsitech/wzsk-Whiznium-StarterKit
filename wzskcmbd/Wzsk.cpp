/**
	* \file Wzsk.cpp
	* Wzsk global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#include "Wzsk.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

/******************************************************************************
 namespace Acv
 ******************************************************************************/

ubigint Acv::addfile(
			DbsWzsk* dbswzsk
			, const string& acvpath
			, const string& path
			, const ubigint grp
			, const ubigint own
			, const uint refIxVTbl
			, const ubigint refUref
			, const string& osrefKContent
			, const string& Filename
			, const string& srefKMimetype
			, const string& Comment
		) {
	ubigint retval = 0;

	WzskMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in byte
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size;

	dbswzsk->tblwzskmfile->insertNewRec(&fil, grp, own, 0, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	
	// adjust archive name in record
	str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
	if (Filename.rfind('.') != string::npos) str << Filename.substr(Filename.rfind('.'));

	fil->Archivename = str.str();
	dbswzsk->tblwzskmfile->updateRec(fil);

	// create folder if required
	str.str(""); str << acvpath << "/";
	str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
	if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

	// copy file
	s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

	res = system(s.c_str());
	if (res != 0) cout << "Acv::addfile() error copying file (" << res << ")" << endl;

	retval = fil->ref;
	delete fil;

	return retval;
};

void Acv::alterfile(
			DbsWzsk* dbswzsk
			, const string& acvpath
			, const string& path
			, const ubigint ref
		) {
	WzskMFile* fil = NULL;

	uint Archived;
	uint Size;

	ostringstream str;
	string s;

	int res;

	// set archived time to current time
	Archived = time(NULL);

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	// load record
	dbswzsk->tblwzskmfile->loadRecByRef(ref, &fil);

	if (fil) {
		// update record
		fil->Archived = Archived;

		str.str(""); str.fill('0'); str.width(8); str << right << fil->ref; str.width(0);
		if (fil->Filename.rfind('.') != string::npos) str << fil->Filename.substr(fil->Filename.rfind('.'));
		fil->Archivename = str.str();

		fil->Size = Size;

		dbswzsk->tblwzskmfile->updateRec(fil);

		// create folder if required
		str.str(""); str << acvpath << "/";
		str.fill('0'); str.width(5); str << right << ((fil->ref-(fil->ref%1000)) / 1000); str.width(0);

#ifdef _WIN32
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str());
#else
		if (access(str.str().c_str(), R_OK | W_OK) == -1) mkdir(str.str().c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
#endif

		// copy file
		s = "cp -p " + path + " " + str.str() + "/" + fil->Archivename;

		res = system(s.c_str());
		if (res != 0) cout << "Acv::alterfile() error copying file (" << res << ")" << endl;

		delete fil;
	};
};

string Acv::getfile(
			DbsWzsk* dbswzsk
			, const ubigint refWzskMFile
		) {
	WzskMFile* fil = NULL;

	ostringstream str;

	dbswzsk->tblwzskmfile->loadRecByRef(refWzskMFile, &fil);

	if (fil) {
		str.fill('0');
		str.width(5);
		str << right << ((fil->ref-(fil->ref%1000)) / 1000);
		
		str.width(0);
		str << "/" << fil->Archivename;

		delete fil;
	};

	return(str.str());
};

/******************************************************************************
 namespace Lop
 ******************************************************************************/

void Lop::apply(
			const uint ixWzskVLop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	if (ixWzskVLop == VecWzskVLop::INS) insert(refsList, refsPool, ref);
	else if (ixWzskVLop == VecWzskVLop::RMV) remove(refsList, refsPool, ref);
};

void Lop::insert(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsPool.size(); i++) {
		if (refsPool[i] == ref) {
			refsList[i] = ref;
			refsPool[i] = 0;
			break;
		};
	};
};

void Lop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref) {
			refsPool[i] = ref;
			refsList[i] = 0;
			break;
		};
	};
};

/******************************************************************************
 namespace Oolop
 ******************************************************************************/

void Oolop::apply(
			const uint ixWzskVOolop
			, vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	if (ixWzskVOolop == VecWzskVOolop::INB) insertBefore(refsList, refsPool, ref1, ref2);
	else if (ixWzskVOolop == VecWzskVOolop::INA) insertAfter(refsList, refsPool, ref1, ref2);
	else if (ixWzskVOolop == VecWzskVOolop::RMV) remove(refsList, refsPool, ref1);
	else if (ixWzskVOolop == VecWzskVOolop::TOB) toBefore(refsList, ref1, ref2);
	else if (ixWzskVOolop == VecWzskVOolop::TOA) toAfter(refsList, ref1, ref2);
	else if (ixWzskVOolop == VecWzskVOolop::SWP) swap(refsList, ref1, ref2);
};

void Oolop::insertBefore(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.insert(refsList.begin(), ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::insertAfter(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itPool = refsPool.begin(); itPool != refsPool.end(); itPool++) {
		if (*itPool == ref1) {
			if (ref2 == 0) {
				refsList.push_back(ref1);
				refsPool.erase(itPool);
			} else {
				for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
					if (*itList == ref2) {
						refsList.insert(++itList, ref1);
						refsPool.erase(itPool);
						break;
					};
				};
			};
			break;
		};
	};
};

void Oolop::remove(
			vector<ubigint>& refsList
			, vector<ubigint>& refsPool
			, const ubigint ref
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref) {
			refsList.erase(itList);
			refsPool.push_back(ref);
		};
	};
};

void Oolop::toBefore(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******2*****1****
	// *******12*********
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref2) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref1) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k+1] = refsList[k];
					refsList[i] = ref1;
					refsList[i+1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::toAfter(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	// *******1*****2****
	// ************21****
	for (unsigned int i = 0; i < refsList.size(); i++) {
		if (refsList[i] == ref1) {
			for (unsigned int j = i + 1; j < refsList.size(); j++) {
				if (refsList[j] == ref2) {
					for (unsigned int k = i + 1; k < j; k++) refsList[k-1] = refsList[k];
					refsList[j] = ref1;
					refsList[j-1] = ref2;
					break;
				};
			};
			break;
		};
	};
};

void Oolop::swap(
			vector<ubigint>& refsList
			, const ubigint ref1
			, const ubigint ref2
		) {
	for (auto itList = refsList.begin(); itList != refsList.end(); itList++) {
		if (*itList == ref1) {
			for (auto itList2 = refsList.begin(); itList2 != refsList.end(); itList2++) {
				if (*itList2 == ref2) {
					*itList = ref2;
					*itList2 = ref1;
					break;
				};
			};
			break;
		};
	};
};

/******************************************************************************
 namespace Tmp
 ******************************************************************************/

string Tmp::newfile(
			const string& tmppath
			, const string& ext
		) {
	string filename;
	fstream tmpfile;

	unsigned int pathlen = tmppath.length() + 1;

	FILE* file;

	bool valid = false;

	while (!valid) {
		filename = tmppath + "/" + random();
		if (ext.length() > 0) filename += "." + ext;

		file = fopen(filename.c_str(), "w+x");

		if (file) {
			fclose(file);
			valid = true;
		} else if (errno != EEXIST) break;
	};

	return(filename.substr(pathlen));
};

string Tmp::newfolder(
			const string& tmppath
		) {
	string foldername;

	unsigned int pathlen = tmppath.length() + 1;

	bool valid = false;

	while (!valid) {
		foldername = tmppath + "/" + random();

		// mkdir() fails if folder exists
#ifdef _WIN32
		valid = (mkdir(foldername.c_str()) == 0);
#else
		valid = (mkdir(foldername.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0);
#endif

		if (!valid) if (errno != EEXIST) break;
	};

	return(foldername.substr(pathlen));
};

string Tmp::random() {
	string retval;

	int digit;

	// random seed is done in engine initialization

	// fetch digits and make sure their ASCII code is in the range 0..9/a..z
	for (unsigned int i = 0; i < 8; i++) {
		digit = rand() % 36 + 48;
		if (digit > 57) digit += (97-48-10);

		retval = retval + ((char) digit);
	};

	return retval;
};

// IP cust --- INSERT

/******************************************************************************
 namespace Wzsk
 ******************************************************************************/

// IP gbl --- IBEGIN
void Wzsk::parseCmd(
			UntWskd& unt
			, string s
			, Dbecore::Cmd*& cmd
		) {
	string cmdsref;
	uint cmdix;

	utinyint tixVController;
	utinyint tixVCommand;

	if (cmd) delete cmd;
	cmd = NULL;

	size_t ptr;

	if (s.length() == 0) return;
	if (s[s.length()-1] != ')') return;
	s = s.substr(0, s.length()-1);
	ptr = s.find('(');
	if (ptr == string::npos) return;

	cmdix = getCmdix(unt, s.substr(0, ptr));
	tixVController = (cmdix >> 8);
	tixVCommand = (cmdix & 0xFF);
	s = s.substr(ptr+1);

	cmd = unt.getNewCmd(tixVController, tixVCommand);
	if (cmd) cmd->parlistToParbufInv(s);
};

uint Wzsk::getCmdix(
			UntWskd& unt
			, const string& cmdsref
		) {
	utinyint tixVController = 0;
	utinyint tixVCommand = 0;

	size_t ptr;

	ptr = cmdsref.find('.');

	if (ptr != string::npos) {
		tixVController = unt.getTixVControllerBySref(cmdsref.substr(0, ptr));
		tixVCommand = unt.getTixVCommandBySref(tixVController, cmdsref.substr(ptr+1));

		return((tixVController << 8) + tixVCommand);

	} else return 0;
};

string Wzsk::getCmdsref(
			UntWskd& unt
			, const uint cmdix
		) {
	string cmdsref;

	utinyint tixVController = (cmdix >> 8);
	utinyint tixVCommand = (cmdix & 0xFF);

	cmdsref = unt.getSrefByTixVController(tixVController);
	cmdsref += ".";
	cmdsref += unt.getSrefByTixVCommand(tixVController, tixVCommand);

	return cmdsref;
};

double Wzsk::getNow() {
	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);

	return(((double) ts.tv_sec) + 1.0e-9*((double) ts.tv_nsec));
};
// IP gbl --- IEND

/******************************************************************************
 namespace OpengWzsk
 ******************************************************************************/

void OpengWzsk::getIcsWzskVOppackByIxWzskVOpengtype(
			const uint ixWzskVOpengtype
			, vector<uint>& icsWzskVOppack
		) {
	icsWzskVOppack.clear();

};

void OpengWzsk::getIcsWzskVDpchByIxWzskVOppack(
			const uint ixWzskVOppack
			, set<uint>& icsWzskVDpch
		) {
};

/******************************************************************************
 namespace StubWzsk
 ******************************************************************************/

string StubWzsk::getStub(
			DbsWzsk* dbswzsk
			, const uint ixWzskVStub
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	if (ixWzskVStub == VecWzskVStub::STUBWZSKFILSTD) return getStubFilStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKGROUP) return getStubGroup(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKOWNER) return getStubOwner(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKPRSSTD) return getStubPrsStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKSESMENU) return getStubSesMenu(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKSESSTD) return getStubSesStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKUSGSTD) return getStubUsgStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	if (ixWzskVStub == VecWzskVStub::STUBWZSKUSRSTD) return getStubUsrStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);

	return("");
};

string StubWzsk::getStubFilStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "abcd.h5"
	string stub;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKFILSTD, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no file)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmfile->loadFnmByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzsk::getStubGroup(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "agroup"
	string stub;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKGROUP, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzsk::getStubOwner(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "auser"
	string stub;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKOWNER, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmuser->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzsk::getStubPrsStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Franz Kuntz"
	string stub;

	WzskMPerson* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKPRSSTD, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no person)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmperson->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzskPrsStd --- BEGIN
			stub = rec->Lastname;
			if (rec->Firstname.length() > 0) stub = rec->Firstname + " " + stub;
			// IP getStubWzskPrsStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzsk::getStubSesMenu(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "user fkuntz / Franz Kuntz;logged in from 127.0.0.1;since 01-01-2010 10:34"
	string stub;

	WzskMSession* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKSESMENU, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzskSesMenu --- BEGIN
			if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "user " + getStubUsrStd(dbswzsk, rec->refWzskMUser, ixWzskVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			// IP getStubWzskSesMenu --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzsk::getStubSesStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "01-01-2010 10:34 from 127.0.0.1"
	string stub;

	WzskMSession* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKSESSTD, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no session)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzskSesStd --- BEGIN
			if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			// IP getStubWzskSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzsk::getStubUsgStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "super"
	string stub;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKUSGSTD, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user group)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmusergroup->loadSrfByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzsk::getStubUsrStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "fkuntz / Franz Kuntz"
	string stub;

	WzskMUser* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKUSRSTD, ref, ixWzskVLocale);
	Stcchitem* stit = NULL;

	if (stcch) {
		stit = stcch->getStitByStref(stref);
		if (stit && !refresh) {
			if (strefSub) stcch->link(stref, *strefSub);
			return stit->stub;
		};
	};

	if (ixVNonetype == Stub::VecVNonetype::DASH) stub = "-";
	else if (ixVNonetype == Stub::VecVNonetype::SHORT) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(none)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmuser->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzskUsrStd --- BEGIN
			stub = rec->sref + " / " + getStubPrsStd(dbswzsk, rec->refWzskMPerson, ixWzskVLocale, ixVNonetype, stcch, &stref);
			// IP getStubWzskUsrStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

/******************************************************************************
 class WzskException
 ******************************************************************************/

WzskException::WzskException(
			const uint ix
			, const map<string,string>& vals
		) :
			SbeException(ix, vals)
		{
};

string WzskException::getSref() {
	string sref = SbeException::getSref();
	if (sref != "") return sref;
	
	
	return("");
};

/******************************************************************************
 class ContInfWzskAlert
 ******************************************************************************/

ContInfWzskAlert::ContInfWzskAlert(
			const string& TxtCpt
			, const string& TxtMsg1
			, const string& TxtMsg2
			, const string& TxtMsg3
			, const string& TxtMsg4
			, const string& TxtMsg5
			, const string& TxtMsg6
			, const string& TxtMsg7
			, const string& TxtMsg8
			, const string& TxtMsg9
			, const string& TxtMsg10
			, const string& TxtMsg11
			, const string& TxtMsg12
		) :
			Block()
			, TxtCpt(TxtCpt)
			, TxtMsg1(TxtMsg1)
			, TxtMsg2(TxtMsg2)
			, TxtMsg3(TxtMsg3)
			, TxtMsg4(TxtMsg4)
			, TxtMsg5(TxtMsg5)
			, TxtMsg6(TxtMsg6)
			, TxtMsg7(TxtMsg7)
			, TxtMsg8(TxtMsg8)
			, TxtMsg9(TxtMsg9)
			, TxtMsg10(TxtMsg10)
			, TxtMsg11(TxtMsg11)
			, TxtMsg12(TxtMsg12)
		{

	mask = {TXTCPT, TXTMSG1, TXTMSG2, TXTMSG3, TXTMSG4, TXTMSG5, TXTMSG6, TXTMSG7, TXTMSG8, TXTMSG9, TXTMSG10, TXTMSG11, TXTMSG12};
};

bool ContInfWzskAlert::all(
			const set<uint>& items
		) {
	if (!find(items, TXTCPT)) return false;
	if (!find(items, TXTMSG1)) return false;
	if (!find(items, TXTMSG2)) return false;
	if (!find(items, TXTMSG3)) return false;
	if (!find(items, TXTMSG4)) return false;
	if (!find(items, TXTMSG5)) return false;
	if (!find(items, TXTMSG6)) return false;
	if (!find(items, TXTMSG7)) return false;
	if (!find(items, TXTMSG8)) return false;
	if (!find(items, TXTMSG9)) return false;
	if (!find(items, TXTMSG10)) return false;
	if (!find(items, TXTMSG11)) return false;
	if (!find(items, TXTMSG12)) return false;

	return true;
};

void ContInfWzskAlert::writeJSON(
			Json::Value& sup
			, string difftag
		) {
	if (difftag == "") difftag = "ContInfWzskAlert";

	Json::Value& me = sup[difftag] = Json::Value(Json::objectValue);

	me["TxtCpt"] = TxtCpt;
	me["TxtMsg1"] = TxtMsg1;
	me["TxtMsg2"] = TxtMsg2;
	me["TxtMsg3"] = TxtMsg3;
	me["TxtMsg4"] = TxtMsg4;
	me["TxtMsg5"] = TxtMsg5;
	me["TxtMsg6"] = TxtMsg6;
	me["TxtMsg7"] = TxtMsg7;
	me["TxtMsg8"] = TxtMsg8;
	me["TxtMsg9"] = TxtMsg9;
	me["TxtMsg10"] = TxtMsg10;
	me["TxtMsg11"] = TxtMsg11;
	me["TxtMsg12"] = TxtMsg12;
};

void ContInfWzskAlert::writeXML(
			xmlTextWriter* wr
			, string difftag
			, bool shorttags
		) {
	if (difftag.length() == 0) difftag = "ContInfWzskAlert";

	string itemtag;
	if (shorttags)
		itemtag = "Ci";
	else
		itemtag = "ContitemInfWzskAlert";

	xmlTextWriterStartElement(wr, BAD_CAST difftag.c_str());
		writeStringAttr(wr, itemtag, "sref", "TxtCpt", TxtCpt);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg1", TxtMsg1);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg2", TxtMsg2);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg3", TxtMsg3);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg4", TxtMsg4);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg5", TxtMsg5);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg6", TxtMsg6);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg7", TxtMsg7);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg8", TxtMsg8);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg9", TxtMsg9);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg10", TxtMsg10);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg11", TxtMsg11);
		writeStringAttr(wr, itemtag, "sref", "TxtMsg12", TxtMsg12);
	xmlTextWriterEndElement(wr);
};

set<uint> ContInfWzskAlert::compare(
			const ContInfWzskAlert* comp
		) {
	set<uint> items;

	if (TxtCpt == comp->TxtCpt) insert(items, TXTCPT);
	if (TxtMsg1 == comp->TxtMsg1) insert(items, TXTMSG1);
	if (TxtMsg2 == comp->TxtMsg2) insert(items, TXTMSG2);
	if (TxtMsg3 == comp->TxtMsg3) insert(items, TXTMSG3);
	if (TxtMsg4 == comp->TxtMsg4) insert(items, TXTMSG4);
	if (TxtMsg5 == comp->TxtMsg5) insert(items, TXTMSG5);
	if (TxtMsg6 == comp->TxtMsg6) insert(items, TXTMSG6);
	if (TxtMsg7 == comp->TxtMsg7) insert(items, TXTMSG7);
	if (TxtMsg8 == comp->TxtMsg8) insert(items, TXTMSG8);
	if (TxtMsg9 == comp->TxtMsg9) insert(items, TXTMSG9);
	if (TxtMsg10 == comp->TxtMsg10) insert(items, TXTMSG10);
	if (TxtMsg11 == comp->TxtMsg11) insert(items, TXTMSG11);
	if (TxtMsg12 == comp->TxtMsg12) insert(items, TXTMSG12);

	return(items);
};

/******************************************************************************
 class DpchWzsk
 ******************************************************************************/

DpchWzsk::DpchWzsk(
			const uint ixWzskVDpch
		) :
			ixWzskVDpch(ixWzskVDpch)
		{
};

DpchWzsk::~DpchWzsk() {
};

/******************************************************************************
 class DpchInvWzsk
 ******************************************************************************/

DpchInvWzsk::DpchInvWzsk(
			const uint ixWzskVDpch
			, const ubigint oref
			, const ubigint jref
		) :
			DpchWzsk(ixWzskVDpch)
			, oref(oref)
			, jref(jref)
		{
};

DpchInvWzsk::~DpchInvWzsk() {
};

void DpchInvWzsk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchInvWzsk");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) add(SCROREF);
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) add(SCRJREF);
	};
};

void DpchInvWzsk::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWzsk");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		writeString(wr, "scrOref", Scr::scramble(oref));
		writeString(wr, "scrJref", Scr::scramble(jref));
	xmlTextWriterEndElement(wr);
};

/******************************************************************************
 class DpchRetWzsk
 ******************************************************************************/

DpchRetWzsk::DpchRetWzsk(
			const uint ixWzskVDpch
			, const string& scrOref
			, const string& scrJref
			, const utinyint ixOpVOpres
			, const utinyint pdone
		) :
			DpchWzsk(ixWzskVDpch)
			, scrOref(scrOref)
			, scrJref(scrJref)
			, ixOpVOpres(ixOpVOpres)
			, pdone(pdone)
		{
};

DpchRetWzsk::~DpchRetWzsk() {
};

void DpchRetWzsk::readXML(
			xmlXPathContext* docctx
			, string basexpath
			, bool addbasetag
		) {
	clear();

	string srefIxOpVOpres;

	bool basefound;

	if (addbasetag)
		basefound = checkUclcXPaths(docctx, basexpath, basexpath, "DpchRetWzsk");
	else
		basefound = checkXPath(docctx, basexpath);

	if (basefound) {
		if (extractStringUclc(docctx, basexpath, "scrOref", "", scrOref)) {
			oref = Scr::descramble(scrOref);
			add(OREF);
		};
		if (extractStringUclc(docctx, basexpath, "scrJref", "", scrJref)) {
			jref = Scr::descramble(scrJref);
			add(JREF);
		};
		if (extractStringUclc(docctx, basexpath, "srefIxOpVOpres", "", srefIxOpVOpres)) {
			ixOpVOpres = VecOpVOpres::getIx(srefIxOpVOpres);
			add(IXOPVOPRES);
		};
		if (extractUtinyintUclc(docctx, basexpath, "pdone", "", pdone)) add(PDONE);
	};
};

void DpchRetWzsk::writeXML(
			xmlTextWriter* wr
		) {
	xmlTextWriterStartElement(wr, BAD_CAST "DpchRetWzsk");
	xmlTextWriterWriteAttribute(wr, BAD_CAST "xmlns", BAD_CAST "http://www.mpsitech.com/wzsk");
		writeString(wr, "scrOref", scrOref);
		writeString(wr, "scrJref", scrJref);
		writeString(wr, "srefIxOpVOpres", VecOpVOpres::getSref(ixOpVOpres));
		writeUtinyint(wr, "pdone", pdone);
	xmlTextWriterEndElement(wr);
};
