#!/bin/bash
# file makeall.sh
# make script for Wzsk database access library, release dbswzsk_tdx (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 11 Mar 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make DbsWzsk.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install
