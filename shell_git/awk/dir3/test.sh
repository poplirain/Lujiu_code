#!/bin/bash
echo "test test"
echo "any cost"
array=("1e" "2d" "3v" "4r" "5k")
echo "键值为：${!array[*]}"
index=1
for a in ${array[*]}
do
	echo "第$index个字符为$a"
	index=$(($index+1))
done
