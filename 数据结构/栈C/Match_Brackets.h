//
// Created by 小楷 on 2022/3/28.
//

#ifndef ?C_MATCH_BRACKETS_H
#define ?C_MATCH_BRACKETS_H

#endif //?C_MATCH_BRACKETS_H

#pragma once
#include "LiStack.h"
/*
Match_Brackets函数检测输入的符号串是否对称匹配
如果是，返回1
否则返回0
该函数仅限于（）[] {}
*/

typedef int Status;
#define TRUE 1
#define FALSE 0

Status Match_Brackets()
{
    //SqStack *S,*T;	顺序栈，T用来保存所有输入的字符串
    LiStack *S, *T;		//链栈

    InitStack(S);
    InitStack(T);

    char inputch, e;	//输入通道
    int ItemNum = 1;	//项目编号
    while (ItemNum % 2 != 0) {
        cout << "请输入字符个数：";
        cin >> ItemNum;
    }
    cout << "字符个数合法！" << endl;
    cout << "请输入字符串：";
    for (int i = 0; i <= ItemNum; i++)//因为要处理回车，长度加1
    {
        cin >> inputch;
        if (inputch != 0x0a)	//0x0a是换行符
        {
            Push(T, inputch);
        }

        switch (inputch)
        {
            case '(':
                Push(S, inputch);
                break;
            case '[':
                Push(S, inputch);
                break;
            case '{':
                Push(S, inputch);
                break;
            case ')':
                Pop(S, e);
                if (e != '(')
                {
                    cout << "')'括号不匹配";
                    return FALSE;
                }
                break;
            case ']':
                Pop(S, e);
                if (e != '[')
                {
                    cout << "']'括号不匹配";
                    return FALSE;
                }
                break;
            case '}':
                Pop(S, e);
                if (e != '{')
                {
                    cout << "'}'括号不匹配";
                    return FALSE;
                }
                break;
        }
    }
    if (!StackEmpty(S))
    {
        cout << endl << endl << "括号数量不匹配！";
        return FALSE;
    }
    else
    {
        cout << endl << endl << "成功匹配！";
        DispStack(T);
        return TRUE;
    }
}

