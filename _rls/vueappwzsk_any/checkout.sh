#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Vue.js UI, release vueappwzsk_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Mar 2022
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/vueappwzsk/src

cp checkin.sh $WEBROOT/vueappwzsk/src

cp ../../vueappwzsk/AppWzsk.vue $WEBROOT/vueappwzsk/src/
cp ../../vueappwzsk/main.js $WEBROOT/vueappwzsk/src/

cp -r ../../vueappwzsk/assets $WEBROOT/vueappwzsk/src/

mkdir $WEBROOT/vueappwzsk/src/components

cp ../../vueappwzsk/SessWzsk.vue $WEBROOT/vueappwzsk/src/components/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskStart

cp ../../vueappwzsk/CrdWzskStart/CrdWzskStart.vue $WEBROOT/vueappwzsk/src/components/CrdWzskStart/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskUsg

cp ../../vueappwzsk/CrdWzskUsg/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskUsg/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskUsr

cp ../../vueappwzsk/CrdWzskUsr/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskUsr/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskPrs

cp ../../vueappwzsk/CrdWzskPrs/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskPrs/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskScf

cp ../../vueappwzsk/CrdWzskScf/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskScf/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskLlv

cp ../../vueappwzsk/CrdWzskLlv/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskLlv/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskLiv

cp ../../vueappwzsk/CrdWzskLiv/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskLiv/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskOgr

cp ../../vueappwzsk/CrdWzskOgr/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskOgr/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskObj

cp ../../vueappwzsk/CrdWzskObj/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskObj/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskSes

cp ../../vueappwzsk/CrdWzskSes/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskSes/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskSht

cp ../../vueappwzsk/CrdWzskSht/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskSht/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskFil

cp ../../vueappwzsk/CrdWzskFil/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskFil/

mkdir $WEBROOT/vueappwzsk/src/scripts

cp ../../vueappwzsk/scripts/*.js $WEBROOT/vueappwzsk/src/scripts/
