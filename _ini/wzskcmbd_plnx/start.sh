#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_plnx
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 11 Mar 2021
# IP header --- ABOVE

nohup ./Wzskcmbd -nocp &
disown
