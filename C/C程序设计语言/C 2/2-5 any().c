#include<stdio.h>

//待改进 
//将单字符s2在s1中第一次出现的位置返回 
int any(char s1[], char s2[])
{
	int i,j;
	for (i = 0; s1[i] != '\0'; i++)
		for (j = 0; s2[j] != '\0'; j++)
			if (s1[i] == s2[j])
				return (i+1);		//返回第一次出现的位置（直接结束函数） 
	return -1;						//循环结束未返回则表示未找到匹配 
}

int main()
{
	char s1[50],s2[50];
	printf("请输入字符串1： ");
	gets(s1);
	printf("请输入字符串2： ");
	gets(s2);
	if(any(s1,s2) == -1)
		printf("\nNot found\n");
	else
		printf("Location: %d",any(s1,s2));
	return 0;
}
