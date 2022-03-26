# [C++] cctype头文件的使用

**cctype**是c/c++标准库中提供的用于操作字符的[头文件](https://so.csdn.net/so/search?q=头文件&spm=1001.2101.3001.7020)。在`cctype`中，声明了一系列对于单个字符进行分类和转换的函数，cctype中的函数可以分为两大类：字符分类函数和字符转换函数，使用时通过`#include`[预处理](https://so.csdn.net/so/search?q=预处理&spm=1001.2101.3001.7020)指令将引入该文件即可：

```c++
#include <cctype>
//或
#include <ctype.h>//老式风格
```

下面对**cctype**头文件中定义的函数进行下总结。

### 1.字符分类函数

![image-20220316114029151](C:\Users\小楷\AppData\Roaming\Typora\typora-user-images\image-20220316114029151.png)

### 2.字符转换函数

| 函数    | 描述                 |
| ------- | -------------------- |
| tolower | 将字母转换为小写返回 |
| toupper | 将字母转换为大写返回 |



示例如下：

```c++
#include <iostream>
#include <ctype.h>

int main()
{
        using namespace std;
        char ch,upper_ch;
        cout << "Enter a character:";
     
        while(cin.get(ch) && ch != '@')
        {   
                if(ch == '\n')//get()不清空回车，故遇到回车时返回此次循环
                        continue;

                if(isalnum(ch))
                {
                        if(isalpha(ch))
                        {   
                            cout << "you enter alpha char: " << ch << endl;
                        } else if(isdigit(ch))
                        {   
                                cout << "you enter digit char: " << ch << endl;
                        }
                } else if(isblank(ch))
                {   
                        cout << "you enter blank char:" << endl;
                } else if(iscntrl(ch))
                {
                        cout << "you enter contrl char:" << endl;
                } else if(ispunct(ch))
                {
                        cout << "you enter punct char:" << ch << endl; 
                } else if(isxdigit(ch))
                {
                        cout << "you enter hex digit char:" << ch << endl;
                } else 
                {
                        cout << "the character is " << ch << endl;
                }
             
                cout << "Enter a character:";
        }
        return 0;
}

```



### 参考文档

http://www.cplusplus.com/reference/cctype/

------------------------------------------------

