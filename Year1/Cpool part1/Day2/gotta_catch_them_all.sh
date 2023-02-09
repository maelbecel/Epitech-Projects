#!/bin/bash
name=$*
if [ -z $name ]
then
    wc -l
else
    cut -d":" -f"5"| cut -d' ' -f"2" | grep -i ^$name | wc -l
 fi
