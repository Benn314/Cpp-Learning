# [C++中查看数据类型的方法](https://www.cnblogs.com/klobohyz/archive/2012/04/25/2470010.html)

最简单当然是用typeid了、不过首先得加入头文件`typeinfo`

例如想知道某个数据的类型、则使用name方法

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
#include <typeinfo>
using namespace std;
int main(){
   int iobj; 
 
   cout << typeid( iobj ).name() << endl;  //  打印: int 
   cout << typeid( 8.16 ).name() << endl; // 打印: double      return 0;}
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

如果只是想比较两者的类型是否相同、大可不必name方法

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

```
#include <type_info> 

using namespace std;
 
int main()
{
   employee *pe = new manager; 
   employee& re = *pe; 
 
   if ( typeid( pe ) == typeid( employee* ) )  // true 
     // do something 
   return 0;
}
```

[![复制代码](https://common.cnblogs.com/images/copycode.gif)](javascript:void(0);)

---

