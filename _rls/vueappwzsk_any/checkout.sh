#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Vue.js UI, release vueappwzsk_any
# copyright: (C) 2022 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
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

mkdir $WEBROOT/vueappwzsk/src/assets

cp ../../vueappwzsk/assets/* $WEBROOT/vueappwzsk/src/assets/
cp ../../vueappwzsk/assets/favicon.ico $WEBROOT/vueappwzsk/public/

mkdir $WEBROOT/vueappwzsk/src/components

cp ../../vueappwzsk/SessWzsk.vue $WEBROOT/vueappwzsk/src/components/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskStart

cp ../../vueappwzsk/CrdWzskStart/CrdWzskStart.vue $WEBROOT/vueappwzsk/src/components/CrdWzskStart/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskNav

cp ../../vueappwzsk/CrdWzskNav/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskNav/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskUsg

cp ../../vueappwzsk/CrdWzskUsg/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskUsg/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskUsr

cp ../../vueappwzsk/CrdWzskUsr/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskUsr/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskPrs

cp ../../vueappwzsk/CrdWzskPrs/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskPrs/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskPrf

cp ../../vueappwzsk/CrdWzskPrf/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskPrf/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskLlv

cp ../../vueappwzsk/CrdWzskLlv/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskLlv/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskVtr

cp ../../vueappwzsk/CrdWzskVtr/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskVtr/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskHwc

cp ../../vueappwzsk/CrdWzskHwc/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskHwc/

mkdir $WEBROOT/vueappwzsk/src/components/CrdWzskFil

cp ../../vueappwzsk/CrdWzskFil/*.vue $WEBROOT/vueappwzsk/src/components/CrdWzskFil/

mkdir $WEBROOT/vueappwzsk/src/scripts

cp ../../vueappwzsk/scripts/*.js $WEBROOT/vueappwzsk/src/scripts/
