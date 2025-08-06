#include<stdlib.h>
#include<stdio.h>

static int S_totalnumber=0;
typedef struct
{
    char ID[20];
    int age;
    char name[20];
    double score;
}Student;
Student student[100000];

typedef enum{
  Create=1,Print,Sort,Search,Delete,OUT
}option;
char * StringDirectionT(option options)
{
        switch(options)
        {
                case Create : return "Create";
                case Print  : return "Print";
                case Sort : return "Sort";
                case Search  : return "Search";
                case Delete  : return "Delete";
                case OUT  : return "OUT";
                default    :return "Wrong"; 
        }
}

void create_student(int snumber)
{
 
  for(int i=S_totalnumber;i<(S_totalnumber+snumber);i++)
  {
    printf("第%d个学生ID是:",i+1);
    scanf("%s",&student[i].ID);
    printf("第%d个学生姓名是:",i+1);
    scanf("%s",&student[i].name);
    printf("第%d个学生年龄是:",i+1);
    scanf("%d",&student[i].age);
    int cin_nums=0;
  do
  {
    if(cin_nums>0)
    {
      printf("你输入的成绩不正确(正确范围0~100),请重新输入。");
    }
    printf("第%d个学生分数是:",i+1);
    scanf("%lf",&student[i].score);
    cin_nums++;
  }while((student[i].score<0)|(student[i].score>100));
  }
  printf("创建完成，以下是你本次创建的学生信息:\n");
  print_sinformation(student,S_totalnumber,S_totalnumber+snumber);
  S_totalnumber+=snumber;
  
}

void print_sinformation(Student *student,int start,int snumber){
    printf("学生信息为:\n");
    for(int i=start;i<snumber;i++)
    {
    printf("%d | ID：%s ,",i+1,student[i].ID);
    printf(" 姓名：%s ,",student[i].name);
    printf(" 年龄: %d ,",student[i].age);
    printf(" 分数：%lf\n",student[i].score);
    }
}


void score_low_sort(Student *s,int n){
   int i, j;
   Student key;
    
    // 首先找出最小值放在arr[0]作为哨兵
    int min=0;
    for (i = 1; i < n; i++) {
        if (s[i].score < s[min].score) {
            min = i;
        }
    }
        Student temp = s[0];
        s[0]= s[min];
        s[min]= temp;
    // 现在arr[0]是最小值，可以作为哨兵
    for (i = 2; i < n; i++) {
        key = s[i];
        j = i - 1;
        while (s[j].score > key.score) {  // 不需要检查j>=0因为arr[0]是最小的
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}

void age_low_sort(Student *s,int n){
   int i, j;
   Student key;
    
    // 首先找出最小值放在arr[0]作为哨兵
    int min=0;
    for (i = 1; i < n; i++) {
        if (s[i].age < s[min].age) {
            min = i;
        }
    }
        Student temp = s[0];
        s[0]= s[min];
        s[min]= temp;
    // 现在arr[0]是最小值，可以作为哨兵
    for (i = 2; i < n; i++) {
        key = s[i];
        j = i - 1;
        while (s[j].age > key.age) {  // 不需要检查j>=0因为arr[0]是最小的
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = key;
    }
}
