#include<stdio.h>

void turn(int n)
{ 
	int i; 
	
	if ((i=n/10)!=0)		//如果整数i除以10后不为0,说明高位还有值
		turn(i);			//调用自身,使用除以10后的i值
	putchar(n%10+'0');		//打印余数,并转换为'0' 
}
int main()
{
	int number;
	printf("\nInput an integer:");
	scanf("%d",&number);	//输入一个整数
	printf("Output:");		//输出信息
	if (number<0){			//如果是负数  
		putchar('-');			//打印负号
	    number=-number;	//负数变为正数
	}
	turn(number); 			//递归函数调用 
}
