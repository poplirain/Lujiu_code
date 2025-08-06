#include "stack.h"


// 初始化栈
void Init_Stack(PStack ps,int num){
    assert(ps);
    ps->base=(Element *)malloc(num*sizeof(Element));
    if(ps->base==NULL)
    {
        exit(1);
    }    
    ps->stackSize=num;
    ps->top=0;
}
// 入栈
bool Push(PStack ps, Element val){
    assert(ps);
    if(IsFull(ps))
    {
       Inc(ps);
    }
    ps->base[ps->top]=val;
    ps->top++;
    return true;
}
// 出栈
bool Pop(PStack ps, Element* rtval){
    assert(ps);
    if(IsEmpty(ps))
    {
        return false;
    }
    *rtval=ps->base[--ps->top];
    return true;
}
// 获取栈顶元素
bool Top(PStack ps, Element* rtval){
    assert(ps);
    if(IsEmpty(ps))
    {
        return false;
    }
    *rtval=ps->base[ps->top-1];
    return true;
}
// 获取有效元素个数
int GetSize(PStack ps){
    return ps->top-1;
}
// 判空
bool IsEmpty(PStack ps){
    return ps->top==0;
}
// 判满
bool IsFull(PStack ps){
    return ps->top==ps->stackSize;
}
// 扩容函数
void Inc(PStack ps){
        int newstackSize=ps->stackSize==0?10:ps->stackSize*2;
        PStack *temp=(PStack *)realloc(ps->base,sizeof(PStack)*newstackSize);
        if(temp==NULL)
        {
            printf("realloc failed\n");
            exit(-1);
        }
}
// 清空
void Clear(PStack ps){
    assert(ps);
    ps->top=0;
}
// 销毁
void Destroy(PStack ps){
    free(ps->base);
    ps->base=NULL;
    ps->top=ps->stackSize=0;
}
// 打印
void Show(PStack ps){
    assert(ps);
    for(int i=0;i<ps->top;i++){
        printf("%d | %d\n",i+1,ps->base[i]);
    }
}

int main()
{
    PStack p;
    printf("存入几个数字：");
    int num;
    scanf("%d",&num);
    getchar();
    Init_Stack(p,num);
    Element number;
    printf("输入序列：\n");
    for(int i=0;i<num;i++)
    {
        scanf("%d",&number);
        getchar();
        Push(p,number);
    }
    Show(p);
    return 0;
}