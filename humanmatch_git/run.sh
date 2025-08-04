#!/bin/bash
echo "首先执行make操作，程序开始编译"
make

echo "程序编译成功,执行./humanmatch，运行程序"
./humanmatch
echo "程序运行中..........................."
echo "最后程序结束后,执行清理擦作"
make clean
