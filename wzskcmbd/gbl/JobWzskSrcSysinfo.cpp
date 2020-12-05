/**
	* \file JobWzskSrcSysinfo.cpp
	* job handler for job JobWzskSrcSysinfo (implementation)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
	*/
// IP header --- ABOVE

#ifdef WZSKCMBD
	#include <Wzskcmbd.h>
#else
	#include <Wzskd.h>
#endif

#include "JobWzskSrcSysinfo.h"

#include "JobWzskSrcSysinfo_blks.cpp"

using namespace std;
using namespace Sbecore;
using namespace Xmlio;

// IP ns.cust --- INSERT

// IP ns.spec --- INSERT

// IP Shrdat.subs --- INSERT

/******************************************************************************
 class JobWzskSrcSysinfo::Shrdat
 ******************************************************************************/

JobWzskSrcSysinfo::Shrdat::Shrdat() :
			ShrdatWzsk("JobWzskSrcSysinfo", "Shrdat")
		{
};

void JobWzskSrcSysinfo::Shrdat::init(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
		) {
	// IP Shrdat.init --- IBEGIN
	const unsigned int N = 60;

	loadAll.resize(N, 0.0);
	loadCore0.resize(N, 0.0);
	loadCore1.resize(N, 0.0);
	loadCore2.resize(N, 0.0);
	loadCore3.resize(N, 0.0);

	temp.resize(N, 0.0);

	NCore = 0;

	unkAll = idleAll = 0;
	unkCore0 = idleCore0 = 0;
	unkCore1 = idleCore1 = 0;
	unkCore2 = idleCore2 = 0;
	unkCore3 = idleCore3 = 0;
	
	tempOffset = 0.0;
	tempScale = 0.0;
	// IP Shrdat.init --- IEND
};

void JobWzskSrcSysinfo::Shrdat::term(
			XchgWzsk* xchg
		) {
	// IP Shrdat.term --- INSERT
};

/******************************************************************************
 class JobWzskSrcSysinfo
 ******************************************************************************/

JobWzskSrcSysinfo::JobWzskSrcSysinfo(
			XchgWzsk* xchg
			, DbsWzsk* dbswzsk
			, const ubigint jrefSup
			, const uint ixWzskVLocale
		) :
			CsjobWzsk(xchg, VecWzskVJob::JOBWZSKSRCSYSINFO, jrefSup, ixWzskVLocale)
		{
	jref = xchg->addJob(dbswzsk, this, jrefSup);

	// IP constructor.cust1 --- INSERT

	// IP constructor.spec1 --- INSERT

	// IP constructor.cust2 --- INSERT

	// IP constructor.spec2 --- INSERT

	if (srvNotCli) changeStage(dbswzsk, VecVSge::RUN); // IP constructor.cust3 --- ILINE

	// IP constructor.spec3 --- INSERT
};

JobWzskSrcSysinfo::~JobWzskSrcSysinfo() {
	// IP destructor.spec --- INSERT

	// IP destructor.cust --- INSERT

	xchg->removeJobByJref(jref);
};

