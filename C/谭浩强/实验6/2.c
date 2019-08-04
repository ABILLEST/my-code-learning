#include<stdio.h>

int main()
{
	int i,j,k=0,a[50],t;  //标志变量t 
	
	for(i=1; i<=100; i++)
	{t = 0;
		for(j=2; j<=i-1; j++)
		{
			if(i%j==0)	//不是素数 
			{
				t = 1;
				break;
			}
		}
		if(t==0)
		{
			a[k] = i;
			printf("%d\t",a[k]);
			k++;
		}
	}
	return 0;
}
