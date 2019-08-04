#include<stdio.h>
//在VS2010下运行通过
int add(int *x, int *y, int *z){
 *x += *x;
 *y += *x;
*z += *y;
 return *z;
}

void main()
{
 //划分三块内存区域
 int a=1,b=1,c=1;
 //注意经过一次add()之后，a，b，c的值有可能发生改变，注意要值要归1
 printf("指向同一内存区域%d\n",add(&a,&a,&a));
 a=1,b=1,c=1;
 printf("指向不同内存区域%d\n",add(&a,&b,&c));
 a=1,b=1,c=1;
 printf("x.y指向同一内存区域%d\n",add(&a,&a,&b));
 a=1,b=1,c=1;
 printf("x.z指向同一内存区域%d\n",add(&a,&c,&a));
 a=1,b=1,c=1;
 printf("y.z指向同一内存区域%d\n",add(&a,&c,&c));
 getchar();
}
