## pow()函数



> pow(a,b)，用于计算a^b（a的b次幂），需要包含头文件#include <math.h>

> 函数原型:  double pow( double x, double y );



```c++
#include <bits/stdc++.h>
using namespace std;

int main(){
    
	int x=2,y=10;
	cout<<pow(x,y);
	printf ("7 ^ 3 = %f\n", pow (7.0, 3.0) );
	printf ("4.73 ^ 12 = %f\n", pow (4.73, 12.0) );
    printf ("32.01 ^ 1.54 = %f\n", pow (32.01, 1.54) );
    
	return 0;
} 
```

