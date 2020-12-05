/**
	* \file Wzskcmbd_exe.h
	* Wzsk combined daemon main (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Emily Johnson (auto-generation)
	* \date created: 5 Dec 2020
  */
// IP header --- ABOVE

#ifndef WZSKCMBD_EXE_H
#define WZSKCMBD_EXE_H

#include <string>
#include <vector>

#include <signal.h>

#include "WzskcmbdAppsrv.h"
#include "WzskcmbdJobprc.h"
#include "WzskcmbdOpprc.h"
#if defined(SBECORE_DDS)
	#include "WzskcmbdDdspub.h"
#endif
#if defined(SBECORE_UA)
	#include "WzskcmbdUasrv.h"
#endif

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

#if defined(SBECORE_DDS)
	pthread_t ddspub;
#endif

#if defined(SBECORE_UA)
	pthread_t uasrv;
#endif

public:
	void loadPref();
	void storePref();

	void loadKeycert();
};

#endif

