#!/bin/bash
declare -A passwd
passwd["3.sh"]="20030212"
passwd["4.sh"]="02122003"

declare -A dir
dir["3.sh"]="dir3"
dir["4.sh"]="dir4"
num=3
read -p "你要运行哪个shell脚本(3.sh/4.sh):" shellname
echo "要运行的脚本是$shellname"
while (($num>0))
do
	if read -s -t 10 -p "你有10秒时间输入权限密码（还有$num次机会):" password
    	then
	    echo ""
	    echo "输入完成，正在验证"
	    if [[ $password == ${passwd["$shellname"]} ]]
	    then
		    cd ${dir["$shellname"]} 
		    sudo chmod +777 $shellname
		    ./$shellname
		    cd ..
		    exit
	    else
		    ((num--))
		    echo "密码错误，请重新输入"
		    continue
	    fi
    	else
	    echo "输入超时，程序自动退出"
	    exit
        fi
done
echo "三次机会已用完，程序自动退出...."
