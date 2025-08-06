#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define INIT_SIZE 10

typedef int Element;
typedef struct Stack {
Element* base;
int top;
int stackSize;

} Stack, *PStack;

// 初始化栈
void Init_Stack(PStack ps,int num);
// 入栈
bool Push(PStack ps, Element val);
// 出栈
bool Pop(PStack ps, Element* rtval);
// 获取栈顶元素
bool Top(PStack ps, Element* rtval);
// 获取有效元素个数
int GetSize(PStack ps);
// 判空
bool IsEmpty(PStack ps);
// 判满
bool IsFull(PStack ps);
// 扩容函数
void Inc(PStack ps);
// 清空
void Clear(PStack ps);
// 销毁
void Destroy(PStack ps);
// 打印
void Show(PStack ps);