#define S(a,b) a*b
#include <stdio.h>

int main( ) 
{
	int c,d,t ;
	scanf("%d,%d",&c,&d);
	t = S(c+d,c-d);	/*宏展开后代入变量 c,d 的值，从而求得变量 t 的值*/
	printf("%d",t);
}

