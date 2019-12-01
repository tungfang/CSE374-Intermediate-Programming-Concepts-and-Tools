#!/bin/bash
#Charles Tung Fang, CSE 374 HW3 #2, 4/21 2019

if [ $# -lt 2  ]; then
    echo "Less than 2 arguments passed." >&2
    exit 1
fi

if [ ! -e "$2"  ]; then
    echo "Input file $2 does not exit"
    exit
fi

grep -io 'http://[a-z0-9./-]*' $2 > /tmp/temp_parse_file
grep -vwE 'altavista|100bestwebsites|en.wikipedia.org' /tmp/temp_parse_file > $1
rm /tmp/temp_parse_file

exit 0
