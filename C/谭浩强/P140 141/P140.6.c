#include<stdio.h>
void main()
{
	double p=1,i,sum=0;
	for(i=1; i<=20; i++)
	{
		p*=i;
		sum+=p;
	}
	printf("%f",sum);
	
}
