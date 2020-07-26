#!/bin/bash
# file makeall.sh
# make script for Wzsk database access library, release dbswzsk_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 23 Jul 2020
# modified: 23 Jul 2020

make DbsWzsk.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

