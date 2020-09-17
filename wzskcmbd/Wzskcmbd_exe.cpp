/**
	* \file Wzskcmbd_exe.cpp
	* Wzsk combined daemon main (implementation)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#include "Wzskcmbd.h"

#include "Wzskcmbd_exe.h"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

Wzskcmbd* wzskcmbd;

/******************************************************************************
 class Wzskcmbd
 ******************************************************************************/

Wzskcmbd::Wzskcmbd(
			const string& exedir
			, const bool clearAll
			, const bool startMon
		) {
	pthread_attr_t attr;

	srand(time(NULL));

#if defined(SBECORE_MAR) || defined(SBECORE_MY)
	mysql_library_init(0, NULL, NULL);
#endif
#if defined(SBECORE_LITE)
	sqlite3_initialize();
#endif

	// 1. create exchange object
	xchg = new XchgWzskcmbd();
	xchg->exedir = exedir;

	// 2. load preferences and SSL key/certificate
	loadPref();
	if (xchg->stgwzskappsrv.https) loadKeycert();

	// 3. connect to database
	dbswzsk.init(xchg->stgwzskdatabase.ixDbsVDbstype, xchg->stgwzskdatabase.dbspath, xchg->stgwzskdatabase.dbsname, xchg->stgwzskdatabase.ip
			, xchg->stgwzskdatabase.port, xchg->stgwzskdatabase.username, xchg->stgwzskdatabase.password);

	// 4. initialize shared data
	xchg->shrdatJobprc.init(xchg, &dbswzsk);

	JobWzskAcqFpgaflg::shrdat.init(xchg, &dbswzsk);
	JobWzskAcqFpgapvw::shrdat.init(xchg, &dbswzsk);
	JobWzskAcqPreview::shrdat.init(xchg, &dbswzsk);
	JobWzskAcqPtcloud::shrdat.init(xchg, &dbswzsk);
	JobWzskActExposure::shrdat.init(xchg, &dbswzsk);
	JobWzskActLaser::shrdat.init(xchg, &dbswzsk);
	JobWzskActServo::shrdat.init(xchg, &dbswzsk);
	JobWzskIprAngle::shrdat.init(xchg, &dbswzsk);
	JobWzskIprCorner::shrdat.init(xchg, &dbswzsk);
	JobWzskIprTrace::shrdat.init(xchg, &dbswzsk);
	JobWzskSrcFpga::shrdat.init(xchg, &dbswzsk);
	JobWzskSrcSysinfo::shrdat.init(xchg, &dbswzsk);
	JobWzskSrcV4l2::shrdat.init(xchg, &dbswzsk);

	xchg->shrdatOpprc.init(xchg, &dbswzsk);

	// 5. start monitoring (optional)
	if (startMon) xchg->startMon();

	// 6. establish root job
	root = new RootWzsk(xchg, &dbswzsk, 0, clearAll);

	// 7. start job processor threads
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	cout << "\tstarting " << xchg->stgwzskcmbd.jobprcn << " job processor threads ... {" << flush;

	for (unsigned int i = 0; i < xchg->stgwzskcmbd.jobprcn; i++) {
		if (i != 0) cout << ", " << flush;

		xchg->cStable.lockMutex("Wzskcmbd", "Wzskcmbd[1]");

		jobprcs.push_back(0);
		pthread_create(&(jobprcs[i]), &attr, &WzskcmbdJobprc::run, (void*) xchg);

		xchg->cStable.wait();
		xchg->cStable.unlockMutex("Wzskcmbd", "Wzskcmbd[1]");
	};

	cout << "} success" << endl;

	// 8. start op processor threads
	cout << "\tstarting " << xchg->stgwzskcmbd.opprcn << " operation processor threads ... {" << flush;

	for (unsigned int i = 0; i < xchg->stgwzskcmbd.opprcn; i++) {
		if (i != 0) cout << ", " << flush;

		xchg->cStable.lockMutex("Wzskcmbd", "Wzskcmbd[2]");

		opprcs.push_back(0);
		pthread_create(&(opprcs[i]), &attr, &WzskcmbdOpprc::run, (void*) xchg);

		xchg->cStable.wait();
		xchg->cStable.unlockMutex("Wzskcmbd", "Wzskcmbd[2]");
	};

	cout << "} success" << endl;

	// 9. start web server
	if (xchg->stgwzskcmbd.appsrv) {
		cout << "\tstarting application server ..." << flush;
		appsrv = WzskcmbdAppsrv::start(xchg);
		cout << " success" << endl;
	};

	// 10. start DDS publisher
	if (xchg->stgwzskcmbd.ddspub) {
		cout << "\tstarting DDS publisher ..." << flush;

		xchg->cStable.lockMutex("Wzskcmbd", "Wzskcmbd[3]");

		pthread_create(&ddspub, &attr, &WzskcmbdDdspub::run, (void*) xchg);

		xchg->cStable.wait();
		xchg->cStable.unlockMutex("Wzskcmbd", "Wzskcmbd[3]");

		cout << " success" << endl;
	};

	// 11. start OPC UA server
	if (xchg->stgwzskcmbd.uasrv) {
		cout << "\tstarting OPC UA server ..." << flush;

		xchg->cStable.lockMutex("Wzskcmbd", "Wzskcmbd[4]");

		pthread_create(&uasrv, &attr, &WzskcmbdUasrv::run, (void*) xchg);

		xchg->cStable.wait();
		xchg->cStable.unlockMutex("Wzskcmbd", "Wzskcmbd[4]");

		cout << " success" << endl;
	};

	pthread_attr_destroy(&attr);
};

