#!/bin/bash
# file checkin.sh
# checkin script for Wzsk web-based UI, release webappwzsk_yocto
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 28 Feb 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp -r * $REPROOT/wzsk/webappwzsk/

rm $REPROOT/wzsk/webappwzsk/checkin.sh
