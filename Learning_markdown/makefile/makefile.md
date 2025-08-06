# This is a makefile Markdown
makefile文件的结构
## 语法
目标：依赖  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;target：dependencies
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;命令 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;commands
编译关系可以获取到很多依赖信息


## 符号

 类似于python的变量赋值，不过这里的作用更像是宏定义
  = 赋予最后被敲定的值  
 ：= 赋予当前呗赋予的值  相当于加上const
 ?= 没有赋值才赋值

  @command 不显示但执行

$@ 目标文件
$^ 全部依赖文件
$< 第一个依赖文件
## 函数
  $(function <argument> <argument> ....)
### wildcard
src =   $(wildcard *.c  test/*.c) 获取当前目录和test的所有c文件  
### patsubst
$(patsubst %.c,%.o,$(src)),将src中的所有.c文件全部替换为.o文件


## .PHONY:
声明标签为伪指令，不需要依赖，仅需make去执行
eg

    .PHONY: clean

    clean:
       rm -f *.o out  # 删除.o文件和可执行文件


gcc -MM 可以查看依赖关系 


define 命令名         定义了一个命令
@echo
@echo
@echo
endef

还能再makefile中进行条件判断
还可以自定义函数
函数名=？？？？
$（call 函数名，参数）

$（shell <shell command>）


makefile对于头文件的一代是为了当头文件中一些数值进行改变时，不用再clean后重新make 而是直接make会自己根据头文件中的改变进行更新，从而更加便利

