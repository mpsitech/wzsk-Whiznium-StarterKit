#!/bin/bash
# file checkout.sh
# checkout script for Wzsk web-based UI, release webappwzsk_apalis
# author Catherine Johnson
# date created: 18 Oct 2020
# modified: 18 Oct 2020

export set WEBROOT=${SYSROOT}${WHIZROOT}/web

mkdir $WEBROOT/appwzsk

cp checkin.sh $WEBROOT/appwzsk/

cp -r ../../webappwzsk/* $WEBROOT/appwzsk/

