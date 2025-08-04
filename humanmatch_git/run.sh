#!/bin/bash
echo "首先执行make操作，程序开始编译........."
mark=''
for ((ratio=0;${ratio}<=100;ratio+=5))
do
        sleep 0.9
        printf "progress:[%-40s]%d%%\r" "${mark}" "${ratio}"
        mark="##${mark}"
done
make
echo "程序编译成功,执行./humanmatch，运行程序........."
mark=''
for ((ratio=0;${ratio}<=100;ratio+=5))
do
        sleep 0.2
        printf "progress:[%-40s]%d%%\r" "${mark}" "${ratio}"
        mark="##${mark}"
done
echo "程序运行中..........................."
./humanmatch
echo "程序结束,执行清理擦作"
mark=''
for ((ratio=0;${ratio}<=100;ratio+=5))
do
        sleep 0.2
        printf "progress:[%-40s]%d%%\r" "${mark}" "${ratio}"
        mark="##${mark}"
done
make clean
