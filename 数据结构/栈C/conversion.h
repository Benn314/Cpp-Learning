//
// Created by С�� on 2022/3/28.
//

#ifndef ջC_CONVERSION_H
#define ջC_CONVERSION_H

#endif //ջC_CONVERSION_H

#pragma once
#include "SqStack.h"
/*
conversion����ʵ�ֽ�ʮ������ת���ɵ�ֵ�Ķ�������
������̣�
1.�Ӽ��̻�ȡ��Ҫ����ת����ʮ������N
2.ֻҪN>0������ִ�����²���
	��N%2�Ľ����ջ��������ջ��Push����
	N=N/2
3.ջ��Ϊ�գ���������ջ��Pop��������ջ��Ԫ�ش�ӡ����
  �õ������м�Ϊת����Ķ�������
*/

void conversion()
{
    SqStack *S;	//˳��ջ
//	LiStack *S;	//��ջ
    int N, e;
    InitStack(S);
    cout << "������ʮ������N: ";
    cin >> N;
    while (N) {
        Push(S, N % 2);
        N = N / 2;
    }
    DispStack(S);
    cout << endl << "��ջ��ջ��Ϊ��" << StackLength(S) << endl;
    cout << "��Ӧ�Ķ������ǣ�";
    while (!StackEmpty(S)) {
        Pop(S, e);
        cout << e;
    }
    cout << endl << "��ջ��ջ��Ϊ��" << StackLength(S);
}