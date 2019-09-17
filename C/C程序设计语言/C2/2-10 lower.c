#include<stdio.h>

//lower函数：把字符c转换为小写形式 
int lower(int c)
{
	c=(c>='A' && c<='Z')?(c+'a'-'A'):c;//把if-else语句改成条件表达式 
	return c;							//return语句要单独写 
}

/*
//Answer
//lower: convert c to lower case(ASCII only)
int lower(int c)
{
	return c >= 'A' && c <= 'Z' ? c+'a'-'A' : c;
}
*/

int main()
{
	char letter;
	printf("输入一个大写字母： ");
	scanf("%c",&letter);
	printf("\n它的小写形式是： %c",lower(letter));
	return 0; 
}
