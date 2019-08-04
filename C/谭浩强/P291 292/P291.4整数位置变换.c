#include<stdio.h>
#include<stdlib.h>

int n;								//数组长度n 

//用指针进行数组元素位置改变
int main()
{
	void exchange(int *before,int *after,int m);	//声明交换函数 
	
	printf("How many numbers: ");
	scanf("%d",&n);
	int *p,m;
	int after[n],before[n];				//定义两个数组用于交换 
	
	printf("Please enter %d numbers:\n",n);	
	for (p = before; p < (before+n); p++)		//输入n个整数 
		scanf("%d",p);
		
	printf("How many number(s) do you want to exchange: ");	//要提前的整数的个数 
	scanf("%d",&m);
	
	printf("\nBefore: ");
	for (p = before; p-before < n; p++) 
		printf("%d ",*p);						//输入追踪
	printf("\n");		 
	exchange(before,after,m);					//调用交换函数 
	printf("Result: ");
	for (p = after; p-after < n; p++)		//输出结果 
		printf("%d ",*p);
	return 0;
	system("pause");
} 

//交换函数
void exchange(int *before,int *after,int m)
{
	int *p1,*p2;				//用两个指针控制两个数组的元素位置 
	
	for (p1 = before+n-m,p2 = after; p2 < after+m+1; p1++,p2++)	//相应元素提前 
		*p2 = *p1;
	//printf("\n%d,%d\n\n",p1-before,p2-after);			//指针位置追踪 
	for (p1 = before,--p2; (p2-after) < n; p1++,p2++)				//顺位延后 
		*p2 = *p1;
} 
