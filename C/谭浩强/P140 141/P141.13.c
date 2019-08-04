#include<stdio.h>
#include<math.h>

int main()
{
	double n=1.0,m,a;
	printf("ÇëÊäÈëa=");
	scanf("%lf",&a);

	do
		 {
		  m=n;
		  n= (m + a/m) / 2;       
		 }
		 while(fabs(n-m)>1e-5);
		 
	printf("x= %f\n",n);
	return 0;
} 
