#include<stdio.h>
#include<string.h>
#define MAXLEN 50
/*
//将输入字符串中最长的单词输出
int main() 
{
	void lestwd(char c[],int n);
	
	char a[MAXLEN];
	gets(a);
	lestwd(a,MAXLEN);
	return 0;
} 

//输出最长单词函数
void lestwd(char c[],int n)
{
	int i,j=0,max=0,len = 0,flag = 0;;
	char wordc[n],longestc[n];
	
	for (i = 0; c[i] != '\0'; ++i,++j){
		if (i > n){
			printf("有单词超出最大长度!\n"); 
			flag = -1;
			break;
		}
		else if(c[i] == ' ' || c[i] == '\n' || c[i] == '\t'){
			wordc[j] = '\0';
			if(len=strlen(wordc) > max){
				printf("length is: %d\n",len);
				max = len;
				strcpy(longestc,wordc);
			}
			j = -1;
		}else
			wordc[j] = c[i];
	}
	
	if (flag != -1){
		printf("longest word: %s",longestc);
	}
}*/

int main()
{
	void lestwd(char ch[]);
	
	char ch[MAXLEN];
	printf("\n输入一串字符：");
	gets(ch);
	lestwd(ch);
	return 0;
}

void lestwd(char ch[])
{
	int  i,j,len,max,p;
	len=max=0;
	
	for (i = 0; ch[i] != '\0'; i++){
		j = i++;
		for (len = 0; ch[i] != ' ' && ch[i] != '\0'; i++)	//计算单词长度 
	    	len++;
	    
		if (len > max){
			max = len;
			p = j;
	    }
	}
	
	printf("\n");
	if(len == 0)
		printf("\n没有输入单词！");
	else{
		printf("最长的单词： ");
		for (i = p; i <= p+max; i++)
	    	printf("%c",ch[i]);
		printf("\n");
	}
}
/*Q:1.为什么要用do-while？ 		A:while也可以 
	2.为什么i要在开始初始化		A：不一定 
	3.j=i++，j，p分别代表什么？	A：1.先把i值给j再i++；j记录单词开始的位置，p保存最大单词开始位置 
	4.为什么会输出笑脸？？ 
*/ 
	
	 
