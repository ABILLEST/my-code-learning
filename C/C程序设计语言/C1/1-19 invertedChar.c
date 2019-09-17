#include<stdio.h>
#define MAXCHAR 50

//颠倒输入行的字符顺序
int main()
{
	int getline(char s[], int lim);
	void reverse(char ch[]);
	
	char ch[MAXCHAR];
	
	while ((getline(ch,MAXCHAR) > 0))
		reverse(ch);
	return 0;
} 

//颠倒字符顺序函数
void reverse(char s[])
{
	int i;
	
	for (i = 0; s[i] != '\0'; i++);
	--i;
	if(s[i] == '\n')
		--i;
	for (i; i >= 0; i--){
		putchar(s[i]);
	}
	printf("\n");
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

/*
//Answer:
int getline(char line[],int maxline);
void reverse(char s[]);

int main()
{
	char line[MAXCHAR];		//current input line
	
	while (getline(line,MAXCHAR) > 0){
		reverse(line);
		printf("%s",line);
	}
}
//reverse: reverse string s
void reverse(char s[])
{
	int i,j;
	char temp;
	
	i = 0;
	while (s[i] != '\0')	//find the end of string s
		++i;
	--i;					//back off from '\0'
	if (s[i] == '\n')
		--i;				//leave newline in place
	j = 0;					//beginning of new string s
	while (j < i){
		temp = s[j];
		s[j] = s[i];		//swap the characters
		s[i] = temp;
		--i;
		++j;
	}
}
*/
