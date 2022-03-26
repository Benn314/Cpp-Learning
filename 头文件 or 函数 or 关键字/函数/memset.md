memset（）是char型初始化函数。

 

**一. 头文件**：<string.h> 或 <memory.h>

 

**二. 函数原型**：void *memset(void *s, int ch, size_t n);

 

函数功能：将s所指向的某一块内存中的前n个字节的内容全部设置为ch指定的ASCII值， 第一个值为指定的内存地址，块的大小由第三个参数指定，这个函数通常为新申请的内存做初始化工作， 其返回值为指向s的指针，它是对较大的结构体或数组进行清零操作的一种最快方法。

 

**三. 使用**：

 

memset(结构体/数组名 , 用于替换的ASCII码对应字符 , 前n个字符 );

memset(结构体/数组名 , "用于替换的字符“ , 前n个字符 );

函数解释：将s中的前n个字节用ch替换并且返回s

函数作用：在一段内存块中填充某一个给定的值，常用于较大的对结构体和数组的清零操作。



例子1：

```c++
#include<iostream>
//#include"string.h"
using namespace std;
int main()
{
    char str[10];
    str[9] = 'w';
    memset(str,97,9);
    for(int i=0;i<10;i++){
        cout<<str[i]<<" ";
    }
    return 0;
} 
```

输出：a a a a a a a a a w

说明：使用memset似乎不需要使用额外的头文件。



例子2：

```c++
#include<iostream>
//#include"string.h"
using namespace std;
int main()
{
    char str[10];
    str[9] = 'w';
    memset(str,97,sizeof(char)*10);
    for(int i=0;i<10;i++){
        cout<<str[i]<<" ";
    }
    return 0;
}
```

输出：a a a a a a a a a a



例子3：

```c++
#include<iostream>
using namespace std;
int main()
{
    char str[10];
    memset(str,65,sizeof(str)-3);
    for(int i=0;i<10;i++){
        cout<<str[i]<<" ";
    } 
    return 0;
}
```

输出：A A A A A A A 

![img](https://images2018.cnblogs.com/blog/1359491/201808/1359491-20180826230003496-1415993915.png)



**四. 几个注意事项**：[转自此文](https://blog.csdn.net/my_business/article/details/40537653) （讲解详细，可多看几遍）

1.memset是以**字节**为单位，初始化内存块。

2.当结构体类型中包含指针时，在使用memset初始化时需要小心。

3.当结构体或类的本身或其基类中存在虚函数时，也需要谨慎使用memset。（笔试中碰到过类似的题，貌似是找错）