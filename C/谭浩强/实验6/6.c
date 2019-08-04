#include<stdio.h>

int main()
{
	int i,a[6],t=0;
	for(i=0; i<=5; i++) 
		scanf("%d",&a[i]);
	for(i=0; i<=2; i++)
	{
		t = a[i];a[i] = a[5-i];a[5] = t;
	}
	for(i=0; i<=5; i++)
		printf("%d ",a[i]);
	return 0;
}
