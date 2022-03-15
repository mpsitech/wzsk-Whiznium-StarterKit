#!/bin/bash
# file checkin.sh
# checkin script for Wzsk Vue.js UI, release vueappwzsk_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 6 Mar 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set REPROOT=${WHIZDEVROOT}/rep

cp AppWzsk.vue $REPROOT/wzsk/vueappwzsk/
cp main.js $REPROOT/wzsk/vueappwzsk/

cp -r assets $REPROOT/wzsk/vueappwzsk/

cp -r components/* $REPROOT/wzsk/vueappwzsk/

cp -r scripts $REPROOT/wzsk/vueappwzsk/