// IP cust --- IBEGIN
void JobWzskSrcSysinfo::getLoad() {
	ifstream infile;
	
	const size_t buflen = 256;
	char buf[buflen];

	vector<string> ss;
	string s;

	vector<float>* vec;
	int* unk_last;
	int* idle_last;

	int core;

	int user, nice, kernel, idle;
	float p, q;

	infile.open(stg.pathStat.c_str(), ifstream::in);

	while (true) {
		s = StrMod::readLine(infile, buf, buflen);

		if (s.find("cpu") != 0) break;
		s = s.substr(3);
		
		if (s.length() == 0) break;
		
		if (s[0] == ' ') {
			vec = &shrdat.loadAll;
			unk_last = &shrdat.unkAll;
			idle_last = &shrdat.idleAll;

		} else {
			core = atoi(s.c_str());
			if ((core < 0) || (core > 3)) break;

			if ((core + 1) > shrdat.NCore) shrdat.NCore = core + 1;

			switch (core) {
				case 0:
					vec = &shrdat.loadCore0;
					unk_last = &shrdat.unkCore0;
					idle_last = &shrdat.idleCore0;
					break;
				case 1:
					vec = &shrdat.loadCore1;
					unk_last = &shrdat.unkCore1;
					idle_last = &shrdat.idleCore1;
					break;
				case 2:
					vec = &shrdat.loadCore2;
					unk_last = &shrdat.unkCore2;
					idle_last = &shrdat.idleCore2;
					break;
				case 3:
					vec = &shrdat.loadCore3;
					unk_last = &shrdat.unkCore3;
					idle_last = &shrdat.idleCore3;
					break;
			};

			s = s.substr(1);
		};
		
		s = StrMod::spcex(s);

		StrMod::stringToVector(s, ss, ' ');
		if (ss.size() < 4) break;
		
		user = atoi(ss[0].c_str());
		nice = atoi(ss[1].c_str());
		kernel = atoi(ss[2].c_str());
		idle = atoi(ss[3].c_str());

		p = (float) (user + nice + kernel - *unk_last);
		q = (float) (user + nice + kernel + idle - *unk_last - *idle_last);

		*unk_last = user + nice + kernel;
		*idle_last = idle;

		for (unsigned int i = vec->size() - 1; i > 0; i--) (*vec)[i] = (*vec)[i-1];
		(*vec)[0] = p/q;
	};

	infile.close();
};

void JobWzskSrcSysinfo::getTempThermal() {
	float f;
	
	f = getValFromFile(stg.pathThermal);

	for (unsigned int i = shrdat.temp.size() - 1; i > 0; i--) shrdat.temp[i] = shrdat.temp[i-1];
	shrdat.temp[0] = 1e-3 * f;
};

void JobWzskSrcSysinfo::getTempXadc() {
	float f;

	if (shrdat.tempScale == 0.0) {
		shrdat.tempOffset = getValFromFile(stg.pathrootXadc + "_offset");
		shrdat.tempScale = getValFromFile(stg.pathrootXadc + "_scale");
	};

	f = (getValFromFile(stg.pathrootXadc + "_raw") + shrdat.tempOffset) * shrdat.tempScale;

	for (unsigned int i = shrdat.temp.size() - 1; i > 0; i--) shrdat.temp[i] = shrdat.temp[i-1];
	shrdat.temp[0] = 1e-3 * f;
};

float JobWzskSrcSysinfo::getValFromFile(
			const string& path
		) {
	ifstream infile;
	
	const size_t buflen = 256;
	char buf[buflen];

	string s;

	infile.open(path.c_str(), ifstream::in);

	s = StrMod::readLine(infile, buf, buflen);

	infile.close();

	return atof(s.c_str());
};
// IP cust --- IEND

// IP spec --- INSERT

void JobWzskSrcSysinfo::handleRequest(
			DbsWzsk* dbswzsk
			, ReqWzsk* req
		) {
	if (req->ixVBasetype == ReqWzsk::VecVBasetype::CMD) {
		reqCmd = req;

		if (req->cmd == "cmdset") {
			cout << "\ttest" << endl;
		} else if (req->cmd == "test") {
			req->retain = handleTest(dbswzsk);

		} else {
			cout << "\tinvalid command!" << endl;
		};

		if (!req->retain) reqCmd = NULL;

	} else if (req->ixVBasetype == ReqWzsk::VecVBasetype::TIMER) {
		if ((req->sref == "mon") && (ixVSge == VecVSge::RUN)) handleTimerWithSrefMonInSgeRun(dbswzsk);
	};
};

bool JobWzskSrcSysinfo::handleTest(
			DbsWzsk* dbswzsk
		) {
	bool retval = false;
	// IP handleTest --- INSERT
	return retval;
};

