#!/bin/bash
# file checkin.sh
# checkin script for Wzsk web-based UI, release webappwzsk_mac
# author Catherine Johnson
# date created: 13 Oct 2020
# modified: 13 Oct 2020

export set REPROOT=${WHIZROOT}/srcrep

cp -r * $REPROOT/wzsk/webappwzsk/

rm $REPROOT/wzsk/webappwzsk/checkin.sh

