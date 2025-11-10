#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Vue.js UI, release vueappwzsk_yocto
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Oct 2025
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${SYSROOT}${WHIZROOT}/web

mkdir $WEBROOT/vueappwzsk/src

cp checkin.sh $WEBROOT/vueappwzsk/src

cp ../../vueappwzsk/AppWzsk.vue $WEBROOT/vueappwzsk/src/
cp ../../vueappwzsk/main.js $WEBROOT/vueappwzsk/src/

mkdir $WEBROOT/vueappwzsk/src/assets

cp ../../vueappwzsk/assets/* $WEBROOT/vueappwzsk/src/assets/
cp ../../vueappwzsk/assets/favicon.ico $WEBROOT/vueappwzsk/public/

mkdir $WEBROOT/vueappwzsk/src/components

cp ../../vueappwzsk/SessWzsk.vue $WEBROOT/vueappwzsk/src/components/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskStart

cp ../../vueappwzsk/CrdWzskStart/CrdWzskStart.vue $WEBROOT/vueappwzsk/src/components/CrdWzskStart/

# IP cp.cars --- INSERT

mkdir $WEBROOT/vueappwzsk/src/scripts

cp ../../vueappwzsk/scripts/*.js $WEBROOT/vueappwzsk/src/scripts/
