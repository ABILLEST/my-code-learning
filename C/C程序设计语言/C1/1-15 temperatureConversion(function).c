#include<stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

float transtemper(int f);
//用函数实现温度转换程序 
int main()
{
	int fahr;
	
	for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
		printf("%3d %6.1f\n", fahr, transtemper(fahr));
	return 0;
} 

//温度转换函数
float transtemper(int f)
{
	float c;
	
	c = (5.0/9.0)*(f-32);
	//printf("%f\n",c);		//测试 
	return c;
} 
