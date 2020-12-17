#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_ubuntu
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 15 Dec 2020
# IP header --- ABOVE

nohup ./Wzskcmbd -nocp &
disown
