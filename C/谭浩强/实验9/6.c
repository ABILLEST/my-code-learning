#include<stdio.h>
#include "conio.h"
#include "stdio.h"
#include<stdlib.h>

int max;		
//一维数组中最大数及其位置查找函数
int fun(int arr[], int n)
{
	int pos, i;
	max = arr[0];
	pos = 0;
	for (i = 1; i<n; i++)		//打擂台
		if (max < arr[i])
		{
			max = arr[i];
			pos = i;
		}
	return (pos);
}
int main()
{
	int a[10] = { 1,4,2,7,3,12,5,34,5,9 }, n;
	n  = fun(a,10);
	printf("The max is: %d ,pos is: %d\n", max, n);

	system("pause");
	return 0;
}
