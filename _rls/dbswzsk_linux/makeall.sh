#!/bin/bash
# file makeall.sh
# make script for Wzsk database access library, release dbswzsk_linux
# author Catherine Johnson
# date created: 13 Oct 2020
# modified: 13 Oct 2020

make DbsWzsk.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

