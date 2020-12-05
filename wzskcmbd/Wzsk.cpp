/**
	* \file Wzsk.cpp
	* Wzsk global functionality (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
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

	// determine file size in kB
	struct stat st;
	stat(path.c_str(), &st);
	Size = st.st_size / 1024;

	dbswzsk->tblwzskmfile->insertNewRec(&fil, 0, grp, own, refIxVTbl, refUref, osrefKContent, Archived, Filename, "", srefKMimetype, Size, Comment);
	
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
void Wzsk::getPvwWh(
			const uint ixWzskVPvwmode
			, unsigned int& w
			, unsigned int& h
		) {
	if ((ixWzskVPvwmode == VecWzskVPvwmode::BINGRAY) || (ixWzskVPvwmode == VecWzskVPvwmode::RAWGRAY)) {
		w = 256;
		h = 192;
	} else if ((ixWzskVPvwmode == VecWzskVPvwmode::BINRGB) || (ixWzskVPvwmode == VecWzskVPvwmode::RAWRGB)) {
		w = 160;
		h = 120;
	} else {
		w = 0;
		h = 0;
	};
};

bool Wzsk::getPvwRawNotBin(
			const uint ixWzskVPvwmode
		) {
	return ((ixWzskVPvwmode == VecWzskVPvwmode::RAWGRAY) || (ixWzskVPvwmode == VecWzskVPvwmode::RAWRGB));
};

bool Wzsk::getPvwGrayNotRgb(
			const uint ixWzskVPvwmode
		) {
	return ((ixWzskVPvwmode == VecWzskVPvwmode::BINGRAY) || (ixWzskVPvwmode == VecWzskVPvwmode::RAWGRAY));
};

uint Wzsk::getIxWzskVPvwmode(
			const bool rawNotBin
			, const bool grayNotRgb
		) {
	if (!rawNotBin) {
		if (!grayNotRgb) return VecWzskVPvwmode::BINRGB;
		return VecWzskVPvwmode::BINGRAY;
	} else {
		if (!grayNotRgb) return VecWzskVPvwmode::RAWRGB;
		return VecWzskVPvwmode::RAWGRAY;
	};
};

void Wzsk::getFlgWh(
			unsigned int& w
			, unsigned int& h
		) {
	w = 1024;
	h = 768;
};

void Wzsk::bitmapToXy(
			unsigned char* src
			, const bool src16Not8
			, const unsigned int width
			, const unsigned int height
			, vector<int>& xs
			, vector<int>& ys
			, const unsigned int cntPerRowMax
			, const bool roi
			, const vector<int>& xsRoi
			, const vector<int>& ysRoi
			, const bool rot180
			, const bool append
		) {
	bool byteflip = src16Not8 && !bigendian();

	unsigned int ldix, stix;

	register unsigned char byte0, byte1;
	register uint16_t data;

	register uint16_t test;

	unsigned int cnt;

	vector<int> dxsRoi;
	vector<int> dysRoi;

	unsigned int Nroi;

	double rx, ry, x0, dx, y0, dy, mu, lam;

	if (!append) {
		xs.clear();
		ys.clear();
	};

	if (roi) {
		// vectors between each two points
		dxsRoi.resize(xsRoi.size());
		dysRoi.resize(xsRoi.size());

		for (unsigned int i = 0; i < xsRoi.size(); i++) {
			unsigned int j = i + 1;
			if (j == xsRoi.size()) j = 0;

			dxsRoi[i] = xsRoi[j] - xsRoi[i];
			dysRoi[i] = ysRoi[j] - ysRoi[i];
		};
	};

	for (unsigned int i = 0; i < height; i++) {
		cnt = 0;

		for (unsigned int j = 0; j < width; j += 16) {
			ldix = i * width/8 + j/8;

			if (!byteflip) {
				byte0 = src[ldix];
				byte1 = src[ldix + 1];
			} else {
				byte1 = src[ldix];
				byte0 = src[ldix + 1];
			};

			data = (byte0 << 8) + byte1;

			for (stix = j, test = 32768; test != 0; stix++, test >>= 1)
				if (data & test) {
					Nroi = 0;

					if (roi) {
						// count vector intersections with line pointing from test point to x = -width/2
						for (unsigned int k = 0; k < xsRoi.size(); k++) {
							if (!rot180) {
								rx = stix;
								ry = i;
							} else {
								rx = width - stix - 1;
								ry = height - i - 1;
							};

							x0 = xsRoi[k] + ((double) width)/2.0;
							dx = dxsRoi[k];

							y0 = ysRoi[k] + ((double) height)/2.0;
							dy = dysRoi[k];

							if (dy == 0.0) continue;

							mu = (ry - y0) / dy;
							if (mu < 0.0) continue;
							if (mu > 1.0) continue;

							if (rx == 0.0) continue;

							lam = 1.0 - (x0 + mu * dx) / rx;
							if (lam < 0.0) continue;
							if (lam <= 1.0) Nroi++;
						};
					};

					if (!roi || (Nroi%2)) {
						if (!rot180) {
							xs.push_back(((int) stix) - ((int) width)/2);
							ys.push_back(((int) i) - ((int) height)/2);
						} else {
							xs.push_back(((int) (width - stix - 1)) - ((int) width)/2);
							ys.push_back(((int) (height - i - 1)) - ((int) height)/2);
						};

						cnt++;
						if (cnt >= cntPerRowMax) break;
					};
				};

			if (cnt >= cntPerRowMax) break;
		};
	};
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
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKGROUP) return getStubGroup(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKOBJSTD) return getStubObjStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKOGRHSREF) return getStubOgrHsref(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKOGRSTD) return getStubOgrStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKOWNER) return getStubOwner(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKPRSSTD) return getStubPrsStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKSESMENU) return getStubSesMenu(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKSESSTD) return getStubSesStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKSHTSTD) return getStubShtStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKUSGSTD) return getStubUsgStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);
	else if (ixWzskVStub == VecWzskVStub::STUBWZSKUSRSTD) return getStubUsrStd(dbswzsk, ref, ixWzskVLocale, ixVNonetype, stcch, strefSub, refresh);

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
	// example: "customers.xlsx"
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no file)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Datei)";
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user group)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Benutzergruppe)";
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

string StubWzsk::getStubObjStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Tux"
	string stub;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKOBJSTD, ref, ixWzskVLocale);
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keines)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no object)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(kein Objekt)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmobject->loadTitByRef(ref, stub)) {
			if (stcch) {
				if (!stit) stit = stcch->addStit(stref);
				stit->stub = stub;
			};
		};
	};

	return stub;
};

string StubWzsk::getStubOgrHsref(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "icon;comp"
	string stub;

	WzskMObjgroup* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKOGRHSREF, ref, ixWzskVLocale);
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no object group)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Objektgruppe)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmobjgroup->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			stub = rec->sref;
			if (rec->supRefWzskMObjgroup != 0) stub = getStubOgrHsref(dbswzsk, rec->supRefWzskMObjgroup, ixWzskVLocale, ixVNonetype, stcch, &stref) + ";" + stub;
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzsk::getStubOgrStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "(icon;comp) Open Source Software"
	string stub;

	WzskMObjgroup* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKOGRSTD, ref, ixWzskVLocale);
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no object group)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Objektgruppe)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmobjgroup->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubOgrStd --- IBEGIN
			WzskJMObjgroupTitle* ogrJTit = NULL;

			if (dbswzsk->tblwzskjmobjgrouptitle->loadRecByOgrLcl(rec->ref, ixWzskVLocale, &ogrJTit)) {
				stub = ogrJTit->Title;
				delete ogrJTit;

			} else stub = rec->Title;;

			if (rec->supRefWzskMObjgroup != 0) stub = "(" + getStubOgrHsref(dbswzsk, rec->supRefWzskMObjgroup, ixWzskVLocale, ixVNonetype, stcch, &stref) + ") " + stub;
			// IP getStubOgrStd --- IEND
			if (stit) stit->stub = stub;
			delete rec;
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(kein Benutzer)";
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no person)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Person)";
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no session)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Sitzung)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzskSesMenu --- BEGIN
			if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "user " + getStubUsrStd(dbswzsk, rec->refWzskMUser, ixWzskVLocale, ixVNonetype, stcch, &stref) + ";logged in from " + rec->Ip + ";since " + Ftm::stamp(rec->start);
			else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "Benutzer " + getStubUsrStd(dbswzsk, rec->refWzskMUser, ixWzskVLocale, ixVNonetype, stcch, &stref) + ";eingeloggt von " + rec->Ip + ";seit " + Ftm::stamp(rec->start);
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no session)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Sitzung)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmsession->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubWzskSesStd --- BEGIN
			if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = Ftm::stamp(rec->start) + " from " + rec->Ip;
			else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = Ftm::stamp(rec->start) + " von " + rec->Ip;
			// IP getStubWzskSesStd --- END
			if (stit) stit->stub = stub;
			delete rec;
		};
	};

	return stub;
};

string StubWzsk::getStubShtStd(
			DbsWzsk* dbswzsk
			, const ubigint ref
			, const uint ixWzskVLocale
			, const uint ixVNonetype
			, Stcch* stcch
			, stcchitemref_t* strefSub
			, const bool refresh
		) {
	// example: "Tux 1-9-2019 8:23:05"
	string stub;

	WzskMShot* rec = NULL;

	stcchitemref_t stref(VecWzskVStub::STUBWZSKSHTSTD, ref, ixWzskVLocale);
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no shot)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Aufnahme)";
	};

	if (ref != 0) {
		if (dbswzsk->tblwzskmshot->loadRecByRef(ref, &rec)) {
			if (stcch && !stit) stit = stcch->addStit(stref);
			// IP getStubShtStd --- IBEGIN
			stub = getStubObjStd(dbswzsk, rec->refWzskMObject, ixWzskVLocale, ixVNonetype, stcch, &stref) + " " + Ftm::stamp(rec->start);
			// IP getStubShtStd --- IEND
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user group)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keine Benutzergruppe)";
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
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(keiner)";
	} else if (ixVNonetype == Stub::VecVNonetype::FULL) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) stub = "(no user)";
		else if (ixWzskVLocale == VecWzskVLocale::DECH) stub = "(kein Benutzer)";
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
	
	if (ix == GPIO) return("gpio");
	if (ix == PWM) return("pwm");
	if (ix == SPIDEV) return("spidev");
	if (ix == V4L2) return("v4l2");
	
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
		{
	this->TxtCpt = TxtCpt;
	this->TxtMsg1 = TxtMsg1;
	this->TxtMsg2 = TxtMsg2;
	this->TxtMsg3 = TxtMsg3;
	this->TxtMsg4 = TxtMsg4;
	this->TxtMsg5 = TxtMsg5;
	this->TxtMsg6 = TxtMsg6;
	this->TxtMsg7 = TxtMsg7;
	this->TxtMsg8 = TxtMsg8;
	this->TxtMsg9 = TxtMsg9;
	this->TxtMsg10 = TxtMsg10;
	this->TxtMsg11 = TxtMsg11;
	this->TxtMsg12 = TxtMsg12;

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
		) {
	this->ixWzskVDpch = ixWzskVDpch;
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
		{
	this->oref = oref;
	this->jref = jref;
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
		{
	this->scrOref = scrOref;
	this->scrJref = scrJref;
	this->ixOpVOpres = ixOpVOpres;
	this->pdone = pdone;
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







