## c++中stoi函数

### 作用：

将 n 进制的字符串转化为十进制

### 头文件：

```
#include <string>
```

### 用法：

```
1 stoi（字符串，起始位置，n进制），将 n 进制的字符串转化为十进制
2 
3  示例：
4 stoi(str, 0, 2); //将字符串 str 从 0 位置开始到末尾的 2 进制转换为十进制
```

但好像不是标准函数，慎用吧。

### 案例：

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
 1 #include <iostream>
 2 #include <string>
 3 
 4 using namespace std;
 5 
 6 int main()
 7 {
 8     string str = "1010";
 9     int a = stoi(str, 0, 2);
10     cout << a << endl;
11         return 0;
12 }        
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

### 输出结果：

```
10
```



```c++
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
	string str = "000101";	
	int temp = stoi(str);//直接stoi(str)是直接把字符串译成整型，取第一位为有效位开始，例如"000101"->101,"234"->234
	cout << temp;
	return 0;
}
```

