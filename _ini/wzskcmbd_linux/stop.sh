#!/bin/bash
# file stop.sh
# stop script for Wzsk combined daemon, release wzskcmbd_linux
# author Catherine Johnson
# date created: 18 Oct 2020
# modified: 18 Oct 2020

pid=$(pgrep Wzskcmbd)
kill -15 $pid

