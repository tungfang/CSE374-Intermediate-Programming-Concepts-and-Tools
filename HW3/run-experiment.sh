#!/bin/bash
#Charles Tung Fang, CSE 374 HW3 #3, 4/23 2019

if [ $# -lt 2 ]; then
    echo "Less than 2 arguments passed." >&2
    exit 1
fi

if [ ! -e "$2" ]; then
    echo "Input file $2 does not exit"
    exit 1
fi

RANK=1
OUTPUT="$1"
INPUT="$(< $2)"

for URL in $INPUT;do
    echo "Performing byte-size measurement on "$URL
    SIZE="$(./perform-measurement.sh $URL)"
    if [ "$SIZE" -gt 0 ]; then
        echo "...successful"
        echo "$RANK $URL $SIZE" >> "$OUTPUT"
    else
        echo "...failure"
    fi
    ((RANK++))
done

exit 0
