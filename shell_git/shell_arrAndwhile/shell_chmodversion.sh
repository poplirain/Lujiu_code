#!/bin/bash
planet=("sd" "ff" "dsa" "sada" "fsaf" "sdad")
plength=${#planet[@]}
index=1
while((index <= plength))
do
	echo "这是第$index个星球：${planet[index-1]}"
	((index++))
done
