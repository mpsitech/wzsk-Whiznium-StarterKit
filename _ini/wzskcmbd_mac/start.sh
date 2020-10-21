#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_mac
# author Catherine Johnson
# date created: 18 Oct 2020
# modified: 18 Oct 2020

nohup ./Wzskcmbd -nocp &
disown

