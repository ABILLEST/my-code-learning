#include<stdio.h>

int main()
{
	int i,a,b,c,d;
	for(i=0; i<=2; i++)
	{
		for(a=1; a<=15-i; a++)
			printf(" ");
		for(b=1; b<=2*i+1; b++)
			printf("*");
		printf("\n");
	}
	return 0;
}
