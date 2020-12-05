#!/bin/bash
# file stop.sh
# stop script for Wzsk combined daemon, release wzskcmbd_tdx
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Emily Johnson (auto-generation)
# date created: 5 Dec 2020
# IP header --- ABOVE

pid=$(pgrep Wzskcmbd)
kill -15 $pid

