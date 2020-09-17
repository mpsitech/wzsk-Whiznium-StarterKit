#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Java API library, release &rlssref;
# author &author;
# date created: 16 Sep 2020
# modified: 16 Sep 2020

export set JAVAROOT=${WHIZROOT}/srcjava

mkdir $JAVAROOT/apiwzsk
mkdir $JAVAROOT/apiwzsk/src
mkdir $JAVAROOT/apiwzsk/src/apiwzsk
mkdir $JAVAROOT/apiwzsk/bin
mkdir $JAVAROOT/apiwzsk/bin/apiwzsk

cp ../../japiwzsk/*.java $JAVAROOT/apiwzsk/src/apiwzsk/

