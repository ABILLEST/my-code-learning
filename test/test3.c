#include<stdio.h>

static int a = 1;
void fun1(void){	a = 2;	}
void fun2(void){	int a = 3;}
void fun3(void){	static int a = 4;}
int main()
{
	printf("%d ",a);
	fun1();
	printf("%d ",a);
	fun2;
	printf("%d ",a);
	fun3;
	printf("%d ",a);

	return 0;
}
