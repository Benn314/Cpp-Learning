

# [C++ std::copy()用法及代码示例](https://vimsky.com/examples/usage/stl-std-copy-function-with-example-02.html)

## C++ STL std::copy() 函数

copy() 函数是算法头的库函数，用于复制容器的元素，将容器的元素从给定的范围从给定的开始位置复制到另一个容器。

**注意：**使用 copy() 函数 - 包括`<algorithm>`标题或者您可以简单使用`<bits/stdc++.h>`头文件。

**std::copy() 函数的语法**

```
    std::copy(iterator source_first, iterator source_end, iterator target_start);
```

**参数：**

- `iterator source_first, iterator source_end`- 是源容器的迭代器位置。
- `iterator target_start`- 是目标容器的开始迭代器。

**返回值：** `iterator`- 它是指向已复制元素的目标范围末尾的迭代器。

**例：**

```
    Input:
    //declaring & initializing an int array
    int arr[] = { 10, 20, 30, 40, 50 };
    
    //vector declaration
    vector<int> v1(5);
    
    //copying array elements to the vector
    copy(arr, arr + 5, v1.begin());

    Output:
    //if we print the value
    arr:10 20 30 40 50
    v1:10 20 30 40 50
```

## C++ STL程序演示std::copy()函数的使用

在这个例子中，我们将数组元素复制到向量中。

```
//C++ STL program to demonstrate use of
//std::copy() function
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //declaring & initializing an int array
    int arr[] = { 10, 20, 30, 40, 50 };
    //vector declaration
    vector<int> v1(5);

    //copying array elements to the vector
    copy(arr, arr + 5, v1.begin());

    //printing array
    cout << "arr:";
    for (int x:arr)
        cout << x << " ";
    cout << endl;

    //printing vector
    cout << "v1:";
    for (int x:v1)
        cout << x << " ";
    cout << endl;

    return 0;
}
```

**输出**

```
arr:10 20 30 40 50
v1:10 20 30 40 50
```



参考：C++ std::copy()