#include<stdio.h>
#define MAXLEN 10 
int max = 0;			//定义全局变量 
int min = 0;

int main()
{
	void maxmin(int *array);		//声明数组中求最大最小值得函数 
	

	int a[MAXLEN] = {1,8,10,2,-5,0,7,15,4,-5};
	maxmin(a);						//调用函数处理数组 
	printf("max = %d\nmin = %d",max,min);
} 

//定义求数组中最大最小值函数 
void maxmin(int *array)
{
	int *p;
 
	for (p = array; p < array+MAXLEN-1; p++){
		if (*p > max)	max = *p;
	    if (*p < min)	min = *p;
	}
}
