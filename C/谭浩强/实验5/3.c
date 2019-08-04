#include<stdio.h>

int main()
{
	int i,j,t,sum=0;
	
	for(i=100; i<=300; i++)
	{
		t = 0;
		for(j=2; j<=i/2; j++)
		{
			if(i%j==0)	//²»ÊÇËØÊý 
			{
				t = 1;
				break;
			}
		}
		if(t==0) sum += i;
	}
	
	printf("Sum is %d\n",sum);
	return 0;
}
