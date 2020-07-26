#!/bin/bash
# file checkout.sh
# checkout script for Wzsk database access library, release dbswzsk_mac
# author Catherine Johnson
# date created: 23 Jul 2020
# modified: 23 Jul 2020

export set SRCROOT=${WHIZROOT}/src

mkdir $SRCROOT/dbswzsk

cp makeall.sh $SRCROOT/dbswzsk/

cp Makefile $SRCROOT/dbswzsk/

cp ../../dbswzsk/DbsWzsk.h $SRCROOT/dbswzsk/
cp ../../dbswzsk/DbsWzsk_vecs.cpp $SRCROOT/dbswzsk/
cp ../../dbswzsk/DbsWzsk.cpp $SRCROOT/dbswzsk/

cp ../../dbswzsk/Wzsk*.h $SRCROOT/dbswzsk/
cp ../../dbswzsk/Wzsk*.cpp $SRCROOT/dbswzsk/
