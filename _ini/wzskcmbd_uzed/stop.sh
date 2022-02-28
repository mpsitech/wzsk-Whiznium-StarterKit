#!/bin/bash
# file stop.sh
# stop script for Wzsk combined daemon, release wzskcmbd_uzed
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 28 Feb 2022
# IP header --- ABOVE

pid=$(pgrep Wzskcmbd)
kill -15 $pid
