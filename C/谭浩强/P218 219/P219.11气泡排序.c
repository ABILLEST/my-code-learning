#include "stdio.h"

int main()
{
	void sort(char array[],int num);	
	void printch(char array[],int n);
	
	int i,n;
	printf("How many chars? ");			 
	scanf("%d",&n);						//待比较字符数量
	char a[n];
	printf("Please enter %d chars:\n",n);
	for (i = 0; i < n; ++i)				//键入字符 
		scanf("%c",&a[i]);
	printf("\nBefore: "); 
	printch(a,n);
	printf("\nAfter: ");
	sort(a,n);
	printch(a,n);
	return 0;
} 

//起泡法排序
void sort(char a[],int n)
{
	int i,j;
	char temp;
	
	for (i = 0; i < n-1; i++)				//进行n-1次循环，实现n-1趟比较 
		for (j = 0; j < (n-1-i); j++)		//每趟中进行n-1-i次比较 
			if (a[j] > a[j+1]){				//相邻两数比较 
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
}

//打印字符数组函数
void printch(char a[],int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%c ",a[i]);
}
