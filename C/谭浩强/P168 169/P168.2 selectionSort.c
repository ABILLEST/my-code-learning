#include<stdio.h>
#define LENGTH 10

int main()
{
	int a[10],i,j,t;   //定义交换中间量t，外部循环变量i, 内部循环变量j 
	for(i=0; i<=9; i++) 
		scanf("%d",&a[i]);//输入10个整数 
	for(i=0; i<LENGTH-1; i++)//表示下标i的元素与下表j的各个元素依次比较 
		for(j=i+1; j<LENGTH; j++)//保证前面排好的顺序不变 
			if(a[i]>a[j]) //小的放前面 
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	for(i=0; i<=9; i++) //循环输出 
		printf("%d ",a[i]);
	return 0;
}
