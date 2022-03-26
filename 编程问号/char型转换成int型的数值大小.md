### char型转换成int型的数值大小

```c++
#include<iostream>
#include <typeinfo>
#include<string>
using namespace std;


int main() {
	string s1="233008";
	//cout << typeid(s1[0]+s1[1]).name() << endl; //c
    //cout << typeid(s1).name() << endl; 	//Ss
	//cout << s1[0]+s1[1] << endl; 	//i
	cout<<(int)'2'<<' '<<(int)'3'<<' '<<'2'+'3';
    
    //结论：
	//'1'=49 
	return 0;
}
```

