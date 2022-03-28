//
// Created by 小楷 on 2022/3/28.
//

#ifndef C_SYMMETRY_H
#define C_SYMMETRY_H

#endif //C_SYMMETRY_H

//#pragma once
/*
函数symmetry实现对称串检测
是对称串返回true
否则返回false
*/
#include "LiStack.h"
bool symmetry(ElemType str[])
{
    int i;
    ElemType e;
    //SqStack *st;	顺序栈
    LiStack *st;

    InitStack(st);	//初始化栈
    for (i = 0; str[i] != '\0'; i++)
    {
        Push(st, str[i]);	//将串所有元素进栈
    }
    cout << "给定的串是：";
    DispStack(st);

    //NULL=='\0'
    for (i = 0; str[i] != '\0'; i++)
    {
        Pop(st, e);	//退栈元素e
        if (str[i] != e)	//若e与当前串元素不同则不是对称串
        {
            DestroyStack(st);	//销毁串
            return false;
        }
    }
    DestroyStack(st);	//销毁栈
    return true;
}

//实例：abccbb
//进栈：bbccba	栈顶--栈底
//出栈：abccbb	后出--先出
