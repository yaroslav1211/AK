#!/bin/bash

name=$(basename "$0")

[ $# -ne 2 ] && echo "Need 2 numeric args" && exit 1

if [ "$1" -gt "$2" ]; then
    echo "First > Second"
    alias
else
    echo "First <= Second"
    stat -c%s "$0"
fi
