#include <stdio.h>

//用指针实现数的交换函数 
void swap(int *p1, int *p2)
{
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
int main()
{
	int a,b;
	int *p,*q;
	scanf("%d,%d",&a,&b);
	p=&a; q=&b;
	if(a<b)
		swap(p,q);
	printf("\n%d,%d\n",a,b);
	return 0;
}
