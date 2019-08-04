#include<stdio.h>
//if-else used 
int main()
{	long I,award;
	scanf("%ld",&I);
	if(I<=100000) award = I*0.1;
		else if(I<=200000) award = 10000 + (I-100000)*0.075;
			else if(I<=400000) award = 17500 + (I-200000)*0.05;
				else if(I<=600000) award = 27500 + (I-400000)*0.03;
					else if(I<=1000000) award = 33500 + (I-600000)*0.015;
						else award = 37500 + (I-1000000)*0.01;
	printf("The award is %ld",award);
	return 0;
			
} 
