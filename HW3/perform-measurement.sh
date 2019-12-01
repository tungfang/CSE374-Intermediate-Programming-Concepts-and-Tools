#!/bin/bash
#Charles Tung Fang, CSE 374 HW3 #1, 4/21 2019

if [ $# -lt 1 ]; then
    echo "please provide arguments." >&2
    exit 1
fi

wget -t 1 -T 5 -q -O temp_file $1
wc -c temp_file | grep -E -o '[0-9]* '
rm temp_file

exit 0