Wzskcmbd::~Wzskcmbd() {
	// 1. stop OPC UA server
	if (xchg->stgwzskcmbd.uasrv) {
		pthread_cancel(uasrv);
		pthread_join(uasrv, NULL);
	};

	// 2. stop DDS publisher
	if (xchg->stgwzskcmbd.ddspub) {
		pthread_cancel(ddspub);
		pthread_join(ddspub, NULL);
	};

	// 3. stop web server
	if (xchg->stgwzskcmbd.appsrv) WzskcmbdAppsrv::stop(appsrv);

	// 4. end op processor threads
	for (unsigned int i = 0; i < opprcs.size(); i++) {
		//if (opprcs[i]) {
			pthread_cancel(opprcs[i]);
			pthread_join(opprcs[i], NULL);
		//};
	};

	// 5. end job processor threads
	for (unsigned int i = 0; i < jobprcs.size(); i++) {
		//if (jobprcs[i]) {
			pthread_cancel(jobprcs[i]);
			pthread_join(jobprcs[i], NULL);
		//};
	};

	// 6. delete root job
	delete root;
	root = NULL;

	// 7. terminate shared data
	xchg->shrdatOpprc.term(xchg);

	JobWzskAcqFpgaflg::shrdat.term(xchg);
	JobWzskAcqFpgapvw::shrdat.term(xchg);
	JobWzskAcqPreview::shrdat.term(xchg);
	JobWzskAcqPtcloud::shrdat.term(xchg);
	JobWzskActExposure::shrdat.term(xchg);
	JobWzskActLaser::shrdat.term(xchg);
	JobWzskActServo::shrdat.term(xchg);
	JobWzskIprAngle::shrdat.term(xchg);
	JobWzskIprCorner::shrdat.term(xchg);
	JobWzskIprTrace::shrdat.term(xchg);
	JobWzskSrcFpga::shrdat.term(xchg);
	JobWzskSrcSysinfo::shrdat.term(xchg);
	JobWzskSrcV4l2::shrdat.term(xchg);

	xchg->shrdatJobprc.term(xchg);

	// 8. store preferences
	storePref();

	// 9. delete exchange object
	delete xchg;
};

