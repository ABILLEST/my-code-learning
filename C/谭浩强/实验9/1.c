#include "stdio.h"

//求x的n次方 
int main()
{
	long int fact(long x,long n) ; 			/*声明fact函数*/
	
	long int x, n;
	printf("please enter X , N (>=0): ");
    scanf("%ld,%ld", &x, &n );
    
    printf("%ld的%ld次方 = %ld",x,n, fact(x,n));  /*调用fact函数 */
	return 0;
 } 

long int fact(long int x, long int n)        /*定义fact函数求xn */
{ 
	long int  i,s;
    s = 1;                       /*求累积变量的初始化*/
	if (n == 0)  return 1;
	for(i=1; i<=n; i++)                     /*用循环实现xn*/
		s=s*x; 
    return(s);                              /*返回结果xn*/
}
