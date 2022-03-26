# C isdigit()

isdigit() 函数检查字符是否为数字字符 (0-9)。

## isdigit() 函数原型

```
int isdigit(int arg);
```

函数 isdigit() 采用整数形式的单个参数并返回 type 的值`int`。

即使 isdigit() 将整数作为参数，字符也会传递给函数。在内部，字符被转换为其 ASCII 值以进行检查。

它在<ctype.h>头文件中定义。

------

## C isdigit() 返回值

| 返回值             | 评论                 |
| :----------------- | :------------------- |
| 非零整数 ( x > 0 ) | 参数是一个数字字符。 |
| 零 (0)             | 参数不是数字字符。   |

------

## 示例：C isdigit() 函数

```
#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    c='5';
    printf("Result when numeric character is passed: %d", isdigit(c));

    c='+';
    printf("\nResult when non-numeric character is passed: %d", isdigit(c));

    return 0;
}
```



**输出**

```
传递数字字符时的结果：1 
传递非数字字符时的结果：0
```

------

## 示例：C程序检查用户输入的字符是否为数字字符

```
#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;

    printf("Enter a character: ");
    scanf("%c",&c);

    if (isdigit(c) == 0)
         printf("%c is not a digit.",c);
    else
         printf("%c is a digit.",c);
    return 0;
}
```

**输出**

```
输入一个字符：8 
8 是一个数字。
```

