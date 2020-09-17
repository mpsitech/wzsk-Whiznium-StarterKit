#!/bin/bash
# file checkout.sh
# checkout script for Wzsk web-based UI, release webappwzsk_linux
# author Catherine Johnson
# date created: 16 Sep 2020
# modified: 16 Sep 2020

export set WEBROOT=${WHIZROOT}/web

mkdir $WEBROOT/appwzsk

cp checkin.sh $WEBROOT/appwzsk/

cp -r ../../webappwzsk/* $WEBROOT/appwzsk/

