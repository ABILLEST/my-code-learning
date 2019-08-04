#include<stdio.h>
#include<string.h>
//排序字符串
int main()
{
	void get_3_str(char *a,char *b,char *c);
	void swap(char *a,char *b);
	void put_3_str(char *a,char *b,char *c);
	
	char a[100],b[100],c[100];	//定义要用足够大的字符数组 

	get_3_str(a,b,c);		//输入三个字符串 
	swap(a,b);				//对字符串大小排序 
	swap(b,c);
	swap(a,c);
	printf("\n");
	
	put_3_str(a,b,c);		//输出三个字符串 
	return 0;
}

//输入函数
void get_3_str(char *a,char *b,char *c)
{
	gets(a);
	gets(b);
	gets(c);
 } 

//排序函数
void swap(char *a,char *b)
{
	char t[100];
	if (strcmp(a,b)>0)	{
		strcpy(t,a);
		strcpy(a,b);
		strcpy(b,t);
	}
 }
 
 //输出函数
 void put_3_str(char *a,char *b,char *c)
 {
 	puts(a);
 	puts(b);
 	puts(c);
 }
