#include<stdio.h>

//指针法输入 12 个数,然后按每行 4 个数输出
int main()
{
	int a[12];
	int *p;
	printf("Please enter 12 numbers: ");
	
	for (p = a; p < (a+12); p++)	//用指针输入 
		scanf("%d",p);
		
	printf("Answer:\n");
	for (p = a; p < (a+12);){		//用指针输出,循环体内自增 
		printf("%5d",*p++);
		printf("%5d",*p++);
		printf("%5d",*p++);
		printf("%5d",*p++);
		printf("\n");				//四个一行 
	}
	return 0;
 } 
