# 小场景
## 斐波那契数列(阶乘)
F（n）{
    ①F(1)=1
    ②F(2)=1
    ③F(n-1)+F(n-2);
}
## 判断奇偶
%2\==0
%2\==1

## 判断素数（素数特征）
1）除以2~n-1不为0（基本）
2）除以2~平方根不为0



## 判断闰年，判断该年第几天(利用键值)

    int isLeapYear(int year) {
        // 闰年的判断规则：能被4整除且（不能被100整除或能被400整除）
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 1;
        }
            return 0;
        }
 
    int main() {
        int year, month, day;
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
         totalDays = 0;
    
        printf("请输入年份、月份和日期（格式：年 月 日）：");
        scanf("%d %d %d", &year, &month, &day);
    
        // 判断是否是闰年
        if (isLeapYear(year)) {
            daysInMonth[1] = 29; // 闰年2月有29天
        }
 
        // 计算从1月1日到输入日期的天数
        for (int i = 0; i < month - 1; i++) {
            totalDays += daysInMonth[i];
        }
        totalDays += day; // 加上当前月份的天数
 
        ("%d年%d月%d日是该年的第%d天\n", year, month, day, totalDays);

## 




# 模拟题
## 1
牛牛从键盘输入一个长度为 n 的数组，问你能否用这个数组组成一个链表，并顺序输出链表每个节点的值。
输入描述：
第一行输入一个正整数 n ，表示数组的长度
输出描述：
制作一个链表然后输出这个链表的值
示例1
输入：
4
5 4 2 1
复制
输出：
5 4 2 1
复制
说明：
请实现链表后再遍历输出结果！

#include <stdio.h>
#include <stdlib.h>

// write your code here......
struct List{
    int val;
 struct List *next;
};
struct List*creatList(){
    struct List*head=(struct List*)malloc(sizeof(struct List));    
    head->val=0;
    head->next=NULL;
    return head;
}
void addNode(struct List *head, int val){
    struct List*next=(struct List*)malloc(sizeof(struct List));
    next->val=val;
    next->next=head->next;
    head->next=next;
}
void print(struct List*l){
    l=l->next;
    while(l!=NULL){
        printf("%d ",l->val);
        l=l->next;
    }
}
int main() {

    int n;
    scanf("%d",&n);

    int* arr=(int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    struct List*l;
    l=creatList();
    for(int i=n-1;i>=0;i--){
        addNode(l,arr[i]);
    }
    print(l);
    // write your code here......
    

    free(arr);
    return 0;
}



## 2