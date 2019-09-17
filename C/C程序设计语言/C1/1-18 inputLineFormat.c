#include<stdio.h>
#define MAXLEN 50

int removeblank(char s[]);
int getline(char s[], int lim);

//删除每个输入行末尾的空格和制表符，并删除完全是空格的行
int main()
{

	
	char s[MAXLEN];
	
	while (getline(s,MAXLEN) > 0)
		if(removeblank(s) > 0)
			printf("%s",s);
	return 0;
} 

//删除末尾空格函数
int removeblank(char s[])
{
	int i;
	
	i = 0;	
	while(s[i] != '\n')		//find new line
		++i;
	--i;					//back from '\n'
	while(i >= 0 && s[i] == ' ' || s[i] == '\t')
		--i;
	if (i >= 0){			//if not a blank line
		++i;				//add '\n'
		s[i] = '\n';
		++i;				//add endchar
		s[i] = '\0';
	}
	return i;
} 

 //getline函数：将一行读入到s中并返回其长度
int getline(char s[], int lim)
{
	int c, i;
	
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	} 
	s[i] = '\0';	//插入结束符 
	return i;
} 
