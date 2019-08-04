#include "stdio.h"

void fun(int m)
{ 
	int aa[20],i,k=2;			//定义要转换的进制k 
    for(i=0; m > 0; i++) {aa[i]=m%k; m = m/k;}
    printf("\n");
    for(i-=1; i >= 0; i--)  printf("%d",aa[i]);
}
    
int main()
{ 
	int n;
    printf("\n请输入一个十进制整数：\n"); 
	scanf("%d",&n);
    fun(n); 
  	return 0;
}
