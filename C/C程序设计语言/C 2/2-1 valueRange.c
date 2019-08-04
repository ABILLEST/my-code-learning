#include <stdio.h>  
#include <limits.h>//各类型变量范围均在此头文件中  
int main()  
{  /*//方法一 
    printf("signed char min = %d\n",SCHAR_MIN);  
    printf("signed char max = %d\n",SCHAR_MAX);  
    printf("signed short min = %d\n",SHRT_MIN);  
    printf("signed short max = %d\n",SHRT_MAX);  
    printf("signed int min = %d\n",INT_MIN);  
    printf("signed int max = %d\n",INT_MAX);  
    printf("signed long min = %ld\n",LONG_MIN);  
    printf("signed long max = %ld\n",LONG_MAX);  

    //printf("unsigned char min = %u\n",UCHAR_MIN);  
    printf("unsigned char max = %u\n",UCHAR_MAX);  
   // printf("unsigned short min = %u\n",USHRT_MIN);  
    printf("unsigned short max = %u\n",USHRT_MAX);  
   // printf("unsigned int min = %u\n",UINT_MIN);  
    printf("unsigned int max = %u\n",UINT_MAX);  
   // printf("unsigned long min =%lu\n",ULONG_MIN);  
    printf("unsigned long max = %lu\n",ULONG_MAX);  
	*/
	
	//方法二（直接计算） 
	printf("signed char min = %d\n",-(char)((unsigned char)~0 >> 1));  
    printf("signed char max = %d\n",(char)((unsigned char)~0 >> 1));  
    printf("signed short min = %d\n",-(short)((unsigned short)~0 >> 1));  
    printf("signed short max = %d\n",(short)((unsigned short)~0 >> 1));  
    printf("signed int min = %d\n",-(int)((unsigned int)~0 >> 1));  
    printf("signed int max = %d\n",(int)((unsigned int)~0 >> 1));  
    printf("signed long min = %ld\n",-(long)((unsigned long)~0 >> 1));  
    printf("signed long max = %ld\n",(long)((unsigned long)~0 >> 1));  

    //printf("unsigned char min = %u\n",UCHAR_MIN);  
    printf("unsigned char max = %u\n",(unsigned char)~0);  
   // printf("unsigned short min = %u\n",USHRT_MIN);  
    printf("unsigned short max = %u\n",(unsigned short)~0);  
   // printf("unsigned int min = %u\n",UINT_MIN);  
    printf("unsigned int max = %u\n",(unsigned int)~0);  
   // printf("unsigned long min =%lu\n",ULONG_MIN);  
    printf("unsigned long max = %lu\n",(unsigned long)~0);  
    return 0;  
}
