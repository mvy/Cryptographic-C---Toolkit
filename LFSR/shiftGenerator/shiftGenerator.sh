#!/bin/bash

#Gathering taps
for i in `seq 1 $#`
do
    list="$list $1"
    shift
done

#Sorting
sorted=`echo $list | tr " " "\n" | sort -g`

#Processing

cat shiftHead.tpl
for i in $sorted
do
    echo "        (workValue & TAP$i) ^"
done
cat shiftTail.tpl
