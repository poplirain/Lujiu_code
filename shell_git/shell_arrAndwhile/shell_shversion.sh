#!/bin/bash
echo "这是一个shell练习脚本"
planet="pl wf vd gd ws bd"
index=1
for p in $planet;
do
	echo "这是第$index个星球:$p"
	index=$((index+1))
done

