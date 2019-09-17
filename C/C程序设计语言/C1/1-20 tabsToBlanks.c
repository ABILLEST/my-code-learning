#include<stdio.h>
/*
#define MAXLEN 100

void detab(char s[],int i);
void copy(char to[], char from[]);
int getline(char s[], int lim);

int topos = 0;

//将输入的制表符替换成n个空格
int main()
{
//	printf("This is a test for blanks\n");
//	char a;
//	scanf("%c",&a);	
//	printf("        *\n");
//	8 blanks for a tab
	
	char instr[MAXLEN], outstr[MAXLEN];
	
	while (getline(instr,MAXLEN) > 0){
		copy(outstr,instr);
		printf("%s",outstr);
	}
		
	return 0;
}

//替换制表符函数 
void detab(char s[],int i)
{
	int n;
	
	for (n = 0; n < 8; i++){
		s[i] = ' ';
	}
}

//copy函数：将from复制到to；假定to足够大
void copy(char to[], char from[])
{
	int i;
	
	i = 0;
	while ((to[topos] = from[i]) != '\0'){
		if (to[topos] == '\t')	detab(to,topos);
		++i;
		topos++;
	}
	topos = 0;
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
} */

//Answer
#define TABINC 8		//tab increment size

//replace tabs with the proper nuber of blanks
int main()
{
	int c, nb, pos;
	
	nb = 0;				//number of blanks necessary
	pos = 1;			//position of character in line
	while ((c = getchar()) != EOF){
		if (c == '\t'){	//tab character
			nb = TABINC - (pos - 1) % TABINC;
			while (nb > 0){
				putchar(' ');
				++pos;
				--nb;
			}
		}else if (c == '\n'){	//newline character
			putchar(c);
			pos = 1;
		}else{					//other characters
			putchar(c);
			++pos;
		}
	}
}
