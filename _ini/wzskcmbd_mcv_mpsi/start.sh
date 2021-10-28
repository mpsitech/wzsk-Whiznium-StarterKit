#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_mcv_mpsi
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 25 Oct 2021
# IP header --- ABOVE

nohup ./Wzskcmbd -nocp &
disown