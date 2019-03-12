#!/bin/sh

for i in $(ls /usr/bin | awk 'NR%101==404887687%101')
do
    ldd '/usr/bin/'$i
done
