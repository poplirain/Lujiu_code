#!/bin/bash
read -p "please give me a file(test.sh/test.txt):" File

if  [[ "$File" == "test.sh" ]]
then
	echo "该程序行数为："
	awk 'END{print NR}' test.sh
	Head=$(awk 'NR==1' test.sh)	
	echo "HEAD:$Head"
	echo " "
	Other=$(awk 'NR>1' test.sh)
	echo "OTHER:$Other"
	echo ""
	echo "for循环的书写方式："
	awk  '/for/{print $0}' test.sh
	echo "该文件的执行结果为"
	chmod +777 test.sh
	./test.sh

else
	        echo "该程序行数为：" 
	awk 'END{print NR}' test.txt
         Head=$(awk 'NR==1' test.txt) 
 	 echo "HEAD:$Head"
	 echo " "
         Other=$(awk 'NR!=1' test.txt)
         echo "OTHER:$Other"
	 echo ""
	 echo "含有as的行有："
	 awk  '/as/{print $1,$3}' test.txt
fi
