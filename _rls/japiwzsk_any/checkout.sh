#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Java API library, release japiwzsk_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 11 Mar 2021
# IP header --- ABOVE

if [ -z ${JAVAROOT+x} ]; then
	echo "JAVAROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

mkdir $JAVAROOT/apiwzsk
mkdir $JAVAROOT/apiwzsk/src
mkdir $JAVAROOT/apiwzsk/src/apiwzsk
mkdir $JAVAROOT/apiwzsk/bin
mkdir $JAVAROOT/apiwzsk/bin/apiwzsk

cp ../../japiwzsk/*.java $JAVAROOT/apiwzsk/src/apiwzsk/
