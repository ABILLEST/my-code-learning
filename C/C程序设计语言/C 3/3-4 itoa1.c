#include<stdio.h>
#include<string.h>
//解释：最大负数(10000000)求负后是00000000，操作n = -n 将-(2^字长-1)变成了0 

//my altered version
void itoa(int n, char s[])
{
	int i, sign;
	
	sign = n;
	i = 0;
	do {
		s[i++] = -(n % 10 + '0');		//取下一个数字 
		} while ((n /= 10) < 0);	//删除该数字
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}
/*
//original version
//itoa函数：将数字n转换为字符串并保存到s中 
void itoa(int n, char s[])
{
	int i, sign;
	
	if ((sign = n) < 0)	//记录符号
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';		//取下一个数字 
		} while ((n /= 10) > 0);	//删除该数字
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}
*/

//reverse函数：倒置字符串s中各个字符的位置
void reverse(char s[])
{
	int c,i,j;
	
	for (i = 0, j = strlen(s)-1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
} 

int main()
{
	int n;
	char s[10];
	scanf("%d",&n);
	itoa(n,s);
	puts(s);
	return 0;
}
