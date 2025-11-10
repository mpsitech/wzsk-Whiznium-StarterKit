/**
	* \file WzskcmbdJobprc.h
	* job processor for Wzsk combined daemon (declarations)
	* \copyright (C) 2016-2020 MPSI Technologies GmbH
	* \author Alexander Wirthmueller (auto-generation)
	* \date created: 1 Jul 2025
  */
// IP header --- ABOVE

#ifndef WZSKCMBDJOBPRC_H
#define WZSKCMBDJOBPRC_H

/**
	* WzskcmbdJobprc
	*/
namespace WzskcmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgWzskcmbd* xchg, DbsWzsk* dbswzsk, ReqWzsk* req);
};

#endif
