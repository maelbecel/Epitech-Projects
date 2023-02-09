#!/bin/bash

getcompress() {

    ./antman/antman $1 $2 >  "temp_compress"
    ./giantman/giantman "temp_compress" $2 > $1_uncompress

    difference=$(diff $1_uncompress $1)
    sizecompress=$(stat -c%s temp_compress)
    sizeuncompress=$(stat -c%s "$1")

    if [[ "$sizeuncompress" == 0 ]]; then
        echo "⛔ Warning, $1 is an empty file ⛔"
        exit 84
    fi

    percent=$((sizecompress * 100 / sizeuncompress))

    rm temp_compress > /dev/null

    if [[ $sizecompress -eq 0 || $sizecompress -ge $sizeuncompress ]]; then
        echo "💢 Warning no compression 💢"
        echo "      Original file size : $sizeuncompress"
        echo "      Compress file size : $sizecompress"
    elif [ -z "$difference" ]; then
        echo "👍 Good compression  of $1 👍, compression is $percent%"
    else
        echo "👎 Bad compression or decompression of $1 👎"
        echo $difference
    fi
}
if [[ -z "$1" ]]; then
    echo "Need file or directory"
    exit 84
elif [[ -f "$1" ]]; then
    getcompress $1 $2
elif [[ -d "$1" ]]; then
    for x in $1/* ; do
        if [[ -f "$x" ]]; then
            getcompress $x
        fi
    done
fi
