//
// Created by 小楷 on 2022/3/28.
//

#ifndef C_LISTACK_H
#define C_LISTACK_H

#endif //C_LISTACK_H

#pragma once
#include <iostream>
#include<malloc.h>
using namespace std;

typedef char ElemType;

//栈的链式存储表示
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LiStack;

//链栈基本运算的实现
void InitStack(LiStack *&s)
{
    s = (LiStack *)malloc(sizeof(LiStack));
    s->next = NULL;
}

bool StackEmpty(LiStack *s)
{
    return(s->next == NULL);
}

void DestroyStack(LiStack *&s)
{
    LiStack *pre = s, *p = s->next;
    while (p != NULL)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(p);
}

void Push(LiStack *&s, ElemType e)
{
    LiStack *p;
    p = (LiStack *)malloc(sizeof(LiStack));//新建结点p
    p->data = e;	//存放元素e
    p->next = s->next;	//将p结点插入作为首结点
    s->next = p;
}

bool Pop(LiStack *&s, ElemType &e)
{
    LiStack *p;
    if (s->next == NULL)
        return false;
    p = s->next;//（怎么理解）
    e = p->data;
    s->next = p->next;
    free(p);
    return true;
}

bool GetTop(LiStack *s, ElemType &e)
{
    if (s->next == NULL)
        return false;
    e = s->next->data;
    return true;
}

int StackLength(LiStack *s)
{
    LiStack *p = s->next;
    int num = 0;
    while (p != NULL)
    {
        num++;
        p = p->next;
    }
    return num;
}

void DispStack(LiStack *s)
{
    cout << "从栈顶到栈底依次为：";
    LiStack *p = s->next;
    while (p != NULL)
    {
        cout << p->data;
        p = p->next;
    }
}