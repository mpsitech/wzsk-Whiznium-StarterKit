/**
	* \file Wzskcmbd_exe.h
	* Wzsk combined daemon main (declarations)
	* \author Catherine Johnson
	* \date created: 16 Sep 2020
	* \date modified: 16 Sep 2020
	*/

#ifndef WZSKCMBD_EXE_H
#define WZSKCMBD_EXE_H

#include <string>
#include <vector>

#include <signal.h>

#include "WzskcmbdAppsrv.h"
#include "WzskcmbdJobprc.h"
#include "WzskcmbdOpprc.h"
#include "WzskcmbdDdspub.h"
#include "WzskcmbdUasrv.h"

/**
	* Wzskcmbd
	*/
class Wzskcmbd {

public:
	Wzskcmbd(const std::string& exedir, const bool clearAll, const bool startMon);
	~Wzskcmbd();

public:
	std::string exedir;

	DbsWzsk dbswzsk;

	XchgWzskcmbd* xchg;
	
	RootWzsk* root;

	MHD_Daemon* appsrv;

	std::vector<pthread_t> jobprcs;

	std::vector<pthread_t> opprcs;

	pthread_t ddspub;

	pthread_t uasrv;

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif

