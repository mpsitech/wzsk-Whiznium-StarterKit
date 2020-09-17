#!/bin/bash
# file stop.sh
# stop script for Wzsk combined daemon, release wzskcmbd_linux
# author Catherine Johnson
# date created: 16 Sep 2020
# modified: 16 Sep 2020

pid=$(pgrep Wzskcmbd)
kill -15 $pid

