//
// Created by С�� on 2022/3/28.
//

#ifndef ?C_MATCH_BRACKETS_H
#define ?C_MATCH_BRACKETS_H

#endif //?C_MATCH_BRACKETS_H

#pragma once
#include "LiStack.h"
/*
Match_Brackets�����������ķ��Ŵ��Ƿ�Գ�ƥ��
����ǣ�����1
���򷵻�0
�ú��������ڣ���[] {}
*/

typedef int Status;
#define TRUE 1
#define FALSE 0

Status Match_Brackets()
{
    //SqStack *S,*T;	˳��ջ��T������������������ַ���
    LiStack *S, *T;		//��ջ

    InitStack(S);
    InitStack(T);

    char inputch, e;	//����ͨ��
    int ItemNum = 1;	//��Ŀ���
    while (ItemNum % 2 != 0) {
        cout << "�������ַ�������";
        cin >> ItemNum;
    }
    cout << "�ַ������Ϸ���" << endl;
    cout << "�������ַ�����";
    for (int i = 0; i <= ItemNum; i++)//��ΪҪ����س������ȼ�1
    {
        cin >> inputch;
        if (inputch != 0x0a)	//0x0a�ǻ��з�
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
                    cout << "')'���Ų�ƥ��";
                    return FALSE;
                }
                break;
            case ']':
                Pop(S, e);
                if (e != '[')
                {
                    cout << "']'���Ų�ƥ��";
                    return FALSE;
                }
                break;
            case '}':
                Pop(S, e);
                if (e != '{')
                {
                    cout << "'}'���Ų�ƥ��";
                    return FALSE;
                }
                break;
        }
    }
    if (!StackEmpty(S))
    {
        cout << endl << endl << "����������ƥ�䣡";
        return FALSE;
    }
    else
    {
        cout << endl << endl << "�ɹ�ƥ�䣡";
        DispStack(T);
        return TRUE;
    }
}

