#include <stdio.h>

int main()
{
	void fsum(int a, int b, int *c);
	void swap(int *a, int *b);

	int a, b,c=0,*sum=&c,*pa=&a,*pb=&b;
	void (*p)();
	scanf_s("%d,%d", &a, &b);
	p = fsum;
	(*p)(a, b, sum);				//*p需要括号 
	p = swap;
	(*p)(pa, pb);
	printf("sum=%d\n", *sum);
	printf("a=%d,b=%d\n", a, b);
}

//求和函数 
void fsum(int a, int b, int *sum)	//类型为空，用指针带回结果 
{
	*sum = a + b;
}


//交换函数 
void swap(int *a, int *b)			//类型为空，用指针带回结果 
{
	int t; t = *a;	*a = *b; *b = t;
}

