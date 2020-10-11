#!/bin/bash
# file checkout.sh
# checkout script for Wzsk Java API library, release &rlssref;
# author &author;
# date created: 6 Oct 2020
# modified: 6 Oct 2020

export set JAVAROOT=

mkdir $JAVAROOT/apiwzsk
mkdir $JAVAROOT/apiwzsk/src
mkdir $JAVAROOT/apiwzsk/src/apiwzsk
mkdir $JAVAROOT/apiwzsk/bin
mkdir $JAVAROOT/apiwzsk/bin/apiwzsk

cp ../../japiwzsk/*.java $JAVAROOT/apiwzsk/src/apiwzsk/

