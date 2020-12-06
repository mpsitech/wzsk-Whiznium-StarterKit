#!/bin/bash
# file checkout.sh
# checkout script for Wzsk API library, release apiwzsk_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set BUILDROOT=${WHIZSDKROOT}/build

mkdir $BUILDROOT/apiwzsk

cp makeall.sh $BUILDROOT/apiwzsk/

cp Makefile $BUILDROOT/apiwzsk/

cp ../../apiwzsk/*.h $BUILDROOT/apiwzsk/
cp ../../apiwzsk/*.cpp $BUILDROOT/apiwzsk/
