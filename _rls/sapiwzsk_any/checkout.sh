#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Swift API package, release sapiwzsk_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Mar 2022
# IP header --- ABOVE

if [ -z ${SWIFTROOT+x} ]; then
	echo "SWIFTROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

mkdir $SWIFTROOT/apiwzsk
mkdir $SWIFTROOT/apiwzsk/Sources
mkdir $SWIFTROOT/apiwzsk/Sources/apiwzsk

cp ../../sapiwzsk/*.java $SWIFTROOT/apiwzsk/src/apiwzsk/