void JobWzskSrcSysinfo::handleTimerWithSrefMonInSgeRun(
			DbsWzsk* dbswzsk
		) {
	wrefLast = xchg->addWakeup(jref, "mon", 1000000, true);
	changeStage(dbswzsk, ixVSge); // IP handleTimerWithSrefMonInSgeRun --- ILINE
};

void JobWzskSrcSysinfo::changeStage(
			DbsWzsk* dbswzsk
			, uint _ixVSge
		) {
	bool reenter = true;

	do {
		if (ixVSge != _ixVSge) {
			switch (ixVSge) {
				case VecVSge::IDLE: leaveSgeIdle(dbswzsk); break;
				case VecVSge::RUN: leaveSgeRun(dbswzsk); break;
			};

			setStage(dbswzsk, _ixVSge);
			reenter = false;
			// IP changeStage.refresh1 --- INSERT
		};

		switch (_ixVSge) {
			case VecVSge::IDLE: _ixVSge = enterSgeIdle(dbswzsk, reenter); break;
			case VecVSge::RUN: _ixVSge = enterSgeRun(dbswzsk, reenter); break;
		};

		// IP changeStage.refresh2 --- INSERT
	} while (ixVSge != _ixVSge);
};

string JobWzskSrcSysinfo::getSquawk(
			DbsWzsk* dbswzsk
		) {
	string retval;
	// IP getSquawk --- BEGIN
	if ( (ixVSge == VecVSge::IDLE) || (ixVSge == VecVSge::RUN) ) {
		if (ixWzskVLocale == VecWzskVLocale::ENUS) {
			if (ixVSge == VecVSge::IDLE) retval = "idle";
			else if (ixVSge == VecVSge::RUN) retval = "running";
		} else if (ixWzskVLocale == VecWzskVLocale::DECH) {
			if (ixVSge == VecVSge::IDLE) retval = "inaktiv";
			else if (ixVSge == VecVSge::RUN) retval = "aktiv";
		};

	} else {
		retval = VecVSge::getSref(ixVSge);
	};
	// IP getSquawk --- END
	return retval;
};

uint JobWzskSrcSysinfo::enterSgeIdle(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::IDLE;

	// IP enterSgeIdle --- INSERT

	return retval;
};

void JobWzskSrcSysinfo::leaveSgeIdle(
			DbsWzsk* dbswzsk
		) {
	// IP leaveSgeIdle --- INSERT
};

uint JobWzskSrcSysinfo::enterSgeRun(
			DbsWzsk* dbswzsk
			, const bool reenter
		) {
	uint retval = VecVSge::RUN;

	if (!reenter) wrefLast = xchg->addWakeup(jref, "mon", 1000000, true);

	// IP enterSgeRun --- IBEGIN
	shrdat.wlockAccess(jref, "enterSgeRun");

	// update load information
	getLoad();

	// update temperature information
	if (!xchg->stgwzskglobal.fpgaNotV4l2gpio) getTempThermal();
	else getTempXadc();

	shrdat.wunlockAccess(jref, "enterSgeRun");

	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "loadAllLoadCore0LoadCore1LoadCore2LoadCore3");
	xchg->triggerSrefCall(dbswzsk, VecWzskVCall::CALLWZSKSHRDATCHG, jref, "temp");
	// IP enterSgeRun --- IEND

	return retval;
};

void JobWzskSrcSysinfo::leaveSgeRun(
			DbsWzsk* dbswzsk
		) {
	invalidateWakeups();
	// IP leaveSgeRun --- INSERT
};

bool JobWzskSrcSysinfo::handleClaim(
			DbsWzsk* dbswzsk
			, map<ubigint,Sbecore::Claim*>& claims
			, const ubigint jrefNewest
		) {
	bool mod = false;

	// IP handleClaim --- INSERT

	return mod;
};







