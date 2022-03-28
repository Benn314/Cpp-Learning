//
// Created by 小楷 on 2022/3/28.
//

#ifndef 栈C_CONVERSION_H
#define 栈C_CONVERSION_H

#endif //栈C_CONVERSION_H

#pragma once
#include "SqStack.h"
/*
conversion函数实现将十进制数转换成等值的二进制数
具体过程：
1.从键盘获取需要进制转换的十进制数N
2.只要N>0，持续执行以下操作
	将N%2的结果入栈，即调用栈的Push操作
	N=N/2
3.栈不为空，持续调用栈的Pop操作，将栈顶元素打印出来
  得到的序列即为转换后的二进制数
*/

void conversion()
{
    SqStack *S;	//顺序栈
//	LiStack *S;	//链栈
    int N, e;
    InitStack(S);
    cout << "请输入十进制数N: ";
    cin >> N;
    while (N) {
        Push(S, N % 2);
        N = N / 2;
    }
    DispStack(S);
    cout << endl << "进栈后栈长为：" << StackLength(S) << endl;
    cout << "对应的二进制是：";
    while (!StackEmpty(S)) {
        Pop(S, e);
        cout << e;
    }
    cout << endl << "出栈后栈长为：" << StackLength(S);
}