#include<stdio.h>
//if-else used 
int main()
{	long I,award;
	scanf("%ld",&I);
	int i = I/100000;
	printf("%d\n",I/100000);
	switch(i)
	{	case 0:award = I*0.1;break;
		case 1:award = 10000 + (I-100000)*0.075;break;
		case 2:award = 17500 + (I-200000)*0.05;break;
		case 3:award = 17500 + (I-200000)*0.05;break;
		case 4:award = 27500 + (I-400000)*0.03;break;
		case 5:award = 27500 + (I-400000)*0.03;break;
		default:award = 33500 + (I-600000)*0.01;break;
		}
	printf("The award is %ld",award);
	return 0;
			
} 
