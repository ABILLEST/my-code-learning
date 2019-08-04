#include "stdio.h"

long int jf (int n)                         /*定义求阶乘函数jf*/
{ 
	int  i;
  	long int t=1;
 	for(i=1; i<=n; i++)
    t*=i;
    return t;
}

long int cmn(int m, int n)           /*定义求组合数函数cmn*/
{ return (jf(m) / (jf(n)*jf(m-n)));}      /*用return语句返回结果*/ 

int main()
{ 
	int m,n;   
    printf("please enter m and n(用中文逗号连接): ");
    scanf("%d，%d", &m, &n );   //scanf中两个数字用中文逗号连接 
    printf("C(m,n) = %ld\n",cmn(m,n)); 
    return 0;        
  }
