#!/bin/bash
echo "请输入数组大小："
read num
i=0
echo "数组具体内容："
while (($i<$num))
do
read nums
array[$i]=$nums
((i++))
done
index=1
echo "本次你输入了${#array[*]}个数字，具体如下"
for var in ${array[*]}
do
 echo "第$index个数字是$var"
 ((index++))
done	
