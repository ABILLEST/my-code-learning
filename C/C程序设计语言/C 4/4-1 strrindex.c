#include<stdio.h> 
#define MAXLINE 1000

int getline(char line[], int maxline);
int strindex(char source[],char searchfor[]);

char pattern[] = "this";	//待查找的模式

//找出所有与模式匹配的行 
int main()
{
	char line[MAXLINE];
	int found = 0;
	
	while (getline(line,MAXLINE) > 0)
		if (strindex(line,pattern) >= 0) {
			printf("%sthe index is %d\n",line,strindex(line,pattern)+1);
			found++;
		}
	return found;
}

//getline函数：将一行读入到s中并返回其长度
int getline(char s[], int lim)
{
	int c, i;
	
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if(c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
} 


//strrindex函数：返回t在s中最右边出现的位置，若未找到则返回-1 
int strindex(char s[],char t[])
{
	int i, j, k, l;
	
	for(i = 0; s[i] != '\0'; i++)//把光标指向s的后面一个 
		; 
	i--;						//拉回到s的最后一个 
	for(k = 0; t[k] != '\0'; k++)//把光标指向t的后面一个 
		; 
	k--;						//拉回到t的最后一个 
	for (j = i; i > 0; i--){
		for (j=i; t[k] != '\0' && s[j]==t[k]; j--, k--)
		;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;	
} 

