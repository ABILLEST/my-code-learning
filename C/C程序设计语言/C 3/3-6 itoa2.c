#include<stdio.h>
#include<string.h>

//itoa函数2.0：将数字n转换为字符串并保存到s中,结果至少具有第三个参数制定的最小宽度 
void itoa(int n, char s[], int w)
{
	int i, sign;
	
	if ((sign = n) < 0)	//记录符号
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';		//取下一个数字 
		} while ((n /= 10) > 0);	//删除该数字
	if (sign < 0)
		s[i++] = '-';			//如果是负数，添加负号 
	while (i < w)				//在必要时给字符串s补足空格 
		s[i++] = ' ';
	s[i] = '\0';
	reverse(s); 				//关键！给位宽的建立提供条件 
}

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
	itoa(n,s,10);
	puts(s);
	return 0;
}
