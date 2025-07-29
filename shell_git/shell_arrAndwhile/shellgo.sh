#!/bin/bash
set -euo pipefail  # 启用严格模式

type_name="/home/louis/Desktop/test/SHELL/shell_arrAndwhile"

# 读取匹配的文件到数组
mapfile -t arr < <(find "$type_name" -maxdepth 1 -type f -name "*.sh" ! -name "shellgo.sh")

readonly length=${#arr[@]}
if (( length == 0 )); then
    echo "没有找到匹配 *shell_*version.sh 的脚本文件" >&2
    exit 1
fi

echo "共找到 $length 个匹配的脚本文件"

for ((shnum=1; shnum<=length; shnum++)); do
    echo "=== 正在处理第 $shnum/$length 个脚本 ==="
    echo "脚本路径: ${arr[shnum-1]}"
    echo "脚本内容:"
    echo "----------------------------------------"
    cat "${arr[shnum-1]}"
    echo "----------------------------------------"
    echo "执行结果:"
    
    # 执行脚本并捕获可能的错误
    if ! source "${arr[shnum-1]}"; then
        echo "警告: 第 $shnum 个脚本执行失败" >&2
    fi
    
    echo ""
done

echo "所有脚本处理完成"
