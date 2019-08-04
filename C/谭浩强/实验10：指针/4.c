#include<stdio.h>
#define MAXLEN 10

//用指针作为函数参数，排序 
int main()
{
	void sort(int *array);

	int a[MAXLEN] = {1,8,10,2,-5,0,7,15,4,-5};
	int *p;
	sort(a);
	
	for (p = a; p < (a+MAXLEN); p++)	//用指针输出 
		printf("%d ",*p);
	return 0;
}

//冒泡法排序
void sort(int *array)
{
	int temp;
	int *p1,*p2;
	
	for (p1 = array; p1 < array+MAXLEN-1; p1++){ 			// 10个数，10 - 1轮冒泡，每一轮都将当前最大的数推到最后      
	  	for (p2 = array; p2 < array+MAXLEN-1 - p1; p2++) // 9 - i，意思是每当经过一轮冒泡后，就减少一次比较   
	        if (*p2 > *(p2+1)){   
	          temp = *p2;   
	          *p2 = *(p2+1);   
	          *(p2+1) = temp;   
	        }
    }  
}
 
