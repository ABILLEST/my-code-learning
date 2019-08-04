#include "stdio.h"
#define LEN 10		//数组长度 

//判断一个整数数组中各元素的值函数 
void judge(int array[],int length)
{
	int i;
	for (i = 0; i <= length; ++i){		//逐个判断各元素值 
		if (array[i] > 0)
			printf("%d\t",array[i]);
		else
			printf("0\t");
	}
} 

int main( )
{
	int a[LEN],i;
	printf("输入10个数：\n");
	 
	for (i = 0; i <= LEN; ++i){
		scanf("%d",&a[i]);
	}
	
	printf("\n");
	judge(a,LEN);
	return 0; 
}
