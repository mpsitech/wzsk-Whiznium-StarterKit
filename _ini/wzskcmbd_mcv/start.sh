#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_mcv
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 14 Nov 2021
# IP header --- ABOVE

nohup ./Wzskcmbd -nocp &
disown
