#include<stdio.h>
#define LOW 10	//打印大于此数的输入行
#define MAXLINE 1000	//允许输入行的最大长度


int getline(char line[], int maxline);
//打印大于LOW的所有输入行 
int main()
{
	int len[MAXLINE];			//每一行长度
	char line[5][MAXLINE];	//当前的输入行
	int i = 0;			//控制输入的行 
	
	for(i = 0; i < 5; i++)
		len[i] = getline(line[i], MAXLINE)-1;
	printf("\n");
	
	//for(i = 0; i < 5 ; i++)					//test:	lenghth formally
		//printf("%d ",len[i]);
	//for(i = 0; i < 5 ; i++)					//test:	input formally
		//printf("%s",line[i]);
		
	for(i = 0; i < 5; i++)		//output
		if (len[i] > LOW)
			printf("line[%d] : %s\n",i+1,line[i]);
	return 0;
 } 	
 
 //getline函数：将一行读入到s中并返回其长度
int getline(char s[], int lim)
{
	int c, i;
	
	for (i = 0; i<lim-1&&(c=getchar())!=EOF&&c!='\n';++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	} 
	s[i] = '\0';	//插入结束符 
	return i;
} 