void Wzskcmbd::loadPref() {
	xmlDoc* doc = NULL;
	xmlXPathContext* docctx = NULL;

	string basexpath;

	parseFile(xchg->exedir + "/PrefWzskcmbd.xml", &doc, &docctx);

	if (checkUclcXPaths(docctx, basexpath, "/", "PrefWzskcmbd")) {
		xchg->stgwzskappearance.readXML(docctx, basexpath, true);
		xchg->stgwzskappsrv.readXML(docctx, basexpath, true);
		xchg->stgwzskcamera.readXML(docctx, basexpath, true);
		xchg->stgwzskcmbd.readXML(docctx, basexpath, true);
		xchg->stgwzskdatabase.readXML(docctx, basexpath, true);
		xchg->stgwzskddspub.readXML(docctx, basexpath, true);
		xchg->stgwzskframegeo.readXML(docctx, basexpath, true);
		xchg->stgwzskglobal.readXML(docctx, basexpath, true);
		xchg->stgwzskpath.readXML(docctx, basexpath, true);
		xchg->stgwzskuasrv.readXML(docctx, basexpath, true);
		JobWzskAcqPtcloud::stg.readXML(docctx, basexpath, true);
		JobWzskActLaser::stg.readXML(docctx, basexpath, true);
		JobWzskActServo::stg.readXML(docctx, basexpath, true);
		JobWzskIprCorner::stg.readXML(docctx, basexpath, true);
		JobWzskIprTrace::stg.readXML(docctx, basexpath, true);
		JobWzskSrcFpga::stg.readXML(docctx, basexpath, true);
		JobWzskSrcSysinfo::stg.readXML(docctx, basexpath, true);
		JobWzskSrcV4l2::stg.readXML(docctx, basexpath, true);
	};

	closeParsed(doc, docctx);

	xchg->acvpath = xchg->stgwzskpath.acvpath;
#ifdef _WIN32
	if (_access(xchg->acvpath.c_str(), 0)) throw SbeException(SbeException::PATHNF, {{"path",xchg->acvpath}});
#else
	if (access(xchg->acvpath.c_str(), R_OK)) throw SbeException(SbeException::PATHNF, {{"path",xchg->acvpath}});
#endif

	xchg->tmppath = xchg->stgwzskpath.tmppath;
#ifdef _WIN32
	if (_access(xchg->tmppath.c_str(), 0)) throw SbeException(SbeException::PATHNF, {{"path",xchg->tmppath}});
#else
	if (access(xchg->tmppath.c_str(), R_OK)) throw SbeException(SbeException::PATHNF, {{"path",xchg->tmppath}});
#endif

	xchg->helpurl = xchg->stgwzskpath.helpurl;
};

void Wzskcmbd::storePref() {
	xmlTextWriter* wr = NULL;

	startwriteFile(xchg->exedir + "/PrefWzskcmbd.xml", &wr);
	xmlTextWriterStartElement(wr, BAD_CAST "PrefWzskcmbd");
		xchg->stgwzskappearance.writeXML(wr);
		xchg->stgwzskappsrv.writeXML(wr);
		xchg->stgwzskcamera.writeXML(wr);
		xchg->stgwzskcmbd.writeXML(wr);
		xchg->stgwzskdatabase.writeXML(wr);
		xchg->stgwzskddspub.writeXML(wr);
		xchg->stgwzskframegeo.writeXML(wr);
		xchg->stgwzskglobal.writeXML(wr);
		xchg->stgwzskpath.writeXML(wr);
		xchg->stgwzskuasrv.writeXML(wr);
		JobWzskAcqPtcloud::stg.writeXML(wr);
		JobWzskActLaser::stg.writeXML(wr);
		JobWzskActServo::stg.writeXML(wr);
		JobWzskIprCorner::stg.writeXML(wr);
		JobWzskIprTrace::stg.writeXML(wr);
		JobWzskSrcFpga::stg.writeXML(wr);
		JobWzskSrcSysinfo::stg.writeXML(wr);
		JobWzskSrcV4l2::stg.writeXML(wr);
	xmlTextWriterEndElement(wr);
	closewriteFile(wr);
};

