#include<stdio.h>

int main()
{
	double k,s3=0;
	int s1=0,s2=0;
	
	
	for(k=1;k<=100;k++) s1 += k;
	printf("s1=%d\n",s1);
	
	for(k=1;k<=50;k++) s2 += k*k;
	printf("s2=%d\n",s2);
	
	for(k=1;k<=10;k++) s3 += 1.0/k;
	printf("s3=%f\n",s3);
	
	return 0;
}
