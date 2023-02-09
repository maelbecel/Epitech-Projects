#!/bin/bash

parameter=$*
if [ -z $parameter ]; then
	parameter="Update unnamed"
fi
git add --all
git commit -m  "$parameter"
git push
