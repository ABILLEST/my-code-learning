#include<stdio.h>

int main()
{
	int i,j,n,t=1;
	double sum;
	printf("n=");
	scanf("%d",&n);
	
	for(i=1,sum=0; i<=n; i++)
	{
		t=1;
		for(j=1; j<=i; j++) t = t*j;
		sum += 1.0/t;
	}
	printf("Sum is %.10f\n",sum);
	return 0;
}
