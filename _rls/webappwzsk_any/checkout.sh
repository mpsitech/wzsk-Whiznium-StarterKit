#!/bin/bash
# file checkout.sh
# checkout script for Wzsk web-based UI, release webappwzsk_any
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 6 Dec 2020
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/appwzsk

cp checkin.sh $WEBROOT/appwzsk/

cp -r ../../webappwzsk/* $WEBROOT/appwzsk/
