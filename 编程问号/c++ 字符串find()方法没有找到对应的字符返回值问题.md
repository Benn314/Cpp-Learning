## c++ 字符串find()方法没有找到对应的字符返回值问题

```c++
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    ////find函数返回类型 size_type
    string s("1a2b3c4d5e6f7jkg8h9i1a2b3c4d5e6f7g8ha9i");
    string flag;
    string::size_type position;
    //find 函数 返回jk 在s 中的下标位置
    position = s.find("000");
    if (position != s.npos)  //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，
    {
        printf("position is : %d\n" ,position);
    }
    else
    {
        printf("Not found the flag\n");
        printf("position is : %d\n" ,position);
    }
}
```



### Output

```c++
Not found the flag
position is : -1

--------------------------------
Process exited after 0.04042 seconds with return value 0
请按任意键继续. . .
```

---

