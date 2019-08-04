#include<stdio.h>
#define MAXLEN 20

//16->10进制转换函数
int trans_16to10(char *s)
{
	int i, t;			//定义循环控制变量i， 
	long long a = 0;
	
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] <= '9') 
			t = s[i] - '0';		//把字符转换为数字 
		else
			t = s[i] - 'A' + 10;//把十六进制中的字母转换为数字 
		a = a * 16 + t;
	}
	return a;
}

int main()
{
	char s_16[MAXLEN];
	printf("输入十六进制数： ");
	scanf("%s",s_16);
	printf("\n对应十进制数为：%lld\n",trans_16to10(s_16));	
	return 0;
}
/*
//标准输入输出法 
int main()
{
	int num;
	scanf("%x",&num);
	printf("%d",num);
	return 0;
}*/
