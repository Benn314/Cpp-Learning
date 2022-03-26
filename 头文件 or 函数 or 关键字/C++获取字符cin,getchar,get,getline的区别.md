# [C++获取字符cin,getchar,get,getline的区别](https://www.cnblogs.com/shrimp-can/p/5241544.html)

**原创作品，转载请注明来源：http://www.cnblogs.com/shrimp-can/p/5241544.html**

**1.cin>>**

**1）**最常见的是获取输入的一个字符或数字，如

int a,b;

cin>>a>>b；

注意：cin>>会自动过滤掉不可见字符（如空格 回车 tab等）。若不想过滤掉空白字符，可以用noskipws流进行控制。

如下程序，没有过滤掉不可见字符，输入的空格字符存入了input[1]中，也可输出。

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304103000002-71553994.png)

**2）**获取输入的字符串，可以用数组或string类型。如

char a[20];

cin>>a;

cout<<a<<endl;

或者string类型：

string s;

cin>>s;

cout<<s<<endl;

注意：遇到空格、回车等会结束获取输入的字符串，后面的字符串会过滤掉（存放在输入流中）。如果后面还需要输入字符串，则会从前面存放的字符串开始获取。

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304103444659-1355660106.png)

遇空格、回车等结束。

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304103832612-431605488.png)

po存放在了string中。

 

**2.cin.get()**

**1）**cin.get(字符变量名)，用来接收字符，只获取一个字符，可以接收空格，遇回车结束

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304110453362-2134312510.png)

**2）**cin.get(数组名，接收字符数目)，用来接收字符串，可以接收空格，遇回车结束。

注意：数组的最后一个字符会是‘\0’，设接收字符数目为n，如果输入的字符串大于等于n，则实际接收到的输入是字符串的前面n-1个字符，包括空格（不包括回车，遇到回车就结束了），会自动在后面增加一个‘\0’。

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304111006065-238831180.png)

**3）**cin.get()，没有参数，主要用于舍弃输入流中不需要的字符，或者舍弃回车，即舍弃输入流中的一个字符。

没有用cin.get()，则后面的s会从输入流中继续读入

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304111800565-294028853.png)

有cin.get()，则h后面的s被省略了。

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304112118096-272303141.png)

 

**3.cin.getline()**

实际是cin.getline(接收字符串到m，接收个数n，结束字符)。接收一个字符串，可以接收空格等，最后一个字符为‘\0’。结束符可以通过设置第三个参数自己设置，默认是回车。m不能为string类型。

注意：实际接收到的要比n少一个，因为最后一个字符为'\0'。

![img](https://images2015.cnblogs.com/blog/699064/201603/699064-20160304113359252-388473868.png)

 

**4.getline()**

用于string类的。使用需包含头文件#include<string>。getline(cin,string s)，接收一个字符串，可以接收空格、回车等

与cin.getline()的区别：1.cin.getline()接收输入字符串的是数组，getline（）是string类型。

​                  2.cin.getline()可以接收空格，但不能接收回车；getline()可以接收空格和回车

​                  3.cin.getline()会在数组结尾是'\0'，getline()不会

 

**5.gets()**

gets(m)用于string类的，需包含#include<string>。可以接收空格，遇回车结束。可用于多维数组。

 

**6.getchar()**

 m=getchar(),需包含#include<string>

---

