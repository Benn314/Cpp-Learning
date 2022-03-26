# [C++——sort和stable_sort的若干区别](https://www.cnblogs.com/oddcat/p/10313192.html)

***版权声明：本文系作者原创，转载请注明出处。***

 

C++中sort和stable_sort的区别：

1. sort是快速排序实现，因此是不稳定的；stable_sort是归并排序实现，因此是稳定的；
2. 对于相等的元素sort可能改变顺序，stable_sort保证排序后相等的元素次序不变；
3. 如果提供了比较函数，sort不要求比较函数的参数被限定为const，而stable_sort则要求参数被限定为const，否则编译不能通过。

