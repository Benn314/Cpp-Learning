//
// Created by С�� on 2022/3/28.
//

#ifndef C_SYMMETRY_H
#define C_SYMMETRY_H

#endif //C_SYMMETRY_H

//#pragma once
/*
����symmetryʵ�ֶԳƴ����
�ǶԳƴ�����true
���򷵻�false
*/
#include "LiStack.h"
bool symmetry(ElemType str[])
{
    int i;
    ElemType e;
    //SqStack *st;	˳��ջ
    LiStack *st;

    InitStack(st);	//��ʼ��ջ
    for (i = 0; str[i] != '\0'; i++)
    {
        Push(st, str[i]);	//��������Ԫ�ؽ�ջ
    }
    cout << "�����Ĵ��ǣ�";
    DispStack(st);

    //NULL=='\0'
    for (i = 0; str[i] != '\0'; i++)
    {
        Pop(st, e);	//��ջԪ��e
        if (str[i] != e)	//��e�뵱ǰ��Ԫ�ز�ͬ���ǶԳƴ�
        {
            DestroyStack(st);	//���ٴ�
            return false;
        }
    }
    DestroyStack(st);	//����ջ
    return true;
}

//ʵ����abccbb
//��ջ��bbccba	ջ��--ջ��
//��ջ��abccbb	���--�ȳ�
