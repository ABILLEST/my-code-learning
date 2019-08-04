#include<stdio.h>

int main()
{
	char s[50];
	char *p,c,del;
	
	printf("请输入一行字符串： "); 
	gets(s);
	printf("输入要删除的字符： "); 
	scanf("%c",&del);
	for(p = s; *p != '\0'; p++){
		if (*p != del)			//如果遇到'0'跳过该字符,否则把它输出
			  putchar(*p);    
	}
	return 0; 
 } 
