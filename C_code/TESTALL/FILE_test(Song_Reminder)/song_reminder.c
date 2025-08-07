#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
int main() {
    SetConsoleOutputCP(65001); // 设置控制台编码为 UTF-8
    FILE *fp;
    fp=fopen("../../filetest.txt","w+");//w+为读写，可以让写的东西覆盖原有文件内容
    if(fp==NULL){
        printf("文件打开失败\n");
        return 1;
    }
    char buffer[60];
    char b[]={"We are 伐木累！！！"};
    char a[][60]={"gogogo,出发咯",
        "黑咖啡品味有多浓","我只要汽水和轻松",
        "大热天做个白日梦","梦见我变成了彩虹",
        "我有想奔跑的冲动","有你在跌倒也从容",
        "无所畏惧的去追梦","汗水书写这份光荣",
        "电影中角色也会有不同","每一个小人物也拥有小的梦",
        "大屏幕映不出现实中的暗涌","我只想和你牵着手在雨中等彩虹",
        "你说我是你的超级英雄","偶尔也客串你的出气筒",
        "心甘情愿接受这份光荣~","做你身边的萤火虫oh~a~ei",
        "如果我是你的超级英雄","此刻为你高唱这首Love-song~~",
        "小小的默契让爱转动","做你最骄傲的英雄"};


    //fgetc/fputc
    int ch=78;
    fputc(ch,fp);  //fputc
    rewind(fp); // 确保指针在开头
    printf("fputc/fgetc方式：\n");
    printf("%c\n",fgetc(fp));
    printf("----------------------------\n");
    printf("\n");

    //fgets/fputs
    rewind(fp);
    fputs(b,fp);
    rewind(fp);
    printf("fgets/fputs方式:\n");
    fgets(buffer,60,fp);

    printf("%s\n",buffer);
    printf("----------------------------\n");
    printf("\n");
    if(feof(fp))
    {
        printf("基础输出结束，开始整活！！\n");//判断文件是否到结束
    }
    else{
        printf("前边有错误\n");
        return 1;
    }
    rewind(fp);//复位到文件开头

    printf("----------------------------\n");
    printf("\n");

    //fprintf/fscanf
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        fprintf(fp,"%s",a[i]);
        fputs("\n", fp); // 添加换行符
    }

    rewind(fp);//
    printf("fprintf/fscanf方式：\n   《超级英雄》\n    原唱:邓超\n");
    for(int i=0;i<len;i++){
    fscanf(fp,"%s",buffer);
    printf("%d : %s\n",i+1,buffer);
    memset(buffer,0,sizeof(buffer));
    Sleep(3000);
}
    long offset=ftell(fp);
    fclose(fp);

    printf("间奏中~~~~~~~~~~\n");
    Sleep(1000);
    printf("🎶");
    Sleep(1000);
    printf("🎶");
    Sleep(1000);
    printf("🎶");
    Sleep(1000);
    printf("🎶");
    Sleep(1000);
    printf("🎶");
    Sleep(1000);
    printf("🎶");
    Sleep(1000);
    printf("🎶\n");
    //第二段追加内容
    FILE *fp2;
    fp2=fopen("../../filetest.txt","r+");
    //这里用a+会追加，但是用fseek回到位置会出错，因为fseek会在a无效，大概可能是因为a+本身就有强制重定位（自动到尾部）
    if(fp2==NULL){
        printf("文件打开错误\n");
        return 1;
    }
    char c[][60]={"我有想奔跑的冲动","有你在跌倒也从容",
                  "无所畏惧的去追梦","汗水书写这份光荣",
                  "不管住城堡或胡同","也不管富有或贫穷",
                  "因为有爱不停转动","金山也不在我眼中",
                  "电影中角色也会有不同","每一个小人物也拥有小的梦",
                  "大屏幕映不出现实中的暗涌","我只想和你牵着手在雨中等彩虹",
                  "你说我是你的超级英雄!","偶尔也客串你的出气筒~",
                  "心甘情愿接受这份光荣","做你身边的萤火虫oh~a~ei",
                  "如果我是你的超级英雄!!!","此刻为你高唱这首Love-song~~",
                  "小小的默契让爱转动","做你最骄傲的英雄",
                  "我是你骄傲的英雄~~~"};
    int len2=sizeof(c)/sizeof(c[0]);//第二段内容长度
    char buffer2[len2][60];

    if (fseek(fp2, offset, SEEK_SET) != 0) //fseek使用，定位到上次文件位置，并且如果没成功则进入if
    {
    perror("fseek 失败");
    fclose(fp2);
    return 1;
    }

    for(int i=0;i<len2;i++){
    fwrite(c[i],1,60,fp2);//fwrite读入文件，每次60字符，一个字符1Byte,但是这种读入方式会让文件的格式变乱
    //fputs("\n",fp2);    //如果采用上边同样的读入回车fputs("\n",fp2);那么下面就会出现问题，下边会说到.
    }                     

    fflush(fp2);//写入后，fflush确保写入磁盘
  
    fseek(fp2,offset,SEEK_SET);  //写入完，文件来到了最末尾，重新定位到第一段结束，即第二段开始
    printf("第二段\n");
    for(int i=0;i<len2;i++)
    {
        fread(buffer2[i],1,60,fp2);/*如果上方使用回车，文本中的内容格式上确实会工整，但是在fread环节，
                                     fread不会对换行符进行识别，会当作内容，这也导致此处的获取很大可能变成空，
                                     或者也可以使用fgets来获取，不过那样的话一开始使用fgets和fputs会更好*/
    }

    for(int i=0;i<len2;i++)
    {
        Sleep(3000);
        printf("%d : %s\n",i+len+1,buffer2[i]);
    }
    fclose(fp2);
    return 0;
}
