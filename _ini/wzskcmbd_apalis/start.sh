#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_apalis
# author Catherine Johnson
# date created: 13 Oct 2020
# modified: 13 Oct 2020

nohup ./Wzskcmbd -nocp &
disown

