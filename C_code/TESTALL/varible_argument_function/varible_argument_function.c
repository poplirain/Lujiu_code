#include <stdio.h>
#include <errno.h>
#include <string.h>
#include<stdarg.h>
static int group;
void function(int num,...){
    group++;
    va_list valist;
    va_start(valist,num);
    printf("第%d组数字为：\n",group);
    for(int i=1;i<=num;i++){
        printf("第%d个为：%d\n",i,va_arg(valist,int));
    }
    va_end(valist);
 }
int main ()
{
        function(1,1);
        function(2,2,3);
        function(3,4,5,6);
   return 0;
}