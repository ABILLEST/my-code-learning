#include<stdio.h>
//short类型变量取值范围测试 
int main()
{
	short a,b,c;
	a = 32767;
	b = a + 1;
	c = b + 1;
	
	printf("a = %d ,b = %d, c = %d",a,b,c);
	return 0;
}
