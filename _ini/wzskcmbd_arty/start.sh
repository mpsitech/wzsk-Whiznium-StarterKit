#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_arty
# author Catherine Johnson
# date created: 16 Sep 2020
# modified: 16 Sep 2020

nohup ./Wzskcmbd -nocp &
disown

