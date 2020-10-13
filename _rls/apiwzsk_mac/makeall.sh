#!/bin/bash
# file makeall.sh
# make script for Wzsk API library, release apiwzsk_mac
# author Catherine Johnson
# date created: 13 Oct 2020
# modified: 13 Oct 2020

make ApiWzsk.h.gch
if [ $? -ne 0 ]; then
	exit
fi

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

