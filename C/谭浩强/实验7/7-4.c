#include<stdio.h>

int main()
{
	int i,j;
	int a[10][10];
	
	for(i=0; i<10; i++){		//给第一列和对角线元素赋1 
		a[i][i]=1;
		a[i][0]=1; 
	}
	for(i=2; i<10; i++)			//从第3行开始 
		for(j=1; j <= i-1; j++){	//从第2列开始，每次到i-1列结束本行 
			a[i][j] = a[i-1][j-1] + a[i-1][j];
		}
	for(i=0; i<10; i++){
		for(j=0; j<=i; j++)		//列的输出要跟随行 
			printf("%5d",a[i][j]);
		printf("\n");	
	}
	return 0;
}
