#!/bin/bash
city=$*
if [ -z $city ]
then
	wc -l
else
    cut -d";" -f "3"  | grep -i $city | wc -l
fi
