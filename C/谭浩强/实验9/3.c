#include "stdio.h"

//级数求和函数 
double fun(int m)
{ 
	float t=1.0; 
	int i;
   	for(i=2; i<=m; i++) 
    t += 1.0/i;
	return(t); 
}

int main()
{ 
	int m; 
   	printf("\nPlease enter 1 integer number: ");
   	scanf("%d",&m);
   	printf("The result is %lf",fun(m));          /*按照例子中的输出形式输出结果*/
   	return 0;
}
