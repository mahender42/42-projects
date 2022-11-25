#! /bin/bash

if [ $# -ge 1 ]
then
	for i in $*
do
	mkdir ex$i
done
else
	echo "No arguments supplied"
fi
