#include<stdio.h>

//删除字符串s1中与s2中的匹配的字符 
void queeze(char s1[], char s2[])
{
	int i,j,k,flag = 0;			//利用标志变量判断是否找到匹配字符 
	
	for (i = j = 0; s1[i] != '\0'; i++){	//对每个s1中的字符判断是否和s2中的任意字符匹配 
		for (k = 0; s2[k] != '\0'; k++)
			if (s1[i] == s2[k])
				flag = 1;			//当前s1字符匹配则置1 
		if (!flag)	s1[j++] = s1[i];//当前s1不匹配则保留 并让j指向下一个待复制位 
		flag = 0;					//重新置0 
	}
	s1[j] = '\0';					//循环结束后添加字符串结束符 
}

/*
//Answer。squeeze： delete each char in s1 which is in s2 
void queeze(char s1[], char s2[])
{
	int i,j,k;
	
	for (i = j = 0; s1[i] != '\0'; i++){
		for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++);
			if (s2[k] == '\0')				//end of string - no match
				s1[j++] = s1[i];
	}
	s1[j] = '\0';	
}
*/
int main()
{
	char s1[50],s2[50];
	printf("请输入字符串1： ");
	gets(s1);
	printf("请输入字符串2： ");
	gets(s2);
	queeze(s1,s2);
	printf("处理后： ");
	puts(s1);
	return 0;
}
