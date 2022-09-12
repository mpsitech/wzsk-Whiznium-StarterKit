#!/bin/bash
# file stop.sh
# stop script for Wzsk combined daemon, release wzskcmbd_pl64_mpsi
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 12 Sep 2022
# IP header --- ABOVE

pid=$(pgrep Wzskcmbd)
kill -15 $pid