void Wzskcmbd::loadKeycert() {
	ifstream infile;
	char* buf = new char[1048576];

	string s;

	// key file
	s = xchg->exedir + "/server.key";
	infile.open(s.c_str(), ifstream::in);
	if (infile.fail()) throw SbeException(SbeException::PATHNF, {{"path",s}});

	while (infile.good() && !infile.eof()) {
		s = StrMod::readLine(infile, buf, 1048576);
		xchg->key += s + "\n";
	};

	infile.close();

	// certificate file
	s = xchg->exedir + "/server.pem";
	infile.open(s.c_str(), ifstream::in);
	if (infile.fail()) throw SbeException(SbeException::PATHNF, {{"path",s}});

	while (infile.good() && !infile.eof()) {
		s = StrMod::readLine(infile, buf, 1048576);
		xchg->cert += s + "\n";
	};

	infile.close();

	delete[] buf;
};

/******************************************************************************
 settings for jobs, operation packs and operations
 ******************************************************************************/

StgJobWzskAcqPtcloud JobWzskAcqPtcloud::stg;
StgJobWzskActLaser JobWzskActLaser::stg;
StgJobWzskActServo JobWzskActServo::stg;
StgJobWzskIprCorner JobWzskIprCorner::stg;
StgJobWzskIprTrace JobWzskIprTrace::stg;
StgJobWzskSrcFpga JobWzskSrcFpga::stg;
StgJobWzskSrcSysinfo JobWzskSrcSysinfo::stg;
StgJobWzskSrcV4l2 JobWzskSrcV4l2::stg;

/******************************************************************************
 shared data for jobs, operation packs and operations
 ******************************************************************************/

ShrdatJobWzskAcqFpgaflg JobWzskAcqFpgaflg::shrdat;
ShrdatJobWzskAcqFpgapvw JobWzskAcqFpgapvw::shrdat;
ShrdatJobWzskAcqPreview JobWzskAcqPreview::shrdat;
ShrdatJobWzskAcqPtcloud JobWzskAcqPtcloud::shrdat;
ShrdatJobWzskActExposure JobWzskActExposure::shrdat;
ShrdatJobWzskActLaser JobWzskActLaser::shrdat;
ShrdatJobWzskActServo JobWzskActServo::shrdat;
ShrdatJobWzskIprAngle JobWzskIprAngle::shrdat;
ShrdatJobWzskIprCorner JobWzskIprCorner::shrdat;
ShrdatJobWzskIprTrace JobWzskIprTrace::shrdat;
ShrdatJobWzskSrcFpga JobWzskSrcFpga::shrdat;
ShrdatJobWzskSrcSysinfo JobWzskSrcSysinfo::shrdat;
ShrdatJobWzskSrcV4l2 JobWzskSrcV4l2::shrdat;

/******************************************************************************
 main program
 ******************************************************************************/

