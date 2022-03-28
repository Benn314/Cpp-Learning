//
// Created by С�� on 2022/3/28.
//

#ifndef ջC_SQSTACK_H
#define ջC_SQSTACK_H

#endif //ջC_SQSTACK_H

#pragma once
#include <iostream>
using namespace std;
#define MaxSize 50

typedef int ElemType;
//ջ��˳��洢��ʾ
typedef struct
{
    ElemType data[MaxSize];
    int top;	//ջ��ָ��
}SqStack;

//˳��ջ���������ʵ��
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
    if (s->top == MaxSize - 1)	//ջ�����������ջ�����
        return false;
    s->top++;
    s->data[s->top] = e;	//Ԫ��e����ջ��ָ�봦
    return true;
}
bool Pop(SqStack *&s, ElemType &e)
{
    if (s->top == -1)	//ջΪ�յ��������ջ�����
        return false;
    e = s->data[s->top];//ȡջ��ָ��Ԫ�ص�Ԫ��
    s->top--;	//ջ��ָ���1
    /*��ʱջ��Ԫ�ػ��ڣ����´�ѹջֱ�Ӱ�ֵ��ֵ��ջ��
    Ԫ�أ�����û��*/
    return true;
}
bool GetTop(SqStack *s, ElemType &e)
{
    if (s->top == -1)	//ջΪ�յ��������ջ�����
        return false;
    e = s->data[s->top];//ȡջ��ָ��Ԫ�ص�Ԫ��
    return true;
}
int StackLength(SqStack *s)
{
    return s->top + 1;
    //��Ϊջ����MaxSize-1
}
void DispStack(SqStack *s)
{
    cout << "��ջ�׵�ջ������Ϊ��";
    for (int i = 0; i < StackLength(s); i++)
    {
        cout << s->data[i] << " ";
    }
    cout << endl;
}

