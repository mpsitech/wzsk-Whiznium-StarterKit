#!/bin/bash
# file makeall.sh
# make script for Wzsk API library, release apiwzsk_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 6 Oct 2020
# modified: 6 Oct 2020

make ApiWzsk.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