void showSubjobs(
			XchgWzskcmbd* xchg
			, JobWzsk* job
			, Jobinfo* jobinfo
			, bool clstns
			, bool ops
			, bool presets
			, bool sges
			, bool dcolcont
			, bool stmgrcont
			, unsigned int indent
		) {
	string id;

	string setgray = "\033[38;2;196;196;196m";
	string reset = "\033[0m";

	bool csjobNotJob = false;
	bool srvNotCli = false;

	DcolWzsk* dcol = NULL;
	StmgrWzsk* stmgr = NULL;

	vector<uint> icsWzskVCall;
	vector<uint> icsVJobmask;

	vector<uint> icsWzskVPreset;
	vector<Arg> args;

	string s;

	// indentation
	for (unsigned int i = 0; i < indent; i++) id = id + "\t";

	// actual entry
	if (jobinfo->jrefsSub.empty()) cout << "\t" << id << "- ";
	else cout << "\t" << id << "+ ";
	cout << VecWzskVJob::getSref(job->ixWzskVJob);

	csjobNotJob = xchg->getCsjobNotJob(job->ixWzskVJob);
	if (csjobNotJob) srvNotCli = ((CsjobWzsk*) job)->srvNotCli;

	if (csjobNotJob) {
		if (srvNotCli) cout << "/SRV";
		else cout << "/CLI";
	};

	cout << " (" << job->jref;

	dcol = xchg->getDcolByJref(job->jref, false);
	if (dcol) {
		cout << ", dcol";
		dcol->unlockAccess("", "showSubjobs");
	};

	stmgr = xchg->getStmgrByJref(job->jref);
	if (stmgr) {
		cout << ", stmgr";
		stmgr->unlockAccess("", "showSubjobs");
	};

	cout << ")" << endl;

	if (clstns) {
		// call listeners
		cout << setgray;

		xchg->getClstnsByJref(job->jref, Clstn::VecVTarget::JOB, icsWzskVCall, icsVJobmask);
		for (unsigned int i = 0; i < icsWzskVCall.size(); i++)
					cout << "\t\t" << id << VecWzskVCall::getSref(icsWzskVCall[i]) << " (" << Clstn::VecVJobmask::getSref(icsVJobmask[i]) << ")" << endl;

		xchg->getClstnsByJref(job->jref, Clstn::VecVTarget::STMGR, icsWzskVCall, icsVJobmask);
		for (unsigned int i = 0; i < icsWzskVCall.size(); i++)
					cout << "\t\t" << id << "stmgr: " << VecWzskVCall::getSref(icsWzskVCall[i]) << endl;

		cout << reset;
	};

	if (ops) {
		// ops
		cout << setgray;

		job->mOps.lock("", "showSubjobs", "jref=" + to_string(job->jref));

		for (auto it = job->ops.begin(); it != job->ops.end(); it++)
					cout << "\t\t" << id << VecWzskVDpch::getSref((*it)->ixVDpch).substr(4+3) << " (" << to_string((*it)->oref) << "): " << (*it)->squawk << endl;

		job->mOps.unlock("", "showSubjobs", "jref=" + to_string(job->jref));

		cout << reset;
	};

	if (presets) {
		// presettings
		cout << setgray;

		xchg->getPresetsByJref(job->jref, icsWzskVPreset, args);

		for (unsigned int i = 0; i < icsWzskVPreset.size(); i++)
					cout << "\t\t" << id << VecWzskVPreset::getSref(icsWzskVPreset[i]) << ": " << args[i].to_string() << endl;

		cout << reset;
	};

	if (sges) {
		// stages
		if (!csjobNotJob || (csjobNotJob && srvNotCli)) {
			s = job->getSquawk(NULL);

			if (s != "") {
				cout << setgray;

				cout << "\t\t" << id << job->ixVSge << ": " << s << endl;

				cout << reset;
			};
		};
	};

	if (dcolcont) {
		// dispatch collector content
		dcol = xchg->getDcolByJref(job->jref, false);

		if (dcol) {
			cout << setgray;

			for (auto it = dcol->dpchs.begin(); it != dcol->dpchs.end(); it++)
						cout << "\t\t" << id << VecWzskVDpch::getSref((*it)->ixWzskVDpch) << " (" << (*it)->jref << ")" << endl;

			dcol->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	if (stmgrcont) {
		// stub manager content
		stmgr = xchg->getStmgrByJref(job->jref);

		if (stmgr) {
			cout << setgray;

			for (auto it = stmgr->stcch->nodes.begin(); it != stmgr->stcch->nodes.end(); it++)
						cout << "\t\t" << id << VecWzskVStub::getSref(it->second->stref.ixVStub) << " (" << it->second->stref.ref << "): " << it->second->stub << endl;

			stmgr->unlockAccess("", "showSubjobs");
			cout << reset;
		};
	};

	// sub-entries
	Jobinfo* jobinfo2 = NULL;

	for (auto it = jobinfo->jrefsSub.begin(); it != jobinfo->jrefsSub.end(); it++) {
		job = xchg->getJobByJref(*it);
		jobinfo2 = xchg->getJobinfoByJref(*it);

		if (job && jobinfo2) showSubjobs(xchg, job, jobinfo2, clstns, ops, presets, sges, dcolcont, stmgrcont, indent + 1);
	};
};

void handleSignal(
			int sig
		) {
	// deleting wzskcmbd forces PrefWzskcmbd to be written
	if (wzskcmbd) delete wzskcmbd;

	exit(sig);
};

int main(
			const int argc
			, const char** argv
		) {
	char* buf = NULL;
	string exedir;
	size_t ptr;

	string s;
	bool nocp = false;
	bool clearAll = false;
	bool startMon = false;

	Cond cDummy("cDummy", "", "main");

	string cmd;

	string input;
	int iinput;

	string s_backup;

	XchgWzskcmbd* xchg;

	JobWzsk* job;
	Jobinfo* jobinfo;

	ReqWzsk* req;

	wzskcmbd = NULL;

	// ensure proper termination on signals such as ctrl-c
#ifndef _WIN32
	signal(SIGHUP, handleSignal);
#endif
	signal(SIGINT, handleSignal); // 2
	signal(SIGTERM, handleSignal); // 15

	// evaluate command line options
	for (int i = 1; i < argc; i++) {
		s = argv[i];

		if (s.find("-exedir=") == 0) exedir = s.substr(8);
		else if (s == "-nocp") nocp = true;
		else if (s == "-clearAll") clearAll = true;
		else if (s == "-startMon") startMon = true;
	};

	if (exedir == "") {
		// determine executable path
		buf = new char[4096];

		if (readlink("/proc/self/exe", buf, 4096) >= 1) {
			exedir = buf;

		} else {
			if (strlen(argv[0]) >= 1) {
				exedir = argv[0];

				if (exedir[0] != '/') {
					if (getcwd(buf, 4096)) {
						exedir = "/" + exedir;
						exedir = buf + exedir;
					};
				};
			};
		};

		delete[] buf;

		ptr = exedir.rfind('/');
		if ((ptr != string::npos) && (ptr > 0)) exedir = exedir.substr(0, ptr);
	};

	try {
		// welcome message
		cout << "Welcome to Whiznium StarterKit v0.1.33!" << endl;

		// calls wzskcmbd.init()
		wzskcmbd = new Wzskcmbd(exedir, clearAll, startMon);
		xchg = wzskcmbd->xchg;

		cout << "Initialization complete." << endl;
		cout << endl;

		if (nocp) {
			// wait on a dummy condition
			cDummy.lockMutex("", "main");
			cDummy.wait("", "main");
			cDummy.unlockMutex("", "main");

		} else {
			// main command loop
			while (cmd != "quit") {
				cout << "Wzskcmbd >> ";

				do {
					cin.clear();
					cin >> cmd;
				} while (cin.fail());

				if (cmd == "quit") {

				} else if (cmd == "cmdsetStd") {
					cout << "\tquit" << endl;

					cout << "\tstartMon" << endl;
					cout << "\tstopMon" << endl;

					cout << "\tstartMtdump" << endl;
					cout << "\tstopMtdump" << endl;

					cout << "\tshowJobs" << endl;
					cout << "\tshowSubjobs" << endl;

					cout << "\tshowClstns" << endl;
					cout << "\tshowOps" << endl;
					cout << "\tshowPresets" << endl;
					cout << "\tshowSges" << endl;

					cout << "\tshowDcolContent" << endl;
					cout << "\tshowStmgrContent" << endl;

					cout << "\tgotoJob" << endl;
					cout << "\tgotoSupjob" << endl;

				} else if (cmd == "startMon") {
					xchg->startMon();

				} else if (cmd == "stopMon") {
					xchg->stopMon();

				} else if (cmd == "startMtdump") {
					Mt::ixVVerbose = Mt::VecVVerbose::ALL;

				} else if (cmd == "stopMtdump") {
					Mt::ixVVerbose = Mt::VecVVerbose::ERROR;

				} else if ( (cmd == "showJobs") || (cmd == "showSubjobs") || (cmd == "showClstns") || (cmd == "showOps") || (cmd == "showPresets")
							|| (cmd == "showSges") || (cmd == "showDcolContent") || (cmd == "showStmgrContent") ) {

					xchg->rwmJobs.rlock("", "main[1]");

					if (cmd == "showSubjobs") {
						job = xchg->getJobByJref(xchg->jrefCmd);
						jobinfo = xchg->getJobinfoByJref(xchg->jrefCmd);
					} else {
						job = xchg->getJobByJref(xchg->jrefRoot);
						jobinfo = xchg->getJobinfoByJref(xchg->jrefRoot);
					};

					if (job && jobinfo) {
						if (cmd == "showJobs") showSubjobs(xchg, job, jobinfo, false, false, false, false, false, false, 0);
						else if (cmd == "showSubjobs") showSubjobs(xchg, job, jobinfo, false, false, false, false, false, false, 0);
						else if (cmd == "showClstns") showSubjobs(xchg, job, jobinfo, true, false, false, false, false, false, 0);
						else if (cmd == "showOps") showSubjobs(xchg, job, jobinfo, false, true, false, false, false, false, 0);
						else if (cmd == "showPresets") showSubjobs(xchg, job, jobinfo, false, false, true, false, false, false, 0);
						else if (cmd == "showSges") showSubjobs(xchg, job, jobinfo, false, false, false, true, false, false, 0);
						else if (cmd == "showDcolContent") showSubjobs(xchg, job, jobinfo, false, false, false, false, true, false, 0);
						else if (cmd == "showStmgrContent") showSubjobs(xchg, job, jobinfo, false, false, false, false, false, true, 0);
					};

					xchg->rwmJobs.runlock("", "main[1]");

				} else if (cmd == "gotoJob") {
					cout << "\tjob reference: ";
					cin >> input;
					iinput = atoi(input.c_str());

					if (xchg->getJobinfoByJref(iinput)) xchg->jrefCmd = iinput;
					else cout << "\tjob reference doesn't exist!" << endl;

				} else if (cmd == "gotoSupjob") {
					xchg->rwmJobs.rlock("", "main[2]");

					jobinfo = xchg->getJobinfoByJref(xchg->jrefCmd);

					if (jobinfo) {
						if (jobinfo->jrefSup != 0) xchg->jrefCmd = jobinfo->jrefSup;
						else cout << "\talready at topmost job!" << endl;
					};

					xchg->rwmJobs.runlock("", "main[2]");

				} else {
					job = xchg->getJobByJref(xchg->jrefCmd);

					if (job) {
						req = new ReqWzsk(ReqWzsk::VecVBasetype::CMD, ReqWzsk::VecVState::RECEIVE);
						req->cmd = cmd;
						req->jref = xchg->jrefCmd;

						xchg->addReq(req);

						s_backup = "";

						while (req->ixVState != ReqWzsk::VecVState::REPLY) {
							// wait for job processor to finish or to time out
							req->cReady.lockMutex("", "main");
							req->cReady.timedwait(1000000, "", "main");
							req->cReady.unlockMutex("", "main");

							if (req->ixVState == ReqWzsk::VecVState::WAITPRC) {
								cout << "\twaiting for processing" << endl;

							} else if (req->ixVState == ReqWzsk::VecVState::PRC) {
								s = job->getSquawk(&(wzskcmbd->dbswzsk));
								if (s != s_backup) {
									cout << "\t" << s << endl;
									s_backup = s;
								};
							};
						};

						delete req;
					};
				};
			};
		};

		delete wzskcmbd;

	} catch (WzskException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
		throw;

	} catch (SbeException& e) {
		cout << e.getSquawk(VecWzskVError::getIx, VecWzskVError::getTitle, VecWzskVLocale::ENUS) << endl;
		throw;
	};

	return(0);
};

