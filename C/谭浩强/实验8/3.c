#include "stdio.h"
#include<stdlib.h>
int main( ){ 
	char str1[100],str2[100];
    int i=0,j=0;
    printf("please input the string1:");
	gets(str1);
    printf("please input the string2:");
	gets(str2);
	for(i=0; str1[i]!='\0'; i++) ;        /*注意,此处空语句不可少*/
    for(j=0;str2[j]!='\0';j++){
		str1[i]=str2[j];
    	i++;
	}
	str1[i+1] = '\0';                   /*给出新的字符串的结束符*/
    printf("the catenated string is %s\n",str1);

	system("pause");
    return 0;
}
