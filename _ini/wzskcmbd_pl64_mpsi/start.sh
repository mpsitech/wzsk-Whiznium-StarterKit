#!/bin/bash
# file start.sh
# start script for Wzsk combined daemon, release wzskcmbd_pl64_mpsi
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 23 Nov 2025
# IP header --- ABOVE

nohup ./Wzskcmbd -nocp &
disown
