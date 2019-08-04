#include<stdio.h>

int main()
{
	int divisor(int a,int b);			//最大公约数函数原型 
	int mutiple(int a,int b);			//最小公倍数函数原型 
	
	int num1,num2;
	
	printf("Enter two numbers: \n");
	scanf("%d",&num1);					//键入两个数 
	scanf("%d",&num2);
	if (divisor(num1,num2) == -1)		//判断输入是否错误 
		printf("Wrong enter!\n");
	else{								//输出 
		printf("The largest common divisor is %d\n",divisor(num1,num2));
		printf("The least common mutiple is %d\n",mutiple(num1,num2));
	}
	return 0;
}

//最大公约数函数（辗转相除法） 
int divisor(int a,int b)
{
	int c;			//定义余数 
	c = a%b; 
	if (a == 0 || b == 0)	//输入为0时报错 
		return -1;
	else if (c == 0)		//除数为0时除数即为最大公约数 
		return(b);
	else{
		a = b; b = c;		//数的交换 
		b = divisor(a,b);	//递归调用 
	}
}

//最小公倍数函数
int mutiple(int a,int b)
{return (a*b/divisor(a,b));}

