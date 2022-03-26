# [C++ STL set容器](https://segmentfault.com/a/1190000039975187)

![img](https://sponsor.segmentfault.com/lg.php?bannerid=0&campaignid=0&zoneid=25&loc=https%3A%2F%2Fsegmentfault.com%2Fa%2F1190000039975187&referer=https%3A%2F%2Fwww.google.com%2F&cb=257fa4c75c)

# 一、前言

和 map、multimap 容器不同，使用 set 容器存储的各个键值对，要求键 key 和值 value 必须相等。如下：

```1c
{<'a', 'a'>, <'b', 'b'>, <'c', 'c'>}
```

不支持存储键和值不相等的键值对。因此在使用set容器时，只需要为其提供各键值对中的value值即可。set容器和map容器一样，会自行根据键的大小对存储的键值对进行排序，在set容器中，实际上也是根据value值进行排序。
set 容器存储的各个元素的值**必须各不相同**。需要注意的是：在语法上set容器并没有强制对存储元素的类型做const修饰，因此**set容器中存储的元素的值是可以修改的**。但是，C++ 标准为了防止用户修改容器中元素的值，对所有可能会实现此操作的行为做了限制，使得**在正常情况下，用户是无法做到修改 set 容器中元素的值的**。
**注意：**直接修改set容器中的已存储的元素的值，可能会破坏set容器中元素的有序性。最正确的修改 set 容器中元素值的做法是：**先删除该元素，然后再添加一个修改后的元素**。使用set容器，需要

```arduino
#include <set>
```

## 1、set容器类模板的定义

```axapta
template < class T,     // 键 key 和值 value 的类型
           class Compare = less<T>,  // 指定 set 容器内部的排序规则
           class Alloc = allocator<T>  // 指定分配器对象的类型
           > class set;
```

因为键和值的类型是一样的，因此这里只有3个参数，大多数情况下，主需要用到其中的前2个参数。

# 二、创建set容器的方法

常见的创建 set 容器的方法，大致有以下 5 种。

```thrift
①std::set<std::string> myset;
②std::set<std::string> myset{"1","2","3"};
③std::set<std::string> copyset(myset);
④std::set<std::string> myset{"1","2","3"};
std::set<std::string> copyset(++myset.begin(), myset.end());
⑤std::set<std::string,std::greater<string> > myset{"1","2","3"};
```

①默认构造函数，创建空的set容器，会对存储的 string 类型元素做升序排序
②在创建 set 容器的同时，对其进行初始化
③通过拷贝（复制）构造函数，实现在创建新 set 容器的同时，将已有 set 容器中存储的所有元素全部复制到新 set 容器中，等价于std::set<std::string> copyset = myset；C++ 11 标准还为 set 类模板新增了移动构造函数，其功能是实现创建新 set 容器的同时，利用临时的 set 容器为其初始化，如下：

```cmake
set<string> retSet() 
{
    std::set<std::string> myset{ "1","2","3" };
    return myset;   //返回值是一个临时 set 容器，因此在初始化 copyset 容器时，其内部调用的是 set 类模板中的移动构造函数，而非拷贝构造函数。
}
std::set<std::string> copyset(retSet());
//等价于 std::set<std::string> copyset = retSet();
```

④set 类模板取已有 set 容器中的部分元素，来初始化新 set 容器
⑤、修改 set 容器中的排序规则方式





# 1 容器set和multiset

## 一 set和multiset基础

set和multiset会根据特定的 **排序准则**，自动将元素进行排序。不同的是后者允许元素重复而前者不允许。
（排序法则可以是自己定义的——运算符重载）



```
greater<>,从大到小排序；
less<>从小到大排序。
12
```

## 二 set和multiset的功能

1）和所有关联式容器类似，通常使用平衡二叉树完成。事实上，set和multiset通常以红黑树实作而成。
2）**自动排序**的优点是使得搜寻元素时具有良好的性能，具有对数时间复杂度。但是造成的一个缺点就是：
3）不能直接改变元素值。因为这样会打乱原有的顺序。
4）**改变元素值的方法是：先删除旧元素，再插入新元素。**

存取元素只能通过迭代器，从迭代器的角度看，元素值是常数。



### 1 set和multiset容器
set和multiset容器的内部结构通常由平衡二叉树(balanced binary tree)来实现。当元素放入容器中时，会按照一定的排序法则自动排序，默认是按照less<>排序规则来排序。这种自动排序的特性加速了元素查找的过程，但是也带来了一个问题：不可以直接修改set或multiset容器中的元素值，因为这样做就可能违反了元素自动排序的规则。如果你希望修改一个元素的值，必须先删除原有的元素，再插入新的元素。