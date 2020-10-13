#!/bin/bash
# file stop.sh
# stop script for Wzsk combined daemon, release wzskcmbd_mac
# author Catherine Johnson
# date created: 13 Oct 2020
# modified: 13 Oct 2020

pid=$(pgrep Wzskcmbd)
kill -15 $pid

