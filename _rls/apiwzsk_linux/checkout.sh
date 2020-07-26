#!/bin/bash
# file checkout.sh
# checkout script for Wzsk API library, release apiwzsk_linux
# author Catherine Johnson
# date created: 23 Jul 2020
# modified: 23 Jul 2020

export set SRCROOT=${WHIZROOT}/src

mkdir $SRCROOT/apiwzsk

cp makeall.sh $SRCROOT/apiwzsk/

cp Makefile $SRCROOT/apiwzsk/

cp ../../apiwzsk/*.h $SRCROOT/apiwzsk/
cp ../../apiwzsk/*.cpp $SRCROOT/apiwzsk/

