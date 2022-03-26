## C++ string的size()和length()函数有什么区别？

 [C++ string的size()和length()函数没有区别](https://www.cnblogs.com/lakeone/p/4764577.html)

 C++标准库中的string中两者的源代码如下：  
 size_type  __CLR_OR_THIS_CALL  length()  const  
 { //  return  length  of  sequence  
 return  (_Mysize);  
 }  

 size_type  __CLR_OR_THIS_CALL  size()  const  
 { //  return  length  of  sequence  
 return  (_Mysize);  
 }  
    所以两者没有区别。

 

​    length是因为沿用C语言的习惯而保留下来的，string类最初只有length，引入STL之后，为了兼容又加入了size，它是作为STL容器的属性存在的，便于符合STL的接口规则，以便用于STL的算法。

​    string类的size()/length()方法返回的是字节数，不管是否有汉字。

---

