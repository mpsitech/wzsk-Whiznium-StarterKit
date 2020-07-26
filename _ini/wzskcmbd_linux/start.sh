#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_linux
# author Catherine Johnson
# date created: 23 Jul 2020
# modified: 23 Jul 2020

nohup ./Wzskcmbd -nocp &
disown

