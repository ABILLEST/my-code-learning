#include<stdio.h>

int main()
{
	int i,yinzi,s;//定义 循环控制变量，因子，因子合 
	for(i=2; i<1000; i++)//检索2~1000 
	{ 
		s = 0;//赋初值（*重要*） 
		yinzi = 1;
		do//循环查找因子 
		{
			if(i%yinzi==0) s += yinzi;//因子累加 
			yinzi++; 
		}while(yinzi<i);//此处的分号不能漏 
		
		if(i==s) //判断是否是完数 
		{printf("%d its factors are ",i);
		 for(yinzi=1; yinzi<i; yinzi++)//循环输出因子 
		 {
      		if(i%yinzi==0) printf("%d ", yinzi);
   		}
   		printf("\n");
		}
	}
		 return 0;
} 

