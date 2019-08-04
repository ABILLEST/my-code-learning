#include<stdio.h>
#define N 10		//定义数组长度 

int main()
{
	void input(int *a);
	void fuc(int *a);
	void output(int *a);
	
	int a[N];
	void (*p)();	//定义指针函数，分别调用三个函数 
	p = input;
	(*p)(a);
	p = fuc;
	(*p)(a);
	p = output;
	(*p)(a);
	return 0;
	
 } 
 
//输入函数
void input(int *a)
{
	int *p;
	printf("Please enter %d numbers\n",N);
	for (p = a; p < (a+N); p++){	//利用指针遍历数组提高效率 
		scanf("%d",p);
	}
 } 
 
//处理函数
void fuc(int *a)
{
	int max,*p1,*p2,t;				//p1循环，p2记录max位置 
	for (p1 = a; p1<a+N;p1++) 		//利用指针遍历数组提高效率 
		if (*p1 > max){
			max = *p1;
			p2 = p1;
		} 
	//printf("max is %d,p:%d\n",max,p2-a);
	t = *p2;						//最大数和最后一个数交换位置 
	*p2 = *(a+N-1);
	*(a+N-1) = t;
}


//输出函数
void output(int *a)
{
	int *p;
	printf("\n");
	for (p = a; p < (a+N); p++){	//利用指针遍历数组提高效率 
		printf("%d  ",*p);
	}
 }

