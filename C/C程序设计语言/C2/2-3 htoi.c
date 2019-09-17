#include<stdio.h>
#define MAXLEN 20

//16->10进制转换函数
int htois(char *s)
{
	int i, t;			//定义循环控制变量i， 
	long long a = 0;	//定义足够大的数表示10进制 
	
	for (i = 0; s[i] != '\0'; i++){
		if (s[i] <= '9') 
			t = s[i] - '0';		//把字符转换为数字 
		else if (s[i] >= 'A' && s[i] <= 'Z')
			t = s[i] - 'A' + 10;
		else
			t = s[i] - 'a' + 10; //把十六进制中的字母转换为数字 
		a = a * 16 + t;//进制转换（按位权相加） 
	}
	return a;
}

int main()
{
	char s_16[MAXLEN];
	printf("输入十六进制数： ");
	gets(s_16);
	printf("\n对应十进制数为：%lld\n",htois(s_16));	
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
