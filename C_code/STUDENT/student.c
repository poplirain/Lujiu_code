#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "student.h"
#define  TABLE  "请选择你要进行的操作:\n1、创建学生信息\n2、打印学生信息\n3、排序\n4、筛选\n5、删除学生信息\n6、结束任务\n" 

// 配置参数
const char *LastStr = "[####################] 100%";
const char ProgressIcon = '#';
const int Step = 5;
const int IconMaxNum = 20;
const int PrintInterval = 10000;

int main()
{
  Student *stu;
  stu=student;
  int snumber;
  option op;
  _Bool is_first=0;
  while(1)
  {
    if(is_first)
    {
      printf("接下来你希望进行什么操作?\n");
    }
    else
    {
    printf("欢迎您使用本程序，请选择你要进行的操作（初次使用仅可选择创建）\n");
    }
option_Rechoose:
    printf(TABLE);
    scanf("%u",&op);
    if(is_first==0&&op!=1&&op!=6)
    {
      op=1;
      is_first=1;
      printf("首次只能使用创建功能，已为你自动跳转。\n");
      goto Firstuse;
    }
    is_first=1;
    switch(op)
    {
      case Create:
      {
        printf("你选择了%s操作\n",StringDirectionT(op));
Firstuse:
        printf("你要输入的学生信息数量： ");
        scanf("%d",&snumber);
        create_student(snumber); 
        break;
      }

      case Print:
      {
        printf("你选择了%s操作\n",StringDirectionT(op));
        print_sinformation(stu,0,S_totalnumber);
        printf("打印完成\n");
        break;
      }

      case Sort:
      {
        int select;
        printf("你选择了%s操作\n",StringDirectionT(op));
Sort_Rechoose:
        printf("有两种排序，年龄排序与分数排序，你选择(1/2)?   :  \n");
        scanf("%d",&select);
        switch(select)
        {
          case 1:
            {
              age_low_sort(stu,S_totalnumber);
              printf("按年龄排序后结果为\n");
              print_sinformation(stu,0,S_totalnumber);
              break;
            }
          case 2:
            {
              score_low_sort(stu,S_totalnumber);
              printf("按成绩排序后结果为\n");
              print_sinformation(stu,0,S_totalnumber);
              break;
            }
          default:
          {
            printf("没有这个选项重新选择\n");
            goto Sort_Rechoose;
          }
        }
        printf("排序完成\n");
        break;
      }

      case Search:
      {
        printf("你选择了%s操作\n",StringDirectionT(op));
Search_Rechoose:
        printf("请输入你需要筛选的内容(1.姓名/2.年龄/3.分数)\n");
        int searchchoose;
        scanf("%d",&searchchoose);
        getchar();
        int member=0;
        switch(searchchoose)
        {
          case 1:
          {
            printf("需要筛选的姓名： ");
            char name[20];
            scanf("%s",&name);
            getchar();
            printf("姓名筛选完毕，以下是符合条件名单\n");
            for(int i=0;i<S_totalnumber;i++)
            {
              
              if(strcmp(stu[i].name,name)==0)
              {
                printf("%s,%s\n",stu[i].name,name);
                member++;
                print_sinformation(stu,i,i+1);
              }
            }
            if(member==0)
            {
              printf("未查找到目标\n");
            }
            break;
          }
          case 2:
          {
            printf("需要筛选的年龄： ");
            int age;
            scanf("%d",&age);
            getchar();
            printf("年龄筛选完毕，以下是符合条件名单\n");
            for(int i=0;i<S_totalnumber;i++)
            {
              if(stu[i].age==age)
              {
                member++;
                print_sinformation(stu,i,i+1);
              }
            }
            if(member==0)
            {
              printf("未查找到目标\n");
            }
            break;
          }
          case 3:
          {
            printf("需要筛选的成绩： ");
            double score;
            scanf("%lf",&score);
            getchar();
            printf("成绩筛选完毕，以下是符合条件名单\n");
            for(int i=0;i<S_totalnumber;i++)
            {
              if(stu[i].score==score)
              {
                member++;
                print_sinformation(stu,i,i+1);
              }
            }
            if(member==0)
            {
              printf("未查找到目标\n");
            }
            break;
          }
          default:
          {
            printf("没有这个选项重新选择\n");
            goto Search_Rechoose;
            break;
          }
        break;
        }
        break;
      }

      case Delete:
      {
        printf("你选择了%s操作\n",StringDirectionT(op));
        printf("请键入ID已删除该学生：");
        char id[20];
        scanf("%s",&id);
        getchar();
        int deletesign=0;
        for(int i=0;i<S_totalnumber;i++)
        {
          if(strcmp(stu[i].ID,id)==0)
          {
            deletesign=1;
          }
          if(deletesign==1){
            stu[i]=stu[i+1];
          }
        }
        S_totalnumber--;
        printf("删除完成\n");
        break;
      }

      case OUT:
      {
        printf("你选择了%s操作\n",StringDirectionT(op));
        goto OUT;
      }

      default:
      {
      printf("没有这个操作，重新选择\n");
      goto option_Rechoose;
      }
    }
    char continue_choose;
    printf("是否需要继续操作?(Y/N):");
    scanf("%c",&continue_choose);
    getchar();
    if((continue_choose=='N')||(continue_choose=='n'))
    {
      goto OUT;
    } 
  }

OUT:
printf("程序退出中");
for (int i = 0; i <= 100; ++i) {
// 打印进度条
printf("[");
int currentIndex = i / Step;
for (int j = 0; j < IconMaxNum; ++j) {
if (j < currentIndex) {
printf("%c", ProgressIcon);
} else {
printf(" ");
}
}
printf("] ");

// 打印数字进度
printf("%3d%%", i);
fflush(stdout);
usleep(PrintInterval);

// 回删字符，让数字和进度条原地变化
for (int j = 0; j < strlen(LastStr); ++j) {
printf("\b");
}
fflush(stdout);
}
printf("\n\n");
    return 0;
}

