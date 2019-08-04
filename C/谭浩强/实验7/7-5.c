#include<stdio.h>

//¾ØÕóÌõ¼ş¿ØÖÆÁ·Ï° 
int main()
{
	int i,j,num=2;
	int a[5][5];
	
	for (i = 0; i < 5; ++i)
		for (j = i+1; j < 5; ++j){
			a[i][j] = num;
			num++;
		}
	for (i = 0; i < 5; i++)
		for (j = 0; j <= i; j++)
			a[i][j] = 1;
			
	for (i = 0; i <5; i++){
		for (j = 0; j < 5; j++)
			printf("%5d",a[i][j]);
		printf("\n");
	}
	return 0;
} 
