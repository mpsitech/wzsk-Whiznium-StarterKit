/**
	* \file WzskcmbdOpprc.h
	* operation processor for Wzsk combined daemon (declarations)
	* \author Catherine Johnson
	* \date created: 6 Oct 2020
	* \date modified: 6 Oct 2020
	*/

#ifndef WZSKCMBDOPPRC_H
#define WZSKCMBDOPPRC_H

/**
	* WzskcmbdOpprc
	*/
namespace WzskcmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif

