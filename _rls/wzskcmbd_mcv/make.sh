#!/bin/bash
# file make.sh
# make script for Wzsk combined daemon, release wzskcmbd_mcv (ubuntu cross-compilation)
# copyright: (C) 2016-2020 MPSI Technologies GmbH
# author: Alexander Wirthmueller (auto-generation)
# date created: 2 Nov 2021
# IP header --- ABOVE

if [ -z ${WHIZROOT+x} ]; then
	echo "WHIZROOT is not defined. It looks as if you didn't run a Whiznium initialization script beforehand."
	exit 1
fi

make Wzskcmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWzsk" "VecWzsk" "CrdWzskUsg" "CrdWzskUsr" "CrdWzskPrs" "CrdWzskScf" "CrdWzskNav" "CrdWzskLlv" "CrdWzskLiv" "CrdWzskOgr" "CrdWzskObj" "CrdWzskSes" "CrdWzskSht" "CrdWzskFil")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j4
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j4
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wzskcmbd.h.gch
