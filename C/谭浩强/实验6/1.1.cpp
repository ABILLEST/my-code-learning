#include<stdio.h>

int main()
{
	int i,sum=0;
	int a[]={2,3,4,5,6,7,8,9};
	for(i=0; i<8; i+=2)
		sum += a[i];
	printf("sum=%d\n",sum);
	return 0;
} 
