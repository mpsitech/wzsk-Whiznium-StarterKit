#!/bin/bash
# file make.sh
# make script for Wzsk combined daemon, release wzskcmbd_arty(linux (ubt_x86_64) cross-compilation)
# author Catherine Johnson
# date created: 23 Jul 2020
# modified: 23 Jul 2020

make Wzskcmbd.h.gch
if [ $? -ne 0 ]; then
	exit
fi

if [ "$1" = "all" ]; then
	subs=("IexWzsk" "VecWzsk" "CrdWzskNav" "CrdWzskUsg" "CrdWzskUsr" "CrdWzskPrs" "CrdWzskScf" "CrdWzskLlv" "CrdWzskLiv" "CrdWzskOgr" "CrdWzskObj" "CrdWzskSes" "CrdWzskSht" "CrdWzskFil")
else
	subs=("$@")
fi

for var in "${subs[@]}"
do
	cd "$var"
	make -j${NCORE}
	if [ $? -ne 0 ]; then
		exit
	fi
	make install
	cd ..
done

make -j${NCORE}
if [ $? -ne 0 ]; then
	exit
fi

make install

rm Wzskcmbd.h.gch

