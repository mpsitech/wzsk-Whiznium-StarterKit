/**
	* \file WzskcmbdJobprc.h
	* job processor for Wzsk combined daemon (declarations)
	* \author Catherine Johnson
	* \date created: 18 Oct 2020
	* \date modified: 18 Oct 2020
	*/

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



