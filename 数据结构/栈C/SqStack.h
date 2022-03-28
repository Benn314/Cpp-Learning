//
// Created by 小楷 on 2022/3/28.
//

#ifndef 栈C_SQSTACK_H
#define 栈C_SQSTACK_H

#endif //栈C_SQSTACK_H

#pragma once
#include <iostream>
using namespace std;
#define MaxSize 50

typedef int ElemType;
//栈的顺序存储表示
typedef struct
{
    ElemType data[MaxSize];
    int top;	//栈顶指针
}SqStack;

//顺序栈基本运算的实现
void InitStack(SqStack *&s)
{
    s = (SqStack *)malloc(sizeof(SqStack));
    s->top = -1;
}
bool StackEmpty(SqStack *s)
{
    return(s->top == -1);
}
void DestoryStack(SqStack *&s)
{
    free(s);
}
bool Push(SqStack *&s, ElemType e)
{
    if (s->top == MaxSize - 1)	//栈满的情况，即栈上溢出
        return false;
    s->top++;
    s->data[s->top] = e;	//元素e放在栈顶指针处
    return true;
}
bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)	//栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];//取栈顶指针元素的元素
    s->top--;	//栈顶指针减1
    /*此时栈顶元素还在，等下次压栈直接把值赋值给栈顶
    元素，它就没了*/
    return true;
}
bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)	//栈为空的情况，即栈下溢出
        return false;
    e = s->data[s->top];//取栈顶指针元素的元素
    return true;
}
int StackLength(SqStack *s)
{
    return s->top + 1;
    //因为栈顶是MaxSize-1
}
void DispStack(SqStack *s)
{
    cout << "从栈底到栈顶依次为：";
    for (int i = 0; i < StackLength(s); i++)
    {
        cout << s->data[i] << " ";
    }
    cout << endl;
}

