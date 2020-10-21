#!/bin/bash
# file checkout.sh
# checkout script for Wzsk API library, release apiwzsk_apalis(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 18 Oct 2020
# modified: 18 Oct 2020

export set SRCROOT=${SYSROOT}${WHIZROOT}/src

mkdir $SRCROOT/apiwzsk

cp makeall.sh $SRCROOT/apiwzsk/

cp Makefile $SRCROOT/apiwzsk/

cp ../../apiwzsk/*.h $SRCROOT/apiwzsk/
cp ../../apiwzsk/*.cpp $SRCROOT/apiwzsk/

