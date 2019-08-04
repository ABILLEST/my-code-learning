#include<stdio.h>
#include<math.h>

int main()
{
	int sign=1;
	long counter1=0.0,counter2=0.0;
	double pi=0.0,n=1.0,term=1.0;
	
	while(fabs(term)>=1e-6)
	{
		pi = pi+term;
		n = n+2;
		sign = -sign;
		term = sign/n;
		counter1++;
	}
	while(fabs(term)>=1e-8)
	{
		pi = pi+term;
		n = n+2;
		sign = -sign;
		term = sign/n;
		counter2++;
	}
	pi = pi*4;
	printf("pi = %10.8f\n",pi);
	printf("%ld\t%ld\n",counter1,counter2);
	return 0;
}
